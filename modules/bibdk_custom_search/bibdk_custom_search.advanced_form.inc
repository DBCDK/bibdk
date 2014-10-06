<?php

/** Generates the form for advanced search pages.
 *
 * @param $elements
 * @param $current_page
 * @param $default_values
 * @param $extended_fields
 */
function _bibdk_custom_search_create_advanced_form($elements, $current_page, $default_values) {
  $fields = array();

  // We loop through all search elements
  foreach ($elements as $element) {

    if (empty($element->search_code)) {
      $element->search_code = 'n/a' . strtolower($element->element_label);
    }
    $element->value = urlencode($element->value);

    /* GROUPS */
    $group = strtolower($element->element_label);

    _bibdk_custom_search_translate_element($element);

    /* REGIONS */
    $region = $element->region;
    if (!isset($fields[$region]) && $region != 'main') {
      $fields[$region] = array(
        '#type' => 'fieldset',
        '#title' => t('Advanced search'),
        '#collapsible' => TRUE,
        '#collapsed' => ($current_page['expand']) ? $current_page['expand'] : FALSE,
        '#weight' => 102,
      );
    }

    // we add a subgroup because elements can have matching searchcodes
    $subgroup = $element->e_uuid;

    if (!isset($fields[$region][$group][$subgroup])) {
      $fields[$region][$group][$subgroup] = array(
        '#type' => 'fieldset',
        '#collapsible' => FALSE,
        '#collapsed' => FALSE,
        '#tree' => FALSE,
        '#theme' => 'bibdk_search_element',
        '#element_id' => drupal_html_id('input ' . $element->element_label),
        '#element_title' => $element->element_label,
        '#title_text' => $element->element_label,
        '#description_text' => $element->description,
        '#help_text' => $element->help_text,
        '#attributes' => array(
          'class' => array(_bibdk_custom_search_machine_readable($group), 'element-wrapper'),
        ),
      );
    }
    /* VALUES */
    _bibdk_custom_search_add_element($element, $fields[$region][$group][$subgroup], $default_values);

  }
  return $fields;
}

/** Translate element values
 *
 * @param $element
 */
function _bibdk_custom_search_translate_element(&$element) {
  // Translate all labels, descriptions and help-texts
  $element->element_label = bibdk_custom_search_translate($element->element_label, 'element_label');
  $element->description = bibdk_custom_search_translate($element->description, 'description');
  $element->help_text = bibdk_custom_search_translate($element->help_text, 'help_text');
  $element->label = bibdk_custom_search_translate($element->label, 'label');
}


/** Add single field to fields array
 *
 * @param $element
 * @param $field
 * @param $default_values
 */
function _bibdk_custom_search_add_element($element, &$field, &$default_values ) {
  $value = str_replace('.', '_', $element->search_code);
  if (!isset($field[$value])) {
    $field[$value] = array(
      '#id' => $field['#element_id'],
      '#type' => $element->value_type,
      '#title' => $field['#element_title'],
      '#title_display' => 'attribute',
      '#disabled' => $element->is_disabled || $element->value_disabled,
      '#attributes' => array(
        'tabindex' => $element->tab_index,
        'accesskey' => $element->access_key,
        'data-term' => array($value),
      ),
    );
  }

  // Add type specific settings for values
  switch ($element->value_type) {
    CASE 'textarea':
      $field[$value]['#size'] = 30;
    CASE 'textfield':
      $field[$value]['#maxlength'] = 64;
      $field[$value]['#default_value'] = isset($default_values[$value]) ? array_shift($default_values[$value]) : NULL;
      $field[$value]['#parents'] = array($value, $element->value_title);
      $field[$value]['#tree'] = FALSE;
      break;
    CASE 'select':

      $field[$value]['#default_value'] = isset($default_values[$value]) ? $default_values[$value] : $element->default_value;
      if (!$element->option_disabled) {
        $field[$value]['#options'][$element->value] = $element->label;
      }
      break;
    CASE 'radios':
      $field[$value]['#theme'] = 'bibdk_custom_search_radio_buttons';
      $field[$value]['#default_value'] = isset($default_values[$element->search_code]) ? $default_values[$element->search_code] : $element->default_value;
      if (!$element->option_disabled) {
        $field[$value]['#options'][$element->value] = $element->label;
      }
      if ( $element->expand ) {
        // this element have a sub-group
        $options = _bibdk_custom_search_get_options_db_raw($element->expand);
        if ( !empty($options) ) {
          foreach ($options as $option) {
            $field[$value]['#options'][$option->value] = bibdk_custom_search_translate($option->label, 'label');
          }
        }

        // add info for hide/show sub-group
        reset($options);
        $first = current($options);
        $last  = end($options);
        $data_toggle['options']['first']['value'] = $first->value;
        $data_toggle['options']['first']['label'] = $first->label;
        $data_toggle['options']['last']['value'] = $last->value;
        $data_toggle['options']['last']['label'] = $last->label;
        $data_toggle['key'] = $element->value;

        $field[$value]['#data_toggle'][] = $data_toggle;
      }
      break;
    CASE 'checkboxes':
      $field[$value]['#type'] = 'container';
      $field[$value]['#tree'] = TRUE;
      $checkbox_values = isset($field[$value]['#values']) ? $field[$value]['#values'] : array();
      // If value includes a facet get a list of options
      if (strpos($element->value, 'facet.') !== FALSE) {
        $checkboxes = bibdk_custom_search_get_list_options($element->value, $element->search_code, $default_values);
        $field[$value] += $checkboxes;
      }
      else {
        $options = $element->expand ? _bibdk_custom_search_get_options_db_raw($element->expand) : array();
        $checkboxes = bibdk_custom_search_create_checkboxes($element, $default_values, $options);
        $field[$value] += $checkboxes['elements'];
        $field[$value]['#values'] = array_merge((array)$checkbox_values, $checkboxes['values']);
      }
      break;
    DEFAULT:
      break;
  }

}

/** Generate checkboxes for advanced search elements. Function works recursively
 * if a checkbox is expanded and has subelements
 *
 * @param $element
 * @param $default_values
 * @param array $options
 * @return array
 */
function bibdk_custom_search_create_checkboxes($element, &$default_values, $options = array()) {
  $parent = str_replace('.', '_', $element->search_code);

  // Get default values
  $default = ($element->default_value == $element->value) ? $element->default_value : NULL;
  if (isset($default_values[$parent][$element->value])){
    $default = $element->value;
    unset($default_values[$element->search_code][$element->value]);
  }
  // Create checkbox
  $return = array();
  $return[$element->value] = array(
    '#type' => 'checkbox',
    '#default_value' => $default,
    '#disabled' => ($element->is_disabled || $element->option_disabled) ? TRUE : FALSE,
    '#title' => $element->label,
    '#return_value' => $element->value,
    '#parents' => array($parent, $element->value),
    '#attributes' => array(
      'data-group' => $parent,
      'class' => array(($element->default_value == $element->value) ? 'default-value' : ''),
    ),
  );

  $values = array($element->value);

  // Create nested checkbox options
  if ($element->expand) {
    $key = $element->value;
    $return[$element->value]['#attributes'] += array(
      'data-parent' => $parent,
    );
    $return[$element->value]['#title'] = '<span data-child="' . $key . '" class="toggle-subgroup"> + </span>' . $return[$element->value]['#title'];
    $return[$key . '-fieldset'] = array(
      '#type' => 'fieldset',
      '#attributes' => array(
        'data-child' => $key,
        'class' => array('sub-elements'),
      ),
      '#parents' => array($parent),
    );
    foreach ($options as $option) {
      $option->label = bibdk_custom_search_translate($option->label, 'label');
      if (empty($option->value)){
        continue;
      }
      $option = (object)array_merge((array)$element, (array)$option);
      $option_elements = bibdk_custom_search_create_checkboxes($option, $default_values);
      $return[$key . '-fieldset'] += $option_elements['elements'];
      $values = array_merge($values, $option_elements['values']);
    }
  }
  return array('elements' => $return, 'values' => $values);
}
