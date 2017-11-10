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
function bibdk_heimdal_handle_login_request($uuid){
  $message = '';
  $row = array();

  try {
    $row = heimdalDatabase::get($uuid);
  }
  catch (Exception $e){
    watchdog('heimdal', 'DATABASE EXCEPTION: %message%', array('%message%' => $e->getMessage()), WATCHDOG_ERROR);
    $message = bibdk_heimdal_exception_message();
  }

  if(empty($row)){
    // row was not found - it has probably been deleted because it was too old
    $message = bibdk_heimdal_link_deprecated_message();
  }

  if(!empty($row) && !bibdk_heimdal_check_timestamp($row['date'])){
    // message is to old
    $message = bibdk_heimdal_link_deprecated_message();
  }

  $response = bibdk_heimdal_do_insert_culr($row);
  if(!bibdk_heimcdal_pages_check_insert_response($response)) {
    // something went wrong when creating culr account
    $message = bibdk_heimdal_pages_no_culr_message();
  }

  // row has been fetched - this is a one time link - delete on database
  heimdalDatabase::deleteByUUID($uuid);

  // if message is set something has gone wrong. Set a message and return to
  // fromtpage
  if(!empty($message)){
    drupal_set_message($message, 'warning');
    drupal_goto('<front>');
  }

  // all is good - set a welcome message and redirect to heimdal access platform
  // for another login attempt
  $message = bibdk_heimdal_pages_welcome_message();
  drupal_set_message($message);
  $link = bibdk_heimdal_pages_get_login_link();
  drupal_goto($link);
}

/**
 * Get a message
 * @return null|string
 */
function bibdk_heimdal_pages_welcome_message() {
  $message = t('welcome_to_single_sign_on', array(), array('context'=>'heimdal'));
  return $message;
}

/**
 * Get a message
 * @return null|string
 */
function bibdk_heimdal_pages_no_culr_message(){
  $message = t('bibdk_heimdal_no_culr_helptext', array(), array('context' => 'heimdal'));
  return $message;
}

/**
 * check response from createAccount action on culr
 * @param $response
 * @return bool
 */
function bibdk_heimcdal_pages_check_insert_response($response){
  // @TODO implement
  return TRUE;
}

/**
 * Check if given time is more than a day old
 * @param int $time
 * @return bool
 */
function bibdk_heimdal_check_timestamp(int $time){
  $now = time();
  // 86400 seconds = one day
  if($now - $time > 86400){
    return FALSE;
  }

  return TRUE;
}

/**
 * Let openuserinfo do an insert(createAccount) on culr.
 * @param $row
 * @return array
 */
function bibdk_heimdal_do_insert_culr($row){
  $agencies = unserialize($row['libraries']);
  if(empty($agencies)){
    $agencies = array();
  }
  $response = array();
  $mail = $row['email'];
  foreach ($agencies as $agency) {
    $borrowerId = $agency['userId'];
    $uidType = $agency['userIdType'];
    $response[$agency['agencyId']][] = BibdkUser::instance()->insertCulr($mail, $borrowerId, $uidType);
  }
  return $response;
}

/**
 * Get a login link for heimdal access platform
 * @return string
 */
function bibdk_heimdal_pages_get_login_link() {
  $config = variable_get('ding_wayf', NULL);
  $token = variable_get('heimdal_access_token');
  $heimdal_link = $config['hosturl'] . $config['loginpath'] . '?token=' . $token . '&destination=heimdal/login';
  return $heimdal_link;
}

/**
 * Get a message
 * @return null|string
 */
function bibdk_heimdal_exception_message(){
  $message = t('bibdk_heimdal_exception_message', array(), array('context'=>'heimdal'));
  return $message;
}

/**
 * Get a message
 * @return null|string
 */
function bibdk_heimdal_link_deprecated_message(){
  $message = t('bibdk_heimdal_old_message_link', array(), array('context' => 'heimdal'));
  return $message;
}
