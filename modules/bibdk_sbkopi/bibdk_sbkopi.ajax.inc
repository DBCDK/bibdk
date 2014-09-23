<?php

function bibdk_sbkopi_ajax_get_options() {
  $result = bibdk_sbkopi_ajax_openorder_request($_REQUEST['pid']);
  $data['pid'] = $_REQUEST['pid'];
  if ($result != 'error') {
    $result['#options']['attributes']['class'] = array('bibdk-popup-link');
    $result = drupal_render($result);
  }
  $data['link'] = $result;
  drupal_json_output($data);
}

function bibdk_sbkopi_ajax_openorder_request($pid) {
  $xml = bibdk_openorder_do_checkArticleDeliveryRequest($pid);
  return bibdk_sbkopi_ajax_parse_response($xml, $pid);
}

function bibdk_sbkopi_ajax_parse_response($xml, $pid) {
  $xpath = _bibdk_sbkopi_set_xpath($xml);
  if ($xpath === FALSE) {
    return 'error';
  }
  // get articleDeliveryPossible
  $query = '//ns:articleDeliveryPossible';
  $nodelist = $xpath->query($query);
  $possible = isset($nodelist->item(0)->nodeValue) ? $nodelist->item(0)->nodeValue : null;

// get articleDirect
  $query = '//ns:articleDirect';
  $nodelist = $xpath->query($query);
  $deliver = isset($nodelist->item(0)->nodeValue) ? $nodelist->item(0)->nodeValue : null;

  if ($possible) {
    $result = _bibdk_sbkopi_make_link($deliver, $pid);
  }
  else {
    return 'error';
  }
  return $result;
}

function _bibdk_sbkopi_make_link($method, $pid) {
  // two methods postal (print), electronic (e-copy)
  switch ($method) {
    case 'postal' :
      $label = '<span class="icon icon-left icon-lightgrey-link">&nbsp</span>' . t('order_printed_copy', array(), array('context' => 'bibdk_sbkopi'));
      return _bibdk_sb_kopi_get_link($pid, $label, 'PAY');
    case 'electronic' :
      $label = '<span class="icon icon-left icon-lightgrey-link">&nbsp</span>' . t('order_electronic_copy', array(), array('context' => 'bibdk_sbkopi'));
      return _bibdk_sb_kopi_get_link($pid, $label, 'FREE');
    default :
      return 'error';
  }
}

function _bibdk_sb_kopi_get_link($pid, $label, $type) {
  //$ref = url('reservation', array('query' => array('ids'=>$pid,'bestil_kopi'=>$type)));
  //return array('href' => $ref, 'text' => $label);
  return array(
    '#theme' => 'link',
    '#text' => $label,
    '#path' => 'reservation',
    '#options' => array(
      'attributes' => array(),
      'html' => true,
      'query' => array('ids'=>$pid,'bestil_kopi'=>$type)
    ),
  );
}

function _bibdk_sbkopi_set_xpath($xml) {
  $dom = new DomDocument();
  if (!@$dom->loadXML($xml)) {
    return FALSE;
  }
  $xpath = new DomXPATH($dom);
  $xpath->registerNamespace('ns', 'http://oss.dbc.dk/ns/openorder');
  return $xpath;
}

