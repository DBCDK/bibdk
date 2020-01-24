<?php

/**
 * @file
 * List elements form
 */
function _bibdk_custom_search_elements_admin_form($elements = array()) {
  $form = array();

  $form['bibdk_custom_search_page_elements'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('Search page elements'),
    '#description'  => t('Order, edit and add search page elements.'),
    '#tree'         => TRUE,
    '#theme'        => 'bibdk_custom_search-list-elements-form',
  );

  $i = 0;
  foreach ($elements as $element => $data) {
    $form['bibdk_custom_search_page_elements'][$i] = array(
      '#title'          => check_plain($data['element_title']),
      '#weight'         => $data['sort'],
    );
    $form['bibdk_custom_search_page_elements'][$i]['e_uuid'] = array(
      '#type'           => 'hidden',
      '#title'          => t('Element ID'),
      '#title_display'  => 'invisible',
      '#default_value'  => $data['e_uuid'],
    );
    $form['bibdk_custom_search_page_elements'][$i]['element_title'] = array(
      '#type'           => 'hidden',
      '#title'          => t('Element name'),
      '#title_display'  => 'invisible',
      '#default_value'  => $data['element_title'],
    );
    $form['bibdk_custom_search_page_elements'][$i]['edit'] = array(
      '#type'           => 'link',
      '#title'          => t('edit'),
      '#title_display'  => 'invisible',
      '#href'           =>  'admin/config/search/bibdk_custom_search/elements/' . $data['e_uuid'] . '/edit',
      '#options'        => array('attributes' => array('title' => t('Edit element.'))),
    );
    $form['bibdk_custom_search_page_elements'][$i]['delete'] = array(
      '#type'           => 'link',
      '#title'          => t('delete'),
      '#title_display'  => 'invisible',
      '#href'           =>  'admin/config/search/bibdk_custom_search/elements/' . $data['e_uuid'] . '/delete',
      '#options'        => array('attributes' => array('title' => t('Delete element.'))),
    );
    $form['bibdk_custom_search_page_elements'][$i]['sort'] = array(
      '#type'           => 'weight',
      '#delta'          => 100,
      '#title'          => t('Weight'),
      '#title_display'  => 'invisible',
      '#default_value'  => $data['sort'],
      '#attributes'     => array('class' => array('element-weight')),
    );
    $form['bibdk_custom_search_page_elements'][$i]['is_disabled'] = array(
      '#type'           => 'checkbox',
      '#title'          => t('Disabled'),
      '#title_display'  => 'invisible',
      '#return_value'   => TRUE,
      '#default_value'  => ( !empty($data['is_disabled']) ) ? TRUE : FALSE,
      '#attributes'     => array('class' => array('element-weight')),
    );
    $i++;
  }

  $form['bibdk_custom_search_page_elements'][$i] = array(
      '#title'        => 'Add search element',
      '#weight'       => '100',
  );
  $form['bibdk_custom_search_page_elements'][$i]['e_uuid'] = array(
    '#type'           => 'hidden',
    '#title'          => t('Element ID'),
    '#title_display'  => 'invisible',
    '#default_value'  => '_new',
  );
  $form['bibdk_custom_search_page_elements'][$i]['element_title'] = array(
    '#type'           => 'textfield',
    '#title'          => t('Name'),
    '#title_display'  => 'invisible',
    '#default_value'  => '',
  );
  $form['bibdk_custom_search_page_elements'][$i]['sort'] = array(
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
 * Edit element form
 */
function _bibdk_custom_search_edit_element_form($element=array(), $list_values=array()) {
  $form = array();
  drupal_add_css(drupal_get_path('module', 'bibdk_custom_search') . '/css/bibdk_custom_search.css');

  $form['bibdk_custom_search_page_element'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('Edit search page element'),
    '#description'  => t('Search page element configuration.'),
    '#tree'         => TRUE,
    '#theme'        => 'bibdk_custom_search-edit-element-form',
  );

  $form['bibdk_custom_search_page_element']['e_uuid'] = array(
    '#type'           => 'hidden',
    '#default_value'  => $element['e_uuid'],
    '#title'          => t('Page ID'),
    '#title_display'  => 'invisible',
  );

  $form['bibdk_custom_search_page_element']['element_title'] = array(
    '#type'           => 'textfield',
    '#default_value'  => $element['element_title'],
    '#title'          => t('Title'),
    '#description'  => t('Administrative title for this search element.'),
    '#size'           => 36,
  );

  $form['bibdk_custom_search_page_element']['element_label'] = array(
    '#type'           => 'textfield',
    '#default_value'  => $element['element_label'],
    '#title'          => t('Element label'),
    '#description'  => t('Label for this search element as shown in the search form.'),
    '#size'           => 36,
  );

  $form['bibdk_custom_search_page_element']['description'] = array(
    '#type'           => 'textarea',
    '#default_value'  => $element['description'],
    '#title'          => t('Description'),
    '#description'  => t('Description for this search element, or a short help text.'),
    '#size'           => 36,
    '#rows'           => 3,
  );

  $form['bibdk_custom_search_page_element']['help_text'] = array(
    '#type'           => 'textarea',
    '#default_value'  => $element['help_text'],
    '#title'          => t('Help text'),
    '#description'  => t('Long help text for this search element.'),
    '#size'           => 36,
    '#rows'           => 3,
  );

  $form['bibdk_custom_search_page_element']['access_key'] = array(
    '#type'           => 'textfield',
    '#default_value'  => $element['access_key'],
    '#title'          => t('AccessKey'),
    '#size'           => 2,
  );

  $form['bibdk_custom_search_page_element']['tab_index'] = array(
    '#type'           => 'textfield',
    '#default_value'  => $element['tab_index'],
    '#title'          => t('TabIndex'),
    '#size'           => 2,
  );

  $form['bibdk_custom_search_page_element']['is_disabled'] = array(
    '#type'           => 'checkbox',
    '#default_value'  => ( !empty($element['is_disabled']) ) ? TRUE : FALSE,
    '#title'          => t('Disabled'),
    '#title_display' => 'before',
    '#description'    => t('Toggle "disabled" status on/off. If disabled, all values in the element is disabled.'),
  );

  $form['bibdk_custom_search_page_element_values'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('Values ordering'),
    '#description'  => t('Order the form element values as you want them to be displayed.'),
    '#theme'        => 'bibdk_custom_search-edit-element-values-form',
    '#tree'         => TRUE,
  );

  if ( sizeof($element['values']) > 1 ) {
    $notice = t('You may need a pre-search processor for these values: Use hook_bibdk_custom_search_field_preprocess to combine values for element ID @id', array('@id' => $element['e_uuid']));
    $form['bibdk_custom_search_page_element_values']['#description'] .= ' <span class="helptext" title="' . htmlspecialchars(strip_tags($notice)) . '">?</span>';
  }

  $i = 0;
  foreach ($element['values'] as $key => $value) {
    $form['bibdk_custom_search_page_element_values'][$i] = array(
      '#title'          => check_plain($value['value_title']),
      '#weight'         => $value['sort'],
    );
    $form['bibdk_custom_search_page_element_values'][$i]['mv_uuid'] = array(
      '#type'           => 'hidden',
      '#title'          => t('Value map ID'),
      '#title_display'  => 'invisible',
      '#default_value'  => $value['mv_uuid'],
    );
    $form['bibdk_custom_search_page_element_values'][$i]['v_uuid'] = array(
      '#type'           => 'hidden',
      '#title'          => t('Value ID'),
      '#title_display'  => 'invisible',
      '#default_value'  => $value['v_uuid'],
    );
    $form['bibdk_custom_search_page_element_values'][$i]['value_title'] = array(
      '#type'           => 'hidden',
      '#title'          => t('Value title'),
      '#title_display'  => 'invisible',
      '#default_value'  => $value['value_title'],
    );
    $form['bibdk_custom_search_page_element_values'][$i]['edit'] = array(
      '#type'           => 'link',
      '#title'          => t('edit'),
      '#title_display'  => 'invisible',
      '#href'           =>  'admin/config/search/bibdk_custom_search/values/' . $value['v_uuid'] . '/edit',
      '#options'        => array('attributes' => array('title' => t('Edit value.'))),
    );
    $form['bibdk_custom_search_page_element_values'][$i]['delete'] = array(
      '#type'           => 'link',
      '#title'          => t('remove'),
      '#title_display'  => 'invisible',
      '#href'           =>  'admin/config/search/bibdk_custom_search/elements/' . $element['e_uuid'] . '/remove_value/' . $value['mv_uuid'],
      '#options'        => array('attributes' => array('title' => t('Remove value.'))),
    );
    $form['bibdk_custom_search_page_element_values'][$i]['sort'] = array(
      '#type'           => 'weight',
      '#delta'          => 100,
      '#title'          => t('Weight'),
      '#title_display' => 'invisible',
      '#default_value'  => $value['sort'],
      '#attributes'     => array('class' => array('element-weight')),
    );
    $form['bibdk_custom_search_page_element_values'][$i]['is_disabled'] = array(
      '#type'           => 'checkbox',
      '#title'          => t('Disabled'),
      '#title_display'  => 'invisible',
      '#return_value'   => TRUE,
      '#default_value'  => ( !empty($value['is_disabled']) ) ? TRUE : FALSE,
    );
    $i++;
  }

  $form['bibdk_custom_search_page_element_values'][$i] = array(
      '#title'        => 'Add search element',
      '#weight'       => '100',
  );
  $form['bibdk_custom_search_page_element_values'][$i]['mv_uuid'] = array(
    '#type'           => 'hidden',
    '#title'          => t('Value map ID'),
    '#title_display'  => 'invisible',
    '#default_value'  => '_new',
  );
  $form['bibdk_custom_search_page_element_values'][$i]['v_uuid'] = array(
    '#type'           => 'select',
    '#options'        => $list_values,
    '#title'          => t('Name'),
    '#title_display'  => 'invisible',
    '#default_value'  => '',
  );

  $form['bibdk_custom_search_page_element_values'][$i]['sort'] = array(
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
 * Delete elements form
 */
function _bibdk_custom_search_delete_element_form($delta = '') {
  $form = array();
  return $form;
}
