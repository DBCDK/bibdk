<?php

/**
 * @file
 * List values form
 */

function _bibdk_custom_search_values_admin_form($elements = array()) {

  $form = array();

  $form['bibdk_custom_search'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('Search page values'),
    '#description'  => t('Order, edit and add search page values.'),
    '#tree'         => TRUE,
    '#theme'        => 'bibdk_custom_search-list-values-form',
  );

  $i = 0;
  foreach ($elements as $element => $data) {
    $form['bibdk_custom_search'][$i] = array(
      '#title'          => check_plain($data['value_title']),
      '#weight'         => $data['sort'],
    );
    $form['bibdk_custom_search'][$i]['v_uuid'] = array(
      '#type'           => 'hidden',
      '#title'          => t('Element ID'),
      '#title_display'  => 'invisible',
      '#default_value'  => $data['v_uuid'],
    );
    $form['bibdk_custom_search'][$i]['value_title'] = array(
      '#type'           => 'hidden',
      '#title'          => t('Page name'),
      '#title_display'  => 'invisible',
      '#default_value'  => $data['value_title'],
    );
    $form['bibdk_custom_search'][$i]['edit'] = array(
      '#type'           => 'link',
      '#title'          => t('edit'),
      '#title_display'  => 'invisible',
      '#href'           => 'admin/config/search/bibdk_custom_search/values/' . $data['v_uuid'] . '/edit',
      '#options'        => array('attributes' => array('title' => t('Edit values.'))),
    );
    $form['bibdk_custom_search'][$i]['delete'] = array(
      '#type'           => 'link',
      '#title'          => t('delete'),
      '#title_display'  => 'invisible',
      '#href'           =>  'admin/config/search/bibdk_custom_search/values/' . $data['v_uuid'] . '/delete',
      '#options'        => array('attributes' => array('title' => t('Delete values.'))),
    );
    $form['bibdk_custom_search'][$i]['sort'] = array(
      '#type'           => 'weight',
      '#delta'          => 100,
      '#title'          => t('Weight'),
      '#title_display' => 'invisible',
      '#default_value'  => $data['sort'],
      '#attributes'     => array('class' => array('element-weight')),
    );
    $form['bibdk_custom_search'][$i]['is_disabled'] = array(
      '#type'           => 'checkbox',
      '#title'          => t('Disabled'),
      '#title_display'  => 'invisible',
      '#return_value'   => TRUE,
      '#default_value'  => ( !empty($data['is_disabled']) ) ? TRUE : FALSE,
      '#attributes'     => array('class' => array('element-weight')),
    );
    $i++;
  }

  $form['bibdk_custom_search'][$i] = array(
      '#title'        => 'Add search values',
      '#weight'       => '100',
  );
  $form['bibdk_custom_search'][$i]['v_uuid'] = array(
    '#type'           => 'hidden',
    '#title'          => t('Element ID'),
    '#title_display'  => 'invisible',
    '#default_value'  => '_new',
  );
  $form['bibdk_custom_search'][$i]['value_title'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Name'),
    '#title_display'  => 'invisible',
    '#default_value'  => '',
  );
  $form['bibdk_custom_search'][$i]['sort'] = array(
    '#type'           => 'weight',
    '#delta'          => 100,
    '#title'          => t('Weight'),
    '#default_value'  => 10,
    '#attributes'     => array('class' => array('element-weight')),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  return $form;
}


/**
 * Edit values form
 */
function _bibdk_custom_search_edit_value_form($value = array(), $list_values) {
  $form = array();
  drupal_add_css(drupal_get_path('module', 'bibdk_custom_search') . '/css/bibdk_custom_search.css');

  $form['element_value'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('Edit search page element value'),
    '#description'  => t('Search page element element configuration.'),
    '#tree'         => TRUE,
    '#theme'        => 'bibdk_custom_search-edit-value-form',
  );

  $form['element_value']['v_uuid'] = array(
    '#type'           => 'hidden',
    '#default_value'  => $value['v_uuid'],
    '#title'          => t('Value ID'),
    '#title_display'  => 'invisible',
  );

  $form['element_value']['value_title'] = array(
    '#type'           => 'textfield',
    '#default_value'  => $value['value_title'],
    '#title'          => t('Title'),
    '#description'    => t('Administrative title for this search value'),
    '#size'           => 30,
  );

  $form['element_value']['value_type'] = array(
    '#type'           => 'select',
    '#options'        => array(
                          '' => t('Select value type'),
                          'textfield' => t('Text'),
                          'select' => t('Select'),
                          // 'select-multi' => t('Select multiple'),
                          'radios' => t('Radio'),
                          'checkboxes' => t('Checkbox'),
                          'hidden' => t('Hidden'),
    ),
    '#default_value'  => $value['value_type'],
    '#title'          => t('Type'),
  );

  $form['element_value']['search_code'] = array(
    '#type'           => 'textfield',
    '#default_value'  => $value['search_code'],
    '#title'          => t('Search code'),
    '#description'    => t('Search code for this search query.') . "\n" . t('F.ex. dc.type.') . "\n" . t('Leave blank, if it is a value submenu.'),
    '#size'           => 30,
  );

  $form['element_value']['default_value'] = array(
    '#type'           => 'textfield',
    '#default_value'  => $value['default_value'],
    '#title'          => t('Default value'),
    '#description'    => t('If a select, radio or checkbox group, the value is selected by default.'),
    '#size'           => 30,
  );

  $form['element_value']['is_disabled'] = array(
    '#type'           => 'checkbox',
    '#default_value'  => ( !empty($value['is_disabled']) ) ? TRUE : FALSE,
    '#title'          => t('Disabled'),
    '#title_display' => 'before',
    '#description'    => t('Toggle "disabled" status on/off.
If disabled, the value is shown greyed out, and can\'t be selectd.
Checkbox options that are disabled are greyed out.
Select and radio options are removed'),
  );


  $form['element_value_options'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('Options'),
    '#description'  => t('Order the form elements options as you want them to be displayed.'),
    '#theme'        => 'bibdk_custom_search-list-options-form',
    '#tree'         => TRUE,
  );

  $i = 0;
  foreach ($value['options'] as $key => $option) {
    $form['element_value_options'][$i] = array(
      '#weight'         => $option['sort'],
    );
    $form['element_value_options'][$i]['o_uuid'] = array(
      '#type'           => 'hidden',
      '#title'          => t('Option ID'),
      '#title_display'  => 'invisible',
      '#default_value'  => $option['o_uuid'],
    );
    $form['element_value_options'][$i]['label'] = array(
      '#type'           => 'textfield',
      '#title'          => t('Option label'),
      '#title_display'  => 'invisible',
      '#default_value'  => $option['label'],
      '#size'           => 36,
    );
    if ( $option['expand'] ) {
      $form['element_value_options'][$i]['value'] = array(
        '#type'           => 'textfield',
        '#title_display'  => 'invisible',
        '#title'          => t('Value submenu'),
        '#default_value'  => $option['value'],
        '#maxlength'      => 255,
        '#size'           => 36,
      );
      $form['element_value_options'][$i]['expand'] = array(
        '#type'           => 'select',
        '#options'        => $list_values,
        '#default_value'  => $option['expand'],
        '#title'          => t('Option submenu'),
        '#title_display'  => 'invisible',
      );
    }
    else {
      $form['element_value_options'][$i]['value'] = array(
        '#type'           => 'textfield',
        '#title'          => t('Option value'),
        '#title_display'  => 'invisible',
        '#default_value'  => $option['value'],
        '#maxlength'      => 255,
        '#size'           => 36,
      );
      $form['element_value_options'][$i]['expand'] = array(
        '#type'           => 'hidden',
        '#title'          => t('Option submenu'),
        '#title_display'  => 'invisible',
        '#default_value'  => $option['expand'],
      );
    }
    $form['element_value_options'][$i]['delete'] = array(
      '#type'           => 'link',
      '#title'          => t('delete'),
      '#title_display'  => 'invisible',
      '#href'           =>  'admin/config/search/bibdk_custom_search/values/' . $value['v_uuid'] . '/delete_option/' . $option['o_uuid'],
      '#options'        => array('attributes' => array('title' => t('Delete option.'))),
    );
    $form['element_value_options'][$i]['sort'] = array(
      '#type'           => 'weight',
      '#delta'          => 100,
      '#title'          => t('Weight'),
      '#title_display' => 'invisible',
      '#default_value'  => $option['sort'],
      '#attributes'     => array('class' => array('element-weight')),
    );
    $form['element_value_options'][$i]['is_disabled'] = array(
      '#type'           => 'checkbox',
      '#title'          => t('Disabled'),
      '#title_display'  => 'invisible',
      '#return_value'   => TRUE,
      '#default_value'  => ( !empty($option['disabled']) ) ? TRUE : FALSE,
    );
    $i++;
  }

  $form['element_value_options'][$i] = array(
      '#title'        => 'Add search element value',
      '#weight'       => '100',
  );
  $form['element_value_options'][$i]['o_uuid'] = array(
    '#type'           => 'hidden',
    '#title'          => t('Option ID'),
    '#title_display'  => 'invisible',
    '#default_value'  => '_new',
  );
  $form['element_value_options'][$i]['label'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Option label'),
    '#title_display'  => 'invisible',
    '#default_value'  => '',
    '#size'           => 36,
  );
  $form['element_value_options'][$i]['value'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Option value'),
    '#title_display'  => 'invisible',
    '#maxlength'      => 255,
    '#default_value'  => '',
    '#size'           => 36,
  );
  $form['element_value_options'][$i]['expand'] = array(
    '#type'           => 'hidden',
    '#title'          => t('Value submenu'),
    '#title_display'  => 'invisible',
    '#default_value'  => '0',
  );
  $form['element_value_options'][$i]['sort'] = array(
    '#type'           => 'weight',
    '#delta'          => 100,
    '#title'          => t('Weight'),
    '#title_display'  => 'invisible',
    '#default_value'  => 10,
    '#attributes'     => array('class' => array('element-weight')),
  );
  $i++;

  $form['add_options']['element_value_options'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('Add value submenu'),
    '#tree'         => TRUE,
    '#collapsible'  => TRUE,
    '#collapsed'    => TRUE,
    '#theme'        => 'bibdk_custom_search-list-options-form',
  );

  $form['add_options']['element_value_options'][$i] = array(
      '#title'        => 'Add search element value',
      '#weight'       => '110',
  );
  $form['add_options']['element_value_options'][$i]['o_uuid'] = array(
    '#type'           => 'hidden',
    '#title'          => t('Option ID'),
    '#title_display'  => 'invisible',
    '#default_value'  => '_submenu',
  );
  $form['add_options']['element_value_options'][$i]['label'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Option label'),
    '#title_display'  => 'invisible',
    '#default_value'  => '',
    '#size'           => 36,
  );
  $form['add_options']['element_value_options'][$i]['value'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Option value'),
    '#title_display'  => 'invisible',
    '#maxlength'      => 255,
    '#default_value'  => '',
    '#size'           => 36,
  );
  $form['add_options']['element_value_options'][$i]['expand'] = array(
    '#type'           => 'select',
    '#options'        => $list_values,
    '#title_display'  => 'invisible',
    '#default_value'  => NULL,
    '#title'          => t('Value submenu'),
  );
  $form['add_options']['element_value_options'][$i]['sort'] = array(
    '#type'           => 'weight',
    '#delta'          => 100,
    '#title'          => t('Weight'),
    '#title_display'  => 'invisible',
    '#default_value'  => 10,
    '#attributes'     => array('class' => array('element-weight')),
  );


  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}


/**
 * Delete values form
 */
function _bibdk_custom_search_delete_value_form($delta = '') {
  $form = array();
  return $form;
}
