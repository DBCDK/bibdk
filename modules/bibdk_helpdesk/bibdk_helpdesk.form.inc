<?php

/**
 * @file
 * Library helpdesk form
 */

/**
 * Implements hook_form().
 */
function bibdk_helpdesk_form() {
  $logo = array(
    '#theme' => 'image',
    '#path' => drupal_get_path('module', 'bibdk_helpdesk') . '/images/logo/bvagt_logo.jpg',
    '#alt' => t('Helpdesk logo', array(), array('context' => 'bibdk_helpdesk')),
  );

  $form['logo'] = array(
    '#type' => 'link',
    '#title' => drupal_render($logo), // has to be rendered here because link theming won't
    '#href' => 'http://biblioteksvagten.dk',
    '#options' => array(
      'attributes' => array(
        'target' => '_blank',
      ),
      'html' => TRUE,
    ),
    '#weight' => -5,
  );

  // Fields related to the question
  $form['question'] = array(
    '#type' => 'fieldset',
    '#tree' => FALSE,
    '#attributes' => array(),
  );
  $form['question']['questionDeadline'] = array(
    '#type' => 'select',
    '#title' => t('Time limit'),
    '#description' => t('Select the time limit of your question'),
    '#options' => array(
      -1 => t('No time limit'),
      2 => "2 " . t('Hours'),
      8 => "8 " . t('Hours'),
      24 => "24 " . t('Hours'),
      48 => "2 " . t('Days'),
      168 => "1 " . t('Week')
    ),
    '#default_value' => '',
  );

  $form['question']['questionContent'] = array(
    '#type' => 'textarea',
    '#title' => t('My question is'),
    '#default_value' => '',
    '#required' => TRUE
  );
  $form['question']['questionUsage'] = array(
    "#type" => "fieldset",
    "#after_build" => array("_remove_validation"),
    "#attributes" => array(
      'class' => array('fieldset-notitle'),
    ),
  );
  $form['question']['questionUsage'][] = array(
    '#type' => 'radios',
    '#title' => t('The information will be used for'),
    '#options' => array(
      'personal' => t('General interest / hobby'),
      'business' => t('Business'),
    ),
    '#parents' => array('questionUsage'),
    '#spawned' => TRUE,
  );
  $form['question']['questionUsage'][] = array(
    '#type' => 'radios',
    '#title' => t('or in connection with assignment for'),
    '#options' => array(
      'school1' => t('Primary school'),
      'school2' => t('Gymnasium, EUC, VUC, SOSU or other short-cycle higher education'),
      'school3' => t('Medium-cycle higher or higher education'),
      'school4' => t('University education or research'),
    ),
    '#spawned' => TRUE,
    '#parents' => array('questionUsage'),
  );

  // Fields related to the user

  $form['user'] = array(
    '#type' => 'fieldset',
    '#tree' => FALSE,
  );
  $form['user']['userName'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#default_value' => '',
    '#required' => TRUE
  );
  $form['user']['userPostalCode'] = array(
    '#type' => 'textfield',
    '#title' => t('PostalCode'),
    '#default_value' => '',
    '#required' => TRUE
  );
  $form['user']['userEmail'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#default_value' => '',
    '#required' => TRUE
  );
  $form['user']['userMobilePhone'] = array(
    '#type' => 'textfield',
    '#title' => t('Phone'),
    '#default_value' => '',
    '#required' => FALSE
  );

  // Submit
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Send'),
  );

  return $form;
}


/**
 * Remove required validation from Purpose ID
 */
function _remove_validation($element) {
  _bibdk_helpdesk_disable_validation($element);
  return $element;
}


/*
 * Recursive function.
 * Removes required validation flag for specified form element and all its children.
 */
function _bibdk_helpdesk_disable_validation(&$element) {
  unset($element['#needs_validation']);
  foreach (element_children($element) as $key) {
    _bibdk_helpdesk_disable_validation($element[$key]);
  }
}


/**
 * Validate helpdesk form submission.
 */
function bibdk_helpdesk_form_validate($form, &$form_state) {
  if (!valid_email_address($form_state['values']['userEmail'])) {
    form_set_error("CustomerEmail", t('Email needs to be a valid email', array(), array('context' => 'bibdk_helpdesk:error')));
  }
  if (!isset($form_state['values']['questionUsage'])) {
    form_set_error("questionUsage", t('Please state a purpose', array(), array('context' => 'bibdk_helpdesk:error')));
  }
}


/**
 * Process helpdesk form submission.
 */
function bibdk_helpdesk_form_submit($form, &$form_state) {
  form_state_values_clean($form_state);
  $values = $form_state['values'];

  if ($values['questionUsage'] == 'school3' || $values['questionUsage'] == 'school4'){
    $values['editorial'] = 'Forskningsbibliotek';
  }
  else {
    $values['editorial'] = 'Folkebibliotek';
  }

  $response = bibdk_helpdesk_request($values);

  if (isset($response->createQuestionResponse->questionReceipt->{'$'}) && $response->createQuestionResponse->questionReceipt->{'$'} == 'Ack'){
    drupal_goto('overlay/helpdesk/receipt');
  }
  else {
    drupal_set_message(t('drupal_bibdk_helpdesk_question_not_acknowledged'), 'error');
    watchdog('submit', 'ERROR: cannot submit to helpdesk: @error', array('@error' => print_r($response, FALSE)), WATCHDOG_ERROR);
  }

}
