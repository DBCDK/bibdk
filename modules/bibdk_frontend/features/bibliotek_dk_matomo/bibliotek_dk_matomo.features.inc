<?php

/**
 * @file
 * bibliotek_dk_matomo.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bibliotek_dk_matomo_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
