<?php
// load form definitions - we need to include them here for fetching by ajax
module_load_include('inc', 'bibdk_heimdal', 'includes/heimdalDatabase');

/**
 * Define a form for writing an email address
 * @param $form
 * @param $form_state
 * @return array
 */
function bibdk_heimdal_verify_email_form($form, $form_state) {
  $form = array(
    'help' => array(
      '#type' => 'html_tag',
      '#tag' => 'p',
      '#attributes' => array(
        'class' => array(
          'heimdal_email_verify'
        )
      ),
      '#value' => t('bibdk_needs_an_email_helptext', array(), array('context' => 'heimdal')),
    ),
    'mail' => array(
      '#type' => 'emailfield',
      '#required' => TRUE,
    ),
    'actions' => array(
      'submit_but' => array(
        '#type' => 'submit',
        '#name' => 'ok',
        '#value' => 'Ok'
      ),
      'cancel_but' => array(
        '#type' => 'submit',
        '#name' => 'cancel',
        '#value' => t('cancel', array(), array('context' => 'heimdal'))
      ),
    ),
    '#validate' => array('bibdk_heimdal_verify_email_validate')
  );

  return $form;
}

/**
 * Add javascript for user to input an email address
 */
function bibdk_heimdal_forms_add_email_write_js() {
  $path = drupal_get_path('module', 'bibdk_heimdal');
  drupal_add_js($path . '/js/bibdk_heimdal_email_write.js');
}

/**
 * Add javascript for selecting which email to use
 */
function bibdk_heimdal_forms_add_email_select_js() {
  $path = drupal_get_path('module', 'bibdk_heimdal');
  drupal_add_js($path . '/js/bibdk_heimdal_email_select.js');
}

/**
 * Custom validating for verify_email_form
 * @param $form
 * @param $form_state
 */
function bibdk_heimdal_verify_email_validate($form, &$form_state) {
  $action = $form_state['clicked_button']['#name'];
  if ($action == 'cancel') {
    bibdk_heimdal_cleanup_and_exit();
  }
  $email = $form_state['values']['mail'];
  if (!valid_email_address($email)) {
    form_set_error('mail', t('Please enter a valid email address', array(), array('context' => 'heimdal')));
  }
}

/**
 * Submit function form verify_email_form
 * @param $form
 * @param $form_state
 */
function bibdk_heimdal_verify_email_form_submit($form, &$form_state) {
  $mail = $form_state['values']['mail'];
  $agencies = bibdkHeimdalUser::getLibraries();
  // save on database before sending email
  $key = heimdalDatabase::insert($mail, $agencies);
  if($key === FALSE){
    bibdk_heimdal_cleanup_and_exit();
  }

  $row = heimdalDatabase::get($key);
  if (!empty($row)) {
    bibdk_heimdal_send_verification_mail($row);
  }
  else {
    bibdk_heimdal_cleanup_and_exit();
  }
  // an email has been sent - start from scratch
  unset($_SESSION['heimdal']);
  drupal_set_message(t('an_email_has_been_sent_help_txt', array(), array('context' => 'heimdal')));
}


/**
 * Send an email
 * @param array $row
 *   A row from verification table
 */

function bibdk_heimdal_send_verification_mail(array $row) {
  $message = drupal_mail('bibdk_heimdal', 'bibdk_heimdal_verify_mail', $row['email'], 'da', $row);
}

/**
 * Implements hook mail
 *
 * Set email text for user
 **/
function bibdk_heimdal_mail($key, &$message, $params) {
  if ($key !== 'bibdk_heimdal_verify_mail') {
    return;
  }
  $message['subject'] = t('bibdk_verify_email_helptxt', array(), array('context' => 'heimdal'));
  $message['body'][] = t('bibdk_click_this_link_txt', array(), array('context' => 'heimdal'));
  $message['body'][] = bibdk_heimdal_get_verification_link($params['uuid']);
}

function bibdk_heimdal_get_verification_link($uuid) {
  $verification_link = array(
    '#theme' => 'link',
    '#text' => 'fisk',
    '#path' => 'heimdal/loginrequest/' . $uuid,
    '#options' => array(
      'absolute' => TRUE,
      'html' => TRUE,
      'attributes' => array(),
    ),
  );
  return drupal_render($verification_link);
}

/**
 * Define a form for selecting between more emails
 * @param $form
 * @param $form_state
 * @return array
 *   Rnder array for drupal to render
 */

function bibdk_heimdal_select_email_form($form, $form_state) {
  $options = isset($_SESSION['heimdal']['select_from_emails']) ?
    $_SESSION['heimdal']['select_from_emails'] : array();
  $form = array(
    'help' => array(
      '#type' => 'html_tag',
      '#tag' => 'p',
      '#attributes' => array(
        'class' => array(
          'heimdal_email_verify'
        )
      ),
      '#value' => t('Select_an_email_helptext', array(), array('context' => 'heimdal')),
    ),
    'select' => array(
      '#type' => 'select',
      '#options' => $options,
    ),
    'submit_but' => array(
      '#name' => 'ok',
      '#type' => 'submit',
      '#value' => 'Ok'
    ),
    'cancel_but' => array(
      '#name' => 'cancel',
      '#type' => 'submit',
      '#value' => t('cancel', array(), array('context' => 'heimdal'))
    ),
  );

  return $form;
}

/**
 * Submit function for select_email_form
 * @param $form
 * @param $form_state
 */
function bibdk_heimdal_select_email_form_submit($form, &$form_state) {
  $action = $form_state['clicked_button']['#name'];
  if ($action == 'cancel') {
    bibdk_heimdal_cleanup_and_exit();
  }

  $index = $form_state['values']['select'];
  $email = $_SESSION['heimdal']['select_from_emails'][$index];

  // @TODO use COOKIE in production NOT SESSION
  $_SESSION['heimdal']['selected_email'] = $email;
  // also set a cookie - for production
  user_cookie_save(array('user_selected_email' => $email));
  drupal_goto('heimdal/login');
}
