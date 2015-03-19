<?php

echo drupal_render_children($form);

/*
TO DO: render form as a table, in order to have a "sticky" submit button

  $header = array();
  foreach (element_children($form) as $key) {
    $row = array();
    if ( $form[$key]['#type'] == 'container' ) {
      foreach ( element_children($form[$key]) as $row_key ) {
        $row[] = array('data' => drupal_render_children($form[$key][$row_key]));
      }
    }
    if ( !empty($row) ) {
      $rows[] = $row;
    }
  }

  $output = theme('table', array('header' => $header, 'rows' => $rows));
  $output .= drupal_render_children($form);

  echo $output;
*/


?>
