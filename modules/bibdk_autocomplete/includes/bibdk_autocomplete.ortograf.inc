<?php 

/**
 * Implements hook_0_hit().
 * @return array
 *
 */
function bibdk_autocomplete_0_hit_ortograf($string) {
  $matches = array();
  $query['q'] = strtolower($string);

  $settings = variable_get('bibdk_autocomplete_ortograf_settings', array());
  $query = array_merge($query, $settings);

  $vars = variable_get('bibdk_autocomplete_ortograf_var', array());
  $query['type'] = 'all';

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
  
  $link_items = bibdk_make_item_list($matches);

  return $link_items;
}


/**
 * helper function for 0_hit_search()
 */
function bibdk_make_item_list($items) {

  $links = array();

  // make a list of suggesttions
  foreach ($items as $suggest) {
    $zero_hit_link = array(
      '#theme' => 'link',
      '#path' => 'search/work/' . '"' . $suggest . '"',
      '#weight' => 0,
      '#text' => $suggest,
      '#options' => array(
        'attributes' => array(
          'class' => array(
            'bibdk-suggest-link',
          ),
        ),
        'html' => false,
      ),
    );
    $links[] = drupal_render($zero_hit_link);
  }

  // label for suggestions
  $render['label'] = array(
    '#type' => 'html_tag',
    '#tag' => 'div',
    '#value' => t('label_did_you_mean', array(), array('context' => 'bibdk_autocomplete_suggest')),
    '#attributes' => array(
      'class' => array('bibdk-suggest-label'),
    ),
  );

  // render array for suggestions
  $render['suggest_list'] = array(
    '#theme' => 'item_list',
    '#type' => 'ul',
    '#attributes' => array(
      'class' => array('links'),
      'class' => array('bibdk-suggest-links'),
    ),
    '#items' => $links,
  );

  return $render;

}
