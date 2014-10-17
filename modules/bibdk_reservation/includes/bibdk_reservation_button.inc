<?php
/**
 * @file
 * Functions for reservation buttons
 */

//include field info for button and infotext
module_load_include('inc', 'bibdk_reservation', 'includes/bibdk_reservation.field');

/**
 * Returns a link for reservation flow.
 * If more than one pid is present in $entity_ids a button will be
 *
 * @param $entity_ids
 * @param $subtype
 * @param $entity_type
 * @return bool|string
 */
function bibdk_reservation_link($entity_ids, $subtype, $entity_type) {
  $manifestations = explode(',', implode(',', $entity_ids));

  if (count($manifestations) >= 2) {
    $text = t("order_any_edition", array(), array('context' => 'bibdk_reservation'));
    $button_id = 'any_edition_' . $manifestations[0];
  }
  else {
    $translated_sub = t($subtype, array(), array('context' => 'bibdk_reservation'));
    $text = ($entity_type == "bibdkSubwork") ? $translated_sub : t("Order this @type", array("@type" => $translated_sub), array('context' => 'bibdk_reservation'));
    $button_id = 'this_edition_' . current($manifestations);
  }
  $path = 'reservation';
  $query = array('ids' => implode(',', $entity_ids));

  // This should be moved to the template
  $attributes['id'] = $button_id;
  $attributes['data-rel'] = 'reservation';
  $attributes['class'][] = 'bibdk-popup-link';
  $attributes['class'][] = 'btn';
  $attributes['class'][] = (isset($entity_type) && $entity_type == 'bibdkManifestation') ? 'btn-grey' : 'btn-blue';

  $link = array(
    '#theme' => 'link',
    '#text' => $text,
    '#path' => $path,
    '#options' => array(
      'query' => $query,
      'attributes' => $attributes,
      'html' => FALSE,
    ),
  );
  return drupal_render($link);
}

/**
 * Checks session for already ordered materials
 */
function bibdk_reservation_check_past_reservations($entity_ids) {
  if (isset($_SESSION['orderedPids'])) {
    foreach ($entity_ids as $pid) {
      if (in_array($pid, $_SESSION['orderedPids'])) {
        return TRUE;
        break;
      }
    }
  }

  return FALSE;
}

/**
 * Returns a link for 'reservation'Order any edition' button
 *
 * @param $collection
 * @param $uid
 * @return string
 */
function bibdk_reservation_order_any_edition_link($collection, $uid) {
  $uid = strtolower(preg_replace('/[^a-zA-Z0-9]+/', '', $uid));

  $header = array(
    '',
    t('Order', array(), array('context' => 'bibdk_reservation'))
  );
  $rows = array();

  foreach ($collection as $type => $ids) {
    $row = array();
    $mat_type = t($type, array(), array('context' => 'material_type'));

    if (!_bibdk_reservation_is_mattype_order_ok(ucfirst($mat_type))) {
      // make not for order text
      $note = array(
        '#prefix' => '<div class="not-for-order">',
        '#markup' => $mat_type,
        '#suffix' => '</div>',
      );
      $row[] = drupal_render($note);
      $order_btn = t('can not be ordered', array(), array('context' => 'bibdk_reservation')); //$order_btn;
      $row[] = $order_btn;
    }
    else {
      $row[] = ucfirst($mat_type);
      $order_btn = _bibdk_reservation_create_type_button($mat_type, $ids, $uid);
      $row[] = $order_btn;
    }
    $hook = module_invoke_all('order_any_btn_lists', $type, $ids);

    foreach ($hook as $column => $element) {
      $col_name = t($column, array(), array('context' => 'bibdk_reservation'));
      if (!in_array($col_name, $header)) {
        array_push($header, $col_name);
      }
      $row[] = drupal_render($element);
    }
    $rows[] = $row;
  }
  $table = theme('table', array('header' => $header, 'rows' => $rows));

  $infotext = _bibdk_reservation_infotext_order_any_edition_create_link($uid);

  $button = theme('bibdk_reservation_order_any_btn', array(
    'table' => $table,
    'addi_attributes' => array('id' => 'any_edition_but_' . $uid),
    'infotext' => $infotext,
    'hide' => empty($infotext) ? 'visuallyhidden' : '',
  ));

  return $button;
}


/**
 * Get a 'More info' link for placeholder_infotext_on_order_any_edition_btn
 */
function _bibdk_reservation_infotext_order_any_edition_create_link($uid=NULL) {

  $infotext['lead_text'] = array(
    '#type' => 'translatable',
    '#translate' => 'placeholder_infotext_on_order_any_edition_btn',
    '#options' =>  array('context' => 'bibdk_reservation'),
  );

  $infotext['link'] = array(
    '#theme' => 'link',
    '#text' => array(
      '#type' => 'translatable',
      '#translate' => 'More info',
      '#options' =>  array('context' => 'bibdk_reservation'),
    ),
    '#path' => '',
    '#weight' => 10,
    '#options' => array(
      'fragment' => $uid,
      'external' => TRUE,
      'attributes' => array(
        'class' => array(
          'infotext-order-any-edition-link',
        ),
        'id' => drupal_html_id('infotext_order_any_edition_link ' . $uid),
      ),
      'html' => FALSE,
    ),
  );

  return $infotext;
}



/**
 * Returns button with material type
 *
 * @param $type
 * @param $ids
 * @param $uid
 * @return string
 */
function _bibdk_reservation_create_type_button($type, $ids, $uid) {

  $text = t('Order', array(), array('context' => 'bibdk_reservation'));
  $path = 'reservation';
  $query = array('ids' => implode(',', $ids));
  $class = strtolower(preg_replace('/[^a-zA-Z0-9]+/', '', $ids[0]));

  $attributes = array(
    'data-rel' => array(
      'reservation'
    ),
    'class' => array(
      'bibdk-popup-order-work',
      'bibdk-popup-link',
      'btn',
      'btn-blue',
    ),
    'id' => array(
      'any_edtion_order_' . $class
    ),
    'aria-label' => $text . ' ' . $type,
  );

  return l($text, $path, array('attributes' => $attributes, 'query' => $query));
}


/**
 * Ckecks settings from admin Configuration -> Openformat -> Materiale types
 * @return boolean, TRUE ok for order - else FALSE
 */
function _bibdk_reservation_is_mattype_order_ok($text) {
  $mattypes = variable_get('bibdk_mattype_settings', array());
  foreach ($mattypes as $key => $mattype) {
    if ($mattype['name'] == $text) { return FALSE; }
  }
  return TRUE;
}
