<?php

/**
 * @file
 * Handles agency request with bibdk_provider
 */


/**
 * implements hook_agency_get_order_library().
 *
 * This method controls the flow for making sure that a user has an order
 * library before continuing a flow
 *
 * 1. Check if user is logged in
 * 2. Check if user has order library
 * 3. Check user data is set for order library
 * 4. return order library
 *
 *
 * @param $form
 * @param $form_state
 * @return array drupal form array or order library
 */
function bibdk_provider_agency_get_order_library($form, $form_state) {
  if (!ding_user_is_provider_user()) {
    return array();
  }
  else if ($order_library = bibdk_favourite_get_order_library()) {
    if ($order_library->getUserData() == FALSE) {
      return bibdk_favourite_user_form_fields($form, $form_state, $order_library->getBranch()->getBranchId());
    }
    return array('order_library' => $order_library);
  }
  else {
    return bibdk_favourite_no_library_form($form, $form_state);
  }
}
