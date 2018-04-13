<?php
/**
 * @file
 * bibdk_role_redakteur.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function bibdk_role_redakteur_user_default_roles() {
  $roles = array();

  // Exported role: redakteur.
  $roles['redakteur'] = array(
    'name' => 'redakteur',
    'weight' => '2',
  );

  return $roles;
}
