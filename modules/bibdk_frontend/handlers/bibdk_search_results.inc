<?php

/**
 * @file
 * bibdk_search_results.inc
 */

$handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'search_ting_openformat_panel_context';
$handler->task = 'search';
$handler->subtask = 'ting_openformat';
$handler->handler = 'panel_context';
$handler->weight = 0;
$handler->conf = array(
  'title' => 'Panel',
  'no_blocks' => 0,
  'pipeline' => 'standard',
  'body_classes_to_remove' => '',
  'body_classes_to_add' => 'lift-columns',
  'css_id' => '',
  'css' => '',
  'contexts' => array(),
  'relationships' => array(),
);
$display = new panels_display();
$display->layout = 'bibdk_33_66_search_result';
$display->layout_settings = array();
$display->panel_settings = array(
  'style_settings' => array(
    'default' => NULL,
    'left' => NULL,
    'middle' => NULL,
    'right' => NULL,
    'top' => NULL,
    'middle-top' => NULL,
    'bottom' => NULL,
    'middle_top' => NULL,
    'works_controls' => NULL,
    'works' => NULL,
    'facets' => NULL,
    'works_controls_top' => NULL,
    'works_controls_bottom' => NULL,
  ),
  'middle_top' => array(
    'style' => '-1',
  ),
  'top' => array(
    'style' => '-1',
  ),
);
$display->cache = array();
$display->title = '';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-1';
  $pane->panel = 'facets';
  $pane->type = 'ting_openformat_filters';
  $pane->subtype = 'ting_openformat_filters';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $display->content['new-1'] = $pane;
  $display->panels['facets'][0] = 'new-1';
  $pane = new stdClass();
  $pane->pid = 'new-2';
  $pane->panel = 'facets';
  $pane->type = 'bibdk_facetbrowser';
  $pane->subtype = 'bibdk_facetbrowser';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $display->content['new-2'] = $pane;
  $display->panels['facets'][1] = 'new-2';
  $pane = new stdClass();
  $pane->pid = 'new-3';
  $pane->panel = 'top';
  $pane->type = 'ting_openformat_search_text';
  $pane->subtype = 'ting_openformat_search_text';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'searchresult_count',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $display->content['new-3'] = $pane;
  $display->panels['top'][0] = 'new-3';
  $pane = new stdClass();
  $pane->pid = 'new-4';
  $pane->panel = 'top';
  $pane->type = 'ting_openformat_pager';
  $pane->subtype = 'ting_openformat_pager';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $display->content['new-4'] = $pane;
  $display->panels['top'][1] = 'new-4';
  $pane = new stdClass();
  $pane->pid = 'new-5';
  $pane->panel = 'top';
  $pane->type = 'ting_openformat_feeds';
  $pane->subtype = 'ting_openformat_feeds';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $display->content['new-5'] = $pane;
  $display->panels['top'][2] = 'new-5';
  $pane = new stdClass();
  $pane->pid = 'new-6';
  $pane->panel = 'top';
  $pane->type = 'block';
  $pane->subtype = 'bibdk_search_controls-search-control-sort';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $display->content['new-6'] = $pane;
  $display->panels['top'][3] = 'new-6';
  $pane = new stdClass();
  $pane->pid = 'new-7';
  $pane->panel = 'top';
  $pane->type = 'ting_openformat_full_view';
  $pane->subtype = 'ting_openformat_full_view';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $display->content['new-7'] = $pane;
  $display->panels['top'][4] = 'new-7';
  $pane = new stdClass();
  $pane->pid = 'new-8';
  $pane->panel = 'top';
  $pane->type = 'block';
  $pane->subtype = 'bibdk_facetbrowser-bibdk_works_controls_facets_link';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $display->content['new-8'] = $pane;
  $display->panels['top'][5] = 'new-8';
  $pane = new stdClass();
  $pane->pid = 'new-9';
  $pane->panel = 'works';
  $pane->type = 'ting_openformat_search_result';
  $pane->subtype = 'ting_openformat_search_result';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'ting_openformat',
    'log' => TRUE,
    'override_empty' => FALSE,
    'empty_title' => '',
    'empty' => '',
    'empty_format' => 'plain_text',
    'override_no_key' => FALSE,
    'no_key_title' => '',
    'no_key' => '',
    'no_key_format' => 'plain_text',
    'context' => 'argument_string_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => 'search-result-wrapper',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $display->content['new-9'] = $pane;
  $display->panels['works'][0] = 'new-9';
  $pane = new stdClass();
  $pane->pid = 'new-10';
  $pane->panel = 'works_controls_bottom';
  $pane->type = 'ting_openformat_pager';
  $pane->subtype = 'ting_openformat_pager';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $display->content['new-10'] = $pane;
  $display->panels['works_controls_bottom'][0] = 'new-10';
  $pane = new stdClass();
  $pane->pid = 'new-11';
  $pane->panel = 'works_controls_top';
  $pane->type = 'ting_openformat_rank_frequency';
  $pane->subtype = 'ting_openformat_rank_frequency';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $display->content['new-11'] = $pane;
  $display->panels['works_controls_top'][0] = 'new-11';
$display->hide_title = PANELS_TITLE_FIXED;
$display->title_pane = '0';
$handler->conf['display'] = $display;
