<?php

/**
 * @file
 * Admin settings for bibliotek.dk autocomplete.
 */

function bibdk_autocomplete_admin() {

  $base_settings['filterQuery'] = NULL;
  $base_settings['agency'] = NULL;
  $base_settings['maxSuggestions'] = NULL;
  $base_settings['maxTime'] = NULL;
  $base_settings['profile'] = NULL;
  $base_settings['highlight'] = NULL;
  $base_settings['highlight.pre'] = NULL;
  $base_settings['highlight.post'] = NULL;

  $defaults = variable_get('bibdk_autocomplete_settings', array());

  foreach ($base_settings as $key => $base_setting) {
    $default_settings[$key] = ( isset($defaults[$key]) ) ? $defaults[$key] : $base_setting;
  }

  $form['bibdk_autocomplete_webservice'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('Bibliotek.dk autocomplete URL', array(), array('context' => 'bibdk_autocomplete_admin')),
    '#tree'         => FALSE,
    '#collapsible'  => TRUE,
  );

  $form['bibdk_autocomplete_webservice']['bibdk_autocomplete_rest_url'] = array(
    '#type' => 'textfield',
    '#title' => t('bibliotek.dk autocomplete REST URL', array(), array('context' => 'bibdk_autocomplete_admin')),
    '#size' => 73,
    '#description' => t('Autocomplete REST URL (Redo as a standard webservice client once we have a SOAP webservice.)', array(), array('context' => 'bibdk_autocomplete_admin')),
    '#default_value' => variable_get('bibdk_autocomplete_rest_url', NULL),
  );

  $form['bibdk_autocomplete_settings'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('Bibliotek.dk autocomplete settings', array(), array('context' => 'bibdk_autocomplete_admin')),
    '#tree'         => TRUE,
    '#collapsible'  => TRUE,
  );

  $form['bibdk_autocomplete_settings']['agency'] = array(
    '#type' => 'textfield',
    '#title' => t('Agency', array(), array('context' => 'bibdk_autocomplete_admin')),
    '#size' => 26,
    '#description' => t('Only get suggestions from data accessible to the specified agency', array(), array('context' => 'bibdk_autocomplete_admin')),
    '#default_value' => $default_settings['agency'],
  );

  $form['bibdk_autocomplete_settings']['maxSuggestions'] = array(
    '#type' => 'textfield',
    '#title' => t('Max suggestions', array(), array('context' => 'bibdk_autocomplete_admin')),
    '#size' => 26,
    '#description' => t('Maximum suggestions to return', array(), array('context' => 'bibdk_autocomplete_admin')),
    '#default_value' => $default_settings['maxSuggestions'],
  );

  $form['bibdk_autocomplete_settings']['maxTime'] = array(
    '#type' => 'textfield',
    '#title' => t('Max request time', array(), array('context' => 'bibdk_autocomplete_admin')),
    '#size' => 26,
    '#description' => t('Maximum request time in milliseconds.', array(), array('context' => 'bibdk_autocomplete_admin')),
    '#default_value' => $default_settings['maxTime'],
  );

  $form['bibdk_autocomplete_settings']['profile'] = array(
    '#type' => 'textfield',
    '#title' => t('Profile', array(), array('context' => 'bibdk_autocomplete_admin')),
    '#size' => 26,
    '#description' => t('Only get suggestions from data accessible to the specified search profile', array(), array('context' => 'bibdk_autocomplete_admin')),
    '#default_value' => $default_settings['profile'],
  );

  $form['bibdk_autocomplete_settings']['highlight'] = array(
    '#type' => 'checkbox',
    '#title' => t('Highlight', array(), array('context' => 'bibdk_autocomplete_admin')),
    '#description' => t('If checked, search prefix will be enclosed in highlight prefix and -suffix', array(), array('context' => 'bibdk_autocomplete_admin')),
    '#default_value' => $default_settings['highlight'],
  );

  $form['bibdk_autocomplete_settings']['highlight.pre'] = array(
    '#type' => 'textfield',
    '#title' => t('Highlight prefix', array(), array('context' => 'bibdk_autocomplete_admin')),
    '#size' => 20,
    '#default_value' => $default_settings['highlight.pre'],
  );

  $form['bibdk_autocomplete_settings']['highlight.post'] = array(
    '#type' => 'textfield',
    '#title' => t('Highlight suffix', array(), array('context' => 'bibdk_autocomplete_admin')),
    '#size' => 18,
    '#default_value' => $default_settings['highlight.post'],
  );

  // Attach the CSS to the form
  $path = drupal_get_path('module', 'bibdk_autocomplete');
  $form['#attached'] = array(
    'css' => array(
      'type' => 'file',
      'data' => $path . '/css/bibdk_autocomplete_admin_form.css',
    ),
  );

  $result = _bibdk_autocomplete_get_search_fields_db();

  $default = variable_get('bibdk_autocomplete_var', array());

  $form['bibdk_autocomplete_var'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('Bibliotek.dk autocomplete fields', array(), array('context' => 'bibdk_autocomplete_admin')),
    '#tree'         => TRUE,
  );

  $form['bibdk_autocomplete_var']['description'] = array(
    '#type'         => 'item',
    '#markup'       => t('Term index: Get terms starting with a prefix from a specific index', array(), array('context' => 'bibdk_autocomplete_admin')) . '<br/>' .
                       t('Facet index: Get phrases containing words starting with a prefix from a specific index', array(), array('context' => 'bibdk_autocomplete_admin')) . '<br/>' .
                       t('Query filter: Limit results to a search register', array(), array('context' => 'bibdk_autocomplete_admin')),
  );

  $base_vars['autocomplete'] = NULL;
  $base_vars['term_index'] = NULL;
  $base_vars['facet_index'] = NULL;
  $base_vars['sort_order'] = NULL;

  foreach ($result as $value) {

    $default_value = isset($default[ $value->p_uuid ]['vars'][ $value->v_uuid ]) ? $default[ $value->p_uuid ]['vars'][ $value->v_uuid ] : $base_vars;

    $form['bibdk_autocomplete_var'][ $value->p_uuid ]['vars'][ $value->v_uuid ] = array(
      '#type'         => 'fieldset',
      '#title'        => $value->menu_title . ' > ' . $value->element_label,
      '#tree'         => TRUE,
      '#collapsible'  => TRUE,
    );

    $form['bibdk_autocomplete_var'][ $value->p_uuid ]['page_path'] = array(
      '#type' => 'hidden',
      '#default_value' => $value->page_path,
    );

    $form['bibdk_autocomplete_var'][ $value->p_uuid ]['vars'][ $value->v_uuid ]['autocomplete'] = array(
      '#type' => 'checkbox',
      '#title' => t('Autocomplete', array(), array('context' => 'bibdk_autocomplete_admin')),
      '#default_value' => ( !empty($default_value['autocomplete']) ) ? $default_value['autocomplete'] : FALSE,
    );

    $form['bibdk_autocomplete_var'][ $value->p_uuid ]['vars'][ $value->v_uuid ]['index'] = array(
      '#type' => 'textfield',
      '#title' => t('Term index', array(), array('context' => 'bibdk_autocomplete_admin')),
      '#size' => 25,
      '#default_value' => ( !empty($default_value['index']) ) ? $default_value['index'] : '',
    );

    $form['bibdk_autocomplete_var'][ $value->p_uuid ]['vars'][ $value->v_uuid ]['facetIndex'] = array(
      '#type' => 'textfield',
      '#title' => t('Facet Index', array(), array('context' => 'bibdk_autocomplete_admin')),
      '#size' => 25,
      '#default_value' => ( !empty($default_value['facetIndex']) ) ? $default_value['facetIndex'] : '',
    );

    $form['bibdk_autocomplete_var'][ $value->p_uuid ]['vars'][ $value->v_uuid ]['filterQuery'] = array(
      '#type' => 'textfield',
      '#title' => t('Filter Query', array(), array('context' => 'bibdk_autocomplete_admin')),
      '#size' => 25,
      '#default_value' => ( !empty($default_value['filterQuery']) ) ? $default_value['filterQuery'] : '',
    );

    $form['bibdk_autocomplete_var'][ $value->p_uuid ]['vars'][ $value->v_uuid ]['sort'] = array(
      '#type' => 'radios',
      '#title' => t('Output sort order', array(), array('context' => 'bibdk_autocomplete_admin')),
      '#options' => array('count' => 'count', 'index' => 'index', ),
      '#default_value' => ( !empty($default_value['sort']) ) ? $default_value['sort'] : '',
    );

    // see also drupal_html_id
    $id = strtr(drupal_strtolower('input ' . $value->element_label), array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));
    $id = preg_replace('/[^A-Za-z0-9\-_]/', '', $id);
    $id = preg_replace('/\-+/', '-', $id);
    $form['bibdk_autocomplete_var'][ $value->p_uuid ]['vars'][ $value->v_uuid ]['id'] = array(
      '#type' => 'hidden',
      '#title' => t('Id'),
      '#value' => ( !empty($value->element_label) ) ? $id : '',
    );

  }

  $form['#submit'][] = 'bibdk_autocomplete_admin_submit';

  return system_settings_form($form);

}


/**
 * Validation handler for bibdk_autocomplete_admin
 */
function bibdk_autocomplete_admin_validate($form, &$form_state) {

  $form_state['values']['bibdk_autocomplete_rest_url'] = trim($form_state['values']['bibdk_autocomplete_rest_url'], $character_mask = " \t\n\r\0\x0B/");
  
  foreach ($form_state['values']['bibdk_autocomplete_var'] as $p_uuid => $page) {
    foreach ($page['vars'] as $v_uuid => $vars) {
      if ( $vars['autocomplete'] && empty($vars['index']) ) {
        form_set_error(
          'bibdk_autocomplete_var][' . $p_uuid . '][vars][' . $v_uuid . '][index', 
          'If autocomplete is checked, a search index must be configured'
        );
      }
    }
  }

}


/**
 * Submt handler for bibdk_autocomplete_admin
 */
function bibdk_autocomplete_admin_submit($form, &$form_state) {
  //
}

/**
 * Get advanced search field records from db
 *
 * @return DatabaseStatementInterface|null
 */
function _bibdk_autocomplete_get_search_fields_db() {

  // Get cached result
  $cache_id = 'bibdk_autocomplete_search_fields';

  if ( $cache = cache_get($cache_id) ) {
    return $cache->data;
  }

  // bibdk_custom_search_elements
  $query = db_select('bibdk_custom_search', 's');
  $query->leftjoin('bibdk_custom_search_map_elements', 'me', 's.p_uuid = me.p_uuid');
  $query->join('bibdk_custom_search_elements', 'e', 'me.e_uuid = e.e_uuid');
  $query->leftjoin('bibdk_custom_search_map_values', 'mv', 'e.e_uuid = mv.e_uuid');
  $query->join('bibdk_custom_search_values', 'v', 'mv.v_uuid = v.v_uuid');
  $query->leftjoin('bibdk_custom_search_options', 'o', 'v.v_uuid = o.v_uuid');

  $query->fields('s', array('menu_title', 'p_uuid', 'page_path'));
  // $query->fields('me', array('sort'));
  $query->fields('e', array(
    'e_uuid',
    'element_label',
  ));
  // $query->fields('mv', array('sort'));
  $query->fields('v', array(
    'v_uuid',
    'value_title',
    'search_code',
  ));

  $query -> condition('v.value_type', 'textfield', '=');

  $query->orderBy('me.sort', 'ASC');
  $query->orderBy('e.element_label', 'ASC');
  $query->orderBy('region', 'ASC');
  $query->orderBy('mv.sort', 'ASC');
  $query->orderBy('v.value_title', 'ASC');

  $result = $query->execute()->fetchAll();

  cache_set($cache_id, $result, 'cache');

  return $result;

}
