<?php

/**
 * @file
 * Theme implementation for Bibliotek.dk search page menu.
 */

print theme('links', array(
  'links' => $pages,
  'attributes' => array('class' => array('nav--horizontal')),
));
