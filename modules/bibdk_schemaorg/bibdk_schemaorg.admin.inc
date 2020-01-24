<?php

/**
 * @file
 * User interface for setting the schema.org mappings
 */

/**
 * Implements hook_form_FORM_ID_alter().
 */
function bibdk_schemaorg_form_field_ui_field_edit_form_alter(&$form, &$form_state) {

  $field_name = $form['#field']['field_name'];
  $instance = $form['instance'];
  $label = isset($instance['label']) ? $instance['label']['#default_value'] : $instance['field_name'];
  
  $bibdk_schema_org_vars = variable_get('bibdk_schema_org_vars', array());

  // Attach the css  & js to the form
  $path = drupal_get_path('module', 'bibdk_schemaorg');
  $form['#attached']['css'][] = $path . '/css/bibdk_schemaorg_admin_form.css';
  $form['#attached']['js'][]  = $path . '/js/bibdk_schemaorg_admin_form.js';

  $form['bibdk_schemaorg_ui'] = array(
    '#type' => 'fieldset',
    '#title' => t('%label schema.org mapping', array('%label' => $label)),
  );

  $form['bibdk_schemaorg_ui']['bibdk_schemaorg_field_property'] = array(
    '#type' => 'textfield',
    '#title' => t('Schema.org property'),
    '#description' => t('Specify the property you want to associated to this field.'),
    '#default_value' => (isset($bibdk_schema_org_vars[$field_name]['property'])) ? $bibdk_schema_org_vars[$field_name]['property'] : '',
    '#attributes' => array('class' => array('bibdk_schemaorg')),
  );

  $form['bibdk_schemaorg_ui']['bibdk_schemaorg_field_typeof'] = array(
    '#type' => 'textfield',
    '#title' => t('Schema.org data type'),
    '#description' => t('Expected type for this property, if not text or an integer. f.ex. Person, Organization or Date'),
    '#default_value' => (isset($bibdk_schema_org_vars[$field_name]['typeof'])) ? $bibdk_schema_org_vars[$field_name]['typeof'] : '',
    '#attributes' => array('class' => array('bibdk_schemaorg')),
  );

  $form['bibdk_schemaorg_ui']['bibdk_schemaorg_field_typeof_property'] = array(
    '#type' => 'textfield',
    '#title' => t('Data type property <span class="form-required" title="This field is required.">*</span>'),
    '#description' => t('Property for the Schema.org data type.'),
    '#default_value' => ( isset($bibdk_schema_org_vars[$field_name]['typeof_property'])) ? $bibdk_schema_org_vars[$field_name]['typeof_property'] : '',
    '#attributes' => array('class' => array('bibdk_schemaorg')),
  );

  $form['#validate'][] = 'bibdk_schemaorg_field_ui_field_edit_form_validate';
  $form['#submit'][]   = 'bibdk_schemaorg_field_ui_field_edit_form_submit';

}

/**
 * Submit function for edit field form.
 */
function bibdk_schemaorg_field_ui_field_edit_form_submit($form, &$form_state) {

  $field_name = $form['#field']['field_name'];

  $bibdk_schema_org_vars = variable_get('bibdk_schema_org_vars', array());

  $typeof_property = ( empty($form_state['values']['bibdk_schemaorg_field_typeof']) ) ? '' : $form_state['values']['bibdk_schemaorg_field_typeof_property'];

  $bibdk_schema_org_vars[$field_name]['property']        = $form_state['values']['bibdk_schemaorg_field_property'];
  $bibdk_schema_org_vars[$field_name]['typeof']          = $form_state['values']['bibdk_schemaorg_field_typeof'];
  $bibdk_schema_org_vars[$field_name]['typeof_property'] = $typeof_property;

  variable_set('bibdk_schema_org_vars', $bibdk_schema_org_vars);

}

/**
 * Validation function for edit field form.
 */
function bibdk_schemaorg_field_ui_field_edit_form_validate($form, &$form_state) {

  if (!empty($form_state['values']['bibdk_schemaorg_field_typeof']) && empty($form_state['values']['bibdk_schemaorg_field_typeof_property'])) {
    $error_msg = t('Data type property must be set if Schema.org data type is not text or an integer', array(), array('context' => 'bibdk_schemaorg'));
    form_set_error('bibdk_schemaorg_field_typeof_property', $error_msg);
  }

}
