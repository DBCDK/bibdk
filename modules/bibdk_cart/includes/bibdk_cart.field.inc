<?php


/**
 * @param $id
 * @return array
 */
function bibdk_cart_get_link($id) {
  if (!is_array($id)) {
    $id = array($id);
  }

  if (empty($id)) {
    return array();
  }

  if (BibdkCart::checkInCart($id)) {
    $title = t('remove_item_from_cart');
  }
  else {
    $title = t('add_item_to_cart');
  }
  $id = implode(',', $id);
  $link = array(
    '#href' => '#' . $id,
    '#title' => $title,
    '#data-pid' => $id,
    '#weight' => 4,
  );
  drupal_add_js(drupal_get_path('module', 'bibdk_cart') . '/js/bibdk_cart.js');
  return $link;
}
