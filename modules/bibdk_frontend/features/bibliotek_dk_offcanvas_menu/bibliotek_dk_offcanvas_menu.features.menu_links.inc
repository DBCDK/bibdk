<?php
/**
 * @file
 * bibliotek_dk_offcanvas_menu.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function bibliotek_dk_offcanvas_menu_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-offcanvas-menu-da:<front>
  $menu_links['menu-offcanvas-menu-da:<front>'] = array(
    'menu_name' => 'menu-offcanvas-menu-da',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Forside',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'devicetypes' => array(
        'devicesize_small' => 1,
        'devicesize_large' => 1,
        'devicesize_medium' => 1,
        'devicesize_xlarge' => 1,
        'devicesize_xxlarge' => 1,
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: menu-offcanvas-menu-da:http://statsbiblioteket.dk/videnskabeligeartikler/
  $menu_links['menu-offcanvas-menu-da:http://statsbiblioteket.dk/videnskabeligeartikler/'] = array(
    'menu_name' => 'menu-offcanvas-menu-da',
    'link_path' => 'http://statsbiblioteket.dk/videnskabeligeartikler/',
    'router_path' => '',
    'link_title' => 'Videnskabelige artikler',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'devicetypes' => array(
        'devicesize_small' => 0,
        'devicesize_large' => 1,
        'devicesize_medium' => 0,
        'devicesize_xlarge' => 1,
        'devicesize_xxlarge' => 1,
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-45',
  );
  // Exported menu link: menu-offcanvas-menu-da:overlay/help
  $menu_links['menu-offcanvas-menu-da:overlay/help'] = array(
    'menu_name' => 'menu-offcanvas-menu-da',
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
        'devicesize_medium' => 1,
        'devicesize_xlarge' => 1,
        'devicesize_xxlarge' => 1,
      ),
    ),
    'module' => 'menu',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
  );
  // Exported menu link: menu-offcanvas-menu-da:overlay/helpdesk
  $menu_links['menu-offcanvas-menu-da:overlay/helpdesk'] = array(
    'menu_name' => 'menu-offcanvas-menu-da',
    'link_path' => 'overlay/helpdesk',
    'router_path' => 'overlay/helpdesk',
    'link_title' => 'Spørg biblioteksvagten',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'devicetypes' => array(
        'devicesize_small' => 1,
        'devicesize_large' => 0,
        'devicesize_medium' => 1,
        'devicesize_xlarge' => 0,
        'devicesize_xxlarge' => 0,
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Exported menu link: menu-offcanvas-menu-da:user/cart
  $menu_links['menu-offcanvas-menu-da:user/cart'] = array(
    'menu_name' => 'menu-offcanvas-menu-da',
    'link_path' => 'user/cart',
    'router_path' => 'user/cart',
    'link_title' => 'Huskeliste',
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
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: menu-offcanvas-menu-da:user/login
  $menu_links['menu-offcanvas-menu-da:user/login'] = array(
    'menu_name' => 'menu-offcanvas-menu-da',
    'link_path' => 'user/login',
    'router_path' => 'user/login',
    'link_title' => 'Log ind',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'devicetypes' => array(
        'devicesize_small' => 1,
        'devicesize_large' => 0,
        'devicesize_medium' => 1,
        'devicesize_xlarge' => 0,
        'devicesize_xxlarge' => 0,
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-44',
  );
  // Exported menu link: menu-offcanvas-menu-da:vejviser
  $menu_links['menu-offcanvas-menu-da:vejviser'] = array(
    'menu_name' => 'menu-offcanvas-menu-da',
    'link_path' => 'vejviser',
    'router_path' => 'vejviser',
    'link_title' => 'Find bibliotek',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'devicetypes' => array(
        'devicesize_small' => 1,
        'devicesize_large' => 1,
        'devicesize_medium' => 1,
        'devicesize_xlarge' => 1,
        'devicesize_xxlarge' => 1,
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: menu-offcanvas-menu-eng:<front>
  $menu_links['menu-offcanvas-menu-eng:<front>'] = array(
    'menu_name' => 'menu-offcanvas-menu-eng',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'devicetypes' => array(
        'devicesize_small' => 1,
        'devicesize_large' => 1,
        'devicesize_medium' => 1,
        'devicesize_xlarge' => 1,
        'devicesize_xxlarge' => 1,
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: menu-offcanvas-menu-eng:http://statsbiblioteket.dk/videnskabeligeartikler/
  $menu_links['menu-offcanvas-menu-eng:http://statsbiblioteket.dk/videnskabeligeartikler/'] = array(
    'menu_name' => 'menu-offcanvas-menu-eng',
    'link_path' => 'http://statsbiblioteket.dk/videnskabeligeartikler/',
    'router_path' => '',
    'link_title' => 'Scientific articles',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'devicetypes' => array(
        'devicesize_small' => 0,
        'devicesize_large' => 1,
        'devicesize_medium' => 0,
        'devicesize_xlarge' => 1,
        'devicesize_xxlarge' => 1,
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-45',
  );
  // Exported menu link: menu-offcanvas-menu-eng:overlay/help
  $menu_links['menu-offcanvas-menu-eng:overlay/help'] = array(
    'menu_name' => 'menu-offcanvas-menu-eng',
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
        'devicesize_medium' => 1,
        'devicesize_xlarge' => 1,
        'devicesize_xxlarge' => 1,
      ),
    ),
    'module' => 'menu',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
  );
  // Exported menu link: menu-offcanvas-menu-eng:overlay/helpdesk
  $menu_links['menu-offcanvas-menu-eng:overlay/helpdesk'] = array(
    'menu_name' => 'menu-offcanvas-menu-eng',
    'link_path' => 'overlay/helpdesk',
    'router_path' => 'overlay/helpdesk',
    'link_title' => 'Ask helpdesk',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'devicetypes' => array(
        'devicesize_small' => 1,
        'devicesize_large' => 0,
        'devicesize_medium' => 1,
        'devicesize_xlarge' => 0,
        'devicesize_xxlarge' => 0,
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Exported menu link: menu-offcanvas-menu-eng:user/cart
  $menu_links['menu-offcanvas-menu-eng:user/cart'] = array(
    'menu_name' => 'menu-offcanvas-menu-eng',
    'link_path' => 'user/cart',
    'router_path' => 'user/cart',
    'link_title' => 'Cart',
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
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: menu-offcanvas-menu-eng:user/login
  $menu_links['menu-offcanvas-menu-eng:user/login'] = array(
    'menu_name' => 'menu-offcanvas-menu-eng',
    'link_path' => 'user/login',
    'router_path' => 'user/login',
    'link_title' => 'Log in',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'devicetypes' => array(
        'devicesize_small' => 1,
        'devicesize_large' => 0,
        'devicesize_medium' => 1,
        'devicesize_xlarge' => 0,
        'devicesize_xxlarge' => 0,
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-44',
  );
  // Exported menu link: menu-offcanvas-menu-eng:vejviser
  $menu_links['menu-offcanvas-menu-eng:vejviser'] = array(
    'menu_name' => 'menu-offcanvas-menu-eng',
    'link_path' => 'vejviser',
    'router_path' => 'vejviser',
    'link_title' => 'Find library',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'devicetypes' => array(
        'devicesize_small' => 1,
        'devicesize_large' => 1,
        'devicesize_medium' => 1,
        'devicesize_xlarge' => 1,
        'devicesize_xxlarge' => 1,
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Ask helpdesk');
  t('Cart');
  t('Find bibliotek');
  t('Find library');
  t('Forside');
  t('Help');
  t('Hjælp');
  t('Home');
  t('Huskeliste');
  t('Log in');
  t('Log ind');
  t('Scientific articles');
  t('Spørg biblioteksvagten');
  t('Videnskabelige artikler');


  return $menu_links;
}
