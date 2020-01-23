<?php

/**
 * @file
 * Theme implementation to configure search control.
 */

?>
<ul>
<?php foreach (element_children($form) as $key => $element):
  $data = $form[$element]; ?>
  <li class="edit-search-control">
    <p class="title"><?php print drupal_render($data['title']); ?></p>
    <p class="edit"><?php print drupal_render($data['edit']); ?></p>
    <p class="delete"><?php print drupal_render($data['delete']); ?></p>
    <?php if ( isset($data['description']) ) { ?>
    <p class="description">( <?php print drupal_render($data['description']); ?> )</p>
    <?php } ?>
  </li>
<?php endforeach; ?>
</ul>

