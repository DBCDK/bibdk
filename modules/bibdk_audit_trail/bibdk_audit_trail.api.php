<?php

/**
 * @file
 * Hooks provided by the bibdk_audit_trail module.
 */

/**
 * Get fieldsets from other modules.
 *
 * @param  $foo
 * @return array Audit Trail params array
 */
function hook_bibdk_audit_trail($foo) {
  global $user;
  $ret['audit_trail']['foo0'] = 'bar';
  $ret['audit_trail']['foo1'] = 'bar';
  $ret['audit_trail']['foo2'] = 'bar';
  $ret['audit_trail']['foo3'] = 'bar';
  return $ret;
}
