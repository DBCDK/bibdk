<?php
/**
 * @file
 * bibliotek_dk_offcanvas_menu.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function bibliotek_dk_offcanvas_menu_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-offcanvas-menu-da.
  $menus['menu-offcanvas-menu-da'] = array(
    'menu_name' => 'menu-offcanvas-menu-da',
    'title' => 'Bibliotek.dk - Offcanvas Menu Dansk',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => '0',
  );
  // Exported menu: menu-offcanvas-menu-eng.
  $menus['menu-offcanvas-menu-eng'] = array(
    'menu_name' => 'menu-offcanvas-menu-eng',
    'title' => 'Bibliotek.dk - Offcanvas Menu Engelsk',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Bibliotek.dk - Offcanvas Menu Dansk');
  t('Bibliotek.dk - Offcanvas Menu Engelsk');


  return $menus;
}
