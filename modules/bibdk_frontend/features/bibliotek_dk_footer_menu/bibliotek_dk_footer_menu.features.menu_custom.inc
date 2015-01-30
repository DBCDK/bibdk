<?php
/**
 * @file
 * bibliotek_dk_footer_menu.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function bibliotek_dk_footer_menu_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-footer-menu-da.
  $menus['menu-footer-menu-da'] = array(
    'menu_name' => 'menu-footer-menu-da',
    'title' => 'Bibliotek.dk - Footer Menu Dansk',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => '0',
  );
  // Exported menu: menu-footer-menu-eng.
  $menus['menu-footer-menu-eng'] = array(
    'menu_name' => 'menu-footer-menu-eng',
    'title' => 'Bibliotek.dk - Footer Menu Engelsk',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Bibliotek.dk - Footer Menu Dansk');
  t('Bibliotek.dk - Footer Menu Engelsk');


  return $menus;
}
