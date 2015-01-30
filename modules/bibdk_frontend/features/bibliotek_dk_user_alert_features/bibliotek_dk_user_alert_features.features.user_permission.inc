<?php
/**
 * @file
 * bibliotek_dk_user_alert_features.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function bibliotek_dk_user_alert_features_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer scheduler.
  $permissions['administer scheduler'] = array(
    'name' => 'administer scheduler',
    'roles' => array(
      0 => 'administrator',
      1 => 'redakteur',
    ),
    'module' => 'scheduler',
  );

  // Exported permission: administer user alert.
  $permissions['administer user alert'] = array(
    'name' => 'administer user alert',
    'roles' => array(
      0 => 'administrator',
      1 => 'redakteur',
    ),
    'module' => 'user_alert',
  );

  // Exported permission: create user_alert content.
  $permissions['create user_alert content'] = array(
    'name' => 'create user_alert content',
    'roles' => array(
      0 => 'administrator',
      1 => 'redakteur',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any user_alert content.
  $permissions['delete any user_alert content'] = array(
    'name' => 'delete any user_alert content',
    'roles' => array(
      0 => 'administrator',
      1 => 'redakteur',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own user_alert content.
  $permissions['delete own user_alert content'] = array(
    'name' => 'delete own user_alert content',
    'roles' => array(
      0 => 'administrator',
      1 => 'redakteur',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any user_alert content.
  $permissions['edit any user_alert content'] = array(
    'name' => 'edit any user_alert content',
    'roles' => array(
      0 => 'administrator',
      1 => 'redakteur',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own user_alert content.
  $permissions['edit own user_alert content'] = array(
    'name' => 'edit own user_alert content',
    'roles' => array(
      0 => 'administrator',
      1 => 'redakteur',
    ),
    'module' => 'node',
  );

  // Exported permission: schedule (un)publishing of nodes.
  $permissions['schedule (un)publishing of nodes'] = array(
    'name' => 'schedule (un)publishing of nodes',
    'roles' => array(
      0 => 'administrator',
      1 => 'redakteur',
    ),
    'module' => 'scheduler',
  );

  return $permissions;
}
