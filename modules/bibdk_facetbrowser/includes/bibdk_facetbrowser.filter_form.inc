<?php
/**
 * @file
 * Holds methods for handling facet filtering
 */

function bibdk_facetbrowser_filter_form_submit($form, &$form_state){
  $query = bibdk_facet_browser_filter_form_parse_query($form, $form_state);
  $form_state['redirect'] = bibdk_facetbrowser_filter_form_get_redirect($query);
}

function bibdk_facetbrowser_filter_form_get_redirect($query){
  global $base_root;
  $path = $base_root.base_path() . 'search/work';
  $url = url($path, array('query'=>$query));
  return preg_replace('/\%5B\d+\%5D/', '%5B%5D',$url);
}

function bibdk_facet_browser_filter_form_parse_query($form, $form_state){
  $title = $form['#title'];
  $facet_name = $form['#facet_name'];
  $facet_key = $form['#facet_key'];
  $current_url = _bibdk_facetbrowser_parseRequestUri();
  $url = parse_url($current_url);
  parse_str($url['query'], $query);

  // Find and remove facets that have been deselected
  $unset = bibdk_facetbrowser_filter_facets_to_remove($form, $form_state, $query);
  if(!empty($query['facets'])) {
    $query['facets'] = array_diff($query['facets'], $unset);
  }

  if(empty($form_state['input'][$facet_key])){
    return $query;
  }

  foreach( $form_state['input'][$facet_key] as $name => $selected){
    if(empty($selected[0])){
      $facet_value = '!' . $facet_name . ':' . $name;
      if(!in_array($facet_value, $query)) {
        $query['facets'][] = $facet_value;
      }
    }
    else{
      $facet_value =  $facet_name . ':' . $name;
      if(!in_array($facet_value, $query)) {
        $query['facets'][] = $facet_value;
      }
      $query['facets'][] = $facet_name . ':' . $name;
    }
  }
  return $query;
}

/**
 * Find the facet that has been deselected
 * @param $form
 * @param $form_state
 * @param $query
 */
function bibdk_facetbrowser_filter_facets_to_remove($form, $form_state, $query){
  $unset_me = array();

  if(empty($query['facets'])) {
    return $unset_me;
  }

  $facet_keys = array_flip($query['facets']);
  $group_key = $form['#facet_key'];

  foreach($form['#options'] as $name => $link){
    $facet_string = $form['#facet_name'] . ':' . $name;
     if(isset($facet_keys[$facet_string]) && !isset($form_state['values'][$group_key][$name])){
       // facet is in original query, but has been deselected; unset
       $unset_me[$facet_keys[$facet_string]] = $facet_string;
     }
  }

  return $unset_me;
}

function bibdk_facetbrowser_filter_form_column_headlines(){
  $output['container'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('checkbox-elements-header clear'),
    ),
  );

  $output['container']['select'] = array(
    '#type' => 'html_tag',
    '#tag' => 'span',
    '#value' => t('label_facet_select', array(), array('context' => 'bibdk_facetbrowser')),
  );

  $output['container']['deselect'] = array(
    '#type' => 'html_tag',
    '#tag' => 'span',
    '#value' => t('label_facet_deselect', array(), array('context' => 'bibdk_facetbrowser')),
  );

  $output['#weight'] = 2;

  return $output;


}


/**
 * @param $form
 * @param $form_state
 */
function bibdk_facetbrowser_filter_form($form, $form_state, $facet_name) {
  // submit button
  $form['actions']['submit'] = bibdk_facetbrowser_filter_form_submit_button();
  // column text
  $form['headlines'] = bibdk_facetbrowser_filter_form_column_headlines();
  // Get configured title.
  $form['#title'] = bibdk_facetbrowser_filter_form_get_title($facet_name);
  // Keep facetname
  $form['#facet_name'] = $facet_name;
  // Keep key for the fieldset
  $name_parts = explode('.', $facet_name);
  $name_key = $name_parts[1];
  $form['#facet_key'] = $name_key;
  // get given facetgroup
  $group = ting_openformat_get_facet_group($facet_name);
  // Get the fieldset
  $field_set = bibdk_facetbrowser_get_single_facetgroup($group->facets[$facet_name], $form['#title']);


  $form['#options'] = $field_set[$form['#facet_key']]['#options'];
  // Get the key for the fieldset facet

  $field_set['#weight'] = 3;
  $field_set[$name_key]['#facet_key'] =  $name_key;
  // keep selected and deselected facets
  $field_set[$name_key]['#selected_facets'] = bibdk_facetbrowser_filter_form_selected_facets();
  $field_set[$name_key]['#deselected_facets'] = bibdk_facetbrowser_filter_form_deselected_facets();
  $field_set[$name_key]['#facet_name'] = $facet_name;
  // Unset the 'checkboxes' type.
  unset($field_set[$name_key]['#type']);
  //$field_set['column_headline'] = bibdk_facetbrowser_filter_form_column_headlines();
  // Give the facet a theme (@ see theme/facetbrowser-filter-form-element.tpl.php)
  $field_set[$name_key]['#theme'] = 'bibdk_facetbrowser_multicolumns_checkboxes';
  $form['checkbox-elements'] = $field_set;

  // attach the stylesheet
  $form['#attached']['css'][] =
    drupal_get_path('module', 'bibdk_facetbrowser') . '/css/facetbrowser_filter_form.css';
  return $form;
}


function bibdk_facetbrowser_filter_form_deselected_facets(){
  return bibdk_facetbrowser_filter_form_selected_facets(FALSE);
}

function bibdk_facetbrowser_filter_form_selected_facets($selected=TRUE) {
  $uri_facets = _bibdk_facetbrowser_getFacets();
  $facets = _bibdk_facetbrowser_isFacetSelected($uri_facets, $selected);
  if(empty($facets)){
    return array();
  }
  // we index by name value
  foreach($facets as $facet){
    $ret[$facet['value']] = $facet['name'];
  }
  return $ret;
}


function bibdk_facetbrowser_filter_form_submit_button(){
  return array(
    '#type' => 'submit',
    '#value' => t('label_facet_save', array(), array('context' => 'bibdk_facetbrowser')),
    '#attributes' => array(
      'class' => array('btn btn-blue save-facet-modal'),
    ),
    '#submit' => array('bibdk_facetbrowser_filter_form_submit'),
    '#weight' => 1,
  );
}

function bibdk_facetbrowser_filter_form_get_title($facet_name){
  $title = '';
  $conf_facets = variable_get('bibdk_facetbrowser_facets', array());
  foreach ($conf_facets as $conf) {
    if ($conf['name'] == $facet_name) {
      $title = $conf['title'];
      break;
    }
  }
  return $title;
}






