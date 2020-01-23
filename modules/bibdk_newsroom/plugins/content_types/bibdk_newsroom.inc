<?php

/**
 * @file
 * Bibdk newsroom: ctools content type.
 *
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Bibliotek.dk newsroom'),
  'admin info' => 'bibdk_newsroom_bibdk_newsroom_admin_info',
  'content_types' => 'bibdk_newsroom',
  'single' => TRUE,
  'render callback' => 'bibdk_newsroom_render',
  'description' => t('Bibliotek.dk newsroom content type.'),
  'required context' => new ctools_context_required(t('bibdk_newsroom_context'), 'bibdk_newsroom_context'),
  'edit form' => 'bibdk_newsroom_edit_form',
  'category' => array(t('Ding!'), -9),
);


/**
 * Callback to provide administrative info (the preview in panels when building
 * a panel).
 *
 * In this case we'll render the content with a dummy argument and
 * a dummy context.
 */
function bibdk_newsroom_bibdk_newsroom_admin_info($subtype, $conf, $context = NULL) {
  $context = new stdClass();
  $context->data = new stdClass();
  $context->data->description = t("Bibliotek.dk newsroom");
  $block = bibdk_newsroom_render($subtype, $conf, array("Example"), $context);
  return $block;
}


/**
 * Run-time rendering of the body of the block (content type)
 *
 * @param $subtype
 * @param $conf
 *   Configuration as done at admin time
 * @param $args
 * @param $context
 *
 * @return
 *   An object with at least title and content members
 */
 // simplecontext_content_type_render
function bibdk_newsroom_render($subtype, $conf, $args, $context) {

  $data = $context->data;
  $block = new stdClass();
  $nid = FALSE;

  if (!empty($conf) && isset($conf['newsroom_id'])) {
    $nid = (int)$conf['newsroom_id'];
  }
  if (!empty($args) && !$nid) {
    $nid = (int)$args[0];
  }
  if (!empty($data->nid) && !$nid) {
    $nid = (int)$data->nid;
  }

  drupal_add_css(
    drupal_get_path('module', 'bibdk_newsroom') . '/css/bibdk_newsroom.css',
    array('group' => CSS_DEFAULT,
    'every_page' => TRUE)
  );

  // The title actually used in rendering.
  $block->title = "Bibliotek.dk newsroom";

  // Build Breadcrumbs
  $breadcrumb[] = l(t('Newsroom'), 'newsroom');

  if ( $nid ) {
    $node = node_load($nid);
    if ( !$node ) {
      drupal_set_message(t('The newsroom node does not exist.', array(), array('context' => 'bibdk_newsroom_context')), 'warning');
      return $block;
    }
    // The title actually used in rendering.
    $block->title = $node->title;
    $breadcrumb[] = l($node->title, current_path());
    drupal_set_breadcrumb($breadcrumb);
    $nodeview = node_view($node, 'full');
    $nodeview['newsroom_url'] = '/overlay/newsroom/' . $nid;
    $nodeview['#contextual_links']['node'][0] = 'newsroom';
    $block->content = $nodeview;
    return $block;
  }

}


/**
 * 'Edit' callback for the content type.
 * This example just returns a form.
 *
 */
function bibdk_newsroom_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['newsroom_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Node ID:'),
    '#size' => 5,
    '#description' => t('Optional: Newsroom node ID.'),
    '#default_value' => !empty($conf['newsroom_id']) ? $conf['newsroom_id'] : '',
  );
  return $form;
}


function bibdk_newsroom_edit_form_submit($form, &$form_state) {
  foreach (element_children($form) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}
