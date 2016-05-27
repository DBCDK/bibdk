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
      $response = bibdk_borchk_request($userId, $userPincode, $libraryCode, 'xml', 'bibliotek.dk');
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
  $dom = new DOMDocument();
  if (!@$dom->loadXML($response)) {
    $result['status'] = 'error';
    $result['message'] = t('invalid response from borchk', array(), array('context' => 'bibdk_favourite_borchk'));
    watchdog('borchk', 'invalid response from borchk %response', array('%response' => $response), WATCHDOG_ERROR);
    return $result;
  }
  $xpath = new DOMXPath($dom);
  $xpath->registerNamespace('ns', 'http://oss.dbc.dk/ns/borchk');
  $query = '//ns:requestStatus';
  $nodelist = $xpath->query($query);
  $status = $nodelist->item(0)->nodeValue;
  if ($status != 'ok') {
    $result['status'] = 'error';
    $result['message'] = t($status, array(), array('context' => 'bibdk_favourite_borchk'));
  }
  else {
    $result['status'] = 'ok';
  }
  return $result;
}