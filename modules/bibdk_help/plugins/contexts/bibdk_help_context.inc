<?php


/**
 * @file
 * Sample ctools context type plugin that shows how to create a context from an arg.
 *
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("bibdk_help context"),
  'description' => t('A single "bibdk_help_context" context, or data element.'),
  'context' => 'ctools_bibdk_help_context_create_bibdk_help_context',  // func to create context
  'context name' => 'bibdk_help_context',
  'settings form' => 'bibdk_help_context_settings_form',
  'keyword' => 'bibdk_help_context',

  'placeholder form' => array(
    '#type' => 'textfield',
    '#description' => t('Enter some data to represent this "bibdk_help context".'),
  ),
);

/**
 * Create a context, either from manual configuration or from an argument on the URL.
 *
 * @param $empty
 *   If true, just return an empty context.
 * @param $data
 *   If from settings form, an array as from a form. If from argument, a string.
 * @param $conf
 *   TRUE if the $data is coming from admin configuration, FALSE if it's from a URL arg.
 *
 * @return
 *   a Context object/
 */
function ctools_bibdk_help_context_create_bibdk_help_context($empty, $data = NULL, $conf = FALSE) {
  $context = new ctools_context('bibdk_help_context');
  $context->plugin = 'bibdk_help_context';

  if ($empty) {
    return $context;
  }

  if ($conf) {
    if (!empty($data)) {
      $context->data = new stdClass();
      // For this simple item we'll just create our data by stripping non-alpha and
      // adding '_from_configuration_item_1' to it.
      $context->data->item1 = t("Item1");
      $context->title = t("bibdk_help_context context from config");
      return $context;
    }
  }
  else {
    // $data is coming from an arg - it's just a string.
    $context->title = t("bibdk_help_context context from arg");
    $context->argument = $data;
    // Make up a bogus context
    $context->data = new stdClass();
    $context->data->nid = (int)$data;
    $context->arg_length = strlen($context->argument);
    return $context;
  }
}

function bibdk_help_context_settings_form($conf, $external = FALSE) {
  if (empty($conf)) {
    $conf = array(
      'sample_bibdk_help_context_setting' => 'default bibdk_help_context setting',
    );
  }
  $form = array();
  $form['sample_bibdk_help_context_setting'] = array(
    '#type' => 'textfield',
    '#title' => t('Setting for bibdk_help_context'),
    '#size' => 50,
    '#description' => t('An example setting that could be used to configure a context'),
    '#default_value' => $conf['sample_bibdk_help_context_setting'],
    '#prefix' => '<div class="clear-block no-float">',
    '#suffix' => '</div>',
  );
  return $form;
}

