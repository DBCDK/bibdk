<?php
/**
 * @file
 * Includes all methods for Features and export functionality
 */

/**
 * Implements hook_features_api
 * @return array
 */
function bibdk_custom_search_features_api() {
  return array(
    'bibdk_custom_search' => array(
      'name' => 'bibdk_custom_search',
      'default_hook' => 'default_bibdk_custom_search_page',
      'feature_source' => TRUE,
    ),
  'bibdk_custom_search_values' => array(
      'name' => 'bibdk_custom_search_values',
      'default_hook' => 'default_bibdk_custom_search_value',
      'feature_source' => TRUE,
    ),
  'bibdk_custom_search_elements' => array(
      'name' => 'bibdk_custom_search_elements',
      'default_hook' => 'default_bibdk_custom_search_element',
      'feature_source' => TRUE,
    ),
  'bibdk_custom_search_options' => array(
      'name' => 'bibdk_custom_search_options',
      'default_hook' => 'default_bibdk_custom_search_option',
      'feature_source' => TRUE,
    ),
  'bibdk_custom_search_map_values' => array(
      'name' => 'bibdk_custom_search_map_values',
      'default_hook' => 'default_bibdk_custom_search_map_value',
      'feature_source' => TRUE,
    ),
  'bibdk_custom_search_map_elements' => array(
      'name' => 'bibdk_custom_search_map_elements',
      'default_hook' => 'default_bibdk_custom_search_map_element',
      'feature_source' => TRUE,
    ),
  );
}

/**
 * Implements hook_features_enable_feature().
 *
 * @param $module Name of module that has been enabled.
 */
function bibdk_custom_search_features_enable_feature($module) {
  bibdk_custom_search_features_revert($module);
}
function bibdk_custom_search_elements_features_enable_feature($module) {
  bibdk_custom_search_elements_features_revert($module);
}
function bibdk_custom_search_map_elements_features_enable_feature($module) {
  bibdk_custom_search_map_elements_features_revert($module);
}
function bibdk_custom_search_map_values_features_enable_feature($module) {
  bibdk_custom_search_map_values_features_revert($module);
}
function bibdk_custom_search_options_features_enable_feature($module) {
  bibdk_custom_search_options_features_revert($module);
}
function bibdk_custom_search_values_features_enable_feature($module) {
  bibdk_custom_search_values_features_revert($module);
}

/**
 * Implements hook_features_revert().
 *
 * @param $module
 *   Name of module that has been enabled.
 */
function bibdk_custom_search_features_revert($module) {
  _bibdk_custom_search_revert_helper('bibdk_custom_search', 'p_uuid', $module);
}
function bibdk_custom_search_elements_features_revert($module) {
  _bibdk_custom_search_revert_helper('bibdk_custom_search_elements', 'e_uuid', $module);
}
function bibdk_custom_search_map_elements_features_revert($module) {
  _bibdk_custom_search_revert_helper('bibdk_custom_search_map_elements', 'me_uuid', $module);
}
function bibdk_custom_search_map_values_features_revert($module) {
  _bibdk_custom_search_revert_helper('bibdk_custom_search_map_values', 'mv_uuid', $module);
}
function bibdk_custom_search_options_features_revert($module) {
  _bibdk_custom_search_revert_helper('bibdk_custom_search_options', 'o_uuid', $module);
}
function bibdk_custom_search_values_features_revert($module) {
  _bibdk_custom_search_revert_helper('bibdk_custom_search_values', 'v_uuid', $module);
}

/**
 * Helper function hook_features_revert()
 *
 * @param $table string
 * @param $uuid string
 * @param $module string
 */
function _bibdk_custom_search_revert_helper($table, $uuid, $module) {
  $defaults = features_get_default($table, $module);
  //print_r($defaults);
  foreach ($defaults as $object) {
    db_delete($table)->condition($uuid, $object->$uuid, '=')->execute();
    drupal_write_record($table, $object);
  }
}

/**
 * Helper function that adds missing UUID's to table
 * @param $table
 * @param $id_field
 * @param $uuid_field
 */
function bibdk_custom_search_uuid_sync_table($table, $id_field, $uuid_field) {
  // Fetch empty records.
  $result = db_select($table, 't')
    ->fields('t', array($id_field))
    ->condition(db_or()->condition($uuid_field, '')->isNull($uuid_field))
    ->execute();
  // Update empty records.
  foreach ($result as $record) {
    db_update($table)
      ->fields(array($uuid_field => uuid_generate()))
      ->condition($id_field, $record->{$id_field})
      ->execute();
  }
}

/**
 * Callback to prov_uuide a list of exportable objects to be chosen for ctools export.
 *
 * In order to simplify the export process only one element is created which exports all elements
 */
function bibdk_custom_search_bibdk_custom_search_list() {
  return array(
    'all_elements' => t('Export all values'),
  );
}
function bibdk_custom_search_bibdk_custom_search_elements_list() {
  return bibdk_custom_search_bibdk_custom_search_list();
}

function bibdk_custom_search_bibdk_custom_search_options_list() {
  return bibdk_custom_search_bibdk_custom_search_list();
}
function bibdk_custom_search_bibdk_custom_search_values_list() {
  return bibdk_custom_search_bibdk_custom_search_list();
}
function bibdk_custom_search_bibdk_custom_search_map_values_list() {
  return bibdk_custom_search_bibdk_custom_search_list();
}
function bibdk_custom_search_bibdk_custom_search_map_elements_list() {
  return bibdk_custom_search_bibdk_custom_search_list();
}

/**
 * Implements hook_features_export
 * @param $data
 * @param $export
 * @param string $module_name
 * @return array
 */
function bibdk_custom_search_features_export($data, &$export, $module_name = '') {
  return bibdk_custom_search_features_export_helper($data, $export, 'bibdk_custom_search', 'p_uuid');
}
function bibdk_custom_search_values_features_export($data, &$export, $module_name = '') {
  return bibdk_custom_search_features_export_helper($data, $export, 'bibdk_custom_search_values', 'v_uuid');
}
function bibdk_custom_search_elements_features_export($data, &$export, $module_name = '') {
  return bibdk_custom_search_features_export_helper($data, $export, 'bibdk_custom_search_elements', 'e_uuid');
}
function bibdk_custom_search_options_features_export($data, &$export, $module_name = '') {
  return bibdk_custom_search_features_export_helper($data, $export, 'bibdk_custom_search_options', 'o_uuid');
}
function bibdk_custom_search_map_elements_features_export($data, &$export, $module_name = '') {
  return bibdk_custom_search_features_export_helper($data, $export, 'bibdk_custom_search_map_elements', 'me_uuid');
}
function bibdk_custom_search_map_values_features_export($data, &$export, $module_name = '') {
  return bibdk_custom_search_features_export_helper($data, $export, 'bibdk_custom_search_map_values', 'mv_uuid');
}

/**
 * Helper function for hook_features_export
 * @param $data
 * @param $export
 * @param $table
 * @param $uuid
 * @return array
 */
function bibdk_custom_search_features_export_helper($data, &$export, $table, $uuid) {
  $export['dependencies']['features'] = 'features';
  $export['dependencies']['ctools'] = 'ctools';
  $export['dependencies']['bibdk_custom_search'] = 'bibdk_custom_search';
  if (in_array('all_elements', $data)) {
   $data = bibdk_custom_search_list_helper($uuid, $table);
   unset($data['all_elements']);
    foreach ($data as $component) {
      $export['features'][$table][$component] = $component;
    }
  }
  else {
    foreach ($data as $component) {
      $export['features'][$table][$component] = $component;
    }
  }
  return array();
}


/**
 * Helper function for list callback
 * @param $uuid
 * @param $table
 * @return array
 */
function bibdk_custom_search_list_helper($uuid, $table) {
  $list = array('all_elements' => 'All elements');
  $query = db_select($table, 't');
  $query -> fields('t', array($uuid));
  $result = $query -> execute();

  foreach ($result as $record) {
    $list[ $record->$uuid] = $record->$uuid;
  }

  return $list;
}