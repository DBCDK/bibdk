<?php

/**
 * @file
 * THIS IS NOT A FORM
 *
 * loose functions to support bibdk_reservation_form_step_3
 */

/**
 * Make a base form for bibdk_reservation_form_step_3. If orderid is set it means
 * an order has been completed. If not something went wront
 * @param $form
 * @param $form_state
 * @return mixed
 */
function bibdk_reservation_form_step_4_form($form, &$form_state) {
  $orderId = BibdkReservationOrderObject::GetObject()->getOrderId();
  if ( $orderId ) {
    // render OrderID
    $form['orderId'] = array(
      '#type' => 'fieldset',
      '#title' => t('Your order is complete', array(), array('context' => 'bibdk_reservation')),
      '#attributes' => array('class' => array('bottom-space')),
    );
    $form['orderId']['container']['markup'] = bibdk_reservation_convert_array_to_table(array(
      t('Your order ID', array(), array('context' => 'bibdk_reservation')) => $orderId,
    ));

  }
  else {
    // openOrder error message
    $form['orderId'] = array(
      '#type' => 'fieldset',
      '#title' => t('empty_orderid_error_message', array(), array('context' => 'bibdk_reservation:error')),
      '#attributes' => array('class' => array('bottom-space')),
    );
  }

  return $form;
}

function bibdk_reservation_form_step_4_do_order() {
  $params = array();
  $pids = BibdkReservationOrderObject::GetObject()->getManifestationIds();
  $userdata = BibdkReservationOrderObject::GetObject()->getUserOrderData();
  // do NOT send pincode
  if(isset($userdata['pincode'])){
    unset($userdata['pincode']);
  }

  $orderdata = BibdkReservationOrderObject::GetObject()->getOrderParameters();

  $articleDirect = BibdkReservationOrderObject::GetObject()->getArticleDirect();
  if ( !empty($articleDirect) ) {
    $params += array('articleDirect' => 'pickup');
  } else {
    $articleType = BibdkReservationOrderObject::GetObject()->getSbKopi();
    if ( $articleType == 'FREE' ) {
      $params += array('articleDirect' => 'electronic');
    }
    if ( $articleType == 'PAY' ) {
      $params += array('articleDirect' => 'postal');
    }
  }

  if (count(BibdkReservationOrderObject::GetObject()->getManifestationIds()) > 1) {
    $exactEdition = 'false';
  }
  else {
    $exactEdition = 'true';
  }

  // 'order any edition' option on manifestation.
  if (BibdkReservationOrderObject::GetObject()->getSubtypeOrder()) {
    $pids = BibdkReservationOrderObject::GetObject()->getSubtypeOrderIds();
    $exactEdition = 'false';
  }

  $params += array('requesterNote' => BibdkReservationOrderObject::GetObject()->getRequesterNote());

  $params += array('exactEdition' => $exactEdition);

  $params += (isset($userdata)) ? $userdata : array();
  $params += (isset($orderdata)) ? $orderdata : array();
  $params += array(
    'pid' => $pids,
    'pickUpAgencyId' => BibdkReservationOrderObject::GetObject()->getBranchId(),
    'needBeforeDate' => BibdkReservationOrderObject::GetObject()->getNeedBeforDate(),
  );

  $response = bibdk_borchk_request($params['userId'], (isset($params['userPincode'])) ? $params['userPincode'] : NULL, $params['pickUpAgencyId'], 'bibliotek.dk');
  $params['userIdAuthenticated'] = ( $response->Envelope->Body->borrowerCheckResponse->requestStatus->{'$'} == 'ok' ) ? 'true' : 'false';

  bibdk_reservation_form_step_4_register_pid();
  $response = bibdk_openorder_do_placeOrder($params);

  // orderId may be NULL in case of a timeout or a 404
  $orderId = NULL;
  if ( isset($response->placeOrderResponse->orderPlaced) ) {
    $orderId = $response->placeOrderResponse->orderPlaced->orderId->{'$'};
  }

  if ( isset($response->placeOrderResponse->orderNotPlaced) || empty($orderId) ) {
    $error = ( isset($response->placeOrderResponse->orderNotPlaced->placeOrderError->{'$'}) )
      ? $response->placeOrderResponse->orderNotPlaced->placeOrderError->{'$'}
      : t('empty_orderid_error_message', array(), array('context' => 'bibdk_reservation:error'));
    $pickUpAgencyId = BibdkReservationOrderObject::GetObject()->getBranchId();
    watchdog('bibdk_reservation_form_step_4', 'openOrder responded with an error: ' . $error . '. pid: #pid agencyId: #agency', array(
      '#pid' => $pids[0],
      '#agency' => $pickUpAgencyId
    ), WATCHDOG_ERROR);
    $result = array('error' => t('An error happened and the order could not be completed.', array(), array('context' => 'bibdk_reservation')));
  }
  else {
    // do not set confirm message for sb_copy service
    $sb_copy = BibdkReservationOrderObject::GetObject()->getSbKopi();
    if(empty($sb_copy)){
      bibdk_reservation_set_confirm_message();
    }

    $result = bibdk_reservation_form_step_4_handle_response($response);
    // We need the following to ifs for bibdk_audit_trail.
    if (!user_is_logged_in()) {
      if (isset($params['userId']) && !empty($params['userId']) && $params['userIdAuthenticated'] === "true") {
        $result['userId'] = $params['userId'];
        $result['userName'] = $params['userName'] ?? '';
        $result['userMail'] = $params['userMail'] ?? '';
      }
    }
    module_invoke_all('bibdk_reservation_complete', $pids, $result);
    unset($result['userId'], $result['userName'], $result['userMail']);
  }

  return $result;
}

function bibdk_reservation_set_confirm_message(){
  global $language;
  $IllOrderReceiptText = check_plain(BibdkReservationOrderObject::GetObject()->getBranch()->getIllOrderReceiptText($language->language));

  $msg = '';
  if($IllOrderReceiptText != 'ting_agency_no_order_receipt_text'){
    $msg = $IllOrderReceiptText;
  }

  $pickUpAgency = BibdkReservationOrderObject::GetObject()->getBranch();
  $link = _bibdk_reservation_get_userstatus_link($pickUpAgency);

  if(!empty($msg) && !empty($link)){
    $msg .= '<br />';
  }

  $msg .= $link;

  if (!empty($msg)) {
    drupal_set_message($msg, 'status');
  }
}

/**
 * Generates a message based on the the current users loginstatus and the
 * pickUpAgency's userstatuspolicy
 *
 * @param VipCoreFindLibrary $pickUpAgency
 * @return null|string
 */
function _bibdk_reservation_get_userstatus_link($pickUpAgency) {
  $ncipLookUpUser = $pickUpAgency->getNcipLookUpUser();
  $msg = '';
  $attributes = array(
    'attributes' => array(
      'class' => array(
        'redirect-parent',
      ),
      'target' => array(
        '_parent',
      ),
    ),
  );

  if (empty($ncipLookUpUser)) {
    $userStatusUrl = $pickUpAgency->getUserStatusUrl();
    if (!empty($userStatusUrl)) {
      $url = $userStatusUrl;
      $attributes['attributes']['target'][0] = '_blank';
    } else {
      return $msg;
    }
  } else if (bibdk_reservation_user_is_logged_in()) {
    global $user;
    $url = (module_exists('me')) ? 'user/me/bibdk_openuserstatus' : 'user/' . $user->uid . '/bibdk_openuserstatus';
  } else {
    return $msg;
  }

  $link = bibdk_reservation_get_link(bibdk_reservation_translate('link_to_userstatus'), $url, $attributes);
  $msg = bibdk_reservation_translate('you_can_watch_order_status_here: !link', array('!link' => $link));
  return $msg;
}

/**
 * @param $response
 * @return array
 */
function bibdk_reservation_form_step_4_handle_response($response) {
  $result = array();
  if (isset($response->placeOrderResponse->orderPlaced)) {
    $orderId = $response->placeOrderResponse->orderPlaced->orderId->{'$'};
    $result = array('orderId' => $orderId);
    $type = BibdkReservationOrderObject::GetObject()->getManifestation()->getSubType();
    if (strtolower($type) != 'avis' && strtolower($type) != 'tidsskrift') {
      bibdk_reservation_form_step_4_register_pid();
    }
  }

  return $result;
}

function bibdk_reservation_form_step_4_register_pid() {
  $pids = BibdkReservationOrderObject::GetObject()->getManifestationIds();

  // 'order any edition' option on manifestation.
  if (BibdkReservationOrderObject::GetObject()->getSubtypeOrder()) {
    $pids = BibdkReservationOrderObject::GetObject()->getSubtypeOrderIds();
  }

  if (array_key_exists('orderedPids', $_SESSION)) {
    $_SESSION['orderedPids'] = array_merge($_SESSION['orderedPids'], $pids);
  }
  else {
    $_SESSION['orderedPids'] = $pids;
  }
}
