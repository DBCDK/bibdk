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
function bibdk_sbkopi_reservation_form($form, &$form_state, $pid) {
  // Make sure the user is logged in
  if (!ding_user_is_provider_user()) {
    return bibdk_sbkopi_user_not_logged_in();
  }

  // Get user order library
  $result = ding_provider_invoke('agency', 'get_order_library', $form, $form_state);
  if(isset($result['order_library'])) {
    $order_library = $result['order_library'];
    return bibdk_sbkopi_order_form_fields($form, $form_state, $pid, $order_library);
  }
  else {
    // if user does not have a valid order library hook_agency_get_order_library
    // returns the relevant form
    return $result;
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
  // Returner en login knap
  $render_array['link'] = array(
    '#theme' => 'link',
    '#text' => t('Login to order at sb_kopi', array(), array('context' => 'bibdk_sbkopi')),
    '#path' => 'user/login',
    '#options' => array(
      'attributes' => array(),
      'html' => true,
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
function bibdk_sbkopi_order_form_fields($form, $form_state, $pid, FavouriteAgency $order_library) {
  $userdata = $order_library->getUserData();
  dpm(func_get_args());
  $form['user_loaner_id'] = array(
    '#type' => 'value',
    '#value' => $order_library->getUserId()
  );
  $form['pid'] = array(
    '#type' => 'value',
    '#value' => 'test');
  $form['agencyId'] = array(
    '#type' => 'value',
    '#value' => $order_library->getAgencyId(),
  );
  $form['pickupAgencyId'] = array(
    '#type' => 'value',
    '#value' => $order_library->getBranch()->getBranchId(),
  );

  $form['userName'] = array(
    '#type' => 'textfield',
    '#title' => t('name', array(), array('context' => 'bibdk_sbkopi')),
    '#required' => true,
  );
  $form['userMail'] = array(
    '#type' => 'textfield',
    '#title' => t('email', array(), array('context' => 'bibdk_sbkopi')),
    '#default' => (isset($userdata['email'])) ? $userdata['email'] : null,
    '#required' => true,

  );
  $form['user_interest_date'] = array();
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('sb_kopi_order', array(), array('context' => 'bibdk_sbkopi')),
  );
  $form['#submit'] = array('bibdk_sbkopi_order_form_submit');
  return $form;
}

/**
 * implements hook_form_submit().
 *
 * @todo: Call sbkopi webservice to make final order
 *
 * @param $form
 * @param $form_state
 */
function bibdk_sbkopi_order_form_submit($form, $form_state) {
  debug($form_state['values']);
}
