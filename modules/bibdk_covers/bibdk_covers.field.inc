<?php

/**
 * @file
 * Field hook implementations.
 */


/**
 * Implements hook_field_formatter_info().
 */
function bibdk_covers_field_formatter_info() {
  return array(
    'bibdk_cover_work' => array(
      'label' => t('Default'),
      'field types' => array('bibdk_cover_work'),
      'settings' => array(
        'image_style' => 'medium',
      ),
    ),
  );
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function bibdk_covers_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $image_styles = image_style_options(FALSE);
  $element['image_style'] = array(
    '#title' => t('Image style'),
    '#type' => 'select',
    '#default_value' => $settings['image_style'],
    '#empty_option' => t('None (original image)'),
    '#options' => $image_styles,
  );

  return $element;
}

/**
 * Implements hook_field_formatter_settings_summary().
 */
function bibdk_covers_field_formatter_settings_summary($field, $instance, $view_mode) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $image_styles = image_style_options(FALSE);
  // Unset possible 'No defined styles' option.
  unset($image_styles['']);
  // Styles could be lost because of enabled/disabled modules that defines their styles in code.
  if (isset($image_styles[$settings['image_style']])) {
    $summary = t('Image style: @style', array('@style' => $image_styles[$settings['image_style']]));
  }
  else {
    $summary = t('Original image');
  }
  return $summary;
}

/**
 * Implements hook_field_formatter_view().
 */
function bibdk_covers_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();
  foreach ($items as $delta => $item) {
    $element[$delta] = array(
      '#theme' => 'bibdk_object_cover',
      '#object' => $entity,
      '#image_style' => $display['settings']['image_style'],
      '#attached' => array(
        'js' => array(drupal_get_path('module', 'bibdk_covers') . '/js/bibdk-object-covers.js'),
      ),
    );
  }
  return $element;
}
