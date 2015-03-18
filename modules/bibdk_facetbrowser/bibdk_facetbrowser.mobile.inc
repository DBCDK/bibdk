<?php
/**
 * @file
 * Functions for mobile bibdk_facetbrowser.
 */


/** Render array with facet groups for mobile
 * @return array
 */
function bibdk_facetbrowser_mobile_form($form, $form_state) {

  $facet_group = FALSE;
  if (isset($form_state['input'])) {
    foreach ($form_state['input'] as $key => $input) {
      if ( substr($key,0,11) == 'facetgroup-' ) {
        $facet_group = substr($key,11);
        $facet_group = str_replace('_', '.', $facet_group);
      }
    }
  }

  if (!$facet_group) {
    $form = bibdk_facetbrowser_mobile_form_init($form, $form_state);
  } else {
    $form = bibdk_facetbrowser_mobile_form_values($form, $form_state, $facet_group);
  }

  return $form;

}


function bibdk_facetbrowser_mobile_redirect_uri($form_state, $reset_facets = FALSE) {

  $facet_group = $form_state['input']['facet_group'];

  $facet_values = array();
  foreach ($form_state['input'] as $input) {
    if ( is_array($input) && isset($input['facet_select']) ) {
      $key = key($input['facet_select']['actions']);
      $facet_values[$key] = $input['facet_select']['actions'][$key];
    }
  }

  $parse = parse_url($_SESSION['latest_search']['request_uri']);
  $query = explode('&', $parse['query']);
  foreach ($query as $key => $query_item) {
    $query[$key] = urldecode($query_item);
  }

  foreach ($facet_values as $facet_key => $checked) {
    if ($checked) {
      $query[] = 'facets[]=' . $facet_group . ':' . $facet_key;
    }
    else {
      foreach ($query as $key => $val) {
        if (strpos($val, $facet_group . ':' . $facet_key)) {
          unset($query[$key]);
        }
      }
    }
  }

  $url['path'] = 'search/work';

  foreach ($query as $key => $val) {
    $query_item = explode('=', $val, 2);
    $regex = '/^(facets\[)[\d]*(\])$/';
    $match = preg_match($regex, $query_item[0]);
    if (!$match) {
      $url['options']['query'][ $query_item[0] ] = $query_item[1];
    }
    else {
      $facets[] = $query_item[1];
    }
  }

  $facets = array_unique($facets);
  sort($facets);

  if (!$reset_facets) {
    $url['options']['query']['facets'] = $facets;
  }

  return $url;
}


/** Render array with facet groups for mobile
 * @return array
 */
function bibdk_facetbrowser_mobile_form_init($form, $form_state) {

  $form = array(
    '#theme' => 'theme_facets_mobile',
    '#attributes' => array(
      'class' => array('bibdk-facetbrowser-mobile', 'facet-group'),
    ),
  );

  $form['step'] = array(
    '#type' => 'hidden',
    '#value' => '1',
  );

  $client = new ting_client_class();
  $params = !empty($_SESSION['latest_search']['params']) ? $_SESSION['latest_search']['params'] : NULL;;
  $results = new stdClass();
  $results->search_key = !empty($_SESSION['latest_search']['search_key']) ? $_SESSION['latest_search']['search_key'] : NULL;
  $results->cacheKey   = !empty($_SESSION['latest_search']['cache_key'])  ? $_SESSION['latest_search']['cache_key']  : NULL;

  if ( module_exists('ting_openformat') ) {
    _ting_openformat_facet_cache($client, $results, $params);
  }

  $form['actions']['reset_facets'] = array(
    '#type'  => 'submit',
    '#name'  => 'reset_facets',
    '#value' => t('reset facets', array(), array('context' => 'bibdk_facetbrowser')),
    '#attributes' => array (
      'class' => array('use-ajax-submit', 'button-as-link', 'reset-facets'),
      'title' => t('reset facets', array(), array('context' => 'bibdk_facetbrowser')),
    ),
  );

  foreach (variable_get('bibdk_facetbrowser_facets', array()) as $configured_facet) {

    if ( isset($results->facets[$configured_facet['name']]) ) {

      $key = $configured_facet['title'];

      $facet = $results->facets[$configured_facet['name']];

      foreach ($facet->terms as $term_name => $term_count) {
        if ( _bibdk_facetbrowser_isFacetSet($facet->name, $term_name) === TRUE ) {
          $selected_facets[$facet->name][] = $term_name;
        }
      }

      if (count($facet->terms) > 0) {

        $form[$key] = array(
          '#type' => 'container',
          '#attributes' => array(
            'id' => str_replace('.', '-mobile-', $facet->name),
            'class' => array('facet-wrapper'),
            'data-name' => array($facet->name),
            'data-count' => count($facet->terms)
          ),
        );
        
        $form[$key]['facet_name'] = array(
          '#type' => 'container',
          '#attributes' => array(
            'class' => array('facet-name'),
          ),
        );

        $form[$key]['facet_name']['facet_name_label'] = array(
          '#type' => 'container',
          '#attributes' => array(
            'class' => array('facet-name-label'),
          ),
        );

        $form[$key]['facet_name']['facet_name_label']['title'] = array(
          '#type' => 'markup',
          '#markup' => t($configured_facet['title'], array(), array('context' => 'facet_titles')),
        );

        $form[$key]['facet_select'] = array(
          '#type' => 'container',
          '#attributes' => array(
            'class' => array('facet-select'),
          ),
        );

        $form[$key]['facet_select']['actions'] = array(
          '#type' => 'container',
          '#attributes' => array(
            'class' => array('facet-select-actions'),
          ),
        );

        $form[$key]['facet_select']['facet_selected_label'] = array(
          '#type' => 'container',
          '#attributes' => array(
            'class' => array('facet-select-label'),
          ),
        );

        if ( !empty($selected_facets[$facet->name] ) ) {
          $n = count($selected_facets[$facet->name]); 
          if ( $n > 1 ) {
            $form[$key]['facet_select']['facet_selected_label']['selected'] = array(
              '#type' => 'markup',
              '#markup' => t("%n seleced facets", array('%n'=>$n), array('context' => 'bibdk_facetbrowser')),
            );
          }
          if ( $n == 1 ) {
            // Check if term name is longer than 14 chars. If so, short it down to fit facetbrowser
            _bibdk_facetbrowser_shortstring($selected_facets[$facet->name][0], 14);
            $form[$key]['facet_select']['facet_selected_label']['selected_text'] = array(
              '#type' => 'markup',
              '#markup' => $selected_facets[$facet->name][0],
            );
          }
        }

        $form[$key]['facet_select']['actions']['submit2'] = array(
          '#type'  => 'submit',
          '#name'  => 'facetgroup-' . $configured_facet['name'],
          '#value' => t('select', array(), array('context' => 'bibdk_facetbrowser')),
          '#attributes' => array (
            'class' => array('use-ajax-submit'),
            'title' => t('Select facets', array(), array('context' => 'bibdk_facetbrowser')),
          ),
        );

      }
    }
  }

  $form['facet_group'] = array(
    '#type' => 'hidden',
    '#value' => NULL,
  );

  return $form;
}


/** Form render-array with facet values for mobile
 * @return array
 */
function bibdk_facetbrowser_mobile_form_values($form, $form_state, $facet_group) {

  $form = array(
    '#theme' => 'theme_facets_mobile',
    '#tree' => TRUE,
    '#attributes' => array(
      'class' => array('bibdk-facetbrowser-mobile', 'facet-values'),
    ),
  );

  $form['step'] = array(
    '#type' => 'hidden',
    '#value' => '2',
  );

  $client = new ting_client_class();
  $params = !empty($_SESSION['latest_search']['params']) ? $_SESSION['latest_search']['params'] : NULL;;
  $results = new stdClass();
  $results->search_key = !empty($_SESSION['latest_search']['search_key']) ? $_SESSION['latest_search']['search_key'] : NULL;
  $results->cacheKey   = !empty($_SESSION['latest_search']['cache_key'])  ? $_SESSION['latest_search']['cache_key']  : NULL;

  if ( module_exists('ting_openformat') ) {
    _ting_openformat_facet_cache($client, $results, $params);
  }

  foreach (variable_get('bibdk_facetbrowser_facets', array()) as $configured_facet) {

    if ( isset($results->facets[$configured_facet['name']]) && $configured_facet['name'] == $facet_group ) {

      $facet = $results->facets[$configured_facet['name']];

      $facet_group_title = &drupal_static('facet_group_title');
      $facet_group_title = $configured_facet['title'];

      foreach ($facet->terms as $term_name => $term_count) {

        $key = $term_name;
        $id = drupal_html_id('facet-value-name-' . $term_name);

        // Check if term name is longer than 34 chars. If so, short it down to fit facetbrowser
        _bibdk_facetbrowser_shortstring($term_name, 30);

        $form[$key] = array(
          '#type' => 'container',
          '#attributes' => array(
            'id' => 'mobile-facet-value-' . $term_name,
            'class' => array('facet-wrapper'),
          ),
        );


        $form[$key]['facet_name'] = array(
          '#type' => 'container',
          '#attributes' => array(
            'class' => array('facet-name'),
          ),
        );

        $form[$key]['facet_name']['facet_name_label'] = array(
          '#type' => 'container',
          '#attributes' => array(
            'class' => array('facet-name-label'),
          ),
        );

        _bibdk_facetbrowser_shortstring($term_name, 28);
        $form[$key]['facet_name']['facet_name_label']['title'] = array(
          '#type' => 'markup',
          '#markup' => $term_name,
        );

        $form[$key]['facet_name']['facet_count_label'] = array(
          '#type' => 'container',
          '#attributes' => array(
            'class' => array('facet-count-label'),
          ),
        );

        $form[$key]['facet_name']['facet_count_label']['count'] = array(
          '#type' => 'markup',
          '#markup' => $term_count,
        );

        $form[$key]['facet_select'] = array(
          '#type' => 'container',
          '#attributes' => array(
            'class' => array('facet-select'),
          ),
        );

        $form[$key]['facet_select']['actions'] = array(
          '#type' => 'container',
          '#attributes' => array(
            'class' => array('facet-select-actions'),
          ),
        );

        $form[$key]['facet_select']['actions'][$term_name] = array(
          '#type' => 'hidden',
          '#value' => _bibdk_facetbrowser_isFacetSet($facet->name, $term_name),
        );

        $form[$key]['facet_select']['actions']['checkmark_wrapper'] = array(
          '#type' => 'container',
          '#attributes' => array(
            'class' => array('facet-checkmark-wrapper'),
          ),
        );

        $class = (_bibdk_facetbrowser_isFacetSet($facet->name, $term_name)) ? 'checked' : '';
        $form[$key]['facet_select']['actions']['checkmark_wrapper']['checkmark'] = array(
          '#theme' => 'span_with_svg',
          '#content' => '',
          '#attributes' => array('class' => array($class), 'title' => t('select %term_name favet value', array('%term_name' => $term_name), array('context' => 'bibdk_facetbrowser'))),
          '#svg' => 'svg-checked',
        );

      }

    }

  }

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('actions-wrapper'),
    ),
  );

  $form['actions']['dummy'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('action-wrapper'),
    ),
    'dummy' => array(
      '#type' => 'markup',
      '#markup' => ' ',
    ),
  );

  $form['actions']['action'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('action-wrapper'),
    ),
  );

  $form['actions']['action']['submit'] = array(
    '#type'  => 'submit',
    '#name'  => 'facetgroup-' . $facet_group,
    '#value' => t('select and search', array(), array('context' => 'bibdk_facetbrowser')),
    '#attributes' => array (
      'class' => array('use-ajax-submit'),
      'title' => t('select and search', array(), array('context' => 'bibdk_facetbrowser')),
    ),
  );

  $form['facet_group'] = array(
    '#type' => 'hidden',
    '#value' => $facet_group,
  );

  return $form;

}


/** Helper function: Shorten string
 * @return string
 */
function _bibdk_facetbrowser_shortstring(&$string, $length) {
  $substr_length = $length + substr_count(drupal_substr($string, 0, $length), 'l') + strtolower(substr_count(drupal_substr($string, 0, $length), 'i')) - 1;
  if (drupal_strlen($string) > $substr_length + 3) {
    $string = drupal_substr($string, 0, $substr_length) . '...';
  }
  return $string;
}


/** Title on selected facet group mobile
 * @return string
 */
function bibdk_facetbrowser_mobile_form_title() {
  $selected_facet_group = &drupal_static('facet_group_title');
  return !empty($selected_facet_group) ? $selected_facet_group : NULL;
}
