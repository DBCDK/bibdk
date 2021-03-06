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
    'selector' => 'favourite-' . $branchId,
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
  $selector = '.messages-' . $branchId;
  drupal_set_message($text);
  $commands[] = ajax_command_replace($selector, theme('status_messages'));

  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * ajax callback for setting order agency
 */
function bibdk_favourite_ajax_link_set_favourite($branchId) {
  unset($_SESSION['bibdk_favourites']);

  $response = bibdk_favourite_set_favourite($branchId);
  if (!$response) {
    $text = _bibdk_favourite_set_error_text($branchId);
    $type = 'error';
  }
  else {
    $text = _bibdk_favourite_set_favourite_text();
    $type = 'status';
  }

  $commands = array();
  //clear message stack
  drupal_get_messages();
  $commands[] = bibdk_favourite_ajax_command($branchId);
  // if $response is not set something went wrong
  if (!$response) {
    $selector = '.favourite-' . $branchId;
    drupal_set_message($text, $type);
    $commands[] = ajax_command_append($selector, theme('status_messages'));
  }
  $page = array('#type' => 'ajax', '#commands' => $commands);
  ajax_deliver($page);
  drupal_exit();
}

/**
 * Ajax callback for deleting a favourite library
 *
 * @param $branchId
 * @throws Exception
 */
function bibdk_favourite_ajax_link_delete_favourite($branchId) {
  if (empty($branchId) && !empty($_GET['agency'])) {
    $branchId = $_GET['agency'];
  }

  $deleted_agency = unserialize($_SESSION['bibdk_favourites'][$branchId]);
  $response = _bibdk_favourite_ajax_delete_from_session($branchId);

  $commands = array();
  if ($deleted_agency && $deleted_agency->getOrderAgency()) {
    _bibdk_favourite_set_agencies();
    $agencies = isset($_SESSION['bibdk_favourites']) ? $_SESSION['bibdk_favourites'] : NULL;
    if ($agencies) {
      $agency = unserialize(current($agencies));
      $commands[] = bibdk_favourite_ajax_command($agency->getBranchId());
    }
  }
  $selector = '.favourite-' . $branchId;

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
 * Callback method for deleting a user's favourite library
 *
 * @param string $branchId
 * @return bool
 */
function bibdk_favourite_ajax_remove_favourite($branchId) {
  $commands = array();

  if (empty($branchId)) {
    $text = t('No branchID provided. Please reload the page and try again.', array(), array('context' => 'bibdk_favourite'));
    drupal_set_message($text, 'error');
    $commands[] = ajax_command_append('#bibdk-vejviser--search-form', theme('status_messages'));
  }
  else {
    $response = _bibdk_favourite_ajax_delete_from_session($branchId);
    if ($response) {
      $selector = '#add-remove-' . $branchId;
      $link = drupal_render(bibdk_favourite_list_link($branchId));
      $commands[] = ajax_command_replace($selector, $link);
      drupal_get_messages();
    }
    else {
      _bibdk_favourite_ajax_set_status_message($response);
      $commands[] = ajax_command_append('#bibdk-vejviser--search-form', theme('status_messages'));
    }
  }

  $output = array('#type' => 'ajax', '#commands' => $commands);

  ajax_deliver($output);
  drupal_exit();
}

/**
 * Delete the branch with the given $branchId from the user's list of favourite
 * libraries and set an appropriate status message.
 *
 * @param string $branchId
 * @return bool
 */
function _bibdk_favourite_ajax_delete_from_session($branchId) {
  $response = bibdk_favourite_delete_favourite_from_session($branchId);
  _bibdk_favourite_ajax_set_status_message($response);

  return $response;
}

/**
 * Queues an appropriate status message depending on the given parameter
 *
 * @param bool $response
 */
function _bibdk_favourite_ajax_set_status_message($response) {
  if (!$response) {
    $text = _bibdk_favourite_set_error_text();
    $type = 'error';
  }
  else {
    $text = _bibdk_favourite_set_delete_text();
    $type = 'status';
  }

  drupal_set_message($text, $type);
}

