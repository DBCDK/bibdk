<?php

/**
 * Callback function used when input is entered in a search field.
 *
 * @param      $p_uuid
 * @param      $v_uuid
 * @param      $string
 * @see: https://github.com/DBCDK/ortograf
 */
function bibdk_autocomplete($p_uuid, $v_uuid, $string = '') {
  
  if (strlen($string) < 3) {
    drupal_json_output(array());
    drupal_exit();
  }

  $matches = array();
  $query['q'] = strtolower($string);

  $settings = variable_get('bibdk_autocomplete_settings', array());
  $query = array_merge($query, $settings);

  $vars = variable_get('bibdk_autocomplete_var', array());
  $value_vars = $vars[$p_uuid]['vars'][$v_uuid];
  unset($value_vars['autocomplete']);
  $query['type'] = $value_vars['type'];

  // Try to use cache for the query.
  $cid = md5(serialize($query));
  if ($cache = cache_get($cid, 'cache_bibdk_autocomplete_ortograf')) {
    $matches = $cache->data;
  }
  else {
    $suggestions = bibdk_autocomplete_get_suggestions($query);
    // Maximum space in suggestions dropdown is 64 characters.
    // Maximum characters for search query string is 256 characters.
    foreach ($suggestions as $suggestion) {
      $val = truncate_utf8($suggestion, 64, TRUE, TRUE, 1);
      
      $key = truncate_utf8($suggestion, 256, TRUE, FALSE, 1);
      if (strpos(trim($suggestion), ' ')) {
        $key = '"' . $key . '"';
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

/**
 * SuggestionService - retrieve suggestions with drupal_http_request() 
 *
 * @param array $query
 *   Search suggestion parameters.
 *
 * @return array
 *   Search suggestion results.
 */
function bibdk_autocomplete_get_suggestions(array $query) {
  $items = array();
  
  $rest_url = variable_get('bibdk_autocomplete_rest_url', '');
  $url = url($rest_url, array('query' => $query));
  $headers = array('Accept' => 'application/json');

  watchdog('bibdk_autocomplete', 'Autocomplete URL sent: ' . $url, array(), $severity = WATCHDOG_DEBUG);
  $result = drupal_http_request($url, $headers);

  if (!empty($result->error)) {
    watchdog(
      'ting_search_ortograf',
      "Autocomplete error: %error (%code)\nURL: !url",
      array(
        '%error' => $result->error,
        '%code' => $result->code,
        '!url' => $url,
      ),
      $severity = WATCHDOG_ERROR
    );
    return $items;
  }

  if (!empty($result->data)) {
    $result_data = drupal_json_decode($result->data);
    if (!empty($result_data['response']['docs'])) {
      foreach ($result_data['response']['docs'] as $suggestion) {
        $items[] = $suggestion['all'][0];
      }
    }
  }

  return $items;
}