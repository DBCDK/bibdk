<?php

/**
 * Callback function used when input is entered in a search field.
 *
 * @param      $p_uuid
 * @param      $v_uuid
 * @param      $string
 * @see: https://github.com/DBCDK/ortograf
 */
function bibdk_autocomplete_callback_ortograf($p_uuid, $v_uuid, $string = '') {
  
  if (strlen($string) < 3) {
    drupal_json_output(array());
    drupal_exit();
  }

  $matches = array();
  $query['q'] = strtolower($string);

  $settings = variable_get('bibdk_autocomplete_ortograf_settings', array());
  $query = array_merge($query, $settings);

  $vars = variable_get('bibdk_autocomplete_ortograf_var', array());
  $value_vars = $vars[$p_uuid]['vars'][$v_uuid];
  unset($value_vars['autocomplete']);
  $query['type'] = $value_vars['type'];

  // Try to use cache for the query.
  $cid = md5(serialize($query));
  if ($cache = cache_get($cid, 'cache_bibdk_autocomplete_ortograf')) {
    $matches = $cache->data;
  }
  else {
    $suggestions = bibdk_autocomplete_get_suggestions_ortograf($query);
    // Maximum space in suggestions dropdown is 64 characters.
    // Maximum characters for search query string is 256 characters.
    foreach ($suggestions as $suggestion) {
      $val = truncate_utf8($suggestion, 64, TRUE, TRUE, 1);
      $key = truncate_utf8($suggestion, 256, TRUE, FALSE, 1);
      $key = trim($key, " \t\n\r\0\x0B?"); // trim whitespace and question mark.
      if (strpos($suggestion, ' ')) {
        $key = '"' . str_replace('"', '\"', $key) . '"';
      }
      $matches[$key] = $val;
    }

    // Store the matches in cache for faster lookup next time.
    if (sizeof($matches) > 0) {
      cache_set($cid, $matches, 'cache_bibdk_autocomplete_ortograf', CACHE_TEMPORARY);
    }
  }
  
  // Return the result to the form in json
  drupal_json_output($matches);
  drupal_exit();
}