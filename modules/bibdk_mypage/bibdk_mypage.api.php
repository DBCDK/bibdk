<?php

/**
 * @file
 * Hooks provided by the Bibdk_mypage module.
 */

/**
 * Get fieldsets from other modules.
 *
 * @param int $max_rows
 * @internal param $form
 * @internal param $form_state
 * @return array Render array
 */
function hook_bibdk_mypage_tabs($max_rows = 3) {

  global $user;

  $form['module_name'] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
    '#theme' => 'bibdk_mypage-form',
    '#attributes' => array('class' => array('element-wrapper', 'bibdk-mypage-wrapper')),
  );

  $form['module_name']['header'] = array(
    '#type' => 'markup',
    '#markup' => t('header'),
  );

  $form['module_name']['rows'] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
  );

  $cart = array();

  if (sizeof($array) > 0) {
    $array = array_slice($array, 0, $max_rows);
    foreach ($array as $id => $item) {
      $form['module_name']['rows'][$id] = array(
        'label_row' => array(
          '#type' => 'markup',
          '#markup' => $item->itemName,
        ),
        'value_row' => array(
          '#type' => 'markup',
          '#markup' => $item->itemValue,
        ),
      );
    }
  }
  else {
    $form['module_name']['rows'][] = array(
      'item_row' => array(
        '#type' => 'markup',
        '#markup' => t('No items in module'),
      ),
    );
  }

  $form['module_name']['link_profile2_tab'] = array(
    '#type' => 'link',
    '#title' => t('Go to tab'),
    '#title_display' => 'invisible',
    '#href' => 'user/' . $user->uid . '/edit/module_name_list',
    '#options' => array('attributes' => array('title' => t('Go to tab'))),
  );

  return $form;
}

/**
 * Define one or more items that should be accesible in the mypage sidebar menu.
 * Basically this hook should return an array of menu items knwon from
 * HOOK_menu() but during the processing of the hook all items will be set
 * with type = MENU_LOCAL_TASK, overriding any type that otherwise would have
 * been set.
 *
 * Below is used an example of how the hook is implemented in the bibdk_cart
 * module.
 *
 * At a minimum 'title' shopuld be set as well as the array key should be the
 * path for the given link item.
 *
 * @return array
 * @see bibdk_cart_mypage_link() in bibdk_cart.module
 */
function HOOK_mypage_link(){
  $items['user/%user/cart'] = array(
    'title' => 'Cart',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('bibdk_cart_view_form'),
    'access callback' => 'user_edit_access',
    'access arguments' => array(1),
    'weight' => 25,
  );

  return $items;
}










