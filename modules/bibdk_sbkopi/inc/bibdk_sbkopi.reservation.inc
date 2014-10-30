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
    '#required' => true,
  );
  $form['userinfo']['userMail'] = array(
    '#type' => 'textfield',
    '#title' => t('email', array(), array('context' => 'bibdk_sbkopi')),
    '#default' => (isset($userdata['email'])) ? $userdata['email'] : null,
    '#required' => true,

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
 * implements hook_form_submit().
 *
 * @todo: Call sbkopi webservice to make final order
 *
 * @param $form
 * @param $form_state
 */
function bibdk_sbkopi_order_form_submit($form, $form_state) {
  form_state_values_clean($form_state);
}

/**
 * Create view of manifestation being ordered
 *
 * @param $pid
 * @return array
 */
function bibdk_sbkopi_manifestation_view($pid) {
  $manifestation = ting_openformat_get_single_manifestation($pid);
  return bibdk_reservation_render_custom_manifestation_view($manifestation, 'You are about to order the following');
}

/**
 * Return the relevant messages tu
 *
 * @param $pid
 * @param TingClientAgencyBranch $branch
 */
function bibdk_sbkopi_messages($pid, TingClientAgencyBranch $branch) {
  unset($_SESSION['bibdk_favourites']);
  if (!$branch->getStateAndUniversityLibraryCopyService()) {
    drupal_set_message(t('Your library does not have a subscription', array(), array('context' => 'bibdk_sbkopi')), 'warning');
  }
  if($delivery = bibdk_sbkopi_delivery_method($pid)) {
    drupal_set_message(t('delivery_method is !method', array('!method' => $delivery), array('context' => 'bibdk_sbkopi')), 'warning');
  }
  else {
    drupal_set_message(t('This article cannot be ordered', array(), array('context' => 'bibdk_sbkopi')), 'error');
  }


}
