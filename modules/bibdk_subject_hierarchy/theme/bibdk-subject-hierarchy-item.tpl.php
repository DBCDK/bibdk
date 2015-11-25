<?php
/**
 * @file
 * Theme implementation for bibdk_subject_hierarchy_item.
 */
?>

<div class="subjects-sublists">

  <div class="subjects-close-button"><?php echo drupal_render($close_button); ?></div>

  <div class="subjects-breadcrumb">
    <?php echo drupal_render($breadcrumbs); ?>
  </div>

  <div class="subjects-sublists-heading">
    <?php echo drupal_render($heading); ?>
  </div>

  <div class="subjects-sublist">
    <ul>
      <?php foreach ($variables['hierarchy']['term'] as $key => $item) {
        $link = array(
            '#theme' => 'link',
            '#text' => $item['ord'],
            '#path' => NULL,
            '#options' => array('attributes' => array()),
            '#prefix' => '<li>',
            '#suffix' => '</li>'
        );
        if (!empty($item['cql']) && empty($item['term'])) {
            $link['#path'] = 'search/' . $variables['search_path'];
            $link['#options']['query'] = array('search_block_form' => trim($item['cql']));
            $link['#options']['fragment'] = 'content';
            $link['#options']['html'] = TRUE;
        }
        else {
            $link['#path'] = 'bibdk_subject_hierarchy/nojs/' . $variables['current_key'] . ',' . $key;
            $link['#options']['attributes']['class'] = array('use-ajax', 'nesting');
        }
        echo render($link);
      } ?>
    </ul>
  </div>

</div>
