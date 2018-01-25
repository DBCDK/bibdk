<?php

/**
 * Implements hook_0_hit().
 * @return array
 *
 */
function bibdk_autocomplete_0_hit_old($conditions) {
  $settings = variable_get('bibdk_autocomplete_settings', array());
  $url = variable_get('bibdk_autocomplete_rest_url', null);

  $value_vars = array();
  $value_vars['index'] = 'scanterm.default';
  $value_vars['facetIndex'] = 'scanphrase.default';
  $value_vars['agency'] = $settings['agency'];
  $value_vars['profile'] = $settings['profile'];
  $url = $url . '/facetSpell';
  $settings['highlight'] = ($settings['highlight']) ? 'true' : null;
  $options['query'] = array('query' => check_plain($conditions)) + $value_vars + $settings;
  $options['maxTime'] = 300;
  $url = url($url, $options);
  $curl = new MicroCURL();
  $headers = array('Accept: application/json');
  $curl->set_option(CURLOPT_HTTPHEADER, $headers);
  $result = json_decode($curl->get(array($url)));
  $curl->close();

  $items = array();
  if (!empty($result->suggestion)) {
    foreach ($result->suggestion as $suggestion) {
      $val = truncate_utf8($suggestion->phrase, 124, TRUE, TRUE, 1);
      $key = truncate_utf8($suggestion->phrase, 256, TRUE, FALSE, 1);
      $key = trim($key, " \t\n\r\0\x0B?"); // trim whitespace and question mark.
      if (strpos($suggestion->phrase, ' ')) {
        $key = '"' . str_replace('"', '\"', $key) . '"';
      }
      $items[$key] = $val;
    }
  }

  $link_items = bibdk_make_item_list($items);

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