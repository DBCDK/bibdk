<?php

/** Implements hook_shortcode_info
 *
 * @return mixed
 */
function bibdk_favourite_shortcode_info() {
  $shortcodes['favourite_library'] = array(
    'title' => t('Favourite Library'),
    'description' => t('Insert favourite library'),
    'process callback' => 'bibdk_favourite_shortcode_favourite_library',
    'tips callback' => 'bibdk_favourite_shortcode_favourite_library_tip',
    'attributes callback' => '_shortcode_settings_form',
    'default settings' => array(),
  );

  return $shortcodes;
}

/** Callback for [favourite_library] shortcode
 * @param $attributes
 * @param $default_text
 * @return null|string
 */
function bibdk_favourite_shortcode_favourite_library($attributes, $default_text) {
  $favourites = array();
  if (ding_user_is_provider_user()) {
    $favourites = bibdk_favourite_get_favourites();
  }

  if (!empty($favourites)) {
    $favourite = reset($favourites);
    return drupal_render(bibdk_favourite_form_view_items_from_session($favourite, 0, false, false));
  }

  return t($default_text);
}

/** Tip for [favourite_library] shortcode
 * @return string
 */
function bibdk_favourite_shortcode_favourite_library_tip() {
  return 'Add favourite library contact information by writting: [favourite_library]This text is default text if no favourite exists[/favourite_library]';
}


/** implements hook_filter_info_alter
 * Cache is turned of for this filter. Content needs to be user-specific
 * @param $info
 */
function bibdk_favourite_filter_info_alter(&$info) {
  $info['shortcode']['cache'] = false;
}
