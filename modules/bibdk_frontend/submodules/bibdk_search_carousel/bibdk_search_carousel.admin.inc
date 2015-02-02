<?php
/**
 * @file
 * Admin related backend.
 */

/**
 * Admin settings form for frontend display of carousel.
 */
function bibdk_search_carousel_admin_form($form, &$form_state) {
  $form = array();

  $form['bibdk_search_carousel_search'] = array(
    '#type' => 'fieldset',
    '#title' => t('Bibliotek search settings: Offset, frequency, dateformats and expanded queries.'),
  );

  $form['bibdk_search_carousel_search']['bibdk_search_carousel_dateformat'] = array(
    '#type' => 'textfield',
    '#title' => t('Date format.', array(), array('context' => 'bibdk_search_carousel')),
    '#description' => t('PHP date format. Jfr. http://php.net/manual/en/function.date.php', array(), array('context' => 'bibdk_search_carousel')),
    '#default_value' => variable_get('bibdk_search_carousel_dateformat', 'bk\mYW'),
  );

  $form['bibdk_search_carousel_search']['bibdk_search_carousel_search_test']['boolean_information'] = array(
    '#markup' =>  t(
      'Date format example: "@dateformat" = "@date"',
      array(
        '@dateformat' => variable_get('bibdk_search_carousel_dateformat', 'bk\mYW'),
        '@date' => date( variable_get('bibdk_search_carousel_dateformat', 'bk\mYW'))
      ),
      array(
        'context' => 'bibdk_search_carousel'
      )
    )
  );

  $form['bibdk_search_carousel_search']['bibdk_search_carousel_week_search_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Search code', array(), array('context' => 'bibdk_search_carousel')),
    '#description' => t('Search code for week number.', array(), array('context' => 'bibdk_search_carousel')),
    '#default_value' => variable_get('bibdk_search_carousel_week_search_code', 'dkcclterm.kk'),
  );

  $form['bibdk_search_carousel_search']['boolean_information'] = array(
    '#markup' =>  t(
      'Boolean operators used: "and", "or" and "not"',
      array(),
      array(
        'context' => 'bibdk_search_carousel'
      )
    )
  );

  return system_settings_form($form);
}

