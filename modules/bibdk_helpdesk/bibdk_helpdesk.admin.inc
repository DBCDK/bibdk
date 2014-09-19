<?php

/**
 * @file
 * Admin settings for bibdk helpdesk
 */

/**
 * General settings.
 */
function bibdk_helpdesk_admin() {

  $bibdk_helpdesk_settings = variable_get('bibdk_helpdesk_settings', $default = array());

  drupal_add_css(drupal_get_path('module', 'bibdk_helpdesk') . '/css/bibdk_helpdesk.css');

  $form['bibdk_helpdesk'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('Bibliotek.dk helpdesk text'),
    '#tree'         => TRUE,
    '#theme'        => 'bibdk_helpdesk-admin-form',
  );

  $form['bibdk_helpdesk']['title'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Title'),
    '#title_display'  => 'before',
    '#default_value'  => check_plain($bibdk_helpdesk_settings['title']),
  );

  $form['bibdk_helpdesk']['link'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Link'),
    '#title_display'  => 'before',
    '#default_value'  => check_plain($bibdk_helpdesk_settings['link']),
  );

  $form['bibdk_helpdesk']['description'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Description'),
    '#title_display'  => 'before',
    '#default_value'  => check_plain($bibdk_helpdesk_settings['description']),
  );

  $form['bibdk_helpdesk_image']['image'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('Bibliotek.dk helpdesk image'),
    '#tree'         => TRUE,
  );

  $form['bibdk_helpdesk_image']['image']['normal']['height'] = array(
    '#type'           => 'textfield',
    '#title'          => t('height'),
    '#title_display'  => 'before',
    '#default_value'  => check_plain($bibdk_helpdesk_settings['image']['normal']['height']),
  );

  $form['bibdk_helpdesk_image']['image']['normal']['width'] = array(
    '#type'           => 'textfield',
    '#title'          => t('width'),
    '#title_display'  => 'before',
    '#default_value'  => check_plain($bibdk_helpdesk_settings['image']['normal']['width']),
  );

  $form['helpdesk_url'] = array(
    '#type' => 'fieldset',
    '#title' => t('Helpdesk settings'),
    '#weight' => -3,
  );

  $form['helpdesk_url']['helpdesk_submit_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Helpdesk URL'),
    '#description' => t('URL to where the helpdesk form should be submitted e.g. http://biblioteksvagten.dk/openquestion.asp'),
    '#required' => TRUE,
    '#default_value' => variable_get('helpdesk_submit_url', ''),
  );

  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Save'),
    ),
  );

  $form['#submit'][] = 'bibdk_helpdesk_admin_submit';

  return $form;

}



/**
 * Submit handler for bibdk_helpdesk_admin();
 */
function bibdk_helpdesk_admin_submit($form, &$form_state) {

  $bibdk_helpdesk_settings = array(
    'description' => check_plain($form_state['values']['bibdk_helpdesk']['description']),
    'title' => check_plain($form_state['values']['bibdk_helpdesk']['title']),
    'link' => check_plain($form_state['values']['bibdk_helpdesk']['link']),
    'image' => array(
      'normal' => array(
        'height' => (int)$form_state['values']['image']['normal']['height'],
        'width' => (int)$form_state['values']['image']['normal']['width'],
      ),
    ),
  );

  variable_set('bibdk_helpdesk_settings', $bibdk_helpdesk_settings);

  variable_set('helpdesk_submit_url', check_plain($form_state['values']['helpdesk_submit_url']));

  $message[] = t('The settings have been updated.');
  drupal_set_message(check_plain(implode('<br/>', array_unique($message))));

}

/**
 * Validation handler for bibdk_helpdesk_admin.
 */
function bibdk_helpdesk_admin_validate($form, &$form_state) {
  return $form;
}

