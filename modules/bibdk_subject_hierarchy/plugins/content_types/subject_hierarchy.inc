<?php

/**
 * @file
 * Provides subject hierachy as a Panels content type.
 */

$plugin = array(
  'title' => t('Bibdk subject hierarchy, pane'),
  'single' => TRUE,
  'description' => t('Subject hierarchy, pane'),
  'category' => t('Bibliotek.dk'),
);


/**
 * Return the pane contents.
 */
function bibdk_subject_hierarchy_subject_hierarchy_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();

  $block->content = bibdk_subject_hierarchy_get_block_content();
  return $block;
}
