<?php

/** Generates print action link for cart view
 *
 * @param array $actions
 * @return array
 */
function bibdk_actions_get_print_actions($actions) {

  $actions['print'] = array(
    '#action_type' => 'primary',
    '#theme' => 'link',
    '#text' => t('print_manifestation', array(), array('context' => 'bibdk_actions')),
    '#path' => 'print/cart',
    '#weight' => 0,
    '#options' => array(
      'query' => null,
      'attributes' => array(
        'class' => array(
          'cart-action-btn', 'inactive', 'cart-popup', 'show-for-large-up',
        ),
      ),
      'html' => FALSE,
    ),
  );

  return $actions;
}

/** Generates page to be printed
 *
 * @param $ids string
 * @return bool|string
 */
function bibdk_actions_print_page($ids) {
  $pids = preg_replace('@;@', ',', $ids);
  $pids = explode(',', $pids);
  $view = "";
  $return = t('no_elements_to_be_printed', array(), array('context' => 'bibdk_actions'));
  if (($manifestations = bibdk_actions_get_manifestations($pids))){
    foreach ($manifestations as $manifestation) {
      $views[] = _bibdk_actions_print_manifestation_view($manifestation);
    }
    drupal_add_js(drupal_get_path('module', 'bibdk_actions') . '/js/bibdk_actions.print.js');
    drupal_add_css(drupal_get_path('module', 'bibdk_actions') . '/css/bibdk_actions.css', array('media' => 'all'));
    $return = $views;
  }
  bibdk_cart_reservation_update_status('print_complete', $ids);
  return $return;
}


/** Generate viewmode for manifestation in print cart viewmode
 *
 * @param $manifestation
 * @return array
 */
function _bibdk_actions_print_manifestation_view($manifestation) {
  $work = new BibdkWork($manifestation->getWork());
  $view = ting_openformat_manifestation_view($manifestation, 'print');
  if (isset($view['#fields']) && is_array($view['#fields'])) {
    _bibdk_actions_manifestation_view_strip_links($view['#fields']);
  }
  $view['#theme'] = 'bibdk_actions_print';
  $view += array(
    '#title' => $work->getTitle(),
  );
  return $view;
}

