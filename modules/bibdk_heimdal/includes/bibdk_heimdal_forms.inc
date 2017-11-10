<?php
module_load_include('inc', 'bibdk_heimdal', 'includes/heimdalDatabase');

//function bibdk_heimdal_

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
        '#value' => 'Ok'
      ),
      'cancel_but' => array(
        '#type' => 'submit',
        '#value' => t('cancel', array(), array('context' => 'heimdal'))
      ),
    ),
    '#validate' => array('bibdk_heimdal_verify_email_validate')
  );

  return $form;
}

function bibdk_heimdal_forms_add_email_write_js() {
  $path = drupal_get_path('module', 'bibdk_heimdal');
  drupal_add_js($path . '/js/bibdk_heimdal_email_write.js');
}

function bibdk_heimdal_forms_add_email_select_js(){
  $path = drupal_get_path('module', 'bibdk_heimdal');
  drupal_add_js($path . '/js/bibdk_heimdal_email_write.js');
}

function bibdk_heimdal_verify_email_validate($form, $form_state){
  $email = $form_state['values']['mail'];
  if( !BibdkUser::instance()->verify($email)){
    // user does not exist - create
    // make a random password
    $pass = user_password();
    bibdk_provider_user_create_account($email, $pass);
  }
}

function bibdk_heimdal_verify_email_form_submit($form, $form_state){
  $mail = $form_state['values']['mail'];
  $agencies = bibdkHeimdalUser::getLibraries();
  // save on database before sending email
  $key = heimdalDatabase::insert($mail, $agencies);
  $row = heimdalDatabase::get($key);
  if(!empty($row)){
    bibdk_heimdal_send_verification_mail($row);
  }
  else{
    // @TODO .. no libraries was given from heimdal - do something
    drupal_set_message('NO LIBRARIES FROM CULR', 'error');
  }
  // an email has been send or row was empty - either way start from scratch
  unset($_SESSION['heimdal']);
  drupal_set_message(t('an_email_has_been_sent_help_txt', array(), array('context'=>'heimdal')));
  drupal_goto('<front>');
}


function bibdk_heimdal_send_verification_mail(array $row){
  $message = drupal_mail('bibdk_heimdal', 'bibdk_heimdal_verify_mail', $row['email'], 'da', $row);
}
/**
 * Implements hook mail
 *
 * Set email text for user
 **/
function bibdk_heimdal_mail($key, &$message, $params){
  if($key !== 'bibdk_heimdal_verify_mail'){
    return;
  }
  $message['subject'] = t('bibdk_verify_email_helptxt', array(), array('context' => 'heimdal'));
  $message['body'][] = t('bibdk_click_this_link_txt', array(), array('context'=>'heimdal'));
  $message['body'][] = bibdk_heimdal_get_verification_link($params['uuid']);
}

function bibdk_heimdal_get_verification_link($uuid){
  $verification_link = array(
    /*'#type'  => 'link',
    '#title' => 'fisk',
    '#href'  => 'heimdal/email/?uuid='.$uuid,
    '#options' => array(
      'absolute' => TRUE,
      'attributes' => array(),
    ),*/
    '#theme' => 'link',
    '#text' => 'fisk',
    '#path' => 'heimdal/loginrequest/' . $uuid,
    '#options' => array(
      'absolute' => TRUE,
      'html' => TRUE,
      'attributes' => array(),
    ),
  );
  $link = drupal_render($verification_link);

  return $link;
}

function bibdk_heimdal_select_email_form($form, $form_state){
  $options = isset($_SESSION['heimdal']['select_from_emails']) ?
    $_SESSION['heimdal']['select_from_emails'] : array();
  $form = array(
    'help'=> array(
      '#type' => 'html_tag',
      '#tag' => 'div',
      '#attributes' => array(
        'class'=>array(
          'heimdal_email_verify'
        )
      ),
      '#value' => t('Select_an_email_helptext', array(), array('context'=>'heimdal')),
    ),
    'select' => array(
      '#type' => 'select',
      '#options' => $options,
    ),
    'submit_but' => array(
      '#type' => 'submit',
      '#value' => 'Ok'
    ),
    'cancel_but' => array(
      '#type'=>'submit',
      '#value'=>t('cancel', array(), array('context'=>'heimdal'))
    ),
  );

  return $form;
}

function bibdk_heimdal_select_email_form_submit($form, &$form_state){
  $index = $form_state['values']['select'];
  $email = $_SESSION['heimdal']['select_from_emails'][$index];

  // @TODO datacheck on email var

  // @TODO use COOKIE in production NOT SESSION
  $_SESSION['heimdal']['selected_email'] = $email;
  // also set a cookie - for production
  user_cookie_save(array('user_selected_email' => $email));

  unset($_SESSION['heimdal']['select_from_emails']);
  drupal_goto('heimdal/login');
}
