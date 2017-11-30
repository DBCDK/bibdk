<?php


/** Implements hook_ting_openformat_actions
 * Add actions to work, subwork and manifestations
 * @param $type
 * @param $entity
 * @param $view_mode
 * @param $langcode
 * @return array
 */
function bibdk_reservation_ting_openformat_actions($type, $entity, $view_mode, $langcode) {
  $element = array();
  $subtype_order_ids = $entity->getSubtypeOrderIds();
  switch ($type) { 
    case "bibdkManifestation" :
      if ($entity->isReservable() || ($entity->isLink() && $entity->getRestrictedExtendedUse())) {
        $element['reservation'] = array(
          '#markup' => bibdk_reservation_link($entity, $type),
          '#weight' => -2,
        );
      }
      elseif ($entity->isLink()) {
        $accessUrlContainer = $entity->getSingleAccessUrl();
        $element['reservation'] = array(
          '#markup' => l(t('Order', array(), array('context' => 'bibdk_reservation')), $accessUrlContainer['accessUrl'], array(
            'attributes' => array(
              'target' => '_blank',
              'data-subtypeOrderIds' => implode(',', $subtype_order_ids),
              'class' => array('btn btn-blue')
            )
          )),
          '#weight' => -2,
        );
      }
      break;
    case "bibdk_reservation_collection_button" :
      // TODO: add collection reservation button to actions
      break;
  }

  return $element;
}
