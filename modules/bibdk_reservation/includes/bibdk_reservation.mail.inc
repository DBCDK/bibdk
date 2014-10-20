<?php
/**
 * @file
 * Methods for sending mails in the reservation flow
 */

/**
 * Submit form for sendmail button
 *
 * @param array $form
 * @param array $form_state
 */
function bibdk_reservation_mail_form_submit($form, &$form_state) {

  $pids = BibdkReservationOrderObject::GetObject()->getManifestationIds();
  $userdata = BibdkReservationOrderObject::GetObject()->getUserOrderData();
  $orderdata = BibdkReservationOrderObject::GetObject()->getOrderParameters();

  $params = array();
  $params['manifestations'] = $pids;

  $params += array('subject' => t('Your order reciept', array(), array('context' => 'bibdk_reservation')));

  $articleDirect = BibdkReservationOrderObject::GetObject()->getArticleDirect();
  if (!empty($articleDirect)) {
    $params += array('articleDirect' => 'pickup');
  }

  $params += (isset($userdata)) ? $userdata : array();
  $params += (isset($orderdata)) ? $orderdata : array();
  $params += array(
    'pid' => $pids,
    'pickUpAgencyId' => BibdkReservationOrderObject::GetObject()->getBranchId(),
    'needBeforeDate' => BibdkReservationOrderObject::GetObject()->getNeedBeforDate(),
  );

  bibdk_reservation_mail_send($params, $form_state);

  //force rebuild form_state for step 4
  $form_state['step'] = 4;
  $form_state['rebuild'] = TRUE;

}

/**
 * Implements mail delivery for users order
 *
 * @param $params
 * @param $form_state
 */
function bibdk_reservation_mail_send($params, $form_state) {

  global $language;
  $module = 'bibdk_reservation';
  $key = 'mail_bibdk_reservation';

  // check for user order email
  if (!empty($params['userMail'])) {
    $to = $params['userMail'];
  }
  // check for user alternative email
  if (empty($to) && !empty($form_state['values']['email'])) {
    $to = $form_state['values']['email'];
  }

  if (!empty($to)) {
    $from = variable_get('bibdk_reservation_mail_send', 'noreply@bibliotek.dk');
    $send = TRUE;

    $result = drupal_mail($module, $key, $to, $language, $params, $from, $send);
    if ($result['result'] == TRUE) {
      drupal_set_message(t('Your mail message has been sent.', array('context' => 'bibdk_reservation')), $type = 'status');
    }
    else {
      drupal_set_message(t('There was a problem sending your message and it was not sent.', array('context' => 'bibdk_reservation')), $type = 'error');
    }
  }

}

/**
 * Implements hook_mail()
 * Deliver data to template: bibdk_reservation_order_mail
 */
function bibdk_reservation_mail($key, &$message, $params) {

  if ($key == 'mail_bibdk_reservation') {
    global $language;
    // set mail variables
    $header = variable_get('mail_bibdk_reservation_email_header', '');
    $footer = variable_get('mail_bibdk_reservation_email_footer', '');

    $manifestation = BibdkReservationOrderObject::GetObject()->getManifestation();
    $message['subject'] = $params['subject'] . _bibdk_reservation_mail_get_title($manifestation);

    $message['body'][] = !empty($header) ? t($header, array(), array('context' => 'bibdk_reservation')) : '';

    $branch = BibdkReservationOrderObject::GetObject()->getBranch();

    //make data for template: bibdk_reservation_order_mail
    $message['body'][] = theme('bibdk_reservation_mail', array(
      'headertext' => t('Your order is complete', array(), array('context' => 'bibdk_reservation')),
      'orderidtext' => t('Your order ID', array(), array('context' => 'bibdk_reservation')),
      'orderid' => BibdkReservationOrderObject::GetObject()->getOrderId(),
      'userparameter' => t('User Parameters', array(), array('context' => 'bibdk_reservation')),
      'userinfo' => bibdk_reservation_mail_user(),
      'manifestation' => t('Manifestation', array(), array('context' => 'bibdk_reservation')),
      'subtype' => $manifestation->getSubType(),
      'title' => $manifestation->getTitleSpecific(),
      'author' => _bibdk_reservation_mail_get_author($manifestation),
      'branch' => t('Branch', array(), array('context' => 'bibdk_reservation')),
      'branchtext' => $branch->getBranchShortName($language->language),
      'addresstext' => $branch->postalAddress,
      'postalCodetext' => $branch->postalCode,
      'citytext' => $branch->city,
      'orderparameters' => t('Order Parameters', array(), array('context' => 'bibdk_reservation')),
      'orderinfo' => bibdk_reservation_mail_order_parameters(),
      'IllOrderReceiptText' => $branch->getIllOrderReceiptText($language->language),
    ));
    $message['body'][] = !empty($footer) ? t($footer, array(), array('context' => 'bibdk_reservation')) : '';
  }

}

/**
 * Retreives the author from the ordered material. If no author is found an empty
 * string is returned.
 *
 * @param Manifestation $manifestation
 * @return string
 */
function _bibdk_reservation_mail_get_author($manifestation) {
  $creators = $manifestation->getCreator();
  $author = '';
  if (isset($creators)) {
    foreach ($creators as $creator) {
      foreach ($creator as $key => $value) {
        if (!empty($author)) {
          $author .= ' ';
        }
        $author .= $value[0][0]['display'];
      }
    }
  }
  return $author;
}

/**
 * Retreives the title from the ordered material. If no title is found an empty
 * string is returned.
 *
 * @param Manifestation $manifestation
 * @return string
 */
function _bibdk_reservation_mail_get_title($manifestation) {
  
  $titleSpecific = $manifestation->getTitleSpecific();
  $creators = $manifestation->getCreator();
  $author = '';
  if (isset($creators)) {
    foreach ($creators as $creator) {
      foreach ($creator as $key => $value) {
        $author .= ' ' . $value[0][0]['display'];
      }
    }
  }
  $type = $manifestation->getSubType();

  if (!empty($titleSpecific)) {
    $returnTitle = ' - ' . $titleSpecific;
    if (!empty($author)) {
      $returnTitle .= ', ' . $author;
    }
    if (!empty($type)) {
      $returnTitle .= ', ' . $type;
    }
    return $returnTitle;
  }
  return '';

}

/**
 * Implements orderformating for email an return array with orderinformation
 */
function bibdk_reservation_mail_order_parameters() {

  $orderParamWithLabel = array();
  $orderParameters = BibdkReservationOrderObject::GetObject()->getOrderParameters();
  if (isset($orderParameters)) {
    foreach ($orderParameters as $type => $orderParameter) {
      $orderParamWithLabel[bibdk_reservation_get_agency_fields()->getOrderLabelFromType($type)] = $orderParameter;
    }
    $rows[] = array();
    $arrycount = 0;
    foreach ($orderParamWithLabel as $key => $value) {
      $rows[$arrycount] = t($key, array(), array('context' => 'material_type')) . " \t" . check_plain($value);
      $arrycount = $arrycount + 1;
    }

    return $rows;
  }

  return NULL;

}

/**
 * Implements titleformating for email an return array with titleinformation
 *
 * @param Manifestation $manifestation
 * @return array
 */
function bibdk_reservation_mail_title(Manifestation $manifestation) {

  $title = $manifestation->getTitleSpecific();
  $contribs = $manifestation->getContributors();
  $author = isset($contribs) && is_array($contribs) ? implode(', ', $contribs) : NULL;
  $type = $manifestation->getSubType();

  return array(
    'title' => $title,
    'author' => $author,
    'type' => $type,
  );

}

/**
 * Implements userformating for email and return array with userinformation
 */
function bibdk_reservation_mail_user() {

  $user_data_array = BibdkReservationOrderObject::GetObject()->getUserData();
  if (isset($user_data_array)) {
    $arrycount = 0;
    $rows[] = array();
    foreach ($user_data_array as $key => $value) {
      $rows[$arrycount] = $rows[$arrycount] = t($key, array(), array('context' => 'bibdk_reservation')) . "  \t" . $value;
      $arrycount = $arrycount + 1;
    }

    return $rows;
  }

  return NULL;

}
