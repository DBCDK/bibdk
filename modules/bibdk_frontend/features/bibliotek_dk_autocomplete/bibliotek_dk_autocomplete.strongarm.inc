<?php

/**
 * @file
 * bibliotek_dk_autocomplete.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bibliotek_dk_autocomplete_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bibdk_autocomplete_rest_url';
  $strongarm->value = '';
  $export['bibdk_autocomplete_rest_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bibdk_autocomplete_settings';
  $strongarm->value = array(
    'agency' => '190101',
    'maxSuggestions' => '10',
    'maxTime' => '',
    'profile' => 'default',
    'highlight' => 1,
    'highlight.pre' => '<em>',
    'highlight.post' => '</em>',
  );
  $export['bibdk_autocomplete_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bibdk_autocomplete_var';
  $strongarm->value = array(
    '6c9427f4-c8da-e4b4-2550-4533080fc500' => array(
      'vars' => array(
        'search_block_form' => array(
          'autocomplete' => 0,
          'index' => 'creator',
          'operation' => 'suggest',
          'id' => 'input-fritekst',
        ),
        '70391b7f-5ccc-e634-657a-5a51ef315920' => array(
          'autocomplete' => 0,
          'index' => 'title',
          'operation' => 'suggest',
          'id' => 'input-albumtitel',
        ),
        '6c8f510b-73e1-9d84-410e-7750c6eb5581' => array(
          'autocomplete' => 0,
          'index' => 'creator',
          'operation' => 'suggest',
          'id' => 'input-hovedkunstner-komponist',
        ),
        'ea7df21c-2bab-3874-15a9-bc8e4afed0d9' => array(
          'autocomplete' => 0,
          'index' => 'title',
          'operation' => 'suggest',
          'id' => 'input-alle-titler',
        ),
        'a0ba26ef-efb3-1d14-f567-3ae2e36b3bd8' => array(
          'autocomplete' => 0,
          'index' => 'creator',
          'operation' => 'suggest',
          'id' => 'input-medvirkende',
        ),
        'c62bd379-2702-ff84-6573-85e7627d257d' => array(
          'autocomplete' => 0,
          'index' => 'creator',
          'operation' => 'suggest',
          'id' => 'input-medvirkende',
        ),
      ),
      'page_path' => 'bibdk_frontpage/musik',
    ),
    'eb1079e4-72ae-cb64-8542-0492a206b36e' => array(
      'vars' => array(
        'search_block_form' => array(
          'autocomplete' => 0,
          'index' => 'creator',
          'operation' => 'suggest',
          'id' => 'input-fritekst',
        ),
        'd119b2ef-6c7d-0c04-a105-f1628434e336' => array(
          'autocomplete' => 0,
          'index' => 'title',
          'operation' => 'suggest',
          'id' => 'input-filmens-titel',
        ),
        '28c5d5d3-761a-5e24-fdef-88e47f135dd1' => array(
          'autocomplete' => 0,
          'index' => 'creator',
          'operation' => 'suggest',
          'id' => 'input-personer',
        ),
      ),
      'page_path' => 'bibdk_frontpage/film',
    ),
    'b29c03e2-f2a9-9504-f97f-2cb529a0dad3' => array(
      'vars' => array(
        'search_block_form' => array(
          'autocomplete' => 0,
          'index' => 'creator',
          'operation' => 'suggest',
          'id' => 'input-fritekst',
        ),
        '1150ebb6-8e38-27d4-b929-840f71d17137' => array(
          'autocomplete' => 0,
          'index' => 'creator',
          'operation' => 'suggest',
          'id' => 'input-forfatter',
        ),
        'd119b2ef-6c7d-0c04-a105-f1628434e336' => array(
          'autocomplete' => 0,
          'index' => 'title',
          'operation' => 'suggest',
          'id' => 'input-titel',
        ),
        '90655745-f61d-ac84-c54e-d7907d159271' => array(
          'autocomplete' => 0,
          'index' => 'subject',
          'operation' => 'suggest',
          'id' => 'input-emne',
        ),
      ),
      'page_path' => 'bibdk_frontpage/bog',
    ),
    'd3099a71-b1b6-f5c4-4170-6b8593ad446b' => array(
      'vars' => array(
        'search_block_form' => array(
          'autocomplete' => 1,
          'index' => 'all',
          'operation' => 'suggest',
          'id' => 'input-fritekst',
        ),
        '1150ebb6-8e38-27d4-b929-840f71d17137' => array(
          'autocomplete' => 1,
          'index' => 'creator',
          'operation' => 'suggest',
          'id' => 'input-forfatter',
        ),
        'd119b2ef-6c7d-0c04-a105-f1628434e336' => array(
          'autocomplete' => 1,
          'index' => 'title',
          'operation' => 'suggest',
          'id' => 'input-titel',
        ),
        '90655745-f61d-ac84-c54e-d7907d159271' => array(
          'autocomplete' => 1,
          'index' => 'subject',
          'operation' => 'suggest',
          'id' => 'input-emne',
        ),
      ),
      'page_path' => 'bibdk_frontpage',
    ),
    '535c37b7-2bd4-7254-09f6-1b1285ac5761' => array(
      'vars' => array(
        'search_block_form' => array(
          'autocomplete' => 0,
          'index' => 'creator',
          'operation' => 'suggest',
          'id' => 'input-fritekst',
        ),
        'dbbf0b74-887b-ea84-99e3-45edc72bdae7' => array(
          'autocomplete' => 0,
          'index' => 'creator',
          'operation' => 'suggest',
          'id' => 'input-tidsskrift-eller-avis',
        ),
        'd119b2ef-6c7d-0c04-a105-f1628434e336' => array(
          'autocomplete' => 0,
          'index' => 'title',
          'operation' => 'suggest',
          'id' => 'input-artikel-titelord',
        ),
        '1150ebb6-8e38-27d4-b929-840f71d17137' => array(
          'autocomplete' => 0,
          'index' => 'creator',
          'operation' => 'suggest',
          'id' => 'input-artiklens-forfatter',
        ),
        '90655745-f61d-ac84-c54e-d7907d159271' => array(
          'autocomplete' => 0,
          'index' => 'subject',
          'operation' => 'suggest',
          'id' => 'input-artiklens-emne',
        ),
      ),
      'page_path' => 'bibdk_frontpage/artikel',
    ),
    '28226dd7-3165-49d8-a8e1-f9f82a44f418' => array(
      'vars' => array(
        'search_block_form' => array(
          'autocomplete' => 0,
          'index' => 'creator',
          'operation' => 'suggest',
          'id' => 'input-fritekst',
        ),
        'c065cb77-6f6d-42ff-b6e1-c70b48cab17b' => array(
          'autocomplete' => 0,
          'index' => 'title',
          'operation' => 'suggest',
          'id' => 'input-titel-p-nodehfte',
        ),
        '1150ebb6-8e38-27d4-b929-840f71d17137' => array(
          'autocomplete' => 0,
          'index' => 'creator',
          'operation' => 'suggest',
          'id' => 'input-komponist-eller-gruppe',
        ),
        'e4539af4-043f-49d4-ab45-379299f73085' => array(
          'autocomplete' => 0,
          'index' => 'title',
          'operation' => 'suggest',
          'id' => 'input-titel-p-sang-eller-musikstykke',
        ),
      ),
      'page_path' => 'bibdk_frontpage/noder',
    ),
    'f8e34d18-9d09-4c44-8592-99d4c43c7e79' => array(
      'vars' => array(
        'search_block_form' => array(
          'autocomplete' => 0,
          'index' => 'creator',
          'operation' => 'suggest',
          'id' => 'input-fritekst',
        ),
        '1150ebb6-8e38-27d4-b929-840f71d17137' => array(
          'autocomplete' => 0,
          'index' => 'creator',
          'operation' => 'suggest',
          'id' => 'input-forfatter-eller-udgiver',
        ),
        'd119b2ef-6c7d-0c04-a105-f1628434e336' => array(
          'autocomplete' => 0,
          'index' => 'title',
          'operation' => 'suggest',
          'id' => 'input-titel',
        ),
        '90655745-f61d-ac84-c54e-d7907d159271' => array(
          'autocomplete' => 0,
          'index' => 'subject',
          'operation' => 'suggest',
          'id' => 'input-emne',
        ),
      ),
      'page_path' => 'bibdk_frontpage/net',
    ),
  );
  $export['bibdk_autocomplete_var'] = $strongarm;

  return $export;
}
