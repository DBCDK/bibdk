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
 *
 * @param $pid
 * @param bool $reservation
 *
 * @return bool|array|string
 */
function bibdk_sbkopi_ajax_openorder_request($pid, $reservation = FALSE) {
  if ($delivery_method = bibdk_sbkopi_delivery_method($pid)) {
    return _bibdk_sb_kopi_get_link($pid);
  }
  else {
    return ($reservation === TRUE) ? "error" : FALSE;
  }
}

/**
 * Get sb delivery method
 *
 * @param $pid
 * @return bool|NULL|string
 */
function bibdk_sbkopi_delivery_method($pid) {

  // These two functions below are temporary and will be replaced when
  // openformat can handle single field requests.
  $response = bibdk_sbkopi_do_marcxchangeRequest($pid);
  $issn = bibdk_sbkopi_parse_marcx($response);

  if (!empty($issn)) {
    $xml = bibdk_sb_kopi_do_article_request($issn);
  }
  else {
    $xml = FALSE;
  }

  if ($xml !== FALSE) {
    if ($delivery_method = bibdk_sbkopi_ajax_parse_response($xml)) {
      return $delivery_method;
    }
    else {
      return FALSE;
    }
  }
  else {
    return FALSE;
  }
}

/**
 * Parsing response from OpenSearch with marcxchange format.
 * This is a temporary fix until OpenFormat can deliver single fields.
 *
 * @param $pid
 *
 * @return bool|mixed|\stdClass|string
 */
function bibdk_sbkopi_do_marcxchangeRequest($pid) {
  $params = array(
    'objectFormat' => 'marcxchange',
    'objectId' => array($pid),
    'outputType' => 'xml',
  );

  $tc = new ting_client_class();
  return $tc->do_request('object', $params, FALSE);
}

/**
 * Parsing response from OpenSearch with marcxchange format.
 * This is a temporary fix until OpenFormat can deliver single fields.
 *
 * @param $response
 *
 * @return string
 *   empty string if nothing found- issn of element if found
 */
function bibdk_sbkopi_parse_marcx($response) {
  $xml = new SimpleXMLElement($response);

  $namespaces = $xml->getNamespaces(TRUE);
  foreach ($namespaces AS $prefix => $namespace) {
    $xml->registerXPathNamespace($prefix, $namespace);
  }

  $issn = "";
  if (isset($xml->result->searchResult->collection->object)) {
    $obj = $xml->result->searchResult->collection->object;
    $record = $obj->children($namespaces['marcx'])->collection->record;
    if (!empty($record)) {
      foreach ($record->datafield AS $datafield) {
        foreach ($datafield->attributes() AS $key => $value) {
          $tagv = $value->__toString();
          if ($key === "tag" && ($tagv === "022" || $tagv === "557")) {
            foreach ($datafield->subfield AS $subfield) {
              if ($tagv === "022" && $subfield->attributes()->code->__toString() === "a") {
                $issn = $subfield->__toString();
              }
              else if ($tagv === "557" && $subfield->attributes()->code->__toString() === "z") {
                $issn = $subfield->__toString();
              }
            }
          }
        }
      }
    }
  }
  return $issn;
}

/**
 * Do a request to sbkopi article service - check if given issn is deliverable.
 *
 * @param $issn
 * @return bool|SimpleXMLElement
 */
function bibdk_sb_kopi_do_article_request($issn) {
  $url = variable_get('bibdk_sbkopi_journal_url');
  $url .= '?issn=' . str_replace('-', '', $issn);
  $url .= "&date=" . date('Y-m-d');

  try {
    $micro = new MicroCURL(array());
  }
  catch (\MicroCURLException $e) {
    watchdog('bibdk_sbkopi', 'sb kopi fejlede %message', array('%message' => $e->getMessage()));
    return FALSE;
  }

  if ($content = $micro->get($url)) {
    return simplexml_load_string($content);
  }

  watchdog('bibdk_sbkopi', 'sb kopi fejlede med url %url', array('%url' => $url));

  return FALSE;
}

/**
 * Parse response from open order
 *
 * @param \SimpleXMLElement $xml
 *
 * @return bool|string
 */
function bibdk_sbkopi_ajax_parse_response($xml) {
  $possible = $xml->eDeliveryAllowed->__toString();
  return ($possible === "true") ? "electronic" : FALSE;
}

/**
 * Create link render array for sbkopi order flow
 *
 * @param $pid
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

