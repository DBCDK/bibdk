<?php
/**
 * @file
 * Muckups of Helper functions for unittests
 */

/**
 * Helper function to get a branch name from an Agency ID
 * @param $agencyId
 * @return null
 */
function bibdk_reservation_get_branch_name_from_id($agency_id) {
  return $agency_id . '_name';
}

/**
 * Helper function to translate strings in bibdk_reservation module
 * @param $string
 * @param array $args
 * @param array $options
 * @return null|string
 */
function bibdk_reservation_translate($string, $args = array(), $options = array('context' => 'bibdk_reservation')) {
  return format_string($string, $args);
}

/**
 * Helper function to create links in bibdk_reservation module
 *
 * @param string $text
 * @param string $path
 * @param array $options
 * @return string
 */
function bibdk_reservation_get_link($text, $path, $options = array()) {
  return $path;
}

/**
 * Helper function to determine ifthe current user is logged in
 *
 * @return bool
 */
function bibdk_reservation_user_is_logged_in() {
  return $GLOBALS['bibdk_reservation_user_test'];
}

function _ting_openformat_parse_element($info, $delimiter = '<br/>') {
  return 'parsed_link';
}
