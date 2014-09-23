<?php

/** Callback for vejviser autocomplete functionality
 *
 * @param $string
 */
function bibdk_vejviser_get_autocomplete_data($string) {
  // Get a list of agency names
  $names = variable_get('bibdk_vejviser_agency_autocomplete_names', array());
  if (!$names) {
    $names = bibdk_vejviser_autocomplete_get_all_agency_names();
  }
  // Get a list of matches
  $data = bibdk_vejviser_autocomplete_agency_name_match($string, $names);
  // Return list as json
  drupal_json_output($data);
  drupal_exit();
}

/** Get at list of all agency names. If list does not exists in cache. Retrieve a
 * new list from webservice.
 *
 * @return array
 */
function bibdk_vejviser_autocomplete_get_all_agency_names() {
  $agencies = cache_get('bibdk_vejviser_agency_autocomplete_names', 'cache');
  if (!$agencies) {
    $result = bibdk_vejviser_execute_agency_search('?');
    $agencies = bibdk_vejviser_autocomplete_agency_list($result);
    cache_set('bibdk_vejviser_agency_autocomplete_names', $agencies, 'cache', time() + 24 * 60 * 60);
  }
  else {
    $agencies = $agencies->data;
  }
  variable_set('bibdk_vejviser_agency_autocomplete_names', $agencies);
  return $agencies;
}


/** Method to extract Agencies that matches a given string
 *
 * @param $string
 * @param $agency_names array of agencies
 * @return array
 */
function bibdk_vejviser_autocomplete_agency_name_match($string, $agency_names) {
  if (empty($string)) {
    return array();
  }

  $data = array();

  foreach ($agency_names as $key => $name) {
    if (preg_match("/$string/iu", $key, $match)) {
      $data[$key] = preg_replace("/" . $match[0] . "/i", '<b>' . $match[0] . '</b>', $key);
    }
    elseif (preg_match("/$string/iu", $name, $match)) {
      $data[$key] = preg_replace("/" . $match[0] . "/i", '<b>' . $match[0] . '</b>', $name);
    }
  }

  return $data;
}

/** Extract branchnames from branch objects
 *
 * @param $agencies
 * @return array
 */
function bibdk_vejviser_autocomplete_agency_list($agencies) {
  $names = array();
  if (!empty($agencies)) {
    foreach ($agencies as $branch) {
      // Use shortname if it exists, else use branchname
      $names[$branch->getBranchName()] = ($branch->getBranchShortName() != 'ting_agency_no_shortbranch_name') ? $branch->getBranchShortName() : $branch->getBranchName();
    }
  }
  return $names;
}

/** Implements hook_cron
 * Set/update variable with the agency names
 */
function bibdk_vejviser_cron() {
  bibdk_vejviser_autocomplete_get_all_agency_names();
}
