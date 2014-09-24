<?php

/**
 * File is currently unsused 
 */

/**
 * Parses result from OpenAgency into agency objects
 * @param array $result 
 */
function bibdk_vejviser_parse_result($result) {
  $agencies = array();
  include_once 'object/agency_object.php';

  foreach ($result as $agency) {
    $obj = new agency_object();
    $obj->agencyId = $agency->agencyId;

    $agencies[] = $obj;
  }

  return $agencies;
}