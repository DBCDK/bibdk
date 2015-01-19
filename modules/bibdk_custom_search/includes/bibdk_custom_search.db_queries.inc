<?php

/**
 * Get advanced search field records from db
 *
 * @param $page
 * @return DatabaseStatementInterface|null
 */
function _bibdk_custom_search_get_advanced_fields_db($page) {

  // Get cached result
  $cache_id = 'bibdk_custom_search_fields_' . $page['p_uuid'];
  if ($cache = cache_get($cache_id)) {
    return $cache->data;
  }

  // bibdk_custom_search_elements
  $query = db_select('bibdk_custom_search', 's');
  $query->leftjoin('bibdk_custom_search_map_elements', 'me', 's.p_uuid = me.p_uuid');
  $query->join('bibdk_custom_search_elements', 'e', 'me.e_uuid = e.e_uuid');
  $query->leftjoin('bibdk_custom_search_map_values', 'mv', 'e.e_uuid = mv.e_uuid');
  $query->join('bibdk_custom_search_values', 'v', 'mv.v_uuid = v.v_uuid');
  $query->leftjoin('bibdk_custom_search_options', 'o', 'v.v_uuid = o.v_uuid');
  $query->fields('me', array('region', 'sort'));
  $query->fields('e', array(
    'e_uuid',
    'element_label',
    'description',
    'help_text',
    'access_key',
    'tab_index',
    'is_disabled'
  ));
  $query->fields('mv', array('sort'));
  $query->fields('v', array(
    'v_uuid',
    'value_title',
    'value_type',
    'search_code',
    'default_value'
  ));
  $query->addField('v', 'is_disabled', 'value_disabled');
  $query->fields('o', array(
    'o_uuid',
    'sort',
    'label',
    'value',
    'expand',
    'is_disabled'
  ));
  $query->addField('o', 'is_disabled', 'option_disabled');
  $query->condition('s.p_uuid', $page['p_uuid'], '=');
  $query->orderBy('me.sort', 'ASC');
  $query->orderBy('e.element_label', 'ASC');
  $query->orderBy('region', 'ASC');
  $query->orderBy('mv.sort', 'ASC');
  $query->orderBy('v.value_title', 'ASC');
  $query->orderBy('o.sort', 'ASC');
  $result = $query->execute()->fetchAll();

  cache_set($cache_id, $result, 'cache');
  return $result;
}


/**
 *  Get single searchpage from db
 *
 * @param $page_path
 */
function _bibdk_custom_search_get_page_db($page_path) {
  return db_select('bibdk_custom_search', 'p')
    ->fields('p')
    ->condition('page_path', $page_path, '=')
    ->condition('is_disabled', FALSE, '=')
    ->execute()
    ->fetchAssoc();
}

/**
 * Get all searchpages from db
 *
 * @return array
 */
function _bibdk_custom_search_get_pages_db() {
  global $language;

  $pages = & drupal_static(__FUNCTION__);

  if (!isset($pages)) {
    if ($cache = cache_get('bibdk_custom_search_pages_db_' . $language->language)) {
      $pages = $cache->data;
    }
    else {
      $pages = array();

      $query = db_select('bibdk_custom_search', 'p');
      $query
        ->fields('p')
        ->condition('is_disabled', FALSE)
        ->orderBy('sort', 'ASC');
      $result = $query->execute();

      foreach ($result as $page) {
        $attributes = ($page->is_disabled) ? array('disabled' => 'disabled') : array();
        $row = array(
          'title' => bibdk_custom_search_translate($page->menu_title, 'menu_title'),
          'href' => $page->page_path,
          'attributes' => $attributes,
        );
        $pages[] = $row;
      }
      cache_set('bibdk_custom_search_pages_db_' . $language->language, $pages, 'cache');

    }
  }

  return $pages;
}


function bibdk_custom_search_get_custom_search_pages() {
  static $elements;
  if (isset($elements)) {
    return $elements;
  }
  // Get cached result
  $cache_id = 'bibdk_custom_search_pages';
  if ($cache = cache_get($cache_id)) {
    return $elements = $cache->data;
  }

  $query = db_select('bibdk_custom_search', 'p');
  $query
    ->fields('p', array('p_uuid', 'page_title', 'sort', 'is_disabled', 'page_path'))
    ->orderBy('page_title', 'DESC')
    ->orderBy('sort', 'DESC');
  $result = $query->execute();

  $elements = array();
  foreach ($result as $record) {
    $row = array(
      'p_uuid' => check_plain($record->p_uuid),
      'page_title' => check_plain($record->page_title),
      'sort' => check_plain($record->sort),
      'is_disabled' => check_plain($record->is_disabled),
      'page_path' => $record->page_path,
    );
    $elements[] = $row;
  }

  cache_set($cache_id, $elements, 'cache');
  return $elements;
}

function _bibdk_custom_search_get_options_db_raw($value_id){

  $cache_id = 'bibdk_custom_search_options_' . $value_id;
  if ($cache = cache_get($cache_id)) {
    return $cache->data;
  }

    $query = db_select('bibdk_custom_search_options', 'o');
  $query
    ->fields('o', array(
      'o_uuid',
      'v_uuid',
      'label',
      'value',
      'expand',
      'sort',
      'is_disabled'
    ))
    ->condition('v_uuid', $value_id, '=')
    ->orderBy('sort', 'ASC');
  $result = $query->execute()->fetchAll();

  cache_set($cache_id, $result, 'cache');

  return $result;

}

/**
 * Get search options from db
 */
function _bibdk_custom_search_get_options_db($value_id) {
  global $language;

  // note: drupal_static(__FUNCTION__) crashes Drupal if used here.
  if ($cache = cache_get('bibdk_custom_search_options_db_' . $value_id . $language->language)) {

    $options = $cache->data;

  }
  else {

    $result = _bibdk_custom_search_get_options_db_raw($value_id);
    $options = array();

    foreach ($result as $option) {
      $row = array(
        'o_uuid' => $option->o_uuid,
        'v_uuid' => $option->v_uuid,
        'label' => bibdk_custom_search_translate($option->label, 'label'),
        'value' => $option->value,
        'expand' => $option->expand,
        'sort' => $option->sort,
        'disabled' => $option->is_disabled,
      );
      $options[] = $row;
    }

    cache_set('bibdk_custom_search_options_db_' . $value_id . $language->language, $options, 'cache');

  }

  return $options;

}


/**
 * get form fields and search codes from database.
 */
function _bibdk_custom_search_get_field_searchcodes() {
  if (!isset($fields)) {
    if (false && $cache = cache_get('bibdk_custom_search_field_searchcodes')) {
      $fields = $cache->data;
    }
    else {
      $query = db_select('bibdk_custom_search_values', 'v');
      $query->fields('v', array(
        'v_uuid',
        'value_title',
        'value_type',
        'search_code',
        'default_value'
      ));
      $result = $query->execute();
      $fields = array();

      foreach ($result as $record) {
        $fields[$record->search_code]['value_title'] = $record->value_title;
        $fields[$record->search_code]['value_type'] = $record->value_type;
        $fields[$record->search_code]['search_code'] = $record->search_code;
        $fields[$record->search_code]['default_value'] = $record->default_value;
      }

      cache_set('bibdk_custom_search_field_searchcodes', $fields, 'cache');
    }
  }
  return $fields;
}
