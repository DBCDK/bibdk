<?php
/**
 * @file
 * dbc_zabbix_configuration.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dbc_zabbix_configuration_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dbc_zabbix_settings';
  $strongarm->value = array(
    0 => array(
      'label' => 'SB Kopibesil',
      'url' => 'bibdk_sbkopi_place_copy_request_url',
    ),
    1 => array(
      'label' => 'Infomedia',
      'url' => 'ting_infomedia_url',
    ),
    2 => array(
      'label' => 'Autocomplete',
      'url' => 'bibdk_autocomplete_rest_url',
    ),
    3 => array(
      'label' => 'Ask Vopros',
      'url' => 'ask_vopros_uri',
    ),
    4 => array(
      'label' => ' Bibdk Behaviour',
      'url' => 'bibdk_behavoir_url',
    ),
  );
  $export['dbc_zabbix_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_checkall_enabled';
  $strongarm->value = 1;
  $export['zabbix_checkall_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_checkall_run_interval';
  $strongarm->value = '900';
  $export['zabbix_checkall_run_interval'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_dbc_zabbix_test_enabled';
  $strongarm->value = 1;
  $export['zabbix_dbc_zabbix_test_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_dbc_zabbix_test_last_run';
  $strongarm->value = 1456834610;
  $export['zabbix_dbc_zabbix_test_last_run'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_dbc_zabbix_test_run_interval';
  $strongarm->value = '900';
  $export['zabbix_dbc_zabbix_test_run_interval'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_dbc_zabbix_webservices_urls_enabled';
  $strongarm->value = 1;
  $export['zabbix_dbc_zabbix_webservices_urls_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_dbc_zabbix_webservices_urls_last_run';
  $strongarm->value = 1456922737;
  $export['zabbix_dbc_zabbix_webservices_urls_last_run'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_dbc_zabbix_webservices_urls_run_interval';
  $strongarm->value = '900';
  $export['zabbix_dbc_zabbix_webservices_urls_run_interval'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_host';
  $strongarm->value = 'jgn.dscrum.dbc.dk';
  $export['zabbix_host'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_machine_architecture';
  $strongarm->value = 'x86_64';
  $export['zabbix_machine_architecture'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_port';
  $strongarm->value = '10051';
  $export['zabbix_port'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_scheduling_enabled';
  $strongarm->value = 1;
  $export['zabbix_scheduling_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_server';
  $strongarm->value = 'zabbix.dbc.dk';
  $export['zabbix_server'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_count_active_users_enabled';
  $strongarm->value = 1;
  $export['zabbix_zabbix_count_active_users_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_count_active_users_run_interval';
  $strongarm->value = '900';
  $export['zabbix_zabbix_count_active_users_run_interval'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_count_all_nodes_enabled';
  $strongarm->value = 1;
  $export['zabbix_zabbix_count_all_nodes_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_count_all_nodes_run_interval';
  $strongarm->value = '900';
  $export['zabbix_zabbix_count_all_nodes_run_interval'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_count_all_users_enabled';
  $strongarm->value = 1;
  $export['zabbix_zabbix_count_all_users_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_count_all_users_run_interval';
  $strongarm->value = '900';
  $export['zabbix_zabbix_count_all_users_run_interval'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_count_published_nodes_enabled';
  $strongarm->value = 1;
  $export['zabbix_zabbix_count_published_nodes_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_count_published_nodes_run_interval';
  $strongarm->value = '900';
  $export['zabbix_zabbix_count_published_nodes_run_interval'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_count_sessions_auth_enabled';
  $strongarm->value = 1;
  $export['zabbix_zabbix_count_sessions_auth_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_count_sessions_auth_run_interval';
  $strongarm->value = '900';
  $export['zabbix_zabbix_count_sessions_auth_run_interval'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_last_admin_login_enabled';
  $strongarm->value = 1;
  $export['zabbix_zabbix_last_admin_login_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_last_admin_login_last_run';
  $strongarm->value = 1456922737;
  $export['zabbix_zabbix_last_admin_login_last_run'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_last_admin_login_run_interval';
  $strongarm->value = '900';
  $export['zabbix_zabbix_last_admin_login_run_interval'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_last_cron_run_enabled';
  $strongarm->value = 1;
  $export['zabbix_zabbix_last_cron_run_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_last_cron_run_run_interval';
  $strongarm->value = '900';
  $export['zabbix_zabbix_last_cron_run_run_interval'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_list_modules_enabled';
  $strongarm->value = 1;
  $export['zabbix_zabbix_list_modules_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_list_modules_run_interval';
  $strongarm->value = '900';
  $export['zabbix_zabbix_list_modules_run_interval'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_list_themes_enabled';
  $strongarm->value = 1;
  $export['zabbix_zabbix_list_themes_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_list_themes_run_interval';
  $strongarm->value = '900';
  $export['zabbix_zabbix_list_themes_run_interval'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_module_update_status_enabled';
  $strongarm->value = 1;
  $export['zabbix_zabbix_module_update_status_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_module_update_status_last_run';
  $strongarm->value = 1456922737;
  $export['zabbix_zabbix_module_update_status_last_run'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_module_update_status_run_interval';
  $strongarm->value = '900';
  $export['zabbix_zabbix_module_update_status_run_interval'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_php_watchdog_entries_enabled';
  $strongarm->value = 1;
  $export['zabbix_zabbix_php_watchdog_entries_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_php_watchdog_entries_run_interval';
  $strongarm->value = '900';
  $export['zabbix_zabbix_php_watchdog_entries_run_interval'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_watchdog_alerts_enabled';
  $strongarm->value = 1;
  $export['zabbix_zabbix_watchdog_alerts_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_watchdog_alerts_run_interval';
  $strongarm->value = '900';
  $export['zabbix_zabbix_watchdog_alerts_run_interval'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_watchdog_critical_enabled';
  $strongarm->value = 1;
  $export['zabbix_zabbix_watchdog_critical_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_watchdog_critical_run_interval';
  $strongarm->value = '900';
  $export['zabbix_zabbix_watchdog_critical_run_interval'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_watchdog_debug_enabled';
  $strongarm->value = 1;
  $export['zabbix_zabbix_watchdog_debug_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_watchdog_debug_run_interval';
  $strongarm->value = '900';
  $export['zabbix_zabbix_watchdog_debug_run_interval'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_watchdog_emergencies_enabled';
  $strongarm->value = 1;
  $export['zabbix_zabbix_watchdog_emergencies_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_watchdog_emergencies_run_interval';
  $strongarm->value = '900';
  $export['zabbix_zabbix_watchdog_emergencies_run_interval'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_watchdog_errors_enabled';
  $strongarm->value = 1;
  $export['zabbix_zabbix_watchdog_errors_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_watchdog_errors_run_interval';
  $strongarm->value = '900';
  $export['zabbix_zabbix_watchdog_errors_run_interval'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_watchdog_info_enabled';
  $strongarm->value = 1;
  $export['zabbix_zabbix_watchdog_info_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_watchdog_info_run_interval';
  $strongarm->value = '900';
  $export['zabbix_zabbix_watchdog_info_run_interval'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zabbix_zabbix_watchdog_notices_enabled';
  $strongarm->value = 1;
  $export['zabbix_zabbix_watchdog_notices_enabled'] = $strongarm;

  return $export;
}
