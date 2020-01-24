<?php
/**
 * @file
 * bibliotek_dk_user_alert_features.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function bibliotek_dk_user_alert_features_default_fe_block_settings() {
  $export = array();

  $export['version'] = '1.0';

  // Theme independent visibility settings.
  $export['visibility'] = array(
    'user_alert-user_alert' => array(
      'delta' => 'user_alert',
      'module' => 'user_alert',
    ),
  );

  // bibdk_theme
  $theme = array();

  $theme['user_alert-user_alert'] = array(
    'module' => 'user_alert',
    'delta' => 'user_alert',
    'theme' => 'bibdk_theme',
    'status' => '1',
    'weight' => '0',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '<none>',
    'cache' => -1,
    'i18n_mode' => '0',
  );

  $export['theme']['bibdk_theme'] = $theme;

  $theme_default = variable_get('theme_default', 'garland');
  $themes = list_themes();
  foreach ($export as $theme_key => $settings) {
    if ($theme_key != $theme_default && empty($themes[$theme_key]->status)) {
      unset($export['theme'][$theme_key]);
    }
  }
  return $export;
}
