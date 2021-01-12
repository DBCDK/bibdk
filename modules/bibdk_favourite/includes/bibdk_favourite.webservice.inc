<?php

/**
 * @file webservice related methods.
 */

/**
 * Save the given branchid on the webservice
 *
 * @param $branchId
 * @return null|string
 */
function bibdk_favourite_save_favourite_on_webservice($branchId) {
  $response = _bibdk_favourite_save_on_webservice($branchId);
  $message = '';

  if ($response['status'] != 'error') {
    $new_agency = bibdk_favourite_parse_agencies($response['response']);

    $check = bibdk_favourite_check_agencies($new_agency, TRUE);
    if ($check) {
      global $language;
      bibdk_favourite_add_favourite_to_session($check[$branchId]);
      $bibname = $check[$branchId]->getBranch()->getBranchName($language->language);
      $message = t('@bibname has been added to your favourite libraries', array('@bibname' => $bibname));
    }
  }
  else {
    $message = t($response['response']);
  }

  return $message;
}

/**
 * Add favourite library to sesssion
 * */
function bibdk_favourite_add_favourite_to_session($favourite) {
  if (!isset($_SESSION)) {
    drupal_session_initialize();
  }

  // special case. user logs in and selects a favourite BEFORE
  // going to favourite_list
  if (!isset($_SESSION['bibdk_favourites'])) {
    $_SESSION['bibdk_favourites'] = array();
    _bibdk_favourite_set_agencies();
  }

  $branchId = $favourite->getBranchId();

  if (!isset($_SESSION['bibdk_favourites'][$branchId])) {
    $_SESSION['bibdk_favourites'][$branchId] = serialize($favourite);
  }
}

/**
 * Delete user on webservice
 *
 * @global $user
 * @param  $branchId
 * @return FALSE if user is not logged in or is not ding_provider_user
 * or something goes wrong. TRUE if all went well
 */
function _bibdk_favourite_delete_on_webservice($branchId) {
  global $user;
  try {
    $creds = ding_user_get_creds($user);
  }
  catch (Exception $e) {
    return FALSE;
  }
  $response = ding_provider_invoke('user', 'delete_favourite', $creds['name'], $branchId);
  return $response;
}

/**
 * Save user on webservice
 *
 * @param string $agencyId
 * @global $user
 * @return array['status','response']; status: error or success, response: string (on error) or xml (on success)
 */
function _bibdk_favourite_save_on_webservice($agencyId) {
  // check if user is logged in and if so if user is provider user
  global $user;
  try {
    $creds = ding_user_get_creds($user);
  }
  catch (Exception $e) {
    return FALSE;
  }
  $response = ding_provider_invoke('user', 'add_favourite', $creds['name'], $agencyId);
  return $response;
}

/**
 * Get favourite agencies for the user
 *
 * @return array
 * @throws \GuzzleHttp\Exception\GuzzleException
 */
function _bibdk_favourite_get_from_webservice() {
  global $user;

  if ($user->uid != 1) {
    try {
      $creds = ding_user_get_creds($user);
    } catch (Exception $e) {
      // do nothing
    }
  }
  if (empty($creds)) {
    return array();
  }

  $xml = ding_provider_invoke('user', 'get_favourites', $creds['name']);
  module_load_include('inc', 'bibdk_favourite', 'includes/bibdk_favourite.agencies');
  $saved_agencies = bibdk_favourite_parse_agencies($xml);

  if (!$saved_agencies) {
    return array();
  }

  $agencies = array();
  foreach ($saved_agencies as $key => $agency) {
    if (isset($agency['oui:agencyId'])) {
      try {
        $response = vip_core_findlibrary($agency['oui:agencyId']);
        $favouriteAgency = new FavouriteAgency($agency, $response);
      } catch (Exception $e) {
        drupal_set_message($e->getMessage(), 'error');
      }
    }

    if (isset($favouriteAgency)) {
      $saved_agencies[$key]['oui:userData'];
      // Handle if data is encrypted.
      if ($saved_agencies[$key]['oui:userData'] && variable_get('bibdk_provider_favourite_use_encryption', FALSE)) {
        $saved_agencies[$key]['oui:userData'] = bibdk_provider_decrypt_data($saved_agencies[$key]['oui:userData']);
      }
      $user_data = $saved_agencies[$key]['oui:userData'];
      $favouriteAgency->userdata = array();
      if ($user_data) {
        $favouriteAgency->userData = unserialize($user_data);
      }
      $favouriteAgency->orderLibrary = $saved_agencies[$key]['oui:orderAgency'];
      $agencies[$agency['oui:agencyId']] = $favouriteAgency;
      $saved_agencies[$key]['agencyBranch'] = $favouriteAgency;
    }
  }
  return bibdk_favourite_check_agencies($saved_agencies);
}

/**
 * Delete favourite from SESSION and on webservice
 *
 * @param string $branchId
 * @return boolean
 */
function bibdk_favourite_delete_favourite_from_session($branchId) {
  unset($_SESSION['bibdk_favourites']);

  $ret = _bibdk_favourite_delete_on_webservice($branchId);
  if ($ret && isset($_SESSION['bibdk_favourites'][$branchId])) {
    unset($_SESSION['bibdk_favourites'][$branchId]);
  }

  return $ret;
}

/**
 * Get favourites from webservice and add them to session
 * */
function _bibdk_favourite_set_agencies() {
  // try to get from webservice
  $agencies = _bibdk_favourite_get_from_webservice();
  if (is_array($agencies)) {
    // Delete old favourites stored in session.
    $_SESSION['bibdk_favourites'] = array();
    // Add agencies to session.
    foreach ($agencies as $favourite) {
      bibdk_favourite_add_favourite_to_session($favourite);
    }
  }
}

/**
 * @param $saved_agencies
 * @param false $add
 * @return array
 * @throws \GuzzleHttp\Exception\GuzzleException
 */
function bibdk_favourite_check_agencies($saved_agencies, $add = FALSE) {
  if (!$saved_agencies) {
    $message = _bibdk_favourite_set_error_text();
    drupal_set_message($message, 'error');
    return array();
  }

  $agencies = array();
  $order_agency = FALSE;
  foreach ($saved_agencies as $key => $agency) {

    if ($agency['oui:orderAgency'] == 'TRUE') {
      $order_agency = TRUE;
    }
    $agencies[$agency['oui:agencyId']] = $agency['agencyBranch'];
  }
  if (!$order_agency && !empty($agencies) && !$add) {
    // no orderagency is set pick a new favourite as orderagency
    $fav = current($agencies);
    if (bibdk_favourite_set_favourite($fav->getAgencyId())) {
      $fav->orderAgency = 'TRUE';
    }
  }

  return $agencies;
}
