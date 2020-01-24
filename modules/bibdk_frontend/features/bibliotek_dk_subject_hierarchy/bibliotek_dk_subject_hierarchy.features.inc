<?php

/**
 * @file
 * bibliotek_dk_subject_hierarchy.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bibliotek_dk_subject_hierarchy_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
