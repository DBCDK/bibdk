<?php

/**
 * Implements hook_bibdk_provider_default_settings().
 */
function bibdk_favourite_bibdk_provider_default_settings() {

  $defaults['bibdk_actions_direct']   = TRUE;
  $defaults['bibdk_actions_refworks'] = TRUE;
  $defaults['bibdk_actions_endnote']  = TRUE;

  return $defaults;
}

