<?php
/**
 * @file
 * bibdk_voxb_blog_fields.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bibdk_voxb_blog_fields_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_blog';
  $strongarm->value = 0;
  $export['node_submitted_blog'] = $strongarm;

  return $export;
}
