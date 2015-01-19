<?php

/**
 * Admin settings form for Ting covers.
 */
function ting_covers_admin_settings_form($form, &$form_state) {
  $form = array();

  $form['settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Cover settings'),
  );

  $form['settings']['bibdk_covers_cache_lifetime'] = array(
    '#type' => 'select',
    '#title' => t('Cover cache lifetime'),
    '#options' => array(
      CACHE_TEMPORARY =>  t('Disable cache'),
      '86400' => t("24 hours"),
      '604800' => t("1 week"),
      '2592000' => t("1 month"),
    ),
    '#default_value' => variable_get('bibdk_covers_cache_lifetime', 86400),
  );

  return system_settings_form($form);
}
