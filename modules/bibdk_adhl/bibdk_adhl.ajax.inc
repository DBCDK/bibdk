<?php
/**
 * @file
 * bibdk_adhl.ajax.inc
 */

/**
 * Return json object from ajax call
 */
function bibdk_adhl_ajax_get_recommendations() {

  if ( empty($_REQUEST['pid']) ) {

    $data['error']       = 'bibdk_adhl_unknown_error'; // nb: don't translate!
    $data['error_msg']   = t('bibdk_adhl_unknown_error', array(), array('context' => 'bibdk_adhl'));
    $data['toggle_text'] = t('bibdk_adhl_toggle_text_error', array(), array('context' => 'bibdk_about_author'));
    watchdog('bibdk_adhl', 'Empty PID in AJAX call', WATCHDOG_ERROR);

  }
  else {

    $data['pid'] = $_REQUEST['pid'];

    if ( $result = bibdk_adhl_get_adhl($data['pid'], 10) ) {
      $data['list'] = drupal_render(bibdk_adhl_get_link_list_view($result));
    }
    else {
      $data['error']       = 'bibdk_adhl_no_recommendations'; // nb: don't translate!
      $data['error_msg']   = t('bibdk_adhl_no_recommendations', array(), array('context' => 'bibdk_adhl'));
      $data['toggle_text'] = t('bibdk_adhl_toggle_text_empty', array(), array('context' => 'bibdk_adhl'));
    }

  }

  drupal_json_output($data);

}
