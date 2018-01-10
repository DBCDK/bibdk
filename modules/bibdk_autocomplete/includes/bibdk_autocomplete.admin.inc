<?php

/**
 * @file
 * Admin settings for bibliotek.dk autocomplete.
 */

function bibdk_autocomplete_admin() {

  $base_settings['rows'] = '10';
  
  $defaults = variable_get('bibdk_autocomplete_settings', array());

  foreach ($base_settings as $key => $base_setting) {
    $default_settings[$key] = (isset($defaults[$key])) ? $defaults[$key] : $base_setting;
  }

  $form['bibdk_autocomplete_webservice'] = array(
    '#type' => 'fieldset',
    '#title' => t('Ortograf', array(), array('context' => 'bibdk_autocomplete_admin')),
    '#tree' => FALSE,
    '#collapsible' => TRUE,
  );

  $form['bibdk_autocomplete_webservice']['bibdk_autocomplete_rest_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Ortograf URL', array(), array('context' => 'bibdk_autocomplete_admin')),
    '#size' => 73,
    '#description' => t('Ortograf REST URL.', array(), array('context' => 'bibdk_autocomplete_admin')),
    '#default_value' => variable_get('bibdk_autocomplete_rest_url', NULL),
  );

  $form['bibdk_autocomplete_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Ortograf settings', array(), array('context' => 'bibdk_autocomplete_admin')),
    '#tree' => TRUE,
    '#collapsible' => TRUE,
  );

  $form['bibdk_autocomplete_settings']['rows'] = array(
    '#type' => 'textfield',
    '#title' => t('Max suggestions', array(), array('context' => 'bibdk_autocomplete_admin')),
    '#size' => 26,
    '#return_value' => 'true',
    '#description' => t('Maximum suggestions to return', array(), array('context' => 'bibdk_autocomplete_admin')),
    '#default_value' => $default_settings['rows'],
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

  $p_uuids = $freetext = array();
  foreach ($result as $value) {
    if (!in_array($value->p_uuid, $p_uuids)) {
      $p_uuids[] = $value->p_uuid;
      $freetext[] = (object) array(
        'p_uuid' => $value->p_uuid, 
        'v_uuid' => 'search_block_form', 
        'menu_title' => $value->menu_title, 
        'value_type' => 'textfield',
        'element_label' => 'Fritekst',
        'page_path' => $value->page_path,
      );
    }
  }
  $result = array_merge($result, $freetext);

  $form['bibdk_autocomplete_var'] = array(
    '#type' => 'fieldset',
    '#title' => t('Bibliotek.dk autocomplete fields', array(), array('context' => 'bibdk_autocomplete_admin')),
    '#tree' => TRUE,
  );

  $base_vars['type'] = 'all';

  foreach ($result as $value) {

    if ($value->value_type != 'textfield') {
      continue;
    }
    
    $default_value = isset($default[$value->p_uuid]['vars'][$value->v_uuid]) ? $default[$value->p_uuid]['vars'][$value->v_uuid] : $base_vars;

    $form['bibdk_autocomplete_var'][$value->p_uuid]['vars'][$value->v_uuid] = array(
      '#type' => 'fieldset',
      '#title' => $value->menu_title . ' > ' . $value->element_label,
      '#tree' => TRUE,
      '#collapsible' => TRUE,
    );
    
    if ((empty($default_value['autocomplete']))) {
      $form['bibdk_autocomplete_var'][$value->p_uuid]['vars'][$value->v_uuid]['#collapsed'] = TRUE;
    }

    $form['bibdk_autocomplete_var'][$value->p_uuid]['page_path'] = array(
      '#type' => 'hidden',
      '#default_value' => $value->page_path,
    );

    $form['bibdk_autocomplete_var'][$value->p_uuid]['vars'][$value->v_uuid]['autocomplete'] = array(
      '#type' => 'checkbox',
      '#title' => t('Autocomplete', array(), array('context' => 'bibdk_autocomplete_admin')),
      '#default_value' => (!empty($default_value['autocomplete'])) ? $default_value['autocomplete'] : FALSE,
    );

    $form['bibdk_autocomplete_var'][$value->p_uuid]['vars'][$value->v_uuid]['type'] = array(
      '#type' => 'radios',
      '#title' => t('Suggestion type', array(), array('context' => 'bibdk_autocomplete_admin')),
      '#options' => array('all' => 'all', 'creator' => 'creator', 'subject' => 'subject', 'title' => 'title'),
      '#default_value' => (!empty($default_value['type'])) ? $default_value['type'] : '',
    );

    // see also drupal_html_id
    $id = strtr(drupal_strtolower('input ' . $value->element_label), array(
      ' ' => '-',
      '_' => '-',
      '[' => '-',
      ']' => ''
    ));
    $id = preg_replace('/[^A-Za-z0-9\-_]/', '', $id);
    $id = preg_replace('/\-+/', '-', $id);
    $form['bibdk_autocomplete_var'][$value->p_uuid]['vars'][$value->v_uuid]['id'] = array(
      '#type' => 'hidden',
      '#title' => t('Id'),
      '#value' => (!empty($value->element_label)) ? $id : '',
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
      if ($vars['autocomplete'] && empty($vars['type'])) {
        form_set_error('bibdk_autocomplete_var][' . $p_uuid . '][vars][' . $v_uuid . '][index', 'If autocomplete is checked, a type must be configured');
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

  if ($cache = cache_get($cache_id)) {
    return $cache->data;
  }

  // bibdk_custom_search_elements
  $query = db_select('bibdk_custom_search', 's');
  $query->leftjoin('bibdk_custom_search_map_elements', 'me', 's.p_uuid = me.p_uuid');
  $query->join('bibdk_custom_search_elements', 'e', 'me.e_uuid = e.e_uuid');
  $query->leftjoin('bibdk_custom_search_map_values', 'mv', 'e.e_uuid = mv.e_uuid');
  $query->join('bibdk_custom_search_values', 'v', 'mv.v_uuid = v.v_uuid');
  $query->leftjoin('bibdk_custom_search_options', 'o', 'v.v_uuid = o.v_uuid');

  $query->fields('s', array(
    'menu_title',
    'p_uuid',
    'page_path'
  ));

  $query->fields('e', array(
    'e_uuid',
    'element_label',
  ));

  $query->fields('v', array(
    'v_uuid',
    'value_title',
    'value_type',
    'search_code',
  ));

  $query->orderBy('me.sort', 'ASC');
  $query->orderBy('e.element_label', 'ASC');
  $query->orderBy('region', 'ASC');
  $query->orderBy('mv.sort', 'ASC');
  $query->orderBy('v.value_title', 'ASC');

  $result = $query->execute()->fetchAll();

  cache_set($cache_id, $result, 'cache');

  return $result;

}
