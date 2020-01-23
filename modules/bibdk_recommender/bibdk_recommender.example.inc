<?php

/**
 * @file
 * Module file for bibdk_recommender_example.
 * Used for testing and demo.
 */

/**
 * @defgroup bibdk_recommender Example: Page
 */

/**
 * Constructs a recommender example page.
 */
function bibdk_recommender_example() {

  $pids = array(
    '870970-basis:04256042',
    '870970-basis:51701763',
    '870970-basis:51625447'
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
  $slick_example['baf']['#markup'] = '<hr><h2>AJAX example:</h2>';
  $id = drupal_clean_css_identifier("slick-recommender-" . md5(implode(',', $pids)));
  $markup = '<div class="js-slick-recommender"
    id="' . $id . '"
    data-pids="' . implode(',', $pids) . '"></div>';
  
  $slick_example['foo']['#markup'] = '<p>.js-slick-recommender will be replaced by AJAX response.</p><code>' . htmlentities($markup) . '</code><hr>';
  $slick_example['bar']['#markup'] = $markup;
  
  $slick_example['bas']['#markup'] = 
    '<hr><div>Recommender result: </div>' .
    '<div>' . print_r(implode('; ', $foo), 1) . '</div>';
  
  // markup example
  $slick_example['hop']['#markup'] = '<hr><h2>Markup example:</h2>';
  $slick_example['bof'] = bibdk_recommender_carousel_markup($foo);
  
  drupal_add_css(drupal_get_path('module', 'bibdk_recommender') . '/css/bibdk_recommender.css');
  drupal_add_js(drupal_get_path('module', 'bibdk_recommender') . '/js/bibdk_recommender.js');
  drupal_add_js(drupal_get_path('module', 'bibdk_recommender') . '/js/bibdk_recommender_covers.js');
  
  return $slick_example;
}



/**
 * @} End of "defgroup bibdk_recommender".
 */
