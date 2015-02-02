<?php
/**
 * @file
 * bibdk_custom_search_feature.features.inc
 */

/**
 * Implements hook_default_bibdk_custom_search_page().
 */
function bibdk_custom_search_feature_default_bibdk_custom_search_page() {
  $export = array();

  $search_page = new stdClass();
  $search_page->disabled = FALSE; /* Edit this to true to make a default search_page disabled initially */
  $search_page->api_version = 1;
  $search_page->p_uuid = '28226dd7-3165-49d8-a8e1-f9f82a44f418';
  $search_page->page_title = 'Noder';
  $search_page->page_path = 'bibdk_frontpage/noder';
  $search_page->menu_title = 'Noder';
  $search_page->delimiter = 'term.workType=sheetmusic';
  $search_page->expand = FALSE;
  $search_page->sort = 10;
  $search_page->is_disabled = FALSE;
  $export['28226dd7-3165-49d8-a8e1-f9f82a44f418'] = $search_page;

  $search_page = new stdClass();
  $search_page->disabled = FALSE; /* Edit this to true to make a default search_page disabled initially */
  $search_page->api_version = 1;
  $search_page->p_uuid = '535c37b7-2bd4-7254-09f6-1b1285ac5761';
  $search_page->page_title = 'Artikler';
  $search_page->page_path = 'bibdk_frontpage/artikel';
  $search_page->menu_title = 'Artikler';
  $search_page->delimiter = 'term.workType=article';
  $search_page->expand = FALSE;
  $search_page->sort = -8;
  $search_page->is_disabled = FALSE;
  $export['535c37b7-2bd4-7254-09f6-1b1285ac5761'] = $search_page;

  $search_page = new stdClass();
  $search_page->disabled = FALSE; /* Edit this to true to make a default search_page disabled initially */
  $search_page->api_version = 1;
  $search_page->p_uuid = '6c9427f4-c8da-e4b4-2550-4533080fc500';
  $search_page->page_title = 'Musik';
  $search_page->page_path = 'bibdk_frontpage/musik';
  $search_page->menu_title = 'Musik';
  $search_page->delimiter = 'term.workType=music';
  $search_page->expand = FALSE;
  $search_page->sort = -4;
  $search_page->is_disabled = FALSE;
  $export['6c9427f4-c8da-e4b4-2550-4533080fc500'] = $search_page;

  $search_page = new stdClass();
  $search_page->disabled = FALSE; /* Edit this to true to make a default search_page disabled initially */
  $search_page->api_version = 1;
  $search_page->p_uuid = '82a9e993-2160-2ac4-a577-4b3d980a815e';
  $search_page->page_title = 'Spil';
  $search_page->page_path = 'bibdk_frontpage/spil';
  $search_page->menu_title = 'Spil';
  $search_page->delimiter = 'term.workType=game';
  $search_page->expand = FALSE;
  $search_page->sort = -5;
  $search_page->is_disabled = FALSE;
  $export['82a9e993-2160-2ac4-a577-4b3d980a815e'] = $search_page;

  $search_page = new stdClass();
  $search_page->disabled = FALSE; /* Edit this to true to make a default search_page disabled initially */
  $search_page->api_version = 1;
  $search_page->p_uuid = 'b29c03e2-f2a9-9504-f97f-2cb529a0dad3';
  $search_page->page_title = 'Bøger';
  $search_page->page_path = 'bibdk_frontpage/bog';
  $search_page->menu_title = 'Bøger';
  $search_page->delimiter = 'term.workType=literature';
  $search_page->expand = FALSE;
  $search_page->sort = -9;
  $search_page->is_disabled = FALSE;
  $export['b29c03e2-f2a9-9504-f97f-2cb529a0dad3'] = $search_page;

  $search_page = new stdClass();
  $search_page->disabled = FALSE; /* Edit this to true to make a default search_page disabled initially */
  $search_page->api_version = 1;
  $search_page->p_uuid = 'd3099a71-b1b6-f5c4-4170-6b8593ad446b';
  $search_page->page_title = 'Alle materialer';
  $search_page->page_path = 'bibdk_frontpage';
  $search_page->menu_title = 'Alle materialer';
  $search_page->delimiter = '';
  $search_page->expand = FALSE;
  $search_page->sort = -10;
  $search_page->is_disabled = FALSE;
  $export['d3099a71-b1b6-f5c4-4170-6b8593ad446b'] = $search_page;

  $search_page = new stdClass();
  $search_page->disabled = FALSE; /* Edit this to true to make a default search_page disabled initially */
  $search_page->api_version = 1;
  $search_page->p_uuid = 'eb1079e4-72ae-cb64-8542-0492a206b36e';
  $search_page->page_title = 'Film';
  $search_page->page_path = 'bibdk_frontpage/film';
  $search_page->menu_title = 'Film';
  $search_page->delimiter = 'term.workType=movie';
  $search_page->expand = FALSE;
  $search_page->sort = -7;
  $search_page->is_disabled = FALSE;
  $export['eb1079e4-72ae-cb64-8542-0492a206b36e'] = $search_page;

  $search_page = new stdClass();
  $search_page->disabled = FALSE; /* Edit this to true to make a default search_page disabled initially */
  $search_page->api_version = 1;
  $search_page->p_uuid = 'f8e34d18-9d09-4c44-8592-99d4c43c7e79';
  $search_page->page_title = 'E-materialer';
  $search_page->page_path = 'bibdk_frontpage/net';
  $search_page->menu_title = 'E-materialer';
  $search_page->delimiter = 'term.accessType=online';
  $search_page->expand = FALSE;
  $search_page->sort = -6;
  $search_page->is_disabled = FALSE;
  $export['f8e34d18-9d09-4c44-8592-99d4c43c7e79'] = $search_page;

  return $export;
}

/**
 * Implements hook_default_bibdk_custom_search_element().
 */
function bibdk_custom_search_feature_default_bibdk_custom_search_element() {
  $export = array();

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '03d3d960-f884-1fe4-2db0-52e51ac82a6e';
  $element->element_title = 'bog_sprog';
  $element->element_label = 'Sprog';
  $element->description = 'fx tysk';
  $element->help_text = 'Vælg et eller flere sprog';
  $element->sort = -89;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['03d3d960-f884-1fe4-2db0-52e51ac82a6e'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '05b8e136-f60b-65d4-edd0-56c69d20ce8d';
  $element->element_title = 'musik_materialer';
  $element->element_label = 'Materiale';
  $element->description = 'fx cd musik';
  $element->help_text = 'Sæt tjekmærke ved et eller flere materialer, hvis du kun ønsker disse.';
  $element->sort = -53;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['05b8e136-f60b-65d4-edd0-56c69d20ce8d'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '062dda99-139c-0484-595b-2ddf7f0b88b9';
  $element->element_title = 'emne';
  $element->element_label = 'Emne';
  $element->description = 'fx tsunami';
  $element->help_text = 'Søg emne:
Skriv dit emne eller starten på det ord du søger noget om - skriver du flere ord kombinerer systemet automatisk med - og - mellem ordene.
';
  $element->sort = -98;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['062dda99-139c-0484-595b-2ddf7f0b88b9'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '13f9e684-9da0-b9b4-f107-223551514ae2';
  $element->element_title = 'musik_ophav1';
  $element->element_label = 'Medvirkende';
  $element->description = 'fx: netrebko';
  $element->help_text = 'Medvirkende: 
i begge felter kan du søge på musikere, sangere, grupper og komponister. De to felter betyder at du kan kombinere to sangere eller en kunstner og en komponist og finde hvor de optræder sammen.';
  $element->sort = -59;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['13f9e684-9da0-b9b4-f107-223551514ae2'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '1458f855-531f-b484-1df2-1c7762dc339b';
  $element->element_title = 'film_materialetype';
  $element->element_label = 'Materialetype';
  $element->description = 'fx dvd';
  $element->help_text = 'Klik på et materiale, hvis du kun ønsker en bestemt type.';
  $element->sort = -62;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['1458f855-531f-b484-1df2-1c7762dc339b'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '155a1e44-920c-f014-dd4c-3803c0a3b0e7';
  $element->element_title = 'musik_fritekst';
  $element->element_label = 'Fritekst';
  $element->description = 'fx: ebb nitzer';
  $element->help_text = 'Her kan du søge på titler, kunstnere, komponister, emneord og noter. Sæt evt. trunkeringstegn, hvis du er usikker på ordet:
neanderthal*';
  $element->sort = -55;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['155a1e44-920c-f014-dd4c-3803c0a3b0e7'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '163167ec-084d-3f54-f9cd-81912e42943f';
  $element->element_title = 'titel';
  $element->element_label = 'Titel';
  $element->description = 'fx varm luft';
  $element->help_text = 'Søg titel:
Skriv et eller flere ord fra titlen - flere ord kombinerer systemet med et og.
Sæt evt. * til sidst som joker eller trunkeringstegn, fx indian*';
  $element->sort = -99;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['163167ec-084d-3f54-f9cd-81912e42943f'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '26707474-294f-1c34-e50b-f7831578913d';
  $element->element_title = 'film_nationalitet';
  $element->element_label = 'Nationalitet';
  $element->description = 'fx japanske spillefilm';
  $element->help_text = 'Her er mulighed for at få et udvalg af spillefilm fra nogle lande.
Du finder ikke alle film fra de nævnte lande.';
  $element->sort = -63;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['26707474-294f-1c34-e50b-f7831578913d'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '2e4be922-5e61-bb64-8123-d9c01c3a1640';
  $element->element_title = 'artikel_materialetype';
  $element->element_label = 'Materialetype';
  $element->description = 'fx avisartikler';
  $element->help_text = 'Hvis du ikke ønsker Alle artikler: sæt tjek ved den type du ønsker.
Ønsker du helt andre materialer: Brug Almindelig søgning';
  $element->sort = -81;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['2e4be922-5e61-bb64-8123-d9c01c3a1640'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '3a3e8914-dd72-488d-a816-6f9f4141d701';
  $element->element_title = 'noder, hæftetitel';
  $element->element_label = 'Titel på nodehæfte';
  $element->description = '';
  $element->help_text = 'fx 555 sange';
  $element->sort = 10;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['3a3e8914-dd72-488d-a816-6f9f4141d701'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '3bde0fbf-1f9e-d914-61bb-f92ce00fd65c';
  $element->element_title = 'film_bibliotekets_aldersanbefaling';
  $element->element_label = 'Aldersanbefaling';
  $element->description = 'Biblioteket anbefaler';
  $element->help_text = 'Her kan du søge på hvilken aldersgruppe filmen er egnet til.';
  $element->sort = -61;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['3bde0fbf-1f9e-d914-61bb-f92ce00fd65c'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '3e7a88b5-6ffe-1bb4-d1b7-f218359219ac';
  $element->element_title = 'spil_bibliotekets_aldersanbefaling';
  $element->element_label = 'Aldersanbefaling';
  $element->description = 'Biblioteket anbefaler';
  $element->help_text = 'Her kan du søge på hvilken aldersgruppe biblioteket mener spillet er egnet til.';
  $element->sort = -69;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['3e7a88b5-6ffe-1bb4-d1b7-f218359219ac'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '40cb1fd2-d934-0734-69f7-01248b663172';
  $element->element_title = 'spil_platform';
  $element->element_label = 'Platform';
  $element->description = 'fx nintendo ds';
  $element->help_text = 'Vælg en eller flere platforme.';
  $element->sort = -71;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['40cb1fd2-d934-0734-69f7-01248b663172'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '47c9fbf2-fa7b-11d4-9575-202b97fc228f';
  $element->element_title = 'film_fritekst';
  $element->element_label = 'Fritekst';
  $element->description = 'fx: nordkorea';
  $element->help_text = 'Her kan du søge på ord et eller andet sted i posten. Fx titlen, medvirkende eller et kort handlingsreferat. Sæt evt. trunkeringstegn, hvis du er usikker på ordet:
tryllekunst*';
  $element->sort = -64;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['47c9fbf2-fa7b-11d4-9575-202b97fc228f'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '4a147ba3-9e4e-bef4-75b3-2a1a02a6494d';
  $element->element_title = 'musik_ophav2';
  $element->element_label = 'Medvirkende';
  $element->description = 'fx: villazon';
  $element->help_text = 'Medvirkende:
i begge felter kan du søge på musikere, sangere, grupper og komponister. De to felter betyder at du kan kombinere to sangere eller en kunstner og en komponist.';
  $element->sort = -51;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['4a147ba3-9e4e-bef4-75b3-2a1a02a6494d'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '4a162155-4f91-d2c4-b9fd-2bd17fcfd9fe';
  $element->element_title = 'film_titel';
  $element->element_label = 'Filmens titel';
  $element->description = 'fx jernladyen';
  $element->help_text = 'Her kan du søge på filmens titel - skriv et eller flere ord fra filmens titel.
Ex lost fire
';
  $element->sort = -67;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['4a162155-4f91-d2c4-b9fd-2bd17fcfd9fe'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '4fdbf458-35c2-a8d4-f97f-c50ad6286709';
  $element->element_title = 'bog_titel';
  $element->element_label = 'Titel';
  $element->description = 'fx jordens søjler';
  $element->help_text = 'Søg titel:
Skriv et eller flere ord fra titlen - flere ord kombinerer systemet med et og.
Sæt evt. * til sidst som joker (trunkeringstegn), fx drageløber*.';
  $element->sort = -93;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['4fdbf458-35c2-a8d4-f97f-c50ad6286709'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '54d61692-fd9b-07f4-55a0-c1ba3094cbde';
  $element->element_title = 'bog_målgruppe';
  $element->element_label = 'Målgruppe';
  $element->description = 'fx voksne';
  $element->help_text = 'Her kan du vælge om materialet skal være for alle eller for børn eller for voksne. Ikke alle materialer er markeret om de er beregnet for børn eller voksne.';
  $element->sort = -88;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['54d61692-fd9b-07f4-55a0-c1ba3094cbde'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '553e8edb-bbb1-c6e4-5574-8182d8ed4e15';
  $element->element_title = 'artikler_net_sprog';
  $element->element_label = 'Sprog';
  $element->description = 'fx engelsk';
  $element->help_text = 'Vælg kun sprog, hvis din søgning ellers bliver for stor.';
  $element->sort = -79;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['553e8edb-bbb1-c6e4-5574-8182d8ed4e15'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '56558f6c-0175-3a14-71c9-eac27a76cc85';
  $element->element_title = 'år';
  $element->element_label = 'Udgivelsesår';
  $element->description = 'Vælg Før, Efter eller Lig med et år';
  $element->help_text = 'Vælg Lig med, Før eller Efter og et årstal';
  $element->sort = -95;
  $element->tab_index = 0;
  $element->access_key = 'y';
  $element->is_disabled = FALSE;
  $export['56558f6c-0175-3a14-71c9-eac27a76cc85'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '56b9e76e-8fb6-6ab4-c93e-2d3bee53a7f0';
  $element->element_title = 'artikler_fritekst';
  $element->element_label = 'Fritekst';
  $element->description = 'fx: børn burkina';
  $element->help_text = 'Skriv et eller flere ord - slut dem evt. med ?
Der søges i navne, emner, titelord m.m.
Flere ord kombineres af systemet med &quot;og&quot;.

Ex: pisa? per';
  $element->sort = -82;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['56b9e76e-8fb6-6ab4-c93e-2d3bee53a7f0'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '57308136-ba7d-8224-19af-26b0f6567f77';
  $element->element_title = 'musik_genre';
  $element->element_label = 'Musikgenre';
  $element->description = 'fx jazz';
  $element->help_text = 'Finder du ikke den type musik du leder efter vist som genre?
Søg i stedet i fritekst og brug afgrænsningsmuligheder i spalten til venstre.';
  $element->sort = -54;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['57308136-ba7d-8224-19af-26b0f6567f77'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '61b61f9b-531d-4914-11d4-75430ea98677';
  $element->element_title = 'artikel_titelord';
  $element->element_label = 'Artikel titelord';
  $element->description = 'fx credo';
  $element->help_text = 'Skriv et eller flere ord fra titlen.
Hvis du skriver flere ord, kombinerer systemet dem med og.';
  $element->sort = -84;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['61b61f9b-531d-4914-11d4-75430ea98677'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '66d1dd8d-2742-7d64-8d4c-ab7f601a7916';
  $element->element_title = 'net_materialetype';
  $element->element_label = 'Materialetype';
  $element->description = 'fx tekster på nettet';
  $element->help_text = 'Vælg et materiale på listen, hvis du ikke vil søge i alle materialer.';
  $element->sort = -74;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['66d1dd8d-2742-7d64-8d4c-ab7f601a7916'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '6bfbdc58-a531-19f4-29a2-4e080de94cd8';
  $element->element_title = 'bog_materialer';
  $element->element_label = 'Materialetype';
  $element->description = 'fx trykte bøger';
  $element->help_text = 'Hvis du ikke ønsker Alle typer bøger: sæt tjek ved den type du ønsker. Ønsker du helt andre materialer: Brug søgning Alle materialer.
E-bøger kan ikke kombineres med Litterær form eller Målgruppe.';
  $element->sort = -90;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['6bfbdc58-a531-19f4-29a2-4e080de94cd8'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '75b1623e-766e-f814-e5ae-aa0ccd0d0adf';
  $element->element_title = 'spil_fritekst';
  $element->element_label = 'Fritekst';
  $element->description = 'fx: tetris';
  $element->help_text = 'Her kan du søge på ord et eller andet sted i posten. Fx titlen, udgiver eller et kort handlingsreferat. Sæt evt. trunkeringstegn, hvis du er usikker på ordet:
synge*';
  $element->sort = -72;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['75b1623e-766e-f814-e5ae-aa0ccd0d0adf'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '76a5db8e-179c-4c8b-bd60-4864ba5e6132';
  $element->element_title = 'noder, alle titler';
  $element->element_label = 'Titel på sang eller musikstykke';
  $element->description = '';
  $element->help_text = 'Her kan du søge på alle titler, både enkeltnumre, albumtitler og værktitler';
  $element->sort = 10;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['76a5db8e-179c-4c8b-bd60-4864ba5e6132'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '7b391b37-7099-50a4-e1f6-0a3623de1421';
  $element->element_title = 'artikel_tidsskrift_avis';
  $element->element_label = 'Tidsskrift eller avis';
  $element->description = 'fx ekko';
  $element->help_text = 'Brug dette felt, hvis du søger noget fra en bestemt avis eller et tidsskrift.
Skriv det eller de dele af bladets navn du kender.
Hvis du skriver flere ord, kombinerer systemet dem med og.
Ex: samvirke';
  $element->sort = -86;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['7b391b37-7099-50a4-e1f6-0a3623de1421'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '7b5202bd-ebe9-2344-8d16-1bae6c3ca027';
  $element->element_title = 'film_tilladt_for';
  $element->element_label = 'Tilladt for';
  $element->description = 'Tilladt for';
  $element->help_text = 'Her kan du søge på hvilken aldersgruppe en film er tilladt for.';
  $element->sort = -60;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['7b5202bd-ebe9-2344-8d16-1bae6c3ca027'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '7c3bfbbf-3038-9ca4-952a-85f9785337e2';
  $element->element_title = 'spil_genre';
  $element->element_label = 'Spilgenre, type';
  $element->description = 'fx actionspil';
  $element->help_text = 'Klik på Vælg genre og vælg fra genrerne. Ikke alle spil har en genrebetegnelse.';
  $element->sort = -70;
  $element->tab_index = 0;
  $element->access_key = 's';
  $element->is_disabled = FALSE;
  $export['7c3bfbbf-3038-9ca4-952a-85f9785337e2'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '81335603-ae1d-5de4-25c7-a1538e7ad8f5';
  $element->element_title = 'forfatter';
  $element->element_label = 'Forfatter';
  $element->description = 'fx nesbø';
  $element->help_text = 'Søg forfatter:
Skriv den eller de dele af navnet, du er sikker på. Kombiner evt. med et ord fra titlen - det skal skrives i titelboksen. ';
  $element->sort = -100;
  $element->tab_index = 0;
  $element->access_key = 'f';
  $element->is_disabled = FALSE;
  $export['81335603-ae1d-5de4-25c7-a1538e7ad8f5'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '886babfd-dc9f-eaa4-99df-0ba94265ac17';
  $element->element_title = 'bog_forfatter';
  $element->element_label = 'Forfatter';
  $element->description = 'fx fossum';
  $element->help_text = 'Skriv den eller de dele af navnet, du er sikker på.
Kombiner evt. med et ord fra titlen - det skal skrives i titelboksen.';
  $element->sort = -94;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['886babfd-dc9f-eaa4-99df-0ba94265ac17'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '88b1285a-384d-b874-7d8b-ec675f89ade7';
  $element->element_title = 'film_personer';
  $element->element_label = 'Personer';
  $element->description = 'fx trine dyrholm';
  $element->help_text = 'Her kan du søge på instruktører, medvirkende m.v. Du kan også skrive to navne som medvirker sammen. Men ikke alle poster indeholder alle disse oplysninger.
Der sættes - og - mellem de ord du skriver.';
  $element->sort = -66;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['88b1285a-384d-b874-7d8b-ec675f89ade7'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '8a82ae05-e3d7-2cc4-394f-104685da18b8';
  $element->element_title = 'materialetype';
  $element->element_label = 'Materialetype';
  $element->description = 'fx bøger';
  $element->help_text = 'Vælg en eller flere materialetyper
';
  $element->sort = -96;
  $element->tab_index = 0;
  $element->access_key = 'm';
  $element->is_disabled = FALSE;
  $export['8a82ae05-e3d7-2cc4-394f-104685da18b8'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '8e5ca7c5-c063-4824-15c3-eef91eb682e8';
  $element->element_title = 'artikel_emne';
  $element->element_label = 'Artiklens emne';
  $element->description = 'fx fed* fisk*';
  $element->help_text = 'Skriv dit emne - slut evt. med *
Hvis du skriver flere ord, kombinerer systemet dem med og.
Ex. pisa*';
  $element->sort = -83;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['8e5ca7c5-c063-4824-15c3-eef91eb682e8'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = '9576133e-7fed-45d4-29ec-6920f85c69bb';
  $element->element_title = 'net_titel';
  $element->element_label = 'Titel';
  $element->description = 'fx sort arbejde';
  $element->help_text = 'Skriv et eller flere ord fra titlen. ';
  $element->sort = -77;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['9576133e-7fed-45d4-29ec-6920f85c69bb'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = 'a0e64424-68f9-71f4-1df2-bf0100315aa4';
  $element->element_title = 'net_forfatter';
  $element->element_label = 'Forfatter eller udgiver';
  $element->description = 'fx skat';
  $element->help_text = 'Skriv den eller de dele af navnet, du er sikker på. 
';
  $element->sort = -78;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['a0e64424-68f9-71f4-1df2-bf0100315aa4'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = 'a1beb6bb-b22f-80d4-e5ff-2c191909a51a';
  $element->element_title = 'artikel_avis';
  $element->element_label = '';
  $element->description = '';
  $element->help_text = '';
  $element->sort = -80;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['a1beb6bb-b22f-80d4-e5ff-2c191909a51a'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = 'a54a7813-741a-f3d4-615d-e60a322df4be';
  $element->element_title = 'sprog';
  $element->element_label = 'Sprog';
  $element->description = 'fx spansk';
  $element->help_text = 'Vælg et sprog';
  $element->sort = -52;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['a54a7813-741a-f3d4-615d-e60a322df4be'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = 'acdb74f6-dd28-81c4-5190-af28a09e5d47';
  $element->element_title = 'musik_titler_alle';
  $element->element_label = 'Alle titler';
  $element->description = 'fx: stille før storm';
  $element->help_text = 'Alle titler kan bruges til ord fra alle slags titler - både hele cder og enkelte numre. Får du alt for mange resultater ved brug af Alle titler, kan du bruge Albumtitel på cd eller kombinere med en kunstner eller komponist.';
  $element->sort = -57;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['acdb74f6-dd28-81c4-5190-af28a09e5d47'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = 'ad54f1ac-2da3-475c-9d56-38896ad7cae0';
  $element->element_title = 'noder_materialetyper';
  $element->element_label = 'Materiale';
  $element->description = '';
  $element->help_text = 'Tjek en materialetype af hvis du kun ønsker en bestemt type';
  $element->sort = 10;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['ad54f1ac-2da3-475c-9d56-38896ad7cae0'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = 'ae797962-8b73-3044-31d3-6eebde66c95f';
  $element->element_title = 'film_genre';
  $element->element_label = 'Genre, type';
  $element->description = 'Fx drama';
  $element->help_text = 'Klik på Vælg genre og vælg en eller flere genrer. Ikke alle film har en genrebetegnelse.';
  $element->sort = -65;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['ae797962-8b73-3044-31d3-6eebde66c95f'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = 'b0289528-53b4-2074-258c-735b863085e1';
  $element->element_title = 'musik_hovedophav';
  $element->element_label = 'Hovedkunstner/-komponist';
  $element->description = 'fx: nøhr';
  $element->help_text = 'Brug Hovedkunstner, hvis du får alt for mange fund ved at bruge Medvirkende.
Her finder du kun det som kunstneren, komponisten eller gruppen er hovedansvarlig for - fx kun Rasmus Nøhrs egne plader - og ikke alle dem hvor han blot bidrager.';
  $element->sort = -58;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['b0289528-53b4-2074-258c-735b863085e1'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = 'b35762f5-54c6-4044-355a-96a20c9d21dc';
  $element->element_title = 'artikel_forfatter';
  $element->element_label = 'Artiklens forfatter';
  $element->description = 'fx ib friis';
  $element->help_text = 'Skriv det eller de dele af forfatterens navn du kender.
Ex: mette højbjerg';
  $element->sort = -85;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['b35762f5-54c6-4044-355a-96a20c9d21dc'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = 'b4fe23ee-b461-4b68-813a-d9a32a637bfe';
  $element->element_title = 'noder_ophav';
  $element->element_label = 'Komponist eller gruppe';
  $element->description = '';
  $element->help_text = 'fx fuzzy';
  $element->sort = 10;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['b4fe23ee-b461-4b68-813a-d9a32a637bfe'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = 'b9392a11-5676-3574-fd47-143ad3edcefa';
  $element->element_title = 'net_emne';
  $element->element_label = 'Emne';
  $element->description = 'fx mozart';
  $element->help_text = 'Skriv dit emne eller starten på det ord du søger noget om.';
  $element->sort = -75;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['b9392a11-5676-3574-fd47-143ad3edcefa'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = 'bf216dfd-13d9-e774-01c6-b7ef6d7eb3a9';
  $element->element_title = 'spil_titel';
  $element->element_label = 'Titel';
  $element->description = 'fx bulletstorm';
  $element->help_text = 'Her kan du søge på spillets titel.';
  $element->sort = -73;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['bf216dfd-13d9-e774-01c6-b7ef6d7eb3a9'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = 'bfba5600-ce4d-48d4-6d5e-289878f1889c';
  $element->element_title = 'net_fritekst';
  $element->element_label = 'Fritekst';
  $element->description = 'fx: klimakonference?';
  $element->help_text = 'Her søger du i de fleste oplysninger i posterne
Du kan sætte en * - når du er i tvivl
Du skal ikke skrive &#039;og&#039; mellem ordene.';
  $element->sort = -76;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['bfba5600-ce4d-48d4-6d5e-289878f1889c'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = 'c15df474-dc7b-9b74-ad02-0efe8b6fe29d';
  $element->element_title = 'bog_emne';
  $element->element_label = 'Emne';
  $element->description = 'fx sejlsport';
  $element->help_text = 'Søg emne:
Skriv dit emne eller starten på det ord du søger noget om - skriver du flere ord kombinerer systemet med og.';
  $element->sort = -92;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['c15df474-dc7b-9b74-ad02-0efe8b6fe29d'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = 'ccec6101-d44c-1484-edd8-bab3e529b0e7';
  $element->element_title = 'bog_fritekst';
  $element->element_label = 'Fritekst';
  $element->description = 'fx: thorsminde';
  $element->help_text = 'Her søger du i de fleste oplysninger i posterne
Du kan bruge en * - når du er i tvivl, fx sejl*
Du skal ikke skrive og mellem ordene.';
  $element->sort = -91;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['ccec6101-d44c-1484-edd8-bab3e529b0e7'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = 'ccf7115d-8830-57f4-21c4-4b7a9c204e9b';
  $element->element_title = 'musik_albumtitel';
  $element->element_label = 'Albumtitel';
  $element->description = 'fx: planet earth';
  $element->help_text = 'Albumtitel: her får du kun poster hvor dit søgeord står i navnet på albummet (cd, båndet, pladen, netmusik, videoen eller dvden).';
  $element->sort = -56;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['ccf7115d-8830-57f4-21c4-4b7a9c204e9b'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = 'cd37520a-f3c2-63a4-9979-416311ef9a2b';
  $element->element_title = 'spil_medierådets_aldersanbefaling';
  $element->element_label = 'Medierådets aldersanbefalinger';
  $element->description = 'PEGI aldersmærkning';
  $element->help_text = 'PEGI mærkningen fortæller ikke hvor svært spillet er, men om det kan være skræmmende. Læs mere om <a href="http://www.pegi.dk/visArtikel.asp?artikelID=179" target="_blank">PEGI-afmærkning.</a>';
  $element->sort = -68;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['cd37520a-f3c2-63a4-9979-416311ef9a2b'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = 'd061e38c-7c6a-9014-bd32-00a60a45e2d1';
  $element->element_title = 'fritekst';
  $element->element_label = 'Fritekst';
  $element->description = 'fx matterhorn';
  $element->help_text = 'Søg fritekst:
Her søger du i de fleste oplysninger i posterne. Du kan sætte en joker (trunkering):  * - når du er i tvivl. Ex.: lånemulighed*. Du skal ikke skrive og mellem ordene. ';
  $element->sort = -97;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['d061e38c-7c6a-9014-bd32-00a60a45e2d1'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = 'd868dbb4-c49f-8674-5560-4b0547a2c9df';
  $element->element_title = 'bog_form';
  $element->element_label = 'Litterær form';
  $element->description = 'fx faglitteratur';
  $element->help_text = 'Her kan du vælge om materialet skal være Fag- eller skønlitteratur. Ikke alle materiale er markeret om de er fag- eller skønlitteratur.';
  $element->sort = -87;
  $element->tab_index = 0;
  $element->access_key = '';
  $element->is_disabled = FALSE;
  $export['d868dbb4-c49f-8674-5560-4b0547a2c9df'] = $element;

  $element = new stdClass();
  $element->disabled = FALSE; /* Edit this to true to make a default element disabled initially */
  $element->api_version = 1;
  $element->e_uuid = 'e8fff062-b583-49f5-989f-327864488b5d';
  $element->element_title = 'noder_genrer';
  $element->element_label = 'Genre';
  $element->description = '';
  $element->help_text = 'Brug genre til at kombinere med nodetype';
  $element->sort = 10;
  $element->tab_index = 0;
  $element->access_key = 'g';
  $element->is_disabled = FALSE;
  $export['e8fff062-b583-49f5-989f-327864488b5d'] = $element;

  return $export;
}

/**
 * Implements hook_default_bibdk_custom_search_map_element().
 */
function bibdk_custom_search_feature_default_bibdk_custom_search_map_element() {
  $export = array();

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = 'eb1079e4-72ae-cb64-8542-0492a206b36e';
  $map_element->e_uuid = '4a162155-4f91-d2c4-b9fd-2bd17fcfd9fe';
  $map_element->me_uuid = '0636834b-7f1f-4914-1111-657aa474d5b8';
  $map_element->region = 'main';
  $map_element->sort = -50;
  $export['0636834b-7f1f-4914-1111-657aa474d5b8'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = 'f8e34d18-9d09-4c44-8592-99d4c43c7e79';
  $map_element->e_uuid = '9576133e-7fed-45d4-29ec-6920f85c69bb';
  $map_element->me_uuid = '0935ba89-082a-1b84-59f7-757e590e74ad';
  $map_element->region = 'main';
  $map_element->sort = -48;
  $export['0935ba89-082a-1b84-59f7-757e590e74ad'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = '28226dd7-3165-49d8-a8e1-f9f82a44f418';
  $map_element->e_uuid = '3a3e8914-dd72-488d-a816-6f9f4141d701';
  $map_element->me_uuid = '0eda4c93-f14d-4e04-be5a-5e4ff97a4163';
  $map_element->region = 'main';
  $map_element->sort = -50;
  $export['0eda4c93-f14d-4e04-be5a-5e4ff97a4163'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = 'f8e34d18-9d09-4c44-8592-99d4c43c7e79';
  $map_element->e_uuid = '553e8edb-bbb1-c6e4-5574-8182d8ed4e15';
  $map_element->me_uuid = '1403d4fc-66a1-0054-9daa-eb0b5e74a776';
  $map_element->region = 'expand';
  $map_element->sort = -47;
  $export['1403d4fc-66a1-0054-9daa-eb0b5e74a776'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = 'd3099a71-b1b6-f5c4-4170-6b8593ad446b';
  $map_element->e_uuid = '81335603-ae1d-5de4-25c7-a1538e7ad8f5';
  $map_element->me_uuid = '1b12008b-2c17-5794-91d4-3f390a367125';
  $map_element->region = 'main';
  $map_element->sort = -50;
  $export['1b12008b-2c17-5794-91d4-3f390a367125'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = '6c9427f4-c8da-e4b4-2550-4533080fc500';
  $map_element->e_uuid = '13f9e684-9da0-b9b4-f107-223551514ae2';
  $map_element->me_uuid = '1caf330f-4a89-db84-5d76-eea95b25e73e';
  $map_element->region = 'main';
  $map_element->sort = -47;
  $export['1caf330f-4a89-db84-5d76-eea95b25e73e'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = '535c37b7-2bd4-7254-09f6-1b1285ac5761';
  $map_element->e_uuid = '7b391b37-7099-50a4-e1f6-0a3623de1421';
  $map_element->me_uuid = '228bb04b-de83-fa14-9536-99552ac09d13';
  $map_element->region = 'main';
  $map_element->sort = -50;
  $export['228bb04b-de83-fa14-9536-99552ac09d13'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = 'b29c03e2-f2a9-9504-f97f-2cb529a0dad3';
  $map_element->e_uuid = '4fdbf458-35c2-a8d4-f97f-c50ad6286709';
  $map_element->me_uuid = '22948d61-f9b3-a514-851e-9316e9e7d045';
  $map_element->region = 'main';
  $map_element->sort = -49;
  $export['22948d61-f9b3-a514-851e-9316e9e7d045'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = '28226dd7-3165-49d8-a8e1-f9f82a44f418';
  $map_element->e_uuid = '76a5db8e-179c-4c8b-bd60-4864ba5e6132';
  $map_element->me_uuid = '2c372bfe-36b6-4b09-aee8-f4254ba51b96';
  $map_element->region = 'main';
  $map_element->sort = -48;
  $export['2c372bfe-36b6-4b09-aee8-f4254ba51b96'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = '6c9427f4-c8da-e4b4-2550-4533080fc500';
  $map_element->e_uuid = '57308136-ba7d-8224-19af-26b0f6567f77';
  $map_element->me_uuid = '30baac2c-6c2c-7344-b1cc-c233339ebad6';
  $map_element->region = 'main';
  $map_element->sort = -45;
  $export['30baac2c-6c2c-7344-b1cc-c233339ebad6'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = 'eb1079e4-72ae-cb64-8542-0492a206b36e';
  $map_element->e_uuid = '26707474-294f-1c34-e50b-f7831578913d';
  $map_element->me_uuid = '330986ab-3283-1f14-8dca-2464d63799bd';
  $map_element->region = 'main';
  $map_element->sort = -46;
  $export['330986ab-3283-1f14-8dca-2464d63799bd'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = 'f8e34d18-9d09-4c44-8592-99d4c43c7e79';
  $map_element->e_uuid = '56558f6c-0175-3a14-71c9-eac27a76cc85';
  $map_element->me_uuid = '345b26e3-4a5c-2ab4-3d7d-54ce3e1622f6';
  $map_element->region = 'expand';
  $map_element->sort = -46;
  $export['345b26e3-4a5c-2ab4-3d7d-54ce3e1622f6'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = '6c9427f4-c8da-e4b4-2550-4533080fc500';
  $map_element->e_uuid = 'ccf7115d-8830-57f4-21c4-4b7a9c204e9b';
  $map_element->me_uuid = '36fbc763-5883-2174-1598-99eb1beb3bfe';
  $map_element->region = 'main';
  $map_element->sort = -50;
  $export['36fbc763-5883-2174-1598-99eb1beb3bfe'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = '535c37b7-2bd4-7254-09f6-1b1285ac5761';
  $map_element->e_uuid = '553e8edb-bbb1-c6e4-5574-8182d8ed4e15';
  $map_element->me_uuid = '407ef899-eab7-b304-c50a-fea95dd922c6';
  $map_element->region = 'expand';
  $map_element->sort = -46;
  $export['407ef899-eab7-b304-c50a-fea95dd922c6'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = '535c37b7-2bd4-7254-09f6-1b1285ac5761';
  $map_element->e_uuid = 'b35762f5-54c6-4044-355a-96a20c9d21dc';
  $map_element->me_uuid = '44e8fe84-fd3e-a1e4-a53c-49b14b2874b7';
  $map_element->region = 'main';
  $map_element->sort = -48;
  $export['44e8fe84-fd3e-a1e4-a53c-49b14b2874b7'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = 'd3099a71-b1b6-f5c4-4170-6b8593ad446b';
  $map_element->e_uuid = '163167ec-084d-3f54-f9cd-81912e42943f';
  $map_element->me_uuid = '4767f5c9-02df-e134-4903-dbc801550829';
  $map_element->region = 'main';
  $map_element->sort = -49;
  $export['4767f5c9-02df-e134-4903-dbc801550829'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = 'd3099a71-b1b6-f5c4-4170-6b8593ad446b';
  $map_element->e_uuid = 'a54a7813-741a-f3d4-615d-e60a322df4be';
  $map_element->me_uuid = '4800babd-619d-4344-c1d5-049ce34867b9';
  $map_element->region = 'expand';
  $map_element->sort = -48;
  $export['4800babd-619d-4344-c1d5-049ce34867b9'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = 'eb1079e4-72ae-cb64-8542-0492a206b36e';
  $map_element->e_uuid = '1458f855-531f-b484-1df2-1c7762dc339b';
  $map_element->me_uuid = '4a4c9b84-6a7e-c2b4-f1d8-6e94753c372f';
  $map_element->region = 'expand';
  $map_element->sort = -47;
  $export['4a4c9b84-6a7e-c2b4-f1d8-6e94753c372f'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = 'b29c03e2-f2a9-9504-f97f-2cb529a0dad3';
  $map_element->e_uuid = '54d61692-fd9b-07f4-55a0-c1ba3094cbde';
  $map_element->me_uuid = '5129aa2d-2147-4244-0912-75160a741eb0';
  $map_element->region = 'expand';
  $map_element->sort = -46;
  $export['5129aa2d-2147-4244-0912-75160a741eb0'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = 'b29c03e2-f2a9-9504-f97f-2cb529a0dad3';
  $map_element->e_uuid = '56558f6c-0175-3a14-71c9-eac27a76cc85';
  $map_element->me_uuid = '5a10f6c1-18fd-a924-2d44-1f5f34e194df';
  $map_element->region = 'expand';
  $map_element->sort = -44;
  $export['5a10f6c1-18fd-a924-2d44-1f5f34e194df'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = '82a9e993-2160-2ac4-a577-4b3d980a815e';
  $map_element->e_uuid = 'cd37520a-f3c2-63a4-9979-416311ef9a2b';
  $map_element->me_uuid = '5cb49f0d-451a-c274-a57b-6585e4e49f1c';
  $map_element->region = 'expand';
  $map_element->sort = -48;
  $export['5cb49f0d-451a-c274-a57b-6585e4e49f1c'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = 'f8e34d18-9d09-4c44-8592-99d4c43c7e79';
  $map_element->e_uuid = '66d1dd8d-2742-7d64-8d4c-ab7f601a7916';
  $map_element->me_uuid = '5f5d6a16-f03c-b4b4-0909-da8a067e5375';
  $map_element->region = 'expand';
  $map_element->sort = -48;
  $export['5f5d6a16-f03c-b4b4-0909-da8a067e5375'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = 'b29c03e2-f2a9-9504-f97f-2cb529a0dad3';
  $map_element->e_uuid = '886babfd-dc9f-eaa4-99df-0ba94265ac17';
  $map_element->me_uuid = '7daf7259-d90e-eb44-d92d-34a4900279b1';
  $map_element->region = 'main';
  $map_element->sort = -50;
  $export['7daf7259-d90e-eb44-d92d-34a4900279b1'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = 'd3099a71-b1b6-f5c4-4170-6b8593ad446b';
  $map_element->e_uuid = '56558f6c-0175-3a14-71c9-eac27a76cc85';
  $map_element->me_uuid = '7fdbeb0c-99da-df94-0da8-aab74429c5b1';
  $map_element->region = 'expand';
  $map_element->sort = -49;
  $export['7fdbeb0c-99da-df94-0da8-aab74429c5b1'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = 'd3099a71-b1b6-f5c4-4170-6b8593ad446b';
  $map_element->e_uuid = '062dda99-139c-0484-595b-2ddf7f0b88b9';
  $map_element->me_uuid = '8df0ca1e-53c5-0d74-d5da-225d330cf2e3';
  $map_element->region = 'main';
  $map_element->sort = -48;
  $export['8df0ca1e-53c5-0d74-d5da-225d330cf2e3'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = 'd3099a71-b1b6-f5c4-4170-6b8593ad446b';
  $map_element->e_uuid = '8a82ae05-e3d7-2cc4-394f-104685da18b8';
  $map_element->me_uuid = '92dabaf1-aa66-6f04-7d67-665ddd749d26';
  $map_element->region = 'expand';
  $map_element->sort = -50;
  $export['92dabaf1-aa66-6f04-7d67-665ddd749d26'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = 'b29c03e2-f2a9-9504-f97f-2cb529a0dad3';
  $map_element->e_uuid = '03d3d960-f884-1fe4-2db0-52e51ac82a6e';
  $map_element->me_uuid = '9d2f1d32-4468-0884-99a9-aabcd9a588ad';
  $map_element->region = 'expand';
  $map_element->sort = -45;
  $export['9d2f1d32-4468-0884-99a9-aabcd9a588ad'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = 'eb1079e4-72ae-cb64-8542-0492a206b36e';
  $map_element->e_uuid = '7b5202bd-ebe9-2344-8d16-1bae6c3ca027';
  $map_element->me_uuid = '9eef86ed-5b62-3fa4-35ab-ac31ce4f021b';
  $map_element->region = 'expand';
  $map_element->sort = -45;
  $export['9eef86ed-5b62-3fa4-35ab-ac31ce4f021b'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = 'b29c03e2-f2a9-9504-f97f-2cb529a0dad3';
  $map_element->e_uuid = 'd868dbb4-c49f-8674-5560-4b0547a2c9df';
  $map_element->me_uuid = '9f9b636e-2822-5b34-35aa-8fc9d9162266';
  $map_element->region = 'expand';
  $map_element->sort = -47;
  $export['9f9b636e-2822-5b34-35aa-8fc9d9162266'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = 'eb1079e4-72ae-cb64-8542-0492a206b36e';
  $map_element->e_uuid = '3bde0fbf-1f9e-d914-61bb-f92ce00fd65c';
  $map_element->me_uuid = '9ffdd8cd-1afa-9af4-e110-00b5122e4531';
  $map_element->region = 'expand';
  $map_element->sort = -46;
  $export['9ffdd8cd-1afa-9af4-e110-00b5122e4531'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = 'b29c03e2-f2a9-9504-f97f-2cb529a0dad3';
  $map_element->e_uuid = 'c15df474-dc7b-9b74-ad02-0efe8b6fe29d';
  $map_element->me_uuid = 'a26fbf69-132a-3214-9199-8f98e8ea32b2';
  $map_element->region = 'main';
  $map_element->sort = -48;
  $export['a26fbf69-132a-3214-9199-8f98e8ea32b2'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = 'f8e34d18-9d09-4c44-8592-99d4c43c7e79';
  $map_element->e_uuid = 'a0e64424-68f9-71f4-1df2-bf0100315aa4';
  $map_element->me_uuid = 'a7706d35-0093-aac4-b9ad-37aeb03c2f55';
  $map_element->region = 'main';
  $map_element->sort = -49;
  $export['a7706d35-0093-aac4-b9ad-37aeb03c2f55'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = '535c37b7-2bd4-7254-09f6-1b1285ac5761';
  $map_element->e_uuid = '2e4be922-5e61-bb64-8123-d9c01c3a1640';
  $map_element->me_uuid = 'a776d9cb-877d-6014-8d4d-31c8ae7fd02e';
  $map_element->region = 'expand';
  $map_element->sort = -47;
  $export['a776d9cb-877d-6014-8d4d-31c8ae7fd02e'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = '6c9427f4-c8da-e4b4-2550-4533080fc500';
  $map_element->e_uuid = '4a147ba3-9e4e-bef4-75b3-2a1a02a6494d';
  $map_element->me_uuid = 'a900cbfc-827f-b4d4-21c7-3004631c33a5';
  $map_element->region = 'main';
  $map_element->sort = -46;
  $export['a900cbfc-827f-b4d4-21c7-3004631c33a5'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = 'eb1079e4-72ae-cb64-8542-0492a206b36e';
  $map_element->e_uuid = '88b1285a-384d-b874-7d8b-ec675f89ade7';
  $map_element->me_uuid = 'abd2eb6d-e6a7-e064-f165-712145d8f8b3';
  $map_element->region = 'main';
  $map_element->sort = -49;
  $export['abd2eb6d-e6a7-e064-f165-712145d8f8b3'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = '28226dd7-3165-49d8-a8e1-f9f82a44f418';
  $map_element->e_uuid = 'ad54f1ac-2da3-475c-9d56-38896ad7cae0';
  $map_element->me_uuid = 'b3b1c65d-1d48-4add-9bb4-15c9dcb30ef9';
  $map_element->region = 'expand';
  $map_element->sort = -50;
  $export['b3b1c65d-1d48-4add-9bb4-15c9dcb30ef9'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = '6c9427f4-c8da-e4b4-2550-4533080fc500';
  $map_element->e_uuid = 'b0289528-53b4-2074-258c-735b863085e1';
  $map_element->me_uuid = 'b8e42a9f-1bdf-f424-21dd-0aaf7aa70682';
  $map_element->region = 'main';
  $map_element->sort = -49;
  $export['b8e42a9f-1bdf-f424-21dd-0aaf7aa70682'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = '82a9e993-2160-2ac4-a577-4b3d980a815e';
  $map_element->e_uuid = '7c3bfbbf-3038-9ca4-952a-85f9785337e2';
  $map_element->me_uuid = 'bd4354cd-4218-daa4-ed8f-94551d65cfac';
  $map_element->region = 'main';
  $map_element->sort = -47;
  $export['bd4354cd-4218-daa4-ed8f-94551d65cfac'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = '82a9e993-2160-2ac4-a577-4b3d980a815e';
  $map_element->e_uuid = '40cb1fd2-d934-0734-69f7-01248b663172';
  $map_element->me_uuid = 'c1631440-1237-4bc4-9d80-4d76c5c839dd';
  $map_element->region = 'main';
  $map_element->sort = -48;
  $export['c1631440-1237-4bc4-9d80-4d76c5c839dd'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = 'f8e34d18-9d09-4c44-8592-99d4c43c7e79';
  $map_element->e_uuid = 'b9392a11-5676-3574-fd47-143ad3edcefa';
  $map_element->me_uuid = 'cb531f35-4ef3-bb94-2dfa-14fe18d50cd4';
  $map_element->region = 'main';
  $map_element->sort = -47;
  $export['cb531f35-4ef3-bb94-2dfa-14fe18d50cd4'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = '6c9427f4-c8da-e4b4-2550-4533080fc500';
  $map_element->e_uuid = '05b8e136-f60b-65d4-edd0-56c69d20ce8d';
  $map_element->me_uuid = 'ccd214a3-acac-c174-d9f6-decdbf73a357';
  $map_element->region = 'expand';
  $map_element->sort = -46;
  $export['ccd214a3-acac-c174-d9f6-decdbf73a357'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = 'eb1079e4-72ae-cb64-8542-0492a206b36e';
  $map_element->e_uuid = 'ae797962-8b73-3044-31d3-6eebde66c95f';
  $map_element->me_uuid = 'd03c04e6-eb35-d9e4-6dd8-2fb21bcd99f8';
  $map_element->region = 'main';
  $map_element->sort = -47;
  $export['d03c04e6-eb35-d9e4-6dd8-2fb21bcd99f8'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = '82a9e993-2160-2ac4-a577-4b3d980a815e';
  $map_element->e_uuid = '3e7a88b5-6ffe-1bb4-d1b7-f218359219ac';
  $map_element->me_uuid = 'd1a76cdc-ec67-bb74-21dd-99b547a3d7bb';
  $map_element->region = 'expand';
  $map_element->sort = -47;
  $export['d1a76cdc-ec67-bb74-21dd-99b547a3d7bb'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = '28226dd7-3165-49d8-a8e1-f9f82a44f418';
  $map_element->e_uuid = 'b4fe23ee-b461-4b68-813a-d9a32a637bfe';
  $map_element->me_uuid = 'd430ed0e-74d1-4eb5-a65c-5e3f5d33592b';
  $map_element->region = 'main';
  $map_element->sort = -49;
  $export['d430ed0e-74d1-4eb5-a65c-5e3f5d33592b'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = '6c9427f4-c8da-e4b4-2550-4533080fc500';
  $map_element->e_uuid = 'acdb74f6-dd28-81c4-5190-af28a09e5d47';
  $map_element->me_uuid = 'da97cc66-0faa-3314-61f1-b90dcb80d330';
  $map_element->region = 'main';
  $map_element->sort = -48;
  $export['da97cc66-0faa-3314-61f1-b90dcb80d330'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = '535c37b7-2bd4-7254-09f6-1b1285ac5761';
  $map_element->e_uuid = '61b61f9b-531d-4914-11d4-75430ea98677';
  $map_element->me_uuid = 'de855854-3134-2164-b522-40edd209b8e5';
  $map_element->region = 'main';
  $map_element->sort = -49;
  $export['de855854-3134-2164-b522-40edd209b8e5'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = '535c37b7-2bd4-7254-09f6-1b1285ac5761';
  $map_element->e_uuid = '8e5ca7c5-c063-4824-15c3-eef91eb682e8';
  $map_element->me_uuid = 'e51df668-cc2f-bfb4-6170-871f14423042';
  $map_element->region = 'main';
  $map_element->sort = -47;
  $export['e51df668-cc2f-bfb4-6170-871f14423042'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = 'b29c03e2-f2a9-9504-f97f-2cb529a0dad3';
  $map_element->e_uuid = '6bfbdc58-a531-19f4-29a2-4e080de94cd8';
  $map_element->me_uuid = 'f324599e-dfd4-32f4-a158-48a0305d0450';
  $map_element->region = 'expand';
  $map_element->sort = -48;
  $export['f324599e-dfd4-32f4-a158-48a0305d0450'] = $map_element;

  $map_element = new stdClass();
  $map_element->disabled = FALSE; /* Edit this to true to make a default map_element disabled initially */
  $map_element->api_version = 1;
  $map_element->p_uuid = '535c37b7-2bd4-7254-09f6-1b1285ac5761';
  $map_element->e_uuid = '56558f6c-0175-3a14-71c9-eac27a76cc85';
  $map_element->me_uuid = 'fc1e29fd-3fe1-c574-cdd3-764940c142e5';
  $map_element->region = 'expand';
  $map_element->sort = -45;
  $export['fc1e29fd-3fe1-c574-cdd3-764940c142e5'] = $map_element;

  return $export;
}

/**
 * Implements hook_default_bibdk_custom_search_map_value().
 */
function bibdk_custom_search_feature_default_bibdk_custom_search_map_value() {
  $export = array();

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '025ba21d-159e-ed54-657f-9d212d77762d';
  $map_values->e_uuid = 'b9392a11-5676-3574-fd47-143ad3edcefa';
  $map_values->v_uuid = '90655745-f61d-ac84-c54e-d7907d159271';
  $map_values->sort = 10;
  $export['025ba21d-159e-ed54-657f-9d212d77762d'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '03738e98-1b99-4b39-a56d-b1d01dc4283f';
  $map_values->e_uuid = 'ad54f1ac-2da3-475c-9d56-38896ad7cae0';
  $map_values->v_uuid = '2dfa5ad4-131f-4fb8-881f-3607e4e1d4d1';
  $map_values->sort = 10;
  $export['03738e98-1b99-4b39-a56d-b1d01dc4283f'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '048c6ac1-fb65-d6b4-09a4-dc2d9ad74759';
  $map_values->e_uuid = '1458f855-531f-b484-1df2-1c7762dc339b';
  $map_values->v_uuid = 'f79c6d0f-effe-6944-7951-211d70e904d7';
  $map_values->sort = 10;
  $export['048c6ac1-fb65-d6b4-09a4-dc2d9ad74759'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '0bb2b232-dcf3-88e4-65b3-5554bec9d5b9';
  $map_values->e_uuid = '47c9fbf2-fa7b-11d4-9575-202b97fc228f';
  $map_values->v_uuid = '0d6ffeb4-4c40-1bc4-0d0b-4c2a8d2465b5';
  $map_values->sort = 10;
  $export['0bb2b232-dcf3-88e4-65b3-5554bec9d5b9'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '0bf2fa2d-e0b3-2b44-51e2-3d3c0c9a28e3';
  $map_values->e_uuid = '26707474-294f-1c34-e50b-f7831578913d';
  $map_values->v_uuid = '8e7bda97-5430-9774-e54c-4d2b0005a06b';
  $map_values->sort = 10;
  $export['0bf2fa2d-e0b3-2b44-51e2-3d3c0c9a28e3'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '11a6fe95-1fad-1104-a5f8-863c8f71a27b';
  $map_values->e_uuid = '13f9e684-9da0-b9b4-f107-223551514ae2';
  $map_values->v_uuid = 'a0ba26ef-efb3-1d14-f567-3ae2e36b3bd8';
  $map_values->sort = 10;
  $export['11a6fe95-1fad-1104-a5f8-863c8f71a27b'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '1790e96a-b919-2244-5df7-2c136d20e172';
  $map_values->e_uuid = '81335603-ae1d-5de4-25c7-a1538e7ad8f5';
  $map_values->v_uuid = '1150ebb6-8e38-27d4-b929-840f71d17137';
  $map_values->sort = 10;
  $export['1790e96a-b919-2244-5df7-2c136d20e172'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '18a2b454-d3e5-4264-bdc5-9343f84cb006';
  $map_values->e_uuid = 'a54a7813-741a-f3d4-615d-e60a322df4be';
  $map_values->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $map_values->sort = 10;
  $export['18a2b454-d3e5-4264-bdc5-9343f84cb006'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '1ebdfd40-a47a-ab44-fdfa-ce98b3e3553c';
  $map_values->e_uuid = '553e8edb-bbb1-c6e4-5574-8182d8ed4e15';
  $map_values->v_uuid = '12a1e89e-1274-a394-a12a-588d3abde6e9';
  $map_values->sort = 10;
  $export['1ebdfd40-a47a-ab44-fdfa-ce98b3e3553c'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '1f012822-2482-b004-45a5-2baf2de225da';
  $map_values->e_uuid = 'ccf7115d-8830-57f4-21c4-4b7a9c204e9b';
  $map_values->v_uuid = '70391b7f-5ccc-e634-657a-5a51ef315920';
  $map_values->sort = 10;
  $export['1f012822-2482-b004-45a5-2baf2de225da'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '2102e01f-7e78-d0f4-cdd4-49c44790bd3f';
  $map_values->e_uuid = 'b0289528-53b4-2074-258c-735b863085e1';
  $map_values->v_uuid = '6c8f510b-73e1-9d84-410e-7750c6eb5581';
  $map_values->sort = 10;
  $export['2102e01f-7e78-d0f4-cdd4-49c44790bd3f'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '24cadd77-8d41-a564-65d1-8008232323d0';
  $map_values->e_uuid = '3e7a88b5-6ffe-1bb4-d1b7-f218359219ac';
  $map_values->v_uuid = '3389bb76-ad3a-5c94-81de-2bfc154f8298';
  $map_values->sort = 10;
  $export['24cadd77-8d41-a564-65d1-8008232323d0'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '2625a41c-1966-a984-e5c5-24cef534fc6e';
  $map_values->e_uuid = 'cd37520a-f3c2-63a4-9979-416311ef9a2b';
  $map_values->v_uuid = 'ceae1f55-323f-9774-250b-4b39f9b0bf91';
  $map_values->sort = 10;
  $export['2625a41c-1966-a984-e5c5-24cef534fc6e'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '2bfad62b-967e-8224-4964-74a41ce264d5';
  $map_values->e_uuid = '7c3bfbbf-3038-9ca4-952a-85f9785337e2';
  $map_values->v_uuid = 'fbeb5556-778a-ab64-2522-89eeef2793eb';
  $map_values->sort = 10;
  $export['2bfad62b-967e-8224-4964-74a41ce264d5'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '2d18dce6-af03-eb14-c59f-d56b69b187ae';
  $map_values->e_uuid = 'd061e38c-7c6a-9014-bd32-00a60a45e2d1';
  $map_values->v_uuid = '0d6ffeb4-4c40-1bc4-0d0b-4c2a8d2465b5';
  $map_values->sort = 10;
  $export['2d18dce6-af03-eb14-c59f-d56b69b187ae'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '2d5ab9b3-413a-1a84-b1a6-15a9f02ec530';
  $map_values->e_uuid = '03d3d960-f884-1fe4-2db0-52e51ac82a6e';
  $map_values->v_uuid = '4ed2c5d5-656b-be14-b55f-fbc7c1aff047';
  $map_values->sort = 10;
  $export['2d5ab9b3-413a-1a84-b1a6-15a9f02ec530'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '301d6fc8-fb51-97b4-b56e-b264c144d62a';
  $map_values->e_uuid = '9576133e-7fed-45d4-29ec-6920f85c69bb';
  $map_values->v_uuid = 'd119b2ef-6c7d-0c04-a105-f1628434e336';
  $map_values->sort = 10;
  $export['301d6fc8-fb51-97b4-b56e-b264c144d62a'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '36644c87-7dcc-cb54-6d8f-8aa32ce374af';
  $map_values->e_uuid = '4fdbf458-35c2-a8d4-f97f-c50ad6286709';
  $map_values->v_uuid = 'd119b2ef-6c7d-0c04-a105-f1628434e336';
  $map_values->sort = 10;
  $export['36644c87-7dcc-cb54-6d8f-8aa32ce374af'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '372c632d-3e00-45c4-f5ec-4dc6c6c6f161';
  $map_values->e_uuid = 'd868dbb4-c49f-8674-5560-4b0547a2c9df';
  $map_values->v_uuid = '1be4292d-14b0-f334-a1af-e1e349550f3c';
  $map_values->sort = 10;
  $export['372c632d-3e00-45c4-f5ec-4dc6c6c6f161'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '375e1c63-d82a-60a4-b50e-ab2c24bed137';
  $map_values->e_uuid = '61b61f9b-531d-4914-11d4-75430ea98677';
  $map_values->v_uuid = 'd119b2ef-6c7d-0c04-a105-f1628434e336';
  $map_values->sort = 10;
  $export['375e1c63-d82a-60a4-b50e-ab2c24bed137'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '38a99001-342a-5f14-d50f-66bc0bcce1e9';
  $map_values->e_uuid = '6bfbdc58-a531-19f4-29a2-4e080de94cd8';
  $map_values->v_uuid = 'e1bf5870-5dec-51d4-a968-5a9c01b08d89';
  $map_values->sort = 10;
  $export['38a99001-342a-5f14-d50f-66bc0bcce1e9'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '3fe55f0b-58b0-6724-1596-e7c8957ad8aa';
  $map_values->e_uuid = '7b5202bd-ebe9-2344-8d16-1bae6c3ca027';
  $map_values->v_uuid = '7b0919f2-915d-0484-6da0-a54570056151';
  $map_values->sort = 10;
  $export['3fe55f0b-58b0-6724-1596-e7c8957ad8aa'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '4415f367-c46f-1284-cd22-1fc0d2d6bf90';
  $map_values->e_uuid = '3bde0fbf-1f9e-d914-61bb-f92ce00fd65c';
  $map_values->v_uuid = '6918cf0f-f206-d494-f9da-32aa0d945ab9';
  $map_values->sort = 10;
  $export['4415f367-c46f-1284-cd22-1fc0d2d6bf90'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '4710198c-62f5-e5e4-9de9-f2eae20fabaa';
  $map_values->e_uuid = 'c15df474-dc7b-9b74-ad02-0efe8b6fe29d';
  $map_values->v_uuid = '90655745-f61d-ac84-c54e-d7907d159271';
  $map_values->sort = 10;
  $export['4710198c-62f5-e5e4-9de9-f2eae20fabaa'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '4a35ca23-c4bc-33b4-c5e3-b11eae3e7421';
  $map_values->e_uuid = 'ae797962-8b73-3044-31d3-6eebde66c95f';
  $map_values->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $map_values->sort = 10;
  $export['4a35ca23-c4bc-33b4-c5e3-b11eae3e7421'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '4a864de7-b658-c144-8187-d54a2d5a5684';
  $map_values->e_uuid = '8a82ae05-e3d7-2cc4-394f-104685da18b8';
  $map_values->v_uuid = 'e23b14bf-2112-19c4-41a7-64c531a76301';
  $map_values->sort = 10;
  $export['4a864de7-b658-c144-8187-d54a2d5a5684'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '4f30fadb-5df2-473f-992d-8e5768728a07';
  $map_values->e_uuid = '3a3e8914-dd72-488d-a816-6f9f4141d701';
  $map_values->v_uuid = 'c065cb77-6f6d-42ff-b6e1-c70b48cab17b';
  $map_values->sort = 10;
  $export['4f30fadb-5df2-473f-992d-8e5768728a07'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '5300631b-5041-4e98-9d82-7b7d8ccf40b2';
  $map_values->e_uuid = 'e8fff062-b583-49f5-989f-327864488b5d';
  $map_values->v_uuid = '40822d67-70f3-4a84-be5f-8228cde0de79';
  $map_values->sort = 10;
  $export['5300631b-5041-4e98-9d82-7b7d8ccf40b2'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '6792fd4b-dd3e-7b04-597d-883d6a0a22e6';
  $map_values->e_uuid = '54d61692-fd9b-07f4-55a0-c1ba3094cbde';
  $map_values->v_uuid = 'd5bd0d72-c9ca-8e54-41a1-05d9b65cea77';
  $map_values->sort = 10;
  $export['6792fd4b-dd3e-7b04-597d-883d6a0a22e6'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '6c379dc8-dddc-4c24-b9a9-3e0b60a4b464';
  $map_values->e_uuid = '66d1dd8d-2742-7d64-8d4c-ab7f601a7916';
  $map_values->v_uuid = '819ed112-ec85-8f64-2573-a5a88f7ac3d9';
  $map_values->sort = 10;
  $export['6c379dc8-dddc-4c24-b9a9-3e0b60a4b464'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '706ef259-0d18-53e4-41f7-52dcb1818c3e';
  $map_values->e_uuid = '88b1285a-384d-b874-7d8b-ec675f89ade7';
  $map_values->v_uuid = '28c5d5d3-761a-5e24-fdef-88e47f135dd1';
  $map_values->sort = 10;
  $export['706ef259-0d18-53e4-41f7-52dcb1818c3e'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '7481b4b4-723e-8534-61c8-91d73d476cdd';
  $map_values->e_uuid = '75b1623e-766e-f814-e5ae-aa0ccd0d0adf';
  $map_values->v_uuid = '0d6ffeb4-4c40-1bc4-0d0b-4c2a8d2465b5';
  $map_values->sort = 10;
  $export['7481b4b4-723e-8534-61c8-91d73d476cdd'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '7aa0cde1-742a-9894-8d9e-5200c5edfbb4';
  $map_values->e_uuid = '56b9e76e-8fb6-6ab4-c93e-2d3bee53a7f0';
  $map_values->v_uuid = '0d6ffeb4-4c40-1bc4-0d0b-4c2a8d2465b5';
  $map_values->sort = 10;
  $export['7aa0cde1-742a-9894-8d9e-5200c5edfbb4'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '7e7f28d2-86ab-4044-fdc5-0a262bacd72f';
  $map_values->e_uuid = '56558f6c-0175-3a14-71c9-eac27a76cc85';
  $map_values->v_uuid = '3021bc15-1305-10f4-2112-d08af39718bf';
  $map_values->sort = -100;
  $export['7e7f28d2-86ab-4044-fdc5-0a262bacd72f'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '8e794c0f-b991-acb4-c527-1b3b410b3ed9';
  $map_values->e_uuid = '4a147ba3-9e4e-bef4-75b3-2a1a02a6494d';
  $map_values->v_uuid = 'c62bd379-2702-ff84-6573-85e7627d257d';
  $map_values->sort = 10;
  $export['8e794c0f-b991-acb4-c527-1b3b410b3ed9'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '9313fb20-8ba4-cb84-8d34-ce1fd8c2cd3a';
  $map_values->e_uuid = '56558f6c-0175-3a14-71c9-eac27a76cc85';
  $map_values->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $map_values->sort = -99;
  $export['9313fb20-8ba4-cb84-8d34-ce1fd8c2cd3a'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = '98314a4a-3528-a0d4-a9b4-eaada8729c60';
  $map_values->e_uuid = '8e5ca7c5-c063-4824-15c3-eef91eb682e8';
  $map_values->v_uuid = '90655745-f61d-ac84-c54e-d7907d159271';
  $map_values->sort = 10;
  $export['98314a4a-3528-a0d4-a9b4-eaada8729c60'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = 'a19c94b1-d9ca-2c74-9d1c-ce0b309d80ac';
  $map_values->e_uuid = 'a0e64424-68f9-71f4-1df2-bf0100315aa4';
  $map_values->v_uuid = '1150ebb6-8e38-27d4-b929-840f71d17137';
  $map_values->sort = 10;
  $export['a19c94b1-d9ca-2c74-9d1c-ce0b309d80ac'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = 'a948c3de-afc2-e1d4-59d8-72df79ccde1a';
  $map_values->e_uuid = 'acdb74f6-dd28-81c4-5190-af28a09e5d47';
  $map_values->v_uuid = 'ea7df21c-2bab-3874-15a9-bc8e4afed0d9';
  $map_values->sort = 10;
  $export['a948c3de-afc2-e1d4-59d8-72df79ccde1a'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = 'b035a107-a96b-6d74-29f4-304a96445f7b';
  $map_values->e_uuid = '40cb1fd2-d934-0734-69f7-01248b663172';
  $map_values->v_uuid = '3c0f6ff4-63f2-8a54-4500-6198904477ba';
  $map_values->sort = 10;
  $export['b035a107-a96b-6d74-29f4-304a96445f7b'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = 'b3950be0-f03b-f2b4-55ab-73b70480641a';
  $map_values->e_uuid = '2e4be922-5e61-bb64-8123-d9c01c3a1640';
  $map_values->v_uuid = '479cc87e-3ff3-d124-5567-e03e00ef3169';
  $map_values->sort = 10;
  $export['b3950be0-f03b-f2b4-55ab-73b70480641a'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = 'b7528958-48b9-7c44-bd2a-e1cf2694bfac';
  $map_values->e_uuid = '7b391b37-7099-50a4-e1f6-0a3623de1421';
  $map_values->v_uuid = 'dbbf0b74-887b-ea84-99e3-45edc72bdae7';
  $map_values->sort = 10;
  $export['b7528958-48b9-7c44-bd2a-e1cf2694bfac'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = 'bca31175-51a6-49de-9a8c-50fc3ee625a0';
  $map_values->e_uuid = 'b4fe23ee-b461-4b68-813a-d9a32a637bfe';
  $map_values->v_uuid = '1150ebb6-8e38-27d4-b929-840f71d17137';
  $map_values->sort = 10;
  $export['bca31175-51a6-49de-9a8c-50fc3ee625a0'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = 'c6ccecf4-5c51-dfd4-c9af-47915f004cc8';
  $map_values->e_uuid = '062dda99-139c-0484-595b-2ddf7f0b88b9';
  $map_values->v_uuid = '90655745-f61d-ac84-c54e-d7907d159271';
  $map_values->sort = 10;
  $export['c6ccecf4-5c51-dfd4-c9af-47915f004cc8'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = 'd026595a-e2d0-c244-d5b2-b09380683abe';
  $map_values->e_uuid = '57308136-ba7d-8224-19af-26b0f6567f77';
  $map_values->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $map_values->sort = 10;
  $export['d026595a-e2d0-c244-d5b2-b09380683abe'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = 'd08cb63c-ae8d-1084-2186-d0fd0e7b20de';
  $map_values->e_uuid = '163167ec-084d-3f54-f9cd-81912e42943f';
  $map_values->v_uuid = 'd119b2ef-6c7d-0c04-a105-f1628434e336';
  $map_values->sort = 10;
  $export['d08cb63c-ae8d-1084-2186-d0fd0e7b20de'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = 'd0d391af-5955-bf44-c1ab-c06b71c725c0';
  $map_values->e_uuid = '4a162155-4f91-d2c4-b9fd-2bd17fcfd9fe';
  $map_values->v_uuid = 'd119b2ef-6c7d-0c04-a105-f1628434e336';
  $map_values->sort = 10;
  $export['d0d391af-5955-bf44-c1ab-c06b71c725c0'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = 'd25d78e0-084c-9564-9962-485b735940c7';
  $map_values->e_uuid = '05b8e136-f60b-65d4-edd0-56c69d20ce8d';
  $map_values->v_uuid = '604357bb-a73b-65c4-11d8-cf798b7eabe1';
  $map_values->sort = 10;
  $export['d25d78e0-084c-9564-9962-485b735940c7'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = 'df06852d-bd3d-45f4-45a5-6be0523d13d3';
  $map_values->e_uuid = 'bfba5600-ce4d-48d4-6d5e-289878f1889c';
  $map_values->v_uuid = '0d6ffeb4-4c40-1bc4-0d0b-4c2a8d2465b5';
  $map_values->sort = 10;
  $export['df06852d-bd3d-45f4-45a5-6be0523d13d3'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = 'e5c4c890-6bcb-4504-adb4-38597bd2e3cd';
  $map_values->e_uuid = 'bf216dfd-13d9-e774-01c6-b7ef6d7eb3a9';
  $map_values->v_uuid = 'd119b2ef-6c7d-0c04-a105-f1628434e336';
  $map_values->sort = 10;
  $export['e5c4c890-6bcb-4504-adb4-38597bd2e3cd'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = 'e5f63217-d80f-6c34-05bc-063c3bc057e2';
  $map_values->e_uuid = 'ccec6101-d44c-1484-edd8-bab3e529b0e7';
  $map_values->v_uuid = '0d6ffeb4-4c40-1bc4-0d0b-4c2a8d2465b5';
  $map_values->sort = 10;
  $export['e5f63217-d80f-6c34-05bc-063c3bc057e2'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = 'ea5d0baf-096b-f614-4586-3485744743a5';
  $map_values->e_uuid = 'b35762f5-54c6-4044-355a-96a20c9d21dc';
  $map_values->v_uuid = '1150ebb6-8e38-27d4-b929-840f71d17137';
  $map_values->sort = 10;
  $export['ea5d0baf-096b-f614-4586-3485744743a5'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = 'eac661af-dfd0-1854-a5a1-f5ea9aad1244';
  $map_values->e_uuid = '155a1e44-920c-f014-dd4c-3803c0a3b0e7';
  $map_values->v_uuid = '0d6ffeb4-4c40-1bc4-0d0b-4c2a8d2465b5';
  $map_values->sort = 10;
  $export['eac661af-dfd0-1854-a5a1-f5ea9aad1244'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = 'f182d62c-a1fa-6104-8910-7b1622198614';
  $map_values->e_uuid = '886babfd-dc9f-eaa4-99df-0ba94265ac17';
  $map_values->v_uuid = '1150ebb6-8e38-27d4-b929-840f71d17137';
  $map_values->sort = 10;
  $export['f182d62c-a1fa-6104-8910-7b1622198614'] = $map_values;

  $map_values = new stdClass();
  $map_values->disabled = FALSE; /* Edit this to true to make a default map_values disabled initially */
  $map_values->api_version = 1;
  $map_values->mv_uuid = 'f9f2a603-b1ca-4b8c-8ac8-eded98b7c430';
  $map_values->e_uuid = '76a5db8e-179c-4c8b-bd60-4864ba5e6132';
  $map_values->v_uuid = 'e4539af4-043f-49d4-ab45-379299f73085';
  $map_values->sort = 10;
  $export['f9f2a603-b1ca-4b8c-8ac8-eded98b7c430'] = $map_values;

  return $export;
}

/**
 * Implements hook_default_bibdk_custom_search_option().
 */
function bibdk_custom_search_feature_default_bibdk_custom_search_option() {
  $export = array();

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '00a9186a-34b4-1d04-559b-84254e8975ea';
  $option->v_uuid = '12a1e89e-1274-a394-a12a-588d3abde6e9';
  $option->sort = -98;
  $option->label = 'engelsk';
  $option->value = 'term.language="eng"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['00a9186a-34b4-1d04-559b-84254e8975ea'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '0102b87c-cee2-2474-a555-c526a32fe0d3';
  $option->v_uuid = '1c0066cf-f6cb-8694-b102-24a394e912d5';
  $option->sort = -100;
  $option->label = 'noveller';
  $option->value = '"noveller"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['0102b87c-cee2-2474-a555-c526a32fe0d3'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '01cb27f7-17f2-4784-01ac-3b10f34f4865';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = -85;
  $option->label = 'kinesisk';
  $option->value = 'term.language="chi"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['01cb27f7-17f2-4784-01ac-3b10f34f4865'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '021049fe-ac98-4234-29b6-8dcfe6af72f8';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = -73;
  $option->label = 'tjekkisk';
  $option->value = 'term.language=("cze" or "ces")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['021049fe-ac98-4234-29b6-8dcfe6af72f8'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '02962364-d00d-6aa4-051d-a0170dfdb12d';
  $option->v_uuid = '3389bb76-ad3a-5c94-81de-2bfc154f8298';
  $option->sort = -89;
  $option->label = 'Fra 12 år';
  $option->value = '"Fra 12 år"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['02962364-d00d-6aa4-051d-a0170dfdb12d'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '02ad0103-7096-4474-a1c8-612d07eb7acf';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -63;
  $option->label = 'Rock';
  $option->value = '"rock"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['02ad0103-7096-4474-a1c8-612d07eb7acf'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '0312c8d8-3891-49a4-a773-a516fbbbbae4';
  $option->v_uuid = '6e4d6c92-a9b4-4f53-830c-db8bb5ce9dae';
  $option->sort = -99;
  $option->label = 'blandet kor';
  $option->value = 'dkcclterm.dk=78.652*';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['0312c8d8-3891-49a4-a773-a516fbbbbae4'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '04a25dc9-3dd5-76d4-b1db-d36dfba45e7f';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -93;
  $option->label = '2008';
  $option->value = '"2008"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['04a25dc9-3dd5-76d4-b1db-d36dfba45e7f'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '04e1ad22-c09f-19c4-25f0-c8cbb3cfc80c';
  $option->v_uuid = '604357bb-a73b-65c4-11d8-cf798b7eabe1';
  $option->sort = -98;
  $option->label = 'e-musik';
  $option->value = '("musik" and term.accessType="online")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['04e1ad22-c09f-19c4-25f0-c8cbb3cfc80c'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '05962111-b3ab-4fc9-9c2d-317b5b84257c';
  $option->v_uuid = '40822d67-70f3-4a84-be5f-8228cde0de79';
  $option->sort = -89;
  $option->label = 'Singer/songwriter';
  $option->value = '"singer/songwriter"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['05962111-b3ab-4fc9-9c2d-317b5b84257c'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '05c94334-b903-7204-c139-c82bdc9b68ae';
  $option->v_uuid = '6918cf0f-f206-d494-f9da-32aa0d945ab9';
  $option->sort = -89;
  $option->label = 'Fra 12 år';
  $option->value = '"for 12 år"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['05c94334-b903-7204-c139-c82bdc9b68ae'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '079e4b9e-9c02-4ee5-b30e-c812bfc15931';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -76;
  $option->label = 'Goth';
  $option->value = '"goth"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['079e4b9e-9c02-4ee5-b30e-c812bfc15931'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '07b223be-e00c-4654-d511-8cd8726fdf37';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -65;
  $option->label = '1980';
  $option->value = '"1980"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['07b223be-e00c-4654-d511-8cd8726fdf37'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '096f7b5b-6695-476b-aad7-526a761dd035';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -73;
  $option->label = 'Indietronica';
  $option->value = '"indietronica"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['096f7b5b-6695-476b-aad7-526a761dd035'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '0981bf00-199a-3134-ed87-8a8cb76dc8c8';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -70;
  $option->label = 'science fiction';
  $option->value = '"science fiction"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['0981bf00-199a-3134-ed87-8a8cb76dc8c8'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '0a640dca-4e71-5194-d9e9-deb2c0fba93a';
  $option->v_uuid = '4ed2c5d5-656b-be14-b55f-fbc7c1aff047';
  $option->sort = -88;
  $option->label = 'portugisisk';
  $option->value = 'term.language="por"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['0a640dca-4e71-5194-d9e9-deb2c0fba93a'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '0b824b0f-1162-4c1c-a8b6-f451e7a82bb6';
  $option->v_uuid = 'e23b14bf-2112-19c4-41a7-64c531a76301';
  $option->sort = 10;
  $option->label = 'alle';
  $option->value = 'facet.type=facet.type';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['0b824b0f-1162-4c1c-a8b6-f451e7a82bb6'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '0be18392-79b6-02c4-c18e-7149947f0a5f';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = 14;
  $option->label = '1901';
  $option->value = '"1901"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['0be18392-79b6-02c4-c18e-7149947f0a5f'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '0bebddf4-1d90-0e14-e1ea-98948056f902';
  $option->v_uuid = '819ed112-ec85-8f64-2573-a5a88f7ac3d9';
  $option->sort = -93;
  $option->label = 'e-spil';
  $option->value = 'term.type="pc-spil"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['0bebddf4-1d90-0e14-e1ea-98948056f902'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '0c2d782c-3a28-9d54-4961-d3f814ed8d16';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -95;
  $option->label = 'Americana';
  $option->value = '"americana"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['0c2d782c-3a28-9d54-4961-d3f814ed8d16'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '0c85730a-ab99-f254-713c-fb23f5561bf0';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -63;
  $option->label = '1978';
  $option->value = '"1978"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['0c85730a-ab99-f254-713c-fb23f5561bf0'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '0da5b6ed-259e-a524-114d-4cbfa06fa9ba';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -48;
  $option->label = '1963';
  $option->value = '"1963"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['0da5b6ed-259e-a524-114d-4cbfa06fa9ba'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '0dd49630-3980-4ae9-aa6d-81a449c7783f';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -48;
  $option->label = 'Andre koncerter';
  $option->value = '"andre koncerter"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['0dd49630-3980-4ae9-aa6d-81a449c7783f'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '10103f6e-431b-9094-c193-0e934986ee6a';
  $option->v_uuid = 'b056401f-4ff0-a654-55b8-835ad50af150';
  $option->sort = -98;
  $option->label = 'cd - mp3';
  $option->value = 'term.type="lydbog" and term.type="cd-mp3"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['10103f6e-431b-9094-c193-0e934986ee6a'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '120ef2de-bb72-49cc-945e-6a69fe7dffd8';
  $option->v_uuid = 'db557731-87b3-4fd0-b09b-ef08bdfa4d5b';
  $option->sort = -95;
  $option->label = 'to guitarer';
  $option->value = 'dkcclterm.dk="78.437" and dkcclterm.no="guitarer"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['120ef2de-bb72-49cc-945e-6a69fe7dffd8'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '121adc7f-242e-eb84-0545-f4ba6cc3e1f2';
  $option->v_uuid = '6918cf0f-f206-d494-f9da-32aa0d945ab9';
  $option->sort = -99;
  $option->label = 'Fra 2 år';
  $option->value = '"for 2 år"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['121adc7f-242e-eb84-0545-f4ba6cc3e1f2'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '136e3a23-c968-bac4-19cc-967c3969a983';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = -78;
  $option->label = 'serbisk';
  $option->value = 'term.language="scc"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['136e3a23-c968-bac4-19cc-967c3969a983'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '139b5c34-932e-44fa-8192-55576b202b15';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -96;
  $option->label = 'animationsfilm (voksne)';
  $option->value = '"animationsfilm mest for voksne"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['139b5c34-932e-44fa-8192-55576b202b15'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '13e8eec6-5512-46ef-82c3-add9ff7bd85a';
  $option->v_uuid = '2dfa5ad4-131f-4fb8-881f-3607e4e1d4d1';
  $option->sort = -84;
  $option->label = 'alle partiturer';
  $option->value = 'dkcclterm.ma=("pp" or "ps" or "pa" or "pl" or "pk" or "pu" or "pr" or "po")';
  $option->expand = '0cd9f79e-2d4c-466a-a2ce-121b00a41005';
  $option->is_disabled = FALSE;
  $export['13e8eec6-5512-46ef-82c3-add9ff7bd85a'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '13e9c659-5d7c-4fd9-b8a9-634363b8b3f3';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -64;
  $option->label = 'jazzfilm';
  $option->value = '"jazzfilm"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['13e9c659-5d7c-4fd9-b8a9-634363b8b3f3'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '14dad616-4848-e334-0123-874033a23e7f';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -94;
  $option->label = '2009';
  $option->value = '"2009"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['14dad616-4848-e334-0123-874033a23e7f'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '159e3695-369f-4fde-9f2c-cbbf6fd437ce';
  $option->v_uuid = 'db557731-87b3-4fd0-b09b-ef08bdfa4d5b';
  $option->sort = -88;
  $option->label = 'tre eller flere strygere og blæsere';
  $option->value = 'dkcclterm.dk=78.423*';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['159e3695-369f-4fde-9f2c-cbbf6fd437ce'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '15d400a1-1e44-4730-b85e-63195d888c8d';
  $option->v_uuid = '2dfa5ad4-131f-4fb8-881f-3607e4e1d4d1';
  $option->sort = -96;
  $option->label = 'noder for kor';
  $option->value = 'dkcclterm.ma="mu" and dkcclterm.em=("kor" or "børnekor" or "drengekor" or "pigekor" or "mandskor" or "kvindekor" or "damekor")';
  $option->expand = '6e4d6c92-a9b4-4f53-830c-db8bb5ce9dae';
  $option->is_disabled = FALSE;
  $export['15d400a1-1e44-4730-b85e-63195d888c8d'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '1642c8b5-1a24-1304-255e-2a473731c94b';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -4;
  $option->label = '1919';
  $option->value = '"1919"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['1642c8b5-1a24-1304-255e-2a473731c94b'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '173d181f-3013-06b4-2153-a5f2eafb0876';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -73;
  $option->label = 'politi';
  $option->value = '"politifilm"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['173d181f-3013-06b4-2153-a5f2eafb0876'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '1779bde0-7545-4436-a6be-cc56dcaf8c54';
  $option->v_uuid = '0cd9f79e-2d4c-466a-a2ce-121b00a41005';
  $option->sort = 10;
  $option->label = 'studiepartiturer';
  $option->value = 'dkcclterm.ma="ps"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['1779bde0-7545-4436-a6be-cc56dcaf8c54'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '17bfc996-7f89-77e4-d521-2ab315cd9f5d';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -80;
  $option->label = '1995';
  $option->value = '"1995"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['17bfc996-7f89-77e4-d521-2ab315cd9f5d'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '17cff911-5212-95b4-f58b-68eb33ae20fd';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -44;
  $option->label = '1959';
  $option->value = '"1959"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['17cff911-5212-95b4-f58b-68eb33ae20fd'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '183f3e7d-7bcb-0f34-cd3b-f48aa8caf338';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -55;
  $option->label = '1970';
  $option->value = '"1970"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['183f3e7d-7bcb-0f34-cd3b-f48aa8caf338'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '19144f39-4e0a-e6e4-0d2e-5e19684430b7';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -66;
  $option->label = '1981';
  $option->value = '"1981"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['19144f39-4e0a-e6e4-0d2e-5e19684430b7'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '19fde25a-29c6-9bf4-31a2-ec3037108a0c';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -60;
  $option->label = 'operafilm';
  $option->value = '"operafilm"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['19fde25a-29c6-9bf4-31a2-ec3037108a0c'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '1a08671b-8407-7ab4-51ea-7d95322dc90a';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = -97;
  $option->label = 'bulgarsk';
  $option->value = 'term.language="bul"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['1a08671b-8407-7ab4-51ea-7d95322dc90a'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '1bfe0889-237f-a034-4d00-3b12c38c93c5';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -100;
  $option->label = 'Alle';
  $option->value = '';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['1bfe0889-237f-a034-4d00-3b12c38c93c5'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '1c025dad-6622-7a74-f5cb-3f86dfdc241a';
  $option->v_uuid = 'e23b14bf-2112-19c4-41a7-64c531a76301';
  $option->sort = -88;
  $option->label = 'computerspil';
  $option->value = 'term.type="spil" or term.workType="game"';
  $option->expand = '3c0f6ff4-63f2-8a54-4500-6198904477ba';
  $option->is_disabled = FALSE;
  $export['1c025dad-6622-7a74-f5cb-3f86dfdc241a'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '1c3cbec4-6dc2-484e-9253-ff269c1b0973';
  $option->v_uuid = '2dfa5ad4-131f-4fb8-881f-3607e4e1d4d1';
  $option->sort = -88;
  $option->label = 'noder for trommesæt';
  $option->value = 'dkcclterm.ma="mu" and (dkcclterm.dk=("78.482" or "78.4821") or dkcclterm.em="trommesæt")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['1c3cbec4-6dc2-484e-9253-ff269c1b0973'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '1c7e81d5-661c-31b4-0134-357fc0d1a646';
  $option->v_uuid = 'e23b14bf-2112-19c4-41a7-64c531a76301';
  $option->sort = -94;
  $option->label = 'artikler';
  $option->value = 'term.type="artikel" or term.workType="article"';
  $option->expand = '479cc87e-3ff3-d124-5567-e03e00ef3169';
  $option->is_disabled = FALSE;
  $export['1c7e81d5-661c-31b4-0134-357fc0d1a646'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '1d6019b5-c9ca-8634-e1e2-56c2fe9d421d';
  $option->v_uuid = '479cc87e-3ff3-d124-5567-e03e00ef3169';
  $option->sort = -98;
  $option->label = 'tidsskriftsartikler';
  $option->value = 'term.type="tidsskriftsartikel"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['1d6019b5-c9ca-8634-e1e2-56c2fe9d421d'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '1d8d0ee6-a3a2-52c4-d163-98ea3935a898';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -77;
  $option->label = '1992';
  $option->value = '"1992"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['1d8d0ee6-a3a2-52c4-d163-98ea3935a898'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '1da795ff-dcd9-0544-f5d4-94559b67aab6';
  $option->v_uuid = '8e7bda97-5430-9774-e54c-4d2b0005a06b';
  $option->sort = -99;
  $option->label = 'danske spillefilm';
  $option->value = '"dansk"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['1da795ff-dcd9-0544-f5d4-94559b67aab6'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '1ed2a1de-ba07-7174-e147-525624d93ecf';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = -88;
  $option->label = 'hollandsk';
  $option->value = 'term.language=("dut" or "fle")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['1ed2a1de-ba07-7174-e147-525624d93ecf'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '1eda01eb-11c8-4794-91b6-fde1628bfdbd';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -36;
  $option->label = '1951';
  $option->value = '"1951"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['1eda01eb-11c8-4794-91b6-fde1628bfdbd'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '1f6f893b-3711-8d24-19a8-a00d711cf225';
  $option->v_uuid = '8e7bda97-5430-9774-e54c-4d2b0005a06b';
  $option->sort = -100;
  $option->label = 'Alle';
  $option->value = '';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['1f6f893b-3711-8d24-19a8-a00d711cf225'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '1f762c21-aa4b-bbc4-05e4-8d22c9fd1bb9';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -81;
  $option->label = 'Filmmusik - soundtrack';
  $option->value = '"filmmusik - soundtracks"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['1f762c21-aa4b-bbc4-05e4-8d22c9fd1bb9'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '1fd3aa44-cbf2-4fc9-8934-3a1886e29c36';
  $option->v_uuid = 'db557731-87b3-4fd0-b09b-ef08bdfa4d5b';
  $option->sort = -91;
  $option->label = 'to eller flere strygere med klaver';
  $option->value = 'dkcclterm.dk=78.424*';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['1fd3aa44-cbf2-4fc9-8934-3a1886e29c36'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '202f664b-bb2f-f494-b9df-dd05607b69ad';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -33;
  $option->label = '1948';
  $option->value = '"1948"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['202f664b-bb2f-f494-b9df-dd05607b69ad'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '2132a4bc-74b9-31a4-d91e-177decac5196';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = -75;
  $option->label = 'svensk';
  $option->value = 'term.language=("swe" or "sve")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['2132a4bc-74b9-31a4-d91e-177decac5196'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '2149d559-7ce8-e3c4-a561-ac3278c22661';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -65;
  $option->label = 'Punk';
  $option->value = '"punk"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['2149d559-7ce8-e3c4-a561-ac3278c22661'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '2151d98f-bff7-f4a4-815c-9ede6fccd28d';
  $option->v_uuid = '3389bb76-ad3a-5c94-81de-2bfc154f8298';
  $option->sort = -95;
  $option->label = 'Fra 6 år';
  $option->value = '"Fra 6 år"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['2151d98f-bff7-f4a4-815c-9ede6fccd28d'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '21b84c1a-a013-4f35-9fa3-ec3ac06f0179';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -97;
  $option->label = 'animationsfilm (børn)';
  $option->value = '"animationsfilm mest for børn"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['21b84c1a-a013-4f35-9fa3-ec3ac06f0179'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '21f6c940-699c-aaa4-f5e0-b70d62f7aebd';
  $option->v_uuid = '604357bb-a73b-65c4-11d8-cf798b7eabe1';
  $option->sort = -97;
  $option->label = 'blu-ray';
  $option->value = 'term.type="blu-ray"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['21f6c940-699c-aaa4-f5e0-b70d62f7aebd'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '22837940-734a-4bf4-3d3d-b9dd680b100d';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = -91;
  $option->label = 'færøsk';
  $option->value = 'term.language=("far" or "fao")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['22837940-734a-4bf4-3d3d-b9dd680b100d'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '22909313-574f-4f0c-9fde-d13f1e28ad3b';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -96;
  $option->label = '80\'er musik';
  $option->value = '"80\'er musik"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['22909313-574f-4f0c-9fde-d13f1e28ad3b'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '232a057c-503c-41a4-f558-1c6488af4ebb';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -50;
  $option->label = '1965';
  $option->value = '"1965"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['232a057c-503c-41a4-f558-1c6488af4ebb'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '2335d70a-1b68-cde4-2d44-6ac3787e69aa';
  $option->v_uuid = '7b0919f2-915d-0484-6da0-a54570056151';
  $option->sort = -99;
  $option->label = 'Tilladt fra 7 år';
  $option->value = '"Tilladt for børn over 7 år"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['2335d70a-1b68-cde4-2d44-6ac3787e69aa'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '23402893-d3a7-3164-a550-ee70ff64c90b';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -18;
  $option->label = '1933';
  $option->value = '"1933"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['23402893-d3a7-3164-a550-ee70ff64c90b'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '238c9bb0-6841-da64-199a-aab1670b05e8';
  $option->v_uuid = '3c0f6ff4-63f2-8a54-4500-6198904477ba';
  $option->sort = -94;
  $option->label = 'Playstation Vita';
  $option->value = '"playstation vita"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['238c9bb0-6841-da64-199a-aab1670b05e8'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '23d48bf0-07a3-3b74-3de3-77b918d1426d';
  $option->v_uuid = '4ed2c5d5-656b-be14-b55f-fbc7c1aff047';
  $option->sort = -97;
  $option->label = 'engelsk';
  $option->value = 'term.language="eng"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['23d48bf0-07a3-3b74-3de3-77b918d1426d'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '23f98cea-867b-4844-bdac-a4cf6e54efcd';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -75;
  $option->label = 'Hip hop';
  $option->value = '"hip hop"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['23f98cea-867b-4844-bdac-a4cf6e54efcd'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '2400c0a2-bfbb-2cd4-a903-6d0472e5fa7d';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -64;
  $option->label = 'Reggae';
  $option->value = '"reggae"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['2400c0a2-bfbb-2cd4-a903-6d0472e5fa7d'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '240ae559-eafd-d7d4-a156-ed562f3c4946';
  $option->v_uuid = 'f79c6d0f-effe-6944-7951-211d70e904d7';
  $option->sort = -99;
  $option->label = 'dvd';
  $option->value = 'term.type="dvd"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['240ae559-eafd-d7d4-a156-ed562f3c4946'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '24832085-9f0e-b024-fd2f-e06d9bd3f587';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -40;
  $option->label = '1955';
  $option->value = '"1955"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['24832085-9f0e-b024-fd2f-e06d9bd3f587'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '25dfd2ef-64fe-46e2-9385-c872e6382c16';
  $option->v_uuid = '2dfa5ad4-131f-4fb8-881f-3607e4e1d4d1';
  $option->sort = -89;
  $option->label = 'guitarskoler';
  $option->value = 'dkcclterm.em="guitarskoler"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['25dfd2ef-64fe-46e2-9385-c872e6382c16'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '269037c4-a599-3374-ed64-4111e7f4183d';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -84;
  $option->label = '1999';
  $option->value = '"1999"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['269037c4-a599-3374-ed64-4111e7f4183d'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '26fa21f8-7adb-9d44-29f8-553b68730fd8';
  $option->v_uuid = '3389bb76-ad3a-5c94-81de-2bfc154f8298';
  $option->sort = -97;
  $option->label = 'Fra 4 år';
  $option->value = '"Fra 4 år"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['26fa21f8-7adb-9d44-29f8-553b68730fd8'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '272aa076-0dc1-4322-b59c-6d06f2ceed0a';
  $option->v_uuid = '2dfa5ad4-131f-4fb8-881f-3607e4e1d4d1';
  $option->sort = -98;
  $option->label = 'node + cd';
  $option->value = 'dkcclterm.ma=("mu" and "lm") not dkcclterm.ma="mm"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['272aa076-0dc1-4322-b59c-6d06f2ceed0a'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '27be38b8-2b2f-9ca4-31b3-0cb4840bb570';
  $option->v_uuid = '4ed2c5d5-656b-be14-b55f-fbc7c1aff047';
  $option->sort = -98;
  $option->label = 'dansk';
  $option->value = 'term.language="dan"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['27be38b8-2b2f-9ca4-31b3-0cb4840bb570'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '287ba40b-f593-ca14-5943-97e81e88d359';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -57;
  $option->label = 'rockfilm';
  $option->value = '"rockfilm"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['287ba40b-f593-ca14-5943-97e81e88d359'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '28ae7476-e666-e454-397a-db1b37018313';
  $option->v_uuid = 'fbeb5556-778a-ab64-2522-89eeef2793eb';
  $option->sort = -93;
  $option->label = 'platformspil';
  $option->value = '"platformspil"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['28ae7476-e666-e454-397a-db1b37018313'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '29d5c60a-73a9-50e4-dd83-38b9e28f9cf1';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -71;
  $option->label = '1986';
  $option->value = '"1986"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['29d5c60a-73a9-50e4-dd83-38b9e28f9cf1'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '29f9816f-2778-7084-651e-340aad0fef00';
  $option->v_uuid = '6918cf0f-f206-d494-f9da-32aa0d945ab9';
  $option->sort = -94;
  $option->label = 'Fra 7 år';
  $option->value = '"for 7 år"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['29f9816f-2778-7084-651e-340aad0fef00'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '2a42fba4-8ff8-c794-6d94-d39df70e95c0';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -29;
  $option->label = '1944';
  $option->value = '"1944"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['2a42fba4-8ff8-c794-6d94-d39df70e95c0'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '2a55c4ce-15c8-c274-9930-3027f2e9ca66';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -44;
  $option->label = 'Operetter';
  $option->value = '"operetter"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['2a55c4ce-15c8-c274-9930-3027f2e9ca66'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '2b2918ab-84c8-4948-9595-005bba25e299';
  $option->v_uuid = '6e072028-31b8-4f7d-86cc-d24ce84024bd';
  $option->sort = 10;
  $option->label = 'Mindre orkestre og ensembler';
  $option->value = 'dkcclterm.dk=("78.411:8" or "78.421:9" or "78.422:9" or "78.423:9" or "78.424:9" or "78.425:9" or "78.426:9" or "78.427:9" or "78.429:9")';
  $option->expand = '0';
  $option->is_disabled = TRUE;
  $export['2b2918ab-84c8-4948-9595-005bba25e299'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '2b47c980-b31b-0ad4-9569-04ef73133df7';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = -100;
  $option->label = 'Alle';
  $option->value = '';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['2b47c980-b31b-0ad4-9569-04ef73133df7'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '2c0d6436-a072-0024-2934-3c70f1077783';
  $option->v_uuid = 'ceae1f55-323f-9774-250b-4b39f9b0bf91';
  $option->sort = -98;
  $option->label = 'Fra 7 år';
  $option->value = '"7+"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['2c0d6436-a072-0024-2934-3c70f1077783'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '2c43ecd8-4671-ce84-cd4d-7405dd5fb741';
  $option->v_uuid = 'b056401f-4ff0-a654-55b8-835ad50af150';
  $option->sort = -97;
  $option->label = 'på nettet';
  $option->value = '(term.type="lydbog" and term.accessType="online")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['2c43ecd8-4671-ce84-cd4d-7405dd5fb741'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '2c584806-b4a2-4eba-839d-a70146fc85ea';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -80;
  $option->label = 'horror';
  $option->value = '"horror"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['2c584806-b4a2-4eba-839d-a70146fc85ea'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '2c622624-22ad-8664-d58e-07809a75c48b';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = -81;
  $option->label = 'portugisisk';
  $option->value = 'term.language="por"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['2c622624-22ad-8664-d58e-07809a75c48b'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '2c969f0b-ce24-4968-9f64-e589918ed754';
  $option->v_uuid = '3c0f6ff4-63f2-8a54-4500-6198904477ba';
  $option->sort = -96;
  $option->label = 'Playstation 4';
  $option->value = '"playstation 4"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['2c969f0b-ce24-4968-9f64-e589918ed754'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '2e1186cb-6a2c-9c54-dd1a-6172443fc570';
  $option->v_uuid = '3c0f6ff4-63f2-8a54-4500-6198904477ba';
  $option->sort = -92;
  $option->label = 'e-spil';
  $option->value = '"pc-spil (net)"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['2e1186cb-6a2c-9c54-dd1a-6172443fc570'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '2e137bb2-3835-fc34-c959-8e740005c21a';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = -77;
  $option->label = 'somali';
  $option->value = 'term.language="som"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['2e137bb2-3835-fc34-c959-8e740005c21a'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '2ee2a274-57be-4096-9818-512f37df8bb4';
  $option->v_uuid = '2dfa5ad4-131f-4fb8-881f-3607e4e1d4d1';
  $option->sort = -100;
  $option->label = 'alle noder';
  $option->value = 'dkcclterm.ma="mu"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['2ee2a274-57be-4096-9818-512f37df8bb4'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '2f0a7fa2-5a91-4e45-ba0e-860b759f1c14';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -41;
  $option->label = 'Orgel solo';
  $option->value = '"orgel solo"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['2f0a7fa2-5a91-4e45-ba0e-860b759f1c14'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '2f1986f4-c08a-b044-95ad-464501323bd7';
  $option->v_uuid = '4ed2c5d5-656b-be14-b55f-fbc7c1aff047';
  $option->sort = -90;
  $option->label = 'persisk';
  $option->value = 'term.language="per"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['2f1986f4-c08a-b044-95ad-464501323bd7'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '2f492b72-8d01-9c74-6916-4b099428e81d';
  $option->v_uuid = '6918cf0f-f206-d494-f9da-32aa0d945ab9';
  $option->sort = -87;
  $option->label = 'Fra 14 år';
  $option->value = '"for 14 år"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['2f492b72-8d01-9c74-6916-4b099428e81d'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '2f60a039-3e3c-44a4-c9e6-66548746c30b';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -57;
  $option->label = '1972';
  $option->value = '"1972"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['2f60a039-3e3c-44a4-c9e6-66548746c30b'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '2fd43324-f814-d184-e9a2-90b910309dcc';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -43;
  $option->label = '1958';
  $option->value = '"1958"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['2fd43324-f814-d184-e9a2-90b910309dcc'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '30de9fb4-378f-4a00-8f92-47bf21825da7';
  $option->v_uuid = '40822d67-70f3-4a84-be5f-8228cde0de79';
  $option->sort = -91;
  $option->label = 'Pop';
  $option->value = '"pop"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['30de9fb4-378f-4a00-8f92-47bf21825da7'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '30f6d776-852b-ee74-c51b-d8d363d8bf95';
  $option->v_uuid = '1c0066cf-f6cb-8694-b102-24a394e912d5';
  $option->sort = -97;
  $option->label = 'digte';
  $option->value = '"digte"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['30f6d776-852b-ee74-c51b-d8d363d8bf95'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '316a7dea-9c98-70e4-a9b1-03767f6e368e';
  $option->v_uuid = '4ed2c5d5-656b-be14-b55f-fbc7c1aff047';
  $option->sort = -91;
  $option->label = 'norsk';
  $option->value = 'term.language="nor"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['316a7dea-9c98-70e4-a9b1-03767f6e368e'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '31a940f6-cb40-4134-1507-51827bdec651';
  $option->v_uuid = 'fbeb5556-778a-ab64-2522-89eeef2793eb';
  $option->sort = -86;
  $option->label = 'synge- og dansespil';
  $option->value = '"karaokespil" or "dans"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['31a940f6-cb40-4134-1507-51827bdec651'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '336f07d5-1dbd-8d94-550c-0426aa516bf1';
  $option->v_uuid = '3389bb76-ad3a-5c94-81de-2bfc154f8298';
  $option->sort = -86;
  $option->label = 'Fra 15 år';
  $option->value = '"Fra 15 år"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['336f07d5-1dbd-8d94-550c-0426aa516bf1'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '33f4a211-7b06-2a74-594d-71ef52132a7b';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = -70;
  $option->label = 'ungarsk';
  $option->value = 'term.language="ung"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['33f4a211-7b06-2a74-594d-71ef52132a7b'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '3425031e-72e4-0484-5570-eee2f7d96810';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -99;
  $option->label = 'actionfilm';
  $option->value = '"actionfilm"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['3425031e-72e4-0484-5570-eee2f7d96810'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '34c605ba-e1b2-4518-a59a-a31cc3166bb2';
  $option->v_uuid = '819ed112-ec85-8f64-2573-a5a88f7ac3d9';
  $option->sort = -97;
  $option->label = 'e-tidsskriftartikler';
  $option->value = 'term.type="tidsskriftsartikel"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['34c605ba-e1b2-4518-a59a-a31cc3166bb2'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '34d43ebd-ef9a-ea74-418c-df26f7b1be75';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -79;
  $option->label = '1994';
  $option->value = '"1994"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['34d43ebd-ef9a-ea74-418c-df26f7b1be75'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '34fa1c8d-267f-4a5e-9ffd-52458e94d627';
  $option->v_uuid = '2dfa5ad4-131f-4fb8-881f-3607e4e1d4d1';
  $option->sort = -99;
  $option->label = 'e-noder';
  $option->value = 'dkcclterm.ma=("mu" and "xe")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['34fa1c8d-267f-4a5e-9ffd-52458e94d627'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '3504a246-1dae-4b06-8895-998f43fbaead';
  $option->v_uuid = '8e7bda97-5430-9774-e54c-4d2b0005a06b';
  $option->sort = -98;
  $option->label = 'bosniske spille film';
  $option->value = '"bosnisk"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['3504a246-1dae-4b06-8895-998f43fbaead'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '350ab740-dea3-a1e4-a9cf-bb5f6aee3763';
  $option->v_uuid = 'f79c6d0f-effe-6944-7951-211d70e904d7';
  $option->sort = -97;
  $option->label = 'blu-ray';
  $option->value = 'term.type="blu-ray"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['350ab740-dea3-a1e4-a9cf-bb5f6aee3763'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '35af48c9-0b22-7e14-5986-56bf507da0d0';
  $option->v_uuid = 'f79c6d0f-effe-6944-7951-211d70e904d7';
  $option->sort = -96;
  $option->label = 'VHS';
  $option->value = 'term.type="video"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['35af48c9-0b22-7e14-5986-56bf507da0d0'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '3689ff50-3c68-8c44-59f0-63246f074c2a';
  $option->v_uuid = '3c0f6ff4-63f2-8a54-4500-6198904477ba';
  $option->sort = -88;
  $option->label = 'Xbox 360';
  $option->value = '"xbox 360"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['3689ff50-3c68-8c44-59f0-63246f074c2a'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '36d207fa-72a6-2f94-7de7-455c9836ab71';
  $option->v_uuid = '3021bc15-1305-10f4-2112-d08af39718bf';
  $option->sort = -100;
  $option->label = 'År lig med';
  $option->value = '"year_eq"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['36d207fa-72a6-2f94-7de7-455c9836ab71'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '37416938-5d08-3a24-b1ef-91cb82d5732c';
  $option->v_uuid = '4ed2c5d5-656b-be14-b55f-fbc7c1aff047';
  $option->sort = -99;
  $option->label = 'arabisk';
  $option->value = 'term.language="ara"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['37416938-5d08-3a24-b1ef-91cb82d5732c'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '37aa8e3e-7ed2-a8f4-dd70-743758a0c28c';
  $option->v_uuid = 'fbeb5556-778a-ab64-2522-89eeef2793eb';
  $option->sort = -98;
  $option->label = 'adventurespil';
  $option->value = '"adventurespil"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['37aa8e3e-7ed2-a8f4-dd70-743758a0c28c'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '37ce90d0-4329-0004-6516-87a8f3115fbb';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -67;
  $option->label = '1982';
  $option->value = '"1982"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['37ce90d0-4329-0004-6516-87a8f3115fbb'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '380912a7-9c5b-5c54-f5e7-40fb8b2fa208';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -5;
  $option->label = '1920';
  $option->value = '"1920"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['380912a7-9c5b-5c54-f5e7-40fb8b2fa208'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '380a95e5-72a6-e4f4-d927-f04c627a79eb';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -54;
  $option->label = 'Verdensmusik-world music';
  $option->value = '"verdensmusik - world music"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['380a95e5-72a6-e4f4-d927-f04c627a79eb'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '384f2c0d-786b-4c48-a486-a5df8f742b92';
  $option->v_uuid = '6e4d6c92-a9b4-4f53-830c-db8bb5ce9dae';
  $option->sort = -98;
  $option->label = 'børnekor';
  $option->value = 'dkcclterm.em="børnekor"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['384f2c0d-786b-4c48-a486-a5df8f742b92'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '386b4e52-6666-3354-3127-8fb68db0e1ac';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -9;
  $option->label = '1924';
  $option->value = '"1924"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['386b4e52-6666-3354-3127-8fb68db0e1ac'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '3992e7b1-9f8d-40ad-af50-4db6a8e477df';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -97;
  $option->label = '70\'er rock';
  $option->value = '"70\'er rock"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['3992e7b1-9f8d-40ad-af50-4db6a8e477df'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '39b55f0d-b66b-4c3f-9efc-88a21fecd101';
  $option->v_uuid = '40822d67-70f3-4a84-be5f-8228cde0de79';
  $option->sort = -99;
  $option->label = 'Country';
  $option->value = '"country"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['39b55f0d-b66b-4c3f-9efc-88a21fecd101'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '39c56404-f046-0ad4-4d5b-de9d1d614677';
  $option->v_uuid = '7b0919f2-915d-0484-6da0-a54570056151';
  $option->sort = -100;
  $option->label = 'Tilladt for alle';
  $option->value = '';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['39c56404-f046-0ad4-4d5b-de9d1d614677'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '3a7b312c-5082-8474-a9b3-b70a3a5035c0';
  $option->v_uuid = '8e7bda97-5430-9774-e54c-4d2b0005a06b';
  $option->sort = -93;
  $option->label = 'norske spillefilm';
  $option->value = '"norsk"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['3a7b312c-5082-8474-a9b3-b70a3a5035c0'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '3ab0660b-f523-4eee-bced-bdd0054916e5';
  $option->v_uuid = '3c0f6ff4-63f2-8a54-4500-6198904477ba';
  $option->sort = -89;
  $option->label = 'Xbox';
  $option->value = '"xbox"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['3ab0660b-f523-4eee-bced-bdd0054916e5'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '3ac29d85-70d4-4873-a354-794960e5d118';
  $option->v_uuid = '6e4d6c92-a9b4-4f53-830c-db8bb5ce9dae';
  $option->sort = -95;
  $option->label = 'mandskor';
  $option->value = 'dkcclterm.em="mandskor"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['3ac29d85-70d4-4873-a354-794960e5d118'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '3b148271-66a0-453e-9d20-ec974ddb7567';
  $option->v_uuid = '3c0f6ff4-63f2-8a54-4500-6198904477ba';
  $option->sort = -87;
  $option->label = 'Xbox One';
  $option->value = '"xbox one"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['3b148271-66a0-453e-9d20-ec974ddb7567'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '3b73e77a-12a0-1d84-8523-57ce326ef281';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = -82;
  $option->label = 'polsk';
  $option->value = 'term.language="pol"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['3b73e77a-12a0-1d84-8523-57ce326ef281'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '3ba4096a-04c6-4ad0-a54f-9aec40c6670c';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -65;
  $option->label = 'western';
  $option->value = '"westerns"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['3ba4096a-04c6-4ad0-a54f-9aec40c6670c'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '3bd90cc6-cd99-c434-2121-953316c7bc32';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -94;
  $option->label = 'biografiske film';
  $option->value = '"biografiske film"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['3bd90cc6-cd99-c434-2121-953316c7bc32'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '3be22425-6b3c-6c94-0df0-f9afa77f7877';
  $option->v_uuid = '6918cf0f-f206-d494-f9da-32aa0d945ab9';
  $option->sort = -98;
  $option->label = 'Fra 3 år';
  $option->value = '"for 3 år"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['3be22425-6b3c-6c94-0df0-f9afa77f7877'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '3c6bc3ed-54d9-27a4-410c-48e3070c8d83';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = 4;
  $option->label = '1911';
  $option->value = '"1911"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['3c6bc3ed-54d9-27a4-410c-48e3070c8d83'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '3d806cb8-2148-4d03-bc75-77cae81c6f8c';
  $option->v_uuid = 'db557731-87b3-4fd0-b09b-ef08bdfa4d5b';
  $option->sort = -99;
  $option->label = 'to blæsere';
  $option->value = 'dkcclterm.ok="78.432"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['3d806cb8-2148-4d03-bc75-77cae81c6f8c'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '3f2e9dd3-22a9-a7e4-6df8-bfe3514f0ed1';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -70;
  $option->label = '1985';
  $option->value = '"1985"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['3f2e9dd3-22a9-a7e4-6df8-bfe3514f0ed1'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '3f4f8622-e29f-3444-79c0-ae5951830826';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -72;
  $option->label = 'Jazz';
  $option->value = '"jazz"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['3f4f8622-e29f-3444-79c0-ae5951830826'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '3fd98de8-29af-c9d4-0576-0cd072d675d5';
  $option->v_uuid = '8e7bda97-5430-9774-e54c-4d2b0005a06b';
  $option->sort = -90;
  $option->label = 'russiske spillefilm';
  $option->value = '"russisk"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['3fd98de8-29af-c9d4-0576-0cd072d675d5'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '3fee7c7b-5292-4af3-b2d0-d32689e9772f';
  $option->v_uuid = 'f6e38171-96d3-4852-9dcc-f66cb3a6a13f';
  $option->sort = -94;
  $option->label = 'billedbøger';
  $option->value = 'term.type="billedbog"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['3fee7c7b-5292-4af3-b2d0-d32689e9772f'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '3ffa308b-9344-4969-a5b4-31cff8427b81';
  $option->v_uuid = '3c0f6ff4-63f2-8a54-4500-6198904477ba';
  $option->sort = -93;
  $option->label = 'PSP';
  $option->value = '"psp"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['3ffa308b-9344-4969-a5b4-31cff8427b81'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '401add77-651a-ee24-a5bc-340b15d31dab';
  $option->v_uuid = '8e7bda97-5430-9774-e54c-4d2b0005a06b';
  $option->sort = -97;
  $option->label = 'italienske spillefilm';
  $option->value = '"italiensk"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['401add77-651a-ee24-a5bc-340b15d31dab'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '40e11f9d-2c9a-f4a4-7960-0ef9a1ad10ed';
  $option->v_uuid = '8e7bda97-5430-9774-e54c-4d2b0005a06b';
  $option->sort = -94;
  $option->label = 'koreanske spillefilm';
  $option->value = '"koreansk"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['40e11f9d-2c9a-f4a4-7960-0ef9a1ad10ed'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '40fcea21-dfda-495a-b5d4-21e5666a2297';
  $option->v_uuid = 'db557731-87b3-4fd0-b09b-ef08bdfa4d5b';
  $option->sort = -92;
  $option->label = 'tre eller flere strygere';
  $option->value = 'dkcclterm.dk=78.421*';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['40fcea21-dfda-495a-b5d4-21e5666a2297'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '41a0ca6b-d9f2-6c94-b974-4c13a2dcfd11';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = -80;
  $option->label = 'rumænsk';
  $option->value = 'term.language="rum"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['41a0ca6b-d9f2-6c94-b974-4c13a2dcfd11'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '41c9cc64-b9f5-4a83-8038-75b5ac7d4af0';
  $option->v_uuid = '6e072028-31b8-4f7d-86cc-d24ce84024bd';
  $option->sort = 10;
  $option->label = 'Stort orkester med soloinstrument';
  $option->value = 'dkcclterm.dk=78.412*';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['41c9cc64-b9f5-4a83-8038-75b5ac7d4af0'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '423d2d19-4bdb-ab44-5927-dc27f3652f31';
  $option->v_uuid = 'e23b14bf-2112-19c4-41a7-64c531a76301';
  $option->sort = -83;
  $option->label = 'musik';
  $option->value = 'term.type="musik" or term.workType="music"';
  $option->expand = '604357bb-a73b-65c4-11d8-cf798b7eabe1';
  $option->is_disabled = FALSE;
  $export['423d2d19-4bdb-ab44-5927-dc27f3652f31'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '43562684-e584-48d4-be43-ea2ce40dad06';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -91;
  $option->label = 'dansk filmkanon';
  $option->value = '"dansk filmkanon"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['43562684-e584-48d4-be43-ea2ce40dad06'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '442ba4b3-fce3-4d77-a242-4dd2bf147b96';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -71;
  $option->label = 'Jazz - dansk';
  $option->value = '"jazz - dansk"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['442ba4b3-fce3-4d77-a242-4dd2bf147b96'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '454f4227-4d9f-3414-c90a-71a304f4dd31';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -61;
  $option->label = 'R&B';
  $option->value = '"R&B"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['454f4227-4d9f-3414-c90a-71a304f4dd31'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '47ecae57-cd12-d2c4-210f-c59826958d20';
  $option->v_uuid = '8e7bda97-5430-9774-e54c-4d2b0005a06b';
  $option->sort = -95;
  $option->label = 'kinesiske spillefilm';
  $option->value = '"kinesisk"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['47ecae57-cd12-d2c4-210f-c59826958d20'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '47f92a49-8a05-4e2e-91ea-770aac361df8';
  $option->v_uuid = '2dfa5ad4-131f-4fb8-881f-3607e4e1d4d1';
  $option->sort = -95;
  $option->label = 'sangskoler';
  $option->value = 'dkcclterm.em=("sangskoler" or "sangteknik")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['47f92a49-8a05-4e2e-91ea-770aac361df8'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '481f8701-65f3-433f-ad99-9e2634939275';
  $option->v_uuid = '2dfa5ad4-131f-4fb8-881f-3607e4e1d4d1';
  $option->sort = -94;
  $option->label = 'Music-Minus-One - karaoke';
  $option->value = 'dkcclterm.ma="mm"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['481f8701-65f3-433f-ad99-9e2634939275'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '48a3f024-8a67-4cd8-993c-b473b4509d39';
  $option->v_uuid = '40822d67-70f3-4a84-be5f-8228cde0de79';
  $option->sort = -90;
  $option->label = 'Rock';
  $option->value = '"rock"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['48a3f024-8a67-4cd8-993c-b473b4509d39'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '48e0627a-0fe9-2594-998f-b10d2535cf70';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -19;
  $option->label = '1934';
  $option->value = '"1934"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['48e0627a-0fe9-2594-998f-b10d2535cf70'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '4bc41f0e-0503-8554-d922-884a90b1678e';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -45;
  $option->label = '1960';
  $option->value = '"1960"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['4bc41f0e-0503-8554-d922-884a90b1678e'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '4c7d9190-bf59-f4b4-b56d-cfad7ebc705b';
  $option->v_uuid = 'd5bd0d72-c9ca-8e54-41a1-05d9b65cea77';
  $option->sort = -98;
  $option->label = 'Voksne';
  $option->value = '"voksenmaterialer"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['4c7d9190-bf59-f4b4-b56d-cfad7ebc705b'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '4ca8354d-2a97-e5f4-f1fa-80229c9b2ff4';
  $option->v_uuid = '4ed2c5d5-656b-be14-b55f-fbc7c1aff047';
  $option->sort = -92;
  $option->label = 'kinesisk';
  $option->value = 'term.language="chi"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['4ca8354d-2a97-e5f4-f1fa-80229c9b2ff4'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '4e2cd7cc-1a34-4c96-9e34-ef6c5febd59a';
  $option->v_uuid = '0cd9f79e-2d4c-466a-a2ce-121b00a41005';
  $option->sort = 10;
  $option->label = 'klaverpartiturer';
  $option->value = 'dkcclterm.ma="pp"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['4e2cd7cc-1a34-4c96-9e34-ef6c5febd59a'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '4ebd873c-5a7d-e614-4544-8f6b40c40f11';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -77;
  $option->label = 'For børn';
  $option->value = '"for børn"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['4ebd873c-5a7d-e614-4544-8f6b40c40f11'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '4f3830c1-9b44-4373-9518-135c4715efa0';
  $option->v_uuid = 'db557731-87b3-4fd0-b09b-ef08bdfa4d5b';
  $option->sort = -89;
  $option->label = 'to eller flere strygere og blæsere med klaver';
  $option->value = 'dkcclterm.dk=78.426*';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['4f3830c1-9b44-4373-9518-135c4715efa0'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '4fabac7e-b37b-2114-e5a9-00aeb4f46c0a';
  $option->v_uuid = 'e23b14bf-2112-19c4-41a7-64c531a76301';
  $option->sort = -100;
  $option->label = 'Alle typer materiale';
  $option->value = '';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['4fabac7e-b37b-2114-e5a9-00aeb4f46c0a'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '4fbde02a-5c8a-8b44-a189-a9961bf5d83a';
  $option->v_uuid = '3c0f6ff4-63f2-8a54-4500-6198904477ba';
  $option->sort = -98;
  $option->label = 'Playstation 2';
  $option->value = '"playstation 2"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['4fbde02a-5c8a-8b44-a189-a9961bf5d83a'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '4ff0b3fc-d0a1-c644-29a3-98eed5001e01';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = 6;
  $option->label = '1909';
  $option->value = '"1909"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['4ff0b3fc-d0a1-c644-29a3-98eed5001e01'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '50f987d4-fb53-4fc0-b6b3-4820be2e9da9';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -91;
  $option->label = 'Dance';
  $option->value = '"dance"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['50f987d4-fb53-4fc0-b6b3-4820be2e9da9'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '51a8db89-a998-4ab4-fd72-22b345e27d21';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -90;
  $option->label = 'danske fillmklassikere';
  $option->value = '"danske filmklassikere"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['51a8db89-a998-4ab4-fd72-22b345e27d21'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '523987c0-06d5-9994-812d-24328a1f1cba';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -88;
  $option->label = '2003';
  $option->value = '"2003"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['523987c0-06d5-9994-812d-24328a1f1cba'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '528af37a-2cf0-f9c4-e1ac-bcb3c81bcd61';
  $option->v_uuid = '12a1e89e-1274-a394-a12a-588d3abde6e9';
  $option->sort = -100;
  $option->label = 'Alle';
  $option->value = '';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['528af37a-2cf0-f9c4-e1ac-bcb3c81bcd61'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '532bd727-dbf1-4b81-bc91-0b1bb5ae3b54';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -80;
  $option->label = 'Fitness musik';
  $option->value = '"fitness musik"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['532bd727-dbf1-4b81-bc91-0b1bb5ae3b54'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '533b4694-b2c4-3fe4-a910-df0e1945ed67';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = -92;
  $option->label = 'fransk';
  $option->value = 'term.language=("fra" or "fre")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['533b4694-b2c4-3fe4-a910-df0e1945ed67'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '565280cd-c6a5-ebf4-99dc-9c4a0e02d898';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -78;
  $option->label = 'Folkemusik';
  $option->value = '"folkemusik"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['565280cd-c6a5-ebf4-99dc-9c4a0e02d898'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '57ab90ca-d98c-7354-d1d3-4287b916b6df';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = 15;
  $option->label = '1900';
  $option->value = '"1900"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['57ab90ca-d98c-7354-d1d3-4287b916b6df'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '57fece46-741d-a144-a18f-304820bc59bc';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -62;
  $option->label = '1977';
  $option->value = '"1977"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['57fece46-741d-a144-a18f-304820bc59bc'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '584f7d7f-791f-1474-a9c0-ec0b30964e42';
  $option->v_uuid = '1be4292d-14b0-f334-a1af-e1e349550f3c';
  $option->sort = -100;
  $option->label = 'Alle';
  $option->value = '';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['584f7d7f-791f-1474-a9c0-ec0b30964e42'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '59ea0d53-325c-d6f4-3954-01cd3a9d87aa';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -10;
  $option->label = '1925';
  $option->value = '"1925"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['59ea0d53-325c-d6f4-3954-01cd3a9d87aa'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '59ffac2c-e189-4e6d-b6bc-f1773f84aacf';
  $option->v_uuid = '479cc87e-3ff3-d124-5567-e03e00ef3169';
  $option->sort = 10;
  $option->label = 'e-avisartikler';
  $option->value = '(term.type="avisartikel" and term.accessType="online")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['59ffac2c-e189-4e6d-b6bc-f1773f84aacf'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '5a9e6dc5-c05f-7a44-0152-d4c1c59cc41b';
  $option->v_uuid = '8e7bda97-5430-9774-e54c-4d2b0005a06b';
  $option->sort = -91;
  $option->label = 'polske spillefilm';
  $option->value = '"polsk"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['5a9e6dc5-c05f-7a44-0152-d4c1c59cc41b'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '5ac6a51b-9f40-429e-bb9a-9a4c2e8e5ee4';
  $option->v_uuid = 'e1bf5870-5dec-51d4-a968-5a9c01b08d89';
  $option->sort = -93;
  $option->label = 'børnebøger';
  $option->value = 'dkcclterm.ma="bø" or dkcclterm.ka="b"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['5ac6a51b-9f40-429e-bb9a-9a4c2e8e5ee4'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '5b63b5fd-97e8-f254-3184-8926e6912ad5';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -50;
  $option->label = 'Klaverkoncerter';
  $option->value = '"klaverkoncerter"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['5b63b5fd-97e8-f254-3184-8926e6912ad5'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '5c28868d-dde5-48fb-af37-4da92b760f05';
  $option->v_uuid = '4ed2c5d5-656b-be14-b55f-fbc7c1aff047';
  $option->sort = -80;
  $option->label = 'alle';
  $option->value = 'facet.language=facet.language';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['5c28868d-dde5-48fb-af37-4da92b760f05'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '5cc6e82f-2e20-4ad3-8f0d-8482f0f33ed8';
  $option->v_uuid = 'db557731-87b3-4fd0-b09b-ef08bdfa4d5b';
  $option->sort = -96;
  $option->label = 'tre eller flere guitarer';
  $option->value = 'dkcclterm.dk=78.427* and dkcclterm.no="guitarer"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['5cc6e82f-2e20-4ad3-8f0d-8482f0f33ed8'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '5de14e11-f071-b804-9982-8f846a064768';
  $option->v_uuid = '12a1e89e-1274-a394-a12a-588d3abde6e9';
  $option->sort = -95;
  $option->label = 'russisk';
  $option->value = 'term.language="rus"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['5de14e11-f071-b804-9982-8f846a064768'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '5f242142-3055-49d4-dd7f-00c6caf78cbf';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = -89;
  $option->label = 'hebræisk';
  $option->value = 'term.language="heb"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['5f242142-3055-49d4-dd7f-00c6caf78cbf'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '5f5d6031-17e0-4025-9e53-796184b447f9';
  $option->v_uuid = 'db557731-87b3-4fd0-b09b-ef08bdfa4d5b';
  $option->sort = -94;
  $option->label = 'én stryger med klaver';
  $option->value = 'dkcclterm.dk=78.434*';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['5f5d6031-17e0-4025-9e53-796184b447f9'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '5faae28a-5305-f8d4-39e5-2e88c130c7c2';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -79;
  $option->label = 'komedier';
  $option->value = '"komedier"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['5faae28a-5305-f8d4-39e5-2e88c130c7c2'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '6038c9b8-3f37-6954-fdf3-5cc7ef263698';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = 3;
  $option->label = '1912';
  $option->value = '"1912"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['6038c9b8-3f37-6954-fdf3-5cc7ef263698'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '605aeaeb-f676-8fe4-e9d5-4f7579d76052';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -58;
  $option->label = '1973';
  $option->value = '"1973"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['605aeaeb-f676-8fe4-e9d5-4f7579d76052'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '6098c202-8a5a-4d83-8cbc-475d11e581ac';
  $option->v_uuid = '8e7bda97-5430-9774-e54c-4d2b0005a06b';
  $option->sort = -95;
  $option->label = 'indiske (hindi) spillefilm';
  $option->value = '"indisk"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['6098c202-8a5a-4d83-8cbc-475d11e581ac'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '60a8d35c-1823-94d4-59e0-9617bc880a54';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -34;
  $option->label = '1949';
  $option->value = '"1949"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['60a8d35c-1823-94d4-59e0-9617bc880a54'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '61bc3514-f377-409a-ba69-1f8d07ac8fe3';
  $option->v_uuid = '819ed112-ec85-8f64-2573-a5a88f7ac3d9';
  $option->sort = -96;
  $option->label = 'e-avisartikler';
  $option->value = 'term.type="avisartikel"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['61bc3514-f377-409a-ba69-1f8d07ac8fe3'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '639b37a6-fece-dcb4-21fe-262f34644f82';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -39;
  $option->label = '1954';
  $option->value = '"1954"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['639b37a6-fece-dcb4-21fe-262f34644f82'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '64748fa8-dc65-cc34-adec-86a2a69bb45e';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -87;
  $option->label = '2002';
  $option->value = '"2002"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['64748fa8-dc65-cc34-adec-86a2a69bb45e'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '64eeddd6-917d-e044-1194-d3b827e49d78';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -6;
  $option->label = '1921';
  $option->value = '"1921"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['64eeddd6-917d-e044-1194-d3b827e49d78'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '667b9ec6-30c1-bd64-9958-863de345ddce';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -88;
  $option->label = 'Danske viser';
  $option->value = '"danske viser"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['667b9ec6-30c1-bd64-9958-863de345ddce'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '66c0d95a-089e-4cfb-a9ca-b0983aef601d';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -37;
  $option->label = 'Klassisk musik 1950->';
  $option->value = '"klassisk musik 1950"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['66c0d95a-089e-4cfb-a9ca-b0983aef601d'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '67700ffd-7443-aea4-0d74-0a36f834097d';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -57;
  $option->label = 'Swing';
  $option->value = '"swing"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['67700ffd-7443-aea4-0d74-0a36f834097d'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '67cad172-efc3-4444-59a2-1590bb53bd83';
  $option->v_uuid = '8e7bda97-5430-9774-e54c-4d2b0005a06b';
  $option->sort = -85;
  $option->label = 'tyske spillefilm';
  $option->value = '"tysk"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['67cad172-efc3-4444-59a2-1590bb53bd83'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '68bd5a42-2f8b-e434-8141-97061d44eddb';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -7;
  $option->label = '1922';
  $option->value = '"1922"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['68bd5a42-2f8b-e434-8141-97061d44eddb'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '68c94958-d077-49e2-9847-9298e67cf6e7';
  $option->v_uuid = '2dfa5ad4-131f-4fb8-881f-3607e4e1d4d1';
  $option->sort = -92;
  $option->label = 'klaverskoler';
  $option->value = 'dkcclterm.em="klaverskoler"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['68c94958-d077-49e2-9847-9298e67cf6e7'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '68f7e7fe-d5dd-8434-997a-959e777dbe47';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -83;
  $option->label = '1998';
  $option->value = '"1998"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['68f7e7fe-d5dd-8434-997a-959e777dbe47'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '6978c229-80fd-48b4-35ea-8741d346c5cd';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -41;
  $option->label = '1956';
  $option->value = '"1956"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['6978c229-80fd-48b4-35ea-8741d346c5cd'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '6a64f578-db7e-4a70-929b-46ab16aaf89d';
  $option->v_uuid = 'db557731-87b3-4fd0-b09b-ef08bdfa4d5b';
  $option->sort = -97;
  $option->label = 'to eller flere blæsere med klaver';
  $option->value = 'dkcclterm.dk=78.425*';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['6a64f578-db7e-4a70-929b-46ab16aaf89d'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '6a988e81-8fea-8d64-1d06-a7159dd72e6e';
  $option->v_uuid = '1c0066cf-f6cb-8694-b102-24a394e912d5';
  $option->sort = -99;
  $option->label = 'romaner';
  $option->value = '"romaner"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['6a988e81-8fea-8d64-1d06-a7159dd72e6e'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '6bbc6142-d2c9-47ce-bc96-164167b500b6';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -93;
  $option->label = 'Chill';
  $option->value = '"chill"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['6bbc6142-d2c9-47ce-bc96-164167b500b6'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '6c48c5ac-7a71-1d64-2dd8-4e6477c505bc';
  $option->v_uuid = '12a1e89e-1274-a394-a12a-588d3abde6e9';
  $option->sort = -96;
  $option->label = 'fransk';
  $option->value = 'term.language=("fre" or "fra")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['6c48c5ac-7a71-1d64-2dd8-4e6477c505bc'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '6c8c225a-ac31-c1d4-cd06-ea3c8b9ed12c';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -30;
  $option->label = '1945';
  $option->value = '"1945"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['6c8c225a-ac31-c1d4-cd06-ea3c8b9ed12c'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '6cd16de7-c667-ee94-e149-b538e4063b8b';
  $option->v_uuid = '3021bc15-1305-10f4-2112-d08af39718bf';
  $option->sort = -50;
  $option->label = 'År før';
  $option->value = '"year_lt"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['6cd16de7-c667-ee94-e149-b538e4063b8b'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '6d38c576-ff8a-4d24-8937-5d3e4d954fc7';
  $option->v_uuid = '819ed112-ec85-8f64-2573-a5a88f7ac3d9';
  $option->sort = -100;
  $option->label = 'e-bøger';
  $option->value = 'term.type="ebog"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['6d38c576-ff8a-4d24-8937-5d3e4d954fc7'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '6da9b561-2952-4a10-b69d-3846b260af35';
  $option->v_uuid = '6e4d6c92-a9b4-4f53-830c-db8bb5ce9dae';
  $option->sort = -96;
  $option->label = 'kvindekor';
  $option->value = '(dkcclterm.em="kvindekor" or dkcclterm.em="damekor")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['6da9b561-2952-4a10-b69d-3846b260af35'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '6dd989df-1478-0ff4-a5a5-e518aa5dfb77';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = 12;
  $option->label = '1903';
  $option->value = '"1903"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['6dd989df-1478-0ff4-a5a5-e518aa5dfb77'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '6f4e965e-d180-4a53-bee3-ed7a61375397';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -43;
  $option->label = 'Kor';
  $option->value = '"kor"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['6f4e965e-d180-4a53-bee3-ed7a61375397'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '6fa651ad-4aa8-46f2-94a0-790663faf303';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -86;
  $option->label = 'Dubstep-bass';
  $option->value = '("dubstep-bass")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['6fa651ad-4aa8-46f2-94a0-790663faf303'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '6fb3a821-5cad-8654-8d6e-8a3d93ab11b5';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -75;
  $option->label = '1990';
  $option->value = '"1990"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['6fb3a821-5cad-8654-8d6e-8a3d93ab11b5'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '701db998-d8c5-1824-9d4d-f19d481cdde2';
  $option->v_uuid = '12a1e89e-1274-a394-a12a-588d3abde6e9';
  $option->sort = -97;
  $option->label = 'finsk';
  $option->value = 'term.language="fin"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['701db998-d8c5-1824-9d4d-f19d481cdde2'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '707209a6-5118-8af4-e5ef-6c76e84c61da';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -75;
  $option->label = 'kærlighed';
  $option->value = '"kærlighed"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['707209a6-5118-8af4-e5ef-6c76e84c61da'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '70b03352-39db-0824-29c4-50cfa976d5c0';
  $option->v_uuid = '3389bb76-ad3a-5c94-81de-2bfc154f8298';
  $option->sort = -88;
  $option->label = 'Fra 13 år';
  $option->value = '"Fra 13 år"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['70b03352-39db-0824-29c4-50cfa976d5c0'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '71594c39-5887-46a4-dd5a-f63665ba8f49';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -60;
  $option->label = '1975';
  $option->value = '"1975"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['71594c39-5887-46a4-dd5a-f63665ba8f49'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '7238ce8a-8e15-a3f4-090e-038755436af3';
  $option->v_uuid = 'fbeb5556-778a-ab64-2522-89eeef2793eb';
  $option->sort = -90;
  $option->label = 'shooters';
  $option->value = '"shooters"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['7238ce8a-8e15-a3f4-090e-038755436af3'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '7244e0ab-ff90-49e1-8b3e-497913a2deb1';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -56;
  $option->label = 'Synthpop';
  $option->value = '"synthpop"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['7244e0ab-ff90-49e1-8b3e-497913a2deb1'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '72e49d31-5a93-7b64-2133-f3cb22d04c9a';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -82;
  $option->label = 'Evergreen';
  $option->value = '"evergreen"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['72e49d31-5a93-7b64-2133-f3cb22d04c9a'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '73c4c721-838c-0f24-0107-0d4128301f5d';
  $option->v_uuid = 'fbeb5556-778a-ab64-2522-89eeef2793eb';
  $option->sort = -96;
  $option->label = 'hovedbrudsspil';
  $option->value = '"hovedbrudsspil" or "brætspil" or "quiz" or "puslespil"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['73c4c721-838c-0f24-0107-0d4128301f5d'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '7469d725-4e5f-8884-7150-bc8d653adf09';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -58;
  $option->label = 'popfilm';
  $option->value = '"popfilm"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['7469d725-4e5f-8884-7150-bc8d653adf09'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '7482e3a2-8946-4f30-9212-1f10841e533e';
  $option->v_uuid = '3c0f6ff4-63f2-8a54-4500-6198904477ba';
  $option->sort = -100;
  $option->label = 'Alle';
  $option->value = '';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['7482e3a2-8946-4f30-9212-1f10841e533e'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '74a3b752-7fe7-4f44-753b-5bfc468555a6';
  $option->v_uuid = '3c0f6ff4-63f2-8a54-4500-6198904477ba';
  $option->sort = -91;
  $option->label = 'Wii';
  $option->value = '"wii"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['74a3b752-7fe7-4f44-753b-5bfc468555a6'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '7500eb47-bedc-ad54-2da0-f3c6809128fc';
  $option->v_uuid = '4ed2c5d5-656b-be14-b55f-fbc7c1aff047';
  $option->sort = -85;
  $option->label = 'svensk';
  $option->value = 'term.language=("swe" or "sve")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['7500eb47-bedc-ad54-2da0-f3c6809128fc'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '750b3939-6e55-4e7b-bf08-54b8971890b1';
  $option->v_uuid = 'f6e38171-96d3-4852-9dcc-f66cb3a6a13f';
  $option->sort = -97;
  $option->label = 'e-bøger';
  $option->value = 'term.type="ebog"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['750b3939-6e55-4e7b-bf08-54b8971890b1'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '754e67ca-964c-bce4-119b-b950192d3cfa';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -60;
  $option->label = 'Salsa - afrocubansk musik';
  $option->value = '"salsa - afrocubansk musik"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['754e67ca-964c-bce4-119b-b950192d3cfa'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '7553fe18-ed47-4f1a-a725-eea0fecadc02';
  $option->v_uuid = '2dfa5ad4-131f-4fb8-881f-3607e4e1d4d1';
  $option->sort = -97;
  $option->label = 'sangnoder';
  $option->value = 'dkcclterm.ma="mu" and (dkcclterm.no="sangstemme?" or dkcclterm.ti="stemme?")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['7553fe18-ed47-4f1a-a725-eea0fecadc02'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '75df79fb-0802-4c55-ada2-bd88d7939eb3';
  $option->v_uuid = '40822d67-70f3-4a84-be5f-8228cde0de79';
  $option->sort = -97;
  $option->label = 'Folkemusik';
  $option->value = '("folkemusik" or "folkesange")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['75df79fb-0802-4c55-ada2-bd88d7939eb3'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '75e5df4f-aaa3-bc34-a96e-2937b653f4d4';
  $option->v_uuid = '4ed2c5d5-656b-be14-b55f-fbc7c1aff047';
  $option->sort = -89;
  $option->label = 'polsk';
  $option->value = 'term.language="pol"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['75e5df4f-aaa3-bc34-a96e-2937b653f4d4'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '7626c629-fb2a-1944-71a2-6fbb57093422';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -26;
  $option->label = '1941';
  $option->value = '"1941"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['7626c629-fb2a-1944-71a2-6fbb57093422'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '7725de77-b75d-aaa4-6906-3170a680ac7f';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = -93;
  $option->label = 'finsk';
  $option->value = 'term.language="fin"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['7725de77-b75d-aaa4-6906-3170a680ac7f'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '77bf813c-95e6-a2f4-91ed-145d7be6d490';
  $option->v_uuid = 'b056401f-4ff0-a654-55b8-835ad50af150';
  $option->sort = -96;
  $option->label = 'bånd';
  $option->value = 'term.type="lydbog" and term.type="bånd"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['77bf813c-95e6-a2f4-91ed-145d7be6d490'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '79bbb10e-a743-e4d4-7db6-0a1de3b0f967';
  $option->v_uuid = 'e1bf5870-5dec-51d4-a968-5a9c01b08d89';
  $option->sort = -96;
  $option->label = 'punktskrift';
  $option->value = 'term.type="punktskrift"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['79bbb10e-a743-e4d4-7db6-0a1de3b0f967'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '7b056400-add8-beb4-ad47-a04a758de6f9';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -11;
  $option->label = '1926';
  $option->value = '"1926"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['7b056400-add8-beb4-ad47-a04a758de6f9'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '7b0c9fa4-620e-0214-ed72-23c5bad62648';
  $option->v_uuid = '1150ebb6-8e38-27d4-b929-840f71d17137';
  $option->sort = 10;
  $option->label = 'fjhfjhgfjh';
  $option->value = '"nnj"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['7b0c9fa4-620e-0214-ed72-23c5bad62648'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '7b33e683-5d1e-64c4-3d80-54dfa937fb12';
  $option->v_uuid = '6918cf0f-f206-d494-f9da-32aa0d945ab9';
  $option->sort = -88;
  $option->label = 'Fra 13 år';
  $option->value = '"for 13 år"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['7b33e683-5d1e-64c4-3d80-54dfa937fb12'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '7b3e78d2-8581-4c68-9ed6-97d8b938d35b';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -38;
  $option->label = 'Renæssance ->1600';
  $option->value = '"renæssance 1600"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['7b3e78d2-8581-4c68-9ed6-97d8b938d35b'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '7c16db30-ece8-aff4-895b-a29c47adf457';
  $option->v_uuid = '819ed112-ec85-8f64-2573-a5a88f7ac3d9';
  $option->sort = -95;
  $option->label = 'e-musik';
  $option->value = 'term.type="musik"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['7c16db30-ece8-aff4-895b-a29c47adf457'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '7c1c2d1f-9bf2-40d5-8b41-c97848da6379';
  $option->v_uuid = '6e4d6c92-a9b4-4f53-830c-db8bb5ce9dae';
  $option->sort = -97;
  $option->label = 'drengekor';
  $option->value = 'dkcclterm.em="drengekor"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['7c1c2d1f-9bf2-40d5-8b41-c97848da6379'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '7cecf3c9-99ef-2774-2dc9-2af4c80204c4';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -21;
  $option->label = '1936';
  $option->value = '"1936"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['7cecf3c9-99ef-2774-2dc9-2af4c80204c4'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '7d9ddc21-de30-48d4-999e-28be1c16b3ec';
  $option->v_uuid = '819ed112-ec85-8f64-2573-a5a88f7ac3d9';
  $option->sort = -98;
  $option->label = 'e-dokumenter frit tilgængelige';
  $option->value = 'term.type="netdokument" and dkcclterm.ma="ou"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['7d9ddc21-de30-48d4-999e-28be1c16b3ec'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '7e5e55cf-039c-11e4-89e6-dee2f54d82b0';
  $option->v_uuid = '819ed112-ec85-8f64-2573-a5a88f7ac3d9';
  $option->sort = -94;
  $option->label = 'e-noder';
  $option->value = 'term.type="node"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['7e5e55cf-039c-11e4-89e6-dee2f54d82b0'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '7ec6cacf-dad8-49c0-8b49-259a8282a782';
  $option->v_uuid = '40822d67-70f3-4a84-be5f-8228cde0de79';
  $option->sort = -96;
  $option->label = 'For børn';
  $option->value = '("for børn" or "børnesange" or "børnemusik" or "børnekor" or "børnemusical*")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['7ec6cacf-dad8-49c0-8b49-259a8282a782'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '7fff6718-e551-4822-9261-7806c30dddb0';
  $option->v_uuid = '6e4d6c92-a9b4-4f53-830c-db8bb5ce9dae';
  $option->sort = -100;
  $option->label = 'a cappella';
  $option->value = 'dkcclterm.dk=78.65* and cappella* or dkcclphrase.lem="a cappella" or dkcclphrase.lem="a cappella kor"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['7fff6718-e551-4822-9261-7806c30dddb0'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '80487da9-f769-a984-99e2-f5894ffc6737';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -47;
  $option->label = '1962';
  $option->value = '"1962"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['80487da9-f769-a984-99e2-f5894ffc6737'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '804a40a6-8952-4230-b818-b47aead1bace';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -55;
  $option->label = 'Teenpop';
  $option->value = '"teenpop"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['804a40a6-8952-4230-b818-b47aead1bace'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '81178722-f2eb-9cf4-390c-c3a2d88dba34';
  $option->v_uuid = '1be4292d-14b0-f334-a1af-e1e349550f3c';
  $option->sort = 10;
  $option->label = 'Skønlitteratur';
  $option->value = '"fiktion"';
  $option->expand = '1c0066cf-f6cb-8694-b102-24a394e912d5';
  $option->is_disabled = FALSE;
  $export['81178722-f2eb-9cf4-390c-c3a2d88dba34'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '819af23c-2e96-1224-995a-d78405694ca8';
  $option->v_uuid = '3389bb76-ad3a-5c94-81de-2bfc154f8298';
  $option->sort = -99;
  $option->label = 'Fra 2 år';
  $option->value = '"Fra 2 år"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['819af23c-2e96-1224-995a-d78405694ca8'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '81c9a75b-2835-a334-3505-c96a56eb9cd0';
  $option->v_uuid = '6918cf0f-f206-d494-f9da-32aa0d945ab9';
  $option->sort = -91;
  $option->label = 'Fra 10 år';
  $option->value = '"for 10 år"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['81c9a75b-2835-a334-3505-c96a56eb9cd0'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '835f62f8-c2fc-0cf4-9537-6068ca5b93b1';
  $option->v_uuid = 'fbeb5556-778a-ab64-2522-89eeef2793eb';
  $option->sort = -100;
  $option->label = 'Alle';
  $option->value = '';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['835f62f8-c2fc-0cf4-9537-6068ca5b93b1'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '83a1904f-c4a7-4e77-aa92-29872cd53a9d';
  $option->v_uuid = 'e1bf5870-5dec-51d4-a968-5a9c01b08d89';
  $option->sort = -98;
  $option->label = 'stor skrift';
  $option->value = 'term.type=("bog stor skrift")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['83a1904f-c4a7-4e77-aa92-29872cd53a9d'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '84195ddc-e237-0664-1dcc-1c15ec465e2e';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -24;
  $option->label = '1939';
  $option->value = '"1939"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['84195ddc-e237-0664-1dcc-1c15ec465e2e'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '841ea809-d8f9-2e64-19f2-c8cdee0c20e3';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -13;
  $option->label = '1928';
  $option->value = '"1928"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['841ea809-d8f9-2e64-19f2-c8cdee0c20e3'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '8436cfef-8427-4882-9d65-a6576bec019a';
  $option->v_uuid = 'f6e38171-96d3-4852-9dcc-f66cb3a6a13f';
  $option->sort = -100;
  $option->label = 'trykte bøger ';
  $option->value = 'term.type="bog"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['8436cfef-8427-4882-9d65-a6576bec019a'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '84a44e93-93f1-b3b4-9da2-698a45b3c6a0';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -31;
  $option->label = '1946';
  $option->value = '"1946"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['84a44e93-93f1-b3b4-9da2-698a45b3c6a0'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '84c3527d-3d98-43e9-8140-0f75a6192bae';
  $option->v_uuid = 'e1bf5870-5dec-51d4-a968-5a9c01b08d89';
  $option->sort = -100;
  $option->label = 'Alle';
  $option->value = '';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['84c3527d-3d98-43e9-8140-0f75a6192bae'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '86efe6fa-d2fe-6734-6d6b-dcb9ca7cff7b';
  $option->v_uuid = '8e7bda97-5430-9774-e54c-4d2b0005a06b';
  $option->sort = -92;
  $option->label = 'pakistanske (urdu) spillefilm';
  $option->value = '"pakistansk"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['86efe6fa-d2fe-6734-6d6b-dcb9ca7cff7b'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '873bc1c0-3b80-8fb4-1964-78fba3047807';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -1;
  $option->label = '1916';
  $option->value = '"1916"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['873bc1c0-3b80-8fb4-1964-78fba3047807'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '876fa643-58b8-4951-8636-9804f7bf9796';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -59;
  $option->label = 'operette';
  $option->value = '"operetteklassikere"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['876fa643-58b8-4951-8636-9804f7bf9796'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '87f0cc87-f579-8034-d5a6-fe85c004b864';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -100;
  $option->label = 'Alle';
  $option->value = '';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['87f0cc87-f579-8034-d5a6-fe85c004b864'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '880be159-017e-0ce4-dd6c-a788c95f1bae';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = -69;
  $option->label = 'urdu';
  $option->value = 'term.language="urd"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['880be159-017e-0ce4-dd6c-a788c95f1bae'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '881ef1f5-ac13-9354-9106-a03112786a4d';
  $option->v_uuid = 'fbeb5556-778a-ab64-2522-89eeef2793eb';
  $option->sort = -95;
  $option->label = 'leg og lær';
  $option->value = '"leg og lær" or "leg"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['881ef1f5-ac13-9354-9106-a03112786a4d'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '88c3c543-9aef-4463-a408-4d168ca2e5b8';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -74;
  $option->label = 'novellefilm';
  $option->value = '"novellefilm"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['88c3c543-9aef-4463-a408-4d168ca2e5b8'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '8a23f15d-55b9-0654-55c1-8ac01c12741e';
  $option->v_uuid = 'e1bf5870-5dec-51d4-a968-5a9c01b08d89';
  $option->sort = -97;
  $option->label = 'lydbøger';
  $option->value = 'term.type="lydbog"';
  $option->expand = 'b056401f-4ff0-a654-55b8-835ad50af150';
  $option->is_disabled = FALSE;
  $export['8a23f15d-55b9-0654-55c1-8ac01c12741e'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '8b122891-e93c-28a4-39eb-94509fb94b0d';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -8;
  $option->label = '1923';
  $option->value = '"1923"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['8b122891-e93c-28a4-39eb-94509fb94b0d'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '8b442f0f-07a4-c124-1958-01cac9498a93';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -69;
  $option->label = 'socialrealisme';
  $option->value = '"socialrealisme"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['8b442f0f-07a4-c124-1958-01cac9498a93'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '8b4c3c07-93e3-d664-f599-ed93dd65a185';
  $option->v_uuid = '3389bb76-ad3a-5c94-81de-2bfc154f8298';
  $option->sort = -96;
  $option->label = 'Fra 5 år';
  $option->value = '"Fra 5 år"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['8b4c3c07-93e3-d664-f599-ed93dd65a185'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '8b8646ab-b23d-0574-25e9-9680d86025c7';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = -72;
  $option->label = 'tyrkisk';
  $option->value = 'term.language="tur"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['8b8646ab-b23d-0574-25e9-9680d86025c7'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '8bf9f673-1e8d-2014-894c-24f5d4b8df8b';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -89;
  $option->label = '2004';
  $option->value = '"2004"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['8bf9f673-1e8d-2014-894c-24f5d4b8df8b'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '8c366ab9-009f-e384-6dec-7a482ee2c092';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -82;
  $option->label = '1997';
  $option->value = '"1997"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['8c366ab9-009f-e384-6dec-7a482ee2c092'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '8dfb3100-4d1c-4589-be4d-858edbdfc0b6';
  $option->v_uuid = '40822d67-70f3-4a84-be5f-8228cde0de79';
  $option->sort = -94;
  $option->label = 'Klassisk';
  $option->value = '("renæssance" or "barok" or "klassik" or "wienerklassik" or "romantik" or "senromantik" or "impressionisme" or "neoklass*")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['8dfb3100-4d1c-4589-be4d-858edbdfc0b6'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '8dfc5958-129f-4844-cd06-68d3a6599635';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -88;
  $option->label = 'drama';
  $option->value = '"drama"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['8dfc5958-129f-4844-cd06-68d3a6599635'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '8eda79e6-8d41-1804-ed41-16fc659fc232';
  $option->v_uuid = '1c0066cf-f6cb-8694-b102-24a394e912d5';
  $option->sort = -98;
  $option->label = 'tegneserier';
  $option->value = '"tegneserier"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['8eda79e6-8d41-1804-ed41-16fc659fc232'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '8f1bda4f-b6a8-4f61-b38f-3b6aaa0411b6';
  $option->v_uuid = '6e072028-31b8-4f7d-86cc-d24ce84024bd';
  $option->sort = 10;
  $option->label = 'Stort orkester uden soloinstrument';
  $option->value = 'dkcclterm.dk=("78.41" or "78.411")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['8f1bda4f-b6a8-4f61-b38f-3b6aaa0411b6'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '90c833d5-e0f7-4d9a-b434-8d97e32c32f2';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -89;
  $option->label = 'Dansk pop/rock';
  $option->value = '"dansk pop/rock"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['90c833d5-e0f7-4d9a-b434-8d97e32c32f2'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '91381e4b-b3f9-0d84-1d43-bee4d0234e15';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = -74;
  $option->label = 'thai';
  $option->value = 'term.language="tha"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['91381e4b-b3f9-0d84-1d43-bee4d0234e15'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '91a976b7-5e74-1824-39f6-27f8f392279e';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = -99;
  $option->label = 'arabisk';
  $option->value = 'term.language="ara"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['91a976b7-5e74-1824-39f6-27f8f392279e'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '91e4cac4-276e-0de4-f15c-492d3a8ef578';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -56;
  $option->label = '1971';
  $option->value = '"1971"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['91e4cac4-276e-0de4-f15c-492d3a8ef578'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '91e552d5-40c6-d9c4-7d56-8967d10386ab';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -16;
  $option->label = '1931';
  $option->value = '"1931"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['91e552d5-40c6-d9c4-7d56-8967d10386ab'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '91ede760-aa7f-73b4-a593-2a3756fe1b84';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -68;
  $option->label = 'Musicals';
  $option->value = '"musicals"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['91ede760-aa7f-73b4-a593-2a3756fe1b84'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '9225aa47-9ab3-bc54-51fc-16614a652545';
  $option->v_uuid = '6918cf0f-f206-d494-f9da-32aa0d945ab9';
  $option->sort = -93;
  $option->label = 'Fra 8 år';
  $option->value = '"for 8 år"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['9225aa47-9ab3-bc54-51fc-16614a652545'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '92673cb9-d0f8-7d84-195b-14556c004621';
  $option->v_uuid = 'ceae1f55-323f-9774-250b-4b39f9b0bf91';
  $option->sort = -97;
  $option->label = 'Fra 12 år';
  $option->value = '"12+"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['92673cb9-d0f8-7d84-195b-14556c004621'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '92d882e0-03e9-6534-d951-4b15016e7ff6';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = -71;
  $option->label = 'tysk';
  $option->value = 'term.language=("ger" or "deu")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['92d882e0-03e9-6534-d951-4b15016e7ff6'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '92df261f-4aff-94b4-152d-7f51c0639c82';
  $option->v_uuid = '8c3bba75-59b9-6604-c597-e042f60e6a3b';
  $option->sort = 10;
  $option->label = 'stor skrift';
  $option->value = '"bog stor skrift"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['92df261f-4aff-94b4-152d-7f51c0639c82'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '93811015-9a63-ac34-d9c3-c33b5d8c4d92';
  $option->v_uuid = 'fbeb5556-778a-ab64-2522-89eeef2793eb';
  $option->sort = -97;
  $option->label = 'eventyrspil';
  $option->value = '"eventyrspil"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['93811015-9a63-ac34-d9c3-c33b5d8c4d92'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '93c3c006-33ef-5174-4d8f-1522208e4d4d';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -68;
  $option->label = 'tegnefilm';
  $option->value = '"tegnefilm"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['93c3c006-33ef-5174-4d8f-1522208e4d4d'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '949561ff-b017-42b2-aad2-38151a3a34a5';
  $option->v_uuid = '2dfa5ad4-131f-4fb8-881f-3607e4e1d4d1';
  $option->sort = -90;
  $option->label = 'noder for basguitar';
  $option->value = 'dkcclterm.ma="mu" and (dkcclterm.dk=("78.458" or "78.4581") or dkcclterm.em="basguitar")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['949561ff-b017-42b2-aad2-38151a3a34a5'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '9603f424-38cc-b004-b1a1-342cf9792cbe';
  $option->v_uuid = 'f79c6d0f-effe-6944-7951-211d70e904d7';
  $option->sort = -98;
  $option->label = 'film på nettet';
  $option->value = 'term.type="film" and term.accessType="online"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['9603f424-38cc-b004-b1a1-342cf9792cbe'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '961cd4ce-fd18-9634-b9c6-de35c62083f6';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -91;
  $option->label = '2006';
  $option->value = '"2006"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['961cd4ce-fd18-9634-b9c6-de35c62083f6'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '9737815b-cb2b-41d4-b74d-f31783b262c5';
  $option->v_uuid = '40822d67-70f3-4a84-be5f-8228cde0de79';
  $option->sort = -93;
  $option->label = 'Metal';
  $option->value = '("metal" or "heavy")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['9737815b-cb2b-41d4-b74d-f31783b262c5'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '974f0aff-f3e7-434d-bc57-151ab9100eac';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -84;
  $option->label = 'eventyr';
  $option->value = '"eventyr"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['974f0aff-f3e7-434d-bc57-151ab9100eac'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '98693da7-620c-a174-9d36-4f06a7ff9928';
  $option->v_uuid = '3389bb76-ad3a-5c94-81de-2bfc154f8298';
  $option->sort = -98;
  $option->label = 'Fra 3 år';
  $option->value = '"Fra 3 år"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['98693da7-620c-a174-9d36-4f06a7ff9928'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '98ac7f85-2930-4576-b855-af0a431f0a38';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -62;
  $option->label = 'Korfilm';
  $option->value = '"korfilm"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['98ac7f85-2930-4576-b855-af0a431f0a38'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '98d32763-d0e5-16f4-2566-d2a2d2abb170';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -67;
  $option->label = 'New age';
  $option->value = '"new age"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['98d32763-d0e5-16f4-2566-d2a2d2abb170'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '9947585b-b40d-f444-6d69-80402a0f0224';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = -95;
  $option->label = 'engelsk';
  $option->value = 'term.language="eng"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['9947585b-b40d-f444-6d69-80402a0f0224'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '99d0719a-0363-49b5-8cfa-cfee94190079';
  $option->v_uuid = '2dfa5ad4-131f-4fb8-881f-3607e4e1d4d1';
  $option->sort = -86;
  $option->label = 'noder for orkestre';
  $option->value = 'dkcclterm.dk=78.41*';
  $option->expand = '6e072028-31b8-4f7d-86cc-d24ce84024bd';
  $option->is_disabled = FALSE;
  $export['99d0719a-0363-49b5-8cfa-cfee94190079'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '9a3dbdc4-5582-fee4-351e-17511c851c62';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = 9;
  $option->label = '1906';
  $option->value = '"1906"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['9a3dbdc4-5582-fee4-351e-17511c851c62'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '9b33b447-3074-d254-71b3-f238446dd6c9';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -69;
  $option->label = '1984';
  $option->value = '"1984"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['9b33b447-3074-d254-71b3-f238446dd6c9'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '9b4d82fb-1e86-c774-61e2-0b139eab7ad8';
  $option->v_uuid = '8e7bda97-5430-9774-e54c-4d2b0005a06b';
  $option->sort = -96;
  $option->label = 'japanske spillefilm';
  $option->value = '"japansk"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['9b4d82fb-1e86-c774-61e2-0b139eab7ad8'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '9c334088-901d-4211-9a66-7f97b75b85e3';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -95;
  $option->label = 'animé';
  $option->value = '"anime"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['9c334088-901d-4211-9a66-7f97b75b85e3'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '9d8e4436-74ce-9704-8d42-3fcafbdb35eb';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -82;
  $option->label = 'folkekomedie';
  $option->value = '"folkekomedier"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['9d8e4436-74ce-9704-8d42-3fcafbdb35eb'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '9dc38888-1f28-6554-89ed-473d9e41f3d6';
  $option->v_uuid = '604357bb-a73b-65c4-11d8-cf798b7eabe1';
  $option->sort = -95;
  $option->label = 'grammofonplade';
  $option->value = 'term.type="grammofonplade"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['9dc38888-1f28-6554-89ed-473d9e41f3d6'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '9eefa885-93d9-eb94-15cd-6a26c1f646be';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = 2;
  $option->label = '1913';
  $option->value = '"1913"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['9eefa885-93d9-eb94-15cd-6a26c1f646be'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '9f708012-2c04-ea34-f1c0-fa76d96a6d66';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -42;
  $option->label = '1957';
  $option->value = '"1957"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['9f708012-2c04-ea34-f1c0-fa76d96a6d66'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = '9fdf9930-a827-e834-3d2f-14cbe44aed57';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -32;
  $option->label = '1947';
  $option->value = '"1947"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['9fdf9930-a827-e834-3d2f-14cbe44aed57'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'a05914d9-5d26-49e0-a177-6c88c1383211';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -83;
  $option->label = 'Emo';
  $option->value = '"emo"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['a05914d9-5d26-49e0-a177-6c88c1383211'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'a0dceb5c-cce4-4060-8214-41ef6e154231';
  $option->v_uuid = '2dfa5ad4-131f-4fb8-881f-3607e4e1d4d1';
  $option->sort = -87;
  $option->label = 'noder for mere end ét instrument';
  $option->value = 'dkcclterm.ma="mu" and dkcclterm.dk=(78.42* or 78.43*)';
  $option->expand = 'db557731-87b3-4fd0-b09b-ef08bdfa4d5b';
  $option->is_disabled = FALSE;
  $export['a0dceb5c-cce4-4060-8214-41ef6e154231'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'a180dbaa-b9db-7474-8107-156f3be0b527';
  $option->v_uuid = '8e7bda97-5430-9774-e54c-4d2b0005a06b';
  $option->sort = -87;
  $option->label = 'svenske spillefilm';
  $option->value = '"svensk"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['a180dbaa-b9db-7474-8107-156f3be0b527'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'a18d1a9c-435c-4153-b320-f534778db866';
  $option->v_uuid = '0cd9f79e-2d4c-466a-a2ce-121b00a41005';
  $option->sort = 10;
  $option->label = 'stemmer';
  $option->value = 'dkcclterm.ma=("pd" or "pl" or "so" or "st" or "sv")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['a18d1a9c-435c-4153-b320-f534778db866'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'a2369453-a8bf-4a3a-ad95-c146c164aa07';
  $option->v_uuid = '479cc87e-3ff3-d124-5567-e03e00ef3169';
  $option->sort = 10;
  $option->label = 'e-tidsskriftsartikler';
  $option->value = '(term.type="tidsskriftsartikel" and term.accessType="online")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['a2369453-a8bf-4a3a-ad95-c146c164aa07'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'a24fef0c-5b25-da24-810d-d927ec434b09';
  $option->v_uuid = 'fbeb5556-778a-ab64-2522-89eeef2793eb';
  $option->sort = -89;
  $option->label = 'simulationsspil';
  $option->value = '"simulationsspil" or "managerspil"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['a24fef0c-5b25-da24-810d-d927ec434b09'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'a295b637-e039-5bf4-ed7f-18b9d8ebfece';
  $option->v_uuid = 'fbeb5556-778a-ab64-2522-89eeef2793eb';
  $option->sort = -87;
  $option->label = 'strategispil';
  $option->value = '"strategispil"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['a295b637-e039-5bf4-ed7f-18b9d8ebfece'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'a33807f6-1028-c654-dd6a-cc71fe74ef48';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -86;
  $option->label = 'erotik';
  $option->value = '"erotik"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['a33807f6-1028-c654-dd6a-cc71fe74ef48'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'a34b968a-8fd2-4f96-b28f-88dbf2342b6f';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -98;
  $option->label = '60\'er soul';
  $option->value = '"60\'er soul"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['a34b968a-8fd2-4f96-b28f-88dbf2342b6f'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'a460c46b-af28-d1b4-a1c9-e923ae7e6017';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -46;
  $option->label = 'Opera';
  $option->value = '"opera"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['a460c46b-af28-d1b4-a1c9-e923ae7e6017'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'a5544d27-38fd-eb64-29a8-924ed0ff45ed';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -3;
  $option->label = '1918';
  $option->value = '"1918"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['a5544d27-38fd-eb64-29a8-924ed0ff45ed'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'a57935ad-6759-7364-654e-7a77fd3f46ee';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -49;
  $option->label = 'Violinkoncerter';
  $option->value = '"violinkoncerter"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['a57935ad-6759-7364-654e-7a77fd3f46ee'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'a5b66943-98cf-ddd4-a9f0-5e63ab4b6f9b';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -61;
  $option->label = 'musicalfilm';
  $option->value = '"musicalfilm"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['a5b66943-98cf-ddd4-a9f0-5e63ab4b6f9b'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'a5c66137-5a81-9474-65a4-64a784e39d5b';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -14;
  $option->label = '1929';
  $option->value = '"1929"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['a5c66137-5a81-9474-65a4-64a784e39d5b'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'a6020901-708b-2e04-c9f7-9d2936b2848d';
  $option->v_uuid = '479cc87e-3ff3-d124-5567-e03e00ef3169';
  $option->sort = -97;
  $option->label = 'e-artikler (alle)';
  $option->value = 'term.accessType="online"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['a6020901-708b-2e04-c9f7-9d2936b2848d'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'a6257666-c86e-f144-894e-4feddd43f726';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -89;
  $option->label = 'dokumentarfilm';
  $option->value = '"dokumentarfilm"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['a6257666-c86e-f144-894e-4feddd43f726'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'a62c3640-de7c-4b14-af13-7157b9ddbb02';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -85;
  $option->label = 'europæiske klassikere';
  $option->value = '"europæiske klassikere"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['a62c3640-de7c-4b14-af13-7157b9ddbb02'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'a795d499-64e0-6f14-81b0-ee859df959ad';
  $option->v_uuid = '6918cf0f-f206-d494-f9da-32aa0d945ab9';
  $option->sort = -100;
  $option->label = 'Biblioteket anbefaler';
  $option->value = '';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['a795d499-64e0-6f14-81b0-ee859df959ad'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'a863e932-0a8b-1214-4117-f6a6b658cf50';
  $option->v_uuid = '3389bb76-ad3a-5c94-81de-2bfc154f8298';
  $option->sort = -100;
  $option->label = 'Biblioteket anbefaler';
  $option->value = '';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['a863e932-0a8b-1214-4117-f6a6b658cf50'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'a8a12369-bdd5-6654-69d0-bebd0500542f';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -84;
  $option->label = 'Electronica';
  $option->value = '"electronica"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['a8a12369-bdd5-6654-69d0-bebd0500542f'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'a8c2773f-e491-43a1-866a-e2db6c0e14cc';
  $option->v_uuid = 'e1bf5870-5dec-51d4-a968-5a9c01b08d89';
  $option->sort = -99;
  $option->label = 'trykte bøger ';
  $option->value = 'term.type="bog"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['a8c2773f-e491-43a1-866a-e2db6c0e14cc'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'a961f2fc-d0d7-af14-2988-e53f804724c5';
  $option->v_uuid = 'e23b14bf-2112-19c4-41a7-64c531a76301';
  $option->sort = -98;
  $option->label = 'bøger';
  $option->value = 'term.workType="literature"';
  $option->expand = 'f6e38171-96d3-4852-9dcc-f66cb3a6a13f';
  $option->is_disabled = FALSE;
  $export['a961f2fc-d0d7-af14-2988-e53f804724c5'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'a9792dc0-b73e-9024-adf7-4edacb091c90';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -38;
  $option->label = '1953';
  $option->value = '"1953"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['a9792dc0-b73e-9024-adf7-4edacb091c90'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'aa1ae4e9-5bf3-19e4-e546-1c764aeb7363';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -74;
  $option->label = 'House ';
  $option->value = '"house"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['aa1ae4e9-5bf3-19e4-e546-1c764aeb7363'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'abf00406-3fb4-e7b4-2dea-7fc2cf913b31';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -86;
  $option->label = '2001';
  $option->value = '"2001"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['abf00406-3fb4-e7b4-2dea-7fc2cf913b31'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'abf72f58-f0f4-c624-05fb-c644183f4979';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = 1;
  $option->label = '1914';
  $option->value = '"1914"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['abf72f58-f0f4-c624-05fb-c644183f4979'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'ac2e6822-aed4-c7e4-3970-7ade71e61637';
  $option->v_uuid = '4ed2c5d5-656b-be14-b55f-fbc7c1aff047';
  $option->sort = -81;
  $option->label = 'urdu';
  $option->value = 'term.language="urd"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['ac2e6822-aed4-c7e4-3970-7ade71e61637'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'acccc8f3-ac9e-4cb2-9c15-82bcc3f42eaa';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = 10;
  $option->label = 'alle';
  $option->value = 'facet.language=facet.language';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['acccc8f3-ac9e-4cb2-9c15-82bcc3f42eaa'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'acce13e1-d768-8174-0dec-5d0ee485f01e';
  $option->v_uuid = '7b0919f2-915d-0484-6da0-a54570056151';
  $option->sort = -98;
  $option->label = 'Tilladt fra 11 år';
  $option->value = '"Tilladt for børn over 11 år"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['acce13e1-d768-8174-0dec-5d0ee485f01e'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'ad4b1005-6743-1674-691c-3e155b72d5e9';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -76;
  $option->label = '1991';
  $option->value = '"1991"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['ad4b1005-6743-1674-691c-3e155b72d5e9'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'ad6f8a16-9275-41fd-a206-236723fcce48';
  $option->v_uuid = 'f6e38171-96d3-4852-9dcc-f66cb3a6a13f';
  $option->sort = -98;
  $option->label = 'punktskrift';
  $option->value = 'term.type="punktskrift"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['ad6f8a16-9275-41fd-a206-236723fcce48'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'ad804fc3-4a37-49cf-82bf-0f263909927b';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -85;
  $option->label = 'Electro';
  $option->value = '"electro"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['ad804fc3-4a37-49cf-82bf-0f263909927b'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'adb3819a-daca-4a3b-9e3e-027492d5469f';
  $option->v_uuid = '2dfa5ad4-131f-4fb8-881f-3607e4e1d4d1';
  $option->sort = -91;
  $option->label = 'noder for guitar';
  $option->value = 'dkcclterm.ma="mu" and (dkcclterm.dk=("78.457" or "78.4571" or "78.437" or "78.427*") or dkcclterm.em="guitar")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['adb3819a-daca-4a3b-9e3e-027492d5469f'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'adb50128-d88d-3aa4-71d8-35523a330ec9';
  $option->v_uuid = '3389bb76-ad3a-5c94-81de-2bfc154f8298';
  $option->sort = -91;
  $option->label = 'Fra 10 år';
  $option->value = '"Fra 10 år"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['adb50128-d88d-3aa4-71d8-35523a330ec9'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'ae4c2f64-e1f9-7754-4948-902f02ddd150';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -85;
  $option->label = '2000';
  $option->value = '"2000"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['ae4c2f64-e1f9-7754-4948-902f02ddd150'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'ae8f6c82-72e4-53f4-6126-2904f7563408';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -58;
  $option->label = 'Soul';
  $option->value = '"soul"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['ae8f6c82-72e4-53f4-6126-2904f7563408'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'af10d043-4c89-5ef4-c15a-e04e5e2c82cd';
  $option->v_uuid = '6918cf0f-f206-d494-f9da-32aa0d945ab9';
  $option->sort = -86;
  $option->label = 'Fra 15 år';
  $option->value = '"for 15 år"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['af10d043-4c89-5ef4-c15a-e04e5e2c82cd'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'afabf934-cf42-9204-bd42-432092564006';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -72;
  $option->label = '1987';
  $option->value = '"1987"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['afabf934-cf42-9204-bd42-432092564006'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'b07250fa-3e30-61c4-5956-51ef022564a9';
  $option->v_uuid = '3c0f6ff4-63f2-8a54-4500-6198904477ba';
  $option->sort = -99;
  $option->label = 'pc-spil';
  $option->value = '"pc-spil"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['b07250fa-3e30-61c4-5956-51ef022564a9'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'b0d00e57-8eb0-7c84-31b9-8ab9828d2e16';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -52;
  $option->label = 'Klassiske symfonier';
  $option->value = '"klassiske symfonier"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['b0d00e57-8eb0-7c84-31b9-8ab9828d2e16'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'b0d0b825-be32-1b24-c14b-2b1a3064da2d';
  $option->v_uuid = '1be4292d-14b0-f334-a1af-e1e349550f3c';
  $option->sort = 10;
  $option->label = 'Faglitteratur';
  $option->value = '"nonfiktion"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['b0d0b825-be32-1b24-c14b-2b1a3064da2d'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'b193e4cd-5858-1b24-1d30-fed0016b543f';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -23;
  $option->label = '1938';
  $option->value = '"1938"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['b193e4cd-5858-1b24-1d30-fed0016b543f'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'b1cea512-2100-7854-d1a6-c74e53c923ae';
  $option->v_uuid = '4ed2c5d5-656b-be14-b55f-fbc7c1aff047';
  $option->sort = -87;
  $option->label = 'russisk';
  $option->value = 'term.language="rus"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['b1cea512-2100-7854-d1a6-c74e53c923ae'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'b1d09bde-480b-437a-9689-d4df58b5ebb8';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -45;
  $option->label = 'Operaarier';
  $option->value = '"operaarier"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['b1d09bde-480b-437a-9689-d4df58b5ebb8'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'b2d97282-5b5e-11e4-198f-178112fdfbea';
  $option->v_uuid = '8e7bda97-5430-9774-e54c-4d2b0005a06b';
  $option->sort = -88;
  $option->label = 'spanske og latinamerikanske spillefilm';
  $option->value = '"spansk"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['b2d97282-5b5e-11e4-198f-178112fdfbea'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'b3486c62-2bc3-7544-1196-26a387b6c0e1';
  $option->v_uuid = 'fbeb5556-778a-ab64-2522-89eeef2793eb';
  $option->sort = -88;
  $option->label = 'sportsspil';
  $option->value = '"sportsspil"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['b3486c62-2bc3-7544-1196-26a387b6c0e1'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'b34f8a5e-2c4e-3664-0128-434ec4777a9e';
  $option->v_uuid = '819ed112-ec85-8f64-2573-a5a88f7ac3d9';
  $option->sort = -97;
  $option->label = 'e-lydbøger';
  $option->value = 'term.type="lydbog"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['b34f8a5e-2c4e-3664-0128-434ec4777a9e'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'b39cabef-32ca-86d4-550e-80ca652b7e84';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -100;
  $option->label = 'Alle';
  $option->value = '';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['b39cabef-32ca-86d4-550e-80ca652b7e84'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'b402bba1-5e59-4cd9-a0d2-af74685baaad';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -99;
  $option->label = '60\'er rock';
  $option->value = '"60\'er rock"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['b402bba1-5e59-4cd9-a0d2-af74685baaad'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'b406746a-4f49-5f44-adac-3777b1d68cf3';
  $option->v_uuid = '12a1e89e-1274-a394-a12a-588d3abde6e9';
  $option->sort = -94;
  $option->label = 'italiensk';
  $option->value = 'term.language="ita"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['b406746a-4f49-5f44-adac-3777b1d68cf3'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'b4e9afa1-3fc3-07d4-41e0-e2ee3f6175c3';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = -84;
  $option->label = 'norsk';
  $option->value = 'term.language="nor"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['b4e9afa1-3fc3-07d4-41e0-e2ee3f6175c3'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'b573ba7c-3c55-c334-89cd-ac91504efd68';
  $option->v_uuid = '6918cf0f-f206-d494-f9da-32aa0d945ab9';
  $option->sort = -92;
  $option->label = 'Fra 9 år';
  $option->value = '"for 9 år"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['b573ba7c-3c55-c334-89cd-ac91504efd68'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'b5838439-2576-8d74-ad7b-9b1b4d9e1464';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -96;
  $option->label = '2011';
  $option->value = '"2011"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['b5838439-2576-8d74-ad7b-9b1b4d9e1464'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'b6cadeed-5e48-ef04-ad15-1c6f719013df';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -66;
  $option->label = 'Progressiv rock';
  $option->value = '"progressiv rock"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['b6cadeed-5e48-ef04-ad15-1c6f719013df'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'b716e371-671f-e364-2df6-bdc0220b1d65';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -77;
  $option->label = 'krimi';
  $option->value = '"krimi"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['b716e371-671f-e364-2df6-bdc0220b1d65'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'b75a1834-35b8-ee44-7d83-325fb337b20d';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = 0;
  $option->label = '1915';
  $option->value = '"1915"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['b75a1834-35b8-ee44-7d83-325fb337b20d'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'b8085e36-a519-6cf4-59e9-d8c015ab5569';
  $option->v_uuid = '12a1e89e-1274-a394-a12a-588d3abde6e9';
  $option->sort = -91;
  $option->label = 'svensk';
  $option->value = 'term.language=("swe" or "sve")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['b8085e36-a519-6cf4-59e9-d8c015ab5569'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'b9241a28-bd21-2354-e1e9-653722dd5ab1';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -67;
  $option->label = 'thriller';
  $option->value = '"thriller"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['b9241a28-bd21-2354-e1e9-653722dd5ab1'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'b94c3cbc-61c2-4f04-1525-27e7e85f05ea';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -78;
  $option->label = '1993';
  $option->value = '"1993"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['b94c3cbc-61c2-4f04-1525-27e7e85f05ea'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'b9d9542b-884b-46b6-8c56-f93baf9a671e';
  $option->v_uuid = '40822d67-70f3-4a84-be5f-8228cde0de79';
  $option->sort = -95;
  $option->label = 'Jazz';
  $option->value = '"jazz"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['b9d9542b-884b-46b6-8c56-f93baf9a671e'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'b9e532eb-5a2c-4f54-e115-606a174b5f7c';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = 13;
  $option->label = '1902';
  $option->value = '"1902"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['b9e532eb-5a2c-4f54-e115-606a174b5f7c'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'ba15d0ec-86ff-f754-69e7-12a652ae3a83';
  $option->v_uuid = '3389bb76-ad3a-5c94-81de-2bfc154f8298';
  $option->sort = -90;
  $option->label = 'Fra 11 år';
  $option->value = '"Fra 11 år"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['ba15d0ec-86ff-f754-69e7-12a652ae3a83'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'bb597965-709c-43eb-8431-f3ec368ddd68';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -62;
  $option->label = 'Rock\'n\'roll';
  $option->value = '"rock\'n\'roll"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['bb597965-709c-43eb-8431-f3ec368ddd68'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'bb9dafee-e196-439c-8d36-38d311d192cd';
  $option->v_uuid = 'db557731-87b3-4fd0-b09b-ef08bdfa4d5b';
  $option->sort = -98;
  $option->label = 'tre eller flere blæsere';
  $option->value = 'dkcclterm.dk=78.422*';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['bb9dafee-e196-439c-8d36-38d311d192cd'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'bc004777-0729-d974-c5c0-4ccf0b6881c2';
  $option->v_uuid = '3c0f6ff4-63f2-8a54-4500-6198904477ba';
  $option->sort = -95;
  $option->label = 'Nintendo DS';
  $option->value = '"nintendo ds"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['bc004777-0729-d974-c5c0-4ccf0b6881c2'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'bc0d7849-9216-5904-95d1-3ed519d163f9';
  $option->v_uuid = '4ed2c5d5-656b-be14-b55f-fbc7c1aff047';
  $option->sort = -82;
  $option->label = 'ungarsk';
  $option->value = 'term.language="ung"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['bc0d7849-9216-5904-95d1-3ed519d163f9'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'bc18d25c-00cc-6594-ad90-e38e22697efc';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -46;
  $option->label = '1961';
  $option->value = '"1961"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['bc18d25c-00cc-6594-ad90-e38e22697efc'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'bc3d4e0e-6da5-62a4-7926-41ef7e3f0f82';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -52;
  $option->label = '1967';
  $option->value = '"1967"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['bc3d4e0e-6da5-62a4-7926-41ef7e3f0f82'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'bc80c239-fe6d-4fe5-9254-84cba151648b';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -72;
  $option->label = 'politik og politikere';
  $option->value = '"politik og politikere"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['bc80c239-fe6d-4fe5-9254-84cba151648b'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'bd551fb5-e1b7-6b34-f9c4-699e0d11a206';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -51;
  $option->label = '1966';
  $option->value = '"1966"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['bd551fb5-e1b7-6b34-f9c4-699e0d11a206'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'bde43043-5498-4b53-83b4-2b5eccc2b82e';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -69;
  $option->label = 'Metal';
  $option->value = '"metal"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['bde43043-5498-4b53-83b4-2b5eccc2b82e'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'be868e4b-ccf5-3c84-5548-60aef49deeae';
  $option->v_uuid = 'e23b14bf-2112-19c4-41a7-64c531a76301';
  $option->sort = -87;
  $option->label = 'cd-rom - men ikke spil';
  $option->value = 'term.type="cd-rom"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['be868e4b-ccf5-3c84-5548-60aef49deeae'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'bee8ef28-bf7f-4ac4-4ddf-c0835d99c6b2';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -37;
  $option->label = '1952';
  $option->value = '"1952"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['bee8ef28-bf7f-4ac4-4ddf-c0835d99c6b2'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'bf053754-56a8-4754-751f-4383e9ee4714';
  $option->v_uuid = '4ed2c5d5-656b-be14-b55f-fbc7c1aff047';
  $option->sort = -100;
  $option->label = 'Alle';
  $option->value = '';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['bf053754-56a8-4754-751f-4383e9ee4714'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'bf34da08-c742-5a74-219b-cdb97867dc7b';
  $option->v_uuid = '7b0919f2-915d-0484-6da0-a54570056151';
  $option->sort = -97;
  $option->label = 'Tilladt fra 15 år';
  $option->value = '"Tilladt for børn over 15 år"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['bf34da08-c742-5a74-219b-cdb97867dc7b'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'bf793eba-5623-32a4-2d53-e3beb1d40bdf';
  $option->v_uuid = 'fbeb5556-778a-ab64-2522-89eeef2793eb';
  $option->sort = -92;
  $option->label = 'racerspil';
  $option->value = '"racerspil"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['bf793eba-5623-32a4-2d53-e3beb1d40bdf'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'c046291c-1669-4584-8995-eb8c951a9392';
  $option->v_uuid = '8e7bda97-5430-9774-e54c-4d2b0005a06b';
  $option->sort = -89;
  $option->label = 'serbiske spillefilm';
  $option->value = '"serbisk"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['c046291c-1669-4584-8995-eb8c951a9392'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'c1254cd1-3b2f-da34-750e-af4862402978';
  $option->v_uuid = '604357bb-a73b-65c4-11d8-cf798b7eabe1';
  $option->sort = -97;
  $option->label = 'dvd';
  $option->value = 'term.type="dvd"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['c1254cd1-3b2f-da34-750e-af4862402978'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'c1f171a4-4f5f-4194-6522-dcd248294e5e';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -71;
  $option->label = 'road movies';
  $option->value = '"road movies"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['c1f171a4-4f5f-4194-6522-dcd248294e5e'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'c27fef62-9e01-ec54-e185-775d04fcb050';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = -76;
  $option->label = 'spansk';
  $option->value = 'term.language=("spa" or "esl")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['c27fef62-9e01-ec54-e185-775d04fcb050'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'c305d70d-2803-d4f4-3d03-82161b29cfe8';
  $option->v_uuid = '819ed112-ec85-8f64-2573-a5a88f7ac3d9';
  $option->sort = -96;
  $option->label = 'e-lydbøger NOTA';
  $option->value = '(term.type="lydbog" and (dkcclterm.fl="nota" or dkcclterm.fl="blindebibliotek"))';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['c305d70d-2803-d4f4-3d03-82161b29cfe8'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'c344326f-e7fb-c8d4-4136-c2c71895b5a9';
  $option->v_uuid = '3c0f6ff4-63f2-8a54-4500-6198904477ba';
  $option->sort = -97;
  $option->label = 'Playstation 3';
  $option->value = '"playstation 3"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['c344326f-e7fb-c8d4-4136-c2c71895b5a9'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'c4462408-24db-4e3b-9e1a-a112d54e67b4';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -87;
  $option->label = 'Dansktop';
  $option->value = '"dansktop"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['c4462408-24db-4e3b-9e1a-a112d54e67b4'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'c4c656fc-f0ba-4c56-aaac-c91238f94552';
  $option->v_uuid = '40822d67-70f3-4a84-be5f-8228cde0de79';
  $option->sort = -92;
  $option->label = 'Opera';
  $option->value = '"opera*"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['c4c656fc-f0ba-4c56-aaac-c91238f94552'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'c60ce4e1-aca1-4bb4-c9a4-62139d9a2612';
  $option->v_uuid = '8e7bda97-5430-9774-e54c-4d2b0005a06b';
  $option->sort = -98;
  $option->label = 'franske spillefilm';
  $option->value = '"fransk"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['c60ce4e1-aca1-4bb4-c9a4-62139d9a2612'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'c681fbc7-1eac-4f39-aad5-e1938fc08a6c';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -99;
  $option->label = '2014';
  $option->value = '"2014"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['c681fbc7-1eac-4f39-aad5-e1938fc08a6c'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'c71b8854-ac72-cb94-659e-5a7944ebb7ef';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -68;
  $option->label = '1983';
  $option->value = '"1983"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['c71b8854-ac72-cb94-659e-5a7944ebb7ef'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'c73d9689-9353-1044-e9eb-c8b24da5a5a1';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -22;
  $option->label = '1937';
  $option->value = '"1937"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['c73d9689-9353-1044-e9eb-c8b24da5a5a1'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'c77767d1-cb8e-26d4-8d8f-6118a3426fce';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -93;
  $option->label = 'børnefilm';
  $option->value = '"børnefilm"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['c77767d1-cb8e-26d4-8d8f-6118a3426fce'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'c901dd30-d26f-19d4-21e7-8e9910574a5d';
  $option->v_uuid = '6918cf0f-f206-d494-f9da-32aa0d945ab9';
  $option->sort = -90;
  $option->label = 'Fra 11 år';
  $option->value = '"for 11 år"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['c901dd30-d26f-19d4-21e7-8e9910574a5d'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'ca3b0cba-e9c6-5ee4-45b1-e67097be1ef5';
  $option->v_uuid = '819ed112-ec85-8f64-2573-a5a88f7ac3d9';
  $option->sort = -99;
  $option->label = 'e-dokumenter';
  $option->value = 'term.type="netdokument"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['ca3b0cba-e9c6-5ee4-45b1-e67097be1ef5'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'ca5177cd-9784-68a4-7d84-9da83e4b757f';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -92;
  $option->label = 'Country';
  $option->value = '"country"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['ca5177cd-9784-68a4-7d84-9da83e4b757f'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'ca6790b9-1c58-a904-c170-e822ead44c13';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -42;
  $option->label = 'Solosang';
  $option->value = '"solosang"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['ca6790b9-1c58-a904-c170-e822ead44c13'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'cb07e197-7d9a-0c54-f5f2-7a2629747dae';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -61;
  $option->label = '1976';
  $option->value = '"1976"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['cb07e197-7d9a-0c54-f5f2-7a2629747dae'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'cb75ed6d-0a8d-e624-0d26-8929e18564d9';
  $option->v_uuid = '4ed2c5d5-656b-be14-b55f-fbc7c1aff047';
  $option->sort = -96;
  $option->label = 'fransk';
  $option->value = 'term.language=("fre" or "fra")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['cb75ed6d-0a8d-e624-0d26-8929e18564d9'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'cca03716-e90e-b224-ed12-220ef3968cd7';
  $option->v_uuid = 'ceae1f55-323f-9774-250b-4b39f9b0bf91';
  $option->sort = -96;
  $option->label = 'Fra 16 år';
  $option->value = '"16+"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['cca03716-e90e-b224-ed12-220ef3968cd7'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'ccf15476-4053-4ff1-85b4-bd5e70957dbb';
  $option->v_uuid = 'db557731-87b3-4fd0-b09b-ef08bdfa4d5b';
  $option->sort = -93;
  $option->label = 'to strygere';
  $option->value = 'dkcclterm.ok="78.431"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['ccf15476-4053-4ff1-85b4-bd5e70957dbb'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'cd8beb6b-d0c4-9a94-cd4a-980cd2435a3e';
  $option->v_uuid = 'ceae1f55-323f-9774-250b-4b39f9b0bf91';
  $option->sort = -100;
  $option->label = 'PEGI aldersmærkning';
  $option->value = '';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['cd8beb6b-d0c4-9a94-cd4a-980cd2435a3e'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'cdb0db97-9176-59f4-51be-6f471c501808';
  $option->v_uuid = '3389bb76-ad3a-5c94-81de-2bfc154f8298';
  $option->sort = -87;
  $option->label = 'Fra 14 år';
  $option->value = '"Fra 14 år"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['cdb0db97-9176-59f4-51be-6f471c501808'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'cdebad84-7064-6704-c93d-8118ef2410ea';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = 8;
  $option->label = '1907';
  $option->value = '"1907"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['cdebad84-7064-6704-c93d-8118ef2410ea'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'ce06eb6c-386c-41eb-84ea-f2a9aa0fbfa9';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -92;
  $option->label = 'computeranimerede film';
  $option->value = '"computeranimeret film"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['ce06eb6c-386c-41eb-84ea-f2a9aa0fbfa9'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'cf217bc8-b19e-4a33-beee-98ff300587f5';
  $option->v_uuid = '40822d67-70f3-4a84-be5f-8228cde0de79';
  $option->sort = -98;
  $option->label = 'Filmmusik';
  $option->value = '"film*"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['cf217bc8-b19e-4a33-beee-98ff300587f5'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'cfc0bacb-030f-96a4-4dc9-e418861cd1b4';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -59;
  $option->label = '1974';
  $option->value = '"1974"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['cfc0bacb-030f-96a4-4dc9-e418861cd1b4'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'd0054bdd-7436-6e74-498f-36665612de0a';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -97;
  $option->label = '2012';
  $option->value = '"2012"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['d0054bdd-7436-6e74-498f-36665612de0a'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'd06faef6-4fd2-04a4-6993-685bb252bd9f';
  $option->v_uuid = '479cc87e-3ff3-d124-5567-e03e00ef3169';
  $option->sort = -99;
  $option->label = 'avisartikler';
  $option->value = 'term.type="avisartikel"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['d06faef6-4fd2-04a4-6993-685bb252bd9f'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'd1848562-f163-3c54-ad56-9459beb52f7d';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -74;
  $option->label = '1989';
  $option->value = '"1989"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['d1848562-f163-3c54-ad56-9459beb52f7d'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'd26d349d-4a68-5994-498e-e15d2a8fba28';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -20;
  $option->label = '1935';
  $option->value = '"1935"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['d26d349d-4a68-5994-498e-e15d2a8fba28'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'd2bff843-77c0-2b24-318d-692c9d6305d6';
  $option->v_uuid = '4ed2c5d5-656b-be14-b55f-fbc7c1aff047';
  $option->sort = -86;
  $option->label = 'spansk';
  $option->value = 'term.language=("spa" or "esl")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['d2bff843-77c0-2b24-318d-692c9d6305d6'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'd2c5643e-8407-2944-e91d-310fd3b90134';
  $option->v_uuid = '604357bb-a73b-65c4-11d8-cf798b7eabe1';
  $option->sort = -94;
  $option->label = 'kassettebånd';
  $option->value = 'term.type="bånd"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['d2c5643e-8407-2944-e91d-310fd3b90134'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'd305a53d-a9c6-c734-0976-635cb20ad18a';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -64;
  $option->label = '1979';
  $option->value = '"1979"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['d305a53d-a9c6-c734-0976-635cb20ad18a'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'd394c9fa-6e58-86f4-095e-685f399f0ac1';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -2;
  $option->label = '1917';
  $option->value = '"1917"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['d394c9fa-6e58-86f4-095e-685f399f0ac1'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'd3b1b655-3c40-40e9-a578-0231f38789df';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -83;
  $option->label = 'farcer';
  $option->value = '"farcer"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['d3b1b655-3c40-40e9-a578-0231f38789df'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'd3f4f0e3-cdd7-b174-59b2-96afb155a93a';
  $option->v_uuid = '4ed2c5d5-656b-be14-b55f-fbc7c1aff047';
  $option->sort = -95;
  $option->label = 'hollandsk';
  $option->value = 'term.language=("dut" or "fle")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['d3f4f0e3-cdd7-b174-59b2-96afb155a93a'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'd4173a4c-3c03-2f94-dd81-56ff83728e1d';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -66;
  $option->label = 'tv-serie';
  $option->value = '"tv-serier"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['d4173a4c-3c03-2f94-dd81-56ff83728e1d'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'd4410e76-900e-4184-9546-7cdcaed93dbc';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -98;
  $option->label = '2013';
  $option->value = '"2013"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['d4410e76-900e-4184-9546-7cdcaed93dbc'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'd483e140-8fca-e2f4-f55c-21ec78823c46';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -35;
  $option->label = '1950';
  $option->value = '"1950"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['d483e140-8fca-e2f4-f55c-21ec78823c46'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'd49139c8-4318-79c4-4999-f1c224e7a118';
  $option->v_uuid = 'fbeb5556-778a-ab64-2522-89eeef2793eb';
  $option->sort = -91;
  $option->label = 'rollespil';
  $option->value = '"rollespil"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['d49139c8-4318-79c4-4999-f1c224e7a118'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'd4b47388-b49e-47a4-21e8-9eb8c7519140';
  $option->v_uuid = '3021bc15-1305-10f4-2112-d08af39718bf';
  $option->sort = 10;
  $option->label = 'År efter';
  $option->value = '"year_gt"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['d4b47388-b49e-47a4-21e8-9eb8c7519140'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'd54f4b58-0fe6-1914-2944-bca532f313ab';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -54;
  $option->label = '1969';
  $option->value = '"1969"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['d54f4b58-0fe6-1914-2944-bca532f313ab'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'd617e830-2cae-a074-4d03-63822deef1c8';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -79;
  $option->label = 'Folk';
  $option->value = '"folk"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['d617e830-2cae-a074-4d03-63822deef1c8'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'd691ab0b-2e38-dde4-f1e5-9daa55afefee';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -25;
  $option->label = '1940';
  $option->value = '"1940"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['d691ab0b-2e38-dde4-f1e5-9daa55afefee'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'd6ae951f-d849-6024-15c7-5942b651091f';
  $option->v_uuid = 'fbeb5556-778a-ab64-2522-89eeef2793eb';
  $option->sort = -99;
  $option->label = 'actionspil';
  $option->value = '"actionspil"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['d6ae951f-d849-6024-15c7-5942b651091f'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'd6d1e41a-a59d-4136-8b03-5a6aeb52c932';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -90;
  $option->label = 'Dancehall';
  $option->value = '"dancehall"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['d6d1e41a-a59d-4136-8b03-5a6aeb52c932'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'd6d472cc-889e-9c44-813b-1762db4053df';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = -79;
  $option->label = 'russisk';
  $option->value = 'term.language="rus"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['d6d472cc-889e-9c44-813b-1762db4053df'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'd758e756-a0d3-4b93-aa72-342d9cc19342';
  $option->v_uuid = 'f6e38171-96d3-4852-9dcc-f66cb3a6a13f';
  $option->sort = -99;
  $option->label = 'stor skrift';
  $option->value = 'term.type=("bog stor skrift")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['d758e756-a0d3-4b93-aa72-342d9cc19342'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'd79b0d76-4e44-49ff-a5da-aa382427f45b';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -76;
  $option->label = 'kunst og kunstnere';
  $option->value = '"kunst og kunstnere"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['d79b0d76-4e44-49ff-a5da-aa382427f45b'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'd7a82e8c-d8db-7d34-5d45-773837ceda52';
  $option->v_uuid = '4ed2c5d5-656b-be14-b55f-fbc7c1aff047';
  $option->sort = -93;
  $option->label = 'italiensk';
  $option->value = 'term.language="ita"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['d7a82e8c-d8db-7d34-5d45-773837ceda52'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'd7ce9337-5657-4ba3-a0aa-879cb9a54161';
  $option->v_uuid = 'db557731-87b3-4fd0-b09b-ef08bdfa4d5b';
  $option->sort = -100;
  $option->label = 'én blæser med klaver';
  $option->value = 'dkcclterm.dk=78.435*';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['d7ce9337-5657-4ba3-a0aa-879cb9a54161'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'd7faf5aa-f4fc-4f5c-845a-4a98cfac0fab';
  $option->v_uuid = 'f6e38171-96d3-4852-9dcc-f66cb3a6a13f';
  $option->sort = -96;
  $option->label = 'skolematerialer';
  $option->value = 'dkcclterm.ma="bs" or dkcclterm.ka="s"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['d7faf5aa-f4fc-4f5c-845a-4a98cfac0fab'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'd8b75efd-2948-7664-0dee-2709db4ed51a';
  $option->v_uuid = '3389bb76-ad3a-5c94-81de-2bfc154f8298';
  $option->sort = -94;
  $option->label = 'Fra 7 år';
  $option->value = '"Fra 7 år"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['d8b75efd-2948-7664-0dee-2709db4ed51a'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'd93646ef-5f1d-2494-dd2a-5cb5616161b0';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = -86;
  $option->label = 'italiensk';
  $option->value = 'term.language="ita"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['d93646ef-5f1d-2494-dd2a-5cb5616161b0'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'd993f485-cdf7-3324-199b-70c70b1ad8e2';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = 5;
  $option->label = '1910';
  $option->value = '"1910"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['d993f485-cdf7-3324-199b-70c70b1ad8e2'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'da0cb37a-44b1-6a44-21b2-78d8f38f986e';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -92;
  $option->label = '2007';
  $option->value = '"2007"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['da0cb37a-44b1-6a44-21b2-78d8f38f986e'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'daa6ccc2-6fb9-8434-016b-76182091b65a';
  $option->v_uuid = 'd5bd0d72-c9ca-8e54-41a1-05d9b65cea77';
  $option->sort = -100;
  $option->label = 'Alle';
  $option->value = '';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['daa6ccc2-6fb9-8434-016b-76182091b65a'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'dd1dd4d0-869e-5554-4d1a-5c2d16193d9f';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = -68;
  $option->label = 'vietnamesisk';
  $option->value = 'term.language="vie"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['dd1dd4d0-869e-5554-4d1a-5c2d16193d9f'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'dd426e9b-de57-a084-119c-6f21259ee71f';
  $option->v_uuid = 'e1bf5870-5dec-51d4-a968-5a9c01b08d89';
  $option->sort = -95;
  $option->label = 'e-bøger';
  $option->value = 'term.type="ebog"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['dd426e9b-de57-a084-119c-6f21259ee71f'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'dd713554-009a-f8a4-b53d-0d8d2be0d21a';
  $option->v_uuid = 'fbeb5556-778a-ab64-2522-89eeef2793eb';
  $option->sort = -94;
  $option->label = 'minispil';
  $option->value = '"minispil"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['dd713554-009a-f8a4-b53d-0d8d2be0d21a'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'de1ec428-a519-9384-95b4-926c8b511c87';
  $option->v_uuid = '4ed2c5d5-656b-be14-b55f-fbc7c1aff047';
  $option->sort = -84;
  $option->label = 'tyrkisk';
  $option->value = 'term.language="tur"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['de1ec428-a519-9384-95b4-926c8b511c87'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'de9e9d31-c4b4-6da4-35fc-b410171b0144';
  $option->v_uuid = 'e23b14bf-2112-19c4-41a7-64c531a76301';
  $option->sort = -90;
  $option->label = 'lydbøger';
  $option->value = 'term.type="lydbog"';
  $option->expand = 'b056401f-4ff0-a654-55b8-835ad50af150';
  $option->is_disabled = FALSE;
  $export['de9e9d31-c4b4-6da4-35fc-b410171b0144'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'dedf91bd-47b3-3964-1d60-9c9f31d41089';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -87;
  $option->label = 'dukkefilm';
  $option->value = '"dukkefilm"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['dedf91bd-47b3-3964-1d60-9c9f31d41089'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'dee76133-eebc-1384-7501-d9955a2b55da';
  $option->v_uuid = '604357bb-a73b-65c4-11d8-cf798b7eabe1';
  $option->sort = -99;
  $option->label = 'cd musik';
  $option->value = 'term.type="cd (musik)"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['dee76133-eebc-1384-7501-d9955a2b55da'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'df34e023-e678-47d4-6dba-a1ffae5f7111';
  $option->v_uuid = '3389bb76-ad3a-5c94-81de-2bfc154f8298';
  $option->sort = -92;
  $option->label = 'Fra 9 år';
  $option->value = '"Fra 9 år"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['df34e023-e678-47d4-6dba-a1ffae5f7111'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'dfb1e1c3-6a82-abd4-89ef-fbba9289fdce';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -94;
  $option->label = 'Blues';
  $option->value = '"blues"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['dfb1e1c3-6a82-abd4-89ef-fbba9289fdce'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'e0202101-6715-9ab4-9959-9b31ac45a183';
  $option->v_uuid = '12a1e89e-1274-a394-a12a-588d3abde6e9';
  $option->sort = -90;
  $option->label = 'tysk';
  $option->value = 'term.language=("ger" or "deu")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['e0202101-6715-9ab4-9959-9b31ac45a183'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'e08eb838-6d08-4e2a-b466-0493812129db';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -39;
  $option->label = 'Andre soloinstrumenter';
  $option->value = '"andre soloinstrumenter"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['e08eb838-6d08-4e2a-b466-0493812129db'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'e0f2ed1d-8b50-c164-9906-46c502c759ef';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -28;
  $option->label = '1943';
  $option->value = '"1943"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['e0f2ed1d-8b50-c164-9906-46c502c759ef'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'e11c22da-d437-6984-4155-3855b6b28a05';
  $option->v_uuid = '12a1e89e-1274-a394-a12a-588d3abde6e9';
  $option->sort = -99;
  $option->label = 'dansk';
  $option->value = 'term.language="dan"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['e11c22da-d437-6984-4155-3855b6b28a05'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'e12fa2f8-c2e6-ee54-29dc-5860e95905c5';
  $option->v_uuid = '3c0f6ff4-63f2-8a54-4500-6198904477ba';
  $option->sort = -90;
  $option->label = 'Wii U';
  $option->value = '"wii u"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['e12fa2f8-c2e6-ee54-29dc-5860e95905c5'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'e15443d9-2092-4e17-a922-bd6050ef4a72';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -51;
  $option->label = 'Cellokoncerter';
  $option->value = '"cellokoncerter"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['e15443d9-2092-4e17-a922-bd6050ef4a72'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'e1b4aa08-4fa3-62a4-e1e4-b5152e1bbb94';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = -98;
  $option->label = 'bosnisk';
  $option->value = 'term.language="bos"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['e1b4aa08-4fa3-62a4-e1e4-b5152e1bbb94'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'e20787ad-330c-9044-b16c-3968c2dd2af8';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = -83;
  $option->label = 'persisk';
  $option->value = 'term.language="per"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['e20787ad-330c-9044-b16c-3968c2dd2af8'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'e30efcf2-705c-29f4-d19c-ff620a8fa142';
  $option->v_uuid = 'd5bd0d72-c9ca-8e54-41a1-05d9b65cea77';
  $option->sort = -99;
  $option->label = 'Børn';
  $option->value = '"børnematerialer"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['e30efcf2-705c-29f4-d19c-ff620a8fa142'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'e34857a0-60fa-4e14-81be-3c010f5026db';
  $option->v_uuid = 'e1bf5870-5dec-51d4-a968-5a9c01b08d89';
  $option->sort = -92;
  $option->label = 'skolematerialer';
  $option->value = 'dkcclterm.ma="bs" or dkcclterm.ka="s"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['e34857a0-60fa-4e14-81be-3c010f5026db'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'e3dfc2eb-c2f1-fc04-2966-07fd5c8a2aa6';
  $option->v_uuid = 'ceae1f55-323f-9774-250b-4b39f9b0bf91';
  $option->sort = -95;
  $option->label = 'Fra 18 år';
  $option->value = '"18+"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['e3dfc2eb-c2f1-fc04-2966-07fd5c8a2aa6'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'e40d3af1-5b81-40b4-b15e-a65194d28f10';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -78;
  $option->label = 'krigsfilm';
  $option->value = '"krigsfilm"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['e40d3af1-5b81-40b4-b15e-a65194d28f10'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'e41da0d5-7d4a-f6f4-b55f-a7d286963ac0';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = -96;
  $option->label = 'dansk';
  $option->value = 'term.language="dan"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['e41da0d5-7d4a-f6f4-b55f-a7d286963ac0'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'e43b1e46-554b-b494-61ac-9ff35f97d543';
  $option->v_uuid = 'e23b14bf-2112-19c4-41a7-64c531a76301';
  $option->sort = -85;
  $option->label = 'film';
  $option->value = 'term.type="film" or term.workType="movie"';
  $option->expand = 'f79c6d0f-effe-6944-7951-211d70e904d7';
  $option->is_disabled = FALSE;
  $export['e43b1e46-554b-b494-61ac-9ff35f97d543'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'e43fa7cf-08e4-c834-29ac-3b3a0fc875be';
  $option->v_uuid = 'b056401f-4ff0-a654-55b8-835ad50af150';
  $option->sort = -99;
  $option->label = 'cd - audio';
  $option->value = 'term.type="lydbog" and term.type="cd"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['e43fa7cf-08e4-c834-29ac-3b3a0fc875be'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'e4af5948-b633-43da-99da-af02cfd6d8e0';
  $option->v_uuid = '8e7bda97-5430-9774-e54c-4d2b0005a06b';
  $option->sort = -99;
  $option->label = 'arabiske spillefilm';
  $option->value = '"arabisk"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['e4af5948-b633-43da-99da-af02cfd6d8e0'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'e4b8ed67-7bf4-48cb-80c0-127967c1201f';
  $option->v_uuid = '2dfa5ad4-131f-4fb8-881f-3607e4e1d4d1';
  $option->sort = -93;
  $option->label = 'noder for klaver';
  $option->value = 'dkcclterm.ma="mu" and (dkcclterm.dk=("78.53" or "78.531" or "78.55" or "78.551" or "78.56" or "78.561") or dkcclterm.em="klaver")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['e4b8ed67-7bf4-48cb-80c0-127967c1201f'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'e555a481-fd49-9694-0105-52d5c18bb961';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -53;
  $option->label = '1968';
  $option->value = '"1968"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['e555a481-fd49-9694-0105-52d5c18bb961'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'e5c230e1-770f-5aa4-65dd-c1db58c60c32';
  $option->v_uuid = 'e23b14bf-2112-19c4-41a7-64c531a76301';
  $option->sort = -97;
  $option->label = 'aviser og tidsskrifter';
  $option->value = 'term.type=("avis" or "tidsskrift")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['e5c230e1-770f-5aa4-65dd-c1db58c60c32'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'e7639d4a-0a74-461d-a9ba-e741f01f689f';
  $option->v_uuid = 'db557731-87b3-4fd0-b09b-ef08bdfa4d5b';
  $option->sort = -90;
  $option->label = 'én stryger og én blæser';
  $option->value = 'dkcclterm.dk="78.433"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['e7639d4a-0a74-461d-a9ba-e741f01f689f'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'e7bfc2ae-cc0d-2d04-7955-d82021a5f2e5';
  $option->v_uuid = '6918cf0f-f206-d494-f9da-32aa0d945ab9';
  $option->sort = -96;
  $option->label = 'Fra 5 år';
  $option->value = '"for 5 år"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['e7bfc2ae-cc0d-2d04-7955-d82021a5f2e5'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'e84335f1-6280-19b4-fdbd-be6cb5a780d0';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -95;
  $option->label = '2010';
  $option->value = '"2010"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['e84335f1-6280-19b4-fdbd-be6cb5a780d0'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'ea3f71aa-56ab-9d44-d10a-b8494727db4a';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = 7;
  $option->label = '1908';
  $option->value = '"1908"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['ea3f71aa-56ab-9d44-d10a-b8494727db4a'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'ecd70480-9e1a-e444-f158-2e200dcdf86e';
  $option->v_uuid = 'ceae1f55-323f-9774-250b-4b39f9b0bf91';
  $option->sort = -99;
  $option->label = 'Fra 3 år';
  $option->value = '"3+"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['ecd70480-9e1a-e444-f158-2e200dcdf86e'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'ecf90a3c-4ebc-eee4-05f6-e8d55bb4b068';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -12;
  $option->label = '1927';
  $option->value = '"1927"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['ecf90a3c-4ebc-eee4-05f6-e8d55bb4b068'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'ed56dda3-4c0b-8c64-65a9-01a041863113';
  $option->v_uuid = '8e7bda97-5430-9774-e54c-4d2b0005a06b';
  $option->sort = -86;
  $option->label = 'tyrkiske spillefilm';
  $option->value = '"tyrkisk"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['ed56dda3-4c0b-8c64-65a9-01a041863113'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'ee176ca0-7de0-09e4-f5ad-6a3cd43d156e';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = -87;
  $option->label = 'islandsk';
  $option->value = 'term.language=("ice" or "isl")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['ee176ca0-7de0-09e4-f5ad-6a3cd43d156e'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'ee309163-b72e-02a4-5d53-03271178944e';
  $option->v_uuid = '12a1e89e-1274-a394-a12a-588d3abde6e9';
  $option->sort = -93;
  $option->label = 'norsk';
  $option->value = 'term.language="nor"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['ee309163-b72e-02a4-5d53-03271178944e'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'eecf27fe-2015-a724-357d-3a6da53bc303';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = 10;
  $option->label = '1905';
  $option->value = '"1905"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['eecf27fe-2015-a724-357d-3a6da53bc303'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'eef9cd90-c843-4494-8574-d092a177fa43';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -98;
  $option->label = 'adventurefilm';
  $option->value = '"adventurefilm"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['eef9cd90-c843-4494-8574-d092a177fa43'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'ef468366-590a-94b4-e963-98c373ca4c6f';
  $option->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $option->sort = -90;
  $option->label = 'grønlandsk';
  $option->value = 'term.language="kal"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['ef468366-590a-94b4-e963-98c373ca4c6f'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'ef6ac49e-4c9a-476e-9d7c-902251c9bfb0';
  $option->v_uuid = '6e4d6c92-a9b4-4f53-830c-db8bb5ce9dae';
  $option->sort = -94;
  $option->label = 'pigekor';
  $option->value = 'dkcclterm.em="pigekor"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['ef6ac49e-4c9a-476e-9d7c-902251c9bfb0'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'efb629c5-89be-4f24-e17d-974356a844c8';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = 11;
  $option->label = '1904';
  $option->value = '"1904"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['efb629c5-89be-4f24-e17d-974356a844c8'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'f022a03b-34c6-8b84-bd12-5372c5cfab36';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -49;
  $option->label = '1964';
  $option->value = '"1964"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['f022a03b-34c6-8b84-bd12-5372c5cfab36'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'f03f34fb-4d58-d894-7190-75b10fc32917';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -59;
  $option->label = 'Singer/songwriter';
  $option->value = '"singer/songwriter"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['f03f34fb-4d58-d894-7190-75b10fc32917'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'f1c2841b-b00f-45b0-ba43-cc98eed95af9';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -47;
  $option->label = 'Kammermusik';
  $option->value = '"kammermusik"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['f1c2841b-b00f-45b0-ba43-cc98eed95af9'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'f21fdbac-0e6a-f794-9516-53c3708bcdc0';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -73;
  $option->label = '1988';
  $option->value = '"1988"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['f21fdbac-0e6a-f794-9516-53c3708bcdc0'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'f37e1d88-c442-81d4-8554-b21bec3858b9';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -81;
  $option->label = '1996';
  $option->value = '"1996"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['f37e1d88-c442-81d4-8554-b21bec3858b9'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'f3878cde-262b-4319-9a1c-680c773723de';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -40;
  $option->label = 'Klaver solo';
  $option->value = '"klaver solo"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['f3878cde-262b-4319-9a1c-680c773723de'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'f41b6a91-d6fd-4587-8f43-d3e084f5730c';
  $option->v_uuid = 'e1bf5870-5dec-51d4-a968-5a9c01b08d89';
  $option->sort = -94;
  $option->label = 'billedbøger';
  $option->value = 'term.type="billedbog"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['f41b6a91-d6fd-4587-8f43-d3e084f5730c'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'f6caec37-fc4a-498f-9527-0f23aa69acab';
  $option->v_uuid = 'f6e38171-96d3-4852-9dcc-f66cb3a6a13f';
  $option->sort = -95;
  $option->label = 'børnebøger';
  $option->value = 'dkcclterm.ma="bø" or dkcclterm.ka="b"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['f6caec37-fc4a-498f-9527-0f23aa69acab'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'f6ce0727-9bb5-de84-f5a7-3a210c9ef9de';
  $option->v_uuid = 'e23b14bf-2112-19c4-41a7-64c531a76301';
  $option->sort = -92;
  $option->label = 'e-materialer';
  $option->value = 'term.accessType="online"';
  $option->expand = '819ed112-ec85-8f64-2573-a5a88f7ac3d9';
  $option->is_disabled = FALSE;
  $export['f6ce0727-9bb5-de84-f5a7-3a210c9ef9de'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'f7753574-f55f-cbb4-253e-5f60c9be868a';
  $option->v_uuid = '4ed2c5d5-656b-be14-b55f-fbc7c1aff047';
  $option->sort = -83;
  $option->label = 'tysk';
  $option->value = 'term.language=("ger" or "deu")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['f7753574-f55f-cbb4-253e-5f60c9be868a'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'f798b11c-a17e-435e-a252-230f5374e053';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -63;
  $option->label = 'koncertfilm';
  $option->value = '"koncertfilm"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['f798b11c-a17e-435e-a252-230f5374e053'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'f7ad177a-625c-52c4-ad82-57b45445cfcc';
  $option->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $option->sort = -81;
  $option->label = 'gyserfilm';
  $option->value = '"gyserfilm"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['f7ad177a-625c-52c4-ad82-57b45445cfcc'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'f80a44aa-ddaa-4804-98cb-492bd0a48588';
  $option->v_uuid = '40822d67-70f3-4a84-be5f-8228cde0de79';
  $option->sort = -100;
  $option->label = 'Blues';
  $option->value = '"blues"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['f80a44aa-ddaa-4804-98cb-492bd0a48588'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'f8859abd-84a7-1e74-ad35-596e1731acf0';
  $option->v_uuid = 'b056401f-4ff0-a654-55b8-835ad50af150';
  $option->sort = -95;
  $option->label = 'fra NOTA';
  $option->value = 'term.type="lydbog" and (dkcclterm.fl="nota" or dkcclterm.fl="blindebibliotek")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['f8859abd-84a7-1e74-ad35-596e1731acf0'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'f8fa84bc-e82e-58c4-4d6f-a5575d51b05c';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -17;
  $option->label = '1932';
  $option->value = '"1932"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['f8fa84bc-e82e-58c4-4d6f-a5575d51b05c'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'f92de73b-8c43-aba4-edf1-52b336f0e1c2';
  $option->v_uuid = '12a1e89e-1274-a394-a12a-588d3abde6e9';
  $option->sort = -92;
  $option->label = 'spansk';
  $option->value = 'term.language="spa"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['f92de73b-8c43-aba4-edf1-52b336f0e1c2'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'fa52fa54-1334-7014-313e-17fce62dc6f1';
  $option->v_uuid = '604357bb-a73b-65c4-11d8-cf798b7eabe1';
  $option->sort = -96;
  $option->label = 'VHS';
  $option->value = 'term.type="video"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['fa52fa54-1334-7014-313e-17fce62dc6f1'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'fa74e669-6750-e144-d183-d9192df30082';
  $option->v_uuid = '6918cf0f-f206-d494-f9da-32aa0d945ab9';
  $option->sort = -97;
  $option->label = 'Fra 4 år';
  $option->value = '"for 4 år"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['fa74e669-6750-e144-d183-d9192df30082'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'fc0fd781-c3b8-8864-b527-b73bb75359af';
  $option->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $option->sort = -70;
  $option->label = 'Latin';
  $option->value = '"latin"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['fc0fd781-c3b8-8864-b527-b73bb75359af'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'fc2162ad-9939-f554-41ca-693e2b4f5cd4';
  $option->v_uuid = '6918cf0f-f206-d494-f9da-32aa0d945ab9';
  $option->sort = -95;
  $option->label = 'Fra 6 år';
  $option->value = '"for 6 år"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['fc2162ad-9939-f554-41ca-693e2b4f5cd4'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'fc46b70c-b228-448b-b8b9-4d3c831712b6';
  $option->v_uuid = 'e23b14bf-2112-19c4-41a7-64c531a76301';
  $option->sort = 0;
  $option->label = 'noder';
  $option->value = 'term.type="node" or term.workType="sheetmusic"';
  $option->expand = '2dfa5ad4-131f-4fb8-881f-3607e4e1d4d1';
  $option->is_disabled = FALSE;
  $export['fc46b70c-b228-448b-b8b9-4d3c831712b6'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'fd0e7f20-8ed0-f5d4-89f0-a7d23d48af33';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -90;
  $option->label = '2005';
  $option->value = '"2005"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['fd0e7f20-8ed0-f5d4-89f0-a7d23d48af33'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'fd68aaf3-4782-9aa4-e178-1ce51442eaa5';
  $option->v_uuid = '819ed112-ec85-8f64-2573-a5a88f7ac3d9';
  $option->sort = -92;
  $option->label = 'film på nettet';
  $option->value = 'term.type="film"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['fd68aaf3-4782-9aa4-e178-1ce51442eaa5'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'fd6b4c9d-6d2d-b414-d9e0-5c0bd1263e65';
  $option->v_uuid = '4ed2c5d5-656b-be14-b55f-fbc7c1aff047';
  $option->sort = -94;
  $option->label = 'islandsk';
  $option->value = 'term.language=("ice" or "isl")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['fd6b4c9d-6d2d-b414-d9e0-5c0bd1263e65'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'fe627c1e-f85d-5204-e151-019941198851';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -27;
  $option->label = '1942';
  $option->value = '"1942"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['fe627c1e-f85d-5204-e151-019941198851'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'fe67f3b8-c3aa-4bf4-edc3-42338575feda';
  $option->v_uuid = '3389bb76-ad3a-5c94-81de-2bfc154f8298';
  $option->sort = -93;
  $option->label = 'Fra 8 år';
  $option->value = '"Fra 8 år"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['fe67f3b8-c3aa-4bf4-edc3-42338575feda'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'fe863004-ece4-4344-8de5-8f9599315686';
  $option->v_uuid = '819ed112-ec85-8f64-2573-a5a88f7ac3d9';
  $option->sort = -99;
  $option->label = 'e-artikler';
  $option->value = 'term.type=("avisartikel" or "tidsskriftsartikel" or "artikel")';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['fe863004-ece4-4344-8de5-8f9599315686'] = $option;

  $option = new stdClass();
  $option->disabled = FALSE; /* Edit this to true to make a default option disabled initially */
  $option->api_version = 1;
  $option->o_uuid = 'ff464b3d-ef03-3854-e11e-574c70138f9c';
  $option->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $option->sort = -15;
  $option->label = '1930';
  $option->value = '"1930"';
  $option->expand = '0';
  $option->is_disabled = FALSE;
  $export['ff464b3d-ef03-3854-e11e-574c70138f9c'] = $option;

  return $export;
}

/**
 * Implements hook_default_bibdk_custom_search_value().
 */
function bibdk_custom_search_feature_default_bibdk_custom_search_value() {
  $export = array();

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = '0cd9f79e-2d4c-466a-a2ce-121b00a41005';
  $value->value_title = 'noder, partiturtyper';
  $value->sort = 10;
  $value->value_type = 'checkboxes';
  $value->search_code = '';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['0cd9f79e-2d4c-466a-a2ce-121b00a41005'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = '0d6ffeb4-4c40-1bc4-0d0b-4c2a8d2465b5';
  $value->value_title = 'fritekst';
  $value->sort = -100;
  $value->value_type = 'textfield';
  $value->search_code = 'term.default';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['0d6ffeb4-4c40-1bc4-0d0b-4c2a8d2465b5'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = '1150ebb6-8e38-27d4-b929-840f71d17137';
  $value->value_title = 'ophav';
  $value->sort = -98;
  $value->value_type = 'textfield';
  $value->search_code = 'term.creator';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['1150ebb6-8e38-27d4-b929-840f71d17137'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = '12a1e89e-1274-a394-a12a-588d3abde6e9';
  $value->value_title = 'artikler og net, sprog';
  $value->sort = -64;
  $value->value_type = 'checkboxes';
  $value->search_code = '';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['12a1e89e-1274-a394-a12a-588d3abde6e9'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = '1be4292d-14b0-f334-a1af-e1e349550f3c';
  $value->value_title = 'bøger, litterær form';
  $value->sort = -76;
  $value->value_type = 'checkboxes';
  $value->search_code = 'term.literaryForm';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['1be4292d-14b0-f334-a1af-e1e349550f3c'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = '1c0066cf-f6cb-8694-b102-24a394e912d5';
  $value->value_title = 'bøger, materialetype skønlitteratur';
  $value->sort = -74;
  $value->value_type = 'checkboxes';
  $value->search_code = '';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['1c0066cf-f6cb-8694-b102-24a394e912d5'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = '28c5d5d3-761a-5e24-fdef-88e47f135dd1';
  $value->value_title = 'film, personer';
  $value->sort = -52;
  $value->value_type = 'textfield';
  $value->search_code = 'term.creator';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['28c5d5d3-761a-5e24-fdef-88e47f135dd1'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = '2dfa5ad4-131f-4fb8-881f-3607e4e1d4d1';
  $value->value_title = 'noder, materialetyper';
  $value->sort = 10;
  $value->value_type = 'radios';
  $value->search_code = '';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['2dfa5ad4-131f-4fb8-881f-3607e4e1d4d1'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = '3021bc15-1305-10f4-2112-d08af39718bf';
  $value->value_title = 'år, operator';
  $value->sort = -92;
  $value->value_type = 'select';
  $value->search_code = 'year.op';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['3021bc15-1305-10f4-2112-d08af39718bf'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = '3389bb76-ad3a-5c94-81de-2bfc154f8298';
  $value->value_title = 'spil, bibliotekets aldersanbefaling';
  $value->sort = -56;
  $value->value_type = 'select';
  $value->search_code = 'phrase.audience';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['3389bb76-ad3a-5c94-81de-2bfc154f8298'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = '3c0f6ff4-63f2-8a54-4500-6198904477ba';
  $value->value_title = 'spil, platforme';
  $value->sort = -60;
  $value->value_type = 'checkboxes';
  $value->search_code = 'term.type';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['3c0f6ff4-63f2-8a54-4500-6198904477ba'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = '40822d67-70f3-4a84-be5f-8228cde0de79';
  $value->value_title = 'noder, genre';
  $value->sort = 10;
  $value->value_type = 'checkboxes';
  $value->search_code = 'dkcclterm.em';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['40822d67-70f3-4a84-be5f-8228cde0de79'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = '479cc87e-3ff3-d124-5567-e03e00ef3169';
  $value->value_title = 'artikler, materialetyper';
  $value->sort = -68;
  $value->value_type = 'checkboxes';
  $value->search_code = '';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['479cc87e-3ff3-d124-5567-e03e00ef3169'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = '4ed2c5d5-656b-be14-b55f-fbc7c1aff047';
  $value->value_title = 'bøger, sprog';
  $value->sort = -70;
  $value->value_type = 'checkboxes';
  $value->search_code = '';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['4ed2c5d5-656b-be14-b55f-fbc7c1aff047'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = '604357bb-a73b-65c4-11d8-cf798b7eabe1';
  $value->value_title = 'musik, materialetyper';
  $value->sort = -28;
  $value->value_type = 'checkboxes';
  $value->search_code = '';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['604357bb-a73b-65c4-11d8-cf798b7eabe1'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = '6918cf0f-f206-d494-f9da-32aa0d945ab9';
  $value->value_title = 'film, bibliotekets anbefaling';
  $value->sort = -44;
  $value->value_type = 'select';
  $value->search_code = 'phrase.subject';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['6918cf0f-f206-d494-f9da-32aa0d945ab9'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = '6c8f510b-73e1-9d84-410e-7750c6eb5581';
  $value->value_title = 'musikophav';
  $value->sort = -40;
  $value->value_type = 'textfield';
  $value->search_code = 'dkcclterm.po';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['6c8f510b-73e1-9d84-410e-7750c6eb5581'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = '6e072028-31b8-4f7d-86cc-d24ce84024bd';
  $value->value_title = 'noder, orkestermusik';
  $value->sort = 10;
  $value->value_type = 'radios';
  $value->search_code = '';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['6e072028-31b8-4f7d-86cc-d24ce84024bd'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = '6e4d6c92-a9b4-4f53-830c-db8bb5ce9dae';
  $value->value_title = 'noder, kortyper';
  $value->sort = 10;
  $value->value_type = 'radios';
  $value->search_code = '';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['6e4d6c92-a9b4-4f53-830c-db8bb5ce9dae'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = '70391b7f-5ccc-e634-657a-5a51ef315920';
  $value->value_title = 'musik, albumtitel';
  $value->sort = -32;
  $value->value_type = 'textfield';
  $value->search_code = 'dkcclterm.ht';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['70391b7f-5ccc-e634-657a-5a51ef315920'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = '7b0919f2-915d-0484-6da0-a54570056151';
  $value->value_title = 'film, tilladt for';
  $value->sort = -42;
  $value->value_type = 'select';
  $value->search_code = 'phrase.audience';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['7b0919f2-915d-0484-6da0-a54570056151'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = '819ed112-ec85-8f64-2573-a5a88f7ac3d9';
  $value->value_title = 'net, materialetyper';
  $value->sort = -62;
  $value->value_type = 'checkboxes';
  $value->search_code = '';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['819ed112-ec85-8f64-2573-a5a88f7ac3d9'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = '8c3bba75-59b9-6604-c597-e042f60e6a3b';
  $value->value_title = 'bøger, trykte';
  $value->sort = -80;
  $value->value_type = 'checkboxes';
  $value->search_code = 'term.type';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['8c3bba75-59b9-6604-c597-e042f60e6a3b'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = '8e7bda97-5430-9774-e54c-4d2b0005a06b';
  $value->value_title = 'film, nationalitet';
  $value->sort = -48;
  $value->value_type = 'checkboxes';
  $value->search_code = 'term.nationality';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['8e7bda97-5430-9774-e54c-4d2b0005a06b'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = '90655745-f61d-ac84-c54e-d7907d159271';
  $value->value_title = 'emne';
  $value->sort = -94;
  $value->value_type = 'textfield';
  $value->search_code = 'dkcclterm.em';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['90655745-f61d-ac84-c54e-d7907d159271'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = '95788824-6d40-ebd4-8912-ce2194f48d62';
  $value->value_title = 'alle materialer, sprog';
  $value->sort = -86;
  $value->value_type = 'checkboxes';
  $value->search_code = '';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['95788824-6d40-ebd4-8912-ce2194f48d62'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = 'a0ba26ef-efb3-1d14-f567-3ae2e36b3bd8';
  $value->value_title = 'musik, alle ophav1';
  $value->sort = -38;
  $value->value_type = 'textfield';
  $value->search_code = 'term.creator';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['a0ba26ef-efb3-1d14-f567-3ae2e36b3bd8'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = 'b056401f-4ff0-a654-55b8-835ad50af150';
  $value->value_title = 'bøger, lydbøger';
  $value->sort = -78;
  $value->value_type = 'checkboxes';
  $value->search_code = '';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['b056401f-4ff0-a654-55b8-835ad50af150'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = 'c065cb77-6f6d-42ff-b6e1-c70b48cab17b';
  $value->value_title = 'noder, hæftetitel';
  $value->sort = 10;
  $value->value_type = 'textfield';
  $value->search_code = 'dkcclterm.ht';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['c065cb77-6f6d-42ff-b6e1-c70b48cab17b'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = 'c62bd379-2702-ff84-6573-85e7627d257d';
  $value->value_title = 'musik, alle ophav2';
  $value->sort = -36;
  $value->value_type = 'textfield';
  $value->search_code = 'term.creator';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['c62bd379-2702-ff84-6573-85e7627d257d'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = 'ceae1f55-323f-9774-250b-4b39f9b0bf91';
  $value->value_title = 'spil, medierådets aldersanbefaling';
  $value->sort = -54;
  $value->value_type = 'select';
  $value->search_code = 'term.audience';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['ceae1f55-323f-9774-250b-4b39f9b0bf91'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = 'd119b2ef-6c7d-0c04-a105-f1628434e336';
  $value->value_title = 'titel';
  $value->sort = -96;
  $value->value_type = 'textfield';
  $value->search_code = 'dkcclterm.ti';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['d119b2ef-6c7d-0c04-a105-f1628434e336'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = 'd5bd0d72-c9ca-8e54-41a1-05d9b65cea77';
  $value->value_title = 'bøger, målgruppe';
  $value->sort = -72;
  $value->value_type = 'checkboxes';
  $value->search_code = 'term.category';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['d5bd0d72-c9ca-8e54-41a1-05d9b65cea77'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = 'da48923f-e5ba-5ef4-ad4f-c8aab6767a83';
  $value->value_title = 'år, årstal';
  $value->sort = -90;
  $value->value_type = 'select';
  $value->search_code = 'year.value';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['da48923f-e5ba-5ef4-ad4f-c8aab6767a83'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = 'db557731-87b3-4fd0-b09b-ef08bdfa4d5b';
  $value->value_title = 'noder, flere instrumenter';
  $value->sort = 10;
  $value->value_type = 'radios';
  $value->search_code = '';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['db557731-87b3-4fd0-b09b-ef08bdfa4d5b'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = 'dbbf0b74-887b-ea84-99e3-45edc72bdae7';
  $value->value_title = 'artikler, tidsskrift eller avis';
  $value->sort = -66;
  $value->value_type = 'textfield';
  $value->search_code = 'dkcclterm.vp';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['dbbf0b74-887b-ea84-99e3-45edc72bdae7'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = 'e1bf5870-5dec-51d4-a968-5a9c01b08d89';
  $value->value_title = 'bøger, materialetyper';
  $value->sort = -82;
  $value->value_type = 'checkboxes';
  $value->search_code = '';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['e1bf5870-5dec-51d4-a968-5a9c01b08d89'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = 'e23b14bf-2112-19c4-41a7-64c531a76301';
  $value->value_title = 'alle materialer, materialetyper alle';
  $value->sort = -88;
  $value->value_type = 'checkboxes';
  $value->search_code = '';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['e23b14bf-2112-19c4-41a7-64c531a76301'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = 'e4539af4-043f-49d4-ab45-379299f73085';
  $value->value_title = 'noder, alle titler';
  $value->sort = 10;
  $value->value_type = 'textfield';
  $value->search_code = 'dkcclterm.ti';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['e4539af4-043f-49d4-ab45-379299f73085'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = 'e8258795-3bbe-5e34-fda2-04a8b420d93f';
  $value->value_title = 'musikgenrer';
  $value->sort = -30;
  $value->value_type = 'checkboxes';
  $value->search_code = 'term.genre';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['e8258795-3bbe-5e34-fda2-04a8b420d93f'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = 'ea7df21c-2bab-3874-15a9-bc8e4afed0d9';
  $value->value_title = 'musik, alle titler';
  $value->sort = -34;
  $value->value_type = 'textfield';
  $value->search_code = 'term.title';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['ea7df21c-2bab-3874-15a9-bc8e4afed0d9'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = 'f6e38171-96d3-4852-9dcc-f66cb3a6a13f';
  $value->value_title = 'bøger, materialetyper, alle søgeside';
  $value->sort = -84;
  $value->value_type = 'checkboxes';
  $value->search_code = '';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['f6e38171-96d3-4852-9dcc-f66cb3a6a13f'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = 'f79c6d0f-effe-6944-7951-211d70e904d7';
  $value->value_title = 'film, materialetype';
  $value->sort = -46;
  $value->value_type = 'checkboxes';
  $value->search_code = '';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['f79c6d0f-effe-6944-7951-211d70e904d7'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = 'f81d0c50-5f4b-d1f4-f11f-c000c901c841';
  $value->value_title = 'film, genre';
  $value->sort = -50;
  $value->value_type = 'checkboxes';
  $value->search_code = 'term.genre';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['f81d0c50-5f4b-d1f4-f11f-c000c901c841'] = $value;

  $value = new stdClass();
  $value->disabled = FALSE; /* Edit this to true to make a default value disabled initially */
  $value->api_version = 1;
  $value->v_uuid = 'fbeb5556-778a-ab64-2522-89eeef2793eb';
  $value->value_title = 'spil, genre';
  $value->sort = -58;
  $value->value_type = 'checkboxes';
  $value->search_code = 'dkcclterm.em';
  $value->default_value = '';
  $value->expand = 0;
  $value->is_disabled = FALSE;
  $export['fbeb5556-778a-ab64-2522-89eeef2793eb'] = $value;

  return $export;
}
