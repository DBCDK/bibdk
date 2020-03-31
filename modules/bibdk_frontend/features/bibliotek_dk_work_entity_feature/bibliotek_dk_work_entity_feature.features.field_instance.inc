<?php

/**
 * @file
 * bibliotek_dk_work_entity_feature.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bibliotek_dk_work_entity_feature_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'bibdkWorkEntity-bibdkWorkEntity-bibdk_cover_work'.
  $field_instances['bibdkWorkEntity-bibdkWorkEntity-bibdk_cover_work'] = array(
    'bundle' => 'bibdkWorkEntity',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkWorkEntity',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'bibdk_covers',
        'settings' => array(
          'image_style' => 'medium',
        ),
        'type' => 'bibdk_cover_work',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'bibdk_covers',
        'settings' => array(
          'image_style' => 'medium',
        ),
        'type' => 'bibdk_cover_work',
        'weight' => 0,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'bibdkWorkEntity',
    'field_name' => 'bibdk_cover_work',
    'label' => 'Cover image',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => NULL,
      'settings' => array(),
      'type' => 'default',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'bibdkWorkEntity-bibdkWorkEntity-ting_openformat_work_abstract'.
  $field_instances['bibdkWorkEntity-bibdkWorkEntity-ting_openformat_work_abstract'] = array(
    'bundle' => 'bibdkWorkEntity',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkWorkEntity',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 1,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 1,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'bibdkWorkEntity',
    'field_name' => 'ting_openformat_work_abstract',
    'label' => 'Work abstract',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'virtual_field',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'bibdkWorkEntity-bibdkWorkEntity-ting_openformat_work_lk_subjects'.
  $field_instances['bibdkWorkEntity-bibdkWorkEntity-ting_openformat_work_lk_subjects'] = array(
    'bundle' => 'bibdkWorkEntity',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkWorkEntity',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 4,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 6,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'bibdkWorkEntity',
    'field_name' => 'ting_openformat_work_lk_subjects',
    'label' => 'Work Laesekompas subjects',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'bibdkWorkEntity-bibdkWorkEntity-ting_openformat_work_subjects'.
  $field_instances['bibdkWorkEntity-bibdkWorkEntity-ting_openformat_work_subjects'] = array(
    'bundle' => 'bibdkWorkEntity',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkWorkEntity',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 2,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 2,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'bibdkWorkEntity',
    'field_name' => 'ting_openformat_work_subjects',
    'label' => 'Work subjects',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'bibdkWorkEntity-bibdkWorkEntity-worktabs'.
  $field_instances['bibdkWorkEntity-bibdkWorkEntity-worktabs'] = array(
    'bundle' => 'bibdkWorkEntity',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkWorkEntity',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'worktabs',
        'settings' => array(),
        'type' => 'worktabs_default',
        'weight' => 3,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'worktabs',
        'settings' => array(),
        'type' => 'worktabs_default',
        'weight' => 5,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'bibdkWorkEntity',
    'field_name' => 'worktabs',
    'label' => 'Worktabs',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'virtual_field',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 5,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Cover image');
  t('Work Laesekompas subjects');
  t('Work abstract');
  t('Work subjects');
  t('Worktabs');

  return $field_instances;
}
