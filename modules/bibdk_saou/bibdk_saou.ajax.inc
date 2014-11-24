<?php

/**
 * @file
 * This file handles ajax calls to saou webservice
 */

/**
 * Ajax page callback
 *
 * @param null $pid
 * @param null $url
 */
function bibdk_saou_ajax($pid = NULL, $url = NULL) {
  $pid = check_plain($_POST['pid']);
  $url = check_plain($_POST['url']);
  $alt_pid = check_plain($_POST['altpid']);

  if ($url == 'NONE') {
    $url = NULL;
  }
  if ($alt_pid == 'NONE') {
    $alt_pid = NULL;
  }
  //use case: pid starts with 870970-basis and no relationurl is given
  if (strpos($pid, '870970-basis') === 0 && empty($url)) {
    $output = bibdk_saou_ajax_fetchLicensByPid($pid);
  }
  elseif (!empty($url)) {
    $output = bibdk_saou_fetchLicenseByUrl($pid, $url, $alt_pid);
  }
  else {
    // default behoviour
    $output = bibdk_saou_ajax_fetchLicensByPid($pid);
  }
  drupal_json_output($output);
  drupal_exit();
}

/**
 * Do fetchLicenseByUrl request and pass response to output function
 * @param $pid
 * @param $url
 * @return array, render array from output function
 */
function bibdk_saou_fetchLicenseByUrl($pid, $url, $alt_pid = NULL) {
  $agency_and_user_ids = bibdk_saout_get_agency_and_userids($agency_id);
  $response = open_saou_FetchLicenseByUrl($pid, $url, $agency_and_user_ids, $agency_id, $alt_pid);
  $saou = bibdk_saou_check_saou_response($response);

  return bibdk_saou_get_output_by_permission($saou, $pid, $url);
}

/**
 * Check response. If ok create a responseobject if not initialize with empty object
 * @param $response
 * @return SaouResponse
 */
function bibdk_saou_check_saou_response($response) {
  if ($response) {
    $saou = new SaouResponse($response);
  }
  else {
    $saou = new SaouResponse(new stdClass());
  }

  return $saou;
}

/**
 * Do fetchLicenseByPid request, and pass response to output function.
 * @param $pid
 * @return array, render array from output function
 */
function bibdk_saou_ajax_fetchLicensByPid($pid) {
  $agency_and_user_ids = bibdk_saout_get_agency_and_userids($agency_id);
  $response = open_saou_FetchLicenseByPid($pid, $agency_and_user_ids, $agency_id);
  $saou = bibdk_saou_check_saou_response($response);

  return bibdk_saou_get_output_by_permission($saou, $pid);
}

/**
 * get orderagency from bibdk_favourites.
 * set given agencyId by reference
 *
 * @param $agency_id NOTICE by reference
 * @return array agencyAndUserId => [agencyId, userId]
 */
function bibdk_saout_get_agency_and_userids(&$agency_id) {
  $agency_and_user_ids = array();
  $agency = bibdk_saou_get_order_agency();
  if (!empty($agency)) {
    // saou do NOT accept a branchid - get the mainId
    $agency_id = $agency->getAgencyMainId();

    $agency_and_user_ids = array(
      'agencyAndUserId' => array(
        'agencyId' => $agency_id,
        'userId' => $agency->getUserId(),
      )
    );
  }

  return $agency_and_user_ids;
}

/**
 * Create the arrays to json output.
 *
 * @param SaouResponse object, $saou
 * @param string $pid
 * @return array, Render array az expected by drupal_render
 */
function bibdk_saou_get_output_by_permission($saou, $pid, $url = NULL) {
  $permission = $saou->getlicenseInfo();
  if (empty($permission)) {
    // get the manifestation to display default link
    $manifestation = bibdk_saou_get_manifestation($pid);
    $txt = $manifestation->getInfotext();
    $url = $manifestation->getSingleAccessUrl();

    $value['accessUrl'] = current($url);
    $code = $saou->get_responseCode();
    $message = isset($code) ? $code : 'internal error: malformed answer from saou';
    $value['accessUrlDisplay'] = $message;

    $element[] = $value;
    $link = _ting_openformat_parse_element($element);

    // no licenseinfo - permission is NULL
    $message = $link;
    $output = bibdk_saou_field_get_element_to_toggle($message);
    bibdk_saou_remove_hidden_class($output['container']['#attributes']['class']);
    $html = drupal_render($output);
    $output = array(
      'error' => $html,
      'selector' => bibdk_saou_field_pid_to_selector($pid)
    );

    return $output;
  }
  if ($permission) {
    // permission is ok
    $proxy = $saou->get_proxyLink();
    if (!empty($proxy)) {
      $link = $proxy;
    }
    if (empty($link)) {
      $link = $saou->get_link();
    }

    $remote_user_access = $saou->get_remoteUserAccess();
    if ($link && $remote_user_access) {
      $output = bibdk_saou_ajax_get_proxylink($link, $pid);

      return array(
        'redirect' => $output,
        'selector' => bibdk_saou_field_pid_to_selector($pid),
        'error' => ''
      );
    }
    elseif ($link && empty($remote_user_access)) {
      $message = t('bibdk_saou_walkin_access', array(), array('context' => 'bibdk_saou'));
      $url = l($message, $link, array('attributes' => array('target' => '_blank')));
      $output = bibdk_saou_field_get_element_to_toggle($url);
      bibdk_saou_remove_hidden_class($output['container']['#attributes']['class']);
      $html = drupal_render($output);
      $output = array(
        'error' => $html,
        'selector' => bibdk_saou_field_pid_to_selector($pid)
      );

      return $output;
    }
    else {
      // this is an error from saou service.
      $message = 'internal error: no link to proxy';
      $output = bibdk_saou_field_get_element_to_toggle($message);
      bibdk_saou_remove_hidden_class($output['container']['#attributes']['class']);
      $html = drupal_render($output);
      $output = array(
        'error' => $html,
        'selector' => bibdk_saou_field_pid_to_selector($pid)
      );

      return $output;
    }
  }
}

/**
 * Remove hidden class for toggle element. It should be shown after ajax callback
 * @param array $classes
 */
function bibdk_saou_remove_hidden_class(array &$classes) {
  foreach ($classes as $key => $class) {
    if ($class == 'hidden') {
      unset($classes[$key]);
      break;
    }
  }
}

/**
 * Define a link to proxy.
 *
 * @param string $link , url
 * @param string $pid
 * @return string,html as ouptput by drupal_render
 */
function bibdk_saou_ajax_get_proxylink($link, $pid) {
  $message = t('bibdk_saou_click_here_for_access', array(), array('context' => 'bibdk_saou'));
  $proxy_link = array(
    '#theme' => 'link',
    '#text' => $message,
    '#path' => $link,
    '#options' => array(
      'attributes' => array(
        'target' => '_blank',
        'id' => bibdk_saou_field_pid_to_selector($pid)
      ),
      'html' => FALSE,
      'absolute => TRUE',
    ),
  );

  return drupal_render($proxy_link);
}
