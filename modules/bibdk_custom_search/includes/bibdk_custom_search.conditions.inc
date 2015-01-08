<?php

/** Implements hook_ting_openformat_conditions
 * @param $query
 */
function bibdk_custom_search_ting_openformat_conditions($query) {
  return bibdk_custom_search_get_submitted_searchcodes($_REQUEST);
}

/**
 * Process a block search form submission.
 **/
function bibdk_custom_search_get_submitted_searchcodes($get_values) {
  $extended_fields = _bibdk_custom_search_get_field_searchcodes();
  $extended = _bibdk_custom_search_get_advanced_values($get_values, $extended_fields);
  $controls = module_invoke_all('ting_search_get_controls', $get_values);
  $query = $controls + $extended;
  return $query;
}

/** process the get values from a search reguest
 * @param $get_values
 * @param $extended_fields
 * @return array
 */
function _bibdk_custom_search_get_advanced_values($get_values, $extended_fields) {
  $extended = array();

  if (isset($get_values['search_block_form'])){
    $extended['qe']['query'] = $get_values['search_block_form'];
  }
  foreach ($get_values as $_key => $values) {
    $key = str_replace('_', '.', $_key);
    $no_searchcode = preg_match('@n/a@', $key);
    if (!isset($extended_fields[$key]['search_code']) && !$no_searchcode) {
      continue;
    }
    if (!is_array($values)) {
      $values = array($values);
    }
    foreach ($values as $value) {

      if ($value) {
        if ($no_searchcode) {
          $extended['qe']['n/a'][$key][] = $value;
        }
        else {
          $extended['qe'][$key][] = $value;
        }
      }
    }
  }

  if (isset($get_values['delimiter']) && $delimiter = $get_values['delimiter']) {
    $extended['qe']['delimiter'] = $delimiter;
  }

  if (isset($get_values['page_id'])) {
    $extended['page_id'] = $get_values['page_id'];
  }

  return $extended;
}
