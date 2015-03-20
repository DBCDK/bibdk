<?php
/**
 * @file
 * Drupal 7 doesn't support html input fields - eg. input type=email, numberic etc.
 * this file implements a number of form_FORM_ID_alter functions to set type of input fields
 *
**/

/**
 * Implements hook_form_FORM_ID_alter (user_pass)
 */
function bibdk_frontend_form_user_pass_alter(&$form, $form_state){
  $form['name']['#type'] = "emailfield";
}


/**
 * Implement hook_form_FORM_ID_alter (user_register)
 */
function bibdk_frontend_form_user_register_form_alter(&$form, $form_state){
  $form['mail']['#type'] = "emailfield";
}

/**
 * Implements hook_form_FORM_ID_alter (bibdk-favourite-user-form-fields)
 */
function bibdk_frontend_form_bibdk_favourite_user_form_fields_alter(&$form, $form_state ){
  $fields = &$form['wrapper'];
  // most fields in user-form-fields might not be set
  if(isset($fields['userId'])){
    // borrower-card number - numeric
    $fields['userId']['#type'] = 'numberfield';
  }

  //usermail - email
 if(isset($fields['userMail'])){
    $fields['userMail']['#type'] = 'emailfield';
  }
  //userTelephone - numeric
  if(isset($fields['userTelephone'])) {
    $fields['userTelephone']['#type'] = 'telfield';
  }
}
