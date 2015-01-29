<?php

/**
 * @file
 * Theme functions used with the bibdk search carousel.
 */

/**
 * Implements default preprocess function for the search carsousel.
 */
function template_preprocess_bibdk_search_carousel(&$vars, $hook) {

  // Quickfix to avoid notices from template_process;
  $vars['classes_array'] = array();
  $vars['attributes_array'] = NULL;
  $vars['title_attributes_array'] = NULL;
  $vars['content_attributes_array'] = NULL;

  $path = drupal_get_path('module', 'bibdk_search_carousel');

  drupal_add_css($path . '/css/owl.carousel.css');
  drupal_add_css($path . '/css/owl.theme.css');
  drupal_add_css($path . '/css/bibdk_search_carousel.css');

  drupal_add_js($path . '/js/owl.carousel.min.js');
  drupal_add_js($path . '/js/bibdk_search_carousel.js');

  // Load toggle configuration.
  $toggle = variable_get('bibdk_search_carousel_description_toggle', FALSE);
  $vars['toggle_description'] = $toggle ? 'rs-carousel-wide' : 'rs-carousel-compact';
}
