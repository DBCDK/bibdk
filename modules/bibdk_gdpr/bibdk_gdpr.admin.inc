<?php

/**
 * @file
 * Admin pages and forms for bibdk_gdpr module.
 */

/**
 * General settings form for bibdk_gdpr module.
 */
function bibdk_gdpr_settings_form($form, &$form_state) {
  $text = variable_get('bibdk_gdpr_consent_message', array());
  $form['bibdk_gdpr_consent_message'] = array(
    '#title' => t('Consent message'),
    '#type' => 'text_format',
    '#default_value' => isset($text['value']) ? $text['value'] : '',
    '#format' => isset($text['format']) ? $text['format'] : 'plain_text',
  );

  return system_settings_form($form, $form_state);
}
