<?php

/**
 * @param $form
 * @param $form_state
 * @internal param $form_id
 * @internal param $form
 * @return string
 */
function bibdk_actions_admin_settings_form($form, &$form_state) {
  $form['description'] = array(
    '#type' => 'item',
    '#title' => t('Bibliotek.dk actions settings', array(), array('context' => 'bibdk_actions admin')),
    '#description' => t('Use this form to set settings used for sending mails from cart view', array(), array('context' => 'bibdk_actions admin')),
  );

  $form['sender'] = array(
    '#type' => 'textfield',
    '#title' => 'Sender',
    '#description' => t('The email adress that will appear as the sender. To avoid spam this should be adress refering to the domain of this site.', array(), array('context' => 'bibdk_actions admin')),
    '#default_value' => variable_get('bibdk_actions_email_sender_adress', 'noreply@bibliotek.dk'),
    '#required' => TRUE,
  );

  $form['header'] = array(
    '#type' => 'textfield',
    '#title' => 'Predefined header',
    '#description' => t('The content of field will appear as the very first text in the email', array(), array('context' => 'bibdk_actions admin')),
    '#default_value' => variable_get('bibdk_actions_email_header', ''),
  );

  $form['footer'] = array(
    '#type' => 'textfield',
    '#title' => 'Predefined footer',
    '#description' => t('The content of field will appear as the very last text in the email', array(), array('context' => 'bibdk_actions admin')),
    '#default_value' => variable_get('bibdk_actions_email_footer', ''),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return $form;
}

/**
 * @param $form
 * @param $form_state
 */
function bibdk_actions_admin_settings_form_validate($form, &$form_state) {
  if (!isset($form_state['values']['sender']) || !valid_email_address($form_state['values']['sender'])) {
    $error_msg = t('email_adress_not_formatted_properly', array(), array('context' => 'bibdk_actions admin'));
    form_set_error('sender', $error_msg);
  }
}

/**
 * @param $form
 * @param $form_state
 */
function bibdk_actions_admin_settings_form_submit($form, &$form_state) {
  variable_set('bibdk_actions_email_sender_adress', $form_state['values']['sender']);
  variable_set('bibdk_actions_email_header', $form_state['values']['header']);
  variable_set('bibdk_actions_email_footer', $form_state['values']['footer']);
  drupal_set_message(t('The form has been saved', array(), array('context' => 'bibdk_actions admin')));
}
