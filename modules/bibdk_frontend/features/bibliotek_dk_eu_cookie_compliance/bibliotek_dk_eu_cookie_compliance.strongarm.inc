<?php

/**
 * @file
 * bibliotek_dk_eu_cookie_compliance.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bibliotek_dk_eu_cookie_compliance_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'eu_cookie_compliance';
  $strongarm->value = array(
    'popup_enabled' => 1,
    'method' => 'opt_in',
    'info_template' => 'new',
    'cookie_categories' => '',
    'enable_save_preferences_button' => 1,
    'save_preferences_button_label' => 'Save preferences',
    'accept_all_categories_button_label' => 'Accept all cookies',
    'fix_first_cookie_category' => 1,
    'select_all_categories_by_default' => 0,
    'disabled_javascripts' => 'profiles/bibdk/modules/bibdk_frontend/matomo/matomo.js
https://stats.dbc.dk/piwik.js
https://static.hotjar.com/c/hotjar-1787658.js?sv=6
https://script.hotjar.com/modules.f622ea0eeded5efcf120.js',
    'whitelisted_cookies' => 'has_js
UUID',
    'consent_storage_method' => 'do_not_store',
    'popup_clicking_confirmation' => FALSE,
    'popup_info' => array(
      'value' => '<p><b>Vi bruger cookies til at indsamle statistik over brugen af hjemmesiden. </b></p>
<p>Hvis du klikker på knappen \'Accepter\', godkender du, at vi sætter cookies til brug for statistik.</p>
<p>Statistikdata opsamles i vores eget system og deles ikke med andre.</p>
<p>Hvis du klikker på knappen \'Afvis\', sætter vi ikke cookies til statistik.</p>
<p>Vi benytter dog en cookie for at huske dit valg.</p>',
      'format' => 'html_5',
    ),
    'use_mobile_message' => 0,
    'mobile_popup_info' => array(
      'value' => '<h2>We use cookies on this site to enhance your user experience</h2><p>By tapping the Accept button, you agree to us doing so.</p>',
      'format' => 'plain_text',
    ),
    'mobile_breakpoint' => '768',
    'popup_agree_button_message' => 'Accepter',
    'show_disagree_button' => TRUE,
    'popup_disagree_button_message' => 'Læs mere om vores brug af cookies',
    'disagree_button_label' => 'Afvis',
    'withdraw_enabled' => 1,
    'withdraw_button_on_info_popup' => 0,
    'withdraw_message' => array(
      'value' => '<h2>We use cookies on this site to enhance your user experience</h2><p>You have given your consent for us to set cookies.</p>',
      'format' => 'plain_text',
    ),
    'withdraw_tab_button_label' => 'Privatlivsindstillinger',
    'withdraw_action_button_label' => 'Tilbagetræk cookie accept',
    'popup_agreed_enabled' => 0,
    'popup_hide_agreed' => 1,
    'popup_agreed' => array(
      'value' => '<p>Tak fordi du accepterer at vi bruger cookies. Du kan skjule denne besked eller læse mere om cookies.</p>',
      'format' => 'html_5',
    ),
    'popup_find_more_button_message' => 'More info',
    'popup_hide_button_message' => 'Hide',
    'popup_link' => 'https://bibliotek.dk/da/overlay/help/73',
    'popup_link_new_window' => 1,
    'popup_position' => FALSE,
    'use_bare_css' => 0,
    'popup_text_hex' => 'ffffff',
    'popup_bg_hex' => '0779BF',
    'popup_height' => '',
    'popup_width' => '100%',
    'fixed_top_position' => 1,
    'popup_delay' => '1000',
    'disagree_do_not_show_popup' => 0,
    'reload_page' => 0,
    'popup_scrolling_confirmation' => FALSE,
    'cookie_name' => '',
    'domains_option' => '1',
    'domains_list' => '',
    'exclude_paths' => '',
    'exclude_admin_pages' => 0,
    'exclude_uid_1' => 0,
    'script_scope' => 'footer',
    'better_support_for_screen_readers' => 0,
    'cookie_session' => 0,
  );
  $export['eu_cookie_compliance'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'eu_cookie_compliance_cookie_lifetime';
  $strongarm->value = '100';
  $export['eu_cookie_compliance_cookie_lifetime'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'eu_cookie_compliance_domain';
  $strongarm->value = '';
  $export['eu_cookie_compliance_domain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'eu_cookie_compliance_domain_all_sites';
  $strongarm->value = 0;
  $export['eu_cookie_compliance_domain_all_sites'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'see_the_banner';
  $strongarm->value = array(
    1 => '1',
    2 => '2',
    4 => 0,
    3 => 0,
  );
  $export['see_the_banner'] = $strongarm;

  return $export;
}
