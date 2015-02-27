<?php
/**
 * @file
 * Functions for mobile bibdk_facetbrowser.
 */


function log_to_file($text) {
  $f = fopen('/home/jgn/jgn.ding/sites/default/files/log.txt', 'a');
  fwrite($f, date('Ymd H:i:s - ') . print_r($text,1) . "\n");
  fclose($f);
}


/**
 * mobile facetbrowser theme function
 *
 * @param array $all_facets
 * @return string
 */
function theme_theme_bibdk_facetbrowser_mobile($search_result = FALSE) {
  $all_facets = array_shift($search_result);
  $searchkey = array_shift($search_result);
  $elements = array();
  if ( is_array($all_facets) ) {
    $form = drupal_get_form('bibdk_facetbrowser_form', $all_facets, $searchkey);
  }
  return drupal_render($form);
}


/** Render array with facet groups for mobile
 * @return array
 */
function bibdk_facetbrowser_mobile_form($form, $form_state) {

  $form = array();
  $selected_facets_present = FALSE; 

  $client = new ting_client_class();
  $params = !empty($_SESSION['latest_search']['params']) ? $_SESSION['latest_search']['params'] : NULL;;
  $results = new stdClass();
  $results->search_key = !empty($_SESSION['latest_search']['search_key']) ? $_SESSION['latest_search']['search_key'] : NULL;
  $results->cacheKey   = !empty($_SESSION['latest_search']['cache_key'])  ? $_SESSION['latest_search']['cache_key']  : NULL;

  if ( module_exists('ting_openformat') ) {
    _ting_openformat_facet_cache($client, $results, $params);
  }

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
            'class' => array('facet-wrapper'),
          ),
        );
        
        $form[$key]['facet_wrapper'] = array(
          '#type' => 'container',
          '#attributes' => array(
            'id' => str_replace('.', '-mobile-', $facet->name),
            'class' => array('facet-name-wrapper'),
            'data-name' => array($facet->name),
            'data-count' => count($facet->terms)
          ),
        );

        $form[$key]['facet_wrapper']['facet_name_wrapper'] = array(
          '#type' => 'container',
        );

        $form[$key]['facet_wrapper']['facet_name_wrapper']['title'] = array(
          '#type' => 'markup',
          '#markup' => t($configured_facet['title'], array(), array('context' => 'facet_titles')),
        );

        if ( !empty($selected_facets[$facet->name]) ) {

log_to_file($selected_facets[$facet->name]);

          $n = count($selected_facets[$facet->name]); 

          if ( $n > 1 ) {
            $form[$key]['facet_wrapper']['facet_selected_wrapper'] = array(
              '#type' => 'container',
            );
            $form[$key]['facet_name_wrapper']['selected'] = array(
              '#type' => 'markup',
              '#markup' => t("%n seleced facets", array('%n'=>$n), array('context' => 'bibdk_facetbrowser')),
            );
          }

          if ( $n == 1 ) {
            // Check if term name is longer than 14 chars,
            // if so, short it down to fit facetbrowser
            $substr_length = 19 + substr_count(drupal_substr($selected_facets[$facet->name][0], 0, 20), 'l') + strtolower(substr_count(drupal_substr($selected_facets[$facet->name][0], 0, 20), 'i'));
            if (drupal_strlen($selected_facets[$facet->name][0]) > $substr_length + 3) {
              $selected_facets[$facet->name][0] = drupal_substr($selected_facets[$facet->name][0], 0, $substr_length) . '...';
            }
            $form[$key]['facet_wrapper']['facet_selected_wrapper'] = array(
              '#type' => 'container',
            );
            $form[$key]['facet_wrapper']['facet_selected_wrapper']['selected'] = array(
              '#type' => 'markup',
              '#markup' => $selected_facets[$facet->name][0],
            );
          }

        }

      }
    }
  }

  return $form;
}

