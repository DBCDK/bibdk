<?php


function bibdk_form_callback_all_element_types($form, &$form_state) {

  drupal_set_title('');

  //This is not for production! Grid is controlled in page.tpl
  $form['#prefix'] = '<div class="row"><div class="span19 offset5"><div class="element-wrapper"><div class="element">';
  $form['#suffix'] = '</div></div></div></div>';


  // Regular field
  $form['text'] = array(
    '#type' => 'textfield',
    '#title' => t('Regular text field'),
    '#description' => t('This is the description of the text field'),
    '#default_value' => t('This is the default value'),
    '#prefix' => '<div class="form-wrapper">',
  );

  // Required field
  $form['text_required'] = array(
    '#type' => 'textfield',
    '#title' => t('Required text field'),
    '#description' => t("#required' => TRUE'"),
    '#required' => TRUE,
    '#default_value' => t('This is the default value'),
  );

  // Disabled field
  $form['text_disabled'] = array(
    '#type' => 'textfield',
    '#title' => t('Disabled text field'),
    '#description' => t("#disabled' => TRUE'"),
    '#disabled' => TRUE,
    '#default_value' => t('This is the default value'),
    '#suffix' => '</div>',
  );

  $form['text_100'] = array(
    '#type' => 'textfield',
    '#title' => t('100% text field'),
    '#description' => t("#attributes' => array('class => array('input-100'))"),
    '#default_value' => t('This is the default value'),
    '#attributes' => array(
      'class' => array('input-100'),
    ),
    '#prefix' => '<div class="form-wrapper">',
  );

  $form['text_80'] = array(
    '#type' => 'textfield',
    '#title' => t('80% text field'),
    '#description' => t("#attributes' => array('class => array('input-80'))"),
    '#default_value' => t('This is the default value'),
    '#attributes' => array(
      'class' => array('input-80'),
    ),
  );
  $form['text_60'] = array(
    '#type' => 'textfield',
    '#title' => t('60% text field'),
    '#description' => t("#attributes' => array('class => array('input-60'))"),
    '#default_value' => t('This is the default value'),
    '#attributes' => array(
      'class' => array('input-60'),
    ),
  );
  $form['text_40'] = array(
    '#type' => 'textfield',
    '#title' => t('40% text field'),
    '#description' => t("#attributes' => array('class => array('input-40'))"),
    '#default_value' => t('This is the default value'),
    '#attributes' => array(
      'class' => array('input-40'),
    ),
  );
  $form['text_20'] = array(
    '#type' => 'textfield',
    '#title' => t('20% text field'),
    '#description' => t("#attributes' => array('class => array('input-20'))"),
    '#default_value' => t('This is the default value'),
    '#attributes' => array(
      'class' => array('input-20'),
    ),
    '#suffix' => '</div>',
  );

  // Password
  $form['password'] = array(
    '#type' => 'password',
    '#title' => t('Password'),
    '#description' => t('This is the description of the password field'),
    '#prefix' => '<div class="form-wrapper">',
  );

  // Password + confirm
  $form['password_confirm'] = array(
    '#type' => 'password_confirm',
    '#title' => t('Password with confirm'),
    '#description' => t('This is the description of the password confirm field'),
    '#suffix' => '</div>',
  );

  // Text area
  $form['textarea'] = array(
    '#title' => t('This is a text area'),
    '#type' => 'textarea',
    '#description' => t('This is the description of the text area'),
    '#default_value' => t('This is the default value'),
    '#prefix' => '<div class="form-wrapper">',
    '#suffix' => '</div>',
  );

  // Date field
  $form['date'] = array(
    '#type' => 'date',
    '#title' => t('This is a date field'),
    '#description' => t('This is the description of the date field'),
    '#prefix' => '<div class="form-wrapper">',
    '#suffix' => '</div>',
  );

  // Single checkbox
  $form['checkbox'] = array(
    '#type' => 'checkbox',
    '#title' => t('Single checkbox'),
    '#description' => t('This is the description of the checkbox'),
    '#prefix' => '<div class="form-wrapper">',
  );

  // Multiple checkboxes
  $form['checkboxes'] = array(
    '#type' => 'checkboxes',
    '#options' => drupal_map_assoc(array(t('Option 1'), t('Option 2'))),
    '#title' => t('Multiple checkboxes'),
    '#description' => t('This is the description of the checkboxes'),
    '#suffix' => '</div>',
  );

  // Single radio
  $form['radio'] = array(
    '#type' => 'radio',
    '#title' => t('Single radiobutton'),
    '#description' => t('This is the description of the radio'),
    '#prefix' => '<div class="form-wrapper">',
  );

  // Multiple radios
  $form['radios'] = array(
    '#type' => 'radios',
    '#options' => drupal_map_assoc(array(t('Option 1'), t('Option 2'))),
    '#title' => t('Multiple radiobuttons'),
    '#description' => t('This is the description of the radios'),
    '#suffix' => '</div>',
  );


  // Select
  $form['select'] = array(
    '#type' => 'select',
    '#title' => t('This is a select'),
    '#description' => t('This is the description of the select'),
    '#prefix' => '<div class="form-wrapper">',
    '#suffix' => '</div>',
    '#options' => array(
      0 => t('Option 1'),
      1 => t('Option 2'),
      2 => t('Option 3'),
      3 => t('Option 4'),
      4 => t('Option 5'),
      5 => t('Option 6'),
    ),
  );

  // Upload
  $form['upload'] = array(
    '#type' => 'file',
    '#title' => t('Choose a file'),
    '#description' => t('This is the description of the upload field'),
    '#size' => 22,
    '#prefix' => '<div class="form-wrapper">',
    '#suffix' => '</div>',
  );


  // Fieldset
  $form['fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('This is a fieldset'),
  );
  $form['fieldset']['checkboxes'] = array(
    '#type' => 'checkboxes',
    '#options' => drupal_map_assoc(array(t('Option 1'), t('Option 2'))),
    '#title' => t('This is the checkboxes title'),
  );
  $form['fieldset']['text1'] = array(
    '#type' => 'textfield',
    '#title' => t('Text field'),
    '#description' => t('This is the description of the text field'),
    '#default_value' => t('This is the default value'),
  );
  $form['fieldset']['text2'] = array(
    '#type' => 'textfield',
    '#title' => t('Text field'),
    '#description' => t('This is the description of the text field'),
    '#default_value' => t('This is the default value'),
  );

  // Fieldset collapsable
  $form['fieldset_collapsible'] = array(
    '#type' => 'fieldset',
    '#title' => t('This is a collapsible fieldset'),
    '#collapsible' => TRUE,
  );
  $form['fieldset_collapsible']['checkboxes'] = array(
    '#type' => 'checkboxes',
    '#options' => drupal_map_assoc(array(t('Option 1'), t('Option 2'))),
    '#title' => t('This is the checkboxes title'),
  );
  $form['fieldset_collapsible']['text1'] = array(
    '#type' => 'textfield',
    '#title' => t('Text field'),
    '#description' => t('This is the description of the text field'),
    '#default_value' => t('This is the default value'),
  );
  $form['fieldset_collapsible']['text2'] = array(
    '#type' => 'textfield',
    '#title' => t('Text field'),
    '#description' => t('This is the description of the text field'),
    '#default_value' => t('This is the default value'),
  );

  // Fieldset collapsed
  $form['fieldset_collapsed'] = array(
    '#type' => 'fieldset',
    '#title' => t('This is a collapsed fieldset'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['fieldset_collapsed']['checkboxes'] = array(
    '#type' => 'checkboxes',
    '#options' => drupal_map_assoc(array(t('Option 1'), t('Option 2'))),
    '#title' => t('This is the checkboxes title'),
  );
  $form['fieldset_collapsed']['text1'] = array(
    '#type' => 'textfield',
    '#title' => t('Text field'),
    '#description' => t('This is the description of the text field'),
    '#default_value' => t('This is the default value'),
  );
  $form['fieldset_collapsed']['text2'] = array(
    '#type' => 'textfield',
    '#title' => t('Text field'),
    '#description' => t('This is the description of the text field'),
    '#default_value' => t('This is the default value'),
  );


  // Vertical tabs
  // #prefix and #suffix is required!
  $form['vertical_tabs'] = array(
    '#type' => 'vertical_tabs',
    '#default_tab' => 'edit-tab1',
    '#prefix' => '<div class="form-wrapper">',
    '#suffix' => '</div>',
   );
  $form['tab1'] = array(
    '#type' => 'fieldset',
    '#title' => t('Tab 1'),
    '#collapsible' => TRUE,
    '#group' => 'vertical_tabs',
  );
  $form['tab1']['field1'] = array(
    '#title' => t('Field 1'),
    '#type' => 'textfield',
  );
  $form['tab1']['field2'] = array(
    '#title' => t('Field 2'),
    '#type' => 'textfield',
  );
  $form['tab2'] = array(
    '#type' => 'fieldset',
    '#title' => t('Tab 2'),
    '#collapsible' => TRUE,
    '#group' => 'vertical_tabs',
    '#attributes' => array(
      'class' => array('form-wrapper-horizontal'),
    ),
  );
  $form['tab2']['field3'] = array(
    '#title' => t('Field 3'),
    '#type' => 'textfield',
  );
  $form['tab2']['field4'] = array(
    '#title' => t('Field 4'),
    '#type' => 'textfield',
  );


  // Submit buttons
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  $form['actions']['delete'] = array(
    '#type' => 'button',
    '#value' => t('Delete'),
    '#attributes' => array(
      'class' => array('btn-grey')
    ),
  );
  $form['actions']['cancel'] = array(
    '#markup' => l(t('Cancel'), 'foo/bar', array('attributes' => array('class' => 'form-cancel'))),
  );

  return $form;
}



function bibdk_form_callback_all_inline_element_types($form, &$form_state) {

  drupal_set_title('');

  //This is not for production! Grid is controlled in page.tpl
  $form['#prefix'] = '<div class="row"><div class="span19 offset5"><div class="element-wrapper"><div class="element">';
  $form['#suffix'] = '</div></div></div></div>';


  $form['text'] = array(
    '#type' => 'textfield',
    '#title' => t('Regular text field'),
    '#description' => t('This is the description of the text field'),
    '#default_value' => t('This is the default value'),
    '#prefix' => '<div class="form-wrapper form-wrapper-horizontal">',
  );

  $form['text_required'] = array(
    '#type' => 'textfield',
    '#title' => t('Required text field'),
    '#description' => t("#required' => TRUE'"),
    '#required' => TRUE,
    '#default_value' => t('This is the default value'),
  );

  $form['text_disabled'] = array(
    '#type' => 'textfield',
    '#title' => t('Disabled text field'),
    '#description' => t("#disabled' => TRUE'"),
    '#disabled' => TRUE,
    '#default_value' => t('This is the default value'),
    '#suffix' => '</div>',
  );

  // Password
  $form['password'] = array(
    '#type' => 'password',
    '#title' => t('Password'),
    '#description' => t('This is the description of the password field'),
    '#prefix' => '<div class="form-wrapper form-wrapper-horizontal">',
    '#suffix' => '</div>',
  );

  $form['textarea'] = array(
    '#title' => t('This is a text area'),
    '#type' => 'textarea',
    '#description' => t('This is the description of the text area'),
    '#default_value' => t('This is the default value'),
    '#prefix' => '<div class="form-wrapper form-wrapper-horizontal">',
    '#suffix' => '</div>',
  );

  // Date field
  $form['date'] = array(
    '#type' => 'date',
    '#title' => t('This is a date field'),
    '#description' => t('This is the description of the date field'),
    '#prefix' => '<div class="form-wrapper form-wrapper-horizontal">',
    '#suffix' => '</div>',
  );

  // Single checkbox
  $form['checkbox'] = array(
    '#type' => 'checkbox',
    '#title' => t('Single checkbox'),
    '#description' => t('This is the description of the checkbox'),
    '#prefix' => '<div class="form-wrapper form-wrapper-horizontal">',
  );

  // Multiple checkboxes
  $form['checkboxes'] = array(
    '#type' => 'checkboxes',
    '#options' => drupal_map_assoc(array(t('Option 1'), t('Option 2'))),
    '#title' => t('Multiple checkboxes'),
    '#description' => t('This is the description of the checkboxes'),
    '#suffix' => '</div>',
  );

  // Single radio
  $form['radio'] = array(
    '#type' => 'radio',
    '#title' => t('Single radiobutton'),
    '#description' => t('This is the description of the radio'),
    '#prefix' => '<div class="form-wrapper form-wrapper-horizontal">',
  );

  // Multiple radios
  $form['radios'] = array(
    '#type' => 'radios',
    '#options' => drupal_map_assoc(array(t('Option 1'), t('Option 2'))),
    '#title' => t('Multiple radiobuttons'),
    '#description' => t('This is the description of the radios'),
    '#suffix' => '</div>',
  );


  // Select
  $form['select'] = array(
    '#type' => 'select',
    '#title' => t('This is a select'),
    '#description' => t('This is the description of the select'),
    '#prefix' => '<div class="form-wrapper form-wrapper-horizontal">',
    '#suffix' => '</div>',
    '#options' => array(
      0 => t('Option 1'),
      1 => t('Option 2'),
      2 => t('Option 3'),
      3 => t('Option 4'),
      4 => t('Option 5'),
      5 => t('Option 6'),
    ),
  );

  // Upload
  $form['upload'] = array(
    '#type' => 'file',
    '#title' => t('Choose a file'),
    '#description' => t('This is the description of the upload field'),
    '#size' => 22,
    '#prefix' => '<div class="form-wrapper form-wrapper-horizontal">',
    '#suffix' => '</div>',
  );


  // Fieldset
  $form['fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('This is a fieldset'),
    '#attributes' => array(
      'class' => array('form-wrapper-horizontal'),
    ),
  );
  $form['fieldset']['checkboxes'] = array(
    '#type' => 'checkboxes',
    '#options' => drupal_map_assoc(array(t('Option 1'), t('Option 2'))),
    '#title' => t('This is the checkboxes title'),
  );
  $form['fieldset']['text1'] = array(
    '#type' => 'textfield',
    '#title' => t('Text field'),
    '#description' => t('This is the description of the text field'),
    '#default_value' => t('This is the default value'),
  );
  $form['fieldset']['text2'] = array(
    '#type' => 'textfield',
    '#title' => t('Text field'),
    '#description' => t('This is the description of the text field'),
    '#default_value' => t('This is the default value'),
  );

  // Fieldset collapsable
  $form['fieldset_collapsible'] = array(
    '#type' => 'fieldset',
    '#title' => t('This is a collapsible fieldset'),
    '#collapsible' => TRUE,
    '#attributes' => array(
      'class' => array('form-wrapper-horizontal'),
    ),
  );
  $form['fieldset_collapsible']['checkboxes'] = array(
    '#type' => 'checkboxes',
    '#options' => drupal_map_assoc(array(t('Option 1'), t('Option 2'))),
    '#title' => t('This is the checkboxes title'),
  );
  $form['fieldset_collapsible']['text1'] = array(
    '#type' => 'textfield',
    '#title' => t('Text field'),
    '#description' => t('This is the description of the text field'),
    '#default_value' => t('This is the default value'),
  );
  $form['fieldset_collapsible']['text2'] = array(
    '#type' => 'textfield',
    '#title' => t('Text field'),
    '#description' => t('This is the description of the text field'),
    '#default_value' => t('This is the default value'),
  );

  // Fieldset collapsed
  $form['fieldset_collapsed'] = array(
    '#type' => 'fieldset',
    '#title' => t('This is a collapsed fieldset'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#attributes' => array(
      'class' => array('form-wrapper-horizontal'),
    ),
  );
  $form['fieldset_collapsed']['checkboxes'] = array(
    '#type' => 'checkboxes',
    '#options' => drupal_map_assoc(array(t('Option 1'), t('Option 2'))),
    '#title' => t('This is the checkboxes title'),
  );
  $form['fieldset_collapsed']['text1'] = array(
    '#type' => 'textfield',
    '#title' => t('Text field'),
    '#description' => t('This is the description of the text field'),
    '#default_value' => t('This is the default value'),
  );
  $form['fieldset_collapsed']['text2'] = array(
    '#type' => 'textfield',
    '#title' => t('Text field'),
    '#description' => t('This is the description of the text field'),
    '#default_value' => t('This is the default value'),
  );



  // Submit buttons
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  $form['actions']['delete'] = array(
    '#type' => 'button',
    '#value' => t('Delete'),
    '#attributes' => array(
      'class' => array('btn-grey')
    ),
  );
  $form['actions']['cancel'] = array(
    '#markup' => l(t('Cancel'), 'foo/bar', array('attributes' => array('class' => 'form-cancel'))),
  );

  return $form;
}
