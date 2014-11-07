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
    return $result;
  }
  else {
    $order_library = $result['order_library'];
    return bibdk_sbkopi_order_form_fields($form, $form_state, $pid, $order_library);
  }
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
  // Return a login button
  $render_array['link'] = array(
    '#theme' => 'link',
    '#text' => t('Login to order at sb_kopi', array(), array('context' => 'bibdk_sbkopi')),
    '#path' => 'user/login',
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
function bibdk_sbkopi_order_form_fields($form, &$form_state, $pid, FavouriteAgency $order_library) {
  $userdata = $order_library->getUserData();
  $email = isset($userdata['email']) ? $userdata['email'] : NULL;
  $username = isset($userdata['userName']) ? $userdata['userName'] : NULL;
  bibdk_sbkopi_messages($pid, $order_library->getBranch());

  $form['pid'] = array(
    '#type' => 'value',
    '#value' => $pid,
  );
  $form['agencyId'] = array(
    '#type' => 'value',
    '#value' => $order_library->getAgencyId(),
  );
  $form['pickupAgencyId'] = array(
    '#type' => 'value',
    '#value' => $order_library->getBranch()->getBranchId(),
  );
  $form['user_loaner_id'] = array(
    '#type' => 'value',
    '#value' => $order_library->getUserId()
  );

  $form['manifestation'] = bibdk_sbkopi_manifestation_view($pid);

  $form['userinfo'] = array(
    '#type' => 'fieldset',
    '#title' => t('sb_order_required_information', array(), array('context' => 'bibdk_sbkopi')),
    '#description' => t('sb_order_required_information_description', array(), array('context' => 'bibdk_sbkopi')),
  );
  $form['userinfo']['userName'] = array(
    '#type' => 'textfield',
    '#title' => t('name', array(), array('context' => 'bibdk_sbkopi')),
    '#default' => (isset($form_state['values']['userName'])) ? $form_state['values']['userName'] : $username,
    '#required' => TRUE,
  );
  $form['userinfo']['userMail'] = array(
    '#type' => 'textfield',
    '#title' => t('email', array(), array('context' => 'bibdk_sbkopi')),
    '#default' => (isset($form_state['values']['userMail'])) ? $form_state['values']['userMail'] : $email,
    '#required' => TRUE,
  );
  $timestamp = strtotime(date('Y-m-d') . '+ 3 month');
  $date = date('Y-m-d', $timestamp);
  $form['userinfo']['user_interest_date'] = array(
    '#type' => 'date_select',
    '#title' => t('Is of no interest after', array(), array('context' => 'bibdk_reservation')),
    '#required' => TRUE,
    '#date_label_position' => 'within',
    '#date_format' => 'd-m-Y',
    '#default_value' => $date,
    '#date_year_range' => '0:+3',
  );
  $form['userinfo']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('sb_kopi_order', array(), array('context' => 'bibdk_sbkopi')),
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

  // If request fails it throws an exception
  try {
    if (bibdk_sbkopi_order_request($params, $url)) {
      $form_state['redirect'] = 'reservation/sbkopi/receipt/' . $pid;
      $_SESSION['sbkopi']['order'][$pid] = $form_state['values'];
    }
  }
  catch (SbCurlRequestException $e) {
    // The service do not provide usable feedback for the cause of error, so
    // we log the error and writes out a generic error message to user
    watchdog('sb_kopi', "response code: !reponse_code, return message: !return_message, url: !url, xml: !xml", $e->getParams(), WATCHDOG_ERROR);
    drupal_set_message(t('sb_kopi error message'), 'error');

    //
    $form_state['rebuild'] = TRUE;
  }
}

/**
 * Create view of manifestation being ordered
 *
 * @param $pid
 * @return array
 */
function bibdk_sbkopi_manifestation_view($pid, $title = 'You are about to order the following') {
  $manifestation = ting_openformat_get_single_manifestation($pid);
  return bibdk_reservation_render_custom_manifestation_view($manifestation, $title);
}

/**
 * Return the relevant messages
 *
 * @param $pid
 * @param TingClientAgencyBranch $branch
 */
function bibdk_sbkopi_messages($pid, TingClientAgencyBranch $branch) {
  //drupal_get_messages();
  unset($_SESSION['bibdk_favourites']);
  if (!$branch->getStateAndUniversityLibraryCopyService()) {
    drupal_set_message(t('Your library does not have a subscription', array(), array('context' => 'bibdk_sbkopi')), 'warning');
  }
  if ($delivery = bibdk_sbkopi_delivery_method($pid)) {
    drupal_set_message(t('delivery_method is !method', array('!method' => $delivery), array('context' => 'bibdk_sbkopi')), 'warning');
  }
  else {
    drupal_set_message(t('This article cannot be ordered', array(), array('context' => 'bibdk_sbkopi')), 'error');
  }
}

/**
 * Make request to sb webservice
 *
 * Returns http code 204 if request went well, else it will return http code
 * 4xx or 5xx
 *
 * @param $values
 * @return bool
 * @throws SbCurlRequestException
 */
function bibdk_sbkopi_order_request($params, $url) {
  $curl = new SbCurlRequest('placeCopyRequest', $params, 'http://statsbiblioteket.dk/xws/elba-placecopyrequest-schema', $url);
  $return_message = $curl->call();

  $response_code = $curl->getReponse();
  debug($curl->getPostXml());

  if ($response_code == '204') {
    return TRUE;
  }
  else {
    $report = array(
      '!reponse_code' => $response_code,
      '!return_message' => $return_message,
      '!url' => $url,
      '!xml' => $curl->getPostXml(),
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
  $render = array();
  $render['manifestation'] = bibdk_sbkopi_manifestation_view($pid, 'You have ordered the following');

  return $render;
}
