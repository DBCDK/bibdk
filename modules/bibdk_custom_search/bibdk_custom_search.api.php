<?php

/**
 * @file
 * Hooks provided by the Bibdk custom search module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Combine two or more elements into a single search term.
 *
 * - deprecated!
 *
 * @param $form
 * @param $form_state
 * @return array
 *  Array of search expressions
 */
function hook_bibdk_custom_search_field_preprocess($form, $form_state) {
}

/**
 * Add javascript to element.
 *
 * @param $element_uuids
 * @return array
 *  A render array
 */
function hook_bibdk_custom_search_add_js($element_uuids) {
}

/**
 * Get search control values to use in drupal_goto().
 *
 * @param $values
 * @return array
 */
function hook_ting_search_get_controls($values) {
}

/**
 * @} End of "addtogroup hooks".
 */










