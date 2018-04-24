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
  $pids = array('870970-basis:53887945');
  $numRecords = 10;
  $res = open_platform_recommender_request($pids, $numRecords);
  $foo = print_r($res, 1);
  return array('#markup' => '<p>' . $foo . '</p>');
}

/**
 * @} End of "defgroup bibdk_recommender".
 */
