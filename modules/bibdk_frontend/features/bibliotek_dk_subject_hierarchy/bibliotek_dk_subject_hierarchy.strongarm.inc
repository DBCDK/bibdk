<?php

/**
 * @file
 * bibliotek_dk_subject_hierarchy.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bibliotek_dk_subject_hierarchy_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bibdk_subject_hierarchy_email_from';
  $strongarm->value = 'noreply@bibliotek.dk';
  $export['bibdk_subject_hierarchy_email_from'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bibdk_subject_hierarchy_email_to';
  $strongarm->value = 'lho@dbc.dk';
  $export['bibdk_subject_hierarchy_email_to'] = $strongarm;

  return $export;
}
