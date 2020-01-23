<?php

/**
 * @file
 * This file handles AJAX callbacks related to the bibdk_custom_search module
 */

function bibdk_custom_search_get_advanced_search_panel(){
  $_GET['deliver_search_panel_by_ajax'] = TRUE;
  $form = drupal_get_form('search_block_form');
  return render($form);
}