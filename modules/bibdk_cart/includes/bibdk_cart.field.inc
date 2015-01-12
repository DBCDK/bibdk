<?php


/**
 * @param $id
 * @return array
 */
function bibdk_cart_get_link($id, $linktext, $prefix) {
  if (!is_array($id)) {
    $id = array($id);
  }

  if (empty($id)) {
    return array();
  }

  $class = array('add-item-to-cart');
  $class += BibdkCart::checkInCart($id) ? array('in-cart') : array();

  $id = implode(',', $id);

  $link = array(
    '#theme' => 'link',
    '#text' => t($linktext, array(), array('context' => 'bibdk_reservation')),
    '#path' => '#' . $id,
    '#options' => array(
      'attributes' => array(
        'id' => array($prefix . '-' . drupal_html_id($id)),
        'data-cart-pid' => $id,
        'class' => $class,
      ),
      'html' => FALSE,
      'svg' => 'svg-star',
    ),
    '#weight' => 4,
  );
  drupal_add_js(drupal_get_path('module', 'bibdk_cart') . '/js/bibdk_cart.js');
  return $link;
}
