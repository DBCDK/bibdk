<?php

/**
 * @file
 * Module file for bibdk_recommender_example.
 */

/**
 * @defgroup bibdk_recommender Example: Page
 */

/**
 * Constructs a recommender example page.
 */
function bibdk_recommender_example() {

  // see: https://www.drupal.org/project/slick
  
  $pids = array(
    '870970-basis:53887945',
    '870970-basis:04256042',
    '870970-basis:51701763',
    '870970-basis:12345678'
  );
  $numRecords = 10;
  
  $res = open_platform_client_recommender_request($pids, $numRecords);
  $foo = array();
  if (!empty($res)) {
    foreach ($res as $val) {
      $foo[] = $val->pid;
    }
  }
  
  // ajax example
  $id = drupal_clean_css_identifier("slick-recommender-" . md5(implode(',', $pids)));
  $markup = '<div class="js-slick-recommender"
    id="' . $id . '"
    data-uids="' . implode(',', $pids) . '"> </div>';
  $slick_example['bar']['#markup'] = '<p>.js-slick-recommender will be replaced by AJAX response.</p>' . htmlentities($markup) . '<hr>';
  $slick_example['foo']['#markup'] = $markup;
  $slick_example['bas']['#markup'] = 
    '<hr><div>Recommender result: </div>' .
    '<div>' . print_r(implode('; ', $foo), 1) . '</div><hr>';
  
  // markup example
  $slick_example['bof'] = bibdk_recommender_carousel_markup($foo);
  
  drupal_add_css(drupal_get_path('module', 'bibdk_recommender') . '/css/bibdk_recommender.css');
  drupal_add_js(drupal_get_path('module', 'bibdk_recommender') . '/js/bibdk_recommender.js');
  drupal_add_js(drupal_get_path('module', 'bibdk_recommender') . '/js/bibdk_recommender_covers.js');
  
  return $slick_example;
}



/**
 * @} End of "defgroup bibdk_recommender".
 */
