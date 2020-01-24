<?php
/**
 * @file
 * bibdk_article.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function bibdk_article_taxonomy_default_vocabularies() {
  return array(
    'column' => array(
      'name' => 'column',
      'machine_name' => 'column',
      'description' => 'left or right column',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'page_region' => array(
      'name' => 'Page region',
      'machine_name' => 'page_region',
      'description' => 'page regions for article view',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'page_type' => array(
      'name' => 'Page type',
      'machine_name' => 'page_type',
      'description' => 'page types for custom search pages',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
