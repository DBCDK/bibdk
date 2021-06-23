<?php
/**
 * @file
 * Contains form and methods for handling sbkopi order flow
 *
 * the form bibdk_sbkopi_reservation_form is the main container for the order flow
 *
 * The state is given by the url, and this defines which url logic
 *
 */

/**
 * Create form for ordering articles at sb kopi
 *
 * @param $form
 * @param $form_state
 * @param $state Information about the state fo the flow
 * @return array
 */
function bibdk_sbkopi_reservation_form($form, &$form_state, $pid, $state = NULL) {
  // Make sure the user is logged in
  if (!ding_user_is_provider_user()) {
    return bibdk_sbkopi_user_not_logged_in();
  }

  // Get user order library
  $result = ding_provider_invoke('agency', 'get_order_library', $form, $form_state);

  // if user does not have a valid order library hook_agency_get_order_library
  // returns the relevant form
  if (!isset($result['order_library'])) {
    $result['#attributes']['class'] = array('sbkopi-form');
    return $result;
  }
  else {
    $order_library = $result['order_library'];
    $manifestation = ting_openformat_get_single_manifestation($pid);
    $default_values = bibdk_sbkopi_default_values($form_state, $manifestation, $order_library);
    $fields = bibdk_sbkopi_get_fields_for_manifestation($order_library, $manifestation, $default_values);
    $form += bibdk_sbkopi_order_form_fields($manifestation, $fields);
    return $form;
  }
}

/**
 * Get the fields for the sb request form
 *
 * @param TingAgency $order_library
 * @param Manifestation $manifestation
 * @param array $default_values
 * @return array
 */
function bibdk_sbkopi_get_fields_for_manifestation($order_library, $manifestation, $default_values) {
  $sb = new SbCopyFields();
  $sb->setDefaultValues($default_values)
    ->setDefaultFields();

  if ($manifestation->getSpecifyArticleData()) {
    $sb->setArticleFields();
  }

  return $sb->alterFields('bibdk_sbkopi_translate_field_labels')->render();
}

/**
 * Generate default values for the sb request form
 *
 * @param $form_state
 * @param Manifestation $manifestation
 * @param FavouriteAgency $order_library
 * @return array
 */
function bibdk_sbkopi_default_values($form_state, Manifestation $manifestation, FavouriteAgency $order_library) {
  $form_state_values = isset($form_state['values']) ? $form_state['values'] : array();
  $user_values = $order_library->getUserData();
  $custom_values = array(
    'userMail' => (!isset($form_state_values['userMail']) && isset($user_values['email'])) ? $user_values['email'] : NULL,
    'pid' => $manifestation->id,
    'agencyId' => $order_library->getMainAgencyId(),
    'pickupAgencyId' => $order_library->getBranch()->getBranchId(),
    'user_loaner_id' => $order_library->getUserId(),
    'publicationTitle' => $manifestation->getTitle(),
  );

  return $form_state_values + $user_values + $custom_values;
}

/**
 * Callback for SbCopyFields::alterField()
 *
 * Translates the title of a field
 *
 * @param array $field
 * @return array
 */
function bibdk_sbkopi_translate_field_labels($field) {
  $field['title'] = t($field['title'], array(), array('context' => 'bibdk_sbkopi'));
  return $field;
}

/**
 * Render array with information for users who are not logged in.
 *
 * @return array
 */
function bibdk_sbkopi_user_not_logged_in() {

  $render_array = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('reservation-online-links'),
    ),
  );
  $render_array['infotext'] = array(
    '#type' => 'html_tag',
    '#tag' => 'p',
    '#value' => t('bibdk_sbkopi_user_needs_to_be_logged_in_information', array(), array('context' => 'bibdk_sbkopi')),
  );

  // Return a login link
  $render_array['link'] = array(
    '#theme' => 'link',
    '#text' => t('Login to order at sb_kopi', array(), array('context' => 'bibdk_sbkopi')),
    '#path' => 'user/login',
    '#options' => array(
      'attributes' => array(),
      'html' => TRUE,
    ),
  );

  $render_array['infotextnewuser'] = array(
    '#type' => 'html_tag',
    '#tag' => 'p',
    '#value' => t('bibdk_sbkopi_user_needs_to_create_new_user', array(), array('context' => 'bibdk_sbkopi')),
  );

  // Return a create new user link
  $render_array['linknewuser'] = array(
    '#theme' => 'link',
    '#text' => t('Create new user', array(), array('context' => 'bibdk_sbkopi')),
    '#path' => 'user/register',
    '#options' => array(
      'attributes' => array(),
      'html' => TRUE,
    ),
  );

  return $render_array;
}


/**
 * Form for adding the final information before making an order
 *
 * @param $form
 * @param $form_state
 * @param $pid
 * @param FavouriteAgency $order_library
 * @return mixed
 */
function bibdk_sbkopi_order_form_fields($manifestation, $sb_fields) {
  $form['manifestation'] = bibdk_sbkopi_manifestation_view($manifestation);

  $form['userinfo'] = array(
    '#type' => 'fieldset',
    '#title' => t('sb_order_required_information', array(), array('context' => 'bibdk_sbkopi')),
    '#description' => t('sb_order_required_information_description', array(), array('context' => 'bibdk_sbkopi')),
    '#attributes' => array(
      'class' => array('sbkopi-fields-container'),
    ),
  );

  $form['userinfo'] += $sb_fields;

  $form['userinfo']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('sb_kopi_order', array(), array('context' => 'bibdk_sbkopi')),
    '#attributes' => array("onclick" => "
      jQuery(this).attr('disabled', true);
      jQuery(this).parents('form').submit();"
    ),
  );

  $form['#submit'] = array('bibdk_sbkopi_order_form_submit');

  return $form;
}

/**
 * Implements hook_form_submit().
 *
 * @param $form
 * @param $form_state
 */
function bibdk_sbkopi_order_form_submit($form, &$form_state) {
  form_state_values_clean($form_state);
  $pid = $form_state['values']['pid'];
  // Create an array of parameters
  // user/pass is saved as variables
  $params = array(
      'ws_user' => variable_get('bibdk_sbkopi_request_user'),
      'ws_password' => variable_get('bibdk_sbkopi_request_pass'),
    ) + $form_state['values'];
  // Get webservice URL
  $url = variable_get('bibdk_sbkopi_place_copy_request_url', FALSE);


  if(isset($_SESSION['sb_kopi']['session_key']) && in_array(SbCurlRequest::get_session_key($params), $_SESSION['sb_kopi']['session_key'] )){
    drupal_set_message(t('sb_kopi_already_ordered', array(),array('context'=>'sb_kopi')), 'status');
    $form_state['redirect'] = 'reservation/sbkopi/receipt/' . $pid;
  }
  else {
    // If request fails it throws an exception
    try {
      if (bibdk_sbkopi_order_request($params, $url)) {
        $form_state['redirect'] = 'reservation/sbkopi/receipt/' . $pid;
        $_SESSION['sbkopi']['order'][$pid] = $form_state['values'];
      }
    } catch (SbCurlRequestException $e) {
      // The service do not provide usable feedback for the cause of error, so
      // we log the error and writes out a generic error message to user
      watchdog('sb_kopi', "response code: !reponse_code, return message: !return_message, url: !url, xml: @xml", $e->getParams(), WATCHDOG_ERROR);
      drupal_set_message(
        t(
          'An error has occured at SBKOPI. Please try again.',
          array(), array('context' => 'bibdk_sbkopi')
        ),
        'error'
      );
      $form_state['buttons'][0]['#attributes'] = array(
        "onclick" =>
        "jQuery(this).attr('disabled', false);"
      );
      $form_state['rebuild'] = TRUE;
    }
  }
}

/**
 * Create view of manifestation being ordered
 *
 * @param $pid
 * @return array
 */
function bibdk_sbkopi_manifestation_view($manifestation, $title = 'You are about to order the following') {
  $render = bibdk_reservation_render_custom_manifestation_view($manifestation, $title);
  $render['#attributes']['class'] = array('sbkopi-manifestation-container');
  return $render;
}

/**
 * Make request to sb webservice
 *
 * Returns http code 204 if request went well, else it will return http code
 * 4xx or 5xx
 *
 * @param $params
 * @param $url
 *
 * @return bool
 * @throws \MicroCURLException
 * @throws \SbCurlRequestException
 */
function bibdk_sbkopi_order_request($params, $url) {
  $curl = new SbCurlRequest('placeCopyRequest', $params, 'http://statsbiblioteket.dk/xws/elba-placecopyrequest-schema', $url);
  $return_message = $curl->call();

  $response_code = $curl->getReponse();

  if ($response_code == '204') {
    $_SESSION['sb_kopi']['session_key'][] = SbCurlRequest::get_session_key($params);
    return TRUE;
  }
  else {
    $report = array(
      '!reponse_code' => $response_code,
      '!return_message' => $return_message,
      '!url' => $url,
      '@xml' => $curl->getPostXml(),
    );
    $exception = new SbCurlRequestException();
    $exception->setParams($report);
    throw $exception;
  }
}

/**
 * Page callback. Logic for showing receipt
 *
 * If order has not been set or it has failed. Return to order page
 *
 * @param $pid
 * @return array
 */
function bibdk_sbkopi_reservation_receipt($pid) {
  if (!isset($_SESSION['sbkopi']['order'][$pid])) {
    drupal_goto('reservation/sbkopi/' . $pid);
  }
  else {
    //return receipt text
    return bibdk_sbkopi_reservation_receipt_text($pid);
  }
}

/**
 * Returns render array with order reciept
 *
 * @param $pid
 * @return array
 */
function bibdk_sbkopi_reservation_receipt_text($pid) {
  $render = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('bibdk-sbkopy-receipt-wrapper'),
    ),
  );
  $manifestation = ting_openformat_get_single_manifestation($pid);
  $render['manifestation'] = bibdk_sbkopi_manifestation_view($manifestation, 'You have ordered the following');

  return $render;
}
