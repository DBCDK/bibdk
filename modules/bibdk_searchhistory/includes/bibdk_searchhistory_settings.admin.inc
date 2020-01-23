<?php

/**
 * @file
 * Admin settings for search history.
 */

function bibdk_searchhistory_admin() {
  $form['search_history_save_limit'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum number of searches saved in session'),
    '#size' => 5,
    '#description' => t('Number of saved searches. When exceeded will the oldest unsaved search be deleted - 0 = unlimited'),
    '#default_value' => variable_get('search_history_save_limit', 25),
  );

  $form['search_history_save_facet_search'] = array(
    '#type' => 'checkbox',
    '#title' => t('Save facet searches'),
    '#description' => 'If checked searches using facets will be saved in the search history',
    '#default_value' => variable_get('search_history_save_facet_search', 0),
  );

  $form['search_history_accepted_params'] = array(
    '#type' => 'textfield',
    '#title' => t('Params that should be accepted to display in search history'),
    '#size' => 50,
    '#description' => t('Commaseperated values. No spaces! E.g. dkcclterm,term'),
    '#default_value' => variable_get('search_history_accepted_params', 'dkcclterm,term'),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#submit' => array('bibdk_searchhistory_admin_submit'),
    '#value' => t('Save'),
  );

  return system_settings_form($form);
}
