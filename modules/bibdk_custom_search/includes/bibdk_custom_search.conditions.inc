<?php

/**
 * Implements hook_ting_openformat_conditions
 *
 * @param $query
 * @return array
 */
function bibdk_custom_search_ting_openformat_conditions($query) {
  return bibdk_custom_search_get_submitted_searchcodes($_REQUEST);
}

/**
 * Process a block search form submission.
 * First it will be checked if the values in select_material_type and page_id
 * differ. If they do the dropdown value (select_material_type) will be used and
 * set for further process.
 * This happens if the user resized the browser window as the dropdown is only
 * visible on smaller devices.
 *
 * @param array $get_values
 * @return array
 */
function bibdk_custom_search_get_submitted_searchcodes($get_values) {
  if (empty($get_values['select_material_type'])) {
    $get_values['select_material_type'] = 'bibdk_frontpage';
  }
  if (empty($get_values['page_id'])) {
    $get_values['page_id'] = NULL;
  }
  if ($get_values['select_material_type'] != $get_values['page_id']) {
    $page = _bibdk_custom_search_get_page_db($get_values['select_material_type']);
    $get_values['page_id'] = $get_values['select_material_type'];
    $_GET['page_id'] = $get_values['select_material_type'];
    $get_values['delimiter'] = $page['delimiter'];
    $_GET['delimiter'] = $page['delimiter'];
  }
  $extended_fields = _bibdk_custom_search_get_field_searchcodes();
  $extended = _bibdk_custom_search_get_advanced_values($get_values, $extended_fields);
  $controls = module_invoke_all('ting_search_get_controls', $get_values);
  $query = $controls + $extended;
  return $query;
}

/**
 * process the get values from a search reguest
 *
 * @param $get_values
 * @param $extended_fields
 * @return array
 */
function _bibdk_custom_search_get_advanced_values($get_values, $extended_fields) {
  $extended = array();

  if (isset($get_values['search_block_form']) && !empty($get_values['search_block_form'])){
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
