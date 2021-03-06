<?php


/**
 * Implements hook_provider_user_authenticate().
 *
 * @param String $name
 * @param String $pass
 * @return array
 */
function bibdk_provider_user_authenticate($name, $pass) {

  // USE LOWERCASE (NO uppercase)
  $name = mb_strtolower($name);

  $return = array(
    'success' => FALSE,
  );

  if (BibdkUser::instance()->login($name, $pass)) {
    $return['creds'] = array(
      'name' => $name,
      'pass' => $pass,
    );

    $return['user'] = array(
      'data' => array('display_name' => $name),
      'mail' => $name,
    );

    $return['authname'] = $name;

    $return['success'] = TRUE;
  }
  else {
    /* advanced regex to match e-mail addresses including obscure usernames and
      at server which only has an IPv4 address */
    $is_email = !preg_match("/[a-z0-9!#$%&'*+\/=?^_`\{|\}~-]+(?:\.[a-z0-9!#$%&'*+\/=?^_`\{|\}~-]+)*@(?:(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?)/", strtolower($name));

    /* if all characters in username or password is capitalized caps lock may be on */
    $capslock_on = preg_match('/[[:alpha:]]/', $name) && $name == strtoupper($name) || preg_match('/[[:alpha:]]/', $pass) && $pass == strtoupper($pass);

    /* if password is 4 or 5 digits */
    $is_pincode = preg_match('/^[[:digit:]]{4,5}$/', $pass);

    if ($is_email) {
      $return['messages'][] = t('Your username is your email-address.');
    }
    if ($capslock_on) {
      $return['messages'][] = t('Remember to turn off caps lock.');
    }
    if ($is_pincode) {
      $return['messages'][] = t('Use your Bibliotek.dk password, not your PIN code for your local library.');
    }
  }
  return $return;
}

/**
 * @param $mail_me
 * @param $account
 */
function bibdk_provider_user_mail_me($mail_me, $account) {
  $params['account'] = $account;
  drupal_mail('bibdk_provider', $mail_me->key, $account->mail, user_preferred_language($account), $params, 'no_reply@dbc.dk');
}

function _bibdk_provider_wayf_new_user_message($account, $langcode) {
  return t("Dear !username\n\n wayf_account_created.", array('!username' => $account->mail), array('langcode' => $langcode, 'context' => 'ding_wayf'));
}

//TODO this function should do something
/**
 * @return bool
 */
function bibdk_provider_is_authenticated() {
  return TRUE;
}

/** \brief check if user is logged in and if so if user is provider user
 *
 * @global $user
 * @return boolean
 */
function _bibdk_provider_user_check() {
  global $user;
  if ($user->uid) {
    if (ding_user_is_provider_user($user)) {
      // user is logged in and is provider user
      return TRUE;
    }
    // user is not provider user
    return FALSE;
  }
  // user is not logged in
  return FALSE;
}


/************** VOXB ****************/

function bibdk_provider_user_verify_voxb($voxbid){
  return BibdkUser::instance()->verifyVoxb($voxbid);
}

function bibdk_provider_user_get_voxb($username){
    return BibdkUser::instance()->getVoxbId($username);
}

function bibdk_provider_user_bind_voxb($userName,$voxbId){
    return BibdkUser::instance()->bindVoxb($userName,$voxbId);
}

/************START SETTING(S)****************/

/**
 * Get setting for given users settingtype
 *
 * @param $username
 * @param $settingtype
 * @return bool|string (might be empty)
 */
function bibdk_provider_user_get_setting($username, $settingtype) {
  return BibdkUser::instance()->getUserSetting($username, $settingtype);
}

  /**
   * @param $username
   * @param $settingtype
   * @param $settingString
   * @return bool
   */
function bibdk_provider_user_set_setting($username, $settingtype, $settingString) {
  return BibdkUser::instance()->setUserSetting($username, $settingtype, $settingString);
}

/**
 * Delete setting for given users settingtype
 *
 * @param $username
 * @param $settingtype
 * @return bool
 */
function bibdk_provider_user_delete_setting($username, $settingtype) {
  return BibdkUser::instance()->deleteSetting($username, $settingtype);
}

/************ END SETTING(S) ****************/


/************** FAVOURITEST ********************/
/**
 * @param $name
 * @param $agencyid
 * @return bool
 */
function bibdk_provider_user_set_favourite($name, $agencyid) {
  if (!(_bibdk_provider_user_check())) {
    return FALSE;
  }
  // Use encryption or not has to be global, so use setting to control it.
  $encrypted = variable_get('bibdk_provider_favourite_use_encryption', FALSE);
  return BibdkUser::instance()->setFavourite($name, $agencyid, $encrypted);
}

/**
 * @param $name
 * @param $agencyid
 * @return bool|array
 */
function bibdk_provider_user_add_favourite($name, $agencyid) {
  if (!(_bibdk_provider_user_check())) {
    return FALSE;
  }
  // Use encryption or not has to be global, so use setting to control it.
  $encrypted = variable_get('bibdk_provider_favourite_use_encryption', FALSE);
  return BibdkUser::instance()->addFavourite($name, $agencyid, $encrypted);
}

/**
 * @param $name
 * @param $agencyid
 * @return bool|array
 */
function bibdk_provider_user_delete_favourite($name, $agencyid) {
  if (!(_bibdk_provider_user_check())) {
    return FALSE;
  }
  // Use encryption or not has to be global, so use setting to control it.
  $encrypted = variable_get('bibdk_provider_favourite_use_encryption', FALSE);
  return BibdkUser::instance()->deleteFavourite($name, $agencyid, $encrypted);
}

/**
 * Get favourite agencies for given user
 * @param string name
 *   The userId (email).
 *
 * @return bool|string
 *   List of all favourites user has.
 */
function bibdk_provider_user_get_favourites($name) {
  // Use encryption or not has to be global, so use setting to control it.
  $encrypted = variable_get('bibdk_provider_favourite_use_encryption', FALSE);
  return BibdkUser::instance()->getFavourites($name, $encrypted);
}

/**
 * @param $name
 * @param $agencyid
 * @param $data
 * @return bool|string
 */
function bibdk_provider_user_save_favourite_data($name, $agencyid, $data) {
  // Use encryption or not has to be global, so use setting to control it.
  $encrypted = variable_get('bibdk_provider_favourite_use_encryption', FALSE);
  return BibdkUser::instance()->saveFavouriteData($name, $agencyid, $data, $encrypted);
}

/************** END FAVOURITEST ********************/

/**
 * Get cart content from provider
 *
 * @param $name
 * @return array|bool
 */
function bibdk_provider_user_get_cart($name) {
  static $response;
  if(empty($response)) {
    $response = BibdkUser::instance()->getCart($name);
  }
  return $response;
}

/**
 * Get cart count from provider
 *
 * @param $name
 * @return array|bool
 */
function bibdk_provider_user_get_cart_count($name) {
  return BibdkUser::instance()->getCartCount($name);
}

/**
 * Add Content to cart
 *
 * @param $name
 * @param $content string|array
 * @return array|bool
 */
function bibdk_provider_user_add_cart_content($name, $content) {
  return BibdkUser::instance()->addCartContent($name, $content);
}

/**
 * Update Content to cart
 *
 * @param $name
 * @param $content string|array
 * @return array|bool
 */
function bibdk_provider_user_update_cart_content($name, $content) {
  return BibdkUser::instance()->updateCartContent($name, $content);
}

/**
 * Remove content from cart
 *
 * @param $name
 * @param $content string|array
 * @return array|bool
 */
function bibdk_provider_user_remove_cart_content($name, $content) {
  return BibdkUser::instance()->removeCartContent($name, $content);
}

/**
 * Get search history from provider
 *
 * @param $name
 * @return array|bool
 */
function bibdk_provider_user_get_searchhistory($name) {
  return BibdkUser::instance()->getSearchHistory($name);
}

/**
 * Add Content to searchhistory
 *
 * @param $name
 * @param $content string|array
 * @return array|bool
 */
function bibdk_provider_user_add_searchhistory($name, $content) {
  return BibdkUser::instance()->addSearchHistory($name, $content);
}

/**
 * Remove content from search history
 *
 * @param $name
 * @param $content string|array
 * @return array|bool
 */
function bibdk_provider_user_remove_searchhistory($name, $content) {
  return BibdkUser::instance()->removeSearchHistory($name, $content);
}

function bibdk_provider_user_verify($name) {
  //$response = NULL;
  static $response;
  if (!isset($response)) {
    $response = BibdkUser::instance()->verify($name);
  }
  return $response;
}

/**
 * @param $name
 * @param $pass
 * @return bool
 */
function bibdk_provider_user_create_account($name, $pass) {

  $userCreated = BibdkUser::instance()->create($name, $pass);

  if ($userCreated) {
    // we want new users to have the advanced search form expanded
    // except for the frontpage.
    bibdk_usersettings_user_settings_set(
      'bibdk_custom_search_start_expand_bog',
      's:19:"bibdk_frontpage/bog";'
    );
    bibdk_usersettings_user_settings_set(
      'bibdk_custom_search_start_expand_artikel',
      's:23:"bibdk_frontpage/artikel";'
    );
    bibdk_usersettings_user_settings_set(
      'bibdk_custom_search_start_expand_film',
      's:20:"bibdk_frontpage/film";'
    );
    bibdk_usersettings_user_settings_set(
      'bibdk_custom_search_start_expand_net',
      's:19:"bibdk_frontpage/net";'
    );
    bibdk_usersettings_user_settings_set(
      'bibdk_custom_search_start_expand_spil',
      's:20:"bibdk_frontpage/spil";'
    );
    bibdk_usersettings_user_settings_set(
      'bibdk_custom_search_start_expand_musik',
      's:21:"bibdk_frontpage/musik";'
    );
    bibdk_usersettings_user_settings_set(
      'bibdk_custom_search_start_expand_noder',
      's:21:"bibdk_frontpage/noder";'
    );
  }
  return $userCreated;
}

/**
 * @param $name
 * @param $pass
 * @return bool
 */
function bibdk_provider_user_update_password($name, $pass) {
  return BibdkUser::instance()->update_password($name, $pass);
}

/**
 * @param $name
 * @return bool
 */
function bibdk_provider_user_delete_account($name) {
  return BibdkUser::instance()->delete($name);
}

/**
 * Delete an accoutn on culr (culr.addi.dk) via openuserinfo webservice.
 * @param string $name
 *   The username to delete
 * @return bool
 *   True on success false if not
 */
function bibdk_provider_delete_culr_user($name){
  return BibdkUser::instance()->deleteCulrUser($name);
}


/**
 * Get the status of the GDPR consent
 *
 * @param string $name
 *   The ID of users, actually their name but we call it name for consistency.
 *
 * @return bool
 *   True of user is given consent, false otherwise.
 */
function bibdk_provider_user_get_gdpr_consent($name) {
  return BibdkUser::instance()->getGdprConsent($name);
}

/**
 * Get the status of the GDPR consent
 *
 * @param string $name
 *   The ID of users, actually their name but we call it name for consistency.
 * @param boolean $consent
 *   The consent status to set on user.
 *
 * @return bool
 *   True of user is given consent, false otherwise.
 */
function bibdk_provider_user_set_gdpr_consent($name, $consent) {
  return BibdkUser::instance()->setGdprConsent($name, $consent);
}
