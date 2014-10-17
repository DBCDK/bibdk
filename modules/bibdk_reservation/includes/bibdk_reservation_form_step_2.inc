<?php

/**
 * implements hook_form
 */
function bibdk_reservation_form_step_2($form, &$form_state) {
  global $language;

  //render branch
  $branch = BibdkReservationOrderObject::GetObject()->getBranch();
  
  if ($branch->getTemporarilyClosedReason($language->language) != 'ting_agency_no_temporarilyClosedReason') {
    //set closed information
    drupal_set_message($branch->getTemporarilyClosedReason($language->language), 'warning');
  }

  //render manifestation
  $manifestation = BibdkReservationOrderObject::GetObject()->getManifestation();
  $form['manifestation'] = bibdk_reservation_render_custom_manifestation_view($manifestation);

  $form['branchdata'] = bibdk_reservation_render_custom_branch_view($branch, $form_state); //bibdk_reservation_step_2_order_branch_fields(array(), $form_state);

  $form['branchdata']['favouriteselector'] = bibdk_reservation_favourite_selector();
  $fields = bibdk_reservation_get_agency_fields();

  $infotxt = $fields->getAcceptOrderFromUnknownUserText($language->language);
  if (empty($infotxt)) {
    $infotxt = t('accept_order_from_unknown_standard_txt', array(), array('context' => 'bibdk_reservation'));
  }

  $form['branchdata']['infotext'] = bibdk_reservation_accept_order_from_unknown($infotxt);
  $form['branchdata']['infotextlink'] = bibdk_reservation_registrationUrl($branch);
  $form['branchdata']['hidden_favourite'] = bibdk_reservation_hidden_favourite();

  $orderpolicy = bibdk_reservation_form_step_2_do_policycheck();

  bibdk_reservation_form_step_2_already_ordered();

  if ($orderpolicy->getOrderPossible()) {
    bibdk_reservation_form_notice_wrapper($form, $orderpolicy);
    $form['userdata'] = bibdk_reservation_step_2_user_form_fields(array(), $form_state);
    if($manifestation->getSpecifyArticleData()){
      $form['manifestation_userdata'] = bibdk_reservation_step_2_order_form_fields(array(), $form_state);
    }
    $form['manifestation']['date'] = bibdk_reservation_step_2_permanent_fields(array());
  }
  else {
    $form_state['blocked'] = TRUE;
    if ($error = $orderpolicy->getCheckOrderPolicyError()) {
      form_set_error('bibdk_reservation_form_step_2', t($error, array(), array('context' => 'bibdk_reservation:error')));

      return $form;
    }
    $msgs = _bibdk_reservation_generate_policy_messages($orderpolicy);

    if ($msgs) {
      $form['messages_wrapper'] = array(
        '#type' => 'fieldset',
      );
      $form['messages_wrapper']['messages'] = $msgs;
    }

    if ($reason = $orderpolicy->getOrderPossibleReason()){
      if ($reason != 'not_owned_accepted_by_consortia')
        form_set_error('bibdk_reservation_form_step_2', t($reason, array(), array('context' => 'bibdk_reservation:error')));
    }
  }

  $sbkopi = BibdkReservationOrderObject::GetObject()->getSbKopi();

  if (!empty($sbkopi)) {
    return bibdk_reservation_sanitize_for_order_copy($form, $form_state);
  }

  if (!user_is_logged_in()) {
    _bibdk_reservation_set_login_message();
  }
  return $form;
}

/**
 * Helper function for bibdk_reservation_form_step_2() & bibdk_reservation_form_step_3()
 *
 * @return array; form
 */
function bibdk_reservation_form_notice_wrapper(&$form, $orderpolicy) {
  global $language;

  if ($orderpolicy->getOrderPossibleReason() == 'not_owned_ILL_loc') {
    if ($order_condition = $orderpolicy->getOrderCondition($language->language)) {
      $notice['notice_wrapper'] = array(
        '#type' => 'fieldset',
        '#attributes' => array(
          'class' => array(
            'order-condition',
            'message',
            'messages',
            'message--warning',
          )
        ),
        'messages' => array(
          '#markup' => $order_condition,
        ),
      );
      $form = $notice + $form;
    }
  }
}


/**
 * Hidden field to determine whether favourite has changed
 *
 * @return array; form element hidden
 */
function bibdk_reservation_hidden_favourite() {
  return array(
    '#name' => 'favourite_selected',
    '#type' => 'hidden',
    '#default_value' => 0,
    '#attributes' => array('class' => array('hidden_selector')),
  );
}

/**
 * Array for AcceptOrderFromUnknownUserText
 *
 * @param $AcceptOrderFromUnknownUserText
 * @return array; form element
 */
function bibdk_reservation_accept_order_from_unknown($AcceptOrderFromUnknownUserText) {
  $form['infotext_wrapper'] = array(
   '#type' => 'container',
   '#attributes' => array('class' => array('bibdk_reservation_infotekst_wrapper'),
   ));
 $form['infotext_wrapper']['info_text'] = array(
   '#markup' =>$AcceptOrderFromUnknownUserText,
   );
 return $form;
}

/**
 * Dropdown list to select another favourite library
 *
 * @return array; form element dropdown box
 */
function bibdk_reservation_favourite_selector() {
  $fav_options = bibdk_reservation_get_favourites_for_selector();
  // data check
  if (empty($fav_options)) {
    return;
  }

  $options[0] = t('Select another favourite library');
  $options += $fav_options;

  return array(
    '#type' => 'select',
    '#options' => $options,
    '#default_value' => 0,
    '#attributes' => array('class' => array(drupal_html_class('reservation_favourite_selector'))),
  );
}

/**
 * Get options for favourite select list
 *
 * @return array; [agencyId]=>[branchName]
 */
function bibdk_reservation_get_favourites_for_selector() {
  global $language;
  $ret = array();
  $favourites = BibdkReservationOrderObject::GetObject()->getFavourites();
  foreach ($favourites as $favourite) {
    $branch = $favourite->getBranch();
    if (is_object($branch)) {
      $ret[$favourite->getAgencyId()] = $branch->getBranchShortName($language->language);
    }
  }

  return $ret;
}

/**
 * Get policy messages
 *
 * If users try to order at a consordia library, a custom message on how to order
 * at an consortia library are generated
 *
 * else if there is a lookup url return link to that url
 *
 * else if there is an url to the catalog return that url
 *
<<<<<<< HEAD
 * @param $policy_response
=======
 * @param BibdkOpenorderPolicyResponse $policy_response
>>>>>>> feature/681_userstatus
 * @return array
 */
function _bibdk_reservation_generate_policy_messages($policy_response) {
  $msgs = array();
  $lookup_url = current($policy_response->getLookUpUrl());
  $agencyId = $policy_response->getAgencyId();

  if ($policy_response->getOrderPossibleReason() == 'not_owned_accepted_by_consortia' && $lookup_url) {
    $msgs = bibdk_reservation_get_consortia_message($lookup_url['url'], $lookup_url['agencyId'], $agencyId);
  }
  else if ($lookup_url) {
    $query = array('url' => $lookup_url['url'], 'agency_id' => $agencyId);
    $link_text = bibdk_reservation_translate('link_to_local_library_lookup_url');
    $path = 'reservations/catalogue_url';
    $msgs = bibdk_reservation_get_lookup_url_link_element($path, $link_text, $query);
  }
  else if ($catalog_url = $policy_response->getAgencyCatalogueUrl()) {
    $link_text = bibdk_reservation_translate('link_to_local_library_catalogue_url');
    $msgs = bibdk_reservation_get_lookup_url_link_element($catalog_url, $link_text);
  }

  return $msgs;
}

/**
 * Returns a translated message with the following format
 *
 * [Agency] does not have the material but is in a consortia with [Consortia],
 * which has the material. Therefore, you must order it at [link to consortia catalog].
 * Use your usual card (health insurance or library card) to [Agency] when you order.
 *
 * @param $url
 * @param $consortiaId
 * @param $branchId
 * @return array
 */
function bibdk_reservation_get_consortia_message($url, $consortiaId, $branchId) {
  // Get names for consortia and branch
  $consortia_name = bibdk_reservation_get_branch_name_from_id($consortiaId);
  $branch_name = bibdk_reservation_get_branch_name_from_id($branchId,'short');

  // Generate message for consortia catalog
  return array(
    '#theme' => 'bibdk_reservation_consortia_message',
    '#agency_name' => $branch_name,
    '#consortia_name' => $consortia_name,
    '#url' => $url,
  );
}

/**
 * Generates a lookup url link
 * @param $path
 * @param $link_text
 * @param array $query
 * @return array
 */
function bibdk_reservation_get_lookup_url_link_element($path, $link_text, $query = array()) {

  return array(
    '#theme' => 'link',
    '#text' => $link_text,
    '#path' => $path,
    '#options' => array(
      'query' => $query,
      'attributes' => array(
        'target' => '_blank',
      ),
      'html' => FALSE,
    ),
  );
}


function bibdk_reservation_manifestation_form_fields($form, &$form_state) {
  $form = array(
    '#type' => 'fieldset',
    '#title' => t('Selected Work', array(), array('context' => 'bibdk_reservation')),
  );
  $form['description'] = array(
    '#markup' => t('description_for_selected_work', array(), array('context' => 'bibdk_reservation')),
  );
  $manifestation = BibdkReservationOrderObject::GetObject()->getManifestation();
  $form['view_wrapper'] = array(
    '#type' => 'container',
  );
  $form['view_wrapper']['view'] = array(
    '#markup' => bibdk_reservation_manifestation_view($manifestation),
  );

  return $form;
}

/**
 * Render user fields;
 */
function bibdk_reservation_step_2_user_form_fields($form, $form_state) {
  $userData = NULL;
  $branch = BibdkReservationOrderObject::GetObject()->getBranch();
  $fields = bibdk_reservation_get_agency_fields();

  global $user;
  if (ding_user_is_provider_user($user)) {
    $fields = bibdk_favourite_user_form_fields($form, $form_state, $branch->branchId);
    $form['userParameters']['userfields'] = $fields;
  }
  else {
    $fields = ting_agency_userdata_form($form, $form_state, $fields, NULL, $branch->branchId);
    $form['userParameters']['userfields'] = $fields;
  }

  return $form;
}

/**
 * Render order fields;
 */
function bibdk_reservation_step_2_order_form_fields($form, $form_state) {
  $manifestation = BibdkReservationOrderObject::GetObject()->getManifestation();

  $valid_fields = bibdk_reservation_get_agency_fields();
  if (empty($valid_fields)) {
    return $form;
  }

  $fields = $valid_fields->getOrderParametersForType($manifestation->getOrsOrderMaterialType());
  if (!isset($fields)) {
    return $form;
  }

  $form['orderParameters'] = array(
    '#type' => 'fieldset',
    '#title' => t('Order Parameters', array(), array('context' => 'bibdk_reservation')),
  );
  $form['orderParameters']['description'] = array(
    '#type' => 'markup',
    '#markup' => t('Description for Order Parameters', array(), array('context' => 'bibdk_reservation')),
  );

  foreach ($fields as $itemParameter) {
    $type = $itemParameter['type'];
    $form['orderParameters'][$type] = array(
      '#type' => isset($itemParameter['field_type']) ? $itemParameter['field_type'] : 'textfield',
      '#title' => bibdk_reservation_get_agency_fields()->getOrderLabelFromType($type),
      '#required' => $itemParameter['required'],
      '#default_value' => (isset($form_state['values'][$type])) ? $form_state['values'][$type] : "",
    );
  }

  return $form;
}

/**
 * Render branch fields;
 * 
 */

/*
 * @TODO delete this if not used...
 */
function bibdk_reservation_step_2_order_branch_fields($form, $form_state) {
    
  $branch = BibdkReservationOrderObject::GetObject()->getBranch();

  $form['branchParameters'] = array(
    '#type' => 'fieldset',
    '#title' => t('Selected Branch', array(), array('context' => 'bibdk_reservation')),
  );

  $form['branchParameters']['description'] = array(
    '#type' => 'markup',
    '#attributes' => array('class' => array('form-wrapper', 'form-item')),
    '#markup' => t('Description for selected branch', array(), array('context' => 'bibdk_reservation')),
  );

  $moreinfo = theme('ting_agency_more_info', array(
    'branch' => $branch,
    'openingHours' => theme('ting_agency_opening_hours', array('branch' => $branch,)),
    'address' => theme('ting_agency_address', array('branch' => $branch)),
    'contact' => theme('ting_agency_contact', array('branch' => $branch)),
  ));

  //$classes[] = 'selected_branch';
  $classes = array();
  $classes[] = 'element-wrapper';
  $classes[] = 'favourite_' . $branch->branchId;
  $classes[] = (isset($branch->orderLibrary) && $branch->orderLibrary == 'TRUE') ? 'order-agency' : NULL;

  global $language;
  $form['branchParameters']['selectedBranch']['#markup'] = theme('ting_agency_library', array(
    'branchName' => $branch->getBranchName($language->language),
    'actions' => NULL,
    'add_classes' => $classes,
    'moreinfo' => $moreinfo,
    'branchid' => $branch->branchId
  ));

  return $form;
}

function bibdk_reservation_step_2_permanent_fields($form) {
  $timestamp = strtotime(date('Y-m-d') . '+ 3 month');
  $date = date('Y-m-d', $timestamp);
  $form['needBeforeDate'] = array(
    '#type' => 'date_select',
    '#title' => t('Is of no interest after', array(), array('context' => 'bibdk_reservation')),
    '#required' => TRUE,
    '#date_label_position' => 'within',
    '#date_format' => 'd-m-Y',
    '#default_value' => $date,
    '#date_year_range' => '0:+3',
  );

  return $form;
}

function bibdk_reservation_form_step_2_do_policycheck() {

  $pickUpAgencyId = BibdkReservationOrderObject::GetObject()->getBranchId();
  $pid = BibdkReservationOrderObject::GetObject()->getManifestationIds();

  return bibdk_openorder_do_checkOrderPolicy($pickUpAgencyId, $pid);
}

function bibdk_reservation_form_step_2_already_ordered() {

  $pid = BibdkReservationOrderObject::GetObject()->getManifestationIds();

  //Check for already ordered in this session
  if (!empty($_SESSION['orderedPids'])) {
    foreach ($pid as $Spid) {
      if (in_array($Spid, $_SESSION['orderedPids'])) {
        drupal_set_message(t('already_ordered', array(), array('context' => 'bibdk_reservation')), $type = 'warning', $repeat = FALSE);
        break;
      }
    }
  }

}

/*
 * Implements hook_form_validate
 * Validate user input
 */
function bibdk_reservation_form_step_2_validate(&$form, &$form_state) {
  //TODO: move to ting_agency

  if (!empty($form_state['values']['cpr']) && !is_numeric($form_state['values']['cpr'])) {
    form_set_error('cpr', t('CPR-number needs to be a valid CPR-number', array(), array('context' => 'bibdk_reservation:error')));
  }

  if (!empty($form_state['values']['userMail']) && !valid_email_address($form_state['values']['userMail'])) {
    form_set_error('userEmail', t('Email needs to be a valid email', array(), array('context' => 'bibdk_reservation:error')));
  }

  if ( !bibdk_reservation_validate_date($form_state['values']['needBeforeDate']) ) {
    form_set_error('needBeforeDate', t('Date must be in the future', array(), array('context' => 'bibdk_reservation:error')));
  }

  if ( !bibdk_reservation_validate_date($form_state['values']['needBeforeDate'], 7) ) {
    form_set_error('needBeforeDate', t('Date must be at least 8 days from today', array(), array('context' => 'bibdk_reservation:error')));
  }

  if (!form_get_errors()) {
    $sb_user = BibdkReservationOrderObject::GetObject()->getSbKopiUser();
    // do not borchk validate if copy service user is new
    if (!isset($sb_user) || $sb_user == 'OLD') {
      bibdk_reservation_borchk_validate($form_state);
    }
    // this is a user that registers via bibliotek.dk
    elseif (isset($sb_user) && $sb_user == 'NEW') {
      // @TODO create the user here, and validate that all went well
      $reply = bibdk_reservation_form_step_2_create_sbuser($form, $form_state);

      if ($reply['status'] == 'error') {
        form_set_error($reply['field'], t($reply['message'], array(), array('context' => 'bibdk_reservation:error')));
      }
      else {
        // user was created successfully
        drupal_set_message(t('SB_USER_CREATED', array(), array('context' => 'bibdk_reservation')));
      }
    }
  }
}

/**
 * Validates a given date
 * Returns TRUE if validate is possible and not in the past.
 *
 * @param $date
 * @return bool
 */
function bibdk_reservation_validate_date($date, $buffer = 0) {
  if (!is_string($date)) {
    return FALSE;
  }
  $dateArr = explode('-', $date);
  if (checkdate($dateArr[1], $dateArr[2], $dateArr[0])) {
    $needBeforeDate = new DateTime($date);
    $currentDate = new DateTime();
    if ( $buffer ) {
      $currentDate->add(new DateInterval('P' . (int)$buffer . 'D'));
    }
    if ($needBeforeDate > $currentDate) {
      return TRUE;
    }
  }

  return FALSE;
}

// this is a hacked solution for making a request to statsbiblioteket's
// create user service
// FAKE a request
// @TODO implement this in a better way
function bibdk_reservation_form_step_2_create_sbuser($form, $form_state) {
  $cpr = $form_state['values']['bestil_kopi_cpr_number'];
  $firstname = $form_state['values']['bestil_kopi_firstname'];
  $surname = $form_state['values']['bestil_kopi_lastname'];
  $mail = $form_state['values']['bestil_kopi_e_mail'];

  if (!($cpr && $firstname && $surname && $mail)) {
    return array(
      'status' => 'error',
      'field' => 'form',
      'message' => 'sb_kopi_fill_out_the_form'
    );
  }

  $ch = curl_init('https://webservice.statsbiblioteket.dk/ws-create-user1/CreateUser');

  $body = '<SOAP:Envelope xmlns:SOAP="http://schemas.xmlsoap.org/soap/envelope/"
    SOAP:encodingStyle="http://schemas.xmlsoap.org/soap/encoding/"
    xmlns:CU="http://statsbiblioteket.dk/xws/createuser_v1"
    xmlns:CPR="http://rep.oio.dk/cpr.dk/xml/schemas/core/2005/03/18/"
    xmlns:DKCC="http://rep.oio.dk/ebxml/xml/schemas/dkcc/2003/02/13/">
  <SOAP:Body>
  <CU:CreateUserRequest>
      <CPR:PersonCivilRegistrationIdentifier>' . $cpr . '</CPR:PersonCivilRegistrationIdentifier>
      <DKCC:PersonGivenName>' . $firstname . '</DKCC:PersonGivenName>
      <DKCC:PersonSurnameName>' . $surname . '</DKCC:PersonSurnameName>
      <CU:EmailAddress>' . $mail . '</CU:EmailAddress>
    </CU:CreateUserRequest>
   </SOAP:Body>
</SOAP:Envelope> ';

  $headers = array(
    'Content-Type: text/xml',
    'SOAPAction:CreateUserRequest',
  );

  curl_setopt_array($ch, array(
    CURLOPT_POST => TRUE,
    CURLOPT_POSTFIELDS => $body,
    CURLOPT_HTTPHEADER => $headers,
    CURLOPT_RETURNTRANSFER => TRUE
  ));
  $response = curl_exec($ch);

  if ($response === FALSE) {
    // request FAILED
    $reply = array();
    $reply['status'] = 'error';
    $reply['message'] = t('Internal error please contact site administrator if problem persists', array(), array('context' => 'bibdk_sbkopi'));
    watchdog('curl_error', 'curl_exec returned FALSE for %post', array('%post' => $body));

    return $reply;
  }

  return bibdk_reservation_sbkopi_parse_response($response);
}

/*
 * Implements hook_form_submit
 */

function bibdk_reservation_form_step_2_submit($form, &$form_state) {
  if (isset($form_state['values']['self_pickup'])) {
    BibdkReservationOrderObject::GetObject()->setArticleDirect($form_state['values']['self_pickup']);
  }

  $userParameters = BibdkReservationOrderObject::GetObject()->getFields()->getUserParameters();

  // Parse userParameters
  foreach ($userParameters as $key => $userParameter) {
    $type = $userParameter['type'];
    $name = $userParameter['field_name'];
    $value = (isset($userParameter['field_type']) && $userParameter['field_type'] == 'password') ? preg_replace("/./", "*", $form_state['values'][$type]) : $form_state['values'][$type];
    if (!empty($value)) {
      $userData[$name] = $value;
      if (in_array($type, array('cpr', 'userId', 'cardno', 'customId'))) {
        $userOrderData['userId'] = isset($userOrderData['userId']) ? $userOrderData['userId'] : $form_state['values'][$type];
      }
      else {
        $userOrderData[$type] = $form_state['values'][$type];
      }
    }
  }

  $manifestation = BibdkReservationOrderObject::GetObject()->getManifestation();

  // Parse itemParameters
  $fields = bibdk_reservation_get_agency_fields()->getOrderParametersForType($manifestation->getOrsOrderMaterialType());
  if ($fields) {
    foreach ($fields as $itemParameter) {
      $type = $itemParameter['type'];
      if (isset($form_state['values'][$type])) {
        $orderParameters[$type] = $form_state['values'][$type];
      }
    }
  }
  if (isset($userOrderData['pincode'])) {
    unset($userOrderData['pincode']);
  }

  $input_date = $form_state['values']['needBeforeDate'];
  $date = date("Y-m-d\TH:i:s", strtotime($input_date));
  $userData['Need before Date'] = implode('/', array_reverse(explode('-', $input_date)));

  if (isset($form_state['values']['subdivision'])) {
    $userOrderData['pickUpAgencySubdivision'] = $form_state['values']['subdivision'];
  }

  // Save all user input
  BibdkReservationOrderObject::GetObject()->setUserData($userData);
  BibdkReservationOrderObject::GetObject()->setUserOrderData($userOrderData);

  if (isset($date)) {
    BibdkReservationOrderObject::GetObject()->setNeedBeforeDate($date);
  }

  if (isset($orderParameters)) {
    BibdkReservationOrderObject::GetObject()->setOrderParameters($orderParameters);
  }

}

/**
 * Validate up against Borchk
 */
function bibdk_reservation_borchk_validate($form_state) {

  if ($form_state['clicked_button']['#name'] == 'next' &&  empty($form_state['input']['favourite_selected']) ) {
    // @TODO check that object is set
    $agencySettings = BibdkReservationOrderObject::GetObject()->getFields();

    $messages = bibdk_reservation_borchk_execute($form_state, $agencySettings);
    if (!isset($messages)) {
      return;
    }
    if (isset($messages['status'])) {
      drupal_set_message(t($messages['status'], array(), array('context' => 'bibdk_reservation:error')), 'warning');
    }
    if (isset($messages['error'])) {
      form_set_error('borchk', t($messages['error'], array(), array('context' => 'bibdk_reservation:error')));
    }
  }
}

/**
 * Execute service request to borchk
 */
function bibdk_reservation_borchk_execute($form_state, $agencySettings) {
  $acceptOrderFromUnknownUser = $agencySettings->acceptOrderFromUnknownUser();
  $acceptOrderAgencyOffline = $agencySettings->acceptOrderAgencyOffline();
  $isBorrowerCheckRequired = $agencySettings->isBorrowerCheckRequired();
  $messages = array(
    'error' => NULL,
    'status' => NULL
  );
  if (!$isBorrowerCheckRequired) {
    if (!$acceptOrderFromUnknownUser) {
      // just a notice - it just mean that the library reserves the right to trash the reservation.
      // US1243 - no unknown user warning
      // $messages['status'] = t('Library does not accept reservations form unknown users', array(), array('context' => 'bibdk_reservation:error'));
    }
  }
  else {
    $libraryCode = BibdkReservationOrderObject::GetObject()->getBranchId();
    $userIdKey = BibdkReservationOrderObject::GetObject()->getFields()->getUserIdKey();
    $userId = isset($form_state['values'][$userIdKey]) ? $form_state['values'][$userIdKey] : NULL;
    $userPincode = isset($form_state['values']['pincode']) ? $form_state['values']['pincode'] : NULL;
    $response = bibdk_borchk_request($userId, $userPincode, $libraryCode, 'json', 'bibliotek.dk');

    $messages = bibdk_reservation_borchk_parse_response($response->borrowerCheckResponse->requestStatus->{'$'}, $acceptOrderFromUnknownUser, $acceptOrderAgencyOffline);
    //  $messages = bibdk_reservation_borchk_parse_response($response->borrowerCheckResponse->requestStatus, $acceptOrderFromUnknownUser, $acceptOrderAgencyOffline);
  }

  return $messages;
}

/**
 * Parse response from borchk and return messages
 *
 * @param string $response
 * @param string $acceptOrderFromUnknownUser
 * @param string $acceptOrderAgencyOffline
 * @return array
 */
function bibdk_reservation_borchk_parse_response($response, $acceptOrderFromUnknownUser, $acceptOrderAgencyOffline) {
  $message = array(
    'error' => NULL,
    'status' => NULL
  );
  switch ($response) {
    case 'ok' :
      return;
      break;
    case 'borrower_not_found' :
      if ($acceptOrderFromUnknownUser) {
        $message['status'] = t('Borrower not found, but Library accepts reservations from unknown users', array(), array('context' => 'bibdk_reservation'));
      }
      else {
        $message['error'] = t('User not found', array(), array('context' => 'bibdk_reservation'));
      }
      break;
    case 'error_in_request' :
    case 'service unavailable' :
    case 'borrowercheck_not_allowed' :
    default :
      if ($acceptOrderAgencyOffline) {
        $message['status'] = t('We could not check your status', array(), array('context' => 'bibdk_reservation'));
      }
      else {
        $message['error'] = t('Service Unavailable. We can not make reservation right know', array(), array('context' => 'bibdk_reservation'));
      }
      break;
  }

  return $message;
}

/**
 * Get fields required by Agency
 *
 * @return AgencyFields
 */
function bibdk_reservation_get_agency_fields() {

  $agency = BibdkReservationOrderObject::GetObject()->getAgency();
  if (!is_object($agency)) {
    return NULL;
  }
  $fields = $agency->getAgencyFields();
  if (!empty($fields)) {
    BibdkReservationOrderObject::GetObject()->setFields($fields);
  }

  return $fields;
}

/**
 * Array for registrationUrl and text
 *
 * @param $branch
 * @return array; link element
 */
function bibdk_reservation_registrationUrl($branch) {

  // url
  $linkUrl = $branch->getRegistrationFormUrl();
  if (empty($linkUrl)) {
    return;
  }
  
  //url text
  $linkUrlText = $branch->getRegistrationFormUrlText();
  if (empty($linkUrlText)) {
    // set default text
    $linkUrlText = t('registration_form_url_text', array(), array('context' => 'bibdk_reservation'));
  }

  //create link array
  return array( '#type' => 'link',
                '#title' => $linkUrlText,
                '#href' => $branch->getRegistrationFormUrl(),
                '#options' => array(
                'html' => TRUE
                 ),
                  '#attributes' => array(
                     'class' => array(
                     'clearfix',
                   ),
                    'target' => '_blank',
                 ), 
              );
 }