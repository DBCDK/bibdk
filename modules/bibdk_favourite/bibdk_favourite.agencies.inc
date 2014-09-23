<?php

function bibdk_favourite_load_agency($xml) {
  $dom = new DomDocument();
  if (!@$dom->loadXML($xml)) {
    if (variable_get('bibdk_provider_enable_logging')) {
      watchdog('bibdk_favourite', t('BIBDK favourite could not load response: %xml', array('%xml' => var_export($xml, TRUE))), array(), WATCHDOG_ERROR);
    }
    return array();
  }

  $xpath = new DomXPATH($dom);
  $xpath->registerNamespace('oui', 'http://oss.dbc.dk/ns/openuserinfo');
  return $xpath;
}

/**
 * @param $xml xml from request to openuserinfo (getFavourites)
 * @return array 
 */
function bibdk_favourite_parse_agencies($xml) {
  $xpath = bibdk_favourite_load_agency($xml);

  if (empty($xpath)) {
    return FALSE;
  }
  // grab agencies
  $query = '//oui:agency'; //OpenUserInfo v1.7
  $nodelist = $xpath->query($query);
  // check if empty
  if ( empty($nodelist) || $nodelist->length == 0 ) {
    $query = '//agency'; // fallback to OpenUserInfo v1.6
    $nodelist = $xpath->query($query);
    if ( empty($nodelist) || $nodelist->length == 0 ) {
      return array();
    }
  }

  $agencies = array();
  foreach ($nodelist as $node) {
    if (!empty($node->childNodes)) {
      foreach ($node->childNodes as $child) {
        $agency[$child->nodeName] = $child->nodeValue;
      }
    }
    $agencies[$agency['oui:agencyId']] = $agency;
  }
  return $agencies;
}

?>
