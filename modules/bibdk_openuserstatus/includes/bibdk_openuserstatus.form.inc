<?php

/**
 * Returns render form array containing tables representing the userstatus
 *
 * @param $form
 * @return array
 */
function bibdk_openuserstatus_by_ajax() {

  $output =  drupal_get_form('bibdk_openuserstatus_form');
  $js_array = array (
    'markup' => drupal_render($output),
  );

  return drupal_json_output($js_array);

}

/**
 * Returns renderable form array containing tables representing the userstatus
 *
 * @param $form
 * @return array
 */
function bibdk_openuserstatus_form($form) {
  $response = bibdk_openuserstatus_request();

  $form = bibdk_openuserstatus_get_tables($form, $response);
  $favourites = bibdk_favourite_get_favourites();
  $do_print_status = FALSE;

  // check if user has one library with userdata added
  foreach ($favourites as $favourite) {
    $res = $favourite->getUserId();
    if (!empty($res)) {
      $do_print_status = TRUE;
    }
  }

  if (!$do_print_status) {
    $text = t('label_userstatus_no_favourite', array(), array('context' => 'bibdk_openuserstatus'));
    $type = 'warning';
    drupal_set_message($text, $type);
  }

  return $form;
}

/**
 * Collects tables for each area of the userstatus page and delivers it as one
 * single form
 *
 * @param array $response
 * @param array $form
 * @return array
 */
function bibdk_openuserstatus_get_tables($form, $response) {
  $form['basics'] = array(
    '#theme' => 'bibdk_openuserstatus',
  );
  $loans = bibdk_openuserstatus_get_loans($response);
  $reservations = bibdk_openuserstatus_get_reservations($response);
  $fiscals = bibdk_openuserstatus_get_fiscals($response);
  $loan_agencies = bibdk_openuserstatus_get_pickup_agencies_from_material_list($loans);
  $reservation_agencies = bibdk_openuserstatus_get_pickup_agencies_from_material_list($reservations);
  $agencies = array_unique(array_merge($loan_agencies, $reservation_agencies));
  $named_agencies = bibdk_openuserstatus_agency_names($agencies);

  $form = bibdk_openuserstatus_get_loans_table($form, $loans, $named_agencies);
  $form = bibdk_openuserstatus_get_reservations_readyforpickup_table($form, $reservations, $named_agencies);
  $form = bibdk_openuserstatus_get_reservations_inprocess_table($form, $reservations, $named_agencies);
  $form = bibdk_openuserstatus_get_fiscal_account_table($form, $fiscals,bibdk_openuserstatus_get_fiscals_total($response));

  $form['#attributes'] = array('class' => array('openuserstatus'));
  $form['#attached']['js'] = array(
    drupal_get_path('module', 'bibdk_openuserstatus') . '/js/bibdk_openuserstatus.js',
  );

  return $form;
}

/**
 * Extracts reservations from each favourite library and collects them in a
 * single array
 *
 * @param array $response
 * @return array
 */
function bibdk_openuserstatus_get_reservations($response) {
  return bibdk_openuserstatus_get_group_elements($response, 'orderedItems', 'order');
}

/**
 * Creates the necessary items and header arrays for the loans tableselect form
 *
 * @param array $form The form array containing the entire form
 * @param array $loans List of loans
 * @param array $named_agencies Associative list of agency names
 * @return array
 */
function bibdk_openuserstatus_get_loans_table($form, $loans, $named_agencies) {

  $data = $disabled = array();

  $favourites = bibdk_favourite_get_favourites();

  $data['header'] = array(
    'material' => t('author_title', array(), array('context' => 'bibdk_openuserstatus')),
    'returndate' => t('returndate_header', array(), array('context' => 'bibdk_openuserstatus')),
  );

  $data['msg'] = t('no_loans_found', array(), array('context' => 'bibdk_openuserstatus'));

  $loans_text = t('Loans', array(), array('context' => 'bibdk_userstatus'));

  $data['items'] = array();

  $renew_marked = array(
    '#type' => 'submit',
    '#value' => t('renew_marked', array(), array('context' => 'bibdk_openuserstatus')),
    '#submit' => array('bibdk_openuserstatus_renew_marked_submit'),
    '#weight' => 10,
  );

  $renew_all = array(
    '#type' => 'submit',
    '#value' => t('renew_all', array(), array('context' => 'bibdk_openuserstatus')),
    '#submit' => array('bibdk_openuserstatus_renew_all_submit'),
    '#weight' => 15,
  );

  if (!empty($loans)) {
    $items = array();

    foreach ($loans as $material) {

      $item = array();
      $id = $material['loanId'] . ';' . $material['agencyId'];

      $status_html = bibdk_openuserstatus_check_returndate($material['dateDue']);

      if (!bibdk_openuserstatus_check_renewable($material, $favourites)) {
        $disabled[$id] = TRUE;
        $status_html['data']['#renewable'] = t('renewable_false_msg', array(), array('context' => 'bibdk_openuserstatus'));
      }

      $item['material'] = _bibdk_openuserstatus_material($material, $named_agencies[$material['agencyId']]);
      $item['returndate'] = $status_html;

      $items[$id] = $item;
    }

    $data['items'] = $items;
    $form['loans']['loans_renew_marked'] = $renew_marked;
    $form['loans']['loans_renew_all'] = $renew_all;
  }

  $form['loans']['loans_name'] = array(
    '#type' => 'html_tag',
    '#tag' => 'div',
    '#attributes' => array(
      'class' => array(
        'element-title',
      ),
    ),
    '#value' => $loans_text,
    '#value_prefix' => '<h2>',
    '#value_suffix' => '</h2>',
  );

  $form['loans']['loans_table'] = array(
    '#type' => 'tableselect',
    '#header' => $data['header'],
    '#options' => $data['items'],
    '#empty' => $data['msg'],
    '#js_select' => FALSE,
    '#sticky' => FALSE,
    '#multiple' => TRUE,
    '#attributes' => array(
      'class' => array('loans'),
    ),
  );

  //disable checkboxes
  foreach ($disabled as $id => $disable) {
    if ($disable) {
      $form['loans']['loans_table'][$id]['#disabled'] = TRUE;
    }
  }

  return $form;
}

/**
 * Extracts the currently loaned items from each favourite library and collects
 * them into a single array for easier parsing
 *
 * @param array $response
 * @return array
 */
function bibdk_openuserstatus_get_loans($response) {
  return bibdk_openuserstatus_get_group_elements($response, 'loanedItems', 'loan');
}

/**
 * Check if library allows renewal
 *
 * @param array $material
 * @return boolean
 */
function bibdk_openuserstatus_check_renewable($material, $favourites) {

  $agencyId = isset($material['agencyId']) ? $material['agencyId'] : FALSE;

  if (!$agencyId) {
    return FALSE;
  }

  if (!isset($favourites[$agencyId])) {
    return FALSE;
  }

  if ($favourites[$agencyId]->getRenewOrderAllowed()) {
    return TRUE;
  }

  return FALSE;

}

/**
 * Check if return date is valid (of format dd.mm.yyyy) and
 * returns render array if valid and empty string otherwise.
 *
 * @param string $returnDate
 * @return array|string
 */
function bibdk_openuserstatus_check_returndate($returnDate) {
  // strtotime returns FALSE on failure
  $timestamp = strtotime($returnDate);

  if (!$timestamp) {
    return '';
  }

  $date = date('d.m.Y', $timestamp);
  $limit = new DateTime($date);
  $limit->setTime(23, 59, 59);  // user has all day
  $now = new DateTime('now');

  $alert_class = 'no-alert';
  $title = '';

  if ($limit < $now) {
    $alert_class = 'red-alert';
    $date_overdue = t('Delivery_date_overdue', array(), array('context' => 'bibdk_openuserstatus'));
    $title = 'title="' . $date_overdue . '"';
  }

  return array(
    'data' => array(
      '#theme' => 'bibdk_openuserstatus_return_date',
      '#date' => $date,
      '#alert_class' => $alert_class,
      '#title' => $title,
    ),
  );
}

/**
 * Creates the necessary items and header arrays for the ready_for_pickup table
 * form
 *
 * @param array $form Form structure
 * @param array $reservations List of reservations
 * @param array $named_agencies Associative list of agency names
 * @return array
 */
function bibdk_openuserstatus_get_reservations_inprocess_table($form, $reservations, $named_agencies) {
  $header = array(
    'material' => t('author_title', array(), array('context' => 'bibdk_openuserstatus')),
    'library' => t('library_header', array(), array('context' => 'bibdk_openuserstatus')),
    'help' => '',
    'reservation_date' => array('data' => t('reservation_date', array(), array('context' => 'bibdk_openuserstatus')), 'class' => array('show-for-
large-up')),
    'queue_position' => t('queue_position', array(), array('context' => 'bibdk_openuserstatus')),
  );
  $msg = t('no_loans_found', array(), array('context' => 'bibdk_openuserstatus'));
  $options = array();
  $reservations_in_process = t('Reservations_in_process', array(), array('context' => 'bibdk_userstatus'));

  if (!empty($reservations)) {
    $in_process_states = array('In process', 'Requested via ill', 'Requested', 'Active');
    foreach ($reservations as $reservation) {
      if (isset($reservation['orderStatus']) && (in_array($reservation['orderStatus'], $in_process_states))) {
        // If reservation has pickUpExpiryDate set this is an order ready for
        // pickup due to an error in the webservice handling the response
        // from Integra libraries.
        // See also bibdk_openuserstatus_get_reservations_readyforpickup_table().
        if (isset($reservation['pickUpExpiryDate'])) {
          continue;
        }

        $pickUpAgencies = bibdk_openuserstatus_get_pickup_agencies($reservation['agencyId']);
        $item = array();
        $id = $reservation['orderId'];
        $item['material']['data'] = _bibdk_openuserstatus_material($reservation);
        $item['material']['class'] = array('userstatus--row-item--material-title');

        if (count($pickUpAgencies) > 1) {

          /* Dette virker pt ikke pga. openuserstatus
           $item['library']['data'] = bibdk_openuserstatus_select($pickUpAgencies, $reservation);
          */
          $item['help']['data'] = array(
            '#theme' => 'bibdk_openuserstatus_help_icon',
            '#label' => t('bibdk_openuserstatus_change_library', array(), array('context' => 'bibdk_userstatus')),
            '#element_id' => drupal_html_id($id),
          );

          $item['library']['data'] = $named_agencies[$reservation['agencyId']];
        }
        else {
          $item['library']['data'] = $named_agencies[$reservation['agencyId']];
          $item['help']['data'] = array(
            '#theme' => 'bibdk_openuserstatus_help_icon',
            '#label' => t('bibdk_openuserstatus_no_change_library', array(), array('context' => 'bibdk_userstatus')),
            '#element_id' => drupal_html_id($id),
          );
        }

        $item['reservation_date']['data'] = date('d.m.Y', strtotime($reservation['orderDate']));
        $item['queue_position']['data'] = (isset($reservation['holdQueuePosition']) ? $reservation['holdQueuePosition'] : '');
        $item['reservation_date']['class'] = array('show-for-large-up');
        $options[$id] = $item;
      }
    }

    $form['reservations']['reservations_delete'] = array(
      '#type' => 'submit',
      '#value' => t('delete_selected', array(), array('context' => 'bibdk_openuserstatus')),
      '#submit' => array('bibdk_openuserstatus_cancel_selected_submit'),
      '#weight' => 1,
    );
  }

  $form['reservations']['reservations_name'] = array(
    '#type' => 'html_tag',
    '#tag' => 'div',
    '#attributes' => array(
      'class' => array(
        'element-title',
      ),
    ),
    '#value' => $reservations_in_process,
    '#value_prefix' => '<h2>',
    '#value_suffix' => '</h2>',
  );
  $form['reservations']['reservations_table'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => $msg,
    '#js_select' => FALSE,
    '#sticky' => FALSE,
    '#multiple' => TRUE,
    '#attributes' => array(
      'class' => array(
        'reservations',
      ),
    ),
  );
  return $form;
}

/**
 * Returns a form array representing a select box. This is done in a
 * drupal_get_form to ensure the #default_value functionality
 *
 * @param $pickUpAgencies
 * @param $reservation
 * @return array $form
 */
function bibdk_openuserstatus_select($pickUpAgencies, $reservation) {
  $agencyId = $reservation['pickUpAgency'];

  if (strpos($agencyId, 'DK-') === 0) {
    $agencyId = substr($agencyId, 3, strlen($agencyId));
  }

  $pickupAgency = array_key_exists('pickUpAgencySubdivision', $reservation) ? $agencyId . '-' . $reservation['pickUpAgencySubdivision'] : $agencyId;
  $form['select'] = array(
    '#type' => 'select',
    '#options' => $pickUpAgencies,
    '#value' => $pickupAgency,
    '#attributes' => array(
      'class' => array(
        'openuserstatus-form-select-pickup-agency',
      ),
      'data-oid' => array(
        $reservation['orderId'],
      ),
      'data-caid' => array(
        $reservation['agencyId'],
      ),
    ),
  );
  return $form;
}

/**
 * Creates the necessary items and header arrays for the reservations
 * tableselect form
 *
 * @param array $form Form structure
 * @param array $reservations List of reservations
 * @param array $named_agencies Associative list of agency names
 * @return array
 */
function bibdk_openuserstatus_get_reservations_readyforpickup_table($form, $reservations, $named_agencies) {
  $data = array();
  $data['header'] = array(
    'material' => t('author_title', array(), array('context' => 'bibdk_openuserstatus')),
    'pickup_date' => t('pickup_date_header', array(), array('context' => 'bibdk_openuserstatus')) . ' /<br/>' . t('pickup_id_header', array(),
array('context' => 'bibdk_openuserstatus')),
  );
  $data['items'] = array();
  $readyforpcikTxt = t('Reservations_readyforpickup', array(), array('context' => 'bibdk_userstatus'));

  if (!empty($reservations)) {
    $items = array();
    $pickup_states = array('Available for pickup', 'Shelved', 'At reservation shelf');
    foreach ($reservations as $reservation) {
      $available_pickup = isset($reservation['orderStatus']) && in_array($reservation['orderStatus'], $pickup_states);
      // Last part of if statement is a fix for orders from Integra libraries
      // which has the orderStatus wrongfully set to 'In process' when order is
      // ready for pickup.
      // See also bibdk_openuserstatus_get_reservations_inprocess_table().
      $integra_pickup_bug = isset($reservation['pickUpExpiryDate']) && $reservation['orderStatus'] == 'In process';
      if ($available_pickup || $integra_pickup_bug) {
        $item = array();
        $pickupDate = isset($reservation['pickUpExpiryDate']) ? date('d.m.Y', strtotime($reservation['pickUpExpiryDate'])) : '';
        $pickupId = isset($reservation['pickUpId']) ? $reservation['pickUpId'] : '';
        $item['material'] = _bibdk_openuserstatus_material($reservation, $named_agencies[$reservation['agencyId']]);
        $pickUpAgency = isset($reservation['pickUpAgency']) ? $reservation['pickUpAgency'] : '';
        //get pickupagency name
        $agencybranchName = bibdk_openuserstatus_get_agencyname($reservation['pickUpAgency']);
        $item['pickup_date'] = '<span class="userstatus--date">' . $pickupDate . '</span>' . '<span class="userstatus--pickupid">' . $pickupId .
'</span>' . '<span class="userstatus--pickupid">' . '  ' . $agencybranchName . '' . '</span>';
        $items[] = $item;
      }
    }
    $data['items'] = $items;
  }

  $form['readyforpickup']['readyforpickup_name'] = array(
    '#type' => 'html_tag',
    '#tag' => 'div',
    '#attributes' => array(
      'class' => array(
        'element-title',
      ),
    ),
    '#value' => $readyforpcikTxt,
    '#value_prefix' => '<h2>',
    '#value_suffix' => '</h2>',
  );

  $form['readyforpickup']['readyforpickup_table'] = array(
    '#theme' => 'table',
    '#header' => $data['header'],
    '#rows' => $data['items'],
    '#empty' => t('no_loans_found', array(), array('context' => 'bibdk_openuserstatus')),
    '#attributes' => array(
      'class' => array(
        'table',
        'readyforpickup',
      ),
    ),
  );

  return $form;
}

/**
 * @param $form
 * @param $response
 * @return mixed
 */
function bibdk_openuserstatus_get_fiscal_account_table($form, $fiscals, $fiscals_total) {
  $fiscalBaseTxt = t('fiscal_account', array(), array('context' => 'bibdk_userstatus'));
  $fiscalTotalTxt = t('fiscal_total', array(), array('context' => 'bibdk_userstatus'));

  $form['fiscal']['fiscal_name'] = array(
    '#type' => 'html_tag',
    '#tag' => 'div',
    '#attributes' => array(
      'class' => array(
        'element-title',
      ),
    ),
    '#value' => $fiscalBaseTxt,
    '#value_prefix' => '<h2>',
    '#value_suffix' => '</h2>',
  );

  $header = array(
    'material' => t('author_title', array(), array('context' => 'bibdk_openuserstatus')),
    'type' => t('type_header', array(), array('context' => 'bibdk_openuserstatus')),
    'date' => array('data' => t('date_header', array(), array('context' => 'bibdk_openuserstatus')), 'class' => array('show-for-large-up')),
    'amount' => t('amount_header', array(), array('context' => 'bibdk_openuserstatus')),
  );

  if (!empty($fiscals_total)) {
    foreach ($fiscals_total as $fiscals_total_elsments) {
      foreach ($fiscals_total_elsments as $fiscals_total_elsment) {
        $form['fiscal']['fiscal_total'][] = array(
          '#type' => 'html_tag',
          '#tag' => 'div',
          '#attributes' => array(
            'class' => array(
              'element-title',
            ),
          ),
          '#value' =>  ' ' . $fiscalTotalTxt . ' ' . $fiscals_total_elsment,
          '#value_prefix' => '<h3>',
          '#value_suffix' => '</h3>',
        );
      }
    }
  }

  if (!empty($fiscals)) {
    $items = array();
    $favourites = bibdk_favourite_get_favourites();
    global $language;

    foreach ($fiscals as $reservation) {
      $item = array();
      $agencyId = (isset($reservation['agencyId']) ? $reservation['agencyId'] : NULL);
      $item['material'] = _bibdk_openuserstatus_material($reservation);
      $item['type']['data'] = ''; //t($reservation['fiscalTransactionType'], array(), array('context' => 'bibdk_openuserstatus'));
      $item['date']['data'] = date('d.m.Y', strtotime($reservation['fiscalTransactionDate']));
      $item['date']['class'] = array('show-for-large-up');
      $item['amount'] = $reservation['fiscalTransactionAmount'] . ' ' . $reservation['fiscalTransactionCurrency'];
      $items[$agencyId][] = $item;
    }

    foreach (array_keys($items) as $agencyId) {
      $agency = array();
      $agency['items'] = $items[$agencyId];
      if (isset($favourites[$agencyId])) {
        $agency['branchName'] = $favourites[$agencyId]->getBranch()->getBranchShortName($language->language);
        $agency['paymentUrl'] = $favourites[$agencyId]->getBranch()->getPaymentUrl();
      }
      $agency['class'] = 'fiscal-account';
      $agency['msg'] = t('we_have_no_registered_debt_associated_with_your_name', array(), array('context' => 'bibdk_openuserstatus'));
      $agency['header'] = $header;
      $form['fiscal'][$agencyId]['branchName'] = array(
        '#type' => 'html_tag',
        '#tag' => 'div',
        '#attributes' => array(
          'class' => array(
            'element-title',
          ),
        ),
        '#value' => $agency['branchName'],
        '#value_prefix' => '<h3>',
        '#value_suffix' => '</h3>',
      );
      /* $agency['items'] has an error due to OpenUserStatus response.
      $form['fiscal'][$agencyId]['fiscal_table'] = array(
        '#theme' => 'table',
        '#header' => $agency['header'],
        '#rows' => $agency['items'],
        '#empty' => $agency['msg'],
        '#attributes' => array(
          'class' => array(
            'table',
            $agency['class'],
          ),
        ),
      );
      */
      if (!empty($agency['paymentUrl'])) {
        $form['fiscal'][$agencyId]['fiscal_branch_link'] = array(
          '#type' => 'markup',
          '#prefix' => '<div class="payment-url-link">',
          '#suffix' => '</div>',
          '#markup' => l(t('fiscal_branch_link', array(), array('context' => 'bibdk_openuserstatus')), $agency['paymentUrl'], array(
            'attributes' => array(
              'class' => array('btn', 'btn-blue'),
              'target' => array('_blank'),
            ),
          )),
        );
      }
    }
  }

  return $form;
}

/**
 * Extracts the currently fiscal items from each favourite library and collects
 * them into a single array for easier parsing
 *
 * @param array $response
 * @return array
 */
function bibdk_openuserstatus_get_fiscals($response) {
  $resp = bibdk_openuserstatus_get_group_elements($response, 'fiscalAccount', 'fiscalTransaction');
  return $resp;
}

/**
 * Extracts the total amount fiscal items from each favourite library and return the accumulated amount
 *
 * @param array $response
 * @return string
 */
function bibdk_openuserstatus_get_fiscals_total($response) {
  return bibdk_openuserstatus_get_group_element_amount($response);
}

/**
 * Extracts the from the user status each specified element from a group and
 * returns the elements as an array
 *
 * @param array $user_status
 * @param string $group
 * @param string $element
 * @return array
 */
function bibdk_openuserstatus_get_group_elements($user_status, $group, $element) {
  $items = array();
  foreach ($user_status as $agencyId => $agency_data) {
    if (is_object($agency_data)) {
      $resp = $agency_data->getResponse();
      if (isset($resp[$group][$element])) {
        foreach ($resp[$group][$element] as $item) {
          $item['agencyId'] = $agencyId;
          $items[] = $item;
        }
      }
    }
  }

  return $items;
}

/**
 * Extracts the from the user status each specified element from a group and
 * returns the accumulated ammount for each library
 *
 * @param array $user_status
 * @return array
 */
function bibdk_openuserstatus_get_group_element_amount($user_status) {
  $favourites = bibdk_favourite_get_favourites();
  global $language;
  $items = array();
  foreach ($user_status as $agencyId => $agency_data) {
    if (is_object($agency_data)) {
      if (isset($agency_data->response['fiscalAccount']['totalAmount'])) {
        if ($agency_data->response['fiscalAccount']['totalAmount'] > 0 ) {
          $currency_text = t($agency_data->response['fiscalAccount']['totalAmountCurrency'], array(), array('context' => 'bibdk_openuserstatus'));
          if (!is_null($favourites[$agencyId]) && $favourites[$agencyId]->getBranch() !== NULL) {
            $items['agencyId'][] = $favourites[$agencyId]->getBranch()->getBranchShortName($language->language) . ' ' . $currency_text . ' ' . $agency_data->response['fiscalAccount']['totalAmount'];
          }
        }
      }
    }
  }
  return $items;
}

/**
 * Formats a material with author and title if the elements are present.
 *
 * @param array $material
 * @param string $library
 * @return array
 */
function _bibdk_openuserstatus_material($material, $library = '') {
  return array(
    'data' => array(
      '#theme' => 'bibdk_openuserstatus_row_item',
      '#author' => (!empty($material['author']) ? $material['author'] : ''),
      '#title' => (!empty($material['title']) ? $material['title'] : ''),
      '#library' => $library,
    ),
  );
}

/**
 * Returns a list of unique agencyIds given a list of reservations.
 *
 * @param array $reservations
 * @return array
 */
function bibdk_openuserstatus_get_pickup_agencies_from_material_list($reservations) {
  $agencies = array();

  foreach ($reservations as $reservation) {
    if (isset($reservation['agencyId'])) {
      if (!in_array($reservation['agencyId'], $agencies)) {
        $agencies[] = $reservation['agencyId'];
      }
    }
  }

  return $agencies;
}

/**
 * Looks up names for a list of agencies.
 *
 * @param array $agencies
 * @return array
 */
function bibdk_openuserstatus_agency_names($agencies) {
  $named_agencies = array();

  foreach ($agencies as $agency) {
    $named_agencies[$agency] = bibdk_openuserstatus_get_agencyname($agency);
  }

  return $named_agencies;
}

/**
 * Looks up names for a list of agencies.
 *
 * @param array $agencies
 * @return array
 */
function bibdk_openuserstatus_agency_name_main($agencies) {
  $named_agencies = array();

  foreach ($agencies as $agency) {
    $named_agencies[$agency] = bibdk_openuserstatus_get_agencyname_main($agency);
  }

  return $named_agencies;
}
