<?php

/**
 * Defines the link for delete_selected 
 *
 * @param array $actions
 * @return array
 */
function bibdk_actions_get_delete_selected_actions($actions) {
  
  $actions['delete_selected'] = array(
    '#action_type' => 'primary',
    '#theme' => 'link',
    '#text' => t('delete_selected', array(), array('context' => 'bibdk_actions')),
    '#path' => '',
    '#weight' => 0,
    '#options' => array(
      'query' => NULL,
      'attributes' => array(
        'class' => array(
          'inactive cart-view-delete-selected',
        ),
      ),
      'html' => FALSE,
    ),
  );

  return $actions;
}
