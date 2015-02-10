<?php
/**
 * @file
 * bibdk_article.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bibdk_article_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function bibdk_article_node_info() {
  $items = array(
    'bibdk_article' => array(
      'name' => t('artikel'),
      'base' => 'node_content',
      'description' => t('Add information articles to the frontpage'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  return $items;
}
