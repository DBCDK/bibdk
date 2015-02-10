<?php
/**
 * @file
 * bibdk_role_redakteur.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function bibdk_role_redakteur_user_default_permissions() {
  $permissions = array();

  // Exported permission: access content overview.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      0 => 'administrator',
      1 => 'redakteur',
    ),
    'module' => 'node',
  );

  // Exported permission: access toolbar.
  $permissions['access toolbar'] = array(
    'name' => 'access toolbar',
    'roles' => array(
      0 => 'administrator',
      1 => 'redakteur',
    ),
    'module' => 'toolbar',
  );

  // Exported permission: access user profiles.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      0 => 'administrator',
      1 => 'redakteur',
    ),
    'module' => 'user',
  );

  // Exported permission: administer users.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      0 => 'administrator',
      1 => 'redakteur',
    ),
    'module' => 'user',
  );

  // Exported permission: create bibdk articles.
  $permissions['create bibdk articles'] = array(
    'name' => 'create bibdk articles',
    'roles' => array(
      0 => 'administrator',
      1 => 'redakteur',
    ),
    'module' => 'bibdk_article',
  );

  // Exported permission: create bibdk_article content.
  $permissions['create bibdk_article content'] = array(
    'name' => 'create bibdk_article content',
    'roles' => array(
      0 => 'administrator',
      1 => 'redakteur',
    ),
    'module' => 'node',
  );

  // Exported permission: create userhelp content.
  $permissions['create userhelp content'] = array(
    'name' => 'create userhelp content',
    'roles' => array(
      0 => 'administrator',
      1 => 'redakteur',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any bibdk_article content.
  $permissions['delete any bibdk_article content'] = array(
    'name' => 'delete any bibdk_article content',
    'roles' => array(
      0 => 'administrator',
      1 => 'redakteur',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any userhelp content.
  $permissions['delete any userhelp content'] = array(
    'name' => 'delete any userhelp content',
    'roles' => array(
      0 => 'administrator',
      1 => 'redakteur',
    ),
    'module' => 'node',
  );

  // Exported permission: delete bibdk articles.
  $permissions['delete bibdk articles'] = array(
    'name' => 'delete bibdk articles',
    'roles' => array(
      0 => 'administrator',
      1 => 'redakteur',
    ),
    'module' => 'bibdk_article',
  );

  // Exported permission: delete own bibdk_article content.
  $permissions['delete own bibdk_article content'] = array(
    'name' => 'delete own bibdk_article content',
    'roles' => array(
      0 => 'administrator',
      1 => 'redakteur',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own userhelp content.
  $permissions['delete own userhelp content'] = array(
    'name' => 'delete own userhelp content',
    'roles' => array(
      0 => 'administrator',
      1 => 'redakteur',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any bibdk_article content.
  $permissions['edit any bibdk_article content'] = array(
    'name' => 'edit any bibdk_article content',
    'roles' => array(
      0 => 'administrator',
      1 => 'redakteur',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any userhelp content.
  $permissions['edit any userhelp content'] = array(
    'name' => 'edit any userhelp content',
    'roles' => array(
      0 => 'administrator',
      1 => 'redakteur',
    ),
    'module' => 'node',
  );

  // Exported permission: edit bibdk articles.
  $permissions['edit bibdk articles'] = array(
    'name' => 'edit bibdk articles',
    'roles' => array(
      0 => 'administrator',
      1 => 'redakteur',
    ),
    'module' => 'bibdk_article',
  );

  // Exported permission: edit own bibdk_article content.
  $permissions['edit own bibdk_article content'] = array(
    'name' => 'edit own bibdk_article content',
    'roles' => array(
      0 => 'administrator',
      1 => 'redakteur',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own userhelp content.
  $permissions['edit own userhelp content'] = array(
    'name' => 'edit own userhelp content',
    'roles' => array(
      0 => 'administrator',
      1 => 'redakteur',
    ),
    'module' => 'node',
  );

  // Exported permission: use text format html_5.
  $permissions['use text format html_5'] = array(
    'name' => 'use text format html_5',
    'roles' => array(
      0 => 'redakteur',
    ),
    'module' => 'filter',
  );

  // Exported permission: view own unpublished content.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      0 => 'administrator',
      1 => 'redakteur',
    ),
    'module' => 'node',
  );

  return $permissions;
}
