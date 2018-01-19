<?php
/**
 * @file
 * bibdk_autocomplete_ortograf.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bibdk_autocomplete_ortograf_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
