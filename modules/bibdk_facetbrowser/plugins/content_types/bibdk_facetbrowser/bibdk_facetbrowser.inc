<?php
/**
 * @file
 * CTools content type file for the bibdk_facetbrowser module.
 */

$plugin = array(
  'title' => t('Bibdk Facetbrowser', array(), array('context' => 'bibdk_facetbrowser')),
  'description' => t('Bibdk facetbrowser description', array(), array('context' => 'bibdk_facetbrowser')),
  'single' => TRUE,
  'content_types' => array('bibdk_facetbrowser'),
  'render callback' => 'bibdk_facetbrowser_content_type_render',
  'category' => t('Ting'),
  'render last' => TRUE, # Force the facetbrowser to be generated after the ting_search
);

/**
 * Callback function for the ctools content_type
 */
function bibdk_facetbrowser_content_type_render($subtype, $conf, $panel_args, $context) {
  $block_content          = FALSE;
  $content_in_facet       = FALSE;
  $executed_search_module = FALSE;
  $block                  = new stdClass();

  $block->module = 'bibdk_facetbrowser';
  $block->delta  = 'bibdk_facetbrowser';
  $block->title = t('Bibdk Facetbrowser', array(), array('context' => 'bibdk_facetbrowser block title'));

  $show_count = variable_get('bibdk_facetbrowser_number_shown', 5);
  $show_count_consecutive = variable_get('bibdk_facetbrowser_consecutive_number_shown', 10);

  drupal_add_css(drupal_get_path('module', 'bibdk_facetbrowser') . '/css/facetbrowser.css');
  drupal_add_js(drupal_get_path('module', 'bibdk_facetbrowser') . '/js/facetbrowser.js');
  drupal_add_js(
    array(
      'bibdkFacetBrowser' => array(
        'mainElement' => '.pane-bibdk-facetbrowser',
        'showCount' => $show_count,
        'showCountConsecutive' => $show_count_consecutive
      )
    ),
    'setting'
  );

  $by_ajax = variable_get('bibdk_facetbrowser_by_ajax', FALSE);

  if ($by_ajax) {
    $content = bibdk_facetbrowser_facetbrowser_placeholder();
    $placeholder = drupal_render($content);
    $block->content = $placeholder;
  }
  else {
    // Invoke bibdk_facetbrowser() from executed search module
    $executed_search = menu_get_item();
    if (!empty($executed_search['page_arguments'])) {
      list($executed_search_module, ) = $executed_search['page_arguments'];
    }
    if (is_string($executed_search_module)) {
      $results = module_invoke($executed_search_module, 'bibdk_facetbrowser');
      if (is_object($results)) {
        foreach ($results->facets as $result) {
          if (count($result->terms) == TRUE) {
            $content_in_facet = TRUE;
            break;
          }
        }
        if ( $content_in_facet === TRUE || $results->show_empty == TRUE ) {
          $block_content = theme('theme_bibdk_facetbrowser', array($results->facets, (!empty($results->searchkey) ? $results->searchkey : NULL)));
        }
      }
      $block->content = $block_content;

    }
  }
  return $block;
}


/**
 * Returns an edit form for settings
 */
function bibdk_facetbrowser_bibdk_facetbrowser_content_type_edit_form($form, &$form_state) {
  return $form;
}
