<?php

/**
 * @file
 *
 * Receipt form . An order has been sent.
 */

/**
 * Define a receipt
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function bibdk_reservation_form_step_3($form, &$form_state) {

  $form = bibdk_reservation_form_step_4_form($form, $form_state);

  $orderpolicy = bibdk_reservation_form_step_2_do_policycheck();
  if ($orderpolicy->getOrderPossible()) {
    bibdk_reservation_form_notice_wrapper($form, $orderpolicy);
  }

  //Render user parameters
  $form['userParameters'] = array(
    '#type' => 'fieldset',
    '#title' => t('User Parameters', array(), array('context' => 'bibdk_reservation')),
  );
  $user_data_array = BibdkReservationOrderObject::GetObject()->getUserData();
  $form['userParameters']['table'] = bibdk_reservation_convert_array_to_table($user_data_array);

  //render manifestation
  $manifestation = BibdkReservationOrderObject::GetObject()->getManifestation();
  $form['manifestation'] = bibdk_reservation_render_custom_manifestation_view($manifestation);

  //render branch
  $branch = BibdkReservationOrderObject::GetObject()->getBranch();
  $form['branchdata'] = bibdk_reservation_render_custom_branch_view($branch, $form_state); //bibdk_reservation_step_2_order_branch_fields(array(), $form_state);

  // Render order parameters
  $orderParamWithLabel = array();
  $orderParameters = BibdkReservationOrderObject::GetObject()->getOrderParameters();
  if (isset($orderParameters)) {
    foreach ($orderParameters as $type => $orderParameter) {
      $orderParamWithLabel[bibdk_reservation_get_agency_fields()->getOrderLabelFromType($type)] = $orderParameter;
    }
    $form['orderParameters'] = array(
      '#type' => 'fieldset',
      '#title' => t('Order Parameters', array(), array('context' => 'bibdk_reservation')),
    );

    //Render User parameters
    $form['orderParameters']['table'] = bibdk_reservation_convert_array_to_table($orderParamWithLabel);
  }

  return $form;
}


/**
 * Validation
 * This is where we do the actual ordering. @see bibdk_reservation_form_step_4_do_order()
 *
 * Inovked when any button on step 3 is clicked. First it is checked if either
 * the breadcrumb or the 'previous' button is used. If so we return as we do
 * not want to issue an order.
 */
function bibdk_reservation_form_step_3_validate($form, &$form_state) {
  if (isset($form_state['triggering_element']['#step']) || $form_state['triggering_element']['#name'] == 'prev') {
    return;
  }

  $orderId = BibdkReservationOrderObject::GetObject()->getOrderId();
  if (!isset($orderId)) {
    $result = bibdk_reservation_form_step_4_do_order();
    if (isset($result['error'])) {
      form_set_error('form', t($result['error'], array(), array('context' => 'bibdk_reservation:error')));
    }
    else {
      $orderId = $result['orderId'];
      BibdkReservationOrderObject::GetObject()->setOrderId($orderId);
    }
  }

  // either way set sb_kopi selfpickup setting if needed
  $sb_value = BibdkReservationOrderObject::GetObject()->getArticleDirect();
  if (module_exists('bibdk_usersettings')) {
    bibdk_usersettings_user_settings_set('bibdk_actions_sb_selfpickup', $sb_value);
  }
}




function bibdk_reservation_render_custom_manifestation_view(Manifestation $manifestation, $fieldset_title = 'Manifestation') {
  $creators = $manifestation->getCreator();
  $author = '';
  if (isset($creators)) {
    foreach ($creators as $creator) {
      foreach ($creator as $key => $value) {
        $author .= ' ' . $value[0][0]['display'];
      }
    }
  }
  
  $form = array(
    '#type' => 'fieldset',
    '#title' => t($fieldset_title, array(), array('context' => 'bibdk_reservation')),
    'fortit' => array(
      '#theme' => 'bibdk_reservation_manifestation',
      '#title' => $manifestation->getTitleSpecific(),
      '#author' => $author,
      '#type' => $manifestation->getSubType(),
    ),
  );
  
  return $form;
}

function bibdk_reservation_convert_array_to_table($array) {
  foreach ($array as $key => $value) {
    $rows[]['data'] = array(
      array(
        'data' => t($key, array(), array('context' => 'bibdk_reservation')),
        'class' => array(''),
        'header' => TRUE
      ),
      array('data' => check_plain($value), 'class' => array('')),
    );
  }
  $table = array(
    '#theme' => 'table',
    '#rows' => $rows,
    '#empty' => t('No userdata', array(), array('context' => 'bibdk_reservation')),
    '#attributes' => array('class' => 'table-data'),
  );

  return $table;
}

