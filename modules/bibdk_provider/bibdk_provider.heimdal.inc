<?php

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
    $culr_agencies = $heimdalUser->getLibraries();
    // do a check on favourites
    bibdk_provider_heimdal_favourite_check($username_to_use, $culr_agencies);
    // ONE user is found - user is already approved - log him in
    $form_state['values']['name'] = $username_to_use;
    $form_state['values']['mail'] = $username_to_use;
    $form_state['values']['pass'] = 'fisk';
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

  // outcommented - used while developing
  // @TODO delete
// USE SESSION WHILE DEVELOPING TODO use cookie when done
  /* if(isset($_SESSION['heimdal']['selected_email'])){
     // set selected email in a cookie so user selected is saved
     // across sessions .. @TODO is that persistent enough ??
     $mail = $_SESSION['heimdal']['selected_email'];
     //unset($_SESSION['heimdal']['selected_email']);
     return $mail;
   }*/

  if (isset($_COOKIE['Drupal_visitor_user_selected_email'])) {
    $mail = $_COOKIE['Drupal_visitor_user_selected_email'];
    // paranoia check - on a public computer user might change
    if (!in_array($mail, $usernames)) {
      user_cookie_delete('user_selected_email');
      return '';
    }

    return $mail;
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
  foreach ($culragencies as $agency) {
    $agencyId = $agency['agencyId'];
    // we do NOT want to add 190101 - it is agencyId for bibliotek.dk
    if (empty($bibdk_favourites[$agencyId]) && $agencyId !== '190101') {
      $favourites_to_add[] = $agency;
    }
  }
  bibdk_heimdal_provider_set_session('faveourites_to_handle', $favourites_to_add);
}

/**
 * Keep track of session variable.
 *
 * @param
 * @return string - session variable
 */
function bibdk_heimdal_provider_set_session($key, $value) {
  $_SESSION['heimdal'][$key] = $value;
}

/**
 * Custom validation for heimdal login
 *
 * @param $form
 * @param $form_state
 */
function bibdk_provider_heimdal_validate($form, &$form_state) {
  if ($form_state['values']['authentication_provider'] !== 'heimdal') {
    return;
  }

  /** @var bibdkHeimdalUser $heimdalUser */
  $heimdalUser = $form_state['build_info']['args'][0];
}
