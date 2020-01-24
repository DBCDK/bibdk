<?php

/**
 * @file
 * Bibdk subject hierarchy autocomplete functions
 */

/** Create subject hierarchy suggestion form
 *  * @return array
 */
function bibdk_subject_hierarchy_suggestion_form($form, &$form_state) {

  if ( !isset($form_state['stage']) ) {
    $form_state['stage'] = 'suggest_subject';
  }
  
  $form['#attributes'] = array(
    'class' => array('subject-hierarchy-suggestion-form', 'clearfix'),
  );
  
  $form['#attached']['js'] = array(
    drupal_get_path('module', 'bibdk_subject_hierarchy') . '/js/bibdk_subject_hierarchy.js',
  );

  switch ( $form_state['stage'] ) {

    case 'suggest_subject':
      $form['#attributes'] = array(
        'class' => array('subject-hierarchy-suggestion-form', 'send-suggestion', 'clearfix'),
      );
      return bibdk_subject_hierarchy_send_suggestion_form($form, $form_state);
      break;  
  
    case 'is_confirmed': 
      return bibdk_subject_hierarchy_confirmed_suggestion_form($form, $form_state);  
      break;
 
    default:
      return bibdk_subject_hierarchy_send_suggestion_form($form, $form_state);
      break; 
  }
   
  return $form;

}



function bibdk_subject_hierarchy_send_suggestion_form($form, &$form_state) {

  $header = array(
    '#type' => 'container',
    '#id' => 'search-hierarchy-suggestion-header',
    '#attributes' => array(
      'class' => array('header', 'send-suggestion'),
    ),
  );

  $header['headline'] = array(
    '#theme' => 'html_tag',
    '#tag' => 'h1',
    '#value' => t('HEADER_HIERARCHY_SEND_SUGGESTION', array(), array('context' => 'bibdk_subject_hierarchy') ),
  );

  $header['suggestion_text'] = array(
    '#theme' => 'html_tag',
    '#tag' => 'h2',
    '#value' => t("TEXT_HIERARCHY_SEND_SUGGESTION", array(), array('context' => 'bibdk_subject_hierarchy') ),
  );

  $form['bibdk_subject_hierarchy'] = array(
    '#type' => 'fieldset',
    '#tree' => FALSE,
    '#attributes' => array(
      'class' => array('header', 'fieldset-hierarchy-suggestion'),
    ),
  );

  $form['bibdk_subject_hierarchy']['subject_hierarchy_suggestion_header'] = $header;

  $form['bibdk_subject_hierarchy']['subject_hierarchy_suggestion'] = array(
    '#type' => 'textfield',
    '#attributes' => array(
      'class' => array('search-hierarchy-suggestion-input searchfield-input'),
      'placeholder' => t("PLACEHOLDER_HIERARCHY_SEND_SUGGESTION", array(), array('context' => 'bibdk_subject_hierarchy') ),
    ),
    '#default_value' => isset($values['subject_hierarchy_suggestion']) ? $values['subject_hierarchy_suggestion'] : NULL,
  );

  $form['bibdk_subject_hierarchy']['subject_hierarchy_submit_suggestion'] = array(
    '#type' => 'submit',
    '#value' => t("BUTTON_HIERARCHY_SEND_SUGGESTION", array(), array('context' => 'bibdk_subject_hierarchy') ),
    '#attributes' => array(
      'class' => array('searchfield-submit'),
    ),
    '#ajax' => array(
      'callback' => 'bibdk_subject_hierarchy_suggestion_form_submit',
      'wrapper' => 'bibdk-subject-hierarchy-searchresult',
      'method' => 'replace',
      'effect' => 'fade',
      'event' => 'click',
    ),
  );
  
  return $form;

}



/** Create subject hierarchy suggestion conformation form
 *  * @return array
 */
function bibdk_subject_hierarchy_confirmed_suggestion_form($form, &$form_state) {

  $values = isset($form_state['multistep_values']['suggest_subject']) ? $form_state['multistep_values']['suggest_subject'] : array();

  $suggestion = isset($values['subject_hierarchy_suggestion']) ? $values['subject_hierarchy_suggestion'] : NULL;

  $header = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('header', 'confirmed-suggestion'),
    ),
  );

  $header['close'] = array(
    '#theme' => 'link',
    '#path' => '',
    '#text' => '&nbsp;',
    '#options' => array(
      'attributes' => array(
        'class' => array('subjects-close-button close icon icon-blue-x'),
      ),
      'html' => TRUE,
    ),
  );

  $header['headline'] = array(
    '#theme' => 'html_tag',
    '#tag' => 'h1',
    '#value' => t('HEADER_HIERARCHY_CONFIRMED_SUGGESTION', array(), array('context' => 'bibdk_subject_hierarchy') ),
  );

  $header['suggestion_text'] = array(
    '#theme' => 'html_tag',
    '#tag' => 'h2',
    '#value' => t('TEXT_HIERARCHY_CONFIRMED_SUGGESTION', array(), array('context' => 'bibdk_subject_hierarchy') ),
  );

  $form['bibdk_subject_hierarchy_suggestionresults'] = array(
    'header' => $header,
  );

  return $form;

}



function bibdk_subject_hierarchy_suggestion_form_validate($form, &$form_state) {
     
  $placeholder = t("PLACEHOLDER_HIERARCHY_SEND_SUGGESTION", array(), array('context' => 'bibdk_subject_hierarchy') );
  switch ($form_state['stage']) { 
       
    case 'suggest_subject':
      $suggestion = isset($form_state['values']['subject_hierarchy_suggestion']) ? $form_state['values']['subject_hierarchy_suggestion'] : NULL;
      if ( empty($suggestion) || $suggestion == $placeholder ) {
        form_set_error('subject_hierarchy_suggestion', t('suggestion cant be empty'));
      }
      $form_state['values']['subject_hierarchy_suggestion'] = check_plain($suggestion);
      break;  
  
  }
  
  return;

}



function bibdk_subject_hierarchy_suggestion_move_to_next_stage($form, &$form_state) {
 
  switch ( $form_state['stage'] ) {
    case 'suggest_subject':
      return 'is_confirmed';
      break;
  }
 
}



/** Subject hierarchy suggestion form submit method
 *
 *  * @return array
 */
function bibdk_subject_hierarchy_suggestion_form_submit($form, &$form_state) {
   
  switch ( $form_state['stage'] ) {
     
    case 'is_confirmed':
      $form_state['multistep_values'][$form_state['stage']] = $form_state['values'];
      $suggestion = check_plain($form_state['values']['subject_hierarchy_suggestion']);
      $to = variable_get('bibdk_subject_hierarchy_email_to', NULL);
      $from = variable_get('bibdk_subject_hierarchy_email_from', NULL);
      if ( $to ) {
        drupal_mail('bibdk_subject_hierarchy', 'suggestion', $to, language_default(), $params = array('!suggestion' => $suggestion), $from);
      }
     break;
  
    default:
      $form_state['multistep_values'][$form_state['stage']] = $form_state['values'];
      $form_state['new_stage'] = bibdk_subject_hierarchy_suggestion_move_to_next_stage($form, $form_state);
     break;
  
  }
 
  if ( isset($form_state['multistep_values']['form_build_id']) ) {
    $form_state['values']['form_build_id'] = $form_state['multistep_values']['form_build_id'];
  }

  $form_state['multistep_values']['form_build_id'] = $form_state['values']['form_build_id'];
  $form_state['stage'] = $form_state['new_stage'];
  $form_state['rebuild'] = TRUE;

  $suggestion_form = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => array('bibdk-subject-hierarchy-searchresult'),
      'class' => array('bibdk-subject-hierarchy-searchresult', 'subjects-sublists'),
    ),
    'suggestion_form' => $form,
  );

  return drupal_render($suggestion_form);     

}


function bibdk_subject_hierarchy_mail($key, &$message, $params) {

  switch ( $key ) {
    case 'suggestion':
      $langcode = $message['language']->language;
      $message['subject'] = t('EMAIL_SUBJECT_HIERARCHY_SUGGESTION', array(), array('langcode' => $langcode, 'context' => 'bibdk_subject_hierarchy'));
      $message['body'][] = t("EMAIL_BODY_HIERARCHY_SUGGESTION\n\n!suggestion", $params, array('langcode' => $langcode, 'context' => 'bibdk_subject_hierarchy') );
      break;
  }

}
