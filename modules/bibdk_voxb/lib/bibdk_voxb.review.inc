<?php
/**
 * Created by IntelliJ IDEA.
 * User: pjo
 * Date: 5/6/14
 * Time: 1:12 PM
 */

/**
 * Edit review callback
 */
function bibdk_voxb_edit_review() {
  $blog_node = bibdk_voxb_set_blog_node();
  $block = bibdk_voxb_block_view('bibdk_voxb_blog', $blog_node);

  return $block;
}

function bibdk_voxb_set_blog_node() {
  $form = array();
  $pid = bibdk_voxb_review_check_pid();
  $voxb_user_id = bibdk_voxb_user_check();
  if (!empty($voxb_user_id)) {
    $form['#voxb_user_id'] = $voxb_user_id;
  }

  $user_data = bibdk_voxb_check_voxb_review($pid, $form);
  if (isset($form['#voxb_id'])) {
    // try to get the node
    $blog_node = bibdk_voxb_blog_fetch_blog_node($form['#voxb_id']);
    // fetch item from webservice. Content may have changed on voxb-service
    $response = open_voxb_fetchData_by_itemid($form['#voxb_id']);
    $voxb_node = bibdk_voxb_get_review_node($response);
    // synchronize .. item may have change on voxb-service
    $blog_node = bibdk_voxb_review_synchronize($blog_node, $voxb_node);
  }
  else {
    // create
    $blog_node = bibdk_voxb_blog_node_create();
  }

  return $blog_node;
}

/**
 * Create review callback
 * Create a blog node
 */
function bibdk_voxb_create_review() {
  $blog_node = bibdk_voxb_blog_node_create();

  if (!function_exists("node_form")) {
    include_once(drupal_get_path('module', 'node') . '/node.pages.inc');
  }
  $form = drupal_get_form('blog_node_form', $blog_node);
  drupal_set_title(t('voxb_create_review_title', array(), array('context' => 'bibdk_voxb')));

  return $form;
}

/** Edit review callback
 * @param $blog_node
 * @return array|mixed
 */
function bibdk_voxb_review_edit_node($blog_node) {
  if (!function_exists("node_form")) {
    include_once(drupal_get_path('module', 'node') . '/node.pages.inc');
  }

  $form = drupal_get_form('blog_node_form', $blog_node);
  drupal_set_title(t('voxb_edit_review_title', array(), array('context' => 'bibdk_voxb')));

  return $form;
}

function bibdk_voxb_review_modal_edit_form($form, $form_state) {
  if (!function_exists("node_form")) {
    include_once(drupal_get_path('module', 'node') . '/node.pages.inc');
  }

  $blog_node = $form_state['build_info']['args'][0];
  //$form = node_form($form, $form_state, $blog_node);
  $form = drupal_get_form('blog_node_form', $blog_node);

  return $form;
}

/**
 * Implements hook_form_FORM_ID_alter (node_blog_form)
 *
 * alter the form here .. e.g add pid in hidden field
 * add accept checkbox for review terms
 * add validate and submit methods e.g to save on voxb-webservice
 */
function bibdk_voxb_form_blog_node_form_alter(&$form, &$form_state) {
  $pid = bibdk_voxb_review_check_pid();
  $form['#faust'] = bibdk_voxb_pid2faust($pid);
  // remove preview button
  unset ($form['actions']['preview']);

  $voxb_user_id = bibdk_voxb_user_check();
  $form['#voxb_user_id'] = $voxb_user_id;

  $form['#validate'][] = 'bibdk_voxb_review_validate';
  $form['#validate'][] = 'bibdk_voxb_review_validate_save';

  $form['title']['#maxlength'] = 32; // this is most likely an error at the webservice. Titles longer than 32 return 'Error updating review in database'

  if ( !empty($pid) ) {
    // title should be fixed
    $form['title']['#attributes'] = array('readonly' => 'readonly');
    // get user-data from voxb
    $user_data = bibdk_voxb_check_voxb_review($pid, $form);

    // TO DO: Get title & author from record if it's a new review
    /*if ( !empty($user_data['voxb_items']['voxb:object']['voxb:objectContributors']['#text']) ) {
      $object[] = $user_data['voxb_items']['voxb:object']['voxb:objectContributors']['#text'];
    }
    if ( !empty($user_data['voxb_items']['voxb:object']['voxb:objectTitle']['#text']) ) {
      $object[] = $user_data['voxb_items']['voxb:object']['voxb:objectTitle']['#text'];
    }
    if ( !empty($object) ) {
      $form['review_title'] = array(
        '#type' => 'item',
        '#weight' => -15,
        '#title' => t('review_title_leadtext', array(), array('context' => 'bibdk_voxb')),
        '#markup' => implode(' : ',$object),
      );
    }*/
    if ( $voxb_user_id ) {
      if ( empty($form['field_voxb_id']['und'][0]['value']['#default_value']) ) {
        $form['field_voxb_id']['und'][0]['value']['#default_value'] = $form['#voxb_id'];
      }

      if ( empty($form['field_voxb_useridentifiervalue']['und'][0]['value']['#default_value']) ) {
        $form['field_voxb_useridentifiervalue']['und'][0]['value']['#default_value'] = $form['#voxb_useridentifiervalue'];
      }

      if ( empty($form['field_voxb_alias']['und'][0]['value']['#default_value']) ) {
        $form['field_voxb_alias']['und'][0]['value']['#default_value'] = $form['#voxb_aliasname'];
      }

      if ( !$user_data['accepted_review_terms'] ) {
        $form['accepted_review_terms'] = array(
          '#type' => 'checkbox',
          '#weight' => -15,
          '#title' => t('accept_review_terms_message', array(), array('context' => 'bibdk_voxb')),
          '#default_value'   => FALSE,
          '#element_validate' => array('bibdk_voxb_accepted_review_terms_validate'),
        );
      }

      // hide fields
      $form['field_voxb_id']['#type'] = 'hidden';
      $form['field_voxb_useridentifiervalue']['#type'] = 'hidden';
      $form['field_voxb_alias']['#type'] = 'hidden';
      
      // add delete button if review already exist

      // add delete button for admin users
      global $user;
      if ($user->uid == 1) {
        if (!empty($form['#node']->field_voxb_id['und'][0]['value'])) {
          $form['actions']['delete'] = array(
            '#type' => 'submit',
            '#access' => TRUE,
            '#value' => 'Delete',
            '#weight' => 15,
            '#submit' => array('bibdk_voxb_review_delete'),
          );
        }
      }
    }
    else {

      $form['title']['#disabled']   = TRUE;
      $form['body']['#disabled']    = TRUE;
      $form['actions']['#disabled'] = TRUE;
      drupal_set_message( t('voxb_review_voxb_id_error', array(), array('context'=>'bibdk_voxb:error')), 'error');
      watchdog('voxb', 'VoxB review : VoxB user id is missing in form', array(), WATCHDOG_ERROR);
      return;

    }
  }
  else {
    form_set_error('field_voxb_id', $message = t('voxb_review_no_record_id_set', array(), array('context'=>'bibdk_voxb:error')));
  }
}

/** Check if given pid has already been handled by voxb.
 * if so, add voxb_identifier to form
 *
 * Get the voxb userid and add it to form also
 *
 * @param $pid
 * @param $form
 */
function bibdk_voxb_check_voxb_review($pid, &$form) {

  // get data for user
  if (!empty($form['#voxb_user_id'])) {
    $user_data = bibdk_voxb_get_user_item(bibdk_voxb_pid2faust($pid), $form['#voxb_user_id']);
  }

  if (empty($user_data)) {
    return;
  }

  $form['#voxb_id'] = NULL;
  // if ( !empty($user_data['voxb_items']['voxb:item']['voxb:review']) ) {
  if (!empty($user_data['voxb_items'])) {
    // user has already written a review.
    $voxb_identifier = $user_data['voxb_items']['voxb:voxbIdentifier']['#text'];
    // add voxb_id to form
    $form['#voxb_id'] = $voxb_identifier;
  }
  if (empty($form['#voxb_id'])) {
    $work = bibdk_voxb_get_manifestation($pid);
    $form['title']['#value'] = bibdk_voxb_review_trim_title($work->getTitle());
  }

  $form['#voxb_aliasname'] = isset($user_data['alias']) ? $user_data['alias'] : NULL;

  // $form['#voxb_useridentifiervalue'] = isset($user_data['useridentifiervalue']) ? $user_data['useridentifiervalue'] : NULL;

  return $user_data;
}

/**
 * @param $string
 * @param int $size
 * @return string
 */
function bibdk_voxb_review_trim_title($string, $size = 32) {
  if (strlen($string) <= $size) {
    return $string;
  }
  $trim = substr($string, 0, 30);

  return $trim . '..';
}

/** Synchronize a blog_node with review-node from voxb-webservice
 *
 * the review may have changed on webservice, so we need to update
 * the blog node.
 *
 * @param $blog_node
 * @param $voxb_node
 */
function bibdk_voxb_review_synchronize($blog_node, $voxb_node) {
  global $user;

  if (empty($blog_node)) {
    $blog_node = bibdk_voxb_blog_node_create($voxb_node);
  }
  // try entity_metadata thingie
  $wrapper = entity_metadata_wrapper('node', $blog_node);
  // alias name may have changed
  $wrapper->field_voxb_alias->set($voxb_node->alias);
  // title may have changed
  if (isset($voxb_node->Title)) {
    $wrapper->title->set($voxb_node->Title);
  }
  // body may have change 
  if (isset($voxb_node->reviewData)) {
    $wrapper->body->set(array('value' => $voxb_node->reviewData));
  }
  $blog_node->uid = $user->uid;

  return $blog_node;
}

/** Custom validator for node_blog_form. Create or update voxb-review
 * @param $form
 * @param $form_state
 */
function bibdk_voxb_review_validate(&$form, &$form_state) {

  if (empty($form_state['values']['body']['und'][0]['value'])) {
    form_set_error('body', t('voxb_review_empty_body_error', array(), array('context' => 'bibdk_voxb:error')));
  }

  if (empty($form_state['values']['title'])) {
    form_set_error('title', t('voxb_review_empty_title_error', array(), array('context' => 'bibdk_voxb:error')));
  }

  if (strlen($form_state['values']['title']) > 32) {
    form_set_error('title', t('voxb_review_title_size_error', array(), array('context' => 'bibdk_voxb:error')));
  }

}

/** Custom submit for node_blog_form. Create or update voxb-review
 * @param $form
 * @param $form_state
 */
function bibdk_voxb_review_validate_save(&$form, &$form_state) {

  if (!function_exists("node_form")) {
    include_once(drupal_get_path('module', 'node') . '/node.pages.inc');
  }
  $msg = '';
  // update review
  if (!empty($form['#voxb_id'])) {
    $review = bibdk_voxb_voxb_review_from_form($form_state);
    $response = open_voxb_updateReview($form['#voxb_id'], $review);
    try {
      $voxb_id = bibdk_voxb_parse_update_data_response($response, $msg);
    }
    catch (bibdkVoxbException $e) {
      watchdog('voxb', 'bibdk_voxb_review_submit: ' . $msg, array(), WATCHDOG_ERROR);
      drupal_set_message(t('bibdk_voxb_update_review_error', array(), array('context' => 'bibdk_voxb:error')), 'error');
      form_set_error('submit', $message = t('bibdk_voxb_update_review_error', array(), array('context' => 'bibdk_voxb:error')));
    }
  }
  else {
    // create review
    $review = bibdk_voxb_voxb_review_from_form($form_state);
    $user = $form['#voxb_user_id'];
    // create voxb review
    $response = open_voxb_createMyReviewRequest($form['#faust'], $review, $user);
    try {
      $voxb_id = bibdk_voxb_parse_update_data_response($response, $msg);
    }
    catch (bibdkVoxbException $e) {
      $voxb_id = FALSE;
      watchdog('voxb', 'create review error: ' . $msg, array(), WATCHDOG_ERROR);
      form_set_error('submit', $message = t('bibdk_voxb_review_disabled_error', array(), array('context' => 'bibdk_voxb:error')));
    }

    if ($voxb_id !== FALSE) {
      $form['#voxb_id'] = $voxb_id;
      $form_state['values']['field_voxb_id']['und'][0]['value'] = $voxb_id;
    }
  }
}

/** Custom submit for node_blog_form.  voxb-review
 * @param $form
 * @param $form_state
 */
function bibdk_voxb_review_delete(&$form, &$form_state) {

  // delete voxb review
  $voxbIdentifier = $form_state['values']['field_voxb_id']['und'][0]['value'];
  try {
    $response = open_voxb_deleteMyDataRequest($voxbIdentifier);
  }
  catch (bibdkVoxbException $e) {
    watchdog('voxb', 'bibdk_voxb_review_delete: ' . $msg, array(), WATCHDOG_ERROR);
    drupal_set_message(t('bibdk_voxb_review_delete_error', array(), array('context' => 'bibdk_voxb:error')), 'error');
  }

  // delete blog node
  node_delete($form_state['values']['nid']);
  drupal_set_message(t('bibdk_voxb_review_delete_succes', array(), array('context' => 'bibdk_voxb')), 'status');
}

/**
 * Validate that the user has accepted the terms for reviewing.
 */
function bibdk_voxb_accepted_review_terms_validate($element, &$form_state, $form) {
  if (empty($element['#value'])) {
    form_error($element, t('accept_review_terms_validation_message', array(), array('context' => 'bibdk_voxb')));
  }
}

function bibdk_voxb_voxb_review_from_form($form_state) {
  $ret = new stdClass();
  $ret->title = $form_state['values']['title'];
  // we can use 'und' when indexing since multilingual suppoert is disabled for blogentries
  // use lang if enabling multilingual support
  $ret->Data = $form_state['values']['body']['und'][0]['value'];

  return $ret;
}

function bibdk_voxb_review_check_pid() {
  static $pid;
  if (empty($pid)) {
    $pid = isset($_REQUEST['pid']) ? $_REQUEST['pid'] : NULL;
  }

  return $pid;
}

/********* block definition ***********/

/** Implements hook_block_info
 *
 */
function bibdk_voxb_block_info() {
  $blocks['bibdk_voxb_blog'] = array(
    'info' => t('voxb review as blogenty'),
  );

  return $blocks;
}

/** Implements hook_block_view
 * @return array|mixed
 */
function bibdk_voxb_block_view($delta, $blog_node) {

  return bibdk_voxb_review_edit_node($blog_node);

  $block = array();
  switch ($delta) {
    case 'bibdk_voxb_blog' :
      $block['content'] = bibdk_voxb_review_edit_node($blog_node);
      break;
  }

  return $block;
}