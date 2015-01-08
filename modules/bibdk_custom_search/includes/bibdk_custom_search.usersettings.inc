<?php


/** Implements hook_bibdk_usersettings_user_tabs
 *
 * @return array
 */
function bibdk_custom_search_bibdk_usersettings_user_tabs() {
  $filters = variable_get('bibdk_custom_search_user_settings', array());
  if (!empty($filters)){
    $tab['materials'] = array(
      'title' => t('Materials'),
      'description' => t('tab_materials_description'),
      'weight' => -5,
    );
  }
  $tab['start_page'] = array(
    'title' => t('Start Page'),
    'description' => t('tab_start_page_description'),
    'weight' => -4,
  );
  return $tab;
}


/**
 * implements hook_bibdk_usersettings_user_settings
 */
function bibdk_custom_search_bibdk_usersettings_user_settings() {
  $form = array();

  $form += bibdk_custom_search_usersettings_materials();
  $form += bibdk_custom_search_usersettings_start_page();

  return $form;
}

/** Add usersettings page for setting start page
 *
 * @return array
 */
function bibdk_custom_search_usersettings_start_page() {
  $start_page = bibdk_usersettings_user_settings_get('bibdk_custom_search_start_page', null);

  $pages = _bibdk_custom_search_get_pages_db();
  if (count($pages) == 0) {
    return array();
  }

  foreach ($pages as $key => $page) {
    $options[$page['href']] = $page['title'];
  }

  $form = array(
    'start_page' => array(),
  );

  $form['start_page']['bibdk_custom_search_start_page'] = array(
    '#type' => 'radios',
    '#title' => t('Choose start page'),
    '#options' => $options,
    '#default_value' => $start_page
  );

  $form['start_page'] += array(
    '#type' => 'container',
    '#weight' => -1,
    '#tab' => 'start_page',
  );

  return $form;
}


function bibdk_custom_search_usersettings_materials() {
  //Get values from database
  $default_values = bibdk_usersettings_user_settings_get('bibdk_custom_search_materials', array());
  $elements = variable_get('bibdk_custom_search_user_settings', array());

  bibdk_custom_search_usersettings_set_default_values($elements, $default_values);
  bibdk_custom_search_usersettings_set_subelements($elements);

  $form = array(
    'materials' => array(
      '#type' => 'container',
      '#weight' => -1,
      '#tab' => 'materials',
      '#attached' => array(
        'js' => array(
          drupal_get_path('module', 'bibdk_custom_search') . '/js/bibdk_custom_search_usersettings.js',
        ),
      ),
    ),
  );

  $form['materials']['description'] = array(
    '#markup' => t('bibdk_custom_search_materials_description', array(), array('context' => "bibdk_custom_search")),
  );


  foreach ($elements as $group) {
    $form['materials']['bibdk_custom_search_materials'][$group->id] = bibdk_custom_search_usersettings_form_group($group);
  }


  return $form;

}


/** Set default values for usersetting elements
 *
 * @param $elements
 * @param $default_values
 */
function bibdk_custom_search_usersettings_set_default_values(&$elements, $default_values) {
  foreach ($elements as &$element) {
    $element->default_value = isset($default_values[$element->id]) ? $default_values[$element->id] : 0;
  }
}


/** Group usersetting elements
 *
 * @param $elements
 */
function bibdk_custom_search_usersettings_set_subelements(&$elements) {
  foreach ($elements as $key => $element) {
    if ($element->pid) {
      $elements[$element->pid]->subelements[$element->id] = $element;
      unset($elements[$key]);
    }
  }
}

/** Create usersettings admin-group render-array
 *
 * @param $group
 * @return array
 */
function bibdk_custom_search_usersettings_form_group($group) {
  $id = $group->id;

  $form = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'usersettings-group-wrapper'
      ),
    ),
  );

  // Create parent element
  $attributes = array(
    'data-setting-parent' => $id,
    'class' => array(
      'group-main'
    ),
  );
  $form['main'] = bibdk_custom_search_usersettings_form_group_element($group, $attributes);


  // Create sub elements
  if (isset($group->subelements)) {

    $form['dependent'] = array(
      '#type' => 'fieldset',
      '#attributes' => array(
        'data-setting-child' => $id,
        'class' => array(
          'usersettings-sub--wrapper'
        ),
      ),
    );

    $attributes = array(
      'class' => array(
        'group-sub'
      ),
    );

    foreach ($group->subelements as $element) {
      $form['dependent'][$element->id] = bibdk_custom_search_usersettings_form_group_element($element, $attributes);
    }
  }
  return $form;
}

/** Create single element for usersettings form
 *
 * @param $element
 * @param $attributes
 * @return array
 */
function bibdk_custom_search_usersettings_form_group_element($element, $attributes) {
  return array(
    '#type' => 'radios',
    '#title' => t($element->description, array(), array('context' => "bibdk_custom_search")),
    '#default_value' => $element->default_value,
    '#parents' => array('elements', 'materials', 'bibdk_custom_search_materials', $element->id),
    '#options' => array(
      0 => t('show values', array(), array('context' => "bibdk_custom_search")),
      1 => t('hide values', array(), array('context' => "bibdk_custom_search")),
    ),
    '#attributes' => $attributes,
  );

}


/**
 * Implements hook_ting_openformat_query_filter
 * Method to retrieve custom search code settings
 */
function bibdk_custom_search_ting_openformat_query_filter() {
  $default_values = bibdk_usersettings_user_settings_get('bibdk_custom_search_materials', array());
  $elements = variable_get('bibdk_custom_search_user_settings', array());
  $filter = array();

  foreach ($elements as $element) {
    if (isset($default_values[$element->id]) && $default_values[$element->id] == 1) {
      $filter[$element->description] = $element->value;
    }
  }

  return $filter;

}


/** Admin form for bibdk custom search usersettings
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function bibdk_custom_search_usersettings_admin($form, $form_state) {
  $form['wrapper'] = array(
    '#type' => 'fieldset',
    '#title'        => t('Custom search filters'),
    '#description'  => t('Create new filter options by adding a description and a searchcode. </br> It is possible to use the operators <b>OG</b> and <b>ELLER</b> in the searchcode'),
  );

  $elements = variable_get('bibdk_custom_search_user_settings', array());

  bibdk_custom_search_usersettings_set_subelements($elements);


  foreach ($elements as $element) {
    $form['rows'][$element->id] = bibdk_custom_search_usersettings_admin_element($element);
    if (isset($element->subelements)) {
      foreach ($element->subelements as $subelement) {
        $form['rows'][$subelement->id] = bibdk_custom_search_usersettings_admin_element($subelement);
      }
    }
  }

  // Add input fields for adding new elements
  $form['rows']['new'] = bibdk_custom_search_usersettings_admin_element();
  $form['rows']['new']['id'] = array(
    '#type' => 'machine_name',
    '#title' => t("Machine Name"),
    '#description' => t("machine-friendly name."),
    '#size' => 15,
    '#maxlength' => 15,
    '#machine_name' => array(
      'exists' => '_bibdk_custom_search_usersettings_machinename_exists',
      'source' => array('rows', 'new', 'description'),
    ),
  );
  $form['rows']['new']['remove'] = array(
    '#markup' => '',
  );


  $form['rows']['#tree'] = true;
  $form['header'] = array(
    '#type' => 'value',
    '#value' => array(
      'description',
      'value',
      'weight',
      '',
      '',
      'remove'
    ),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

/** implements form_validate
 *
 * Remove all validation errors, so machine name don't create problems
 * + There are no required fields
 *
 * @param $form
 * @param $form_state
 */
function bibdk_custom_search_usersettings_admin_validate(&$form, &$form_state) {
  form_clear_error();
  drupal_get_messages('error');
}


/** Render array - creates usersettings admin page form element
 *
 * @param $element
 * @return array
 */
function bibdk_custom_search_usersettings_admin_element($element = null) {

  $return = array(
    // Description of element
    'description' => array(
      '#type' => 'textfield',
      '#default_value' => isset($element->description) ? $element->description : null,
    ),

    //value of element
    'value' => array(
      '#type' => 'textfield',
      '#default_value' => isset($element->value) ? $element->value : null,
    ),

    //weight of element
    'weight' => array(
      '#type' => 'weight',
      '#title' => t('Weight'),
      '#default_value' => isset($element->weight) ? $element->weight : null,
      '#delta' => 10,
      '#attributes' => array(
        'class' => array('usersetting-item-weight'),
      ),
    ),

    // ID of element
    'id' => array(
      '#type' => 'hidden',
      '#value' => isset($element->id) ? $element->id : null,
      '#size' => 3,

      '#attributes' => array(
        'class' => array('usersetting-item-id'),
      ),
    ),

    // ID of parent element
    'pid' => array(
      '#type' => 'hidden',
      '#default_value' => isset($element->pid) ? $element->pid : 0,
      '#size' => 3,

      '#attributes' => array(
        'class' => array('usersetting-item-pid'),
      ),
    ),

    'remove' => array(
      '#type' => 'checkbox',
      '#default_value' => false,
    ),

    '#depth' => isset($element->pid) && $element->pid != '0' ? 1 : 0,
  );

  return $return;

}


/** usersetting machinename callback function
 *
 * @param $name
 * @param $element
 * @param $form_state
 * @return int
 */
function _bibdk_custom_search_usersettings_machinename_exists($name, &$element, &$form_state) {
  $name = bibdk_custom_search_usersettings_create_machinename($name, $form_state['values']['rows']);
  $element['#value'] = $name;
  $form_state['values']['rows']['new']['id'] = $name;

  // Always return false, because we generate a unique machinename
  return false;
}

function bibdk_custom_search_usersettings_create_machinename($name, $existing_names) {
  $count = 0;
  $new_name = $name;
  while (isset($existing_names[$new_name])) {
    $new_name = $name . '_' . ++$count;
  }
  return $new_name;
}

/** Usersetting admin form submit function
 *
 * @param $form
 * @param $form_state
 */
function bibdk_custom_search_usersettings_admin_submit($form, &$form_state) {

  $objects = array();
  $rows = $form_state['values']['rows'];

  uasort($rows, 'drupal_sort_weight');

  if (!empty($rows['new']['value'])) {
    $object = (object)$rows['new'];
    $objects[$object->id] = $object;
  }
  unset($rows['new']);

  if (!empty($rows)) {
    foreach ($rows as $key => $row) {
      if ($row['remove'] == 1 || $row['id'] == null) {
        unset($rows[$key]);
      }
    }
    foreach ($rows as $row) {
      $object = (object)$row;
      if ($object->pid !== 0 && !isset($rows[$object->pid])) {
        $object->pid = 0;
      }
      $objects[$object->id] = $object;
    }
  }
  variable_set('bibdk_custom_search_user_settings', $objects);
}

/** Theme function for usersettings admin form
 *
 * @param $variables
 * @return string
 */
function theme_bibdk_custom_search_usersettings_admin($variables) {
  $table_id = 'usersettings-admin-table';
  $form = $variables['form'];
  $header = $form['header']['#value'];

  foreach (element_children($form['rows']) as $id) {
    $class = array('draggable');
    $indent = theme('indentation', array('size' => $form['rows'][$id]['#depth']));
    $data = array();
    foreach (element_children($form['rows'][$id]) as $element_key) {
      $element = & $form['rows'][$id][$element_key];
      $data[$element_key] = count($data) ? drupal_render($element) : $indent . drupal_render($element);
    }
    $rows[] = array(
      'data' => $data,
      'class' => $class,
    );
  }
  drupal_add_tabledrag($table_id, 'match', 'parent', 'usersetting-item-pid', 'usersetting-item-pid', 'usersetting-item-id', true, 1);
  drupal_add_tabledrag($table_id, 'order', 'sibling ', 'usersetting-item-weight', NULL, NULL, TRUE);

  $form['wrapper']['table'] = array(
    '#theme'  => 'table',
    '#header' => $header,
    '#rows' => $rows,
    '#attributes' => array('id' => $table_id),
  );

  return drupal_render_children($form);
}
