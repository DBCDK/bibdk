<?php

/**
 * @file
 * Hooks provided by the bibdk_gdpr module.
 */

/**
 * Get fieldsets from other modules.
 *
 * @return array
 */
function hook_bibdk_gdpr_items() {
  $items['module_name']['#theme'] = 'bibdk_gdpr_item_theme';
  $items['module_name']['#header'] = t('header');
  $items['module_name']['#content'][0] = array(
    'label' => array('#markup' => 'Item Name'),
    'value' => array('#markup' => 'Item Value'),
  );
  return $items;
}
