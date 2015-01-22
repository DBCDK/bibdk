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
 * @param array $work_types
 * @param $uid
 * @return string
 */
function bibdk_reservation_order_any_edition_link($collection, $work_types, $uid) {

  $uid = strtolower(preg_replace('/[^a-zA-Z0-9]+/', '', $uid));

  $table = array(
    '#theme' => 'table',
    '#header' => array(),
    '#rows' => array(),
  );

  $rows = array();

  $svg_icons = array(
    "article",
    "audiobook",
    "book",
    "emat",
    "game",
    "movie",
    "music",
    "sheetmusic",
  );
  // nb: may also be 'other'

  foreach ($collection as $type => $ids) {
    $row = array();
    $mat_type = t($type, array(), array('context' => 'material_type'));

    foreach ( $work_types as $svg_key => $work_type ) {
      if ( in_array($ids[0], $work_type) ) {
        $svg = ( in_array($svg_key, $svg_icons) ) ? 'svg-media-' . $svg_key : NULL;
        break;
      }
    }

    if ( !_bibdk_reservation_is_mattype_order_ok(ucfirst($mat_type)) ) {
      // make "not for order" text
      $row['label_mat']['data'] = array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => array('not-for-order'),
        ),
        'content' => array(
          '#theme' => 'span_with_svg',
          '#content' => array(
            '#markup' => $mat_type,
          ),
          '#attributes' => array(),
          '#svg' => $svg,
        ),
      );
      $row['order_mat']['data'] = array(
        '#type' => 'container',
        'content' => array(
          '#markup' => t('can not be ordered', array(), array('context' => 'bibdk_reservation')),
        ),
        '#attributes' => array(),
      );
    }
    else {
      $row['label_mat']['data'] = array(
        '#theme' => 'span_with_svg',
        '#content' => array(
          '#markup' => ucfirst($mat_type),
        ),
        '#attributes' => array('class'=>array('mat-type')),
        '#svg' => $svg,
      );
      $row['order_mat']['data'] = _bibdk_reservation_create_type_button($mat_type, $ids, $uid);
    }
    $hook = module_invoke_all('order_any_btn_lists', $type, $ids);

    foreach ( $hook as $column => $element ) {
      $col_name = t($column, array(), array('context' => 'bibdk_reservation'));
      $row[$column . '_mat']['data'] = $element;
    }

    $table['#rows'][]['data'] = $row;

  }

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

  $link = array(
    '#theme' => 'link',
    '#text' => $text,
    '#path' => 'reservation',
    '#options' => array(
      'query' => array('ids' => implode(',', $ids)),
      'attributes' => array(
        'id' => 'any_edtion_order_' . strtolower(preg_replace('/[^a-zA-Z0-9]+/', '', $ids[0])),
        'aria-label' => $text . ' ' . $type,
        'alt' => $text . ' ' . $type,
        'data-rel' => array(
          'reservation'
        ),
        'class' => array(
          'bibdk-popup-order-work',
          'bibdk-popup-link',
          'btn',
          'btn-blue',
        ),
      ),
      'html' => FALSE,
    ),
  );

  return $link;
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
