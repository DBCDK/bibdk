<?php

/**
 * Implements hook_bibdk_mypage_tabs().
 */
function bibdk_cart_bibdk_mypage_tabs($max_rows = 3) {
  global $user;

  $ret = array();
  $ret['bibdk_cart']['header'] = 'Cart';
  $ret['bibdk_cart']['rows']['values'] = bibdk_cart_my_page_get_rows($max_rows);
  $ret['bibdk_cart']['link'] = array(
    'title' => t('Go to cart', array(), array('context' => 'bibdk_cart')),
    'href' => 'user/' . $user->uid . '/cart',
  );
  $ret['bibdk_cart']['weight'] = 25;
  $ret['bibdk_cart']['help_text_key'] = 'cart_mypage_help_key';

  return $ret;
}

/**
 * @param $max_rows
 * @return array
 */
function bibdk_cart_my_page_get_rows($max_rows) {
  $cart = BibdkCart::getAll();
  $ret = array();

  if (empty($cart)) {
    $ret[] = array(
      'item_row' => t('No items in cart'),
    );
  }
  else {
    if (count($cart) > $max_rows) {
      $cart = array_slice($cart, 0, $max_rows, TRUE);
    }

    bibdk_cart_set_manifestations($cart);

    foreach ($cart as $id => $item) {
      $ret[] = array(
        'label_row' => isset($item->manifestation) ? $item->manifestation->getTitle() : '',
        'value_row' => '',
      );
    }
  }

  return $ret;
}

