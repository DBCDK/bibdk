<?php

/**
 * @file
 * Admin settings for bibdk search controls
 */

/**
 * General settings.
 */
function bibdk_search_controls_admin() {
  $controls = variable_get('bibdk_search_controls', array());

  $form = _bibdk_search_controls_admin_form($controls);
  $form['#submit'][] = 'bibdk_search_controls_admin_submit';

  return $form;
}



/**
 * Submit handler for bibdk_search_controls_admin();
 */
function bibdk_search_controls_admin_submit($form, &$form_state) {

  // create entry
  $id = '_new';
  $form_state['redirect'] = 'admin/config/search/bibdk_search_controls/' . $id . '/edit';

}


/**
 * Validation handler for bibdk_search_controls_admin.
 */
function bibdk_search_controls_admin_validate($form, &$form_state) {
  return $form;
}


/**
 * Edit search control form
 */
function _bibdk_search_controls_admin_form($controls) {

  drupal_add_css(drupal_get_path('module', 'bibdk_search_controls') . '/css/bibdk_search_controls.css');

  $form['bibdk_search_controls'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('Search controls', array(), array('context' => 'bibdk_search_controls')),
    '#description'  => t('Edit or add search controls.', array(), array('context' => 'bibdk_search_controls')),
    '#tree'         => TRUE,
    '#theme'        => 'bibdk_search_controls-admin-form',
  );

  if ( !empty($controls) ) {
    foreach ($controls as $key => $value) {
      $form['bibdk_search_controls'][$key]['title'] = array(
        '#markup'         => t($value['title'], array(), array('context' => 'bibdk_search_controls')),
      );
      $form['bibdk_search_controls'][$key]['edit'] = array(
        '#type'           => 'link',
        '#title'          => t('edit', array(), array('context' => 'bibdk_search_controls')),
        '#title_display'  => 'invisible',
        '#href'           =>  'admin/config/search/bibdk_search_controls/' . $key . '/edit',
        '#options'        => array('attributes' => array('title' => t('Edit.', array(), array('context' => 'bibdk_search_controls')))),
      );
      $form['bibdk_search_controls'][$key]['delete'] = array(
        '#type'           => 'link',
        '#title'          => t('delete', array(), array('context' => 'bibdk_search_controls')),
        '#title_display'  => 'invisible',
        '#href'           =>  'admin/config/search/bibdk_search_controls/' . $key . '/delete',
        '#options'        => array('attributes' => array('title' => t('Delete.', array(), array('context' => 'bibdk_search_controls')))),
      );
      $form['bibdk_search_controls'][$key]['description'] = array(
        '#markup'         => t($value['description'], array(), array('context' => 'bibdk_search_controls')),
      );
    }
  }

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['add'] = array(
    '#type' => 'submit',
    '#value' => t('Add Control', array(), array('context' => 'bibdk_search_controls')),
  );
  return $form;
}



/**
 * Edit settings.
 */
function bibdk_search_controls_edit($form, &$form_state, $id) {

  $elements = array();

  $state = ( $id == '_new' ) ? 'insert' : 'update';

  $controls = variable_get('bibdk_search_controls', NULL);

  if ( $controls && isset($controls[$id]) ) {
    $elements = $controls[$id];
  }
  else {
    $elements['title'] = '';
    $elements['label'] = '';
    $elements['type'] = '';
    $elements['name'] = '';
    $elements['description'] = '';
    $elements['access_key'] = '';
    $elements['tab_index'] = '';
    $elements['values'] = array();
  }

  $form = _bibdk_search_controls_edit_form($elements, $state);
  $form['#submit'][] = 'bibdk_search_controls_edit_submit';
  return $form;
}


/**
 * Submit handler for bibdk_search_controls_edit();
 */
function bibdk_search_controls_edit_submit($form, &$form_state) {

  $id = $form_state['values']['bibdk_search_control']['name'];

  foreach ($form_state['values']['bibdk_search_control'] as $key => $value) {
    $control[$key] = $value;
  }

  if ( isset($form_state['values']['bibdk_search_control_values']) ) {
    foreach ($form_state['values']['bibdk_search_control_values'] as $key => $value) {
      $control['values'][$key] = $value;
    }
    uasort($control['values'], '_bibdk_search_controls_values_cmp');
  }

  if ( $form_state['values']['op'] == t('Add value', array(), array('context' => 'bibdk_search_controls')) ) {
    $control['values'][] = array('id' => '', 'label' => '', 'value' => '', 'default' => '', 'sort' => '');
  }

  $controls = variable_get('bibdk_search_controls', NULL);

  $controls[$id] = $control;

  if ( $form_state['values']['state'] == 'insert' ) {
    drupal_set_message(t('The control "@page" have been created.', array('@page' => $control['title']), array('context' => 'bibdk_search_controls')));
  }
  else {
    drupal_set_message(t('The control have been updated.', array(), array('context' => 'bibdk_search_controls')));
  }

  variable_set('bibdk_search_controls', $controls);

  $form_state['redirect'] = 'admin/config/search/bibdk_search_controls/' . $id . '/edit';

}


/**
 * Validation handler for bibdk_search_controls_edit.
 */
function bibdk_search_controls_edit_validate($form, &$form_state) {

  $controls = variable_get('bibdk_search_controls', NULL);

  $name = $form_state['values']['bibdk_search_control']['name'];

  if ( $form_state['values']['state'] == 'insert' &&  array_key_exists($name, $controls) ) {
    form_set_error('', t('The name attribute must be unique.', array(), array('context' => 'bibdk_search_controls')));
  }

  if ( !empty($form_state['values']['bibdk_search_control_values']) ) {
    $count_defaults = 0;
      foreach ($form_state['values']['bibdk_search_control_values'] as $key => $value) {
      if ( $value['default']) {
        $count_defaults++;
      }
    }
    if ( $count_defaults > 1 && $form_state['values']['bibdk_search_control']['type'] != 'checkboxes' ) {
      drupal_set_message(t('There are too many default values. Only the last one will be used.', array(), array('context' => 'bibdk_search_controls')), 'warning');
    }
  }
  return $form;

}


/**
 * Delete control.
 */
function bibdk_search_controls_delete($form_id, $form_state, $id) {

  $controls = variable_get('bibdk_search_controls', NULL);

  $title = $controls[$id]['title'];

  $form['id'] = array(
    '#type' => 'value',
    '#value' => $id,
  );

  $form['title'] = array(
    '#type' => 'hidden',
    '#value' => $title,
  );

  $form['#validate'][] = 'bibdk_search_controls_delete_validate';
  $form['#submit'][] = 'bibdk_search_controls_delete_submit';

  return confirm_form($form, t("Are you sure you want to delete '@element'?", array('@element' => $title), array('context' => 'bibdk_search_controls')), 'admin/config/search/bibdk_search_controls');
}


/*
 * Validate handler for bibdk_search_controls_delete();
 */
function bibdk_search_controls_delete_validate($form, &$form_state) {

}


/*
 * Submit handler for bibdk_search_controls_delete();
 */
function bibdk_search_controls_delete_submit($form, &$form_state) {

  $key = $form_state['values']['id'];

  $controls = variable_get('bibdk_search_controls', NULL);

  unset($controls[$key]);

  variable_set('bibdk_search_controls', $controls);

  drupal_set_message(t("'@element' deleted.", array('@element' => $form_state['values']['title']), array('context' => 'bibdk_search_controls')));

  $form_state['redirect'] = 'admin/config/search/bibdk_search_controls';

}


/**
 * Edit search control form
 */
function _bibdk_search_controls_edit_form($element, $state) {

  drupal_add_css(drupal_get_path('module', 'bibdk_search_controls') . '/css/bibdk_search_controls.css');

  $form['state'] = array(
    '#type'           => 'hidden',
    '#default_value'  => $state,
    '#title'          => t('Control state'),
    '#title_display'  => 'invisible',
  );

  $form['bibdk_search_control'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('Bibliotek.dk search controls', array(), array('context' => 'bibdk_search_controls')),
    '#description'  => t('Edit search control configuration.', array(), array('context' => 'bibdk_search_controls')),
    '#tree'         => TRUE,
    '#theme'        => 'bibdk_search_controls-edit-form',
  );

  $form['bibdk_search_control']['title'] = array(
    '#type'           => 'textfield',
    '#default_value'  => $element['title'],
    '#title'          => t('Title', array(), array('context' => 'bibdk_search_controls')),
    '#description'  => t('Administrative name for this control', array(), array('context' => 'bibdk_search_controls')),
    '#size'           => 36,
  );

  $form['bibdk_search_control']['type'] = array(
    '#type'           => 'select',
    '#options' => array(
      'checkboxes' => t('Checkboxes', array(), array('context' => 'bibdk_search_controls')),
      'radios' => t('Radios', array(), array('context' => 'bibdk_search_controls')),
      'select' => t('Dropdown', array(), array('context' => 'bibdk_search_controls')),
    ),
    '#default_value'  => $element['type'],
    '#title'          => t('Element type', array(), array('context' => 'bibdk_search_controls')),
    '#description'  => t('Type of control.', array(), array('context' => 'bibdk_search_controls')),
  );

  $form['bibdk_search_control']['label'] = array(
    '#type'           => 'textfield',
    '#default_value'  => $element['label'],
    '#title'          => t('Element label', array(), array('context' => 'bibdk_search_controls')),
    '#description'  => t('Label for this control as shown in the search form.', array(), array('context' => 'bibdk_search_controls')),
    '#size'           => 36,
  );

  $form['bibdk_search_control']['name'] = array(
    '#type'           => 'textfield',
    '#default_value'  => $element['name'],
    '#title'          => t('Element name', array(), array('context' => 'bibdk_search_controls')),
    '#description'  => t('Name attribute for this control.', array(), array('context' => 'bibdk_search_controls')),
    '#size'           => 36,
  );

  $form['bibdk_search_control']['description'] = array(
    '#type'           => 'textarea',
    '#default_value'  => $element['description'],
    '#title'          => t('Description', array(), array('context' => 'bibdk_search_controls')),
    '#description'  => t('Description for this control, or a short help text.', array(), array('context' => 'bibdk_search_controls')),
    '#size'           => 36,
  );

  $form['bibdk_search_control']['access_key'] = array(
    '#type'           => 'textfield',
    '#default_value'  => $element['access_key'],
    '#title'          => t('AccessKey', array(), array('context' => 'bibdk_search_controls')),
    '#size'           => 2,
  );

  $form['bibdk_search_control']['tab_index'] = array(
    '#type'           => 'textfield',
    '#default_value'  => $element['tab_index'],
    '#title'          => t('TabIndex', array(), array('context' => 'bibdk_search_controls')),
    '#size'           => 2,
  );


  $form['bibdk_search_control_values'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('Search controls : dropdown values', array(), array('context' => 'bibdk_search_controls')),
    '#description'  => t('Order the values as you want them to be displayed.', array(), array('context' => 'bibdk_search_controls')),
    '#tree'         => TRUE,
    '#theme'        => 'bibdk_search_controls-values-form',
  );

  if ( isset($element['values']) ) {
    foreach ($element['values'] as $key => $value) {
      $form['bibdk_search_control_values'][$key] = array(
        '#title'          => check_plain($value['label']),
        '#weight'         => check_plain($value['sort']),
      );
      $form['bibdk_search_control_values'][$key]['label'] = array(
        '#type'           => 'textfield',
        '#title'          => t('Label', array(), array('context' => 'bibdk_search_controls')),
        '#title_display'  => 'invisible',
        '#default_value'  => $value['label'],
      );
      $form['bibdk_search_control_values'][$key]['value'] = array(
        '#type'           => 'textfield',
        '#title'          => t('Value', array(), array('context' => 'bibdk_search_controls')),
        '#title_display'  => 'invisible',
        '#default_value'  => $value['value'],
      );
      $form['bibdk_search_control_values'][$key]['default'] = array(
        '#type'           => 'checkbox',
        '#title'          => t('Default', array(), array('context' => 'bibdk_search_controls')),
        '#title_display'  => 'invisible',
        '#default_value'  => $value['default'],
      );
      $form['bibdk_search_control_values'][$key]['delete'] = array(
        '#type'           => 'link',
        '#title'          => t('delete', array(), array('context' => 'bibdk_search_controls')),
        '#title_display'  => 'invisible',
        '#href'           =>  'admin/config/search/bibdk_search_controls/' . $element['name'] . '/delete_value/' . $key,
        '#options'        => array('attributes' => array('title' => t('Delete value.'))),
      );
      $form['bibdk_search_control_values'][$key]['sort'] = array(
        '#type'           => 'weight',
        '#title'          => t('Weight', array(), array('context' => 'bibdk_search_controls')),
        '#title_display' => 'invisible',
        '#default_value'  => $value['sort'],
        '#attributes'     => array('class' => array('element-weight')),
      );
    }
  }

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  $form['actions']['add'] = array(
    '#type' => 'submit',
    '#value' => t('Add value'),
  );

  return $form;
}


/**
 * Delete control.
 */
function bibdk_search_controls_delete_value($form_id, $form_state, $id, $vid) {

  $controls = variable_get('bibdk_search_controls', NULL);

  $title = $controls[$id]['title'];

  $value = $controls[$id]['values'][$vid]['label'] . ' : ' . $controls[$id]['values'][$vid]['value'];

  $form['id'] = array(
    '#type' => 'value',
    '#value' => $id,
  );

  $form['vid'] = array(
    '#type' => 'value',
    '#value' => $vid,
  );

  $form['title'] = array(
    '#type' => 'hidden',
    '#value' => $title,
  );

  $form['value'] = array(
    '#type' => 'hidden',
    '#value' => $value,
  );

  $form['#validate'][] = 'bibdk_search_controls_delete_value_validate';
  $form['#submit'][] = 'bibdk_search_controls_delete_value_submit';

  return confirm_form($form, t("Are you sure you want to delete '@value' in '@title'?", array('@title' => $title, '@value' => $value), array('context' => 'bibdk_search_controls')), 'admin/config/search/bibdk_search_controls');
}


/*
 * Validate handler for bibdk_search_controls_value_delete();
 */
function bibdk_search_controls_delete_value_validate($form, &$form_state) {

}


/*
 * Submit handler for bibdk_search_controls_value_delete();
 */
function bibdk_search_controls_delete_value_submit($form, &$form_state) {

  $id  = check_plain($form_state['values']['id']);
  $vid = (int)$form_state['values']['vid'];

  $controls = variable_get('bibdk_search_controls', NULL);

  unset($controls[$id]['values'][$vid]);

  variable_set('bibdk_search_controls', $controls);

  drupal_set_message(t("'@value' in '@title' deleted.", array('@title' => $form_state['values']['title'], '@value' => $form_state['values']['value']), array('context' => 'bibdk_search_controls')));

  $form_state['redirect'] = 'admin/config/search/bibdk_search_controls/' . $id . '/edit';

}



/*
 * Comparison function for control values.
 */
function _bibdk_search_controls_values_cmp($a, $b) {
    if ($a['sort'] == $b['sort']) {
        return 0;
    }
    return ($a['sort'] < $b['sort']) ? -1 : 1;
}