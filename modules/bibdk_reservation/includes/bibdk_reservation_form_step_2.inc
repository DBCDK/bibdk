<?php

module_load_include('php', 'vip_core', 'includes/VipCoreService');

/**
 * implements hook_form
 */
function bibdk_reservation_form_step_2($form, &$form_state) {
  global $language;

  //render branch
  $branch = BibdkReservationOrderObject::GetObject()->getBranch();
  $show_url = TRUE;
  if ($branch->getTemporarilyClosed() && $branch->getTemporarilyClosedReason($language->language) != 'ting_agency_no_temporarilyClosedReason') {
    //set closed information
    drupal_set_message($branch->getTemporarilyClosedReason($language->language), 'warning');
    $show_url = FALSE; // don't show not owned message and link to own catalog
  }

  // Render manifestation
  $manifestation = BibdkReservationOrderObject::GetObject()->getManifestation();

  $form['manifestation'] = bibdk_reservation_render_custom_manifestation_view($manifestation);

  // Add 'order any edition' checkbox
  $form['manifestation']['subtype_order_option'] = bibdk_reservation_render_subtype_order_option();

  $form['branchdata'] = bibdk_reservation_render_custom_branch_view($branch, $form_state);

  $form['branchdata']['favouriteselector'] = bibdk_reservation_favourite_selector();
  $fields = bibdk_reservation_get_agency_fields();

  $infotxt = $fields->getAcceptOrderFromUnknownUserText();

  if (empty($infotxt)) {
    $infotxt = t('accept_order_from_unknown_standard_txt', array(), array('context' => 'bibdk_reservation'));
  }

  $form['branchdata']['infotext'] = bibdk_reservation_accept_order_from_unknown($infotxt);
  $form['branchdata']['infotextlink'] = bibdk_reservation_registrationUrl($branch);
  $form['branchdata']['hidden_favourite'] = bibdk_reservation_hidden_favourite();

  $orderpolicy = bibdk_reservation_form_step_2_do_policycheck();
  bibdk_reservation_form_step_2_already_ordered(TRUE);

  if ($orderpolicy->getOrderPossible()) {
    bibdk_reservation_form_notice_wrapper($form, $orderpolicy);
    $form['userdata'] = bibdk_reservation_step_2_user_form_fields(array(), $form_state);
    if ($manifestation->getSpecifyArticleData()) {
      $form['manifestation_userdata'] = bibdk_reservation_step_2_order_form_fields(array(), $form_state);
    }
    $form['manifestation']['date'] = bibdk_reservation_step_2_permanent_fields();
  }
  else {
    $form_state['blocked'] = TRUE;
    if ($error = $orderpolicy->getCheckOrderPolicyError()) {
      form_set_error('bibdk_reservation_form_step_2', t($error, array(), array('context' => 'bibdk_reservation:error')));

      return $form;
    }

    $msgs = _bibdk_reservation_generate_policy_messages($orderpolicy, $show_url);

    if ($msgs) {
      $form['messages_wrapper'] = array(
        '#type' => 'fieldset',
      );
      $form['messages_wrapper']['messages'] = $msgs;
    }

    if ($reason = $orderpolicy->getOrderPossibleReason()) {
      if ($reason != 'not_owned_accepted_by_consortia' && $show_url == TRUE) {
        form_set_error('bibdk_reservation_form_step_2', t($reason, array(), array('context' => 'bibdk_reservation:error')));
      }
    }
  }

  // for now comment out login link - it might come in handy later
  /*if (!user_is_logged_in()) {
    _bibdk_reservation_set_login_message();
  }*/

  return $form;
}

/**
 * Helper function for bibdk_reservation_form_step_2() &
 * bibdk_reservation_form_step_3()
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
 *
 * @return array; form element
 */
function bibdk_reservation_accept_order_from_unknown($AcceptOrderFromUnknownUserText) {
  $form['infotext_wrapper'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('bibdk_reservation_infotekst_wrapper'),
    )
  );
  $form['infotext_wrapper']['info_text'] = array(
    '#markup' => $AcceptOrderFromUnknownUserText,
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
  /** @var FavouriteAgency $favourite */
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
 * If users try to order at a consordia library, a custom message on how to
 * order at an consortia library are generated
 *
 * else if there is a lookup url return link to that url
 *
 * else if there is an url to the catalog return that url
 *
 * @param $policy_response
 *
 * @return array
 */
function _bibdk_reservation_generate_policy_messages($policy_response, $show_url) {
  $msgs = array();
  if ($show_url == FALSE) {
    return $msgs;
  }
  $lookup_url = current($policy_response->getLookUpUrl());
  $agencyId = $policy_response->getAgencyId();

  if ($policy_response->getOrderPossibleReason() == 'not_owned_accepted_by_consortia' && $lookup_url) {
    $msgs = bibdk_reservation_get_consortia_message($lookup_url['url'], $lookup_url['agencyId'], $agencyId);
  }
  else {
    if ($lookup_url) {
      $query = array('url' => $lookup_url['url'], 'agency_id' => $agencyId);
      $link_text = bibdk_reservation_translate('link_to_local_library_lookup_url');
      $path = 'reservations/catalogue_url';
      $msgs = bibdk_reservation_get_lookup_url_link_element($path, $link_text, $query);
    }
    else {
      if ($catalog_url = $policy_response->getAgencyCatalogueUrl()) {
        $link_text = bibdk_reservation_translate('link_to_local_library_catalogue_url');
        $msgs = bibdk_reservation_get_lookup_url_link_element($catalog_url, $link_text);
      }
    }
  }

  return $msgs;
}

/**
 * Returns a translated message with the following format
 *
 * [Agency] does not have the material but is in a consortia with [Consortia],
 * which has the material. Therefore, you must order it at [link to consortia
 * catalog]. Use your usual card (health insurance or library card) to [Agency]
 * when you order.
 *
 * @param $url
 * @param $consortiaId
 * @param $branchId
 *
 * @return array
 */
function bibdk_reservation_get_consortia_message($url, $consortiaId, $branchId) {
  // Get names for consortia and branch
  $consortia_name = bibdk_reservation_get_branch_name_from_id($consortiaId);
  $branch_name = bibdk_reservation_get_branch_name_from_id($branchId, 'short');

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
 *
 * @param $path
 * @param $link_text
 * @param array $query
 *
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
    $fields = bibdk_favourite_user_form_fields($form, $form_state, $branch->getBranchId());
    $form['userParameters']['userfields'] = $fields;
  }
  else {
    $fields = bibdk_favourite_userdata_form($form, $form_state, $fields, NULL, $branch->getBranchId());
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
 * Get fields to shown for ALL agencies (for now only 'needBeforeDate')
 *
 * @return mixed
 */
function bibdk_reservation_step_2_permanent_fields() {
  $form = array();
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

/**
 * Do a checkOrderPolicyRequest @return BibdkOpenorderPolicyResponse
 *
 * @see bibdk_openorder::checkOrderPolicyRequest
 */
function bibdk_reservation_form_step_2_do_policycheck() {
  $pickUpAgencyId = BibdkReservationOrderObject::GetObject()->getBranchId();
  $pid = BibdkReservationOrderObject::GetObject()->getManifestationIds();

  return bibdk_openorder_do_checkOrderPolicy($pickUpAgencyId, $pid);
}

function bibdk_reservation_form_step_2_already_ordered($display_alert) {

  if (isset($_SESSION['ordered_Pids'])) {
    unset($_SESSION['ordered_Pids']);
  }

  $pid = BibdkReservationOrderObject::GetObject()->getManifestationIds();

  //Check for already ordered in this session
  if (!empty($_SESSION['orderedPids'])) {
    foreach ($pid as $Spid) {
      if (in_array($Spid, $_SESSION['orderedPids'])) {
        if ($display_alert) {
          _bibdk_reservation_set_js_settings(TRUE);
          return;
        }
      }
    }
    _bibdk_reservation_set_js_settings(FALSE);
  }
}

/*
 * Implements hook_form_validate
 * Validate user input
 */
function bibdk_reservation_form_step_2_validate(&$form, &$form_state) {
  if (!empty($form_state['values']['cpr']) && !is_numeric(str_replace("-", "", $form_state['values']['cpr']))) {
    form_set_error('cpr', t('CPR-number needs to be a valid CPR-number', array(), array('context' => 'bibdk_reservation:error')));
  }

  if (!empty($form_state['values']['userMail']) && !valid_email_address(trim($form_state['values']['userMail']))) {
    form_set_error('userEmail', t('Email needs to be a valid email', array(), array('context' => 'bibdk_reservation:error')));
  }

  if (!empty($form_state['values']['needBeforeDate'])) {
    if (!bibdk_reservation_validate_date($form_state['values']['needBeforeDate'])) {
      form_set_error('needBeforeDate', t('Date must be in the future', array(), array('context' => 'bibdk_reservation:error')));
    }


    if (!bibdk_reservation_validate_date($form_state['values']['needBeforeDate'], 7)) {
      form_set_error('needBeforeDate', t('Date must be at least 8 days from today', array(), array('context' => 'bibdk_reservation:error')));
    }
  }

  if (form_get_errors() !== FALSE) {
    bibdk_reservation_borchk_validate($form_state);
  }

  // prepare submit
  bibdk_reservation_prepare_for_order($form_state);
}

/**
 * Prepare a reservation
 *
 * @param $form_state
 */
function bibdk_reservation_prepare_for_order(&$form_state) {
  bibdk_reservation_prepare_set_user_data($form_state);
  bibdk_reservation_prepare_set_order_params($form_state);
  bibdk_reservation_prepare_set_user_order_data($form_state);
}

/**
 * Set userdata to be used for a reservation
 *
 * @param array $form_state
 *   state of submitted form
 */
function bibdk_reservation_prepare_set_user_data($form_state) {
  $userParameters = BibdkReservationOrderObject::GetObject()
    ->getFields()
    ->getUserParameters();
  // Parse userParameters
  $userData = array();
  foreach ($userParameters as $key => $userParameter) {
    $type = $userParameter['type'];
    $name = $userParameter['field_name'];
    if (isset($form_state['values'][$type])) {
      $value = (isset($userParameter['field_type']) && $userParameter['field_type'] == 'password') ?
        preg_replace("/./", "*", $form_state['values'][$type]) : $form_state['values'][$type];
    }
    if (!empty($value)) {
      $userData[$name] = $value;
    }
  }

  BibdkReservationOrderObject::GetObject()->setUserData($userData);
}

/**
 * Set parameters for a reservation. @param array $form_state
 *   state of submitted form
 *
 * @see bibdk_openorder::placeOrderRequest
 */
function bibdk_reservation_prepare_set_order_params($form_state) {
  $manifestation = BibdkReservationOrderObject::GetObject()->getManifestation();
  $fields = bibdk_reservation_get_agency_fields()->getOrderParametersForType($manifestation->getOrsOrderMaterialType());
  if ($fields) {
    foreach ($fields as $itemParameter) {
      $type = $itemParameter['type'];
      if (isset($form_state['values'][$type])) {
        $orderParameters[$type] = $form_state['values'][$type];
      }
    }
  }

  if (isset($orderParameters)) {
    BibdkReservationOrderObject::GetObject()
      ->setOrderParameters($orderParameters);
  }
}

/**
 * More parameters for a reservation. @param array $form_state
 *   state of submitted form
 *
 * @see bibdk_openorder::placeOrderRequest
 */
function bibdk_reservation_prepare_set_user_order_data(&$form_state) {
  $userOrderData = array();

  if (isset($form_state['values']['needBeforeDate'])) {
    $input_date = $form_state['values']['needBeforeDate'];
    if (is_string($input_date)) {
      $date = date("c", strtotime($input_date));
      $userData['Need before Date'] = implode('/', array_reverse(explode('-', $input_date)));
    }
  }

  if (isset($form_state['values']['subdivision'])) {
    $userOrderData['pickUpAgencySubdivision'] = $form_state['values']['subdivision'];
  }

  // bug 21614 userId was overwritten if both cpr and cardno is present.
  $branchId = BibdkReservationOrderObject::GetObject()->getBranchId();

  $response = vip_core_service($branchId, 'userOrderParameters');
  //$agency_fields = new VipCoreFields($response);
  $agency_fields = new VipCoreService($response, 'UserOrderParameters');
  $user_id = $agency_fields->getUserIdKey();

  foreach ($agency_fields->getUserParameters() as $key => $userParameter) {

    $type = $userParameter['type'];
    if ($user_id === $type) {
      if (!empty($form_state['values'][$type])) {
        $userOrderData['userId'] =
        $form_state['values'][$type] =
          str_replace("-", "", $form_state['values'][$type]);
      }
    }
    else {
      if (isset($form_state['values'][$type])) {

        //$agencyFields = new VipCoreFields(NULL);
        $agencyFields = new VipCoreService(NULL, 'UserOrderParameters');
        $agencyFields->setUserParameters($key, $userParameter);
        $fields = $agencyFields->getUserIdKey();

        if (!is_null($fields) && !isset($userOrderData['userId'])) {
          $userOrderData[$type] = $form_state['values'][$type];
        }
        else {
          if (is_null($fields)) {
            $userOrderData[$type] = $form_state['values'][$type];
          }
        }
      }
    }
  }

  BibdkReservationOrderObject::GetObject()->setUserOrderData($userOrderData);

  if ($subtype_order = isset($form_state['values']['subtype_order']) ? $form_state['values']['subtype_order'] : FALSE) {
    BibdkReservationOrderObject::GetObject()->setSubtypeOrder($subtype_order);
  }

  if (isset($date)) {
    BibdkReservationOrderObject::GetObject()->setNeedBeforeDate($date);
  }
}

/*
 * Implements hook_form_submit
 */
function bibdk_reservation_form_step_2_submit($form, &$form_state) {
  if (isset($form_state['values']['self_pickup'])) {
    BibdkReservationOrderObject::GetObject()
      ->setArticleDirect($form_state['values']['self_pickup']);
  }

  // Do not display alert box.
  bibdk_reservation_form_step_2_already_ordered(FALSE);

  // @TODO fix med - this iw WRONG
  bibdk_reservation_form_step_3_validate($form, $form_state);
}

/**
 * Validates a given date
 * Returns TRUE if validate is possible and not in the past.
 *
 * @param $date
 *
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
    if ($buffer) {
      $currentDate->add(new DateInterval('P' . (int) $buffer . 'D'));
    }
    if ($needBeforeDate > $currentDate) {
      return TRUE;
    }
  }
  return FALSE;
}

/**
 * Validate up against Borchk
 */
function bibdk_reservation_borchk_validate($form_state) {
  if ($form_state['clicked_button']['#name'] == 'next' && empty($form_state['input']['favourite_selected'])) {
    $agencySettings = BibdkReservationOrderObject::GetObject()->getFields();
    $messages = array();
    if (empty($agencySettings)) {
      watchdog('bibdk_reservation', 'no fields for agency', array(), WATCHDOG_ERROR);
      $messages = array(
        'error' => t('Service Unavailable. We can not make reservation right know', array(), array('context' => 'bibdk_reservation')),
        'status' => NULL
      );
    }

    if (empty($messages)) {
      $messages = bibdk_reservation_borchk_execute($form_state, $agencySettings);
    }
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
 *
 * @param array $form_state
 * @param VipCoreService $agencySettings
 *
 * @return array
 *   messages to display (if any)
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
    $userIdKey = BibdkReservationOrderObject::GetObject()
      ->getFields()
      ->getUserIdKey();
    $userId = isset($form_state['values'][$userIdKey]) ? $form_state['values'][$userIdKey] : NULL;
    $userPincode = isset($form_state['values']['pincode']) ? $form_state['values']['pincode'] : NULL;
    $response = bibdk_borchk_request($userId, $userPincode, $libraryCode, 'json', 'bibliotek.dk');

    $messages = bibdk_reservation_borchk_parse_response($response->borrowerCheckResponse->requestStatus->{'$'}, $acceptOrderFromUnknownUser, $acceptOrderAgencyOffline);
  }

  return $messages;
}

/**
 * Parse response from borchk and return messages
 *
 * @param string $response
 * @param string $acceptOrderFromUnknownUser
 * @param string $acceptOrderAgencyOffline
 *
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
 * @return VipCoreService
 */
function bibdk_reservation_get_agency_fields() {

  /** @var VipCoreFindLibrary $agency */
  $agency = BibdkReservationOrderObject::GetObject()->getAgency();
  if (!is_object($agency)) {
    return NULL;
  }

  $response = vip_core_service($agency->getBranchId(), 'userOrderParameters');
  $fields = new VipCoreService($response, 'userOrderParameters');
  //$fields = new VipCoreFields($response);

//  $fields = $agency->getAgencyFields();
  if (!empty($fields)) {
    BibdkReservationOrderObject::GetObject()->setFields($fields);
  }

  return $fields;
}

/**
 * Array for registrationUrl and text
 *
 * @param $branch
 *
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
  return array(
    '#type' => 'link',
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

/**
 * Setting the JavaScript object Drupal.settings.alreadyOrder for
 * bibdk_reservation.js
 */
function _bibdk_reservation_set_js_settings($ordered) {
  drupal_add_js(array(
    'alreadyOrder' => array(
      'alert_already_showed' => $ordered,
      'alert_message' => t('already_ordered', array(), array('context' => 'bibdk_reservation')),
    ),
  ), 'setting');
}

/**
 * Add checkbox for 'order any edition' option
 *
 * @return array
 */
function bibdk_reservation_render_subtype_order_option() {
  $form = array();
  $ids = BibdkReservationOrderObject::GetObject()->getManifestationIds();
  $subtype_order_ids = BibdkReservationOrderObject::GetObject()
    ->getSubtypeOrderIds();
  $isSubset = array_diff($subtype_order_ids, $ids);
  if (sizeof($isSubset) > 0) {
    $form = array(
      '#type' => 'fieldset',
      '#attributes' => array(
        'class' => array('work-reservation-option'),
      ),
      '#title' => t('header_work_reservation_option', array(), array('context' => 'bibdk_reservation')),
      'subtype_order' => array(
        '#type' => 'checkbox',
        '#title' => t('label_work_reservation_option', array(), array('context' => 'bibdk_reservation')),
      ),
      'subtype_order_ids' => array(
        '#type' => 'hidden',
        '#value' => implode(',', $subtype_order_ids),
      ),
    );
  }
  return $form;
}
