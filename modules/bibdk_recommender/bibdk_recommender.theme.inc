<?php
/**
 * @file bibdk_recommender.theme.inc
 * Theme functions for Bibliotek.dk recommender
 */

/*
 * Preprocess function for bibdk_carousel_cover.
 */
function template_preprocess_bibdk_recommender_item(&$variables) {

  // Quickfix to avoid notices from template_process;
  $variables['classes_array'] = array();
  $variables['attributes_array'] = array();
  $variables['title_attributes_array'] = array();
  $variables['content_attributes_array'] = array();
  
  $image_style   = isset($variables['style']) ? $variables['style'] : 'thumbnail';
  $image_pid     = $variables['pid'];
  $image_creator = truncate_utf8($variables['creator'], 30, $wordsafe = TRUE, $add_ellipsis = TRUE, $min_wordsafe_length = 2);
  $image_title   = truncate_utf8($variables['title'], 40, $wordsafe = TRUE, $add_ellipsis = TRUE, $min_wordsafe_length = 2);
  $image_type    = $variables['work_type'];
  $image_alt     = isset($image_creator) ? $image_title . ' : ' . $image_creator : $image_title;
  
  if ($image_type == 'other') {
    $image_type = 'none';
  }

  $variables['elements']['#id'] = drupal_html_id(md5($image_pid, TRUE));

  // if there's a cover in the file system, we'll use it. Otherwise, we'll get it by AJAX
  $file_path = _bibdk_covers_object_path($image_pid, $image_style . 'Url');

  $image_markup = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('bibdk-recommender-cover-placeholder'),
      'data-pid' => $image_pid,
      'data-alt' => $image_alt,
      'data-style' => $image_style,
    ),
  );
  
  // Determine if the local id is a known negative. If so, don't trigger javascript.
  if ( cache_get('open_moreinfo:thumbnailUrl:' . $image_pid, 'cache') ) {
    $image_markup['#attributes']['class'][] = 'bibdk-recommender-cover-processed';
  }
  
  if (file_exists($file_path)) {
    // Don't trigger javascript if we have an image..
    $image_markup['#attributes']['class'][] = 'bibdk-recommender-cover-processed';
    $image_markup['image_exist'] = array(
      '#theme' => 'image_style',
      '#path' => $file_path,
      '#style_name' => $image_style,
      '#alt' => $image_alt,
      '#attributes' => array(
        'title' => $image_alt,
      ),
    );
  } else {
    // Default element if there's no covers cached
    $image_markup['material_type'] = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array('bibdk-recommender-material-type'),
      ),
      'material_type_image' => array(
        '#theme' => 'bibdk_recommender_svg',
        '#material_type' => $image_type,
      ),
    );
  }
  
  $image_markup['material_biblio_wrapper'] = array(
    'material_biblio_wrapper' => array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array('bibdk-recommender-biblio-wrapper'),
      ),
      'material_biblio' => array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => array('bibdk-recommender-biblio'),
        ),
        'image_title' => array(
          '#type' => 'html_tag',
          '#tag' => 'span',
          '#attributes' => array('class' => 'bibdk-recommender-biblio-title'),
          '#value' => $image_title,
        ),
        'image_creator' => array(
          '#type' => 'html_tag',
          '#tag' => 'span',
          '#attributes' => array('class' => 'bibdk-recommender-biblio-creator'),
          '#value' => $image_creator,
        ),
      ),
    )
  );
    
  // front cover image with link to search
  $variables['elements']['#image'] = array(
    '#type' => 'link',
    '#title' => drupal_render($image_markup),
    '#href' => 'work/' . $image_pid,
    '#options' => array(
      'html' => TRUE,
      'attributes' => array(
        'title' => t("Search for %work", array('%work' => $image_alt), array('context' => 'bibdk_recommender')),
        'aria-title' => t("Search %work", array('%work' => $image_alt), array('context' => 'bibdk_recommender')),
      ),
    ),
  );

}
