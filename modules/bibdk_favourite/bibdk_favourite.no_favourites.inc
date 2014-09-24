<?php
/**
 * Created by IntelliJ IDEA.
 * User: pjo
 * Date: 5/20/14
 * Time: 10:18 AM
 */

/** Implement hook_form_FORM_ID_alter (user_profile_form)
 * add a submit method to check if user has any favourite agencies
 * @param $form
 * @param $form_state
 */
function bibdk_favourite_form_user_profile_form_alter(&$form, $form_state){
  $form['#submit'][] = 'bibdk_favourite_add_favourite_message';
}


/** Set a message for  bibliotek.dk users, who has not yet selected a favourite
 * @param $form
 * @param $form_state
 */
function bibdk_favourite_add_favourite_message($form,$form_state){
  $favourites = bibdk_favourite_get_favourites();
  if(empty($favourites)){
    drupal_set_message(bibdk_favourite_remember_favourites_message());
  }
}

/** Get a message to encourage users to add favourites
 * @return string
 */
function bibdk_favourite_remember_favourites_message() {
  $link = l(t('add_favourites',array(),array('context'=>'bibdk_favourite')), 'vejviser');
  return t('remember_to_add_favourite_libraries',array(),array('context'=>'bibdk_favourite')) . ' ' . $link;
}