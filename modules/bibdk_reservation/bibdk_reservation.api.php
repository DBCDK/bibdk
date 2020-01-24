<?php

/**
 * @file
 * Hooks provided by the bibdk_reservation module.
 */

/**
 * actions to perform when a reservation has been done successfully
 * @param type $pids
 * @param type $result
 */
function hook_bibdk_reservation_complete($pids, $result) {
  // example from bibdk_openuserstatus.module :
  // refresh $_SESSION variables when an order is completed  
  $library = BibdkReservationOrderObject::GetObject()->getBranchId();
  if (strpos($library, 'DK-') === 0) {
    // strip 'DK-' from librarynumber
    $library = substr($library, 3, strlen($library));
  }
  if (isset($_SESSION['userStatus'][$library])) {
    unset($_SESSION['userStatus'][$library]);
  }
}

/**
 * Definition of hook_order_any_btn_lists().
 * Makes it possible for other modules to add content to the
 * 'Order any edition' button shown on each collection.
 *
 * Any content given in a render array could be added, as it will be rendered
 * by the drupal_render() method.
 * Note that the structure given in the example below should be used as the key
 * ('header_of_the_column' in the example below) will be translated and used as
 * header for the column.
 *
 * @param string $type    The material type of the material associated with the
 *                        given $ids.
 *
 * @param array $ids      Array with the $ids associated with the current
 *                        material.
 *
 * @return array $item    Render array of any kind.
 *                        @see includes/common.inc - drupal_render();
 */
function hook_order_any_btn_lists($type, $ids) {

  $item = array(
    'header_of_the_column' => array(
      '#theme' => 'any_theme_you_would_like_to_use',
    )
  );

  return $item;
}
