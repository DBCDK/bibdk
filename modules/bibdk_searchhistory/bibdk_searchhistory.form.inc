<?php

/**
 * @file
 * Create the tableselect form with searchresults and possibly saved searches
 *
 * @param array $form
 * @param $form_state
 * @return array $form
 */
function bibdk_searchhistory_form($form, $form_state) {
  drupal_set_title(t('Searchhistory'));

  $elements = BibdkSearchHistory::getAllElements();
  $search_views = bibdk_searchhistory_get_views($elements);

  $form['#attributes']['class'] = array(
    'searchhistory',
  );

  $header = array(
    'search_string' => t('Search string'),
    'result_count' => t('Result count'),
    'memolist' => t('Save'),
  );

  $form['actions'] = bibdk_searchhistory_get_primary_actions(array());

  $form['bibdk_searchhistory_form']['bibdk_search_history_table'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $search_views,
    '#empty' => array('#markup' => '' . t('No searches executed yet')),
    '#js_select' => FALSE,
    '#sticky' => FALSE,
    '#multiple' => TRUE,
    '#attributes' => array(
      'class' => array(
        'table',
        'combine-select',
        'element-wrapper',
        'search-history-table',
      ),
    ),
  );

  $radios = array(CQL_AND => t('Combine "And"'), CQL_OR => t('Combine "Or"'));

  $form['bibdk_searchhistory_form']['and_or_radios'] = array(
    '#type' => 'radios',
    '#options' => $radios,
    '#default_value' => CQL_AND,
  );

  $form['bibdk_searchhistory_form']['delete_selected_buffer'] = array(
    '#type' => 'hidden',
    '#default_value' => '',
    '#attributes' => array('id' => 'delete-selected-buffer'),
  );

  $form['bibdk_searchhistory_form']['combine'] = array(
    '#type' => 'submit',
    '#value' => t('Combiner'),
    '#submit' => array('bibdk_searchhistory_form_combine'),
    '#attributes' => array(
      'class' => array(
        'search-action-list'
      ),
      'disabled' => TRUE
    ),
  );

  //Adding JavaScript
  $form['#attached']['js'] = array(
    drupal_get_path('module', 'bibdk_searchhistory') . '/js/bibdk_searchhistory.js',
  );

  return $form;
}

function bibdk_searchhistory_get_primary_actions() {

  $elements = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'search-action-list',
      ),
    ),
  );

  $elements['select_all'] = array(
    '#type' => 'link',
    '#title' => t('mark_all_none', array(), array('context' => 'bibdk_cart')),
    '#title_display' => 'invisible',
    '#href' => '',
    '#options' => array(
      'attributes' => array(
        'class' => array(
          'select-all'
        ),
        'title' => t('mark_all_none', array(), array('context' => 'bibdk_cart'))
      ),
    ),
  );

  $elements['delete_selected'] = array(
    '#type' => 'link',
    '#title' => t('delete_selected', array(), array('context' => 'bibdk_cart')),
    '#title_display' => 'invisible',
    '#href' => '',
    '#options' => array(
      'attributes' => array(
        'class' => array(
          'delete-selected'
        ),
        'title' => t('delete_selected', array(), array('context' => 'bibdk_cart'))
      ),
    ),
  );

  return $elements;
}

/**
 * Form callback function. Removes selected entries from $_SESSION['searches] array and deletes posts in db if necessary
 * Used to be activated by a submit button.
 *
 * @param array $form
 * @param array $form_state
 * @return array
 */
function bibdk_searchhistory_form_delete($form, &$form_state) {
  $searches = $form_state['values']['bibdk_search_history_table'];
  $commands = array();
  foreach ($searches as $search => $string) {
    if ($search) {
      $element = BibdkSearchHistory::getElement($string);
      $commands[] = bibdk_searchhistory_ajax_command('input[value=' . $string . ']');
      // Remove from session
      if (isset($element)) {
        BibdkSearchHistory::removeElementFromSession($element);
      }

      // remove from webservice
      if (isset($element['id'])) {
        BibdkSearchHistory::removeElementFromWebservice($element);
        BibdkSearchHistory::removeElementFromSession($element);
      }
    }
  }

  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * @param array $form
 * @param array $form_state
 */
function bibdk_searchhistory_form_combine($form, $form_state) {
  if ( $form_state['values']['delete_selected_buffer'] == 'delete' ) {
    bibdk_searchhistory_form_delete($form, $form_state);
    return FALSE;
  }
  $searches = $form_state['values']['bibdk_search_history_table'];
  $combined = array();
  $combinator = $form_state['values']['and_or_radios'];
  $params_combinator = ' ' . t('params_combinator_placeholder', array(), array('context' => 'bibdk_searchhistory')) . ' ';
  foreach ($searches as $search => $string) {
    if ($string) {
      $element = BibdkSearchHistory::getElement($string);
      $keys = _bibdk_searchhistory_get_search_string($element, TRUE);

      $params = (!empty($element['params'])) ? str_replace('<br />', $params_combinator, bibdk_searchhistory_parse_params($element['params'])) : array();

      if (!empty($keys) && !empty($params)) {
        $string = $keys . $params_combinator . $params;
      }
      else {
        $string = (!empty($keys)) ? $keys : $params;
      }

      $combined[] = "($string)";
    }
  }

  $new_string = implode($combinator, $combined);

  drupal_goto('search/work/' . $new_string);
}

/**
 * Helper function to add enclosing parentheses to strings with spaces and/or parentheses
 *
 * Parentheses in input string are already balanced.
 *
 * @param $string
 * @return string
 */
function _bibdk_searchhistory_format_combine_string($string) {
  $stack = array();
  $tokens = preg_split('/([() ])/', trim($string), 0, PREG_SPLIT_DELIM_CAPTURE);

  foreach ($tokens as $token) {
    if ($token == ')') {
      while (array_pop($stack) != '(') {
      }
    }
    else {
      array_push($stack, $token);
    }
  }

  if (count($stack) == 1 || count($stack) == 2 && $stack[0] == '' && $stack[1] == '') {
    return $string;
  }
  else {
    return '(' . $string . ')';
  }
}

/** Generates a view for each element in the search history
 *
 * @param $element
 * @return array
 */
function _bibdk_searchhistory_element_view($element) {
  $count = $element['count'];
  $memolist = bibdk_searchhistory_action_link($element);

  $string = _bibdk_searchhistory_get_search_string($element, TRUE);
  $link = !empty($string) ? 'search/work/' . $string : 'search/work/';

  $display = _bibdk_searchhistory_get_markup_for_search($element);

  return array(
    'search_string' => l($display, $link, array(
      'query' => (!empty($element['params'])) ? $element['params'] : array(),
      'html' => TRUE
    )),
    'result_count' => $count,
    'memolist' => drupal_render($memolist),
  );
}

/**
 * Create an add/remove button for logged in users
 *
 * @param $element
 * @return array
 */
function bibdk_searchhistory_action_link($element) {
  global $user;
  if (!ding_user_is_provider_user($user)) {
    return array(
      '#type' => 'markup',
      '#markup' => t('login to save'),
    );
  }
  static $count;
  $id = isset($element['id']) ? $element['id'] : 'unsaved_' . $count++;
  $serial_element = json_encode($element['string']);

  $render = array(
    '#type' => 'link',
    '#href' => '',
    '#title' => isset($element['id']) ? t('Remove') : t('Add'),
    '#options' => array(
      'attributes' => array(
        'element-id' => $id,
      ),
    ),
    '#ajax' => array(
      'path' => 'bibdk_searchhistory/ajax/' . $id . '/' . $serial_element,
      'callback' => 'bibdk_searchhistory_action_link_callback',
    ),
    '#attached' => array(
      'js' => array(drupal_get_path('module', 'bibdk_searchhistory') . '/js/bibdk_searchhistory.ajax.js'),
    ),
  );

  return $render;
}


/**
 * Ajax callback : add/remove search history element from webservice
 *
 * @param $unsaved_id
 * @param $serial_element
 */
function bibdk_searchhistory_action_link_callback($unsaved_id, $serial_element) {
  $string = json_decode($serial_element);
  $element = BibdkSearchHistory::getElement($string);
  if (!isset($element['id'])) {
    $element = BibdkSearchHistory::addElementToWebservice($element);
    $link = bibdk_searchhistory_action_link($element);
    $commands[] = ajax_command_replace('[element-id=' . $unsaved_id . ']', drupal_render($link));
  }
  else {
    BibdkSearchHistory::removeElementFromWebservice($element);
    $id = $element['id'];
    $commands[] = bibdk_searchhistory_ajax_command('[element-id=' . $id . ']');
  }

  $callback = array('#type' => 'ajax', '#commands' => $commands);
  ajax_deliver($callback);
}

/**
 * Ajax command to remove element from dom
 *
 * @param $selector
 * @return array
 */
function bibdk_searchhistory_ajax_command($selector) {
  return array(
    'command' => 'searchhistory_remove',
    'selector' => $selector,
  );
}

/**
 * Generate views from searchhistory elements
 *
 * @param $elements
 * @return array
 */
function bibdk_searchhistory_get_views($elements) {
  $views = array();
  foreach ($elements as $element) {
    $string = $element['string'];
    $views[$string] = _bibdk_searchhistory_element_view($element);
  }

  return $views;
}

/**
 * Checks if param is part of the string stored in th variable
 * search_history_accepted_params
 *
 * @param string $param
 * @param $accepted_params
 * @return bool
 */
function _bibdk_searchhistory_accecpted_param($param, $accepted_params) {
  foreach ($accepted_params as $accepted) {
    if (!empty($accepted) && strpos($param, $accepted) !== FALSE) {
      return TRUE;
    }
  }

  return FALSE;
}

/**
 * @param array $element
 * @return string
 */
function _bibdk_searchhistory_get_markup_for_search($element) {
  $params_markup = (!empty($element['params'])) ? bibdk_searchhistory_parse_params($element['params']) : array();
  $string = _bibdk_searchhistory_get_search_string($element);

  if (!empty($params_markup)) {
    if (!empty($string)) {
      $string .= '<br />';
    }
    $string .= $params_markup;
  }

  return $string;
}

/**
 * Parse search params into a string seperated by <br />'s to obtain a nicer
 * view
 *
 * @param array $params
 * @return string $string
 */
function bibdk_searchhistory_parse_params($params) {
  $string = '';

  $accepted_params = explode(',', variable_get('search_history_accepted_params', 'dkcclterm,term'));

  if (!empty($params['qe'])) {
    foreach ($params['qe'] as $param => $value) {
      if (_bibdk_searchhistory_accecpted_param($param, $accepted_params)) {
        if (!empty($string)) {
          $string .= '<br />';
        }
        $string .= $param . ' = ' . implode(', ', $value);
      }
    }
  }

  return $string;
}

/**
 * @param $element
 * @param bool $raw
 * @return string
 */
function _bibdk_searchhistory_get_search_string($element, $raw = FALSE) {
  $keys = explode('?', $element['string']);
  if (!$raw) {
    return (!empty($keys[0])) ? t('freetext_search', array(), array('context' => 'bibdk_searchhistory')) . ' = ' . $keys[0] : '';
  }

  return $keys[0];
}
