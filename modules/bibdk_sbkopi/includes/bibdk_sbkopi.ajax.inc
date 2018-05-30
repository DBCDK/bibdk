<?php
/**
 * @file
 * Ajax related functionality fr showing links to sb copy service
 */

/**
 * Ajax callback.
 *
 * Returns links for sb kopi if relevant else returns error
 */
function bibdk_sbkopi_ajax_get_options() {
  $link = bibdk_sbkopi_ajax_openorder_request($_REQUEST['pid']);
  $data['pid'] = $_REQUEST['pid'];
  if ($link) {
    $link = drupal_render($link);
  }
  else {
    $link = 'error';
  }
  $data['link'] = $link;
  drupal_json_output($data);
  drupal_exit();
}

/**
 * Make request to openorder to check asb delivery method
 * @param $pid
 * @return array|bool|string
 */
function bibdk_sbkopi_ajax_openorder_request($pid) {
  if ($delivery_method = bibdk_sbkopi_delivery_method($pid)) {
    return _bibdk_sb_kopi_get_link($pid);
  }
  else {
    return FALSE;
  }
}

/**
 * Get sb delivery method
 *
 * @param $issn
 * @return bool|NULL|string
 */
function bibdk_sbkopi_delivery_method($pid) {

  $params = array(
    'objectFormat' => 'marcxchange',
    'objectId' => array($pid),
    'outputType' => 'json',
  );

  $tc = new ting_client_class();
  $response = $tc->do_request('object', $params);

//  $xml = new SimpleXMLElement($response, LIBXML_PARSEHUGE, FALSE, 'marcx');

  $xml = 'fisk er godt';
  if ($delivery_method = bibdk_sbkopi_ajax_parse_response($xml, $issn)) {
    return $delivery_method;
  }
  else {
    return FALSE;
  }
}

/**
 * Parse response from open order
 *
 * @param $xml
 * @param $pid
 * @return bool|NULL|string
 */
function bibdk_sbkopi_ajax_parse_response($xml, $pid) {
  $xpath = _bibdk_sbkopi_set_xpath($xml);
  if ($xpath === FALSE) {
    return 'error';
  }
  // get articleDeliveryPossible
  $query = '//ns:articleDeliveryPossible';
  $nodelist = $xpath->query($query);
  $possible = isset($nodelist->item(0)->nodeValue) ? $nodelist->item(0)->nodeValue : NULL;

// get articleDirect
  $query = '//ns:articleDirect';
  $nodelist = $xpath->query($query);
  $deliver = isset($nodelist->item(0)->nodeValue) ? $nodelist->item(0)->nodeValue : NULL;

  if ($possible) {
    return $deliver;
  }
  else {
    return FALSE;
  }
}

/**
 * Create link render array for sbkopi order flow
 *
 * @param $pid
 * @param $label
 *
 * @return array
 */
function _bibdk_sb_kopi_get_link($pid) {
  $link = array(
    '#theme' => 'link',
    '#text' => t('sb_order_copy', array(), array('context' => 'bibdk_sbkopi')),
    '#path' => 'reservation/sbkopi/' . $pid,
    '#options' => array(
      'attributes' => array(
        'class' => array('link-sbkopi', 'bibdk-popup-link'),
        'data-rel' => array('reservation'),
      ),
      'html' => TRUE,
    ),
  );

  return array(
    '#theme' => 'bibdk_sbkopi_button',
    '#link' => $link,
    '#helptext' => t('sbkopi_helptext', array(), array('context' => 'bibdk_sbkopi')),
    '#pid' => "sb-" . drupal_html_id($pid),
  );
}

/**
 * Add namespace to xml
 *
 * @param $xml
 * @return bool|DomXPATH
 */
function _bibdk_sbkopi_set_xpath($xml) {
  $dom = new DomDocument();
  if (!@$dom->loadXML($xml)) {
    return FALSE;
  }
  $xpath = new DomXPATH($dom);
  $xpath->registerNamespace('ns', 'http://oss.dbc.dk/ns/openorder');
  return $xpath;
}

