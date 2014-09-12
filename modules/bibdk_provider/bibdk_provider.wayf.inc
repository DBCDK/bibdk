<?php

/**
 * @file
 * Implements WAYF capabilities.
 */

/**
 * Authentication using WAYF
 *
 * @param type $name
 * @param type $wayfid
 * @return array; an array as expected by ding_user (@see ding_user_user_login_validate)
 */
function bibdk_provider_wayf_authenticate($name, $wayfid) {

  try {
    $loginType = isset($_SESSION['wayf_login']['login_type']) ? $_SESSION['wayf_login']['login_type'] : 'wayf_id';

    // loginWayf-method throws an exception if something (anything) goes wrong
    BibdkUser::instance()->loginWayf($name, $wayfid, $loginType);

    $return = array(
      'creds' => array(
        'name' => $name,
        'pass' => $wayfid,
      ),
      'user' => array(
        'data' => array('display_name' => $name),
        'mail' => $name,
      ),
      'authname' => $name,
      'success' => TRUE,
    );

  } catch (Exception $e) {
    $enable_logging = variable_get('bibdk_provider_enable_logging');

    if ($enable_logging) {
      watchdog('bibdk_wayf', 'login failed %userid; %wayfid message: %message', array('%userid' => $name, '%wayfid' => $wayfid, '%message' => $e->getMessage()), WATCHDOG_NOTICE);
    }

    $return = array(
      'success' => FALSE,
    );
  }

  return $return;
}

/** Implements hook_user_login
 *  unset wayf-SESSION variables - we don't want them once user has logged in
 */
function _bibdk_provider_wayf_user_login(&$edit, $account) {
  if (isset($account->data['accept_wayf']['pass'])) {
    $wayf_id = $account->data['accept_wayf']['pass'];
    $login_type = isset($account->data['wayf_login']['login_type']) ? $account->data['wayf_login']['login_type'] : 'wayf_id';
    bibdk_provider_wayf_bind($account->mail, $wayf_id, $login_type);
  }

  if (isset($_SESSION['wayf_login'])) {
    unset($_SESSION['wayf_login']);
  }
  if (isset($_SESSION['accept_wayf'])) {
    unset($_SESSION['accept_wayf']);
  }
}

/**
 * \brief custom validator for user_login form (@see ding_wayf.module)
 *
 * PRE: user is authenticated with WAYF
 */
function bibdk_provider_wayf_validate(&$form, &$form_state) {
  // check if validation comes from wayf
  if ($form_state['values']['authentication_provider'] != 'wayf') {
    return;
  }

  // Try to validate user
  $email = isset($form_state['values']['name']) ? $form_state['values']['name'] : NULL;
  $pass = $form_state['values']['pass'];
  $loginType = $_SESSION['wayf_login']['login_type'];
  $verified_email = ding_provider_invoke('wayf', 'verify', $pass, $loginType);
  if(!$verified_email){
    if (isset($_GET['destination'])) {
      unset($_GET['destination']);
    }
    bibdk_provider_wayf_set_session('unknown', $pass);
    drupal_goto('wayf/accept');
  }
  else if (!empty($email) && $email != $verified_email) {
    // Email coupled with wayf_id has changed
    if (isset($_GET['destination'])) {
      unset($_GET['destination']);
    }
    bibdk_provider_wayf_set_session($email, $pass, 'unbind');
    drupal_goto('wayf/accept');
  }
}


function bibdk_provider_wayf_login_creds($authentication_attributes, $notify_by_mail) {
  // set authentication provider for ding_user (@see ding_user_user_login_validate)
  $form_state['values']['authentication_provider'] = 'wayf';

// set name and password for login
  $form_state['values']['name'] = isset($authentication_attributes['mail'][0]) ? strtolower($authentication_attributes['mail'][0]) : null;
  $form_state['values']['mail'] = strtolower($form_state['values']['name']);
  $form_state['values']['pass'] = $authentication_attributes['eduPersonTargetedID'][0];

  // # Bug 17442
  // check if name is set.. if not get it from OUI
  if(empty($form_state['values']['name'])){
    $logintype = $_SESSION['wayf_login']['login_type'];
    $username = ding_provider_invoke('wayf', 'verify', $form_state['values']['pass'], $logintype);
    if(!empty($username)){
      $form_state['values']['name'] = $username;
    }
  }

  if (isset($notify_by_mail)) {
    $form_state['mail_me'] = $notify_by_mail;
  }
  return $form_state;
}

/**
 *
 */
function bibdk_provider_wayf_accept_form() {
  return 'user_register_form';
}

/** \brief Check if wayf loginflow has been interrupted.
 * User may abort flow while accepting wayf binding -if so SESSION variables
 * are set .. unset them
 */
function bibdk_provider_wayf_check_logintype() {
  if (end($args) != 'accept') {
    if (isset($_SESSION['wayf_login'])) {
      unset($_SESSION['wayf_login']);
    }
  }
}

/************************************************ REGISTER NEW BINDINGS ********************************************/

/**
 * Custom form alter - called from bibdk_provider.module::bibdk_provider_form_user_register_form_alter
 * @param type $form
 */
function bibdk_provider_wayf_alter_user_register_form(&$form, &$form_state) {

    if (drupal_get_path_alias(current_path()) == 'wayf/accept') {

      // new text on submit button
      $form['actions']['submit']['#value'] = t('Update/create account', array(), array('context' => 'bibdk_provider'));
      $form['account']['mail']['#default_value'] = !empty($_SESSION['wayf_login']['mail'][0]) ? strtolower($_SESSION['wayf_login']['mail'][0]) : '';
      $form['wayf_accept'] = array(
        'messages' => array(
          'message' => array(
            '#markup' => t('You have been authenticated by wayf, but you either have no account or has not yet accepted wayfbinding'),
          ),
          'accept' => array(
            '#type' => 'checkbox',
            '#default_value' => FALSE,
            '#title' => t('accept_wayf_binding', array(), array('context' => 'ding_wayf')),
          ),
        ),
        // put checkbox on top of form
        '#weight' => -100,
      );
      //add validation handler for checkbox
      $form['#validate'] = array('bibdk_provider_accept_form_validate');
      $form['#submit'] = array('bibdk_provider_accept_form_submit');
      // set page title
      drupal_set_title(t('Accept match of profiles', array(), array('context' => 'ding_wayf')));
      // If wayf id is bound to another account give the user a message
      if (isset($_SESSION['accept_wayf']['status']) && $_SESSION['accept_wayf']['status'] == 'unbind') {
        drupal_set_message(t('This wayf_id is already connected to a different email. If you accept this connection, wayf_id will be bound to new email'), 'warning');
      }
    }
}



/** Custom validator for accept_form
 *
 * @param type $form
 * @param type $form_state
 * @return type
 */
function bibdk_provider_accept_form_validate($form, &$form_state) {
  //validate that accept has been checked
  if (!$form_state['values']['accept']) {
    form_set_error('accept', t('You must accept binding your bibliotek.dk username with wayf id', array(), array('context' => 'ding_wayf')));
  }

  //validate mail field
  if (!valid_email_address($form_state['values']['mail'])) {
    form_set_error('mail', t('You need to provide a valid email address', array(), array('context' => 'ding_wayf')));
  }
}

/**
 * Submit function for wayf accept form
 *
 * At this point we know user has accepted binding
 * and has entered a valid email address
 *
 * @param $form
 * @param $form_state
 *
 */
function bibdk_provider_accept_form_submit($form, &$form_state) {
  $mail = strtolower($form_state['values']['mail']);

  // Tjek if user exists as provider user
  $user_exists = ding_provider_invoke('user', 'verify', $mail);


  if ($user_exists) {
    // Tjek if user exists in drupal. If not create one
    if (!$account = user_load_by_mail($mail)) {
      $account = _ding_user_create_account($mail, array());
    }
    bibdk_provider_wayf_confirm_existing_user($account);

  }
  else {
    bibdk_provider_wayf_accept_create_new_user($mail);
  }

  $form_state['redirect'] = '';

}


/**
 * Confirm that email is correct for the user logging in for the first time with wayf
 *
 * @return null
 */
function bibdk_provider_wayf_confirm_existing_user($account) {

  // Make sure the data element on the user is an array
  if (!isset($account->data) || !is_array($account->data))
    $account->data = array();

  // Save wayf_login on user
  $account->data['accept_wayf'] = $_SESSION['accept_wayf'];
  $account->data['wayf_login'] = $_SESSION['wayf_login'];

  // save user
  user_save($account);

  //Send mail to user
  bibdk_provider_wayf_send_confirmation_mail($account);
}

/** Handle registration of users logged in via wayf (or nemlogin).
 *
 * @param array $form
 * @param array $form_state
 */
function bibdk_provider_wayf_accept_create_new_user($mail) {
  $account = bibdk_provider_register_new_user($mail);
  $account->data = array();
  // Save wayf_login on user
  $account->data['accept_wayf'] = $_SESSION['accept_wayf'];
  $account->data['wayf_login'] = $_SESSION['wayf_login'];

  // save user
  user_save($account);
}


function bibdk_provider_wayf_send_confirmation_mail($account) {
  global $language;
  $params['account'] = $account;
  $language = $language ? $language : user_preferred_language($account);
  if (drupal_mail('bibdk_provider', 'wayf_confirm_user', $account->mail, $language, $params)) {
    // Send message to user
    drupal_set_message(t('Confirmation mail have been sent', array(), array('context' => 'bibdk_provider')), 'status');
  }
  else {
    drupal_set_message(t('A mail could not be sent please try again later', array(), array('context' => 'bibdk_provider')), 'status');
  }
}

function bibdk_provider_wayf_confirm_form($form, &$form_state, $uid, $timestamp, $token, $action = false) {
  $users = user_load_multiple(array($uid), array('status' => '1'));
  $account = reset($users);
  $hash = user_pass_rehash($account->pass, $timestamp, $account->login);
  if (!$action && $hash === $token) {
    $form['message'] = array('#markup' => t('<p>This is a one-time login for %user_name and will expire on %expiration_date.</p><p>Click on this button to log in to the site and verify your wayf login.</p>', array('%user_name' => $account->mail, '%expiration_date' => format_date($timestamp + 86400))));
    $form['help'] = array('#markup' => '<p>' . t('This login can be used only once.') . '</p>');
    $form['actions'] = array('#type' => 'actions');
    $form['actions']['submit'] = array('#type' => 'submit', '#value' => t('Log in'));
    $form['#action'] = url("user/wayf/$uid/confirm/$timestamp/$token/login");
    return $form;
  }
  else if ($hash === $token) {
    $_SESSION['accept_wayf'] = $account->data['accept_wayf'];
    $_SESSION['wayf_login'] = $account->data['wayf_login'];
    // Remove existing binding
    $verified_email = ding_provider_invoke('wayf', 'verify', $account->data['accept_wayf']['pass'], $account->data['wayf_login']['login_type']);
    if ($verified_email){
      $verified_email = ding_provider_invoke('wayf', 'verify', $account->data['accept_wayf']['pass'], $account->data['wayf_login']['login_type']);
      bibdk_provider_wayf_delete($verified_email);
    }
    // Create new binding
    bibdk_provider_accept_form_bind_and_login($account);
  }
  else {
    drupal_set_message(t('The acceptlink is either not valid, or has been used before', array(), array('context' => 'bibdk_provider')), 'error');
    drupal_access_denied();
    exit;
  }

  drupal_goto('<front>');
}

/**
 * For existing bibdk_user. Bind wayf_id and log user in
 */
function bibdk_provider_accept_form_bind_and_login($account) {

  if (isset($account->data['accept_wayf']['pass'])) {
    $wayf_id = $account->data['accept_wayf']['pass'];
    $login_type = isset($account->data['wayf_login']['login_type']) ? $account->data['wayf_login']['login_type'] : 'wayf_id';
    if(bibdk_provider_wayf_bind($account->mail, $wayf_id, $login_type)) {
      $attributes['eduPersonTargetedID'][0] = $wayf_id;
      $attributes['mail'][0] = strtolower($account->mail);

      $function = 'ding_wayf_login';
      if (function_exists($function)) {
        // log user in
        $function($attributes);
      }
      else {
        // this is an ERROR - login function was not found
        drupal_set_message(t('Internal error please contact administrator if problem persists', array(), array('context' => 'ding_wayf')), 'error');
        watchdog('wayf login', $function . ' WAS NOT FOUND ', array(), WATCHDOG_ERROR);
      }
    }
    else {
      // wayf bind did not succeed.
      // notice for the user
      drupal_set_message(t('Sorry we could not bind your wayf_id with your account', array(), array('context' => 'ding_wayf')), 'warning');
      // error for the log
      watchdog('wayf login', 'bibdk_provider::bind_wayf failed in binding %username with %wayf_id', array('%username' => $username, '%wayf_id' => $wayf_id), WATCHDOG_ERROR);
    }
  }
}

/**
 * Log in user with wayf
 * @see ding_wayf_login
 *
 * @param $wayf_id
 * @param $mail
 */
function bibdk_provider_wayf_login($wayf_id, $mail){
  $attributes = array(
    'eduPersonTargetedID' => array($wayf_id),
    'mail' => array($mail),
  );
  if (function_exists('ding_wayf_login')) {
    ding_wayf_login($attributes);
  }
  else {
    drupal_set_message(t('Internal error please contact administrator if problem persists', array(), array('context' => 'ding_wayf')), 'error');
    watchdog('wayf login', 'ding_wayf_login WAS NOT FOUND ', array(), WATCHDOG_ERROR);
  }
}


/**
 * Add wayf parameters to SESSION
 *
 * */
function bibdk_provider_wayf_set_session($name, $pass, $status = 'no_user') {
  if (!isset($_SESSION)) {
    drupal_session_initialize();
    $_SESSION['accept_wayf'] = array();
  }
  $_SESSION['accept_wayf']['name'] = $name;
  $_SESSION['accept_wayf']['pass'] = $pass;
  $_SESSION['accept_wayf']['status'] = $status;
}

/**
 * Bind provider user with wayf
 * @param $username
 * @return bool|mixed
 *
 * TODO: is this used
 */
function bibdk_provider_wayf_bind_wayf($username) {
  $wayfid = isset($_SESSION['wayf_login']['eduPersonTargetedID'][0]) ? $_SESSION['wayf_login']['eduPersonTargetedID'][0] : NULL;
  if (empty($wayfid)) {
    return FALSE;
  }

  if (ding_provider_implements('wayf', 'bind')) {
    $success = ding_provider_invoke('wayf', 'bind', $username, $wayfid);
  }

  return $success;
}

/**
 *
 * @param type $name
 * @param type $wayfid
 * @return type
 */
function bibdk_provider_wayf_bind($name, $wayfid, $loginType = 'wayf_id') {

  try {
    $ret = BibdkUser::instance()->bindWayf($name, $wayfid, $loginType);

    return $ret;
  } catch (Exception $e) {
    return FALSE;
  }
}

/** Verify that a user with given $wayfid exists
 *
 * @param string $wayfId
 * @return mixed; string(userid) if user exists; bool(FALSE) if not
 */
function bibdk_provider_wayf_verify($wayfId) {
  if (!isset($_SESSION['wayf_login']['login_type'])) {
    return FALSE;
  }
  try {
    $ret = BibdkUser::instance()->verifyWayf($wayfId, $_SESSION['wayf_login']['login_type']);
    return $ret;
  } catch (Exception $e) {
    return FALSE;
  }
}

/**
 *
 * @param type $name
 * @return type
 */
function bibdk_provider_wayf_delete($name) {
  return BibdkUser::instance()->deleteWayf($name);
}


/** Helper function to generate mail content
 * @param $key
 * @param null $langcode
 * @param array $variables
 * @param bool $replace
 * @return mixed|null|string
 */
function _bibdk_provider_wayf_mail_text($key, $language = null, $variables = array(), $replace = true){
  $langcode = isset($language) ? $language->language : NULL;
  switch($key){
    case 'wayf_new_user_subject' :
      $text = t('Notification from [site:name]', array(), array('langcode' => $langcode));
      break;
    case 'wayf_new_user_body' :
      $text = t("Dear ['user:name']\n\n wayf_account_created.", array(), array('langcode' => $langcode, 'context' => 'ding_wayf'));
      break;

    case 'wayf_confirm_user_subject' :
      $text = t('confirm wayf binding for [user:name] at [site:name]', array(), array('langcode' => $langcode));
      break;
    case 'wayf_confirm_user_body' :
      $text = t("Thank you for for using wayf at [site:name]. You may now confirm by clicking this link or copying and pasting it to your browser:

[user:confirm_wayf_url]

This link can only be used once to log in and will log you in, and make sure you can user wayf in the future", array(), array('langcode' => $langcode));
      break;
  }

  if ($replace) {
    // We do not sanitize the token replacement, since the output of this
    // replacement is intended for an e-mail message, not a web browser.
    return token_replace($text, $variables, array('language' => $language, 'callback' => 'bibdk_provider_mail_tokens', 'sanitize' => FALSE, 'clear' => TRUE));
  }

  return $text;
}



/**
 * Token callback to add tokens for bibdk_provider mails.
 */
function bibdk_provider_mail_tokens(&$replacements, $data, $options) {
  if (isset($data['user'])) {
    $replacements['[user:confirm_wayf_url]'] = bibdk_provider_wayf_confirm_url($data['user']);
  }
}

function bibdk_provider_wayf_confirm_url($account){
  $timestamp = REQUEST_TIME;
  $hash = user_pass_rehash($account->pass, $timestamp, $account->login);
  return url("user/wayf/$account->uid/confirm/$timestamp/" . $hash, array('absolute' => TRUE));
}

/**
 * Implements hook_ding_wayf_attributes().
 *
 * Bibliotek.dk needs unique WAYF identifier called 'eduPersonTargetedID' and
 * email address for WAYF authentication.
 */
function bibdk_provider_ding_wayf_attributes() {
  return array(
    'eduPersonTargetedID' => array(),
    'mail' => array('authname' => TRUE),
  );
}
// 650 lines
