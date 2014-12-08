<?php

/** Method to handle direct access to page (not via link on review)
 * @return array
 */
function bibdk_voxb_offensive_error() {
  return array(
    '#markup' => t('bibdk_voxb_no_access', array(), array('context'=>'bibdk_voxb')),
  );
}

/** Get a link to report offensive content
 * @param $voxb_id
 * @return array
 */
function bibdk_voxb_offensive_link($voxb_id) {
  if (!ding_user_is_provider_user()) {
    $form['login'] = bibdk_voxb_link_to_login();
    return $form;
  }

  $path = 'voxb/offensive';
  $text = t('bibdk_voxb_offensive_content', array(), array('context' => 'bibdk_voxb'));
  $link = array(
    '#theme' => 'link',
    '#text' => $text,
    '#path' => $path,
    '#options' => array(
      'attributes' => array(
        'id' => 'bibdk-offensive-'.$voxb_id,
        'class'=>array('bibdk-voxb-offensive-link'),
      ),
      'html' => TRUE,
      'query'=>array('voxb_id'=>$voxb_id),

    ),
  );
  return $link;
}

function bibdk_voxb_offensive_test_form($form, $form_state) {
  return array(
    'HEST'=>array('#markup'=>'TESTHEST'),
    'HUND'=> array(
      '#type'=>'button',
      '#value'=>'TESTHEST',
    )
  );
}

function bibdk_voxb_offensive_form($form, $form_state) {

 // return bibdk_voxb_offensive_test_form($form, $form_state);

  $voxb_id = isset ($_GET['voxb_id']) ? $_GET['voxb_id'] : NULL;
  if (empty($voxb_id)) {
    return bibdk_voxb_offensive_error();
  }
  $form['wrapper'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('container'),
    ),
    '#weight' => 20,
  );

  $form['#voxb_id'] = array(
    '#type' => 'hidden',
    '#value' => $voxb_id,
  );

  $form['wrapper']['button'] = array(
    '#type' => 'submit',
    '#value' => t('bibdk_voxb_offensive_submit', array(), array('context'=>'bibdk_voxb')),
  );

  $form['#submit'] = array('bibdk_voxb_offensive_submit');

  return $form;
}


function bibdk_voxb_form_error(&$form, $message){
  $message = t($message, array(), array('context'=>'bibdk_voxb'));
  form_set_error('form', $message);
}

function bibdk_voxb_offensive_submit ($form, $form_state) {
  // userid and voxb_id are mandatory
  $userId = bibdk_voxb_user_check();
  $voxb_id = $form['#voxb_id']['#value'];


  if (empty($userId) || empty($voxb_id)) {
    $message = t('bibdk_voxb_failed_to_report', array(), array('context'=>'bibdk_voxb'));
    bibdk_voxb_form_error($form, $message);
    return;
  }

  $response = open_voxb_reportOffensiveContent ($userId, $voxb_id);
  // ting_client returns FALSE on errors
  if ($response === FALSE) {
    $message = t('bibdk_voxb_failed_to_report', array(), array('context'=>'bibdk_voxb'));
    bibdk_voxb_form_error($form, $message);
    return;
  }
  $message = t('bibdk_offensive_content_reported', array(), array('context' => 'bibdk_voxb'));
  drupal_set_message($message);
}