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
function bibdk_search_carousel_result($index) {

  // Get configureation.
  $bibdk_seach_queries = variable_get('bibdk_carousel_search_queries', array());
  $index = bibdk_search_carousel_index($index);
  if (isset($bibdk_seach_queries[$index])) {
    $subtitle = $bibdk_seach_queries[$index]['subtitle'];
    $cover_items = _bibdk_search_carousel_get_content($index, $bibdk_seach_queries);
  }

  $content = drupal_render($cover_items);

  // Return JSON output.
  drupal_json_output(array('cover_list' => $content));

  drupal_exit();
}
/**
 * Checks Sessionsetting for last index
 *
 * @return string
 */
function bibdk_search_carousel_index($index) {

  if (isset($_SESSION['carousel_settings']['show_carousel_number'])) {
    if ($index != 0 ) {
      $_SESSION['carousel_settings']['show_carousel_number'] = $index;
      $index = (int)$_SESSION['carousel_settings']['show_carousel_number'];
    }
  }

  if (isset($_SESSION['carousel_settings']['show_carousel_number'])) {
    $index = (int)$_SESSION['carousel_settings']['show_carousel_number'];
  } else {
    $_SESSION['carousel_settings']['show_carousel_number'] = $index;
  }

  return $index;
}

