<?php

/**
 * @file bibdk_favourite AJAX related methods.
 */

/**
 * @param $branchId
 * @return array
 */
function bibdk_favourite_ajax_command($branchId) {
  return array(
    'command' => 'favourite_set',
    'selector' => 'favourite_' . $branchId,
  );
}

/**
 * Ajax callback function
 * add favourite to session
 * set a message
 * */
function bibdk_favourite_ajax_add_favourite($form, $form_state) {
  $branchId = $form_state['build_info']['args'][0];

  $commands = array();
  $text = bibdk_favourite_save_favourite_on_webservice($branchId);
  $selector = '.messages_' . $branchId;
  drupal_set_message($text);
  $commands[] = ajax_command_replace($selector, theme('status_messages'));

  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * ajax callback for setting order agency
 */
function bibdk_favourite_ajax_link_set_favourite($branchId) {
  // add javascript for handling favourite_set
  bibdk_favourite_add_js();

  unset($_SESSION['bibdk_favourites']);

  $response = bibdk_favourite_set_favourite($branchId);
  if (!$response) {
    $text = _bibdk_favourite_set_error_text($branchId);
    $type = 'error';
  }
  else {
    $text = _bibdk_favourite_set_favourite_text($branchId);
    $type = 'status';
  }

  $commands = array();
  //clear message stack
  drupal_get_messages();
  $commands[] = bibdk_favourite_ajax_command($branchId);
  // if $response is not set something went wrong
  if (!$response) {
    $selector = '.favourite_' . $branchId;
    drupal_set_message($text, $type);
    $commands[] = ajax_command_append($selector, theme('status_messages'));
  }
  $page = array('#type' => 'ajax', '#commands' => $commands);
  ajax_deliver($page);
  drupal_exit();
}

/**
 * ajax callback for deleting a favourite library
 * */
function bibdk_favourite_ajax_link_delete_favourite($branchId) {
  if (empty($branchId) && !empty($_GET['agency'])) {
    $branchId = $_GET['agency'];
  }

  $deleted_agency = unserialize($_SESSION['bibdk_favourites'][$branchId]);
  $response = bibdk_favourite_delete_favourite_from_session($branchId);
  if (!$response) {
    $text = _bibdk_favourite_set_error_text($branchId);
    $type = 'error';
  }
  else {
    $text = _bibdk_favourite_set_delete_text($branchId);
    $type = 'status';
  }

  $commands = array();
  if ($deleted_agency && $deleted_agency->getOrderAgency()) {
    _bibdk_favourite_set_agencies();
    $agencies = isset($_SESSION['bibdk_favourites']) ? $_SESSION['bibdk_favourites'] : NULL;
    if ($agencies) {
      $agency = unserialize(current($agencies));
      $commands[] = bibdk_favourite_ajax_command($agency->getAgencyId());
    }
  }
  $selector = '.favourite_' . $branchId;

  drupal_set_message($text, $type);

  if ($response) {
    $commands[] = ajax_command_replace($selector, theme('status_messages'));
  }
  else {
    $commands[] = ajax_command_append($selector, theme('status_messages'));
  }

  $page = array('#type' => 'ajax', '#commands' => $commands);
  ajax_deliver($page);
  drupal_exit();
}

/**
 * @param $branchId
 * @return bool
 */
function bibdk_favourite_ajax_remove_favourite($branchId){
  if(!$branchId){
    return FALSE; //TODO mmj return some useful command...
  }
}

