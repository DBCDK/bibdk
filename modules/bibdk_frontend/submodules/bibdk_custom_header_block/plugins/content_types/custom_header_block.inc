<?php
/**
 * @file
 * define a configurable plugin
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Bibdk custom header Pane'),  // Title to show up on the pane screen.
  'description' => t('Configure this panel'),
  'category' => t('Bibliotek.dk'), // A category to put this under.
  'edit form' => 'bibdk_custom_header_block_pane_custom_pane_edit_form', // A function that will return the settings form for the pane.
  'render callback' => 'bibdk_custom_header_block_pane_custom_pane_render', // A function that will return the renderable content.
  'defaults' => array( // Array of defaults for the settings form.
    'pane_title' => '', // the title of the pane
    'link' => '', // NOTICE this is handled as a callback. if the function doesn't exist nothing will be output
  ),
  'all contexts' => TRUE,
);

/**
 * Render callback
 * @param $subtype
 * @param $conf
 * @param $args
 * @param $contexts
 * @return stdClass
 */
function bibdk_custom_header_block_pane_custom_pane_render($subtype, $conf, $args, $contexts){
  $block = new stdClass();
  $block->title = t('This is my title!'); // This can be overridden by the user within the panel options.
  $content = bibdk_custom_header_block_get_content($conf);
  $block->content = $content;
  return $block;
}

/**
 * Get block content
 * @param $conf
 * @return mixed
 */
function bibdk_custom_header_block_get_content($conf){
  $content['container'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('bibdk-custom-header-block', 'clearfix'),
    )
  );

  $content['container']['title'] = bibdk_custom_header_block_get_title($conf);
  $content['container']['link'] = bibdk_custom_header_block_get_link($conf);

  return $content;
}

/**
 * Render array for pane title
 * @param $conf
 * @return array
 */
function bibdk_custom_header_block_get_title($conf){
  return array(
    '#type' => 'html_tag',
    '#tag' => 'h1',
    '#attributes' => array(
      'class' => array('bibdk-custom-header-title'),
    ),
    '#value' => $conf['pane_title'],
  );
}

/**
 * Render array for additional block content
 * NOTICE : this method does a callback.
 * @param $conf
 * @return array
 */
function bibdk_custom_header_block_get_link($conf) {
  $content = array();
  $func = $conf['link'];
  if (function_exists($func)) {
    $content['container'] = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array('bibdk-custom-header-link'),
      )
    );
    $content['container']['link'] = $func();
  }
  return $content;
}

/**
 * An edit form for the pane's settings.
 */
function bibdk_custom_header_block_pane_custom_pane_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['pane_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title for this panel'),
    '#description' => t('Text to display, it may use substitution strings'),
    '#default_value' => $conf['pane_title'],
  );

  $form['link'] = array(
    '#type' => 'textfield',
    '#title' => t('Link'),
    '#description' => t('Link element to display on the right side of this panel'),
    '#default_value' => $conf['link'],
  );

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 */
function bibdk_custom_header_block_pane_custom_pane_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}