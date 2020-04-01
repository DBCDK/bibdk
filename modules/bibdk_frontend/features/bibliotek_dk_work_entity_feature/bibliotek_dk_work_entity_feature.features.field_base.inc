<?php

/**
 * @file
 * bibliotek_dk_work_entity_feature.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function bibliotek_dk_work_entity_feature_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'bibdk_cover_work'.
  $field_bases['bibdk_cover_work'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_cover_work',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'bibdk_covers_field',
    'settings' => array(),
    'storage' => array(
      'active' => 1,
      'module' => 'virtual_field',
      'settings' => array(),
      'type' => 'virtual_field',
    ),
    'translatable' => 0,
    'type' => 'bibdk_cover_work',
  );

  // Exported field_base: 'ting_openformat_work_abstract'.
  $field_bases['ting_openformat_work_abstract'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'ting_openformat_work_abstract',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'ting_openformat',
    'settings' => array(),
    'storage' => array(
      'active' => 1,
      'module' => 'virtual_field',
      'settings' => array(),
      'type' => 'virtual_field',
    ),
    'translatable' => 0,
    'type' => 'ting_openformat_work_abstract',
  );

  // Exported field_base: 'ting_openformat_work_lk_subjects'.
  $field_bases['ting_openformat_work_lk_subjects'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'ting_openformat_work_lk_subjects',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'ting_openformat',
    'settings' => array(),
    'storage' => array(
      'active' => 1,
      'module' => 'virtual_field',
      'settings' => array(),
      'type' => 'virtual_field',
    ),
    'translatable' => 0,
    'type' => 'ting_openformat_work_lk_subjects',
  );

  // Exported field_base: 'ting_openformat_work_subjects'.
  $field_bases['ting_openformat_work_subjects'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'ting_openformat_work_subjects',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'ting_openformat',
    'settings' => array(),
    'storage' => array(
      'active' => 1,
      'module' => 'virtual_field',
      'settings' => array(),
      'type' => 'virtual_field',
    ),
    'translatable' => 0,
    'type' => 'ting_openformat_work_subjects',
  );

  // Exported field_base: 'worktabs'.
  $field_bases['worktabs'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'worktabs',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'worktabs',
    'settings' => array(),
    'storage' => array(
      'active' => 1,
      'module' => 'virtual_field',
      'settings' => array(),
      'type' => 'virtual_field',
    ),
    'translatable' => 0,
    'type' => 'worktabs',
  );

  return $field_bases;
}
