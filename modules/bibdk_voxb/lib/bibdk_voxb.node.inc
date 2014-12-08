<?php
/**
 * Created by IntelliJ IDEA.
 * User: pjo
 * Date: 5/5/14
 * Time: 11:15 AM
 * This file handles voxb reviews as a node
 */

/** Fetch a blog node by id given from voxb webservice
 * @param $voxb_identifier ; id from voxb
 * @return mixed; blog_node if found, FALSE if not
 */
function bibdk_voxb_blog_fetch_blog_node($voxb_identifier) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'blog')->propertyCondition('status', 1)
    ->fieldCondition('field_voxb_id', 'value', $voxb_identifier, '=');

  $result = $query->execute();
  if (isset($result['node'])) {
    $blogs = node_load_multiple(array_keys($result['node']));
    // there can be only one
    $blog = current($blogs);
    if (!empty($blog)) {
      return $blog;
    }
  }

  return FALSE;
}

/** does NOT implement hook_node_delete
 * wrapper function for node_delete
 * @param $node
 */
function bibdk_voxb_blog_node_delete($node) {
  node_delete($node->nid);
}

/** Does NOT implement hook_node_view
 * wrapper function for node_view
 * @param $blog_node
 * @return string
 */
function bibdk_voxb_blog_node_view($blog_node) {
  return drupal_render(node_view($blog_node, 'full'));
}

/** Implements hook_node_view
 * unset user links for now
 */
function bibdk_voxb_node_view($node, $view_mode, $langcode) {
  if ($node->type == 'blog') {
    unset($node->content['links']);
    unset($node->content['field_voxb_useridentifiervalue']);
    unset($node->content['field_voxb_alias']);
    $wrapper = entity_metadata_wrapper('node', $node);
    $voxb_id = $wrapper->field_voxb_id->value();
    $node->content['offensive_content'] = bibdk_voxb_offensive_link($voxb_id);
  }

}

/**
 *  Function to update a blog node, based on the response from voxb
 *
 * @param stdObj $revew . A voxb review
 */
function bibdk_voxb_blog_node_update($review = NULL) {
  if (empty($review)) {
    return FALSE;
  }

  $blog_node = bibdk_voxb_blog_fetch_blog_node($review->voxb_identifier);

  if (empty($blog_node)) {
    return FALSE;
  }

  return $blog_node;
}

/** Function to create a node (blog) based on the response from voxb
 *  blog node is created with uid = 0 (anonymous user). blog node is saved
 *  with the alias given from voxb (mandatory). Alias will be used to filter
 *  blog-nodes.
 *
 * @param stdObj $revew . A voxb review
 */
function bibdk_voxb_blog_node_create($review = NULL) {
  if (empty($review)) {
    $review = new stdClass();
  }
  $node = new stdClass();
  $node->title = isset($review->title) ? $review->title : bibdk_voxb_title_from_pid();

  $node->type = "blog";
  node_object_prepare($node); // Sets some defaults. Invokes hook_prepare() and hook_node_prepare().
  $node->language = LANGUAGE_NONE; // Or e.g. 'en' if locale is enabled

  // user anonymous user
  $wrapper = entity_metadata_wrapper('node', $node);

  // get a userid
  if (!empty($review->voxb_userid)) {
    // is this a registred user
    $userid = bibdk_voxb_node_invoke_user_hook($review->voxb_userid);
    $account = user_load_by_mail($userid);
    if ($account) {
      $uid = $account->uid;
    }
  }
  elseif ($voxb_id = bibdk_voxb_user_check()) {
    $review->voxb_userid = $voxb_id;
  }

  // fallback
  if (empty($uid)) {
    global $user;
    $uid = $user->uid;
  }

  $node->uid = $uid;
  $node->status = 1; //(1 or 0): published or not
  $node->promote = 0; //(1 or 0): promoted to front page
  $node->comment = 1; // 0 = comments disabled, 1 = read only, 2 = read/write

  // set extra fields
  if (isset($review->voxb_identifier)) {
    $wrapper->field_voxb_id->set($review->voxb_identifier);
  }
  if (isset($review->voxb_userid)) {
    $wrapper->field_voxb_useridentifiervalue->set($review->voxb_userid);
  }
  if (isset($review->alias)) {
    $wrapper->field_voxb_alias->set($review->alias);
  }
  if (isset($review->reviewData)) {
    $wrapper->body->set(array('value' => $review->reviewData));
  }

  return $node;
}

/** see if anyone delivers a valid userid for given voxb_user_id
 * @param $voxb_user_id
 */
function bibdk_voxb_node_invoke_user_hook($voxb_user_id) {
  $userid = module_invoke_all('user_id_from_voxb_id', $voxb_user_id);
  if (empty($userid)) {
    return 0;
  }

  return $userid[0];
}
