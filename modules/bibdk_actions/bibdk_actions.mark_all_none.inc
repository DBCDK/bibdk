<?php

/**
 * Defines the link for mark_all_none
 *
 * @param array $actions
 * @return array
 */
function bibdk_actions_get_mark_all_none_actions($actions) {

  $actions['mark_all_none'] = array(
    '#action_type' => 'primary',
    '#theme' => 'link',
    '#text' => t('mark_all_none', array(), array('context' => 'bibdk_actions')),
    '#path' => '',
    '#weight' => 0,
    '#options' => array(
      'query' => NULL,
      'attributes' => array(
        'class' => array(
          'cart-view-mark-all',
        ),
      ),
      'html' => FALSE,
      ),
  );

  return $actions;
}