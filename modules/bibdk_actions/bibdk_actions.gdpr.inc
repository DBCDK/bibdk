<?php

/**
 * @file
 * Hooks provided by the bibdk_gdpr module.
 */

/**
 * Implements hook_bibdk_gdpr_items().
 *
 * @return array
 */
function bibdk_actions_bibdk_gdpr_items() {
  $items['bibdk_actions']['#header'] = t('label_gdpr_actions', array(), array('context' => 'bibdk_gdpr'));
  $items['bibdk_actions']['#theme'] = 'bibdk_gdpr_item_theme';
  $items['bibdk_actions']['#weight'] = 90;
  
  $paths = array('direct', 'refworks', 'endnote');

  foreach ($paths as $key => $path) {
    $rows[] = array(
      '#type' => 'container',
      'label' => array(
        '#type' => 'html_tag',
        '#tag' => 'span',
        '#value' => $path
      ),
      'value' => array(
        '#type' => 'html_tag',
        '#tag' => 'span',
        '#value' =>(bibdk_usersettings_user_settings_get('bibdk_actions_' . $path, TRUE)) ? 
          t('label_action_enabled', array(), array('context' => 'bibdk_gdpr')) : 
          t('label_action_disabled', array(), array('context' => 'bibdk_gdpr'))
      ),
    );
  }
  $items['bibdk_actions']['#content'] = $rows;
  return $items;
}


