<?php

/**
 * @file
 * Add search history element to provider webservice
 * @param $element
 * @param null $user
 * @return mixed
 */

function _bibdk_searchhistory_add_element_webservice($element, $user = NULL) {
  if ($response = _bibdk_searchhistory_call_webservice('add_searchhistory', $element, $user)) {
    $xpath = bibdk_searchhistory_webservice_responce_xpath($response['response']);
    $ids = bibdk_searchhistory_parse_id($xpath);
    return reset($ids);
  }
  return NULL;
}

/** Remove search history element to provider webservice
 * @param $element
 * @param null $user
 * @return mixed
 */
function _bibdk_searchhistory_remove_element_webservice($element, $user = NULL) {
  if ($response = _bibdk_searchhistory_call_webservice('remove_searchhistory', $element, $user)) {
    $xpath = bibdk_searchhistory_webservice_responce_xpath($response['response']);
    $ids = bibdk_searchhistory_parse_id($xpath);
    return reset($ids);
  }
  return NULL;
}

/**
 * Get search history from provider webservice
 * @param null $user
 * @return array
 */
function _bibdk_searchhistory_get_elements_webservice($user = NULL) {
  if ($response = _bibdk_searchhistory_call_webservice('get_searchhistory', NULL, $user)) {
    $xpath = bibdk_searchhistory_webservice_responce_xpath($response['response']);
    return bibdk_searchhistory_parse_content($xpath);
  }
  return array();
}


/**
 * Helper function Check if user is provider user. And call provider service
 *
 * @param $service
 * @param null $content
 * @param null $user
 * @return bool
 */
function _bibdk_searchhistory_call_webservice($service, $content = NULL, $user = NULL) {
  if (!isset($user)) {
    global $user;
  }
  if (!ding_user_is_provider_user($user)) {
    return FALSE;
  }
  try {
    $creds = ding_user_get_creds($user);
  }
  catch (Exception $e) {
    return FALSE;
  }
  // Service implemented in bibdk_provider.user.inc
  return ding_provider_invoke('user', $service, $creds['name'], $content);
}

/** Helper function: convert xml to xpath
 *
 * @param $xml
 * @return array|DomXPATH
 */
function bibdk_searchhistory_webservice_responce_xpath($xml) {
  $dom = new DomDocument();
  if (!@$dom->loadXML($xml)) {
    if (variable_get('bibdk_provider_enable_logging')) {
      watchdog('bibdk_cart', 'BIBDK searchHistory could not load response: %xml', array('%xml' => var_export($xml, TRUE)), WATCHDOG_ERROR, $link = NULL);
    }
    return array();
  }
  $xpath = new DomXPATH($dom);
  $xpath->registerNamespace('oui', 'http://oss.dbc.dk/ns/openuserinfo');
  return $xpath;
}

/** Helper function: get element id from request from openuserinfo
 *
 * @param $xpath xpath object
 * @return array
 */
function bibdk_searchhistory_parse_id($xpath) {
  if (!isset($xpath)) {
    return array();
  }
  $return = array();
  $query = '//oui:searchHistoryId';
  $nodelist = $xpath->query($query);
  foreach ($nodelist as $delta => $node) {
    $return[] = $node->nodeValue;
  }
  return $return;
}

/**
 * get elements from request from openuserinfo
 *
 * @param $xpath xpath object
 * @return array
 */
function bibdk_searchhistory_parse_content($xpath) {
  if (empty($xpath)) {
    return array();
  }
  // grap elements
  $query = '//oui:searchHistory';
  $nodelist = $xpath->query($query);

  // check if empty
  if (empty($nodelist)) {
    return array();
  }

  $searchhistory = array();
  foreach ($nodelist as $delta => $node) {
    if (!empty($node->childNodes)) {
      $element = array();
      foreach ($node->childNodes as $child) {
        switch ($child->nodeName) {
          case 'oui:searchHistoryId' :
            $element['id'] = $child->nodeValue;
            break;
          case 'oui:searchHistoryTime' :
            $element['time'] = $child->nodeValue;
            break;
          case 'oui:searchHistoryString' :
            $element['string'] = $child->nodeValue;
            break;
          case 'oui:searchHistoryParams' :
            $element['params'] = isset($child->nodeValue) ? json_decode($child->nodeValue, TRUE) : array();
            break;
          case 'oui:searchHistoryCount' :
            $element['count'] = $child->nodeValue;
            break;
        }
      }
      if (isset($element['string'])) {
        $searchhistory[$element['string']] = $element;
      }
    }
  }
  return $searchhistory;
}
