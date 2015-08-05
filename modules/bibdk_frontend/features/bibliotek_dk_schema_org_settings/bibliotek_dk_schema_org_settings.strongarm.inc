<?php
/**
 * @file
 * bibliotek_dk_schema_org_settings.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bibliotek_dk_schema_org_settings_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bibdk_schema_org_vars';
  $strongarm->value = array(
    'bibdk_mani_publisher' => array(
      'property' => 'publisher',
      'typeof' => 'organization',
      'typeof_property' => 'name',
    ),
    'bibdk_mani_title' => array(
      'property' => 'name',
      'typeof' => '',
      'typeof_property' => '',
    ),
    'ting_openformat_mani_subjects' => array(
      'property' => 'keywords',
      'typeof' => '',
      'typeof_property' => '',
    ),
    'bibdk_latest_reprint' => array(
      'property' => 'bookEdition',
      'typeof' => '',
      'typeof_property' => '',
    ),
    'bibdk_mani_pub_year' => array(
      'property' => 'datePublished',
      'typeof' => '',
      'typeof_property' => '',
    ),
    'bibdk_mani_forms' => array(
      'property' => 'genre',
      'typeof' => '',
      'typeof_property' => '',
    ),
    'bibdk_mani_genre' => array(
      'property' => 'genre',
      'typeof' => '',
      'typeof_property' => '',
    ),
    'bibdk_mani_identifiers_isbn' => array(
      'property' => 'isbn',
      'typeof' => '',
      'typeof_property' => '',
    ),
    'bibdk_mani_identifiers_issn' => array(
      'property' => 'issn',
      'typeof' => '',
      'typeof_property' => '',
    ),
    'ting_openformat_mani_abstract' => array(
      'property' => 'description',
      'typeof' => '',
      'typeof_property' => '',
    ),
    'bibdk_mani_creators' => array(
      'property' => 'creator',
      'typeof' => 'Person',
      'typeof_property' => 'name',
    ),
    'bibdk_cover_work' => array(
      'property' => 'image',
      'typeof' => 'ImageObject',
      'typeof_property' => 'contentUrl',
    ),
  );
  $export['bibdk_schema_org_vars'] = $strongarm;

  return $export;
}
