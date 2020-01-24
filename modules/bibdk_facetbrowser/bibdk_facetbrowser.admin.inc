<?php
/**
 * @file
 * Admin page callback file for the bibdk_facetbrowser module.
 */

/**
 * Form builder; Configure ting settings for this site.
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function bibdk_facetbrowser_settings($form_state) {
  form_load_include($form_state, 'inc', 'bibdk_facetbrowser', 'bibdk_facetbrowser.admin');
  $form = array();
  $facets = variable_get('bibdk_facetbrowser_facets', array());

  $form['description'] = array(
    '#markup' => '<p>' . t('Configure facets shown in the facetbrowser. Facet names can be found at <a href="http://oss.dbc.dk/wiki/bin/view/Databroend/OpenSearchDocIndexes">DBC wiki</a> and is usually named <em>facet.something</em>.') . '</p>',
);

  $form['bibdk_facetbrowser_facets'] = array(
    '#tree' => TRUE,
    '#weight' => -20,
  );

  $i = 0;
  foreach ( $facets as $facet ) {
    $form['bibdk_facetbrowser_facets'][$i]['name'] = array(
      '#type' => 'textfield',
      '#title' => t('Facet id'),
      '#title_display' => 'invisible',
      '#default_value' => $facet['name'],
    );

    $form['bibdk_facetbrowser_facets'][$i]['title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#title_display' => 'invisible',
      '#default_value' => $facet['title'],
    );

    $form['bibdk_facetbrowser_facets'][$i]['weight'] = array(
      '#type' => 'weight',
      '#title' => t('Weight'),
      '#default_value' => $facet['weight'],
      '#title_display' => 'invisible',
      '#attributes' => array('class' => array('facet-weight')),
    );

    $form['bibdk_facetbrowser_facets'][$i]['delete'] = array(
      '#type' => 'link',
      '#title' => t('delete'),
      '#href' =>  'admin/config/ting/facets/' . $facet['name'] . '/delete',
      '#options' => array('attributes' => array('title' => t('Delete facet.'))),
    );

    $i++;
  }

  $form['bibdk_facetbrowser_facets'][$i]['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Facet id'),
    '#default_value' => '',
  );

  $form['bibdk_facetbrowser_facets'][$i]['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => '',
  );

  $form['bibdk_facetbrowser_facets'][$i]['weight'] = array(
    '#type' => 'weight',
    '#title' => t('Weight'),
    '#default_value' => 10,
    '#attributes' => array('class' => array('facet-weight')),
  );
  $i++;

    $form['bibdk_facetbrowser_group_number_shown'] = array(
    '#type' => 'textfield',
    '#size' => 8,
    '#weight' => -115,
    '#title' => t('Number of group facets shown.'),
    '#description' => t('Number of group facets shown initially'),
    '#default_value' => variable_get('bibdk_facetbrowser_group_number_shown', 5),
  );

  $form['bibdk_facetbrowser_number_shown'] = array(
    '#type' => 'textfield',
    '#size' => 8,
    '#weight' => -110,
    '#title' => t('Number of facets shown.'),
    '#description' => t('Number of facets shown in each group initially'),
    '#default_value' => variable_get('bibdk_facetbrowser_number_shown', 5),
  );

  $form['bibdk_facetbrowser_consecutive_number_shown'] = array(
    '#type' => 'textfield',
    '#size' => 8,
    '#weight' => -105,
    '#title' => t('Consecutive number of facets shown.'),
    '#description' => t('Number of facets shown in each group after the initial one'),
    '#default_value' => variable_get('bibdk_facetbrowser_consecutive_number_shown', 10),
  );

  $form['bibdk_facetbrowser_number_requested'] = array(
    '#type' => 'textfield',
    '#size' => 8,
    '#weight' => -100,
    '#title' => t('Number of facets requested from webservice.'),
    '#description' => t('Total number of facets shown in each group'),
    '#default_value' => variable_get('bibdk_facetbrowser_number_requested', 25),
  );

  $form['bibdk_facetbrowser_by_ajax'] = array(
    '#type' => 'checkbox',
    '#weight' => -100,
    '#title' => t('Facets by ajax'),
    '#description' => t('Get facets by ajax or not'),
    '#default_value' => variable_get('bibdk_facetbrowser_by_ajax', FALSE),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save changes'),
  );

  return $form;
}

/**
 * Submit handler for bibdk_facetbrowser_settings();
 */
function bibdk_facetbrowser_settings_submit($form, &$form_state) {
  $facets = $form_state['values']['bibdk_facetbrowser_facets'];
  foreach ($facets as $key => $facet) {
    if (empty($facet['name'])) {
      unset($facets[$key]);
    }
  }
  usort($facets, 'drupal_sort_weight');
  variable_set('bibdk_facetbrowser_facets', $facets);

  //setting for group_number_shown
  $number_of_group_facets = $form_state['values']['bibdk_facetbrowser_group_number_shown'];
  variable_set('bibdk_facetbrowser_group_number_shown', $number_of_group_facets);

  $number_of_facets = $form_state['values']['bibdk_facetbrowser_number_shown'];
  variable_set('bibdk_facetbrowser_number_shown', $number_of_facets);

  $facets_by_ajax = $form_state['values']['bibdk_facetbrowser_by_ajax'];
  variable_set('bibdk_facetbrowser_by_ajax', $facets_by_ajax);

  $consecutive_number_of_facets = $form_state['values']['bibdk_facetbrowser_consecutive_number_shown'];
  variable_set('bibdk_facetbrowser_consecutive_number_shown', $consecutive_number_of_facets);

  $number_of_facets_requested = $form_state['values']['bibdk_facetbrowser_number_requested'];
  variable_set('bibdk_facetbrowser_number_requested', $number_of_facets_requested);

  drupal_set_message(t('The configuration options have been saved.', array(), array('context' => 'bibdk_facetbrowser')));
}

/**
 * Returns HTML for facets admin form.
 */
function theme_bibdk_facetbrowser_settings($variables) {
  $form = $variables['form'];
  $map = array('disabled' => t('Disabled'), 'enabled' => t('Enabled'));

  $rows = array();

  drupal_add_tabledrag('facets', 'order', 'sibling', 'facet-weight');

  foreach (element_children($form['bibdk_facetbrowser_facets']) as $key) {
    $facet = &$form['bibdk_facetbrowser_facets'][$key];
    $row = array();
    $row[] = drupal_render($facet['name']);
    $row[] = drupal_render($facet['title']);
    $row[] = drupal_render($facet['weight']);
    $row[] = drupal_render($facet['delete']);
    $rows[] = array(
      'data' => $row,
      'class' => array('draggable'),
    );
  }

  $header = array(t('Name'), t('Title'), t('Weight'), t('Operations'));
  $output = theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('id' => 'facets')));
  $output .= drupal_render($form['actions']);
  $output = drupal_render_children($form) . $output;
  return $output;
}

/**
 *
 */
function bibdk_facetbrowser_delete_facet($form_id, $form_state, $facet_id) {
  $form['facet_id'] = array(
    '#type' => 'value',
    '#value' => $facet_id,
  );
  return confirm_form($form, t("Are you sure you want to delete @facet?", array('@facet' => $facet_id)), 'admin/config/ting/facets');
}

/**
 *
 */
function bibdk_facetbrowser_delete_facet_submit($form, &$form_state) {
  $facets = variable_get('bibdk_facetbrowser_facets', array());
  foreach ($facets as $key => $facet) {
    if ($facet['name'] == $form_state['values']['facet_id']) {
      unset($facets[$key]);
    }
  }
  variable_set('bibdk_facetbrowser_facets', $facets);
  drupal_set_message(t('@facet deleted.', array('@facet' => $form_state['values']['facet_id'], array('context' => 'bibdk_facetbrowser'))));
  $form_state['redirect'] = 'admin/config/ting/facets';
}
