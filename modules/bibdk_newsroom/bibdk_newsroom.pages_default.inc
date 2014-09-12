<?php

/**
 * @file
 * ding_library.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function bibdk_newsroom_default_page_manager_pages() {
  $pages = array();

$page = new stdClass();
$page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
$page->api_version = 1;
$page->name = 'bibdk_newsroom';
$page->task = 'page';
$page->admin_title = 'Bibliotek.dk Newsroom';
$page->admin_description = 'This page is for showing newsroom nodes in a pop-up window.';
$page->path = 'overlay/newsroom/!bibdk_newsroom_context';
$page->access = array();
$page->menu = array();
$page->arguments = array(
  'bibdk_newsroom_context' => array(
    'id' => 1,
    'identifier' => 'bibdk newsroom: Node ID',
    'name' => 'bibdk_newsroom_arg',
    'settings' => array(),
  ),
);
$page->conf = array(
  'admin_paths' => FALSE,
);
$page->default_handlers = array();
$handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'page_bibdk_newsroom_panel_context';
$handler->task = 'page';
$handler->subtask = 'bibdk_newsroom';
$handler->handler = 'panel_context';
$handler->weight = 0;
$handler->conf = array(
  'title' => 'Panel',
  'no_blocks' => 0,
  'pipeline' => 'standard',
  'body_classes_to_remove' => '',
  'body_classes_to_add' => '',
  'css_id' => '',
  'css' => '',
  'contexts' => array(),
  'relationships' => array(),
);
$display = new panels_display();
$display->layout = 'onecol';
$display->layout_settings = array();
$display->panel_settings = array(
  'style_settings' => array(
    'default' => NULL,
    'middle' => NULL,
  ),
);
$display->cache = array();
$display->title = '';
$display->uuid = '08e93b6e-5e2d-46fb-94b4-418d7f816509';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-22ba4f89-72f9-45d8-8ec9-bc6a1471d404';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'bibdk_newsroom-bibdk-newsroom-form';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '22ba4f89-72f9-45d8-8ec9-bc6a1471d404';
  $display->content['new-22ba4f89-72f9-45d8-8ec9-bc6a1471d404'] = $pane;
  $display->panels['middle'][0] = 'new-22ba4f89-72f9-45d8-8ec9-bc6a1471d404';
  $pane = new stdClass();
  $pane->pid = 'new-5b1cf330-63d0-4a15-ab4b-76cb39f49a79';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'bibdk_newsroom-bibdk-newsroom-popup-menu';
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
  $pane->uuid = '5b1cf330-63d0-4a15-ab4b-76cb39f49a79';
  $display->content['new-5b1cf330-63d0-4a15-ab4b-76cb39f49a79'] = $pane;
  $display->panels['middle'][1] = 'new-5b1cf330-63d0-4a15-ab4b-76cb39f49a79';
  $pane = new stdClass();
  $pane->pid = 'new-395a3688-1590-4a1e-b46f-144ab0792605';
  $pane->panel = 'middle';
  $pane->type = 'bibdk_newsroom';
  $pane->subtype = 'bibdk_newsroom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'buttons' => NULL,
    'context' => 'argument_bibdk_newsroom_arg_1',
    'aligner_start' => NULL,
    'override_title' => 0,
    'override_title_text' => '',
    'aligner_stop' => NULL,
    'override_title_markup' => NULL,
    'newsroom_id' => '0',
    'form_build_id' => 'form-BXxr_iRB9WbBcg5q1hmzpdM1ByqoTgztw4vT8pe1vT0',
    'form_token' => 'ypFsP8LhGeMrnBoaCtWxIny4CzowjVfoUFrPIoQa7RM',
    'form_id' => 'bibdk_newsroom_edit_form',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '395a3688-1590-4a1e-b46f-144ab0792605';
  $display->content['new-395a3688-1590-4a1e-b46f-144ab0792605'] = $pane;
  $display->panels['middle'][2] = 'new-395a3688-1590-4a1e-b46f-144ab0792605';
$display->hide_title = PANELS_TITLE_NONE;
$display->title_pane = 'new-395a3688-1590-4a1e-b46f-144ab0792605';
$handler->conf['display'] = $display;
$page->default_handlers[$handler->name] = $handler;

/* Export end */

  $pages['newsroom_view'] = $page;

  return $pages;
}