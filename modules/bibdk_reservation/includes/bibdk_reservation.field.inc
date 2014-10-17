<?php

/**
 * Implements hook_field_info().
 */
function bibdk_reservation_field_info() {
  return array(
    // Reservation buttons
    'bibdk_mani_reservation_button' => array(
      'label' => t('Reservation button.', array(), array('context' => 'bibdk_reservation')),
      'description' => t('Reservation button.', array(), array('context' => 'bibdk_reservation')),
      'default_widget' => 'hidden',
      'default_formatter' => 'bibdk_reservation_button_default',
      'no_ui' => TRUE,
    ),
    'bibdk_coll_reservation_button' => array(
      'label' => t('Reservation button.', array(), array('context' => 'bibdk_reservation')),
      'description' => t('Reservation button.', array(), array('context' => 'bibdk_reservation')),
      'default_widget' => 'hidden',
      'default_formatter' => 'bibdk_reservation_collection_button',
      'no_ui' => TRUE,
    ),
    /** I think the following field is irrelevant - should be deleted on refactoring /svi */
    // Reservation info field
    'bibdk_reservation_info' => array(
      'label' => t('Reservation info text', array(), array('context' => 'bibdk_reservation')),
      'description' => t('Information related to the reservation process', array(), array('context' => 'bibdk_reservation')),
      'default_widget' => 'hidden',
      'default_formatter' => 'bibdk_reservation_information_default',
      'no_ui' => TRUE,
    ),
  );
}

/**
 * Implements hook_field_load().
 */
function bibdk_reservation_field_load($entity_type, $entities, $field, $instances, $langcode, &$items, $age) {
  foreach ($entities as $id => $entity) {
    $items[$id][] = array(
      'id' => $entity->id
    );
  }
}

/**
 * Implements hook_field_formatter_info().
 */
function bibdk_reservation_field_formatter_info() {
  return array(
    // Reservation button
    'bibdk_reservation_button_default' => array(
      'label' => t('Default', array(), array('context' => 'bibdk_reservation')),
      'field types' => array(
        'bibdk_mani_reservation_button',
        'bibdk_sub_reservation_button'
      ),
    ),
    'bibdk_reservation_collection_button' => array(
      'label' => t('Default', array(), array('context' => 'bibdk_reservation')),
      'field types' => array(
        'bibdk_coll_reservation_button',
      ),
    ),
    // Information text
    'bibdk_reservation_information_default' => array(
      'label' => t('Default', array(), array('context' => 'bibdk_reservation')),
      'field types' => array(
        'bibdk_reservation_info',
      ),
    )
  );
}

/**
 * Implements hook_field_formatter_view().
 */
function bibdk_reservation_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();
  foreach ($items as $delta => $item) {
    switch ($display['type']) {
      case "bibdk_reservation_button_default" :
        if ($entity->isReservable()) {
          $element[$delta]['#markup'] = bibdk_reservation_link($entity->getIDs(), $entity->getSubType(), $entity_type);
        }
        elseif ($entity->isLink()) {
          $info = $entity->getAccessInformation();
          $element[$delta]['#markup'] = l(t('accessUrl', array(), array('context' => 'bibdk_reservation')), $info['accessUrl'][0], array('attributes' => array('target' => '_blank')));
        }
        break;
      case "bibdk_reservation_information_default" :
        $infotext = $entity->getInfotext();
        if (!isset($infotext)) {
          return;
        }
        $element[$delta]['#markup'] = _bibdk_reservation_render_infotext($infotext);
        break;
      case "bibdk_reservation_collection_button" :
        $element[$delta]['#markup'] = bibdk_reservation_order_any_edition_link($entity->getCollectionTypes(), $entity->getId());
        break;
    }
  }

  return $element;
}

/**
 * Returns a placeholder text for the given string
 *
 * @param $string
 * @return null|string
 */
function _bibdk_reservation_render_infotext($string) {
  $message = NULL;
  if(!empty($string)) {
    $message = bibdk_reservation_translate("drupal_text_" . $string);
  }
  return $message;
}
