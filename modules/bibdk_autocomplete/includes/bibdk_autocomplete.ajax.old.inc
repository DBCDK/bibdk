<?php

/**
 * Callback function used when input is entered in a search field.
 *
 * @param      $p_uuid
 * @param      $v_uuid
 * @param      $string
 * @param bool $retry -- the server tends to respond with a error 500 however
 *                       retrying once seems to fix it most of the times.
 */
function bibdk_autocomplete_callback_old($p_uuid, $v_uuid, $string, $retry = false) {
  $items = array();
  $settings = variable_get('bibdk_autocomplete_settings', array());
  $url = variable_get('bibdk_autocomplete_rest_url', null);
  $vars = variable_get('bibdk_autocomplete_var', array());
  $value_vars = $vars[$p_uuid]['vars'][$v_uuid];
  unset($value_vars['autocomplete']);
  if (empty($value_vars['index'])) {
    watchdog('bibdk_autocomplete', 'Autocomplete index not defined for value uuid ' . $v_uuid, array(), $severity = WATCHDOG_WARNING);
    drupal_json_output(array());
    drupal_exit();
  }

  $filter_array = bibdk_autocomplete_parse_filters($string);
  $search_string = key($filter_array);
  $filter_string = bibdk_autocomplete_set_filter_query($filter_array[$search_string]);
  if (!empty($filter_string)) {
    if (!empty($value_vars['filterQuery'])) {
      $value_vars['filterQuery'] .= ' AND ' . $filter_string;
    } else {
      $value_vars['filterQuery'] = $filter_string;
    }
  }

  $settings['highlight'] = ($settings['highlight']) ? 'true' : null;
  $options['query'] = array('query' => check_plain($search_string)) + $value_vars + $settings;
  $options['maxTime'] = 300;

  $url = ($value_vars['facetIndex']) ? $url . '/facetSpell' : $url . '/terms';
  $url = url($url, $options);

  watchdog('bibdk_autocomplete', 'Autocomplete URL sent: ' . $url, array(), $severity = WATCHDOG_DEBUG);

  $curl = new MicroCURL();
  $headers = array('Accept: application/json');
  $curl->set_option(CURLOPT_HTTPHEADER, $headers);
  $result = json_decode($curl->get(array($url)));
  $curl->close();

  if (!empty($result->suggestion)) {
    foreach ($result->suggestion as $suggestion) {
      if (strpos($suggestion->phrase, ' ')) {
        // contains blank
        $items['"' . bibdk_autocomplete_truncate(html_entity_decode(strip_tags($suggestion->phrase)), 64) . '"'] = $suggestion->phrase;
      } else {
        $items[bibdk_autocomplete_truncate(html_entity_decode(strip_tags($suggestion->phrase)), 64)] = $suggestion->phrase;
      }
    }
  } else {
    if (empty($result->suggestions) && !$retry) {
      watchdog('bibdk_autocomplete', 'AUTOCOMPLETE RETRY' . $url, array(), $severity = WATCHDOG_WARNING);
      bibdk_autocomplete_callback_old($p_uuid, $v_uuid, $string, true);
    } else {
      watchdog('bibdk_autocomplete', 'Autocomplete return empty set for ' . $url, array(), $severity = WATCHDOG_WARNING);
      $items = array();
    }
  }
  // Return the result to the form in json
  drupal_json_output($items);
  drupal_exit();
}

function bibdk_autocomplete_parse_filters($filter_string) {
  $search_filter = explode('::::', $filter_string);
  $search_string = $search_filter[0];
  $filter_array = array();
  for ($i = 1; $i < count($search_filter); $i++) {
    $filter = array();
    $elements = explode('$$', $search_filter[$i]);
    $filter['v_uuid'] = $elements[0];
    $filter['p_uuid'] = $elements[1];
    $filter['term'] = $elements[2];
    $filter_array[] = $filter;
  }
  return array($search_string => $filter_array);
}

function bibdk_autocomplete_set_filter_query(array $filters) {
  $filter_query = '';
  $vars = variable_get('bibdk_autocomplete_var', array());
  foreach ($filters as $filter) {
    $values = $vars[$filter['p_uuid']]['vars'][$filter['v_uuid']];
    if (!empty($filter_query)) {
      $filter_query .= ' AND ';
    }
    // trim qoutes if any
    $term = trim($filter['term'], '"');
    $filter_query .= $values['facetIndex'] . '=' . '"' . $term . '"';
  }
  return $filter_query;
}

/**
 * helper function for bibdk_autocomplete()
 */
function bibdk_autocomplete_truncate($string, $width) {
  $parts = preg_split('/([\s\n\r]+)/', $string, null, PREG_SPLIT_DELIM_CAPTURE);
  $parts_count = count($parts);

  $length = 0;
  $last_part = 0;
  for (; $last_part < $parts_count; ++$last_part) {
    $length += strlen($parts[$last_part]);
    if ($length > $width) {
      break;
    }
  }
  return implode(array_slice($parts, 0, $last_part));
}
