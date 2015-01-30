<?php
/**
 * @file
 * bibdk_banner.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bibdk_banner_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function bibdk_banner_node_info() {
  $items = array(
    'bibdk_banner' => array(
      'name' => t('Banner'),
      'base' => 'node_content',
      'description' => t('Add a banner advertisment to the banner region.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  return $items;
}
