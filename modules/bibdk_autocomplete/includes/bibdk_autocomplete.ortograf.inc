/**
 * Implements hook_0_hit().
 * @return array
 *
 */
function bibdk_autocomplete_0_hit_ortograf($string) {
  $settings = variable_get('bibdk_autocomplete_settings', array());
  $url = variable_get('bibdk_autocomplete_rest_url', null);

  $options['query'] = array('q' => check_plain($string)) + $settings;
  $options['query']['type'] = 'all';
  $url = url($url, $options);

  watchdog('bibdk_autocomplete', 'Autocomplete URL sent: ' . $url, array(), $severity = WATCHDOG_DEBUG);

  $curl = new MicroCURL();
  $headers = array('Accept: application/json');
  $curl->set_option(CURLOPT_HTTPHEADER, $headers);
  $result = json_decode($curl->get(array($url)));
  $curl->close();

  $items = array();
  if (!empty($result->response)) {
    foreach ($result->response->docs as $suggestion) {
      $items[] = $suggestion->all[0];
    }
  } else if (!empty($result->error)) {
    watchdog('bibdk_autocomplete', 'Autocomplete return empty set for ' . $url, array(), $severity = WATCHDOG_WARNING);
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
