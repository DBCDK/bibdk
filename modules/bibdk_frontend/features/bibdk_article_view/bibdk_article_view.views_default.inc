<?php
/**
 * @file
 * bibdk_article_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function bibdk_article_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'article_view';
  $view->description = 'bibdk articles in a view(block)';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'article_view';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'small-12 end';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Udfør';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Banner image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: link classes */
  $handler->display->display_options['fields']['field_link_classes']['id'] = 'field_link_classes';
  $handler->display->display_options['fields']['field_link_classes']['table'] = 'field_data_field_link_classes';
  $handler->display->display_options['fields']['field_link_classes']['field'] = 'field_link_classes';
  $handler->display->display_options['fields']['field_link_classes']['label'] = '';
  $handler->display->display_options['fields']['field_link_classes']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link_classes']['element_label_colon'] = FALSE;
  /* Field: Content: link text */
  $handler->display->display_options['fields']['field_link_text']['id'] = 'field_link_text';
  $handler->display->display_options['fields']['field_link_text']['table'] = 'field_data_field_link_text';
  $handler->display->display_options['fields']['field_link_text']['field'] = 'field_link_text';
  $handler->display->display_options['fields']['field_link_text']['label'] = '';
  $handler->display->display_options['fields']['field_link_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link_text']['element_label_colon'] = FALSE;
  /* Field: Content: rows */
  $handler->display->display_options['fields']['field_rows']['id'] = 'field_rows';
  $handler->display->display_options['fields']['field_rows']['table'] = 'field_data_field_rows';
  $handler->display->display_options['fields']['field_rows']['field'] = 'field_rows';
  $handler->display->display_options['fields']['field_rows']['label'] = '';
  $handler->display->display_options['fields']['field_rows']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_rows']['element_label_colon'] = FALSE;
  /* Field: Content: weight */
  $handler->display->display_options['fields']['field_weight']['id'] = 'field_weight';
  $handler->display->display_options['fields']['field_weight']['table'] = 'field_data_field_weight';
  $handler->display->display_options['fields']['field_weight']['field'] = 'field_weight';
  $handler->display->display_options['fields']['field_weight']['label'] = '';
  $handler->display->display_options['fields']['field_weight']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_weight']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['alter']['text'] = '[field_link_text]';
  $handler->display->display_options['fields']['field_link']['alter']['path'] = '[field_link] ';
  $handler->display->display_options['fields']['field_link']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_link']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: weight (field_weight) */
  $handler->display->display_options['sorts']['field_weight_value']['id'] = 'field_weight_value';
  $handler->display->display_options['sorts']['field_weight_value']['table'] = 'field_data_field_weight';
  $handler->display->display_options['sorts']['field_weight_value']['field'] = 'field_weight_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'bibdk_article' => 'bibdk_article',
  );
  /* Filter criterion: Content: column (field_column) */
  $handler->display->display_options['filters']['field_column_tid']['id'] = 'field_column_tid';
  $handler->display->display_options['filters']['field_column_tid']['table'] = 'field_data_field_column';
  $handler->display->display_options['filters']['field_column_tid']['field'] = 'field_column_tid';
  $handler->display->display_options['filters']['field_column_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_column_tid']['vocabulary'] = 'column';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'bibdk_article' => 'bibdk_article',
  );

  /* Display: bottom pane left */
  $handler = $view->new_display('panel_pane', 'bottom pane left', 'panel_pane_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'columns small-24 medium-12 large-12';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['argument'] = 'alle_materialer';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'page_type' => 'page_type',
  );
  $handler->display->display_options['arguments']['tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'bibdk_article' => 'bibdk_article',
  );
  /* Filter criterion: Content: column (field_column) */
  $handler->display->display_options['filters']['field_column_tid']['id'] = 'field_column_tid';
  $handler->display->display_options['filters']['field_column_tid']['table'] = 'field_data_field_column';
  $handler->display->display_options['filters']['field_column_tid']['field'] = 'field_column_tid';
  $handler->display->display_options['filters']['field_column_tid']['value'] = array(
    11 => '11',
  );
  $handler->display->display_options['filters']['field_column_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_column_tid']['vocabulary'] = 'column';
  /* Filter criterion: Content: page region (field_page_region) */
  $handler->display->display_options['filters']['field_page_region_tid']['id'] = 'field_page_region_tid';
  $handler->display->display_options['filters']['field_page_region_tid']['table'] = 'field_data_field_page_region';
  $handler->display->display_options['filters']['field_page_region_tid']['field'] = 'field_page_region_tid';
  $handler->display->display_options['filters']['field_page_region_tid']['value'] = array(
    10 => '10',
  );
  $handler->display->display_options['filters']['field_page_region_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_page_region_tid']['vocabulary'] = 'page_region';
  $handler->display->display_options['argument_input'] = array(
    'field_page_region_tid' => array(
      'type' => 'none',
      'context' => 'entity:taxonomy_vocabulary.name',
      'context_optional' => 1,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: page region (field_page_region)',
    ),
    'tid' => array(
      'type' => 'panel',
      'context' => 'entity:user.uid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Indhold: Has taxonomy term ID',
    ),
  );

  /* Display: top pane */
  $handler = $view->new_display('panel_pane', 'top pane', 'panel_pane_2');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Banner image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: link classes */
  $handler->display->display_options['fields']['field_link_classes']['id'] = 'field_link_classes';
  $handler->display->display_options['fields']['field_link_classes']['table'] = 'field_data_field_link_classes';
  $handler->display->display_options['fields']['field_link_classes']['field'] = 'field_link_classes';
  $handler->display->display_options['fields']['field_link_classes']['label'] = '';
  $handler->display->display_options['fields']['field_link_classes']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link_classes']['element_label_colon'] = FALSE;
  /* Field: Content: link text */
  $handler->display->display_options['fields']['field_link_text']['id'] = 'field_link_text';
  $handler->display->display_options['fields']['field_link_text']['table'] = 'field_data_field_link_text';
  $handler->display->display_options['fields']['field_link_text']['field'] = 'field_link_text';
  $handler->display->display_options['fields']['field_link_text']['label'] = '';
  $handler->display->display_options['fields']['field_link_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link_text']['element_label_colon'] = FALSE;
  /* Field: Content: rows */
  $handler->display->display_options['fields']['field_rows']['id'] = 'field_rows';
  $handler->display->display_options['fields']['field_rows']['table'] = 'field_data_field_rows';
  $handler->display->display_options['fields']['field_rows']['field'] = 'field_rows';
  $handler->display->display_options['fields']['field_rows']['label'] = '';
  $handler->display->display_options['fields']['field_rows']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_rows']['element_label_colon'] = FALSE;
  /* Field: Content: weight */
  $handler->display->display_options['fields']['field_weight']['id'] = 'field_weight';
  $handler->display->display_options['fields']['field_weight']['table'] = 'field_data_field_weight';
  $handler->display->display_options['fields']['field_weight']['field'] = 'field_weight';
  $handler->display->display_options['fields']['field_weight']['label'] = '';
  $handler->display->display_options['fields']['field_weight']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_weight']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['argument'] = 'alle_materialer';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'page_type' => 'page_type',
  );
  $handler->display->display_options['arguments']['tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'bibdk_article' => 'bibdk_article',
  );
  /* Filter criterion: Content: page region (field_page_region) */
  $handler->display->display_options['filters']['field_page_region_tid']['id'] = 'field_page_region_tid';
  $handler->display->display_options['filters']['field_page_region_tid']['table'] = 'field_data_field_page_region';
  $handler->display->display_options['filters']['field_page_region_tid']['field'] = 'field_page_region_tid';
  $handler->display->display_options['filters']['field_page_region_tid']['value'] = array(
    9 => '9',
  );
  $handler->display->display_options['filters']['field_page_region_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_page_region_tid']['vocabulary'] = 'page_region';
  $handler->display->display_options['argument_input'] = array(
    'field_page_region_tid' => array(
      'type' => 'none',
      'context' => 'entity:file.fid',
      'context_optional' => 1,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: page region (field_page_region)',
    ),
    'tid' => array(
      'type' => 'panel',
      'context' => 'entity:user.uid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Indhold: Has taxonomy term ID',
    ),
  );

  /* Display: bottom pane right */
  $handler = $view->new_display('panel_pane', 'bottom pane right', 'panel_pane_3');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'columns small-24 medium-12 large-12 right';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['argument'] = 'alle_materialer';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'page_type' => 'page_type',
  );
  $handler->display->display_options['arguments']['tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'bibdk_article' => 'bibdk_article',
  );
  /* Filter criterion: Content: page region (field_page_region) */
  $handler->display->display_options['filters']['field_page_region_tid']['id'] = 'field_page_region_tid';
  $handler->display->display_options['filters']['field_page_region_tid']['table'] = 'field_data_field_page_region';
  $handler->display->display_options['filters']['field_page_region_tid']['field'] = 'field_page_region_tid';
  $handler->display->display_options['filters']['field_page_region_tid']['value'] = array(
    10 => '10',
  );
  $handler->display->display_options['filters']['field_page_region_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_page_region_tid']['vocabulary'] = 'page_region';
  /* Filter criterion: Content: column (field_column) */
  $handler->display->display_options['filters']['field_column_tid']['id'] = 'field_column_tid';
  $handler->display->display_options['filters']['field_column_tid']['table'] = 'field_data_field_column';
  $handler->display->display_options['filters']['field_column_tid']['field'] = 'field_column_tid';
  $handler->display->display_options['filters']['field_column_tid']['value'] = array(
    12 => '12',
  );
  $handler->display->display_options['filters']['field_column_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_column_tid']['vocabulary'] = 'column';
  $handler->display->display_options['argument_input'] = array(
    'tid' => array(
      'type' => 'panel',
      'context' => 'entity:file.fid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Has taxonomy term ID',
    ),
  );
  $translatables['article_view'] = array(
    t('Master'),
    t('mere'),
    t('Udfør'),
    t('Gendan'),
    t('Sortér efter'),
    t('Stigende'),
    t('Faldende'),
    t('[field_link_text]'),
    t('Block'),
    t('more'),
    t('bottom pane left'),
    t('Alle'),
    t('View panes'),
    t('top pane'),
    t('bottom pane right'),
  );
  $export['article_view'] = $view;

  return $export;
}
