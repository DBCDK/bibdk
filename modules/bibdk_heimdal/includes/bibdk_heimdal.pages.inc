<?php

/**
 * @file
 *
 * Functions to handle a request for login via a confirmation mail
 */

module_load_include('inc', 'bibdk_heimdal', 'includes/heimdalDatabase');

/**
 * Page callback (heimdal/loginrequest/%). Get saved one time login information
 * from database and act on it
 *
 * @param $uuid
 *   unique identifier from email link
 */
function bibdk_heimdal_handle_login_request($uuid) {
  $message = '';
  $row = array();
  try {
    $row = heimdalDatabase::get($uuid);
  } catch (Exception $e) {
    watchdog('heimdal', 'DATABASE EXCEPTION: %message%', array('%message%' => $e->getMessage()), WATCHDOG_ERROR);
    $message = bibdk_heimdal_exception_message();
    bibdk_heimdal_cleanup_and_exit($message);
  }

  // set the access token (from the original login) retrieved from database
  $_SESSION['heimdal']['access_token'] = $row['access_token'];

  // row has been fetched - this is a one time link - delete on database
  heimdalDatabase::deleteByUUID($uuid);
  if (empty($row)) {
    // row was not found - it has probably been deleted because it was too old
    $message = bibdk_heimdal_link_deprecated_message();
  }

  if (!empty($row) && !bibdk_heimdal_check_timestamp($row['date'])) {
    // message is to old
    $message = bibdk_heimdal_link_deprecated_message();
  }

  if (!empty($message)) {
    bibdk_heimdal_cleanup_and_exit($message);
  }
  $response = bibdk_heimdal_do_insert_culr($row);
  if (bibdk_heimcdal_pages_check_insert_response($response) !== TRUE) {
    // something went wrong when creating culr account
    // a message has been set for user @see bibdk_heimcdal_pages_check_insert_response($response)
    bibdk_heimdal_cleanup_and_exit($response['message']);
  }

  // if message is set something has gone wrong. Set a message and return to
  // fromtpage
  if (!empty($message)) {
    drupal_set_message($message, 'warning');
    drupal_goto('<front>');
  }

  $email = $row['email'];
  if (bibdk_heimdal_pages_create_bibdk_user($email)) {
    // all is good - set a welcome message and redirect to heimdal access platform
    // for another login attempt
    $message = bibdk_heimdal_pages_welcome_message();
    drupal_set_message($message);
    $link = bibdk_heimdal_pages_get_login_link();

    drupal_goto($link);
  }

  // user was not created on openuserinfo - set a  message and return to front
  drupal_set_message(bibdk_heimdal_pages_something_went_wrong_message(), 'error');
  drupal_goto('<front>');
}

/**
 * Create a user on openuserinfo - if user doesn't already exist
 * @param string $mail
 *   Username
 */
function bibdk_heimdal_pages_create_bibdk_user($mail) {
  return ding_provider_invoke('heimdal', 'create_bibdk_user', $mail);
}

function bibdk_heimdal_pages_something_went_wrong_message() {
  $message = t('Something went wrong - please try again. Contact administrator if problem persists',
    array(), array('context' => 'heimdal'));
  return $message;
}

/**
 * Get a message
 * @return null|string
 */
function bibdk_heimdal_pages_welcome_message() {
  $message = t('welcome_to_single_sign_on', array(), array('context' => 'heimdal'));
  return $message;
}

/**
 * Get a message
 * @return null|string
 */
function bibdk_heimdal_pages_no_culr_message() {
  $message = t('bibdk_heimdal_no_culr_helptext', array(), array('context' => 'heimdal'));
  return $message;
}


/**
 * check response from createAccount action on culr
 * @param $response
 * @return bool
 */
function bibdk_heimcdal_pages_check_insert_response($response) {
  if ($response['status'] !== FALSE) {
    return TRUE;
  }
  // Something went wront - get the error message
  return $response['message'];
}

/**
 * Check if given time is more than a day old
 * @param int $time
 * @return bool
 */
function bibdk_heimdal_check_timestamp($time) {
  $now = time();
  // 86400 seconds = one day
  if ($now - $time > 86400) {
    return FALSE;
  }

  return TRUE;
}

/**
 * Let openuserinfo do an insert(createAccount) on culr.
 * @param $row
 * @return array|string
 */
function bibdk_heimdal_do_insert_culr($row) {
  $agencies = unserialize($row['libraries']);

  if (empty($agencies)) {
    return array();
  }
  $mail = $row['email'];

  // get en agency for insertion in culr
  $agency = bibdk_heimdal_get_unique_agency($agencies);
  if($agency === FALSE){
    return bibdk_heimdal_get_nogo_response();
  }


  $borrowerId = $agency['userId'];
  $uidType = $agency['userIdType'];
  $xml = BibdkUser::instance()->insertCulr($mail, $borrowerId, $uidType);

  return $xml;
}

/**
 * Culr doesn't handle agencies where no globalid is given - get an
 * abort message
 *
 * @return array
 *   message to abort
 */
function bibdk_heimdal_get_nogo_response() {
  return array(
    'status' => FALSE,
    'message' => bibdk_heimdal_pages_no_culr_message(),
  );
}

/**
 * Find an agency with userIdType CPR or CVR to use for global id in culr
 * @param array $agencies
 *   agencies from heimdal
 * @return array | bool
 *   an agency with userIdType CPR og CVR - if no agencies has that userIdType
 *   return FALSE to signal abort
 */
function bibdk_heimdal_get_unique_agency(array $agencies){
  foreach($agencies as $agency){
    if(isset($agency['userIdType']) && ($agency['userIdType'] === 'CPR' || $agency['userIdType'] === 'CVR' )){
      return $agency;
    }
  }
  // @TODO this is where we should abort. If no valid globalUid is found
  // @TODO there is no point in going on since culr can NOT match accounts
  // @TODO the solution is to get globalUid from culr for ALL libraries

  // no valid agencies found - abort
  return FALSE;
  // no agencies with cpr or cvr found - return first in array
  //return $agencies[0];
}

/**
 * Get a login link for heimdal access platform
 * @return string
 */
function bibdk_heimdal_pages_get_login_link() {

  return bibdk_heimdal_get_login_url('heimdal/login');

  /*$config = variable_get('ding_wayf', NULL);
  $token = variable_get('heimdal_access_token', NULL);
  if (empty($config) || empty($token)) {
    watchdog('heimdal', 'HEIMDAL is not configured', WATCHDOG_ERROR);
    return '';
  }
  $heimdal_link = $config['clientplatform'] . $config['loginpath'] . '?token=' . $token . '&destination=heimdal/login';
  return $heimdal_link;*/
}

/**
 * Get a message
 * @return null|string
 */
function bibdk_heimdal_exception_message() {
  $message = t('bibdk_heimdal_exception_message', array(), array('context' => 'heimdal'));
  return $message;
}

/**
 * Get a message
 * @return null|string
 */
function bibdk_heimdal_link_deprecated_message() {
  $message = t('bibdk_heimdal_old_message_link', array(), array('context' => 'heimdal'));
  return $message;
}
