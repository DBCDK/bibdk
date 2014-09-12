<?php
/**
* @file
* Configure search for userhelp content.
*/

/**
 * Return a help text search form.
 */
function bibdk_help_search_form($form, &$form_state) {

  $form['userhelp'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('Search help texts.'),
    '#tree'         => FALSE,
  );

  $form['userhelp']['search_help'] = array(
    '#type' => 'textfield',
    '#title' => t('Search help:'),
    '#title_display'  => 'invisible',
    '#size' => 5,
    '#default_value' => !empty($form_state['values']['search_help']) ? $form_state['values']['search_help'] : '',
  );

  $form['userhelp']['actions']['#type'] = 'actions';
  $form['userhelp']['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
  );

  if ( $search_help = $form['userhelp']['search_help']['#default_value'] ) {
    $query_result = bibdk_help_search_form_search($form_state['values']['search_help']);
    $form['query_result'] = array(
      '#type' => 'container',
      '#attributes' => array(
        'id' => array('query-result'),
      ),
    );
    $form['query_result']['list_result'] = array(
      '#markup' => drupal_render($query_result),
    );
  }

  return $form;
}


/**
 * Submit handler for bibdk_help_search_form();
 */
function bibdk_help_search_form_submit(&$form, &$form_state) {
  $form_state['rebuild'] = TRUE;
}


/**
 * Validation handler for bibdk_help_search_form();
 */
function bibdk_help_search_form_validate($form, &$form_state) {
  if ( !$form_state['values']['search_help'] ) {
    form_set_error('search_help', t('Enter a search term.', array(), array('context' => 'bibdk_help:error')));
  }
}


function bibdk_help_search_form_search($query) {
  $query_res = bibdk_help_search_execute($query);
  return $query_res;
}


/**
 * Implements hook_menu_alter().
 */
function bibdk_help_menu_alter(&$items) {
  // remove user_help search from search tab.
  unset($items['search/user_help']);
  unset($items['search/user_help/%menu_tail']);
}


/**
 * Implements hook_search_execute().
 */
function bibdk_help_search_execute($keys = NULL, $conditions = NULL) {

  // Build matching conditions
  $query = db_select('search_index', 'i', array('target' => 'slave'))
    ->extend('SearchQuery')
    ->extend('PagerDefault');
  $query->join('node', 'n', 'n.nid = i.sid');

  $db_or = db_or();
  $db_or->condition('n.type', 'userhelp');
  $db_or->condition('n.type', 'bibdk_newsroom');

  $query
    ->condition($db_or)
    ->condition('n.status', 1)
    ->searchExpression($keys, 'node');

  // Insert special keywords.
  $query->setOption('type', 'n.type');
  $query->setOption('language', 'n.language');
  if ($query->setOption('term', 'ti.tid')) {
    $query->join('taxonomy_index', 'ti', 'n.nid = ti.nid');
  }

  // Only continue if the first pass query matches.
  if (!$query->executeFirstPass()) {
    drupal_set_message(t('Search returned no results.', array(), array('context' => 'bibdk_help')), 'status');
    return array();
  }

  // Add the ranking expressions.
  _node_rankings($query);

  // Load results.
  $find = $query
    ->limit(10)
    ->execute();

  $results = array();
  foreach ($find as $item) {
    // Render the node.
    $node = node_load($item->sid);
    $build = node_view($node, 'search_result');
    // $build = node_view($node, 'bibdk_help_list');
    unset($build['#theme']);
    $node->rendered = drupal_render($build);

    // Fetch comments for snippet.
    $node->rendered .= ' ' . module_invoke('comment', 'node_update_index', $node);

    $extra = module_invoke_all('node_search_result', $node);

    $uri = entity_uri('node', $node);
    $results[] = array(
      'link' => str_replace('/node/', '/overlay/help/', url($uri['path']), array_merge($uri['options'], array('absolute' => TRUE))),
      'type' => check_plain(node_type_get_name($node)),
      'title' => $node->title,
      // 'user' => theme('username', array('account' => $node)),
      // 'date' => $node->changed,
      'node' => $node,
      'extra' => $extra,
      'theme' => 'search_item',
      'score' => $item->calculated_score,
      'snippet' => search_excerpt($keys, $node->rendered),
    );
  }

  if ( !$results ) {
    drupal_set_message(t('Search returned no results.', array(), array('context' => 'bibdk_help')), 'status');
  }

  return array(
    '#theme' => 'search_results',
    '#results' => $results,
    '#module' => 'bibdk_help',
  );

}


function bibdk_help_search_info() {
  return array(
    'title' => 'User help',
    'path' => 'user_help',
    // 'conditions_callback' => 'sample_search_conditions_callback',
  );
}


function bibdk_help_update_index() {

  $limit = (int) variable_get('search_cron_limit', 100);

  $result = db_query_range("
      SELECT n.nid FROM {node} n
      LEFT JOIN {search_dataset} d
      ON d.type = 'node'
      AND d.sid = n.nid
      WHERE ( d.sid IS NULL OR d.reindex <> 0 ) AND n.type = 'userhelp'
      ORDER BY d.reindex ASC, n.nid ASC",
      0, $limit
  );

  foreach ($result as $node) {
    $node = node_load($node->nid);

    // Save the changed time of the most recent indexed node, for the search results half-life calculation.
    variable_set('node_cron_last', $node->changed);

    // Render the node.
    node_build_content($node, 'search_index');
    $node->rendered = drupal_render($node->content);

    $text = '<h1>' . check_plain($node->title) . '</h1>' . $node->rendered;

    // Update index
    search_index($node->nid, 'node', $text);
  }

}

