<?php
/**
 * @file. add suggest service settings to ting_clients admin form
 */


/**
 * @param $form
 * @param $form_state
 */
function bibdk_autocomplete_form_ting_client_admin_webservices_settings_alter(&$form, &$form_state) {
  $form['openplatform_suggest']['#type'] = 'fieldset';
  $form['openplatform_suggest']['#title'] = t('Openplatform suggestion service', array(), array('context' => 'bibdk_autocomplete_admin'));
  $form['openplatform_suggest']['#description'] = t('Suggestion service from openplatform', array(), array('context' => 'bibdk_autocomplete_admin'));
  $form['openplatform_suggest']['#collapsible'] = TRUE;
  $form['openplatform_suggest']['#collapsed'] = TRUE;
  $form['openplatform_suggest']['#tree'] = FALSE;


  $form['openplatform_suggest']['OpenPlatformSuggestRequest_url'] = array(
    '#type' => 'textfield',
    '#title' => t('openplatform suggest url', array(), array('context' => 'bibdk_autocomplete_admin')),
    '#description' => t('URL to suggest service', array(), array('context' => 'bibdk_autocomplete_admin')),
    '#required' => TRUE,
    '#default_value' => variable_get('OpenPlatformSuggestRequest_url', ''),
  );
}
