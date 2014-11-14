<?php

/**
 * Adds or removes the requsted pid to/from the cart. If no pid is given an error ís returned
 * Called when user clicks a add_to_cart / remove_from_cart link
 * Outputs json formatted $data array
 */
function bibdk_cart_add_to_cart() {
  if (!isset($_REQUEST['pid']) || empty($_REQUEST['pid'])) {
    $data['error'] = TRUE;
    drupal_json_output($data);
    return;
  }

  $pids = $_REQUEST['pid'];
  if (BibdkCart::checkInCart($pids)) {
    BibdkCart::remove($pids);
    $saved = 0;
  }
  else {
    $object = new BibdkCartElement();
    $object->setElement($pids);
    BibdkCart::add($object);
    $saved = 1;
  }

  $data['saved'] = $saved;
  $data['pid'] = $pids;
  $data['classid'] = strtolower(strtr($pids, array(':' => '-')));
  $data['cartcount'] = BibdkCart::getCartCount();

  drupal_json_output($data);
}

/**
 * Deletes the requested pids from the cart
 * Outputs json formatted $data array
 */
function bibdk_cart_delete_selected() {

  if (!isset($_REQUEST['pids']) || empty($_REQUEST['pids'])) {
    $data['error'] = TRUE;
    drupal_json_output($data);
    return;
  }

  $pids = $_REQUEST['pids'];

  if (!is_array($pids)) {
    $pids = array($pids);
  }

  foreach ($pids as $pid) {
    BibdkCart::remove($pid);
  }

  $data['cartcount'] = BibdkCart::getCartCount();
  drupal_json_output($data);
}
