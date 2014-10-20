<?php

/*
 * get AgencyInformation from favourites
 */
function bibdk_holdingstatus_get_agency_information($favourites){
  if ( !empty($favourites) )
  {
    foreach($favourites as $agencyId => $favourite){
      $information = $favourite->getInformation();
      if (isset($information)){
        $return[$information->getAgencyId()] = $information;
      }
    }
    return isset($return) ? $return : null;
  }
  return null;
}

/**
 * implements hook_ting_openformat_actions
 *
 * @param $type
 * @param $entity
 * @param $view_mode
 * @param $langcode
 * @return mixed
 */
function bibdk_holdingstatus_ting_openformat_actions($type, $entity, $view_mode, $langcode){
  // logged in users only
  global $user;
  if (!ding_user_is_provider_user($user)) {
    return;
  }

  $placeholder = bibdk_holdings_favourite_placeholder($entity->id);
  if ($type == 'bibdkManifestation'){
    $actions['favourite_holdings'] = array(
      '#markup' => drupal_render($placeholder),
      '#weight' => 1,
    );
    return $actions;
  }
}

/**
 * Return a placeholder to be replaced by an ajax call
 * attach the javascript to use
 * @param String $pid
 * @return array
 */
function bibdk_holdings_favourite_placeholder($pid) {
  return array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('bibdk-holdings-favourites'),
      'data-pid' => $pid,
    ),
    '#attached' => array(
      'js' => array(drupal_get_path('module', 'bibdk_holdingstatus') . '/js/bibdk_holdingstatus.js'),
    ),
  );
}

/**
 * Generate view for favourite holdings
 *
 * @param $pid
 * @return string
 */
function bibdk_holdingstatus_holdings_for_favourites_view($pid){
   $item_list = _bibdk_holdingsstatus_favourite_item_list($pid);

  if (empty($item_list)) {
    return;
  }

  $fav['link_text'] = t('home_at_favourites');
  $fav['path'] = 'favourites';
  $fav['favourites'] = array(
    '#theme' => 'item_list',
    '#items' => $item_list,
    '#attributes' => array(
      'class' => array('favourite-list', 'form-item'),
    ),
    '#attached' => array(
      'js' => array(drupal_get_path('module', 'bibdk_holdingstatus') . '/js/bibdk_holdingstatus.js'),
    ),
  );

  return theme('bibdk_holdings_manifestation_field', $fav);
}

/**
 * Helper function - generate item list for favourite holdings
 *
 * @param $pid
 * @return array
 */
function _bibdk_holdingsstatus_favourite_item_list($pid) {

  // get localizations
  $loks = bibdk_holdingstatus_ajax_get_localizations($pid);
  
  $favourites = bibdk_favourite_get_favourites();
  
  $item_list = array();
  foreach ($favourites as $key => $favourite) {
    $agency = new TingAgency($key);
    $agencyId = $agency->getAgencyMainId();
    $agency = new TingAgency($agencyId);

    if (!isset($loks['agencies'][$agencyId])){
      continue;
    }

    $lookupUrl = $favourite->getInformation()->getLookupUrl();    
    $item_list[$agencyId] = theme('favourite_holdings', array(
      'library_name' => $agency->getInformation()->getAgencyName(),
      'lid' => $agencyId,
      'pid' => $pid,
      'link' => $lookupUrl,
    ));
  }

  return $item_list;
}
