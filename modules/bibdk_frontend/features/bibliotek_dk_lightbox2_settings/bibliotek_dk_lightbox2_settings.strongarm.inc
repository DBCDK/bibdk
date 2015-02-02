<?php
/**
 * @file
 * bibliotek_dk_lightbox2_settings.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bibliotek_dk_lightbox2_settings_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_border_size';
  $strongarm->value = '10';
  $export['lightbox2_border_size'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_box_color';
  $strongarm->value = 'fff';
  $export['lightbox2_box_color'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_custom_class_handler';
  $strongarm->value = '0';
  $export['lightbox2_custom_class_handler'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_custom_trigger_classes';
  $strongarm->value = '';
  $export['lightbox2_custom_trigger_classes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_disable_close_click';
  $strongarm->value = 1;
  $export['lightbox2_disable_close_click'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_disable_nested_galleries';
  $strongarm->value = 1;
  $export['lightbox2_disable_nested_galleries'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_disable_resize';
  $strongarm->value = 0;
  $export['lightbox2_disable_resize'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_disable_zoom';
  $strongarm->value = 0;
  $export['lightbox2_disable_zoom'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_download_link_text';
  $strongarm->value = 'Download Original';
  $export['lightbox2_download_link_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_enable_contact';
  $strongarm->value = 0;
  $export['lightbox2_enable_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_enable_login';
  $strongarm->value = 0;
  $export['lightbox2_enable_login'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_enable_video';
  $strongarm->value = 0;
  $export['lightbox2_enable_video'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_fadein_speed';
  $strongarm->value = '0.4';
  $export['lightbox2_fadein_speed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_filter_xss_allowed_tags';
  $strongarm->value = 'p, br, a, em, strong, cite, code, ul, ol, li, dl, dt, dd';
  $export['lightbox2_filter_xss_allowed_tags'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_flickr';
  $strongarm->value = '0';
  $export['lightbox2_flickr'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_flv_player_flashvars';
  $strongarm->value = '';
  $export['lightbox2_flv_player_flashvars'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_flv_player_path';
  $strongarm->value = 'flvplayer.swf';
  $export['lightbox2_flv_player_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_font_color';
  $strongarm->value = '000';
  $export['lightbox2_font_color'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_force_show_nav';
  $strongarm->value = 0;
  $export['lightbox2_force_show_nav'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_gallery2_blocks';
  $strongarm->value = '0';
  $export['lightbox2_gallery2_blocks'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_image_assist_custom';
  $strongarm->value = '0';
  $export['lightbox2_image_assist_custom'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_image_count_str';
  $strongarm->value = 'Image !current of !total';
  $export['lightbox2_image_count_str'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_image_group_node_id';
  $strongarm->value = '1';
  $export['lightbox2_image_group_node_id'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_image_node';
  $strongarm->value = '0';
  $export['lightbox2_image_node'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_inline';
  $strongarm->value = '0';
  $export['lightbox2_inline'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_js_location';
  $strongarm->value = 'header';
  $export['lightbox2_js_location'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_keys_close';
  $strongarm->value = 'c x 27';
  $export['lightbox2_keys_close'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_keys_next';
  $strongarm->value = 'n 39';
  $export['lightbox2_keys_next'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_keys_play_pause';
  $strongarm->value = '32';
  $export['lightbox2_keys_play_pause'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_keys_previous';
  $strongarm->value = 'p 37';
  $export['lightbox2_keys_previous'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_keys_zoom';
  $strongarm->value = 'z';
  $export['lightbox2_keys_zoom'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_lite';
  $strongarm->value = 0;
  $export['lightbox2_lite'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_loop_items';
  $strongarm->value = 0;
  $export['lightbox2_loop_items'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_node_link_target';
  $strongarm->value = 0;
  $export['lightbox2_node_link_target'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_node_link_text';
  $strongarm->value = 'View Image Details';
  $export['lightbox2_node_link_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_overlay_color';
  $strongarm->value = 'ccc';
  $export['lightbox2_overlay_color'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_overlay_opacity';
  $strongarm->value = '0.8';
  $export['lightbox2_overlay_opacity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_page_count_str';
  $strongarm->value = 'Page !current of !total';
  $export['lightbox2_page_count_str'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_page_init_action';
  $strongarm->value = 'page_disable';
  $export['lightbox2_page_init_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially  */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_page_list';
  $strongarm->value = '';
  $export['lightbox2_page_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_resize_sequence';
  $strongarm->value = '0';
  $export['lightbox2_resize_sequence'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_resize_speed';
  $strongarm->value = '0.4';
  $export['lightbox2_resize_speed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_show_caption';
  $strongarm->value = 0;
  $export['lightbox2_show_caption'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_slidedown_speed';
  $strongarm->value = '0.6';
  $export['lightbox2_slidedown_speed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_top_position';
  $strongarm->value = '10';
  $export['lightbox2_top_position'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_use_alt_layout';
  $strongarm->value = 0;
  $export['lightbox2_use_alt_layout'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_video_count_str';
  $strongarm->value = 'Video !current of !total';
  $export['lightbox2_video_count_str'] = $strongarm;

  return $export;
}
