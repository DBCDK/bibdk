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
  switch ($type) {
    case "bibdkManifestation" :
      if ($entity->isReservable()) {
        $element['reservation'] = array(
          '#markup' => bibdk_reservation_link($entity->getIDs(), $entity->getSubType(), $type),
          '#weight' => -2,
        );
      }
      elseif ($entity->isLink()) {
        $accessUrlContainer = $entity->getSingleAccessUrl();

        $element['reservation'] = array(
          '#markup' => l(t('accessUrl', array(), array('context' => 'bibdk_reservation')), $accessUrlContainer['accessUrl'], array(
            'attributes' => array(
              'target' => '_blank',
              'class' => array('btn btn-grey')
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
