<?php

/**
 * @file
 * Provides search results as a Panels content type.
 */

$plugin = array(
  'title' => t('Ting search carousel'),
  'single' => TRUE,
  'description' => t('A carousel displaying search results against the Ting system'),
  'category' => t('Ting'),
);

/**
 * Return the pane contents.
 */
function bibdk_search_carousel_carousel_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();

  $searches = variable_get('bibdk_carousel_search_queries', array());
  $tab_position = variable_get('bibdk_search_carousel_tabs_position');

  $block->content = theme('bibdk_search_carousel', array('searches' => $searches, 'tab_position' => $tab_position));
  return $block;
}

/**
 * Return the pane titles.
 */
function bibdk_search_carousel_carousel_content_type_admin_title($subtype, $conf, $context) {
  return t('Ting search carousel');
}

/**
 * Returns an edit form for the content type.
 */
function bibdk_search_carousel_carousel_content_type_edit_form($form, &$form_state) {
  return $form;
}
