<?php
/**
 * @file bibdk_covers.theme.inc
 * Theme functions for Bibliotek.dk covers
 */

function template_preprocess_bibdk_object_cover(&$variables) {

  // Quickfix to avoid notices from template_process;
  $variables['classes_array'] = array();
  $variables['attributes_array'] = array();
  $variables['title_attributes_array'] = array();
  $variables['content_attributes_array'] = array();

  $modal_link = array();

  $image_style = $variables['elements']['#image_style'];

  $object = $variables['elements']['#object'];

  foreach ($object->manifestations as $key => $manifestation) {
    if ( isset($manifestation->ding_entity_id) ) {
      $local_id_exploded = explode(':', $manifestation->ding_entity_id);
      $work_local_ids[] = $local_id_exploded[1];
    }
  }



  $variables['elements']['#id'] = drupal_html_id(md5(implode($work_local_ids), TRUE));

  $variables['elements']['#front_cover_large_image'] = array('#markup' => 'fubar');

  $variables['elements']['#back_cover_large_pdf'] = array('#markup' => 'fubar');

  $variables['elements']['#close_button'] = array(
    '#theme' => 'link_with_svg',
    '#text' => '',
    '#path' => FALSE,
    '#options' => array(
      'attributes' => array(
        'class' => array('close-reveal-modal'),
      ),
    ),
    '#svg' => 'svg-close',
  );


  // Set initial values required by the template, and check if there's an image available locally
  $cover_file_path = FALSE;
  $backcoverpdf_file_path = $backcoverpdf_local_id = FALSE;

  $variables['elements']['#classes'] = array('bibdk-cover', 'bibdk-cover-style-' . $image_style);

  foreach ($work_local_ids as $key => $lid) {

    // if there's a cover in the file system, we'll use it. Otherwise, we'll get it by AJAX
    if ( !$cover_file_path ) { // we'll just use the first available local image.
      $file_path = _bibdk_covers_object_path($lid, 'detailUrl');
      if ( file_exists($file_path) ) {
        $cover_file_path = $file_path;
        $local_id = $lid;
      }
    }

    // ditto back cover pdf
    if ( !$backcoverpdf_file_path ) { 
      $file_path = _bibdk_covers_object_path($lid, 'backpagePdfUrl');
      if ( file_exists($file_path) ) {
        $backcoverpdf_file_path = $file_path;
        $backcoverpdf_local_id = $lid;
      }
    }

    // we don't know which local_id will be used, so we'll list each as a class
    if ( !empty($lid) ) {
      $variables['elements']['#classes'][] = 'bibdk-cover-work-object-id-' . $lid;
    }

  }

  // Default link if there's no covers cached
  $variables['elements']['#image'] =  array(
    '#type' => 'link',
    '#title' => '',
    // '#title_display' => 'invisible',
    '#href' => '#',
    '#options' => array(
      'attributes' => array(
        'title' => t('See large image', array(), array('context' => 'bibdk_covers')),
        'aria-label' => t('See large image', array(), array('context' => 'bibdk_covers')),
        'data-reveal-id' => 'reveal-cover-large-' . $variables['elements']['#id'],
      ),
    ),
  );

  $variables['elements']['#no_image_style'] = ' style="display:none"';

  // If we already have the image available locally then just use it
  if ( $cover_file_path ) {

    // get image alt text
    $alt = '';
    if ( isset($object->work->creators) ) {
      if ( is_array($object->work->creators->creator) ) {
        foreach ($object->work->creators->creator as $key => $creator) {
          $creators[] = $creator->display->{'$'};
        }
        $alt = implode(', ', $creators);
      }
      else {
        $alt = $object->work->creators->creator->display->{'$'};
      }
      $alt .= ': ' . $object->work->title->titleSpecific->{'$'};
    }
    else {
      $alt = $object->work->title->titleSpecific->{'$'};
    }

    // thumbnail image with link to full cover in modal window
    $variables['elements']['#image'] = array(
      '#type' => 'link',
      '#title' => theme('image_style', array('style_name' => $image_style, 'path' => $cover_file_path, 'alt' => $alt)),
      '#href' => '#',
      '#options' => array(
        'html' => TRUE,
        'attributes' => array(
          'title' => t('See large image foo', array(), array('context' => 'bibdk_covers')),
          'aria-label' => t('See large image', array(), array('context' => 'bibdk_covers')),
          'data-reveal-id' => 'reveal-cover-large-' . $variables['elements']['#id'],
        ),
      ),
    );

    $variables['elements']['#no_image_style'] = ''; 

    // front cover image (shown in modal window)
    $variables['elements']['#front_cover_large_image'] = array(
      '#theme' => 'image_style',
      '#path' => $cover_file_path,
      '#style_name' => 'large',
      '#attributes' => array(
        'alt' => $alt,
        'title' => t('large cover image', array(), array('context' => 'bibdk_covers')),
      ),
    );

    // back cover pdf object (shown in modal window)
    if ( $wrapper = file_stream_wrapper_get_instance_by_uri($backcoverpdf_file_path) ) {
      $backcover_uri = $wrapper->getExternalUrl();
      $variables['elements']['#back_cover_large_pdf'] = array(
        '#markup' =>
          '<object data="' . $backcover_uri . '?page=1&amp;view=Fit" type="application/pdf" width="590" height="925">
              <p>It appears you don\'t have a PDF plugin for this browser.
                 No biggie... you can <a href="' . $backcover_uri . '">click here to download the PDF file.</a></p>
           </object>'
      );
    }

    // Avoid further javascript processing
    $variables['elements']['#classes'][] = 'bibdk-cover-processed';
  }
  // front cover modal link: 
  $options = array(
    'html' => FALSE,
    'attributes' => array(
      'class' => array('work-cover-front', 'active'),
      'title' => t('See large cover image', array(), array('context' => 'bibdk_covers')),
      'aria-label' => t('See large cover image', array(), array('context' => 'bibdk_covers')),
      'data-reveal-id' => 'reveal-cover-large-' . $variables['elements']['#id'],
    )
  );
  if ( !file_exists($backcoverpdf_file_path) ) {
    $options['attributes']['style'] = 'display:none';
  }
  $variables['elements']['#front_cover_large_link'] = array(
    '#type' => 'link',
    '#title' => '',
    '#href' => '',
    '#options' => $options,
  );


  // ditto back cover pdf:
  $options = array(
    'html' => FALSE,
    'attributes' => array(
      'class' => array('work-cover-back'),
      'title' => t('See large back cover image', array(), array('context' => 'bibdk_covers')),
      'aria-label' => t('See large back cover image', array(), array('context' => 'bibdk_covers')),
      'data-reveal-id' => 'reveal-cover-back-' . $variables['elements']['#id'],
    ),
  );
  if ( !file_exists($backcoverpdf_file_path) ) {
    $options['attributes']['style'] = 'display:none';
  }
  $variables['elements']['#back_cover_large_link'] = array(
    '#type' => 'link',
    '#title' => '',
    '#href' => '',
    '#options' => $options,
  );

}
