<?php

  $elements['#text'] = '
    <span class="icon icon-left icon-lightgrey-rightarrow">&nbsp;</span>
    <span>' . $elements['#text'] . '</span>';

  $elements['#options']['attributes']['class'][] = 'text-small';
  $elements['#options']['attributes']['class'][] = 'bibdk-popup-link';
  $elements['#options']['attributes']['data-rel'][] = 'backcoverpdf';

  echo l(
    $elements['#text'],
    $elements['#path'],
    $elements['#options']
  );
