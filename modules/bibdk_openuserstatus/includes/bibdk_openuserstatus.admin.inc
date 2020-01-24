<?php

/**
 * @file
 * Admin settings for bibdk_openuserstatus
 */

/**
 * General settings.
 */
function bibdk_openuserstatus_admin() {

  $bibdk_openuserstatus_settings = variable_get('bibdk_openuserstatus_settings', $default = array());

  $form['bibdk_openuserstatus'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('Bibliotek.dk openUserstatus texts'),
    '#tree'         => TRUE,
    '#theme'        => 'bibdk_openuserstatus-admin-form',
  );

  $form['bibdk_openuserstatus']['label_userstatus_intro'] = array(
    '#type'           => 'textarea',
    '#title'          => t('Intro text'),
    '#title_display'  => 'before',
    '#default_value'  => $bibdk_openuserstatus_settings['label_userstatus_intro'],
  );

  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Save'),
    ),
  );

  $form['#submit'][] = 'bibdk_openuserstatus_admin_submit';

  return $form;

}



/**
 * Submit handler for bibdk_openuserstatus_admin();
 */
function bibdk_openuserstatus_admin_submit($form, &$form_state) {

  $bibdk_openuserstatus_settings = array(
    'label_userstatus_intro' => $form_state['values']['bibdk_openuserstatus']['label_userstatus_intro'],
  );

  variable_set('bibdk_openuserstatus_settings', $bibdk_openuserstatus_settings);

  $message[] = t('The settings have been updated.');
  drupal_set_message(check_plain(implode('<br/>', array_unique($message))));

}

/**
 * Validation handler for bibdk_openuserstatus_admin.
 */
function bibdk_openuserstatus_admin_validate($form, &$form_state) {

  if ( empty($form_state['values']['bibdk_openuserstatus']['label_userstatus_intro']) ) {
    $form_state['values']['bibdk_openuserstatus']['label_userstatus_intro'] = 'label_userstatus_intro';
  }

  if ( !drupal_validate_utf8($form_state['values']['bibdk_openuserstatus']['label_userstatus_intro']) ) {
    form_set_error('label_userstatus_intro', t('The string is not valid UTF-8.', array(), array('context' => 'bibdk_openuserstatus:error')));
  }

  return $form;
}

