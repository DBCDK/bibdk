<?php

/**
 * @file
 * Hooks provided by the bibdk_gdpr module.
 */

/**
 * Implements hook_bibdk_gdpr_items().
 *
 * @return array
 */
function bibdk_searchhistory_bibdk_gdpr_items() {
  $items['bibdk_searchhistory']['#weight'] = 45;
  $items['bibdk_searchhistory']['#header'] = t('label_gdpr_search_history', array(), array('context' => 'bibdk_gdpr'));
  $items['bibdk_searchhistory']['#theme'] = 'bibdk_gdpr_item_theme';
  if ($rows = bibdk_searchhistory_gdpr_get_rows()) {
    $items['bibdk_searchhistory']['#content'] = $rows;
  }
  else {
    $items['bibdk_searchhistory']['#content'] = array(
      '#type' => 'container',
      'text' => array(
        '#markup' => t('label_no_search_history', array(), array('context' => 'bibdk_gdpr'))
      ),
    );
  }
  return $items;
}

/**
 * Collect render array for gdpr.
 * 
 * @return array
 */
function bibdk_searchhistory_gdpr_get_rows() {
  global $user;
  $ret = array();

  $session_history = array();
  if (ding_user_is_provider_user($user)) {
    $session_history = BibdkSearchHistory::getAllElements();
  }
  
  if (sizeof($session_history) == 0) {
    return false;
  }
  
  $counter = 1;
  foreach ($session_history as $searchstring => $search) {
    $string = _bibdk_searchhistory_get_markup_for_gdpr($search);
    $ret[] = array(
      '#type' => 'container',
      'label' => array(
        '#type' => 'html_tag',
        '#tag' => 'span',
        '#value' => $counter
      ),
      'value' => array(
        '#type' => 'html_tag',
        '#tag' => 'span',
        '#value' => $string
      ),
    );
    $counter++;
  }
  return $ret;
}

/**
 * @param array $element
 * @return string
 */
function _bibdk_searchhistory_get_markup_for_gdpr($element) {
  $params_markup = (!empty($element['params'])) ? bibdk_searchhistory_parse_params($element['params']) : array();
  if (!empty($params_markup)) {
    return $params_markup;
  }
  return _bibdk_searchhistory_get_search_string($element);
}







