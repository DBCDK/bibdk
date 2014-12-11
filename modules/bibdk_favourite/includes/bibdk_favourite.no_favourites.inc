<?php
/**
 * @file
 * this file contains functions for handling a flow when users do not have a
 * favourite library attached to their profile
 */

/**
 * Implement hook_form_user_profile_form_alter().
 *
 * add a submit method to check if user has any favourite agencies
 *
 * @param $form
 * @param $form_state
 */
function bibdk_favourite_form_user_profile_form_alter(&$form, $form_state) {
  $form['#submit'][] = 'bibdk_favourite_add_favourite_message';
}

/**
 * Set a message for bibliotek.dk users, who has not yet selected a favourite
 *
 * @param $form
 * @param $form_state
 */
function bibdk_favourite_add_favourite_message($form, $form_state) {
  $favourites = bibdk_favourite_get_favourites();
  if (empty($favourites)) {
    drupal_set_message(bibdk_favourite_remember_favourites_message());
  }
}

/**
 * Get a message to encourage users to add favourites
 *
 * @return string
 */
function bibdk_favourite_remember_favourites_message() {
  $link = l(t('add_favourites', array(), array('context' => 'bibdk_favourite')), 'vejviser');
  return t('remember_to_add_favourite_libraries', array(), array('context' => 'bibdk_favourite')) . ' ' . $link;
}


/**
 * Form if user has no order library
 *
 * @param $form
 * @param $form_state
 * @return array|mixed
 */
function bibdk_favourite_no_library_form($form, &$form_state) {
  if (isset($form_state['clicked_button']['#branch'])) {
    $branch = $form_state['clicked_button']['#branch'];
    $form = bibdk_favourite_user_form_fields($form, $form_state, $branch->branchId);
  }
  else {
    $form = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array('infomedia-search-group', 'form-wrapper'),
      ),
    );
    $form['description_tag'] = array(
      '#theme' => 'html_tag',
      '#tag' => 'p',
      '#value' => t('no_favourite_library_description', array(), array('context' => 'ting_infomedia')),
    );
    $form['elements'] = bibdk_vejviser_form(array(), $form_state);

    if (isset($form_state['input']['openagency_query'])) {
      $query = check_plain($form_state['input']['openagency_query']);
      $result = bibdk_vejviser_execute_agency_search($query);
      $result = is_array($result) ? $result : array($result);
      $form += bibdk_favourite_parse_agency_search_result($result);
    }
  }
  $form['#submit'] = array('bibdk_favourite_no_library_form_submit');
  return $form;
}

/**
 * Set Rebuild form to true.
 *
 * Bibdk_favourite_no_library_form() controls the state of the flow
 *
 * @param $form
 * @param $form_state
 */
function bibdk_favourite_no_library_form_submit($form, &$form_state) {
  $form_state['rebuild'] = TRUE;
}

/**
 * View agency search result
 *
 * @param $result
 * @return array|mixed
 */
function bibdk_favourite_parse_agency_search_result($result) {
  $form = array();

  foreach ($result as $branch) {
    $settings = array(
      '#actions' => bibdk_favourite_get_agency_action($branch)
    );
    $form += ting_agency_view_agency_branch($branch, $settings);
  }
  return $form;
}

/**
 * Action for agency search result view
 *
 * @param $branch
 * @return array
 */
function bibdk_favourite_get_agency_action($branch) {
  return array(
    '#value' => t('select_favourite_library', array(), array('context' => 'bibdk_favourite')),
    '#name' => 'branch-' . $branch->branchId,
    '#type' => 'submit',
    '#submit' => array('bibdk_favourite_select_library_submit'),
    '#branch' => $branch,
  );
}

/**
 * Rebuild form_state
 *
 * @param $form
 * @param $form_state
 */
function bibdk_favourite_select_library_submit($form, &$form_state) {
  $form_state['rebuild'] = true;
}
