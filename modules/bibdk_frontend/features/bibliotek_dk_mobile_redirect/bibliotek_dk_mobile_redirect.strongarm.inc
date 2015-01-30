<?php
/**
 * @file
 * bibliotek_dk_mobile_redirect.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bibliotek_dk_mobile_redirect_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_mobile_redirect_android';
  $strongarm->value = 'http://m.bibliotek.dk/';
  $export['simple_mobile_redirect_android'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_mobile_redirect_blackberry';
  $strongarm->value = 'http://m.bibliotek.dk/';
  $export['simple_mobile_redirect_blackberry'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_mobile_redirect_home';
  $strongarm->value = '/';
  $export['simple_mobile_redirect_home'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_mobile_redirect_ipad';
  $strongarm->value = 'http://m.bibliotek.dk/';
  $export['simple_mobile_redirect_ipad'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_mobile_redirect_iphone';
  $strongarm->value = 'http://m.bibliotek.dk/';
  $export['simple_mobile_redirect_iphone'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_mobile_redirect_mobileredirect';
  $strongarm->value = 'http://m.bibliotek.dk/';
  $export['simple_mobile_redirect_mobileredirect'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_mobile_redirect_opera';
  $strongarm->value = 'http://m.bibliotek.dk/';
  $export['simple_mobile_redirect_opera'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_mobile_redirect_palm';
  $strongarm->value = 'http://m.bibliotek.dk/';
  $export['simple_mobile_redirect_palm'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_mobile_redirect_windows';
  $strongarm->value = 'http://m.bibliotek.dk/';
  $export['simple_mobile_redirect_windows'] = $strongarm;

  return $export;
}
