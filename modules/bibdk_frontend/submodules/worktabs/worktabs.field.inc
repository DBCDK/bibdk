<?php

/**
 * Implements hook_field_info().
 */
function worktabs_field_info() {
  return array(
    'worktabs' => array(
      'label' => t('Worktabs'),
      'description' => t('Displays tabs such as subjects, find more and reviews'),
      'default_widget' => 'hidden',
      'default_formatter' => 'worktabs_default',
      'no_ui' => TRUE,
    ),
  );
}

/**
 * Implements hook_field_formatter_info().
 */
function worktabs_field_formatter_info() {
  return array(
    'worktabs_default' => array(
      'label' => t('Default'),
      'field types' => array(
        'worktabs',
      ),
    )
  );
}

/**
 * Implements hook_field_load()
 */
function worktabs_field_load($entity_type, $entities, $field, $instances, $langcode, &$items, $age) {
  foreach ($entities as $id => $entity) {
    $items[$id][0] = array(
      'id' => $id,
    );
  }
}

/**
 * Implements hook_field_formatter_view().
 *
 * @param String    $entity_type
 * @param BibdkWork $entity
 * @param array     $field
 * @param array     $instance
 * @param String    $langcode
 * @param array     $items
 * @param array     $display
 * @return array
 */
function worktabs_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();
  if ($entity) {
    $element[] = worktabs_get_tabs($entity);
  }

  return $element;
}
