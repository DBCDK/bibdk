<?php
/**
 * @file
 * bibdk_facets.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bibdk_facets_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bibdk_facetbrowser_facets';
  $strongarm->value = array(
    0 => array(
      'name' => 'facet.type',
      'title' => 'Materialetype',
      'weight' => '-10',
    ),
    1 => array(
      'name' => 'facet.subject',
      'title' => 'Emne',
      'weight' => '-9',
    ),
    2 => array(
      'name' => 'facet.creator',
      'title' => 'Forfatter',
      'weight' => '-8',
    ),
    3 => array(
      'name' => 'facet.language',
      'title' => 'Sprog',
      'weight' => '-7',
    ),
    4 => array(
      'name' => 'facet.date',
      'title' => 'Årstal',
      'weight' => '-6',
    ),
    5 => array(
      'name' => 'facet.genreCategory',
      'title' => 'Skøn- og faglitteratur',
      'weight' => '-5',
    ),
    6 => array(
      'name' => 'facet.form',
      'title' => 'Form',
      'weight' => '-4',
    ),
    7 => array(
      'name' => 'facet.access',
      'title' => 'Adgang - net',
      'weight' => '-3',
    ),
    8 => array(
      'name' => 'facet.gamePlatform',
      'title' => 'Platform',
      'weight' => '-2',
    ),
    9 => array(
      'name' => 'facet.genre',
      'title' => 'Genre',
      'weight' => '-1',
    ),
    10 => array(
      'name' => 'facet.nationality',
      'title' => 'Nationalitet',
      'weight' => '0',
    ),
    11 => array(
      'name' => 'facet.category',
      'title' => 'Børn/voksen',
      'weight' => '1',
    ),
    12 => array(
      'name' => 'facet.level',
      'title' => 'Niveau',
      'weight' => '2',
    ),
    13 => array(
      'name' => 'facet.audienceCategory',
      'title' => 'Målgruppe',
      'weight' => '3',
    ),
    14 => array(
      'name' => 'facet.audience',
      'title' => 'Tilladt for',
      'weight' => '4',
    ),
    15 => array(
      'name' => 'facet.let',
      'title' => 'Let-tal',
      'weight' => '5',
    ),
    16 => array(
      'name' => 'facet.lix',
      'title' => 'Lix-tal',
      'weight' => '6',
    ),
    17 => array(
      'name' => 'facet.literaryForm',
      'title' => 'Litterær form',
      'weight' => '7',
    ),
    18 => array(
      'name' => 'facet.titleSeries',
      'title' => 'Serie',
      'weight' => '8',
    ),
    19 => array(
      'name' => 'facet.partOf',
      'title' => 'Tidsskrift, avis eller årbog',
      'weight' => '9',
    ),
    20 => array(
      'name' => 'facet.dk5',
      'title' => 'Opstilling i folkebiblioteker',
      'weight' => '10',
    ),
    21 => array(
      'name' => 'facet.primaryCreator',
      'title' => 'Hovedansvar',
      'weight' => '10',
    ),
    22 => array(
      'name' => 'facet.sheetMusic',
      'title' => 'Nodetype',
      'weight' => '10',
    ),
  );
  $export['bibdk_facetbrowser_facets'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bibdk_facetbrowser_number_requested';
  $strongarm->value = '70';
  $export['bibdk_facetbrowser_number_requested'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bibdk_facetbrowser_number_shown';
  $strongarm->value = '3';
  $export['bibdk_facetbrowser_number_shown'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bibdk_facetbrowser_by_ajax';
  $strongarm->value = 1;
  $export['bibdk_facetbrowser_by_ajax'] = $strongarm;


  return $export;
}
