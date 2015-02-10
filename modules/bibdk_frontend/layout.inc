<?php

$layout = new stdClass;
$layout->disabled = FALSE; /* Edit this to true to make a default layout disabled initially */
$layout->api_version = 1;
$layout->name = 'bibdk_frontpage_layout';
$layout->admin_title = 'bibdk_frontpage_layout';
$layout->admin_description = '';
$layout->category = 'bibliotek.dk';
$layout->plugin = 'flexible';
$layout->settings = array(
  'items' => array(
    'canvas' => array(
      'type' => 'row',
      'contains' => 'column',
      'children' => array(
        0 => 'main',
      ),
      'parent' => NULL,
    ),
    'main' => array(
      'type' => 'column',
      'width' => 100,
      'width_type' => '%',
      'children' => array(
        0 => 'main-row',
        1 => 1,
      ),
      'parent' => 'canvas',
    ),
    'main-row' => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'first',
        1 => 'second',
        2 => 'third',
        3 => 'fourth',
        4 => 'fifth',
      ),
      'parent' => 'main',
    ),
    1 => array(
      'type' => 'row',
      'contains' => 'region',
      'children' => array(
        0 => 'movies',
      ),
      'parent' => 'main',
      'class' => '',
    ),
    'movies' => array(
      'type' => 'region',
      'title' => 'Movies',
      'width' => 100,
      'width_type' => '%',
      'parent' => '1',
      'class' => '',
    ),
    'first' => array(
      'type' => 'region',
      'title' => 'First',
      'width_type' => '%',
      'parent' => 'main-row',
      'class' => '',
    ),
    'second' => array(
      'type' => 'region',
      'title' => 'Second',
      'width_type' => '%',
      'parent' => 'main-row',
      'class' => '',
    ),
    'third' => array(
      'type' => 'region',
      'title' => 'Third',
      'width_type' => '%',
      'parent' => 'main-row',
      'class' => '',
    ),
    'fourth' => array(
      'type' => 'region',
      'title' => 'Fourth',
      'width_type' => '%',
      'parent' => 'main-row',
      'class' => '',
    ),
    'fifth' => array(
      'type' => 'region',
      'title' => 'Fifth',
      'width_type' => '%',
      'parent' => 'main-row',
      'class' => '',
    ),
  ),
);
