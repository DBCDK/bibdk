<?php
/**
 * @file
 * bibdk_ie6nomore_settings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bibdk_ie6nomore_settings_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
