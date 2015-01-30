<?php

/**
 * @file
 * Include file that contains callback methods and the helpers needed for
 * delivering forms in a bibdk-modal using Foundation Reveal.
 */

/**
 * Menu callback that returns the user_login form wrapped in a modal
 * If JavaScript is disabled in the client we will never get here as the login
 * link is being rewritten by client-side JavaScript.
 *
 * If the form hasn't been submitted rendered html will be returned. Otherwise
 * the output will be returned wrapped in one or more commands to have our
 * JavaScript handle it client-side.
 *
 * @return array|mixed
 */
function bibdk_modal_login() {
  $form_state = _bibdk_modal_set_form_state();

  $output = bibdk_modal_form_wrapper('user_login', $form_state);

  $commands = array();
  if (empty($form_state['executed']) && empty($form_state['submitted'])) {
    $commands = $output;
  }
  elseif (empty($form_state['executed']) && !empty($form_state['submitted'])) {
    //Something went wrong. Replace the form currently displayed in the modal and let the user try again
    $commands[] = bibdk_modal_command_replace_form($output);
  }
  elseif (!empty($form_state['executed']) && !empty($form_state['submitted'])) {
    $commands[] = bibdk_modal_command_reload();
    $commands[] = bibdk_modal_command_dismiss();
  }

  bibdk_modal_deliver_output($commands);
}

/**
 * Menu callback that returns the forgot password form form wrapped in a modal
 * If JavaScript is disabled the normal form will be returned without the modal
 * wrapper.
 *
 * @return array|mixed
 */
function bibdk_modal_forgot_password() {
  module_load_include('pages.inc', 'user');

  $form_state = _bibdk_modal_set_form_state();

  $output = bibdk_modal_form_wrapper('user_pass', $form_state);
  $commands = array();

  if (empty($form_state['executed'])) {
    $commands[] = bibdk_modal_command_replace_form($output);
  }
  else {
    $commands[] = bibdk_modal_command_dismiss();
    $commands[] = bibdk_modal_command_reload();
  }

  bibdk_modal_deliver_output($commands);
}

/**
 * Menu callback that returns the user register form wrapped in a modal
 * If JavaScript is disabled the normal form will be returned without the modal
 * wrapper.
 *
 * @return array|mixed
 */
function bibdk_modal_register() {
  $form_state = _bibdk_modal_set_form_state();

  $output = bibdk_modal_form_wrapper('user_register_form', $form_state);
  $commands = array();

  if (empty($form_state['executed'])) {
    $commands[] = bibdk_modal_command_replace_form($output);
  }
  else {
    $commands[] = bibdk_modal_command_dismiss();
    $commands[] = bibdk_modal_command_reload();
  }

  bibdk_modal_deliver_output($commands);
}

/**
 * Creates and delivers the form used to report offensive content.
 */
function bibdk_modal_offensive_form() {
  $form_state = _bibdk_modal_set_form_state();
  $output = bibdk_modal_form_wrapper('bibdk_voxb_offensive_form', $form_state);
  $message = t('bibdk_voxb_offensive_reported', array(), array('context' => 'bibdk_voxb'));
  $voxb_id = $_GET['voxb_id'];

  $commands = array();

  if (empty($form_state['executed']) && empty($form_state['submitted'])) {
    $commands = $output;
  }
  elseif (empty($form_state['executed']) && !empty($form_state['submitted'])) {
    $commands[] = bibdk_modal_command_replace_form($output);
  }
  elseif (!empty($form_state['executed']) && !empty($form_state['submitted'])) {
    $commands[] = bibdk_voxb_offensive_posted($voxb_id, $message);
    $commands[] = bibdk_modal_command_dismiss();
  }

  bibdk_modal_deliver_output($commands);
}

/**
 * Callback function.
 * Gets the pid and calls the _review_edit_node form that delivers the actual
 * form to the client.
 */
function bibdk_modal_review_create_node() {
  $pid = bibdk_voxb_review_check_pid();
  bibdk_modal_review_edit_node($pid);
}

/**
 * Menu callback. wrap blog_node_form in modal.
 *
 * @param string|null $pid
 */
function bibdk_modal_review_edit_node($pid = NULL) {
  if (!function_exists("node_form")) {
    include_once(drupal_get_path('module', 'node') . '/node.pages.inc');
  }

  $form_state = _bibdk_modal_set_form_state();

  $blog_node = bibdk_voxb_set_blog_node();

  $wrap = entity_metadata_wrapper('node', $blog_node);
  $voxb_id = $wrap->field_voxb_id->value();
  $form_state['build_info']['args'] = array($blog_node);

  $output = bibdk_modal_form_wrapper('blog_node_form', $form_state);

  $commands = array();
  if (empty($form_state['executed']) && empty($form_state['submitted'])) {
    $commands = $output;
  }
  elseif (empty($form_state['executed']) && !empty($form_state['submitted'])) {
    $commands[] = bibdk_modal_command_replace_form($output);
  }
  elseif (!empty($form_state['executed']) && !empty($form_state['submitted'])) {
    if (!empty($voxb_id)) {
      $commands[] = bibdk_voxb_ajax_review_saved($voxb_id);
    }
    else {
      $commands[] = bibdk_voxb_ajax_review_created($pid);
    }
    $commands[] = bibdk_modal_command_dismiss();
  }

  bibdk_modal_deliver_output($commands);
}

/**
 * Genrate form for editing favourite userdaata
 *
 * @param string $branchid
 */
function bibdk_modal_edit_favourite_userdata_form($branchid) {
  $form_state = _bibdk_modal_set_form_state();
  $form_state['branchid'] = $branchid;

  $output = bibdk_modal_form_wrapper('bibdk_favourite_user_form_fields', $form_state);

  $commands = array();
  if (empty($form_state['executed']) && empty($form_state['submitted'])) {
    $commands = $output;
  }
  elseif (empty($form_state['executed']) && !empty($form_state['submitted'])) {
    $commands[] = bibdk_modal_command_replace_form($output);
  }
  elseif (!empty($form_state['executed']) && !empty($form_state['submitted'])) {
    $commands[] = bibdk_modal_command_reload();
    $commands[] = bibdk_modal_command_dismiss();
  }

  bibdk_modal_deliver_output($commands);
}

/**
 * Genrate form for editing favourite userdaata
 *
 * @return array|mixed Form array
 */
function bibdk_modal_add_to_favorites_callback() {
  module_load_include('inc', 'bibdk_favourite', 'includes/bibdk_favourite.forms');

  $agencyName = bibdk_favourite_check_for_new_agency();
  drupal_set_message(t("%library was added to your favorite libraries. Please enter your userdata below.", array('%library' => $agencyName), array('context' => 'bibdk_favourite')));
  if (empty($_GET['agency'])) {
    global $user;
    $url = "";
    if ($user->uid) {
      $url = "user/$user->uid/bibdk_favourite_list";
    }
    drupal_goto($url);
  }

  $branchid = $_GET['agency'];

  $form_state = _bibdk_modal_set_form_state();
  $form_state['branchid'] = $branchid;

  $output = bibdk_modal_form_wrapper('bibdk_favourite_user_form_fields', $form_state);

  $commands = array();

  if (empty($form_state['executed']) && empty($form_state['submitted'])) {
    $commands = $output;
  }
  elseif (empty($form_state['executed']) && !empty($form_state['submitted'])) {
    $commands[] = bibdk_modal_command_replace_form($output);
  }
  elseif (!empty($form_state['executed']) && !empty($form_state['submitted'])) {
    global $user;
    if ($user->uid) {
      $url = "user/$user->uid/bibdk_favourite_list";
      $commands[] = bibdk_modal_command_redirect($url, array());
    }
    else {
      $commands[] = bibdk_modal_command_reload();
    }
    $commands[] = bibdk_modal_command_dismiss();
  }

  bibdk_modal_deliver_output($commands);
}

/**
 * @return array
 */
function _bibdk_modal_set_form_state() {
  $form_state = array(
    'ajax' => TRUE,
  );

  return $form_state;
}