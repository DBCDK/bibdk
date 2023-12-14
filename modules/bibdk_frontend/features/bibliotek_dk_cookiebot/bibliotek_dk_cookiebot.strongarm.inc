<?php

/**
 * @file
 * bibliotek_dk_cookiebot.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bibliotek_dk_cookiebot_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cookiebot_block_cookies';
  $strongarm->value = 1;
  $export['cookiebot_block_cookies'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cookiebot_cbid';
  $strongarm->value = '0945225b-6b16-4166-82dd-ea5947b897b3';
  $export['cookiebot_cbid'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cookiebot_cdn_location';
  $strongarm->value = 'eu';
  $export['cookiebot_cdn_location'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cookiebot_exclude_admin_theme';
  $strongarm->value = 0;
  $export['cookiebot_exclude_admin_theme'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cookiebot_exclude_paths';
  $strongarm->value = '';
  $export['cookiebot_exclude_paths'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cookiebot_exclude_uid_1';
  $strongarm->value = 0;
  $export['cookiebot_exclude_uid_1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cookiebot_iab_enabled';
  $strongarm->value = 0;
  $export['cookiebot_iab_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cookiebot_message_placeholder_cookieconsent_optout_marketing';
  $strongarm->value = array(
    'value' => 'Please <a href="!cookiebot_renew" class="cookieconsent-optout-marketing__cookiebot-renew">accept marketing-cookies</a> to view this embedded content from <a href="!cookiebot_from_src_url" target="_blank" class="cookieconsent-optout-marketing__from-src-url">!cookiebot_from_src_url</a>',
    'format' => 'html_5',
  );
  $export['cookiebot_message_placeholder_cookieconsent_optout_marketing'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cookiebot_message_placeholder_cookieconsent_optout_marketing_show';
  $strongarm->value = 0;
  $export['cookiebot_message_placeholder_cookieconsent_optout_marketing_show'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cookiebot_show_declaration';
  $strongarm->value = 0;
  $export['cookiebot_show_declaration'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cookiebot_show_declaration_node_id';
  $strongarm->value = '';
  $export['cookiebot_show_declaration_node_id'] = $strongarm;

  return $export;
}
