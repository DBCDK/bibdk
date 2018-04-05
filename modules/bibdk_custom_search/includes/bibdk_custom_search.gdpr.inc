<?php

/**
 * @file
 * Hooks provided by the bibdk_gdpr module.
 */

/**
 * Implements hook_bibdk_gdpr_items().
 *
 * @return array
 */
function bibdk_custom_search_bibdk_gdpr_items() {
  $rows = array();
  $start_page = bibdk_usersettings_user_settings_get('bibdk_custom_search_start_page', null);
  $pages = _bibdk_custom_search_get_pages_db();
  if (count($pages) > 0) {
    foreach ($pages as $key => $page) {
      if ($start_page == $page['href']) {
        $rows[] = array(
          '#type' => 'container',
          'label' => array(
            '#type' => 'html_tag',
            '#tag' => 'span',
            '#value' => t('label_start_page', array(), array('context' => 'bibdk_gdpr'))
          ),
          'value' => array(
            '#type' => 'html_tag',
            '#tag' => 'span',
            '#value' => $page['title']
          ),
        );
      }
    }
    $items['bibdk_custom_search_start_page']['#weight'] = 50;
    $items['bibdk_custom_search_start_page']['#header'] = t('label_gdpr_bibdk_custom_search_start_page', array(), array('context' => 'bibdk_gdpr'));
    $items['bibdk_custom_search_start_page']['#theme'] = 'bibdk_gdpr_item_theme';
    $items['bibdk_custom_search_start_page']['#content'] = $rows;
  }

  $rows = array();
  $values = _bibdk_custom_search_usersettings_expand_search_options_page();
  if (count($pages) > 0) {
    foreach ($pages as $key => $page) {
      $rows[] = array(
        '#type' => 'container',
        'label' => array(
          '#type' => 'html_tag',
          '#tag' => 'span',
          '#value' => t($page['title'], array(), array('context' => 'bibdk_gdpr'))
        ),
        'value' => array(
          '#type' => 'html_tag',
          '#tag' => 'span',
          '#value' => (in_array($page['href'], $values)) ? 
            t('label_searchbox_expanded', array(), array('context' => 'bibdk_gdpr')) : 
            t('label_searchbox_collapsed', array(), array('context' => 'bibdk_gdpr'))
        ),
      );
    }
    $items['bibdk_custom_search_expand']['#weight'] = 51;
    $items['bibdk_custom_search_expand']['#header'] = t('label_gdpr_bibdk_custom_search_expand', array(), array('context' => 'bibdk_gdpr'));
    $items['bibdk_custom_search_expand']['#theme'] = 'bibdk_gdpr_item_theme';
    $items['bibdk_custom_search_expand']['#content'] = $rows;
  }

  $rows = array();
  if (!empty($filters)) {
    foreach ($filters as $key => $filter) {
      $rows[] = array(
        '#type' => 'container',
        'label' => array(
          '#type' => 'html_tag',
          '#tag' => 'span',
          '#value' => t($filter->description, array(), array('context' => 'bibdk_gdpr'))
        ),
        'value' => array(
          '#type' => 'html_tag',
          '#tag' => 'span',
          '#value' => (bibdk_usersettings_user_settings_get($filter->id, TRUE)) ? 
            t('label_action_enabled', array(), array('context' => 'bibdk_gdpr')) : 
            t('label_action_disabled', array(), array('context' => 'bibdk_gdpr'))
        ),
      );
    }
    $items['bibdk_custom_search_filters']['#weight'] = 52;
    $items['bibdk_custom_search_filters']['#header'] = t('label_gdpr_bibdk_custom_search_filters', array(), array('context' => 'bibdk_gdpr'));
    $items['bibdk_custom_search_filters']['#theme'] = 'bibdk_gdpr_item_theme';
    $items['bibdk_custom_search_filters']['#content'] = $rows;
  }
  
  return $items;
}
