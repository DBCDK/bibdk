<?php
/**
 * @file
 * Small Helper functions that can be excluded for unittests
 */

/**
 * Helper function to get a branch name from an Agency ID
 * @param $agencyId
 * @return null
 */
function bibdk_reservation_get_branch_name_from_id($agencyId, $type = 'long') {
  global $language;
  $lang = $language->language;
  $consortia = new TingAgency($agencyId);
  if ($type == 'short') {
    return $consortia->getBranch()->getBranchShortName($lang);
  }
  else {
    return $consortia->getBranch()->getBranchName($lang);
  }
}

/**
 * Helper function to translate strings in bibdk_reservation module
 * @param $string
 * @param array $args
 * @param array $options
 * @return null|string
 */
function bibdk_reservation_translate($string, $args = array(), $options = array('context' => 'bibdk_reservation')) {
  return t($string, $args, $options);
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
  return l($text, $path, $options);
}

/**
 * Helper function to determine ifthe current user is logged in
 *
 * @return bool
 */
function bibdk_reservation_user_is_logged_in() {
  return user_is_logged_in();
}
