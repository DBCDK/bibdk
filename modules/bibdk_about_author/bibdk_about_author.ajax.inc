<?php
/**
 * @file
 * bibdk_about_author.ajax.inc
 */

/**
 * Return json object from ajax call
 */
function bibdk_about_author_ajax_get_about_author() {

  if ( empty($_REQUEST['query']) ) {

    $data['error']       = 'bibdk_about_author_empty_query'; // nb: don't translate!
    $data['error_msg']   = t('bibdk_about_author_empty_query_error', array(), array('context' => 'bibdk_about_author'));
    $data['toggle_text'] = t('bibdk_about_author_toggle_text_error', array(), array('context' => 'bibdk_about_author'));
    watchdog('bibdk_about_author', 'Empty query in AJAX call');

  }
  else {

    $data['query'] = $_REQUEST['query'];

    if ( $result = bibdk_about_author_get_about_author($_REQUEST['query']) ) {
      $data['list'] = drupal_render(bibdk_about_author_get_link_list_view($result));
    }
    else {
      $data['error']       = 'bibdk_about_author_no_records'; // nb: don't translate!
      $data['error_msg']   = t('bibdk_about_author_no_records', array(), array('context' => 'bibdk_about_author'));
      $data['toggle_text'] = t('bibdk_about_author_toggle_text_empty', array(), array('context' => 'bibdk_about_author'));
    }

  }

  drupal_json_output($data);
}
