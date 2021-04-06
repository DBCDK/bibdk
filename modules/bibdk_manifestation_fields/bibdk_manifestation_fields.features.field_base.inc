<?php

/**
 * @file
 * bibdk_manifestation_fields.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function bibdk_manifestation_fields_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'bibdk_mani_access_information'.
  $field_bases['bibdk_mani_access_information'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_access_information',
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
    'type' => 'bibdk_mani_access_information',
  );

  // Exported field_base: 'bibdk_mani_access_met'.
  $field_bases['bibdk_mani_access_met'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_access_met',
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
    'type' => 'bibdk_mani_access_met',
  );

  // Exported field_base: 'bibdk_mani_acquisition_info'.
  $field_bases['bibdk_mani_acquisition_info'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_acquisition_info',
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
    'type' => 'bibdk_mani_acquisition_info',
  );

  // Exported field_base: 'bibdk_mani_actor_note'.
  $field_bases['bibdk_mani_actor_note'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_actor_note',
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
    'type' => 'bibdk_mani_actor_note',
  );

  // Exported field_base: 'bibdk_mani_alt_title'.
  $field_bases['bibdk_mani_alt_title'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_alt_title',
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
    'type' => 'bibdk_mani_alt_title',
  );

  // Exported field_base: 'bibdk_mani_analytic_content'.
  $field_bases['bibdk_mani_analytic_content'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_analytic_content',
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
    'type' => 'bibdk_mani_analytic_content',
  );

  // Exported field_base: 'bibdk_mani_audience_subjects'.
  $field_bases['bibdk_mani_audience_subjects'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_audience_subjects',
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
    'type' => 'bibdk_mani_audience_subjects',
  );

  // Exported field_base: 'bibdk_mani_common_contributors'.
  $field_bases['bibdk_mani_common_contributors'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_common_contributors',
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
    'type' => 'bibdk_mani_common_contributors',
  );

  // Exported field_base: 'bibdk_mani_content_note'.
  $field_bases['bibdk_mani_content_note'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_content_note',
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
    'type' => 'bibdk_mani_content_note',
  );

  // Exported field_base: 'bibdk_mani_content_partial_note'.
  $field_bases['bibdk_mani_content_partial_note'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_content_partial_note',
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
    'type' => 'bibdk_mani_content_partial_note',
  );

  // Exported field_base: 'bibdk_mani_content_title'.
  $field_bases['bibdk_mani_content_title'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_content_title',
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
    'type' => 'bibdk_mani_content_title',
  );

  // Exported field_base: 'bibdk_mani_context'.
  $field_bases['bibdk_mani_context'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_context',
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
    'type' => 'bibdk_mani_context',
  );

  // Exported field_base: 'bibdk_mani_contribs'.
  $field_bases['bibdk_mani_contribs'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_contribs',
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
    'type' => 'bibdk_mani_contribs',
  );

  // Exported field_base: 'bibdk_mani_contribs_extra'.
  $field_bases['bibdk_mani_contribs_extra'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_contribs_extra',
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
    'type' => 'bibdk_mani_contribs_extra',
  );

  // Exported field_base: 'bibdk_mani_creators'.
  $field_bases['bibdk_mani_creators'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_creators',
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
    'type' => 'bibdk_mani_creators',
  );

  // Exported field_base: 'bibdk_mani_database_ref'.
  $field_bases['bibdk_mani_database_ref'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_database_ref',
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
    'type' => 'bibdk_mani_database_ref',
  );

  // Exported field_base: 'bibdk_mani_debates'.
  $field_bases['bibdk_mani_debates'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_debates',
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
    'type' => 'bibdk_mani_debates',
  );

  // Exported field_base: 'bibdk_mani_description_note'.
  $field_bases['bibdk_mani_description_note'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_description_note',
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
    'type' => 'bibdk_mani_description_note',
  );

  // Exported field_base: 'bibdk_mani_distinction'.
  $field_bases['bibdk_mani_distinction'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_distinction',
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
    'type' => 'bibdk_mani_distinction',
  );

  // Exported field_base: 'bibdk_mani_edition'.
  $field_bases['bibdk_mani_edition'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_edition',
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
    'type' => 'bibdk_mani_edition',
  );

  // Exported field_base: 'bibdk_mani_format'.
  $field_bases['bibdk_mani_format'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_format',
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
    'type' => 'bibdk_mani_format',
  );

  // Exported field_base: 'bibdk_mani_forms'.
  $field_bases['bibdk_mani_forms'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_forms',
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
    'type' => 'bibdk_mani_forms',
  );

  // Exported field_base: 'bibdk_mani_genre'.
  $field_bases['bibdk_mani_genre'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_genre',
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
    'type' => 'bibdk_mani_genre',
  );

  // Exported field_base: 'bibdk_mani_host_pub'.
  $field_bases['bibdk_mani_host_pub'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_host_pub',
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
    'type' => 'bibdk_mani_host_pub',
  );

  // Exported field_base: 'bibdk_mani_identifiers'.
  $field_bases['bibdk_mani_identifiers'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_identifiers',
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
    'type' => 'bibdk_mani_identifiers',
  );

  // Exported field_base: 'bibdk_mani_identifiers_isbn'.
  $field_bases['bibdk_mani_identifiers_isbn'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_identifiers_isbn',
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
    'type' => 'bibdk_mani_identifiers_isbn',
  );

  // Exported field_base: 'bibdk_mani_identifiers_ismn'.
  $field_bases['bibdk_mani_identifiers_ismn'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_identifiers_ismn',
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
    'type' => 'bibdk_mani_identifiers_ismn',
  );

  // Exported field_base: 'bibdk_mani_identifiers_issn'.
  $field_bases['bibdk_mani_identifiers_issn'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_identifiers_issn',
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
    'type' => 'bibdk_mani_identifiers_issn',
  );

  // Exported field_base: 'bibdk_mani_infotext'.
  $field_bases['bibdk_mani_infotext'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_infotext',
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
    'type' => 'bibdk_mani_infotext',
  );

  // Exported field_base: 'bibdk_mani_language'.
  $field_bases['bibdk_mani_language'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_language',
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
    'type' => 'bibdk_mani_language',
  );

  // Exported field_base: 'bibdk_mani_marked_audience'.
  $field_bases['bibdk_mani_marked_audience'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_marked_audience',
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
    'type' => 'bibdk_mani_marked_audience',
  );

  // Exported field_base: 'bibdk_mani_orig_title'.
  $field_bases['bibdk_mani_orig_title'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_orig_title',
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
    'type' => 'bibdk_mani_orig_title',
  );

  // Exported field_base: 'bibdk_mani_originals'.
  $field_bases['bibdk_mani_originals'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_originals',
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
    'type' => 'bibdk_mani_originals',
  );

  // Exported field_base: 'bibdk_mani_pegi'.
  $field_bases['bibdk_mani_pegi'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_pegi',
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
    'type' => 'bibdk_mani_pegi',
  );

  // Exported field_base: 'bibdk_mani_price_information'.
  $field_bases['bibdk_mani_price_information'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_price_information',
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
    'type' => 'bibdk_mani_price_information',
  );

  // Exported field_base: 'bibdk_mani_pub_format'.
  $field_bases['bibdk_mani_pub_format'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_pub_format',
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
    'type' => 'bibdk_mani_pub_format',
  );

  // Exported field_base: 'bibdk_mani_pub_year'.
  $field_bases['bibdk_mani_pub_year'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_pub_year',
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
    'type' => 'bibdk_mani_pub_year',
  );

  // Exported field_base: 'bibdk_mani_publisher'.
  $field_bases['bibdk_mani_publisher'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_publisher',
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
    'type' => 'bibdk_mani_publisher',
  );

  // Exported field_base: 'bibdk_mani_readability_indexes'.
  $field_bases['bibdk_mani_readability_indexes'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_readability_indexes',
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
    'type' => 'bibdk_mani_readability_indexes',
  );

  // Exported field_base: 'bibdk_mani_readability_numbers'.
  $field_bases['bibdk_mani_readability_numbers'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_readability_numbers',
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
    'type' => 'bibdk_mani_readability_numbers',
  );

  // Exported field_base: 'bibdk_mani_recommended_audience'.
  $field_bases['bibdk_mani_recommended_audience'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_recommended_audience',
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
    'type' => 'bibdk_mani_recommended_audience',
  );

  // Exported field_base: 'bibdk_mani_references'.
  $field_bases['bibdk_mani_references'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_references',
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
    'type' => 'bibdk_mani_references',
  );

  // Exported field_base: 'bibdk_mani_related_series'.
  $field_bases['bibdk_mani_related_series'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_related_series',
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
    'type' => 'bibdk_mani_related_series',
  );

  // Exported field_base: 'bibdk_mani_section'.
  $field_bases['bibdk_mani_section'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_section',
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
    'type' => 'bibdk_mani_section',
  );

  // Exported field_base: 'bibdk_mani_series'.
  $field_bases['bibdk_mani_series'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_series',
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
    'type' => 'bibdk_mani_series',
  );

  // Exported field_base: 'bibdk_mani_shelf'.
  $field_bases['bibdk_mani_shelf'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_shelf',
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
    'type' => 'bibdk_mani_shelf',
  );

  // Exported field_base: 'bibdk_mani_shelf_public'.
  $field_bases['bibdk_mani_shelf_public'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_shelf_public',
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
    'type' => 'bibdk_mani_shelf_public',
  );

  // Exported field_base: 'bibdk_mani_system_demand'.
  $field_bases['bibdk_mani_system_demand'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_system_demand',
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
    'type' => 'bibdk_mani_system_demand',
  );

  // Exported field_base: 'bibdk_mani_text_levels'.
  $field_bases['bibdk_mani_text_levels'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_text_levels',
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
    'type' => 'bibdk_mani_text_levels',
  );

  // Exported field_base: 'bibdk_mani_title'.
  $field_bases['bibdk_mani_title'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_title',
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
    'type' => 'bibdk_mani_title',
  );

  // Exported field_base: 'bibdk_mani_title_specific'.
  $field_bases['bibdk_mani_title_specific'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_title_specific',
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
    'type' => 'bibdk_mani_title_specific',
  );

  // Exported field_base: 'bibdk_mani_title_extra'.
  $field_bases['bibdk_mani_title_extra'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_title_extra',
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
    'type' => 'bibdk_mani_title_extra',
  );

  // Exported field_base: 'bibdk_mani_tracks'.
  $field_bases['bibdk_mani_tracks'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_tracks',
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
    'type' => 'bibdk_mani_tracks',
  );

  // Exported field_base: 'bibdk_mani_type'.
  $field_bases['bibdk_mani_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_type',
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
    'type' => 'bibdk_mani_type',
  );

  // Exported field_base: 'bibdk_mani_used_language'.
  $field_bases['bibdk_mani_used_language'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_used_language',
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
    'type' => 'bibdk_mani_used_language',
  );

  // Exported field_base: 'bibdk_mani_volume'.
  $field_bases['bibdk_mani_volume'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_mani_volume',
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
    'type' => 'bibdk_mani_volume',
  );

  // Exported field_base: 'bibdk_saou_link'.
  $field_bases['bibdk_saou_link'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibdk_saou_link',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'bibdk_saou_field',
    'settings' => array(),
    'storage' => array(
      'active' => 1,
      'module' => 'virtual_field',
      'settings' => array(),
      'type' => 'virtual_field',
    ),
    'translatable' => 0,
    'type' => 'bibdk_saou_link',
  );

  // Exported field_base: 'ting_openformat_mani_lk_subjects'.
  $field_bases['ting_openformat_mani_lk_subjects'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'ting_openformat_mani_lk_subjects',
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
    'type' => 'ting_openformat_mani_lk_subjects',
  );

  return $field_bases;
}
