<?php
/**
 * @file
 * Handles search carousel pages data.
 */

/**
 * AJAX callback to retrieve carousel items.
 *
 * @param $index
 *   Array index storing specific data.
 */
function bibdk_search_carousel_result() {

/*
  $content = FALSE;

  // Set default return values.
  $collections = _bibdk_search_carousel_get_content($index);
  $subtitle = '';

  // Get configureation.
  $bibdk_seach_queries = variable_get('bibdk_carousel_search_queries', array());
  if (isset($bibdk_seach_queries[$index])) {
    $subtitle = $bibdk_seach_queries[$index]['subtitle'];

    // If cache have been found theme search carousel pages.
    if (!empty($collections)) {
      foreach ($collections as $collection) {
        $content .= theme('bibdk_search_carousel_collection', array('collection' => $collection));
      }
    }
  }

  // Return JSON output.
  drupal_json_output(array('subtitle' => $subtitle, 'content' => $content, 'index' => $index));
*/

  $path = drupal_get_path('module', 'bibdk_search_carousel');

  $var[] = array(
    "img" => 'http://owlgraphic.com/owlcarousel/demos/assets/owl1.jpg',
    "alt" => "Owl Image 1",
  );
  $var[] = array(
    "img" => "http://owlgraphic.com/owlcarousel/demos/assets/owl2.jpg",
    "alt" => "Owl Image 2",
  );
  $var[] = array(
    "img" => "http://owlgraphic.com/owlcarousel/demos/assets/owl3.jpg",
    "alt" => "Owl Image 3",
  );
  $var[] = array(
    "img" => "http://owlgraphic.com/owlcarousel/demos/assets/owl4.jpg",
    "alt" => "Owl Image 4",
  );
  $var[] = array(
    "img" => "http://owlgraphic.com/owlcarousel/demos/assets/owl5.jpg",
    "alt" => "Owl Image 5",
  );
  $var[] = array(
    "img" => "http://owlgraphic.com/owlcarousel/demos/assets/owl6.jpg",
    "alt" => "Owl Image 6",
  );
  $var[] = array(
    "img" => "http://owlgraphic.com/owlcarousel/demos/assets/owl7.jpg",
    "alt" => "Owl Image 7",
  );
  $var[] = array(
    "img" => "http://owlgraphic.com/owlcarousel/demos/assets/owl8.jpg",
    "alt" => "Owl Image 8",
  );
  $var[] = array(
    "img" => "http://owlgraphic.com/owlcarousel/demos/assets/owl9.jpg",
    "alt" => "Owl Image 9",
  );

  // Return JSON output.
  drupal_json_output(array('items' => $var));

  drupal_exit();
}
