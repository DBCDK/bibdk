<?php
/**
 * @file
 * bibdk_language_settings.features.language.inc
 */

/**
 * Implements hook_locale_default_languages().
 */
function bibdk_language_settings_locale_default_languages() {
  $languages = array();

  // Exported language: da.
  $languages['da'] = array(
    'language' => 'da',
    'name' => 'Danish',
    'native' => 'Dansk',
    'direction' => '0',
    'enabled' => '1',
    'plurals' => '2',
    'formula' => '($n!=1)',
    'domain' => '',
    'prefix' => 'da',
    'weight' => '0',
  );
  // Exported language: en.
  $languages['en'] = array(
    'language' => 'en',
    'name' => 'English (Drupal)',
    'native' => 'English',
    'direction' => '0',
    'enabled' => '0',
    'plurals' => '0',
    'formula' => '',
    'domain' => '',
    'prefix' => 'en',
    'weight' => '0',
  );
  // Exported language: en-gb.
  $languages['en-gb'] = array(
    'language' => 'en-gb',
    'name' => 'English',
    'native' => 'English',
    'direction' => '0',
    'enabled' => '1',
    'plurals' => '2',
    'formula' => '($n!=1)',
    'domain' => '',
    'prefix' => 'eng',
    'weight' => '0',
  );
  return $languages;
}
