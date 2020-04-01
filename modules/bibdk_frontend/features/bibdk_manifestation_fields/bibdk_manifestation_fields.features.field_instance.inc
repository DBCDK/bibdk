<?php

/**
 * @file
 * bibdk_manifestation_fields.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bibdk_manifestation_fields_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_access_information'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_access_information'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 33,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 29,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 41,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 37,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 41,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 33,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_access_information',
    'label' => 'Access Information',
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
      'weight' => 33,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_access_met'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_access_met'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 58,
      ),
      'email' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 48,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 46,
      ),
      'print' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 48,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 60,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_access_met',
    'label' => 'Access methods',
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
      'weight' => 62,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_acquisition_info'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_acquisition_info'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 63,
      ),
      'email' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 48,
      ),
      'print' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 64,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_acquisition_info',
    'label' => 'Acquisition',
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
      'weight' => 67,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_actor_note'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_actor_note'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 31,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 21,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 27,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 24,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 27,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_actor_note',
    'label' => 'Actor Note',
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
      'weight' => 25,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_alt_title'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_alt_title'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 48,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 6,
      ),
      'email' => array(
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
        'weight' => 4,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 3,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_alt_title',
    'label' => 'Alternative title',
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
      'weight' => 10,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_analytic_content'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_analytic_content'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 45,
      ),
      'email' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 45,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 40,
      ),
      'print' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 45,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 52,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_analytic_content',
    'label' => 'Analytic Content',
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
      'weight' => 52,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_audience_subjects'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_audience_subjects'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 44,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 17,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 18,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 15,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 18,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_audience_subjects',
    'label' => 'Audience Subjects',
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
      'weight' => 21,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_common_contributors'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_common_contributors'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 60,
      ),
      'email' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 42,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 3,
      ),
      'print' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 42,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 62,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_common_contributors',
    'label' => 'Common contributors',
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
      'weight' => 64,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_content_note'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_content_note'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 35,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 40,
      ),
      'email' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 53,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 38,
      ),
      'print' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 55,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 44,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_content_note',
    'label' => 'Content Note',
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
      'weight' => 44,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_content_partial_note'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_content_partial_note'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 36,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 41,
      ),
      'email' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 56,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 39,
      ),
      'print' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 54,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 45,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_content_partial_note',
    'label' => 'Content Partial Note',
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
      'weight' => 45,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_content_title'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_content_title'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 55,
      ),
      'email' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 47,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 43,
      ),
      'print' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 50,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 57,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_content_title',
    'label' => 'Content Title',
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
      'weight' => 59,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_context'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_context'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 25,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 25,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 22,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 25,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_context',
    'label' => 'Context',
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
      'weight' => 29,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_contribs'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_contribs'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 55,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 7,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 6,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 5,
      ),
      'print' => array(
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
        'weight' => 11,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_contribs',
    'label' => 'Contributors',
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
      'weight' => 11,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_creators'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_creators'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 1,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 3,
      ),
      'email' => array(
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
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 4,
      ),
      'reservation' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_creators',
    'label' => 'Creators',
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
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_database_ref'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_database_ref'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 57,
      ),
      'email' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 50,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 45,
      ),
      'print' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 47,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 59,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_database_ref',
    'label' => 'Database references',
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
      'weight' => 61,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_debates'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_debates'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 61,
      ),
      'email' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 47,
      ),
      'print' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 63,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_debates',
    'label' => 'Debates',
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
      'weight' => 65,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_description_note'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_description_note'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 22,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 31,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 28,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 31,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 26,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_description_note',
    'label' => 'Description Note',
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
      'weight' => 26,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_distinction'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_distinction'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 44,
      ),
      'email' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 43,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 52,
      ),
      'print' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 43,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 51,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_distinction',
    'label' => 'Distinction',
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
      'weight' => 51,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_edition'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_edition'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 28,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 32,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 9,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 8,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 9,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 36,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_edition',
    'label' => 'Edition',
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
      'weight' => 36,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_format'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_format'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 57,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 9,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 13,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 12,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 13,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_format',
    'label' => 'Format',
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
      'weight' => 13,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_forms'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_forms'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 56,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 8,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 22,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 19,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 22,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_forms',
    'label' => 'Forms',
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
      'weight' => 12,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_genre'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_genre'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 52,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 16,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 23,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 20,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 23,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 20,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_genre',
    'label' => 'Genre',
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
      'weight' => 20,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_host_pub'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_host_pub'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 41,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 34,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 12,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 11,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 12,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 38,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_host_pub',
    'label' => 'Host Publication',
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
      'weight' => 38,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_identifiers'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_identifiers'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 26,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 34,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 31,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 34,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_identifiers',
    'label' => 'Identifiers',
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
      'weight' => 30,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_identifiers_isbn'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_identifiers_isbn'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 42,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 37,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 36,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 32,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 35,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 41,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_identifiers_isbn',
    'label' => 'Identifiers ISBN',
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
      'weight' => 41,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_identifiers_ismn'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_identifiers_ismn'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 38,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 38,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 37,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 34,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 37,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 42,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_identifiers_ismn',
    'label' => 'Identifiers ISMN',
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
      'weight' => 42,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_identifiers_issn'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_identifiers_issn'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 37,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 39,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 35,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 33,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 36,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 43,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_identifiers_issn',
    'label' => 'Identifiers ISSN',
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
      'weight' => 43,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_infotext'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_infotext'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 59,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 35,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 40,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 36,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 40,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 39,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_infotext',
    'label' => 'Info text',
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
      'weight' => 39,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_language'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_language'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 26,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 28,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 7,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 6,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 7,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_language',
    'label' => 'Language',
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
      'weight' => 32,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_marked_audience'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_marked_audience'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 43,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 18,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 30,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 27,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 30,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_marked_audience',
    'label' => 'Marked Audience',
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
      'weight' => 22,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_orig_title'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_orig_title'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 47,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 5,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 32,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 29,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 32,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_orig_title',
    'label' => 'Original title',
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
      'weight' => 9,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_originals'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_originals'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 24,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 33,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 30,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 33,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 28,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_originals',
    'label' => 'Originals',
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
      'weight' => 28,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_pegi'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_pegi'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 45,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 36,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 29,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 26,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 29,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 40,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_pegi',
    'label' => 'Audience Pegi',
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
      'weight' => 40,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_price_information'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_price_information'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 27,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 39,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 53,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 39,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 31,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_price_information',
    'label' => 'Price Information',
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
      'weight' => 31,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_pub_format'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_pub_format'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 34,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 33,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 11,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 10,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 11,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 37,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_pub_format',
    'label' => 'Publication Format',
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
      'weight' => 37,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_pub_year'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_pub_year'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 40,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 31,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 10,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 9,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 10,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 35,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_pub_year',
    'label' => 'Publication Year',
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
      'weight' => 35,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_publisher'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_publisher'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 39,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 30,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 8,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 7,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 8,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 34,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_publisher',
    'label' => 'Publisher',
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
      'weight' => 34,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_readability_indexes'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_readability_indexes'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 53,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 12,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 20,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 17,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 20,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_readability_indexes',
    'label' => 'Readability indexes',
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
      'weight' => 16,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_readability_numbers'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_readability_numbers'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 49,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 13,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 21,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 18,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 21,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_readability_numbers',
    'label' => 'Readability numbers',
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
      'weight' => 17,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_recommended_audience'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_recommended_audience'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 19,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 28,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 25,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 28,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_recommended_audience',
    'label' => 'Recommended Audience',
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
      'weight' => 23,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_references'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_references'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 23,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 24,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 21,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 24,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_references',
    'label' => 'References',
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
      'weight' => 27,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_related_series'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_related_series'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 54,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 11,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 17,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 14,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 17,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_related_series',
    'label' => 'Related series',
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
      'weight' => 15,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_section'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_section'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 50,
      ),
      'email' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 44,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 41,
      ),
      'print' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 44,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_section',
    'label' => 'Section',
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
      'weight' => 54,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_series'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_series'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 58,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 10,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 16,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 13,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 16,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_series',
    'label' => 'Series',
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
      'weight' => 14,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_shelf'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_shelf'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 50,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 14,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 38,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 35,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 38,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_shelf',
    'label' => 'Shelf',
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
      'weight' => 18,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_system_demand'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_system_demand'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 56,
      ),
      'email' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 51,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 44,
      ),
      'print' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 51,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 58,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_system_demand',
    'label' => 'System demands',
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
      'weight' => 60,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_text_levels'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_text_levels'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 51,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 15,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 19,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 16,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 19,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 19,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_text_levels',
    'label' => 'Text Levels',
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
      'weight' => 19,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_title'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_title'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 2,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 1,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 50,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 1,
      ),
      'reservation' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_title',
    'label' => 'Title',
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
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_title_specific'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_title_specific'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'hidden',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 54,
      ),
      'email' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 46,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 0,
      ),
      'print' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 46,
      ),
      'reservation' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 56,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_title_specific',
    'label' => 'Title Specific',
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
      'weight' => 58,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_tracks'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_tracks'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 65,
      ),
      'email' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 49,
      ),
      'print' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 65,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_tracks',
    'label' => 'Tracks',
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
      'weight' => 69,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_type'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_type'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'hidden',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 2,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 59,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 0,
      ),
      'reservation' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_type',
    'label' => 'Manifestation type',
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
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_used_language'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_used_language'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 20,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 26,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 23,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 26,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_used_language',
    'label' => 'Used Language',
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
      'weight' => 24,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-bibdk_mani_volume'.
  $field_instances['bibdkManifestation-bibdkManifestation-bibdk_mani_volume'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 51,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 5,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 42,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 5,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'bibdk_mani_volume',
    'label' => 'Volume',
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
      'weight' => 55,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-ting_openformat_mani_lk_subjects'.
  $field_instances['bibdkManifestation-bibdkManifestation-ting_openformat_mani_lk_subjects'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 67,
      ),
      'email' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 63,
      ),
      'print' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 66,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'ting_openformat_mani_lk_subjects',
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
      'weight' => 71,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestation-bibdkManifestation-ting_openformat_mani_subjects'.
  $field_instances['bibdkManifestation-bibdkManifestation-ting_openformat_mani_subjects'] = array(
    'bundle' => 'bibdkManifestation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestation',
    'display' => array(
      'cart' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 43,
      ),
      'email' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 14,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 53,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 14,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 49,
      ),
    ),
    'entity_type' => 'bibdkManifestation',
    'field_name' => 'ting_openformat_mani_subjects',
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
      'weight' => 49,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_access_information'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_access_information'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 26,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 24,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_access_information',
    'label' => 'Access Information',
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
      'weight' => 26,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_acquisition_info'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_acquisition_info'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 40,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 40,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 40,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_acquisition_info',
    'label' => 'Acquisition',
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
      'weight' => 40,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_actor_note'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_actor_note'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 18,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 16,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_actor_note',
    'label' => 'Actor Note',
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
      'weight' => 18,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_alt_title'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_alt_title'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 3,
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
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_alt_title',
    'label' => 'Alternative title',
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
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_analytic_content'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_analytic_content'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 38,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 38,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 38,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_analytic_content',
    'label' => 'Analytic Content',
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
      'weight' => 38,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_audience_subjects'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_audience_subjects'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 14,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 12,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_audience_subjects',
    'label' => 'Audience Subjects',
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
      'weight' => 14,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_common_contributors'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_common_contributors'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 39,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 39,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 39,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_common_contributors',
    'label' => 'Common contributors',
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
      'weight' => 39,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_content_note'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_content_note'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 36,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 36,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 36,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_content_note',
    'label' => 'Content Note',
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
      'weight' => 36,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_content_partial_note'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_content_partial_note'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 37,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 37,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 37,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_content_partial_note',
    'label' => 'Content Partial Note',
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
      'weight' => 37,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_context'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_context'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 22,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 20,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 20,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_context',
    'label' => 'Context',
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
      'weight' => 22,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_contribs'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_contribs'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
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
        'weight' => 2,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_contribs',
    'label' => 'Contributors',
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
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_description_note'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_description_note'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 19,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 17,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_description_note',
    'label' => 'Description Note',
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
      'weight' => 19,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_edition'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_edition'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 29,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 27,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_edition',
    'label' => 'Edition',
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
      'weight' => 29,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_format'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_format'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 6,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 4,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_format',
    'label' => 'Format',
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
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_forms'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_forms'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 5,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 3,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_forms',
    'label' => 'Forms',
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
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_genre'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_genre'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 13,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 11,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_genre',
    'label' => 'Genre',
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
      'weight' => 13,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_host_pub'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_host_pub'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 31,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 29,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_host_pub',
    'label' => 'Host Publication',
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
      'weight' => 31,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_identifiers'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_identifiers'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 23,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 21,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_identifiers',
    'label' => 'Identifiers',
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
      'weight' => 23,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_identifiers_isbn'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_identifiers_isbn'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 33,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 33,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 33,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_identifiers_isbn',
    'label' => 'Identifiers ISBN',
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
      'weight' => 33,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_identifiers_ismn'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_identifiers_ismn'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 34,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 34,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 34,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_identifiers_ismn',
    'label' => 'Identifiers ISMN',
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
      'weight' => 34,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_identifiers_issn'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_identifiers_issn'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 35,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 35,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 35,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_identifiers_issn',
    'label' => 'Identifiers ISSN',
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
      'weight' => 35,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_language'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_language'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 25,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 23,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_language',
    'label' => 'Language',
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
      'weight' => 25,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_marked_audience'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_marked_audience'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 15,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 13,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_marked_audience',
    'label' => 'Marked Audience',
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
      'weight' => 15,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_orig_title'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_orig_title'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
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
        'weight' => 0,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_orig_title',
    'label' => 'Original title',
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

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_originals'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_originals'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 21,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 19,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 19,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_originals',
    'label' => 'Originals',
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
      'weight' => 21,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_pegi'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_pegi'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 32,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 32,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_pegi',
    'label' => 'Audience Pegi',
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
      'weight' => 32,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_price_information'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_price_information'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 24,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 22,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_price_information',
    'label' => 'Price Information',
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
      'weight' => 24,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_pub_format'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_pub_format'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 30,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 28,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 28,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_pub_format',
    'label' => 'Publication Format',
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
      'weight' => 30,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_pub_year'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_pub_year'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 28,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 26,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 26,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_pub_year',
    'label' => 'Publication Year',
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
      'weight' => 28,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_publisher'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_publisher'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 27,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 25,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_publisher',
    'label' => 'Publisher',
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
      'weight' => 27,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_readability_indexes'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_readability_indexes'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 9,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 7,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_readability_indexes',
    'label' => 'Readability indexes',
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
      'weight' => 9,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_readability_numbers'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_readability_numbers'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 10,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 8,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_readability_numbers',
    'label' => 'Readability numbers',
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
      'weight' => 10,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_recommended_audience'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_recommended_audience'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 16,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 14,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_recommended_audience',
    'label' => 'Recommended Audience',
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
      'weight' => 16,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_references'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_references'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 20,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 18,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_references',
    'label' => 'References',
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
      'weight' => 20,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_related_series'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_related_series'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 8,
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
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_related_series',
    'label' => 'Related series',
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
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_series'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_series'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 7,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 5,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_series',
    'label' => 'Series',
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
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_shelf'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_shelf'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 11,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 9,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_shelf',
    'label' => 'Shelf',
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
      'weight' => 11,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_text_levels'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_text_levels'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 12,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 10,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_text_levels',
    'label' => 'Text Levels',
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
      'weight' => 12,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_tracks'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_tracks'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 41,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 41,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 41,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_tracks',
    'label' => 'Tracks',
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
      'weight' => 41,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_used_language'.
  $field_instances['bibdkManifestationSection-bibdkManifestationSection-bibdk_mani_used_language'] = array(
    'bundle' => 'bibdkManifestationSection',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationSection',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 17,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 15,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
    ),
    'entity_type' => 'bibdkManifestationSection',
    'field_name' => 'bibdk_mani_used_language',
    'label' => 'Used Language',
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
      'weight' => 17,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_access_information'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_access_information'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 26,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 24,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_access_information',
    'label' => 'Access Information',
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
      'weight' => 26,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_acquisition_info'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_acquisition_info'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 41,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 41,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 41,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_acquisition_info',
    'label' => 'Acquisition',
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
      'weight' => 41,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_actor_note'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_actor_note'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 18,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 16,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_actor_note',
    'label' => 'Actor Note',
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
      'weight' => 18,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_alt_title'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_alt_title'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 3,
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
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_alt_title',
    'label' => 'Alternative title',
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
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_analytic_content'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_analytic_content'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 39,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 38,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 38,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_analytic_content',
    'label' => 'Analytic Content',
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
      'weight' => 38,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_audience_subjects'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_audience_subjects'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 14,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 12,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_audience_subjects',
    'label' => 'Audience Subjects',
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
      'weight' => 14,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_common_contributors'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_common_contributors'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 40,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 40,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 40,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_common_contributors',
    'label' => 'Common contributors',
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
      'weight' => 40,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_content_note'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_content_note'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 37,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 36,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 36,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_content_note',
    'label' => 'Content Note',
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
      'weight' => 36,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_content_partial_note'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_content_partial_note'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 38,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 37,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 37,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_content_partial_note',
    'label' => 'Content Partial Note',
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
      'weight' => 37,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_context'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_context'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 22,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 20,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 20,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_context',
    'label' => 'Context',
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
      'weight' => 22,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_contribs'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_contribs'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
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
        'weight' => 2,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_contribs',
    'label' => 'Contributors',
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
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_description_note'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_description_note'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 19,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 17,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_description_note',
    'label' => 'Description Note',
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
      'weight' => 19,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_edition'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_edition'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 30,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 27,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_edition',
    'label' => 'Edition',
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
      'weight' => 29,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_format'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_format'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 6,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 4,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_format',
    'label' => 'Format',
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
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_forms'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_forms'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 5,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 3,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_forms',
    'label' => 'Forms',
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
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_genre'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_genre'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 13,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 11,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_genre',
    'label' => 'Genre',
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
      'weight' => 13,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_host_pub'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_host_pub'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 32,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 29,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_host_pub',
    'label' => 'Host Publication',
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
      'weight' => 31,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_identifiers'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_identifiers'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 23,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 21,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_identifiers',
    'label' => 'Identifiers',
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
      'weight' => 23,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_identifiers_isbn'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_identifiers_isbn'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 34,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 33,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 33,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_identifiers_isbn',
    'label' => 'Identifiers ISBN',
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
      'weight' => 33,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_identifiers_ismn'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_identifiers_ismn'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 35,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 34,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 34,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_identifiers_ismn',
    'label' => 'Identifiers ISMN',
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
      'weight' => 34,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_identifiers_issn'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_identifiers_issn'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 36,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 35,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 35,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_identifiers_issn',
    'label' => 'Identifiers ISSN',
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
      'weight' => 35,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_language'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_language'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 25,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 23,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_language',
    'label' => 'Language',
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
      'weight' => 25,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_marked_audience'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_marked_audience'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 15,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 13,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_marked_audience',
    'label' => 'Marked Audience',
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
      'weight' => 15,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_orig_title'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_orig_title'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
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
        'weight' => 0,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_orig_title',
    'label' => 'Original title',
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

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_originals'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_originals'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 21,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 19,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 19,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_originals',
    'label' => 'Originals',
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
      'weight' => 21,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_pegi'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_pegi'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 33,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 32,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_pegi',
    'label' => 'Audience Pegi',
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
      'weight' => 32,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_price_information'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_price_information'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 22,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_price_information',
    'label' => 'Price Information',
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
      'weight' => 24,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_pub_format'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_pub_format'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 31,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 28,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 28,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_pub_format',
    'label' => 'Publication Format',
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
      'weight' => 30,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_pub_year'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_pub_year'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 28,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 26,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 26,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_pub_year',
    'label' => 'Publication Year',
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
      'weight' => 28,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_publisher'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_publisher'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 27,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 25,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_publisher',
    'label' => 'Publisher',
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
      'weight' => 27,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_readability_indexes'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_readability_indexes'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 9,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 7,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_readability_indexes',
    'label' => 'Readability indexes',
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
      'weight' => 9,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_readability_numbers'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_readability_numbers'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 10,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 8,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_readability_numbers',
    'label' => 'Readability numbers',
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
      'weight' => 10,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_recommended_audience'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_recommended_audience'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 16,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 14,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_recommended_audience',
    'label' => 'Recommended Audience',
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
      'weight' => 16,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_references'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_references'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 20,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 18,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_references',
    'label' => 'References',
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
      'weight' => 20,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_related_series'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_related_series'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 8,
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
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_related_series',
    'label' => 'Related series',
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
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_series'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_series'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 7,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 5,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_series',
    'label' => 'Series',
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
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_shelf'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_shelf'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 11,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 9,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_shelf',
    'label' => 'Shelf',
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
      'weight' => 11,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_text_levels'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_text_levels'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 12,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 10,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_text_levels',
    'label' => 'Text Levels',
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
      'weight' => 12,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_tracks'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_tracks'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 42,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 42,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 42,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_tracks',
    'label' => 'Tracks',
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
      'weight' => 42,
    ),
  );

  // Exported field_instance:
  // 'bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_used_language'.
  $field_instances['bibdkManifestationVolume-bibdkManifestationVolume-bibdk_mani_used_language'] = array(
    'bundle' => 'bibdkManifestationVolume',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'ding_entity_type' => 'bibdkManifestationVolume',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 17,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'ting_openformat',
        'settings' => array(),
        'type' => 'ting_openformat_default_formatter',
        'weight' => 15,
      ),
      'reservation' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
    ),
    'entity_type' => 'bibdkManifestationVolume',
    'field_name' => 'bibdk_mani_used_language',
    'label' => 'Used Language',
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
      'weight' => 17,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Access Information');
  t('Access methods');
  t('Acquisition');
  t('Actor Note');
  t('Alternative title');
  t('Analytic Content');
  t('Audience Pegi');
  t('Audience Subjects');
  t('Common contributors');
  t('Content Note');
  t('Content Partial Note');
  t('Content Title');
  t('Context');
  t('Contributors');
  t('Creators');
  t('Database references');
  t('Debates');
  t('Description Note');
  t('Distinction');
  t('Edition');
  t('Format');
  t('Forms');
  t('Genre');
  t('Host Publication');
  t('Identifiers');
  t('Identifiers ISBN');
  t('Identifiers ISMN');
  t('Identifiers ISSN');
  t('Info text');
  t('Language');
  t('Manifestation type');
  t('Marked Audience');
  t('Original title');
  t('Originals');
  t('Price Information');
  t('Publication Format');
  t('Publication Year');
  t('Publisher');
  t('Readability indexes');
  t('Readability numbers');
  t('Recommended Audience');
  t('References');
  t('Related series');
  t('Section');
  t('Series');
  t('Shelf');
  t('System demands');
  t('Text Levels');
  t('Title');
  t('Title Specific');
  t('Tracks');
  t('Used Language');
  t('Volume');
  t('Work Laesekompas subjects');
  t('Work subjects');

  return $field_instances;
}
