<?php

/**
 * @file
 * Theme implementation to edit search control.
 */
?>

<?php print drupal_render($form['id']); ?>

<div id="edit-search-page-element">
  <div class="left">
    <div class="wrapper">
      <?php print drupal_render($form['title']); ?>
      <?php print drupal_render($form['type']); ?>
      <?php print drupal_render($form['label']); ?>
      <?php print drupal_render($form['name']); ?>
    </div>
  </div>
  <div class="center">
    <div class="wrapper">
      <?php print drupal_render($form['description']); ?>
    </div>
  </div>
  <div class="right">
    <div class="wrapper">
      <?php print drupal_render($form['access_key']); ?>
      <?php print drupal_render($form['tab_index']); ?>
    </div>
  </div>
</div>
