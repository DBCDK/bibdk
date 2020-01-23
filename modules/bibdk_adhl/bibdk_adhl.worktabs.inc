<?php
/**
 * @file
 * bibdk_adhl.worktabs.inc
 */

/**
 * Implements hook_worktabs_items().
 *
 * @param bibdkWork $entity
 */
function bibdk_adhl_worktabs_items($entity) {
  $tabs = array();
  $tabs['more-about']['adhl'] = array(
    '#title' => t('adhls', array(), array('context' => 'bibdk_adhl')),
    '#btn_txt_closed' => t('view_more', array(), array('context' => 'bibdk_adhl')),
    '#content' => bibdk_adhl_get_worktab_content($entity),
    'weight' => 0,
  );
  return $tabs;
}



/**
 * @param bibdkWork $entity
 * @return array $list
 */
function bibdk_adhl_get_worktab_content($entity) {

  //get manifestations of data-pids
  $manifestationslist = bibdk_adhl_work_tabs_render($entity->getManifestations());
  //insert delimiter char ;
  $pidlist = implode(";", array_keys($manifestationslist['recommendations']['#attributes']['data-pid']) );

  $list = bibdk_adhl_work_tabs_render($pidlist);

  return drupal_render($list);
}



/**
 * @param $id
 * @return array $items
 */
function bibdk_adhl_work_tabs_render($id) {

  $items['recommendations'] = array(
    '#type' => 'fieldset',
    '#attributes' => array(
      'class' => array('recommendation-load'),
      'data-pid' => $id,
    ),
    '#attached' => array(
      'js' => array(drupal_get_path('module', 'bibdk_adhl') . '/js/bibdk_adhl.js'),
    ),
  );

  return $items;
}

