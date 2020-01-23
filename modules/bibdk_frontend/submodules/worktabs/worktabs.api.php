<?php

/**
 * @file API documentation of hook_worktabs_items().
 */


/**
 * Hook used by the worktabs module to retrieve content from other modules,
 * implementing the hook, to display embedded in the tabs.
 *
 * @param BibdkWork $entity
 *
 * @return array
 *
 * Return value is a double nested associative array. Keys in the outer array
 * names the parent tabs and the keys in the inner array can be the following:
 * '#title': String giving the title of the current item. If an empty string is
 *           provided no title will be set.
 *
 * '#btn_txt_closed': Optional string or translatable render array, setting the
 *                    title of the open/close button when the item untoggled.
 *
 * '#btn_txt_open': Optional string or translatable render array, setting the
 *                  title of the open/close button when the item is toggled.
 *
 * '#content': Render array containing what to display. If there is no content
 *             to be rendered set #theme of render array to worktabs_no_content.
 *
 * '#weight': Integer indicating the weight of the item.
 *            Lower number = rendered as first item.
 */
function hook_worktabs_items($entity) {
  $tabs = array();
  $tabs['PARENT_TAB']['MY_ITEM'] = array(
    '#title' => '',
    '#btn_txt_closed' => '',
    '#btn_txt_open' => '',
    '#content' => array(),
    '#weight' => 0,
  );
  return $tabs;
}
