<?php
/**
 * @file
 * Admin related backend.
 */

/**
 * Search queries admin form.
 *
 * @param $form
 *   Form.
 * @param $form_state
 *   Form state.
 *
 * @return
 *   Form structure.
 */
function bibdk_search_carousel_admin_form($form, &$form_state) {

  drupal_add_js(drupal_get_path('module', 'bibdk_search_carousel') . '/js/bibdk_search_carousel.admin.js');
  drupal_add_css(drupal_get_path('module', 'bibdk_search_carousel') . '/css/bibdk_search_carousel.css');

  variable_set('bibdk_carousel_search_queries_hidden', array());

  $searches_num = !empty($form_state['values']['num_searches']) ? $form_state['values']['num_searches'] : 0;
  $clicked_btn = '';
  $query = array();
  $hidden = array();

  if ( isset($form_state['clicked_button']) ) {

    // clicked button: redirect to search result, or delete search.
    $id = explode('_', $form_state['clicked_button']['#name']);
    switch ( $id[0] ) {
      case 'test':
        $id = $id[1];
        $queries = variable_get('bibdk_carousel_search_queries', array());
        $query = module_invoke_all('bibdk_search_carousel_query', $queries[$id]);
        $search_info = search_get_default_module_info();
        if ( !empty($search_info['path']) && in_array($search_info['module'], variable_get('search_active_modules', array())) ) {
          $form_state['redirect'] = FALSE;
          $url = 'search/' . $search_info['path'] . '/' . trim($query['query']);
          drupal_goto($url);
        }
        break;
      case 'remove':
        $hidden[] = $id[1];
        variable_set('bibdk_carousel_search_queries_hidden', $hidden);
        break;
    }

    // Whether add a new query field.
    if ( $form_state['clicked_button']['#name'] == 'add_query') {
      $searches_num++;
    }

  }

  $form['bibdk_search_carousel'] = array(
    '#type' => 'fieldset',
    '#title' => 'Searches',
  );

  // Get current saved queries.
  $searches = variable_get('bibdk_carousel_search_queries', array());

  $i = 0;
  $c = 1;

  // Display saved queries.
  if ( !empty($searches[0]['title']) ) {
    $c = count($searches);
    for (; $i < $c; $i++) {
      $form['bibdk_search_carousel']['bibdk_searches']['search_' . $i] = bibdk_search_carousel_query_form($searches[$i], $i);
    }
  }

  for (; $i < $searches_num + $c; $i++) {
    $unsubmitted = array();
    // Maybe prev field had some data in it...
    if ( isset( $form_state['input']['title'][$i]) ) {
      $unsubmitted = array(
        'title' => $form_state['input']['title'][$i],
        'subtitle' => $form_state['input']['subtitle'][$i],
        'query' => $form_state['input']['query'][$i],
      );
    }

    $form['bibdk_search_carousel']['bibdk_searches']['search_' . $i] = bibdk_search_carousel_query_form($unsubmitted, $i);
  }

  // Hide removed fields.
  for ($i = 0; $i < $searches_num + $c; $i++) {
    if ( in_array($i, $hidden) ) {
      // Hide title, used to sort needed queries when saving
      $form['bibdk_search_carousel']['bibdk_searches']['search_' . $i]['fields']['title[]']['#value'] = '';
      $form['bibdk_search_carousel']['bibdk_searches']['search_' . $i]['#prefix'] = '<div class="search-query-hidden">';
      $form['bibdk_search_carousel']['bibdk_searches']['search_' . $i]['#suffix'] = '</div>';
    }
  }

  // Keep track of query fields count.
  $form['bibdk_search_carousel']['num_searches'] = array(
    '#type' => 'hidden',
    '#value' => $searches_num,
  );

  // Ajaxified button for new fields.
  $form['bibdk_search_carousel']['new_search_carousel_button'] = array(
    '#type' => 'button',
    '#value' => 'Add another',
    '#name' => 'add_query',
    '#ajax' => array(
      'callback' => 'bibdk_search_carousel_admin_form_ajaxify',
      'wrapper' => 'bibdk-search-carousel-queries',
      'method' => 'replace',
      'effect' => 'fade'
    ),
  );

  // Get current saved queries.
  $searches = variable_get('bibdk_carousel_search_queries', array());

  $period = array(
    '#title' => t('Period', array(), array('context' => 'bibdk_search_carousel')),
    '#type' => 'select',
    '#options' => array(
      0 => t('All', array(), array('context' => 'bibdk_search_carousel')),
      1 => t('1 week', array(), array('context' => 'bibdk_search_carousel')),
      2 => t('@n weeks', array('@n' => '2'), array('context' => 'bibdk_search_carousel')),
      3 => t('@n weeks', array('@n' => '3'), array('context' => 'bibdk_search_carousel')),
      4 => t('@n weeks', array('@n' => '4'), array('context' => 'bibdk_search_carousel')),
      5 => t('@n weeks', array('@n' => '5'), array('context' => 'bibdk_search_carousel')),
      6 => t('@n weeks', array('@n' => '6'), array('context' => 'bibdk_search_carousel')),
      7 => t('@n weeks', array('@n' => '7'), array('context' => 'bibdk_search_carousel')),
      8 => t('@n weeks', array('@n' => '8'), array('context' => 'bibdk_search_carousel')),
      9 => t('@n weeks', array('@n' => '9'), array('context' => 'bibdk_search_carousel')),
      10 => t('@n weeks', array('@n' => '10'), array('context' => 'bibdk_search_carousel')),
      11 => t('@n weeks', array('@n' => '11'), array('context' => 'bibdk_search_carousel')),
      12 => t('@n weeks', array('@n' => '12'), array('context' => 'bibdk_search_carousel')),
    ),
    '#default_value' => isset($item['period']) ? $item['period'] : '',
    '#description' => t('Select period for this carousel search.', array(), array('context' => 'bibdk_search_carousel')),
  );

  $offset = array(
    '#title' => t('Offset', array(), array('context' => 'bibdk_search_carousel')),
    '#type' => 'select',
    '#options' => array(
      0 => t('None', array(), array('context' => 'bibdk_search_carousel')),
      1 => t('1 week', array(), array('context' => 'bibdk_search_carousel')),
      2 => t('@n weeks', array('@n' => '2'), array('context' => 'bibdk_search_carousel')),
      3 => t('@n weeks', array('@n' => '3'), array('context' => 'bibdk_search_carousel')),
      4 => t('@n weeks', array('@n' => '4'), array('context' => 'bibdk_search_carousel')),
      5 => t('@n weeks', array('@n' => '5'), array('context' => 'bibdk_search_carousel')),
      6 => t('@n weeks', array('@n' => '6'), array('context' => 'bibdk_search_carousel')),
      7 => t('@n weeks', array('@n' => '7'), array('context' => 'bibdk_search_carousel')),
      8 => t('@n weeks', array('@n' => '8'), array('context' => 'bibdk_search_carousel')),
      9 => t('@n weeks', array('@n' => '9'), array('context' => 'bibdk_search_carousel')),
      10 => t('@n weeks', array('@n' => '10'), array('context' => 'bibdk_search_carousel')),
      11 => t('@n weeks', array('@n' => '11'), array('context' => 'bibdk_search_carousel')),
      12 => t('@n weeks', array('@n' => '12'), array('context' => 'bibdk_search_carousel')),
    ),
    '#default_value' => isset($item['offset']) ? $item['offset'] : '',
    '#description' => t('Select offset for this carousel search.', array(), array('context' => 'bibdk_search_carousel')),
  );

  $searches_num = sizeof($form['bibdk_search_carousel']['bibdk_searches']);
  for ($i = 0; $i < $searches_num; $i++) {
    $form['bibdk_search_carousel']['bibdk_searches']['search_' . $i]['bibdk_search_carousel'] = array(
      '#type' => 'fieldset',
      '#title' => t('Search settings', array(), array('context' => 'bibdk_search_carousel')),
      '#title_display' => 'invisible',
    );
    $period['#default_value']    = isset($searches[$i]['period'])    ? $searches[$i]['period']    : '';
    $offset['#default_value']    = isset($searches[$i]['offset'])    ? $searches[$i]['offset']    : '';

    $form['bibdk_search_carousel']['bibdk_searches']['search_' . $i]['bibdk_search_carousel']['period[]'] = $period;
    $form['bibdk_search_carousel']['bibdk_searches']['search_' . $i]['bibdk_search_carousel']['offset[]'] = $offset;

    $form['bibdk_search_carousel']['bibdk_searches']['search_' . $i]['remove[]']['#suffix'] = '';
  }

  // Wrap the form, due to draggable items renewal.
  $form['#prefix'] = '<div id="bibdk-search-carousel-queries">';
  $form['#suffix'] = '</div>';

  // Custom themer, mainly used for dragable table creation.
  $form['#theme'] = array('bibdk_search_carousel_admin_form');

  // Custom form submit handler.
  $form['#submit'] = array('bibdk_search_carousel_search_submit');

  return system_settings_form($form);
}



/**
 * Admin settings form for frontend display of carousel.
 */
function bibdk_search_carousel_settings_admin_form($form, &$form_state) {
  $form = array();

  $form['bibdk_search_carousel_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Frontend settings'),
  );

  $form['bibdk_search_carousel_settings']['bibdk_search_carousel_tabs_position'] = array(
    '#title' => t('Position of navigational tabs'),
    '#type' => 'select',
    '#options' => array(
      'bottom' => t("Bottom"),
    ),
    '#default_value' => variable_get('bibdk_search_carousel_tabs_position', 'bottom'),
    '#required' => TRUE,
    '#description' => t('Select where you want the tabs for displaying the various searches to be placed in frontend.'),
  );

  $form['bibdk_search_carousel_settings']['bibdk_search_carousel_description_toggle'] = array(
    '#title' => t('Show descriptions for navigational tabs'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('bibdk_search_carousel_description_toggle', 0),
    '#required' => FALSE,
    '#description' => t('Toggle whether descriptions of the various searches are displayed or not.'),
  );

  return system_settings_form($form);
}



/**
 * Admin settings form for frontend display of carousel.
 */
function bibdk_search_carousel_search_admin_form($form, &$form_state) {
  $form = array();

  $form['bibdk_search_carousel_search'] = array(
    '#type' => 'fieldset',
    '#title' => t('Search settings'),
  );

  $form['bibdk_search_carousel_search']['bibdk_search_carousel_webservice'] = array(
    '#title' => t('Search webservice'),
    '#type' => 'select',
    '#options' => array(
      'bibdk_search' => t("Ting Search"),
      'bibdk_openformat' => t("Ting OpenFormat"),
    ),
    '#default_value' => variable_get('bibdk_search_carousel_webservice', 'bibdk_search'),
    '#required' => TRUE,
    '#description' => t('Select the search webservice.'),
  );

  $form['bibdk_search_carousel_search']['bibdk_search_carousel_covers_max'] = array(
    '#type' => 'textfield',
    '#title' => t('Covers maximum'),
    '#description' => t('The maximum number of covers fetched from the ADDI webservice.'),
    '#default_value' => (int)variable_get('bibdk_search_carousel_covers_max', 20),
    '#required' => TRUE,
  );

  $form['bibdk_search_carousel_search']['bibdk_search_carousel_queries_max'] = array(
    '#type' => 'textfield',
    '#title' => t('Search maximum'),
    '#description' => t('The maximum number of records fetched from the search webservice.'),
    '#default_value' => (int)variable_get('bibdk_search_carousel_queries_max', 400),
    '#required' => TRUE,
  );

  $form['bibdk_search_carousel_search']['bibdk_search_carousel_dateformat'] = array(
    '#type' => 'textfield',
    '#title' => t('Date format.', array(), array('context' => 'bibdk_search_carousel')),
    '#description' => t('PHP date format. Jfr. http://php.net/manual/en/function.date.php', array(), array('context' => 'bibdk_search_carousel')),
    '#default_value' => variable_get('bibdk_search_carousel_dateformat', 'bk\mYW'),
  );

  $form['bibdk_search_carousel_search']['bibdk_search_carousel_search_test']['boolean_information'] = array(
    '#markup' =>  t(
      'Date format example: "@dateformat" = "@date"',
      array(
        '@dateformat' => variable_get('bibdk_search_carousel_dateformat', 'bk\mYW'),
        '@date' => date( variable_get('bibdk_search_carousel_dateformat', 'bk\mYW'))
      ),
      array(
        'context' => 'bibdk_search_carousel'
      )
    )
  );

  $form['bibdk_search_carousel_search']['bibdk_search_carousel_week_search_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Search code', array(), array('context' => 'bibdk_search_carousel')),
    '#description' => t('Search code for week number.', array(), array('context' => 'bibdk_search_carousel')),
    '#default_value' => variable_get('bibdk_search_carousel_week_search_code', 'dkcclterm.kk'),
  );

  $form['bibdk_search_carousel_search']['boolean_information'] = array(
    '#markup' =>  t(
      'Boolean operators used: "and", "or" and "not"',
      array(),
      array(
        'context' => 'bibdk_search_carousel'
      )
    )
  );

  return system_settings_form($form);
}


/**
 * AJAX responder for field addition/removal fields.
 *
 * @param $form
 *   Form.
 *
 * @return
 *   Changed field to be updated.
 */
function bibdk_search_carousel_admin_form_ajaxify($form, &$form_state) {
  return $form;
}



/**
 * Theme the queries form, mainly adding a table drag-n-drop feature.
 *
 * @param $variables
 *   Theme related variables.
 *
 * @return
 *   Themed form output.
 */
function theme_bibdk_search_carousel_admin_form($variables) {

  $form = $variables['form'];

  drupal_add_tabledrag('bibdk-search-carousel-admin-sort', 'order', 'sibling', 'sort');

  $header = array('Searches', '');
  $rows = array();

  foreach (element_children($form['bibdk_search_carousel']['bibdk_searches']) as $key) {

    // Add class to group weight fields for drag and drop.
    $form['bibdk_search_carousel']['bibdk_searches'][$key]['sort[]']['#attributes']['class'][] = 'sort';

    // Get sort element.
    $sort = $form['bibdk_search_carousel']['bibdk_searches'][$key]['sort[]'];
    unset($form['bibdk_search_carousel']['bibdk_searches'][$key]['sort[]']);

    // Build rows.
    $classes = array('draggable');
    if (isset($form['bibdk_search_carousel']['bibdk_searches'][$key]['#prefix'])) {
      $classes[] = 'search-query-hidden';
    }

    $rows[] = array(
      'data' => array(
        drupal_render($form['bibdk_search_carousel']['bibdk_searches'][$key]),
        drupal_render($sort)
      ),
      'class' => $classes
    );
  }

  $table_vars = array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array('id' => 'bibdk-search-carousel-admin-sort'),
    'caption' => '',
    'colgroups' => array(),
    'sticky' => FALSE,
    'empty' => 'EMPTY'
  );
  $output = theme_table($table_vars);

  // Render remaining elements.
  $output .= drupal_render_children($form);

  return $output;
}



/**
 * Form part, describing query fields.
 *
 * @param $item
 *   Values for existing query.
 *
 * @return
 *   Fields structure.
 */
function bibdk_search_carousel_query_form($item = array(), $index = 0) {
  $form = array();

  $form['fields'] = array(
    '#type' => 'fieldset',
    '#title' => t('Search fields'),
    '#title_display' => 'invisible',
  );

  $form['sort[]'] = array(
    '#type' => 'weight',
    '#delta' => 5,
    '#default_value' => 0,
    '#value' => 0,
    '#attributes' => array(
      'class' => array(
        'sort-hidden'
      )
    ),
  );

  $form['fields']['title[]'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#description' => t('The title of the search is used for the tab in the carousel. Keep it short.'),
    '#default_value' => isset($item['title']) ? $item['title'] : '',
    '#prefix' => '<div class="search-carousel-query">',
  );

  $form['fields']['subtitle[]'] = array(
    '#type' => 'textfield',
    '#title' => t('Description'),
    '#description' => t('The subtitle displayed next to the search results.'),
    '#default_value' => isset($item['subtitle']) ? $item['subtitle'] : '',
  );

  $form['fields']['query[]'] = array(
    '#type' => 'textfield',
    '#title' => t('Query'),
    '#maxlength' => 2048,
    '#description' => t('The query to display search results for.'),
    '#default_value' => isset($item['query']) ? $item['query'] : '',
  );

  if ( isset($item['query']) ) {
    $form['fields']['test[]'] = array(
      '#type' => 'button',
      '#value' => t('Test'),
      '#name' => 'test_' . $index,
      '#attributes' => array(
        'class' => array(
          'test'
        )
      ),
    );
  }

  $form['fields']['remove[]'] = array(
    '#type' => 'button',
    '#value' => t('Remove'),
    '#name' => 'remove_' . $index,
    '#attributes' => array(
      'class' => array(
        'remove'
      )
    ),
    '#suffix' => '</div><div class="clearfix"></div>',
    '#ajax' => array(
      'callback' => 'bibdk_search_carousel_admin_form_ajaxify',
      'wrapper' => 'bibdk-search-carousel-queries',
      'method' => 'replace',
      'effect' => 'fade'
    ),
  );

  return $form;
}



/**
 * Submit handler for admin backend queries form.
 *
 * @param $form
 *   Form.
 * @param $form_state
 *   Form state.
 */
function bibdk_search_carousel_search_submit($form, &$form_state) {
  $c = count($form_state['input']['title']);
  $searches = array();
  $search_items = array();

  $hidden = variable_get('bibdk_carousel_search_queries_hidden', array());

  for ($i = 0; $i < $c; $i++) {
    if (!in_array($i, $hidden)) {
      // Make an array for saving, ignoring queries w/o title.
      if (!empty($form_state['input']['title'][$i])) {
        $searches[] = array(
          'title' => $form_state['input']['title'][$i],
          'subtitle' => $form_state['input']['subtitle'][$i],
          'query' => $form_state['input']['query'][$i],
          'period' => $form_state['input']['period'][$i],
          'offset' => $form_state['input']['offset'][$i]
        );
      }
    }
  }

  /**
   * @TODO: Add clear cache button and detect changes in the query input fields
   * so only partial cache can be rebuild. This will slow down the submit but
   * may speed up the presentation for the users by kick starting the cache.
   */

  // Save the queries as a persistent variable.
  variable_set('bibdk_carousel_search_queries', $searches);

  // Clear carousel search cache
  cache_clear_all('bibdk_search_carousel_result', 'cache');
}