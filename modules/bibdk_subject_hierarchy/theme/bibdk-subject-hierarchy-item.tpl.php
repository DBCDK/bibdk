<?php
/**
 * @file
 * Theme implementation for bibdk_subject_hierarchy_item.
 */
?>

<div class="themes__sublists">
  <div class="themes__close-button icon icon-blue-x">&nbsp;</div>
  <div class="themes__breadcrumb">
    <?php echo drupal_render($breadcrumbs); ?>
  </div>
  <div class="themes__sublist">
    <ul>
      <?php foreach ($variables['hierarchy']['term'] as $key => $item) {
        if (!empty($item['cql']) && empty($item['term'])) {
          $url = 'search/' . $variables['search_path'] . '/' . trim($item['cql']);
          $attributes['attributes'] = array();
        }
        else {
          $url = 'bibdk_subject_hierarchy/nojs/' . $variables['current_key'] . ',' . $key;
          $attributes['attributes']['class'] = array('use-ajax', 'nesting');
        }
        echo '<li>' . l($item['ord'], $url, $attributes) . "</li>\n";
      } ?>
    </ul>
  </div>
</div>
