<?php

/**
 * @file
 * bibliotek_dk_search_controls.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bibliotek_dk_search_controls_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bibdk_search_controls';
  $strongarm->value = array(
    'sort' => array(
      'title' => 'Sort by',
      'type' => 'select',
      'label' => 'Sort by',
      'name' => 'sort',
      'description' => '',
      'access_key' => 'access_key',
      'tab_index' => 'tab_index',
      'values' => array(
        12 => array(
          'label' => '',
          'value' => '',
          'default' => 0,
          'sort' => '-10',
        ),
        10 => array(
          'label' => 'Vælg anden sortering',
          'value' => 'rank_frequency',
          'default' => 1,
          'sort' => '-9',
        ),
        2 => array(
          'label' => 'Date, descending',
          'value' => 'date_descending',
          'default' => 0,
          'sort' => '-8',
        ),
        3 => array(
          'label' => 'Date, ascending',
          'value' => 'date_ascending',
          'default' => 0,
          'sort' => '-7',
        ),
        5 => array(
          'label' => 'Title, ascending',
          'value' => 'title_ascending',
          'default' => 0,
          'sort' => '-6',
        ),
        6 => array(
          'label' => 'Title, descending',
          'value' => 'title_descending',
          'default' => 0,
          'sort' => '-5',
        ),
        0 => array(
          'label' => 'Author, ascending',
          'value' => 'creator_ascending',
          'default' => 0,
          'sort' => '-4',
        ),
        4 => array(
          'label' => 'Author, descending',
          'value' => 'creator_descending',
          'default' => 0,
          'sort' => '-3',
        ),
        7 => array(
          'label' => 'Jeg leder efter en titel  - test',
          'value' => 'rank_main_title',
          'default' => 0,
          'sort' => '-2',
        ),
        8 => array(
          'label' => 'Jeg leder efter et emne - test',
          'value' => 'rank_subject',
          'default' => 0,
          'sort' => '-1',
        ),
        9 => array(
          'label' => 'Jeg leder efter en forfatter - test',
          'value' => 'rank_creator',
          'default' => 0,
          'sort' => '0',
        ),
        11 => array(
          'label' => 'Serie i rækkefølge',
          'value' => 'numberInSeries_ascending',
          'default' => 0,
          'sort' => '1',
        ),
      ),
    ),
  );
  $export['bibdk_search_controls'] = $strongarm;

  return $export;
}
