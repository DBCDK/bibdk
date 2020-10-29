Implements Audit Trail for Bibliotek.dk

This module depends on the contrib libraries module due to the AuditTrail php library.

The PHP AuditTrail library lives here: https://gitlab.dbc.dk/pu/audit/audit-trail-php-library

The audit trail is need due to GDPR. we need to be able to prove who is watching whos data. And writing data as well.

###Important functions:

 This is the main function for this module, it submits the relevant data to AuditTrail.
 There is no return value on this function.
 ```php
 /**
  * @params string $action Must be either read or write.
  * @params string $owning_user The owner of the data been loaded or written. It can be either a token or $user->uid.
  * @params array $access_info The important data like email, username, orderId etc.
  */
 bibdk_audit_trail_submit_data(
   $action,
   $owning_user,
   $access_info
 );
```
The module is hooking into to three functions at this time:
 - hook_user_update()
 - hook_user_load()
 - hook_bibdk_reservation_complete()

It also adds an ekstra validate function for the _bibdk_reservation_create_wizard_form_ function.
The validate function is purely to retrieve the `$form_state['values']`.
