<?php
/*
 * @file. preprocess facet_term_names template to add helptexts on facets select/deselect
 */

/**
 * preprocess facet_term_names template (@see bibdk_facetbrowser.module::hook_theme)
 *
 * @param $variables
 */
function template_preprocess_theme_facet_term_names(&$variables) {
  $facet_key = current(array_filter($variables['form']['#parents']));
  $facet_id = drupal_html_id('modal-' . $facet_key);

  $id = $facet_id . 'bibdk-facetbrowser-help-select';
  $help_select_txt = t('help_select_text', array(), array('context' => 'bibdk_facetbrowser'));
  $help_select = bibdk_facetbrowser_help_link($help_select_txt, $id);
  $variables['form']['#help_select'] = $help_select;

  $id = $facet_id . 'bibdk-facetbrowser-help-deselect';
  $help_deselect_txt = t('help_deselect_text', array(), array('context' => 'bibdk_facetbrowser'));
  $help_deselect = bibdk_facetbrowser_help_link( $help_deselect_txt, $id );
  $variables['form']['#help_deselect'] = $help_deselect;
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
