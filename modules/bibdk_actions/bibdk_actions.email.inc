<?php

/**
 * Defines the link for
 *
 * @param array $actions
 * @return array
 */
function bibdk_actions_get_email_actions($actions) {
  $actions['email'] = array(
    '#action_type' => 'primary',
    '#theme' => 'link',
    '#text' => t('email_manifestation', array(), array('context' => 'bibdk_actions')),
    '#path' => 'email/cart',
    '#weight' => 0,
    '#options' => array(
      'query' => NULL,
      'attributes' => array(
        'class' => array(
          'cart-action-btn', 'inactive', 'cart-popup',
        ),
      ),
      'html' => FALSE,
    ),
  );
  return $actions;
}


/**
 * Callback function when user clicks email button in cart view
 *
 * @param $ids
 * @param bool $sent
 * @return bool|string
 */
function bibdk_actions_email_page($ids, $sent = FALSE) {
  if (empty($ids)) {
    return FALSE;
  }
  $idsstring = $ids;
  $pids = preg_replace('@;@', ',', $ids);
  $pids = explode(',', $pids);
  $manifestations = bibdk_actions_get_manifestations($pids);
  $title = '';
  $content = array();
  if (isset($manifestations)) {
    foreach ($manifestations as $manifestation) {
      $view = ting_openformat_manifestation_view($manifestation, 'email');
      $view['display'] = bibdk_actions_get_fieldinfo($view);
      $view['#theme'] = 'bibdk_actions_email';
      $content[]['#markup'] = theme('bibdk_actions_email', array('strings' => $view['display']));
      if (empty($title)) {
        $title = $manifestation->getTitleSpecific();
      }
    }
    $form_values['content'] = $content;
    $form_values['title'] = $title;
    $form_values['ids'] = $ids;
    $form_values['sent'] = $sent;
    $form_values['idsstring'] = $idsstring;
    $mail_form = drupal_get_form('bibdk_actions_mail_form', $form_values);
  }
  else {
    $mail_form = t('no_elements_to_be_emailed', array(), array('context' => 'bibdk_actions'));
  }
  return $mail_form;
}


/**
 * @param $view
 * @return array
 */
function bibdk_actions_get_fieldinfo($view) {
  $display_strings = array();
  if (isset($view['#fields']) && is_array($view['#fields'])) {
    foreach ($view['#fields'] as $key => $field) {
      if (!$title = !empty($field['#title']) ? $field['#title'] : false) {
        continue;
      }
      $weight = !empty($field['#weight']) ? $field['#weight'] : false;
      $field_content = null;
      _bibdk_actions_recurse_fieldinfo($field, $field_content);
      $display_strings[$weight] = t($title) . ': ' . $field_content;
    }
  }
  ksort($display_strings);
  return $display_strings;
}

/** Recurse fields for strings.
 * @param $field
 * @param $display_string
 */
function _bibdk_actions_recurse_fieldinfo($field, &$display_string) {
  foreach ($field as $key => $value) {
    if (is_array($value)) {
      if (strpos('#', $key) === true) {
         continue;
      }
      if (!empty($value['#openformat_field']['#markup'])) {
        $display_string .= $value['#openformat_field']['#markup'];
      }
      else if (!empty($value['#openformat_field']['#text'])) {
        $display_string .= $value['#openformat_field']['#text'];
      }
      else if (!empty($value['#markup'])) {
        $display_string .= $value['#markup'];
      }
      else {
        _bibdk_actions_recurse_fieldinfo($value, $display_string);
      }
    }
  }
}

/**
 * Creates the bibdk_actions_mail_form form
 *
 * @param $form_id
 * @param $form_state
 * @internal param $form
 * @return mixed
 */
function bibdk_actions_mail_form($form_id, &$form_state) {
  global $user;
  $form['recipient'] = array(
    '#type' => 'textarea',
    '#title' => t('recipients_email_adress', array(), array('context' => 'bibdk_actions')),
    '#default_value' => ($user->uid != 0) ? $user->mail : '',
    '#required' => TRUE,
  );
  $subject_intro = t('manifestations_from @site-name', array('@site-name' => variable_get('site_name', t('email_site_name', array(), array('context' => 'bibdk_actions')))));
  $subject_title = (isset($form_state['build_info']['args'][0]['title'])) ? ' - ' . $form_state['build_info']['args'][0]['title'] : '';
  $subject_more = (count($form_state['build_info']['args'][0]['content']) >= 2) ? ' - ' . t('and_other_titles', array(), array('context' => 'bibdk_actions')) : '';
  $subject = _bibdk_actions_shorten_subject($subject_intro, $subject_title, $subject_more);
  $form['subject'] = array(
    '#type' => 'textarea',
    '#title' => t('email_subject', array(), array('context' => 'bibdk_actions')),
    '#default_value' => $subject,
    '#required' => FALSE,
  );
  $form['note'] = array(
    '#type' => 'textarea',
    '#title' => t('note_for_recipient', array(), array('context' => 'bibdk_actions')),
    '#required' => FALSE,
  );
  $form['send'] = array(
    '#type' => 'submit',
    '#submit' => array('bibdk_actions_mail_form_submit'),
    '#value' => t('send_email', array(), array('context' => 'bibdk_actions')),
  );
  $form['close'] = array(
    '#type' => 'button',
    '#value' => t('close_window', array(), array('context' => 'bibdk_actions')),
    '#attributes' => array(
      'onClick' => array('window.close();'),
      'class' => array(
        'inactive', 'show-for-medium-up',
      ),
    ),
  );
  if($form_state['build_info']['args'][0]['sent']){
    drupal_add_js(drupal_get_path('module', 'bibdk_cart') . '/js/bibdk_cart_reload.js');
  }
  return $form;
}


/**
 * if subjectfield is going to be more than tha maximum allowed 128 chars we will shorten the title
 *
 * @param $subject_intro
 * @param $subject_title
 * @param $subject_more
 * @return string
 */
function _bibdk_actions_shorten_subject($subject_intro, $subject_title, $subject_more) {
  if ((drupal_strlen($subject_intro) + drupal_strlen($subject_title) + drupal_strlen($subject_more)) > 128) {
    $length = (128 - (drupal_strlen($subject_intro) + drupal_strlen($subject_more) + 3));
    $subject_title = drupal_substr($subject_title, 0, $length) . '...';
  }
  return $subject_intro . $subject_title . $subject_more;
}


/**
 * Validates form elements in bibdk_actions_mail_form
 *
 * @param $form
 * @param $form_state
 */
function bibdk_actions_mail_form_validate($form, &$form_state) {
  if (!isset($form_state['values']['recipient']) || !valid_email_address($form_state['values']['recipient'])) {
    $error_msg = t('email_adress_not_formatted_properly', array(), array('context' => 'bibdk_actions'));
    form_set_error('recipient', $error_msg);
  }
}


/**
 * @param $form_id
 * @param $form_state
 */
function bibdk_actions_mail_form_submit($form_id, &$form_state) {
  $params['manifestations'] = $form_state['build_info']['args'][0]['content'];
  $params['subject'] = $form_state['values']['subject'];
  $params['note'] = $form_state['values']['note'];
  $params['recipient'] = $form_state['values']['recipient'];
  bibdk_actions_mail_send($params);
  $ids = $form_state['build_info']['args'][0]['ids'];
  $ids = explode(';', $ids);
  foreach($ids as $id){
    bibdk_cart_reservation_update_status('email_complete', $id);
  }
  drupal_goto('email/cart/'.$form_state['build_info']['args'][0]['idsstring'].'/1');
}


/**
 * @param $params
 * @internal param $form_values
 * @internal param $manifestations
 */
function bibdk_actions_mail_send($params) {
  $module = 'bibdk_actions';
  $key = 'mail_cart_items';
  $to = $params['recipient'];
  global $language;
  $from = variable_get('bibdk_actions_email_sender_adress', 'noreply@bibliotek.dk');
  $send = TRUE;
  $result = drupal_mail($module, $key, $to, $language, $params, $from, $send);
  if ($result['result'] == TRUE) {
    drupal_set_message(t('Your message has been sent.'));
  }
  else {
    drupal_set_message(t('There was a problem sending your message and it was not sent.'), 'error');
  }
}


/**
 * Implements hook_mail().
 */
function bibdk_actions_mail($key, &$message, $params) {
  switch ($key) {
    case 'mail_cart_items':
      $header = variable_get('bibdk_actions_email_header', '');
      $footer = variable_get('bibdk_actions_email_footer', '');
      $message['subject'] = $params['subject'];
      $message['body'][] = !empty($header) ? t($header, array(), array('context' => 'bibdk_action')) : '';
      $message['body'][] = $params['note'];
      $message['body'][] = drupal_render($params['manifestations']);
      $message['body'][] = !empty($footer) ? t($footer, array(), array('context' => 'bibdk_action')) : '';
      break;
  }
}
