<?php

/**
 * AJAX callback
 * Return the URL for the cover of an object
 */
function bibdk_covers_objects() {

  $covers = array();
  $cover_path = $thumbnail_path = $backcover_path = '';

  if ( empty($_POST['coverData']) ) {
    watchdog('bibdk_covers', 'Empty coverData variable in $_POST', array(), WATCHDOG_ERROR);
    drupal_json_output($covers);
    drupal_exit();
  }

  foreach ($_POST['coverData'] as $cover_info) { // ex. [0] => 29316627:medium

    // Reverse cover_info before and after explode to make sure that we explode around
    // the last :. Local ids could contain the delimiter!
    list($local_id, $image_style) = array_reverse(array_map('strrev', explode(':', strrev($cover_info), 2)));

    // Determine if the local id is a known negative
    if ( cache_get('bibdk_covers:' . $local_id, FALSE) ) {
      break;
    }

    if ( $cover_path = open_moreinfo_object_path($local_id, 'detailUrl') ) {

      if ( !file_exists($cover_path) )  {
        drupal_json_output(FALSE);
        drupal_exit();
      }

      $covers[ $local_id . ':' . 'detailUrl' ] = image_style_url('large', _bibdk_covers_object_path($local_id, 'detailUrl'));

      if ( $thumbnail_path = open_moreinfo_object_path($local_id, 'thumbnailUrl') ) {
        $covers[ $local_id . ':' . 'thumbnailUrl' ] = image_style_url('medium', _bibdk_covers_object_path($local_id, 'detailUrl'));
      }

      $backcover_path = open_moreinfo_object_path($local_id, 'backpagePdfUrl');
      if ($backcover_path && file_exists($backcover_path)) {
        if ($wrapper = file_stream_wrapper_get_instance_by_uri($backcover_path)) {
          $backcover_path = $wrapper->getExternalUrl();
        }
        $covers[ $local_id . ':' . 'backpagePdfUrl' ] = $backcover_path;
      } else {
        $covers[ $local_id . ':' . 'backpagePdfUrl' ] = '';
      }

    } else {
      // No cover image. Cache this for future reference to avoid unnecessary requests
      cache_set('bibdk_covers:'.$local_id['id'], 1, 'cache', $_SERVER['REQUEST_TIME'] + variable_get('open_moreinfo_cache_lifetime', 604800));
    }

  }

  // Return all image information
  // ex.   [28917074:detailUrl] => http://jgn.ding.dbc.dk/sites/default/files/styles/large/public/moreinfo/detailUrl/30acd29373256668c1665824b7d6783f.jpg
  // ex.   [28917074:thumbnailUrl] => http://jgn.ding.dbc.dk/sites/default/files/styles/medium/public/moreinfo/detailUrl/30acd29373256668c1665824b7d6783f.jpg
  // ex.   [28917074:backpagePdfUrl] => http://jgn.ding.dbc.dk/sites/default/files/moreinfo/backpagePdfUrl/30acd29373256668c1665824b7d6783f.pdf

  drupal_json_output($covers);

  drupal_exit();
}
