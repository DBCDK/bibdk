<?php
/**
 * @file
 * Admin page callback file for 'materialetyper' not for order 
 */

/**
 * Form builder; Configure 'materialetyper' not for order.
 *
 */
function bibdk_mattype_settings($form_state) {
  
  $form_name = 'bibdk_mattype_settings';
  $form = array();

  $mattypes = variable_get('bibdk_mattype_settings', array());

  $form['description'] = array(
    '#markup' => '<p>' . t('Configure materialetyper - not for order.') . '</p>',
  );

  $form[$form_name] = array(
    '#tree' => TRUE,
    '#weight' => -20,
  );


  // display all saved materialetyper 
  $i = 0;
  foreach ( $mattypes as $mattype ) {
    $form[$form_name][$i]['name'] = array(
      '#type' => 'textfield',
      '#title' => t('Mattype id'),
      '#title_display' => 'invisible',
      '#default_value' => $mattype['name'],
    );

    $form[$form_name][$i]['delete'] = array(
      '#type' => 'link',
      '#title' => t('delete'),
      '#href' =>  'admin/config/ting/mattypes/' . $mattype['name'] . '/delete',
      '#options' => array('attributes' => array('title' => t('Delete mattype.'))),
    );
    $i++;
  }

  // preparing for adding a new materialetype
  $form[$form_name][$i]['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Add new materialetype'),
    '#default_value' => '',
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save changes'),
  );

  return $form;

}

/**
 * Submit handler for bibdk_mattype_settings();
 */
function bibdk_mattype_settings_submit($form, &$form_state) {

  $mattypes = $form_state['values']['bibdk_mattype_settings'];
  foreach ($mattypes as $key => $mattype) {
    if (empty($mattype['name'])) {
      unset($mattypes[$key]);
    }
  }
  variable_set('bibdk_mattype_settings', $mattypes);
  drupal_set_message(t('The configuration options have been saved.', array(), array('context' => 'bibdk_mattype_settings')));
  
}

/**
 * Delete 'materialetype' from 'bibdk_mattype_settings'
 */
function bibdk_mattype_settings_delete_mattype_submit($form, &$form_state) {

  $delete_name = $form_state['build_info']['args'][0];
  $mattypes = variable_get('bibdk_mattype_settings', array());
  
  foreach ($mattypes as $key => $mattype) {
    if ($mattype['name'] == $delete_name) {
      unset($mattypes[$key]);
    }
  }

  variable_set('bibdk_mattype_settings', $mattypes);
  drupal_set_message(t('Materialetype deleted: ' . $delete_name , array(), array('context' => 'bibdk_reservation')));
  $form_state['redirect'] = 'admin/config/ting/mattypes/';
}
