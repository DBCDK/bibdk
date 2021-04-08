<?php

/**
 * @file keeping the borchk related functionality
 */

function bibdk_favourite_borchk($form, $form_state) {
  // check for form errors
  $errors = form_get_errors();
  if (empty($errors)) {
    // validate via borchk
    // we know that userid, pincode and library code is set (required values on form)
    $libraryCode = $form_state['values']['branchid'];
    $userId = _bibdk_favourite_get_userid_from_array($form_state['values']);
    // get userOrderParameter
    $fields = bibdk_favourite_get_agency_fields($libraryCode);

    // Check for - isBorrowerCheckRequired
    if ($fields->isBorrowerCheckRequired() == true) {
      // Do validate userdata
      $userPincode = $form_state['values']['pincode'];
      $response = bibdk_borchk_request($userId, $userPincode, $libraryCode, 'bibliotek.dk');
      $result = bibdk_favourite_parse_borchk($response);
      if ($result['status'] == 'error') {
        form_set_error('userid', t($result['message'], array(), array('context' => 'bibdk_favourite_borchk')));
      }
    }
    else {
      // Dcd ,,o not validate userdata
    }
  }
}

/**
 * Helper function to get the userId out of a form_state
 *
 * @param $values
 * @return string|null
 */
function _bibdk_favourite_get_userid_from_array($values) {
  $possible_userId_keys = array('cpr', 'userId', 'cardno', 'customId');
  $userId_key = array_intersect($possible_userId_keys, array_keys($values));
  if (isset($userId_key) && is_array($userId_key)) {
    $userId_key = reset($userId_key);
    return str_replace("-","",$values[$userId_key]);
  }

  return null;
}

/**
 *
 * @param string $response (xml from borchk)
 */
function bibdk_favourite_parse_borchk($response) {
  $result = isset($response->Envelope->Body->borrowerCheckResponse->requestStatus->{'$'}) ? $response->Envelope->Body->borrowerCheckResponse->requestStatus->{'$'} : 'error';
  $res = array();
  $res['status'] = ($result === 'ok') ? 'ok' : 'error';
  $res['message'] = $result;
  return $res;
}
