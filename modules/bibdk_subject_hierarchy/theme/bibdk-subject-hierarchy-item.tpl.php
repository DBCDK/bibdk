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
      <?php
        foreach ($variables['hierarchy'] as $key => $item) {
            echo render($item);
        }
      ?>
    </ul>
  </div>

</div>
