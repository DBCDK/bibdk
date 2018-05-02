<?php

/**
 * @file
 * Module file for bibdk_recommender_example.
 */

/**
 * @defgroup bibdk_recommender Example: Page
 */
 
/**
 * Implements hook_menu().
 *
 */
function bibdk_recommender_menu() {
  $items['examples/bibdk_recommender'] = array(
    'title' => 'Recommender Example',
    'page callback' => 'bibdk_recommender_callback',
    'access callback' => TRUE,
    'expanded' => TRUE,
  );
  return $items;
}

/**
 * Constructs a recommender example page.
 */
function bibdk_recommender_callback() {
dpm(variable_get('open_platform_access_token', NULL), 'open_platform_access_token');
  
  $pids = array('870970-basis:53887945', '870970-basis:04256042', '870970-basis:51701763', '870970-basis:12345678');
  $numRecords = 10;
  $res = open_platform_client_recommender_request($pids, $numRecords);
  $foo = '';
  foreach ($res as $val) {
    $foo .= $val->pid . '<br>';
  }
  return array('#markup' => '<p>' . $foo . '</p>');
}

/**
 * @} End of "defgroup bibdk_recommender".
 */
