<?php
/**
 * @file
 * bibliotek_dk_work_entity_feature.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function bibliotek_dk_work_entity_feature_field_default_fields() {
  $fields = array();

  // Exported field: 'bibdkWorkEntity-bibdkWorkEntity-bibdk_cover_work'.
  $fields['bibdkWorkEntity-bibdkWorkEntity-bibdk_cover_work'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'bibdk_cover_work',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'bibdk_covers_field',
      'settings' => array(),
      'storage' => array(
        'active' => '1',
        'module' => 'virtual_field',
        'settings' => array(),
        'type' => 'virtual_field',
      ),
      'translatable' => '0',
      'type' => 'bibdk_cover_work',
    ),
    'field_instance' => array(
      'bundle' => 'bibdkWorkEntity',
      'default_value' => NULL,
      'deleted' => '0',
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
          'weight' => '0',
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
    ),
  );

  // Exported field: 'bibdkWorkEntity-bibdkWorkEntity-ting_openformat_work_abstract'.
  $fields['bibdkWorkEntity-bibdkWorkEntity-ting_openformat_work_abstract'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'ting_openformat_work_abstract',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'ting_openformat',
      'settings' => array(),
      'storage' => array(
        'active' => '1',
        'module' => 'virtual_field',
        'settings' => array(),
        'type' => 'virtual_field',
      ),
      'translatable' => '0',
      'type' => 'ting_openformat_work_abstract',
    ),
    'field_instance' => array(
      'bundle' => 'bibdkWorkEntity',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'ding_entity_type' => 'bibdkWorkEntity',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'ting_openformat',
          'settings' => array(),
          'type' => 'ting_openformat_default_formatter',
          'weight' => '1',
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
    ),
  );

  // Exported field: 'bibdkWorkEntity-bibdkWorkEntity-ting_openformat_work_subjects'.
  $fields['bibdkWorkEntity-bibdkWorkEntity-ting_openformat_work_subjects'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'ting_openformat_work_subjects',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'ting_openformat',
      'settings' => array(),
      'storage' => array(
        'active' => '1',
        'module' => 'virtual_field',
        'settings' => array(),
        'type' => 'virtual_field',
      ),
      'translatable' => '0',
      'type' => 'ting_openformat_work_subjects',
    ),
    'field_instance' => array(
      'bundle' => 'bibdkWorkEntity',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'ding_entity_type' => 'bibdkWorkEntity',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'ting_openformat',
          'settings' => array(),
          'type' => 'ting_openformat_default_formatter',
          'weight' => '2',
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
    ),
  );

  // Exported field: 'bibdkWorkEntity-bibdkWorkEntity-worktabs'.
  $fields['bibdkWorkEntity-bibdkWorkEntity-worktabs'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'worktabs',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'worktabs',
      'settings' => array(),
      'storage' => array(
        'active' => '1',
        'module' => 'virtual_field',
        'settings' => array(),
        'type' => 'virtual_field',
      ),
      'translatable' => '0',
      'type' => 'worktabs',
    ),
    'field_instance' => array(
      'bundle' => 'bibdkWorkEntity',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'ding_entity_type' => 'bibdkWorkEntity',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'worktabs',
          'settings' => array(),
          'type' => 'worktabs_default',
          'weight' => '3',
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
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Cover image');
  t('Work abstract');
  t('Work subjects');
  t('Worktabs');

  return $fields;
}
