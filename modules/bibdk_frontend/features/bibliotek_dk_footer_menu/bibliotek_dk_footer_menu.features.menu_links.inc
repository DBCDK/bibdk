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

  // Exported menu link: menu-footer-menu-da:<front>
  $menu_links['menu-footer-menu-da:<front>'] = array(
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
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Exported menu link: menu-footer-menu-da:overlay/help
  $menu_links['menu-footer-menu-da:overlay/help'] = array(
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
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: menu-footer-menu-da:overlay/help/1
  $menu_links['menu-footer-menu-da:overlay/help/1'] = array(
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
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: menu-footer-menu-da:overlay/help/2
  $menu_links['menu-footer-menu-da:overlay/help/2'] = array(
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
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: menu-footer-menu-eng:<front>
  $menu_links['menu-footer-menu-eng:<front>'] = array(
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
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Exported menu link: menu-footer-menu-eng:overlay/help
  $menu_links['menu-footer-menu-eng:overlay/help'] = array(
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
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: menu-footer-menu-eng:overlay/help/14
  $menu_links['menu-footer-menu-eng:overlay/help/14'] = array(
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
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: menu-footer-menu-eng:overlay/help/29
  $menu_links['menu-footer-menu-eng:overlay/help/29'] = array(
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
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
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


  return $menu_links;
}
