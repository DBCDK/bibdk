<?php

  $elements['#text'] = '
    <span class="icon icon-left icon-lightgrey-rightarrow">&nbsp;</span>
    <span>' . $elements['#text'] . '</span>';

  $elements['#options']['attributes']['class'][] = 'text-small';
  $elements['#options']['attributes']['class'][] = 'text-darkgrey';
  $elements['#options']['attributes']['class'][] = 'bibdk-popup-link';

  $elements['#options']['attributes']['data-rel'][] = 'backcoverpdf';

  // $elements['#options']['attributes']['rel'] = 'lightframe[|width:680px; height:900px; scrolling: auto;]';

  echo l(
    $elements['#text'],
    $elements['#path'],
    $elements['#options']
  );
