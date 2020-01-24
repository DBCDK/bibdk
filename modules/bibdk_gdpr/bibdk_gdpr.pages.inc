<?php

/**
 * @file
 * Frontend forms and menu callbacks for bibdk_gdpr module.
 */

/**
 * Create render array for GDPR info page.
 *
 * @return array
 */
function bibdk_gdpr_callback() {
  $items = module_invoke_all('bibdk_gdpr_items');
  uasort($items, 'drupal_sort_weight');
  $render_array['#theme'] = 'bibdk_gdpr_theme';
  $render_array['#header'] = t('gdpr_header', array(), array('context' => 'bibdk_gdpr'));
  $render_array['#intro'] = t('gdpr_intro', array(), array('context' => 'bibdk_gdpr'));
  $render_array['#extro'] = t('gdpr_extro', array(), array('context' => 'bibdk_gdpr'));
  $render_array['#values'] = $items;
  $render_array['#print_button_value'] = t('label_gdpr_print', array(), array('context' => 'bibdk_gdpr'));
  drupal_add_js(drupal_get_path('module', 'bibdk_gdpr') . '/js/bibdk_gdpr.js');
  drupal_add_css(drupal_get_path('module', 'bibdk_gdpr') . '/css/bibdk_gdpr.css', array('media' => 'all'));
  return $render_array;
}

/**
 * Ajax menu callback for assigning consent.
 */
function bibdk_gdpr_consent_ajax() {
  global $user;
  if (ding_user_is_provider_user($user) && !empty($_POST['consent'])) {
    ding_provider_invoke('user', 'set_gdpr_consent', $user->mail, TRUE);
    $_SESSION['bibdk_gdpr_consent'] = TRUE;
    return drupal_json_output(array('consent' => 1));
  }
  return drupal_json_output(array('consent' => 0));
}
