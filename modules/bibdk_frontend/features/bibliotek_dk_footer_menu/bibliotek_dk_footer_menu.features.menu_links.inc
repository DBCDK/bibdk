<?php

/**
 * @file
 * bibliotek_dk_footer_menu.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function bibliotek_dk_footer_menu_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-footer-menu-da_english:<front>.
  $menu_links['menu-footer-menu-da_english:<front>'] = array(
    'menu_name' => 'menu-footer-menu-da',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'English',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'devicetypes' => array(
        'devicesize_small' => 1,
        'devicesize_large' => 1,
      ),
      'identifier' => 'menu-footer-menu-da_english:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-footer-menu-da_hjlp:overlay/help.
  $menu_links['menu-footer-menu-da_hjlp:overlay/help'] = array(
    'menu_name' => 'menu-footer-menu-da',
    'link_path' => 'overlay/help',
    'router_path' => 'overlay/help',
    'link_title' => 'Hjælp',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'devicetypes' => array(
        'devicesize_small' => 1,
        'devicesize_large' => 1,
      ),
      'identifier' => 'menu-footer-menu-da_hjlp:overlay/help',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );
  // Exported menu link: menu-footer-menu-da_kontakt:overlay/help/1.
  $menu_links['menu-footer-menu-da_kontakt:overlay/help/1'] = array(
    'menu_name' => 'menu-footer-menu-da',
    'link_path' => 'overlay/help/1',
    'router_path' => 'overlay/help',
    'link_title' => 'Kontakt',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'devicetypes' => array(
        'devicesize_small' => 1,
        'devicesize_large' => 1,
      ),
      'identifier' => 'menu-footer-menu-da_kontakt:overlay/help/1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );
  // Exported menu link: menu-footer-menu-da_om-bibliotekdk:overlay/help/2.
  $menu_links['menu-footer-menu-da_om-bibliotekdk:overlay/help/2'] = array(
    'menu_name' => 'menu-footer-menu-da',
    'link_path' => 'overlay/help/2',
    'router_path' => 'overlay/help',
    'link_title' => 'Om bibliotek.dk',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'devicetypes' => array(
        'devicesize_small' => 1,
        'devicesize_large' => 1,
      ),
      'identifier' => 'menu-footer-menu-da_om-bibliotekdk:overlay/help/2',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );
  // Exported menu link: menu-footer-menu-da_presserum:https://www.rebelmouse.com/bibliotekdk/.
  $menu_links['menu-footer-menu-da_presserum:https://www.rebelmouse.com/bibliotekdk/'] = array(
    'menu_name' => 'menu-footer-menu-da',
    'link_path' => 'https://www.rebelmouse.com/bibliotekdk/',
    'router_path' => '',
    'link_title' => 'Presserum',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'devicetypes' => array(
        'devicesize_small' => 1,
        'devicesize_medium' => 1,
        'devicesize_large' => 1,
        'devicesize_xlarge' => 1,
        'devicesize_xxlarge' => 1,
      ),
      'identifier' => 'menu-footer-menu-da_presserum:https://www.rebelmouse.com/bibliotekdk/',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-footer-menu-da_privatlivspolitik:overlay/help/33.
  $menu_links['menu-footer-menu-da_privatlivspolitik:overlay/help/33'] = array(
    'menu_name' => 'menu-footer-menu-da',
    'link_path' => 'overlay/help/33',
    'router_path' => 'overlay/help',
    'link_title' => 'Privatlivspolitik',
    'options' => array(
      'fragment' => 'bestil',
      'attributes' => array(
        'title' => '',
      ),
      'devicetypes' => array(
        'devicesize_small' => 1,
        'devicesize_medium' => 1,
        'devicesize_large' => 1,
        'devicesize_xlarge' => 1,
        'devicesize_xxlarge' => 1,
      ),
      'identifier' => 'menu-footer-menu-da_privatlivspolitik:overlay/help/33',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-footer-menu-eng_about-bibliotekdk:overlay/help/29.
  $menu_links['menu-footer-menu-eng_about-bibliotekdk:overlay/help/29'] = array(
    'menu_name' => 'menu-footer-menu-eng',
    'link_path' => 'overlay/help/29',
    'router_path' => 'overlay/help',
    'link_title' => 'About bibliotek.dk',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'devicetypes' => array(
        'devicesize_small' => 1,
        'devicesize_large' => 1,
      ),
      'identifier' => 'menu-footer-menu-eng_about-bibliotekdk:overlay/help/29',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );
  // Exported menu link: menu-footer-menu-eng_contact:overlay/help/14.
  $menu_links['menu-footer-menu-eng_contact:overlay/help/14'] = array(
    'menu_name' => 'menu-footer-menu-eng',
    'link_path' => 'overlay/help/14',
    'router_path' => 'overlay/help',
    'link_title' => 'Contact',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'devicetypes' => array(
        'devicesize_small' => 1,
        'devicesize_large' => 1,
      ),
      'identifier' => 'menu-footer-menu-eng_contact:overlay/help/14',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );
  // Exported menu link: menu-footer-menu-eng_dansk:<front>.
  $menu_links['menu-footer-menu-eng_dansk:<front>'] = array(
    'menu_name' => 'menu-footer-menu-eng',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Dansk',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'devicetypes' => array(
        'devicesize_small' => 1,
        'devicesize_large' => 1,
      ),
      'identifier' => 'menu-footer-menu-eng_dansk:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-footer-menu-eng_help:overlay/help.
  $menu_links['menu-footer-menu-eng_help:overlay/help'] = array(
    'menu_name' => 'menu-footer-menu-eng',
    'link_path' => 'overlay/help',
    'router_path' => 'overlay/help',
    'link_title' => 'Help',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'devicetypes' => array(
        'devicesize_small' => 1,
        'devicesize_large' => 1,
      ),
      'identifier' => 'menu-footer-menu-eng_help:overlay/help',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );
  // Exported menu link: menu-footer-menu-eng_privacy-policy:overlay/help/33.
  $menu_links['menu-footer-menu-eng_privacy-policy:overlay/help/33'] = array(
    'menu_name' => 'menu-footer-menu-eng',
    'link_path' => 'overlay/help/33',
    'router_path' => 'overlay/help',
    'link_title' => 'Privacy policy',
    'options' => array(
      'fragment' => 'bestil',
      'attributes' => array(
        'title' => '',
      ),
      'devicetypes' => array(
        'devicesize_small' => 1,
        'devicesize_medium' => 1,
        'devicesize_large' => 1,
        'devicesize_xlarge' => 1,
        'devicesize_xxlarge' => 1,
      ),
      'identifier' => 'menu-footer-menu-eng_privacy-policy:overlay/help/33',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('About bibliotek.dk');
  t('Contact');
  t('Dansk');
  t('English');
  t('Help');
  t('Hjælp');
  t('Kontakt');
  t('Om bibliotek.dk');
  t('Presserum');
  t('Privacy policy');
  t('Privatlivspolitik');

  return $menu_links;
}
