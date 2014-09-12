<?php

/**
 * Menu callback
 */
function bibdk_openuserstatus_new_pickuplibrary_selected() {
  if (!isset($_POST) && empty($_POST) || !bibdk_openuserstatus_check_post_values($_POST)) {
    $msg = t('insufficient_data_provided', array(), array('context' => 'bibdk_openuserstatus:error'));
    bibdk_openuserstatus_output_error($msg);
  }

  $post = $_POST;

  $orderId = $post['oid'];
  $agencyId = $post['aid'];
  $currentAgencyId = $post['caid'];
  $subdivision = NULL;

  if(strlen($agencyId) > 6){
    $split = explode('-', $agencyId);
    $agencyId = $split[0];
    $subdivision = $split[1];
  }

  if (!bibdk_openuserstatus_validate_selection($orderId, $currentAgencyId)) {
    $msg = t('Could not validate the data received from client', array(), array('context' => 'bibdk_openuserstatus:error'));
    bibdk_openuserstatus_output_error($msg);
  }

  $order = array();
  $order[0]['orderId'] = $orderId;
  $order[0]['pickUpAgency'] = $agencyId;
  $order[0]['agencyId'] = $currentAgencyId;
  if(isset($subdivision)){
    $order[0]['pickUpAgencySubdivision'] = $subdivision;
  }

  $favourites = bibdk_favourite_get_favourites();
  if (isset($favourites[$currentAgencyId])) {
    $favourite = $favourites[$currentAgencyId];
  }
  else {
    $msg['error'] = t('Could not validate the data received from client', array(), array('context' => 'bibdk_openuserstatus:error'));
    ajax_deliver(drupal_json_encode($msg));
  }

  $result = $favourite->updateOrder($order);
  if(isset($result['response']->updateOrderResponse->updateOrderStatus[0]->updateOrderError)){
    $msg = t('An error occured and your request could not be completed.', array(), array('context' => 'bibdk_openuserstatus:error'));
    $reason = $result['response']->updateOrderResponse->updateOrderStatus[0]->updateOrderError->{'$'};
    watchdog('bibdk_openuserstaus', t('OpenUserstatus, %method could not be completed. Parameters: %parameters. Result: %result', array('%result' => var_export($result, TRUE), '%parameters' => var_export($order, TRUE), '%method' => 'updateOrder')), array(), WATCHDOG_ERROR);
    bibdk_openuserstatus_output_error($msg, $reason);
  }

  drupal_json_output('success');
  drupal_exit();
}

/**
 * Validates that the request information is present in the curren userstatus
 * and ensures that the user haven't faked the input
 *
 * @param $orderId
 * @param $currentAgencyId
 * @return bool
 */
function bibdk_openuserstatus_validate_selection($orderId, $currentAgencyId) {
  $userstatus = bibdk_openuserstatus_request();
  $reservations = bibdk_openuserstatus_get_reservations($userstatus);
  foreach ($reservations as $reservation) {
    if ($reservation['orderId'] == $orderId) {
      if ($reservation['agencyId'] == $currentAgencyId) {
        return TRUE;
      }
    }
  }
  return FALSE;
}

/**
 * Checks for expected values in $_POST array. Returns false if a value is
 * missing otherwise TRUE is returned
 *
 * @param array $post
 * @return bool
 */
function bibdk_openuserstatus_check_post_values($post) {
  $keys = array('aid', 'oid', 'caid');
  foreach ($keys as $key) {
    if (!isset($post[$key]) && empty($post[$key])) {
      return FALSE;
    }
  }
  return TRUE;
}

/**
 * Outputs the error message received as json and exits the program with code 0
 *
 * @param $msg
 */
function bibdk_openuserstatus_output_error($msg, $reason = '') {
  $data['error']['msg'] = $msg;
  $data['error']['reason'] = $reason;
  drupal_json_output($data);
  drupal_exit();
}

function bibdk_openuserstatus_get_user_status() {
  $result = bibdk_openuserstatus_request();

  $data = array();
  $loans = 0;
  $orders = 0;
  $debt = 0;

  if (is_array($result)) {
    foreach ($result as $agencyId => $response_obj) {
      $response = $response_obj->getResponse();

      if (!empty($response['error'])) {
        continue;
      }
      $loans  += ( isset($response['loanedItems']['loansCount']) )    ? (int)$response['loanedItems']['loansCount'] : 0;
      $orders += ( isset($response['orderedItems']['ordersCount']) )  ? (int) $response['orderedItems']['ordersCount'] : 0;
      $debt   += ( isset($response['fiscalAccount']['totalAmount']) ) ? (float) $response['fiscalAccount']['totalAmount'] : 0;
    }
    $data['loans'] = $loans;
    $data['orders'] = $orders;
    $data['debt'] = $debt;
  }

  $data['html'] = bibdk_openuserstatus_set_rows_html($data);

  drupal_json_output($data);
  drupal_exit();

}

function bibdk_openuserstatus_set_rows_html($data){
 $html = '';
 if (!empty($data)) {
  $html .= '<div class="bibdk-mypage-row clearfix"> ';
  $html .= '<p class="label-row">'.t('my_loans_count', array(), array('context'=>'bibdk_openuserstatus')).'</p>';
  $html .= '<p class="value-row">'. $data['loans'].'</p>';
  $html .= '</div>';

  $html .= '<div class="bibdk-mypage-row clearfix"> ';
  $html .= '<p class="label-row">'.t('my_orders_count', array(), array('context'=>'bibdk_openuserstatus')).'</p>';
  $html .= '<p class="value-row">'. $data['orders'].'</p>';
  $html .= '</div>';

  $html .= '<div class="bibdk-mypage-row clearfix"> ';
  $html .= '<p class="label-row">'.t('my_debts', array(), array('context'=>'bibdk_openuserstatus')).'</p>';
  $html .= '<p class="value-row">'. $data['debt'].'</p>';
  $html .= '</div>';
 }
 return $html;
}
