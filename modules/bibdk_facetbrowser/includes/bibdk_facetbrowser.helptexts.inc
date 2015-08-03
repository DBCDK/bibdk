<?php
/*
 * @file. preprocess facet_term_names template to add helptexts on facets select/deselect
 */


/**
 * Implements hook_form_FORM_ID_alter.
 *
 * Add help texts to filter form.
 *
 * @param $form
 * @param $form_state
 */
function bibdk_facetbrowser_form_bibdk_facetbrowser_filter_form_alter(&$form, $form_state){
  $facet_key = $form['#facet_key'];
  $facet_id = drupal_html_id('modal-' . $facet_key);

  $id = $facet_id . 'bibdk-facetbrowser-help-select';
  $help_select_txt = t('help_select_text', array(), array('context' => 'bibdk_facetbrowser'));
  $help_select = bibdk_facetbrowser_help_link($help_select_txt, $id);

  $form['headlines']['container']['select']['help'] = $help_select;

  $id = $facet_id . 'bibdk-facetbrowser-help-deselect';
  $help_deselect_txt = t('help_deselect_text', array(), array('context' => 'bibdk_facetbrowser'));
  $help_deselect = bibdk_facetbrowser_help_link( $help_deselect_txt, $id );
  $form['headlines']['container']['deselect']['help'] = $help_deselect;

  dpm(func_get_args());
}

/**
 * prepare a foundation.dropdown (@see foundation.dropdown.js)
 *
 * @param $txt; the text to display in dropdown
 * @param $id; id of the dropdown to show/hide
 * @return array; render array [drop,content]
 */
function bibdk_facetbrowser_help_link($txt, $id) {
  return array(
    'drop' => array(
      '#theme' => 'link_with_svg',
      '#text' => '',
      '#path' => FALSE,
      '#options' => array(
        'attributes' => array(
          'data-dropdown' => $id,
          'aria-controls' => $id,
          'aria-expanded' => "false",
          'class' => array(
            $id,
          )
        ),
        'html' => TRUE,
      ),
      '#svg' => 'svg-question',
    ),
    'content' => array(
      '#theme' => 'html_tag',
      '#tag' => 'div',
      '#value' => $txt,
      '#attributes' => array(
        "id" => $id,
        "data-dropdown-content" => '',
        "aria-hidden" => "true",
        "tabindex" => "-1",
        "class" => array(
          "f-dropdown",
          $id,
        )
      ),
    ),
  );
}