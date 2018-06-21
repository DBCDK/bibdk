<?php

/**
 * Implements hook_cron
 *
 * Get/update access token for library login
 */
function bibdk_heimdal_cron() {
  bibdk_heimdal_cron_get_access_token();
}

function bibdk_heimdal_cron_get_access_token() {
  $curl = new bibdkHeimdalCurl();
  $token = $curl->getAccessToken();

  if ($token !== FALSE) {
    variable_set('heimdal_access_token', $token);
    watchdog('HEIMDAL', 'Heimdal token set to : @TOKEN', array('@TOKEN'=>$token));
  }
  else {
    watchdog('HEIMDAL', 'Cron failed to get new access token', array(), WATCHDOG_ERROR);
  }
}

function bibdk_heimdal_cron_garbage_collect_database() {
  // @TODO implement
  // get all saved login info and delete the old ones


}


