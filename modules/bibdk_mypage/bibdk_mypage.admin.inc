<?php

function bibdk_mypage_admin() {

  $modules = module_implements('bibdk_mypage_tabs'); // for later: order of tabs

  $form['search_history_save_limit'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum number of items in each tab'),
    '#size' => 4,
    '#description' => t('Maximum number of items in each tab.'),
    '#default_value' => variable_get('bibdk_mypage_max_items', 4),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#submit' => array('bibdk_mypage_admin_submit'),
    '#value' => t('Save'),
  );

  return $form;
}

/**
 * Submit handler for bibdk_mypage_admin();
 */
function bibdk_mypage_admin_submit($form, &$form_state) {
  $value = $form_state['values']['search_history_save_limit'];
  variable_set('bibdk_mypage_max_items', (int) abs($value));
  drupal_set_message(t('Value saved', array(), array('context' => 'bibdk_mypage')), 'status');
}

