<?php
/**
 * @file
 * bibliotek_dk_carousel_settings.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bibliotek_dk_carousel_settings_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bibdk_carousel_search_queries';
  $strongarm->value = array(
    0 => array(
      'title' => 'Skønlitteratur',
      'subtitle' => 'Skønlitteratur for voksne',
      'query' => 'dkcclterm.sf=v and dkcclterm.uu=nt and term.literaryForm=fiktion and (term.type=bog) not (term.type=skrift)',
      'period' => '3',
      'offset' => '4',
    ),
    1 => array(
      'title' => 'Faglitteratur',
      'subtitle' => 'Faglitteratur for voksne',
      'query' => 'dkcclterm.sf=v and dkcclterm.uu=nt and (term.type=bog) not term.literaryForm=fiktion',
      'period' => '2',
      'offset' => '4',
    ),
    2 => array(
      'title' => 'Film',
      'subtitle' => 'Spillefilm for voksne (ikke det samme som voksenfilm :))',
      'query' => '(term.type=dvd) and dkcclterm.cl=77.7',
      'period' => '10',
      'offset' => '5',
    ),
    3 => array(
      'title' => 'Musik',
      'subtitle' => 'musik for voksne',
      'query' => '(term.type=musik or term.workType=music) and dkcclterm.sf=v',
      'period' => '2',
      'offset' => '3',
    ),
    4 => array(
      'title' => 'Spil',
      'subtitle' => 'spil for voksne',
      'query' => '(term.workType=game) and dkcclterm.sf=v',
      'period' => '12',
      'offset' => '8',
    ),
    5 => array(
      'title' => 'Børnebøger',
      'subtitle' => 'bøger for børn',
      'query' => '(dkcclterm.sf=b or dkcclterm.sf=s) and dkcclterm.uu=nt and (term.type=bog)',
      'period' => '3',
      'offset' => '4',
    ),
    6 => array(
      'title' => 'Børnefilm',
      'subtitle' => 'spillefilm for børn',
      'query' => '(term.type=dvd) and dkcclterm.cl=77.74',
      'period' => '12',
      'offset' => '8',
    ),
    7 => array(
      'title' => 'Børnespil',
      'subtitle' => 'spil for børn ',
      'query' => '(term.workType=game) and dkcclterm.sf=b',
      'period' => '12',
      'offset' => '8',
    ),
    8 => array(
      'title' => 'Børnemusik',
      'subtitle' => 'musik for børn',
      'query' => '(term.type=musik or term.workType=music) and dkcclterm.sf=b',
      'period' => '7',
      'offset' => '5',
    ),
  );
  $export['bibdk_carousel_search_queries'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bibdk_carousel_search_queries_hidden';
  $strongarm->value = array();
  $export['bibdk_carousel_search_queries_hidden'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bibdk_search_carousel_covers_max';
  $strongarm->value = '50';
  $export['bibdk_search_carousel_covers_max'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bibdk_search_carousel_dateformat';
  $strongarm->value = 'bk\\mYW';
  $export['bibdk_search_carousel_dateformat'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bibdk_search_carousel_description_toggle';
  $strongarm->value = 0;
  $export['bibdk_search_carousel_description_toggle'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bibdk_search_carousel_queries_max';
  $strongarm->value = '500';
  $export['bibdk_search_carousel_queries_max'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bibdk_search_carousel_tabs_position';
  $strongarm->value = 'bottom';
  $export['bibdk_search_carousel_tabs_position'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bibdk_search_carousel_week_search_code';
  $strongarm->value = 'dkcclterm.kk';
  $export['bibdk_search_carousel_week_search_code'] = $strongarm;

  return $export;
}
