<?php   
/**
 * @file
 * bibdk_ie6nomore_settings.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bibdk_ie6nomore_settings_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ie6nomore_dismissable';
  $strongarm->value = 1;
  $export['ie6nomore_dismissable'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ie6nomore_ie';
  $strongarm->value = 'lt IE 9';
  $export['ie6nomore_ie'] = $strongarm;

  return $export;
}
