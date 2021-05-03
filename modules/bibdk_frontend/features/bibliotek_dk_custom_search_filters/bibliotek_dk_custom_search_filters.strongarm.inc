<?php
/**
 * @file
 * bibliotek_dk_custom_search_filters.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bibliotek_dk_custom_search_filters_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bibdk_custom_search_user_settings';
  $strongarm->value = array(
    'e_b_ger_fra_not' => (object) array(
      'description' => 'e-bøger fra NOTA',
      'value' => 'term.publisher="DBBNOTA" and term.type="ebog"',
      'weight' => '-10',
      'id' => 'e_b_ger_fra_not',
      'pid' => 0,
      'remove' => 0,
    ),
    'nota_alle_mater' => (object) array(
      'description' => 'NOTA alle materialer',
      'value' => 'term.publisher="DBBNOTA"',
      'weight' => '-9',
      'id' => 'nota_alle_mater',
      'pid' => 0,
      'remove' => 0,
    ),
    'lydb_ger_fra_no' => (object) array(
      'description' => 'lydbøger fra NOTA',
      'value' => 'term.type="lydbog" and (dkcclterm.fl="NOTA" or dkcclterm.fl="blindebibliotek")',
      'weight' => '-8',
      'id' => 'lydb_ger_fra_no',
      'pid' => 0,
      'remove' => 0,
    ),
    'b_ger_med_punkt' => (object) array(
      'description' => 'bøger med punktskrift',
      'value' => 'term.type="punktskrift"',
      'weight' => '-7',
      'id' => 'b_ger_med_punkt',
      'pid' => 0,
      'remove' => 0,
    ),
    /*
    'film_ikke_til_u' => (object) array(
      'description' => 'film ikke til udlån',
      'value' => '(dkcclterm.tg="må kun benyttes på statsbiblioteket" or dkcclterm.tg="Kun til brug på Statsbibliotekets læsesal")',
      'weight' => '-6',
      'id' => 'film_ikke_til_u',
      'pid' => 0,
      'remove' => 0,
    ),
    */
  );
  $export['bibdk_custom_search_user_settings'] = $strongarm;

  return $export;
}
