<?php
/** Ajax callback
 *
 * @param $term_type
 * @param $facet_term
 * @param $facet_type
 * @return array|mixed
 */
function bibdk_custom_search_list_ajax_callback($term_type, $facet_term, $facet_type) {

  $term_type = urldecode($term_type);
  return bibdk_custom_search_list_select_form($facet_type, $facet_term, $term_type);
}


/** Returns a link, a list of options and a list of form elements, for a defined
 * facet
 *
 * @param $facet_type type of facet e.g. facet.type
 * @param $term_type Sets the parent of the returned elements
 * @param array $default_values elements that has a default value
 * @param array $ignore_values elements that should not be returned
 * @return array Render-array
 */
function bibdk_custom_search_get_list_options($facet_type, $term_type, $default_values = array()) {
  $facet_type_decoded = urldecode($facet_type);
  if (strpos($facet_type_decoded, '=')) {
    $exploded = explode('=', $facet_type_decoded);
    $facet_term = $exploded[0];
    $facet_type = $exploded[1];
  }
  else {
    $facet_term = $term_type;
  }
  $form = array();
  if (isset($default_values[$term_type])){
    $form += bibdk_custom_list_create_default_checkboxes($default_values[$term_type]);
  }
  $form += bibdk_custom_search_list_link($facet_term, $facet_type, $term_type);
  return $form;

}

/** Creates default value checkboxes
 *
 * @param $default_values
 * @return array
 */
function bibdk_custom_list_create_default_checkboxes($default_values) {

  $return = array();
  foreach ($default_values as $value) {
    $label = explode('=', $value);
    $return[$value] = array(
      '#type' => 'checkbox',
      '#default_value' => $value,
      '#title' => t($label[1], array(), array('context' => 'material_type')),
      '#return_value' => $value,
      '#attributes' => array(),
    );
  }
  return $return;
}

/** Wrapper function: fetches options from webservice and adds them to a pop-up form
 *
 * @param $facet_type
 * @param $facet_term
 * @param $term_type
 * @param array $ignore_values
 * @return array|mixed
 */
function bibdk_custom_search_list_select_form($facet_type, $facet_term, $term_type, $ignore_values = array()) {
  // Get options from webservice
  $result = bibdk_custom_search_list_from_webservice($facet_type);
  // Create options array with webservice result
  $options = bibdk_custom_search_list_options($result, $facet_term, $ignore_values);
  // If no options are set we do not return form elements
  if (empty($options)) {
    return array();
  }

  $options = bibdk_custom_search_list_options_translate($options);

  // Create form
  return bibdk_custom_search_get_list_popup_form($options, $facet_type, $term_type);
}

/** Get elements from webservice
 *
 * @param $type  type of facet e.g. facet.type
 * @param int $number_requested number of elements to request from service
 * @return bool|stdClass|string
 */
function bibdk_custom_search_list_from_webservice($type, $number_requested = 1000) {

  $cache_key = 'bibdk_custom_search_list_from_webservice' . $type;
  if ($cache = cache_get($cache_key, 'cache')) {
    return $cache->data;
  }

  $params = array(
    'query' => '*',
    'facets' => $type,
    'numFacets' => $number_requested,
    'numResults' => 0,
    'objectFormat' => 'DKABM',
  );

  $client = new ting_client_class();

  $result = $client->do_request('search', $params);
  $facets = isset($result->facets[$type]) ? $result->facets[$type]->terms : array();

  if (!empty($facets)) {
    cache_set($cache_key, $facets, 'cache');
  }

  return $facets;

}

/** Returns a list of custom search options as an a array where:
 * key = value & ignore values are omitted
 *
 *
 * @param $type
 * @return array
 */
function bibdk_custom_search_list_options($result, $term_type, $ignore_values) {
  if (!is_array($result) || empty($result)) {
    return array();
  }

  $options = array();
  $result = array_keys($result);
  // Set keys = values in options array
  foreach ($result as $option) {
    $options[$term_type . '=' . $option] = $option;
  }

  // Sort alphabetically
  ksort($options);

  // We don't want double values in view
  $options = array_diff($options, $ignore_values);

  return $options;

}

function bibdk_custom_search_list_options_translate($options) {
  foreach ($options as $key => $option) {
    $options[$key] = t($option, array(), array('context' => 'material_type'));
  }

  return $options;
}

/** Create form with more options as a pop-over box
 *
 * @param $options
 * @param $facet_type
 * @return mixed
 */
function bibdk_custom_search_get_list_popup_form($options, $facet_type, $term_type) {

  $type_id = str_replace('.', '-', $facet_type);
  $id = 'custom-search-options-list-' . $type_id;
  $form['pop-over'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => $id,
      'class' => array('custom-search-options-list'),
    ),
  );

  $form['pop-over']['header'] = array(
    '#theme' => 'html_tag',
    '#tag' => 'h3',
    '#value' => t('add options to ' . $facet_type, array(), array('context' => 'bibdk_custom_search')),
  );

  $form['pop-over']['two-panel-multi-select'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('panel-select'),
    ),
    '#tree' => FALSE,
  );

  $form['pop-over']['two-panel-multi-select']['from'] = array(
    '#type' => 'select',
    '#multiple' => true,
    '#options' => $options,
    '#size' => 20,
    '#attributes' => array(
      'id' => array('select-from-list-' . $type_id),
    ),
  );

  $form['pop-over']['two-panel-multi-select']['actions'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('list-actions'),
    ),
  );

  $form['pop-over']['two-panel-multi-select']['actions']['add_button'] = array(
    '#type' => 'button',
    '#value' => t('add >>', array(), array('context' => 'bibdk_custom_search')),
    '#executes_submit_callback' => false,
    '#attributes' => array(
      'class' => array('custom-search-list-action'),
      'data-action-move-from' => array('select-from-list-' . $type_id),
      'data-action-move-to' => array('select-to-list-' . $type_id),
    ),
  );

  $form['pop-over']['two-panel-multi-select']['actions']['remove_button'] = array(
    '#type' => 'button',
    '#value' => t('<< remove', array(), array('context' => 'bibdk_custom_search')),
    '#executes_submit_callback' => false,
    '#attributes' => array(
      'class' => array('custom-search-list-action'),
      'data-action-move-from' => array('select-to-list-' . $type_id),
      'data-action-move-to' => array('select-from-list-' . $type_id),
    ),
  );

  $form['pop-over']['two-panel-multi-select']['to'] = array(
    '#type' => 'select',
    '#multiple' => true,
    '#options' => array(),
    '#size' => 20,
    '#attributes' => array(
      'id' => array('select-to-list-' . $type_id),
    ),
  );

  $form['pop-over']['close_button'] = array(
    '#type' => 'button',
    '#value' => t('close', array(), array('context' => 'bibdk_custom_search')),
    '#executes_submit_callback' => false,
    '#attributes' => array(
      'class' => array('custom-search-list-close'),
      'data-id' => $id,
    ),
  );

  $form['pop-over']['save_button'] = array(
    '#type' => 'button',
    '#value' => t('save', array(), array('context' => 'bibdk_custom_search')),
    '#executes_submit_callback' => false,
    '#attributes' => array(
      'class' => array('custom-search-list-save'),
      'data-action-selected' => array('select-to-list-' . $type_id),
      'data-action-send-to' => array($facet_type . '-options-array'),
      'data-type' => array('n/a' . $type_id),
      'data-type-wrapper' => array($term_type),
    ),
  );

  return $form;
}

/** Adds link that fetches popupform via ajax
 *
 * @param $facet_term
 * @param $facet_type
 * @param $term_type
 * @return array
 */
function bibdk_custom_search_list_link($facet_term, $facet_type, $term_type) {
  $type_id = str_replace('.', '-', $facet_type);
  $id = 'custom-search-options-list-' . $type_id;
  $wrapper_id = 'add_options_list-' . $type_id;

  $form = array();

  $form['add_options_list-' . $term_type] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => $wrapper_id,
    ),
  );

  $form['container-link-' . $type_id] = array(
    '#type' => 'link',
    '#title' => t('see all options'),
    '#href' => '',
    '#name' => 'op-' . $type_id,
    '#attributes' => array(
      'class' => array('popover-button-list', 'button-as-link'),
      'data-id' => $id,
    ),
    '#ajax' => array(
      'path' => "bibdk_custom_search/ajax/list/" . urlencode($term_type) . "/$facet_term/$facet_type",
      'wrapper' => $wrapper_id,
      'method' => 'replace',
      'event' => 'click',
    ),
    '#attached' => array(
      'js' => array(
        drupal_get_path('module', 'bibdk_custom_search') . '/js/bibdk_custom_search_list.js',
      ),
    ),
  );

  return $form;
}

