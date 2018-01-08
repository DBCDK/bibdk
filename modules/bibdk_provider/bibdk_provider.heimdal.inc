<?php

/**
 * Authenticate the user. At this stage user has already been authenticated
 * by heimdal access platform. Further actions NEEDS user to be created on
 * openuserinfo, so basiccaly this is final check if all went well
 * @param $name
 * @param null $pass
 * @return array
 */
function bibdk_provider_heimdal_authenticate($name, $pass = null) {
  $return = array(
    'success' => FALSE,
  );

  if (BibdkUser::instance()->verify($name)) {
    $return['creds'] = array(
      'name' => $name,
      'pass' => 'test',
    );
    $return['user'] = array(
      'data' => array('display_name' => $name),
      'mail' => $name,
    );
    $return['authname'] = $name;
    $return['success'] = TRUE;
  }
  return $return;
}

/**
 * Set and return form_state for user_login via heimdal
 *
 * @param bibdkHeimdalUser $heimdalUser
 * @param $notify
 *   not used here - for provider compatibility
 * @return mixed
 */
function bibdk_provider_heimdal_login_creds($heimdalUser, $notify = null) {
  // we are logged in with heimdal
  bibdk_heimdal_provider_set_session('logged_in', TRUE);
  // set authentication provider
  $form_state['values']['authentication_provider'] = 'heimdal';
  // set build_info  for further processing (see bibdk_heimdal_form_alter())
  // see also bibdk_provider_heimdal_validate below
  $form_state['build_info']['args'][] = $heimdalUser;

  /** @var array $usernames */
  $usernames = $heimdalUser->getBibdkUsers();
  $username_to_use = bibdk_heimdal_provider_username_from_session($usernames);


  // USE CASE one user is found from culr. We exported the user ouselves,
  // so we know he is on openuserinfo - log him in
  if (!empty($username_to_use)) {
    // check or create user
    if(bibdk_provider_heimdal_create_bibdk_user($username_to_use)) {
      $culr_agencies = $heimdalUser->getLibraries();
      // do a check on favourites
      bibdk_provider_heimdal_favourite_check($username_to_use, $culr_agencies);
      // ONE user is found - user is already approved - log him in
      $form_state['values']['name'] = $username_to_use;
      $form_state['values']['mail'] = $username_to_use;
      $form_state['values']['pass'] = 'fisk';
    }
  }
  else {
    if (count($usernames) > 1) {
      // set action to perform
      bibdk_heimdal_provider_set_session('action', 'select_email');
      // we also need the usernames for a selection
      bibdk_heimdal_provider_set_session('select_from_emails', $usernames);
    }
    else {
      if (count($usernames) == 0) {
        bibdk_heimdal_provider_set_session('action', 'write_email');
      }
    }
  }
  return $form_state;
}



/**
 * Create a user on openuserinfo - if user doesn't already exist
 * @param string $mail
 *   Username
 */
function bibdk_provider_heimdal_create_bibdk_user($mail) {
  if (!BibdkUser::instance()->verify($mail)) {
    // user does not exist - create
    // make a random password
    $pass = user_password();
    return bibdk_provider_user_create_account($mail, $pass);
  }
  return TRUE;
}

/**
 * Get the username to use for login.
 *
 * @param array $usernames
 *   one or more usernames to pick from
 * @return string
 *   The username to use or empty string if not found
 */
function bibdk_heimdal_provider_username_from_session(array $usernames) {
  if (count($usernames) == 1) {
    return $usernames[0];
  }

  // value in cookie is md5
  $md5array = array();
  foreach($usernames as $key=>$val){
    $md5array[md5($val)] = $val;
  }


  if (isset($_COOKIE['Drupal_visitor_user_selected_email'])) {
    $mail = $_COOKIE['Drupal_visitor_user_selected_email'];
    // paranoia check - on a public computer user might change
    if (!isset($md5array[$mail])) {
      user_cookie_delete('user_selected_email');
      return '';
    }

    return $md5array[$mail];
  }

  return '';
}


/**
 * Check if any of the libraries from culr are NOT saved as favourite
 * on bibdk user - if so add them to SESSION for later handling
 * @param $username
 * @param $culragencies
 * @return array
 *   The libraries that are NOT in users favourites
 */
function bibdk_provider_heimdal_favourite_check($username, $culragencies) {
  $bibdk_favourites_xml = BibdkUser::instance()->getFavourites($username);
  $bibdk_favourites = bibdk_favourite_parse_agencies($bibdk_favourites_xml);
  // check if ALL culr agencies is a bibdk_favourite
  $favourites_to_add = array();
  $culr_agency_id = variable_get('bibdk_provider_culr_agency', NULL);
  foreach ($culragencies as $agency) {
    $agencyId = $agency['agencyId'];
    // we do NOT want to add 190101 - it is agencyId for bibliotek.dk
    if (empty($bibdk_favourites[$agencyId]) && $agencyId !== $culr_agency_id) {
      $favourites_to_add[] = $agency;
    }
  }
  bibdk_heimdal_provider_set_session('faveourites_to_handle', $favourites_to_add);
}

function bibdk_provider_heimdal_validate($form, &$form_state){
  $form_state['values']['authentication_provider'] = 'heimdal';
}

/**
 * Set a session variable
 * @param string $key
 * @param mixed $value
 */
function bibdk_heimdal_provider_set_session($key, $value) {
  $_SESSION['heimdal'][$key] = $value;
}
