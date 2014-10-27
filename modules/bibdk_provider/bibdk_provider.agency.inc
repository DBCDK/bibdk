<?php

/**
 * @file
 * Handles agency request with bibdk_provider
 */


/**
 * implements hook_agency_get_favourite().
 *
 * This method controls the flow for making sure that a user has a favourite
 * library before continuing a flow
 *
 * 1. Check if user is logged in
 * 2. Check if user has favorite library
 * 3. Check user data is set for favorite library
 * 4. call callback method
 *
 * @todo this method needs to be split up, or/and the arguments array needs to
 *  be documented
 * @todo Move all ting_infomedia_methods to bibdk_provider or bibdk_favourite
 *
 * @param $args
 * @param $callback
 * @return array drupal form array
 */
function bibdk_provider_agency_get_favourite($args, $callback) {
  if (!ding_user_is_provider_user()) {
    return false;
  }
  else if ($order_library = _ting_infomedia_get_user_order_library()) {
    if ($order_library->getUserData() == FALSE) {
      return ting_infomedia_user_form_fields($args[0], $args[1], $order_library->getBranch());
    }
    $args[] = $order_library;
    return $callback($args, $order_library);
  }
  else {
    return ting_infomedia_no_library_form($args[0], $args[1]);
  }
}

/**
 * implements hook_agency_get_user_form_fields().
 *
 * @param $form
 * @param $form_state
 * @param $branch
 * @param null $submit_method
 * @return mixed
 */
function bibdk_provider_agency_user_form_fields($form, $form_state, $branch, $submit_method = null) {
  if (ding_user_is_provider_user()) {
    $fields = bibdk_favourite_user_form_fields($form, $form_state, $branch->branchId);
    $form['userParameters']['userfields'] = $fields;
  }
  else {
    $fields = bibdk_reservation_get_agency_fields();
    $fields = ting_agency_userdata_form($form, $form_state, $fields, NULL, $branch->branchId);
    $form['userParameters']['userfields'] = $fields;
  }
  if (isset($submit_method)) {
    $form['userParameters']['userfields']['wrapper']['submit']['#submit'][] = $submit_method;
  }

  $form['#validate'] = $form['userParameters']['userfields']['#validate'];
  return $form;
}
