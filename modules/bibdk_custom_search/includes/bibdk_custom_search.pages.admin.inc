<?php

/**
 * @file
 * Admin settings for bibdk search pages
 */

/**
 * Includes
 */
module_load_include('inc', 'bibdk_custom_search', 'includes/bibdk_custom_search-pages-forms');


/**
 * General settings.
 */
function bibdk_custom_search_admin() {
  // Page ordering and create new page.
  $elements = bibdk_custom_search_get_custom_search_pages();
  
  $form = _bibdk_custom_search_default_admin_form($elements);
  $form['#submit'][] = 'bibdk_custom_search_admin_submit';
  return $form;
}



/**
 * Submit handler for bibdk_custom_search_admin();
 */
function bibdk_custom_search_admin_submit($form, &$form_state) {
  $pages = $form_state['values']['bibdk_custom_search'];
  $size = sizeof($pages);
  foreach ($pages as $key => $page) {
    if ($page['p_uuid'] == '_new' && !empty($page['page_title'])) {
      _bibdk_custom_search_page_insert($page);
      $message[] = t('The page "@page" have been created.', array('@page' => $page['page_title']));
    }
    else {
      _bibdk_custom_search_page_update($page);
      $message[] = t('The pages have been updated.');
    }
  }
  drupal_set_message(check_plain(implode('<br/>', array_unique($message))));
  cache_clear_all('bibdk_custom_search', 'cache', TRUE);
}

/**
 * Search page list insert.
 */
function _bibdk_custom_search_page_insert($page) {
  $result = db_insert('bibdk_custom_search')
    ->fields(array(
      'p_uuid' => uuid_generate(),
      'page_title' => check_plain($page['page_title']),
      'sort' => (int) $page['sort'],
      'is_disabled' => 0,
    ))
    ->execute();
  return $result;
}

/**
 * Search page list update.
 */
function _bibdk_custom_search_page_update($page) {
  $result = db_update('bibdk_custom_search')
    ->fields(array(
      'sort' => (int) $page['sort'],
      'is_disabled' => (isset($page['is_disabled'])) ? (int) $page['is_disabled'] : 0,
    ))
    ->condition('p_uuid', $page['p_uuid'])
    ->execute();
  return $result;
}


/**
 * Validation handler for bibdk_custom_search_admin.
 */
function bibdk_custom_search_admin_validate($form, &$form_state) {
  // drupal_set_message(t('bibdk page validation.'));
  return $form;
}


/**
 * bibdk_custom_search_delete_page confirmation form;
 */
function bibdk_custom_search_delete_page($form_id, $form_state, $page_id) {

  $result = db_select('bibdk_custom_search', 'p')
    ->fields('p', array('page_title'))
    ->condition('p_uuid', $page_id, '=')
    ->execute()
    ->fetchAssoc();

  $form['page_id'] = array(
    '#type' => 'value',
    '#value' => $page_id,
  );

  $form['page_title'] = array(
    '#type' => 'hidden',
    '#value' => $result['page_title'],
  );

  return confirm_form($form, t("Are you sure you want to delete '@page'?", array('@page' => $result['page_title'])), 'admin/config/search/bibdk_custom_search');
}

/**
 * Submit handler for bibdk_custom_search_delete_page();
 */
function bibdk_custom_search_delete_page_submit($form, &$form_state) {

  $p_uuid = $form_state['values']['page_id'];

  $result = db_delete('bibdk_custom_search_map_elements')
    ->condition('p_uuid', $p_uuid)
    ->execute();

  $result = db_delete('bibdk_custom_search')
    ->condition('p_uuid', $p_uuid)
    ->execute();

  drupal_set_message(t("'@page' deleted.", array('@page' => $form_state['values']['page_title'])));

  cache_clear_all('bibdk_custom_search', 'cache', TRUE);

  $form_state['redirect'] = 'admin/config/search/bibdk_custom_search';
}

/**
 *
 */
function bibdk_custom_search_page_edit($form_id, $form_state, $page_id, $element_pointer = FALSE) {

  if ($element_pointer) {
    $result = db_delete('bibdk_custom_search_map_elements')
      ->condition('me_uuid', $element_pointer)
      ->execute();
    drupal_set_message(t("Element removed."));
  }
  if (!$page = bibdk_custom_search_page_load($page_id)) {
    drupal_set_message(t("The search page does not exist."), 'warning');
    return FALSE;
  }

  // bibdk_custom_search_elements
  $list_elements[0] = 'Select elements';
  $query = db_select('bibdk_custom_search_elements', 'e');
  $query
    ->fields('e', array('e_uuid', 'element_title', 'sort', 'is_disabled'))
    ->orderBy('sort', 'DESC');
  $result = $query->execute();
  foreach ($result as $row) {
    $e_uuid = check_plain($row->e_uuid);
    $element_title = check_plain($row->element_title);
    $list_elements[$e_uuid] = $element_title;
  }

  // bibdk_custom_search_map_elements
  $query = db_select('bibdk_custom_search_map_elements', 'm');
  $query->join('bibdk_custom_search_elements', 'e', 'm.e_uuid = e.e_uuid');
  $query->fields('m', array('me_uuid', 'e_uuid', 'region', 'sort'));
  $query->fields('e', array('element_title', 'is_disabled'));
  $query->condition('p_uuid', $page_id, '=');
  $query->orderBy('sort', 'DESC');
  $result = $query->execute();
  $page_elements = array();
  foreach ($result as $record) {
    $row = array(
      'me_uuid' => check_plain($record->me_uuid),
      'e_uuid' => check_plain($record->e_uuid),
      'region' => check_plain($record->region),
      'element_title' => check_plain($record->element_title),
      'sort' => check_plain($record->sort),
      'is_disabled' => check_plain($record->is_disabled),
    );
    $page_elements[] = $row;
  }
  $page['elements'] = $page_elements;

  $form = _bibdk_custom_search_edit_page_form($page, $list_elements);

  $form['#validate'][] = 'bibdk_custom_search_edit_page_validate';

  $form['#submit'][] = 'bibdk_custom_search_edit_page_submit';

  return $form;
}


/**
 * Validation handler for bibdk_custom_search_page_edit();
 */
function bibdk_custom_search_edit_page_validate($form, &$form_state) {
  return TRUE;
}

/**
 *
 */
function bibdk_custom_search_edit_page_submit($form, &$form_state) {
  $page = $form_state['values']['page'];
  $p_uuid = $form_state['values']['page']['p_uuid'];

  $result = db_update('bibdk_custom_search')
    ->fields(array(
      'page_title' => check_plain($page['page_title']),
      'page_path' => check_plain($page['page_path']),
      'menu_title' => check_plain($page['menu_title']),
      'delimiter' => check_plain($page['delimiter']),
      'expand' => check_plain($page['expand']),
      'sort' => check_plain($page['sort']),
      'is_disabled' => check_plain($page['is_disabled']),
    ))
    ->condition('p_uuid', $p_uuid)
    ->execute();

  $page_elements = $form_state['values']['elements'];
  foreach ($page_elements as $key => $page_element) {
    if ($page_element['me_uuid'] == '_new' && !empty($page_element['e_uuid'])) {
      _bibdk_custom_search_page_element_insert($p_uuid, $page_element);
    }
    if ($page_element['me_uuid'] !== '_new') {
      _bibdk_custom_search_page_element_update($p_uuid, $page_element);
    }
  }

  bibdk_custom_search_translate_update($page['menu_title'], 'menu_title');

  cache_clear_all('bibdk_custom_search', 'cache', TRUE);

  drupal_set_message(t('The page options have been saved.'));

  $form_state['redirect'] = 'admin/config/search/bibdk_custom_search/' . $p_uuid . '/edit';
}


/**
 * Search page element insert.
 */
function _bibdk_custom_search_page_element_insert($p_uuid, $page_element) {
  $result = FALSE;
  $result = db_insert('bibdk_custom_search_map_elements')
    ->fields(array(
      'me_uuid' => uuid_generate(),
      'p_uuid' => $p_uuid,
      'e_uuid' => $page_element['e_uuid'],
      'region' => check_plain($page_element['region']),
      'sort' => (int) $page_element['sort'],
    ))
    ->execute();
  return $result;
}

/**
 * Search page element update.
 */
function _bibdk_custom_search_page_element_update($p_uuid, $page_element) {
  $result = FALSE;
  $result = db_update('bibdk_custom_search_map_elements')
    ->fields(array(
      'region' => check_plain($page_element['region']),
      'sort' => (int) $page_element['sort'],
    ))
    ->condition('me_uuid', $page_element['me_uuid'])
    ->execute();
  if ($result) {
    $result = FALSE;
    $result = db_update('bibdk_custom_search_elements')
      ->fields(array(
        'is_disabled' => (isset($page_element['is_disabled'])) ? (int) $page_element['is_disabled'] : 0,
      ))
      ->condition('e_uuid', $page_element['e_uuid'])
      ->execute();
  }
  return $result;

}

/**
 * Load a bibdk_custom_search page.
 *
 * @param $p_uuid
 *   The page ID.
 * @return
 *   An array with the pages's data.
 */
function bibdk_custom_search_page_load($p_uuid) {
  return db_select('bibdk_custom_search', 'p')
    ->addTag('translatable')
    ->fields('p')
    ->condition('p_uuid', $p_uuid, '=')
    ->execute()
    ->fetchAssoc();
}
