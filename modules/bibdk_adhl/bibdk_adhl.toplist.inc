<?php

/** get list of most popular manifestations from ADHL
 * @param $numRecords
 * @return array|string
 */
function bibdk_adhl_get_toplist($numRecords) {
  if ($numRecords > 100) {
    $numRecords = 100;
  }
  if (!$numRecords || !is_numeric($numRecords)) {
    $numRecords = 20;
  }

  drupal_set_title(t('Top !numRecords', array('!numRecords' => $numRecords)));

  try {
    $result = open_adhl_topTenRequest($numRecords + 5);
  }
  catch (Exception $e) {
    drupal_set_message(t('The service is down, please try again later'), 'warning');
  }

  if (empty($result)) {
    return array(
      '#markup' => t('no_result_to_show'),
    );
  }

  $manifestations = bibdk_adhl_get_manifestations($result);

  $manifestations = array_slice($manifestations, 0, $numRecords);
  $view  = array(
    '#theme' => 'bibdk_adhl_toplist',
    '#title' => t('Top !numRecords', array('!numRecords' => $numRecords)),
    '#before_text' => t('before_adhl_top_list', array(), array('context' => 'bibdk_adhl')),
    '#list' => bibdk_adhl_get_link_list_view($manifestations),
    '#after_text' => t('after_adhl_top_list', array(), array('context' => 'bibdk_adhl')),
  );

  return $view;
}
