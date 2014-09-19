<?php

/**
 * @file
 * Hooks provided by the Bibdk_mypage module.
 */

/**
 * @addtogroup hooks
 * @{
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
 * @} End of "addtogroup hooks".
 */










