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
    $default_settings[$key] = (isset($defaults[$key])) ? $defaults[$key] : $base_setting;
  }

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
    '#type' => 'fieldset',
    '#title' => t('Bibliotek.dk autocomplete fields', array(), array('context' => 'bibdk_autocomplete_admin')),
    '#tree' => TRUE,
  );

  $base_vars['autocomplete'] = NULL;
  $base_vars['term_index'] = NULL;
  $base_vars['facet_index'] = NULL;
  $base_vars['sort_order'] = NULL;

  foreach ($result as $value) {

    $default_value = isset($default[$value->p_uuid]['vars'][$value->v_uuid]) ? $default[$value->p_uuid]['vars'][$value->v_uuid] : $base_vars;

    $form['bibdk_autocomplete_var'][$value->p_uuid]['vars'][$value->v_uuid] = array(
      '#type' => 'fieldset',
      '#title' => $value->menu_title . ' > ' . $value->element_label,
      '#tree' => TRUE,
      '#collapsible' => TRUE,
      '#attributes' => array('class' => array('bibdk-autocomplete-admin-fieldset')),
    );

    $form['bibdk_autocomplete_var'][$value->p_uuid]['page_path'] = array(
      '#type' => 'hidden',
      '#default_value' => $value->page_path,
      '#attributes' => array('class' => array('bibdk-autocomplete-admin-page-path')),
    );

    $form['bibdk_autocomplete_var'][$value->p_uuid]['vars'][$value->v_uuid]['autocomplete'] = array(
      '#type' => 'checkbox',
      '#title' => t('Autocomplete', array(), array('context' => 'bibdk_autocomplete_admin')),
      '#default_value' => (!empty($default_value['autocomplete'])) ? $default_value['autocomplete'] : FALSE,
      '#attributes' => array('class' => array('bibdk-autocomplete-admin-autocomplete')),
    );

    $form['bibdk_autocomplete_var'][$value->p_uuid]['vars'][$value->v_uuid]['index'] = array(
      '#type' => 'select',
      '#options' => array(
        'creator' => 'creator',
        'title' => 'title',
        'subject' => 'subject'
      ),
      '#title' => t('Type', array(), array('context' => 'bibdk_autocomplete_admin')),

      '#default_value' => isset($default_value['index']) ? $default_value['index'] : 'creator',
      '#attributes' => array('class' => array('bibdk-autocomplete-admin-index')),
    );


    $form['bibdk_autocomplete_var'][$value->p_uuid]['vars'][$value->v_uuid]['operation'] = array(
      '#type' => 'select',
      '#title' => t('Function', array(), array('context' => 'bibdk_autocomplete_admin')),
      '#options' => array(
        'suggest' => t('Suggest', array(), array('context' => 'bibdk_autocomplete_admin'))
      ),
      '#default_value' => (!empty($default_value['operation'])) ? $default_value['operation'] : '',
      '#attributes' => array('class' => array('bibdk-autocomplete-admin-operation')),
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

  $form['#attached']['js'][] = drupal_get_path('module', 'bibdk_autocomplete') . '/js/bibdk_autocomplete.admin.js';

  $form['#submit'][] = 'bibdk_autocomplete_admin_submit';

  return system_settings_form($form);

}

/**
 * Validation handler for bibdk_autocomplete_admin
 */
function bibdk_autocomplete_admin_validate($form, &$form_state) {
  foreach ($form_state['values']['bibdk_autocomplete_var'] as $p_uuid => $page) {
    foreach ($page['vars'] as $v_uuid => $vars) {
      if ($vars['autocomplete'] && empty($vars['index'])) {
        form_set_error('bibdk_autocomplete_var][' . $p_uuid . '][vars][' . $v_uuid . '][index', 'If autocomplete is checked, a search index must be configured');
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

  $query->condition('v.value_type', 'textfield', '=');

  $query->orderBy('me.sort', 'ASC');
  $query->orderBy('e.element_label', 'ASC');
  $query->orderBy('region', 'ASC');
  $query->orderBy('mv.sort', 'ASC');
  $query->orderBy('v.value_title', 'ASC');

  $result = $query->execute()->fetchAll();

  cache_set($cache_id, $result, 'cache');

  return $result;

}
