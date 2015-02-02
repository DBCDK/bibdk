<?php
/**
 * @file
 * html_5_text_format.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function html_5_text_format_filter_default_formats() {
  $formats = array();

  // Exported format: HTML 5.
  $formats['html_5'] = array(
    'format' => 'html_5',
    'name' => 'HTML 5',
    'cache' => '0',
    'status' => '1',
    'weight' => '0',
    'filters' => array(
      'filter_autop' => array(
        'weight' => '-49',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_html' => array(
        'weight' => '-48',
        'status' => '1',
        'settings' => array(
          'allowed_html' => '<a> <em> <strong> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd> <div> <span> <hr> <img> <br><h1><h2><h3><h4>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_htmlcorrector' => array(
        'weight' => '-39',
        'status' => '1',
        'settings' => array(),
      ),
      'shortcode' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(
          'favourite_library' => 1,
        ),
      ),
    ),
  );

  return $formats;
}
