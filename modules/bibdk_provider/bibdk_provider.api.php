<?php

/**
 * @file
 * Hooks provided by the Bibdk_provider module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Get user defaults from other modules.
 *
 * @return array
 */
function hook_bibdk_provider_default_settings() {

  $defaults['defaults_key'] = 'defaults_value';

  return $defaults;

}

/**
 * @} End of "addtogroup hooks".
 */










