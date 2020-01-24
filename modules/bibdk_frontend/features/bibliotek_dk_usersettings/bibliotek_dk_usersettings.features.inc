<?php
/**
 * @file
 * bibliotek_dk_usersettings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bibliotek_dk_usersettings_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
