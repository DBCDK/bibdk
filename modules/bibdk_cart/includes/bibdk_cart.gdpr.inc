<?php

/**
 * @file
 * Hooks provided by the bibdk_gdpr module.
 */

/**
 * Implements hook_bibdk_gdpr_items().
 *
 * @return array
 */
function bibdk_cart_bibdk_gdpr_items() {
  $items['bibdk_cart']['#weight'] = 40;
  $items['bibdk_cart']['#header'] = t('label_gdpr_cart', array(), array('context' => 'bibdk_gdpr'));
  $items['bibdk_cart']['#theme'] = 'bibdk_gdpr_item_theme';
  if ($rows = bibdk_cart_gdpr_get_rows()) {
    $items['bibdk_cart']['#content'] = $rows;
  }
  else {
    $items['bibdk_cart']['#content'] = array(
      '#type' => 'container',
      'text' => array(
        '#markup' => t('label_no_cart', array(), array('context' => 'bibdk_gdpr'))
      ),
    );
  }
  return $items;
}


/**
 * @return array
 */
function bibdk_cart_gdpr_get_rows() {
  $cart = BibdkCart::getAll();
  $ret = array();

  if (empty($cart)) {
    return false;
  }
  
  bibdk_cart_set_manifestations($cart);

  $counter = 1;
  foreach ($cart as $id => $item) {
    $ret[] = array(
      '#type' => 'container',
      'label' => array(
        '#type' => 'html_tag',
        '#tag' => 'span',
        '#value' => $counter
      ),
      'value' => array(
        '#type' => 'html_tag',
        '#tag' => 'span',
        '#value' => isset($item->manifestation) ? $item->manifestation->getTitle() : ''
      ),
    );
    $counter++;
  }

  return $ret;
}

