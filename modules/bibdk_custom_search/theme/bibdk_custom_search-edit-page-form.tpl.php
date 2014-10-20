<?php

/**
 * @file
 * Default theme implementation to configure pages.
 */

$form['page_title']['#title'] .= ' <span class="helptext" title="' . htmlspecialchars(strip_tags($form['page_title']['#description'])) . '">?</span>';
unset($form['page_title']['#description']);

$form['menu_title']['#title'] .= ' <span class="helptext" title="' . htmlspecialchars(strip_tags($form['menu_title']['#description'])) . '">?</span>';
unset($form['menu_title']['#description']);

$form['page_path']['#title'] .= ' <span class="helptext" title="' . htmlspecialchars(strip_tags($form['page_path']['#description'])) . '">?</span>';
unset($form['page_path']['#description']);

$form['delimiter']['#title'] .= ' <span class="helptext" title="' . htmlspecialchars(strip_tags($form['delimiter']['#description'])) . '">?</span>';
unset($form['delimiter']['#description']);

$form['expand']['#title'] .= ' <span class="helptext" title="' . htmlspecialchars(strip_tags($form['expand']['#description'])) . '">?</span>';
unset($form['expand']['#description']);

$form['is_disabled']['#title'] .= ' <span class="helptext" title="' . htmlspecialchars(strip_tags($form['is_disabled']['#description'])) . '">?</span>';
unset($form['is_disabled']['#description']);


?>
<?php print drupal_render($form['p_uuid']); ?>
<?php print drupal_render($form['sort']); ?>
<div id="edit-search-page">
      <?php print drupal_render($form['page_title']); ?>
      <?php print drupal_render($form['menu_title']); ?>
      <?php print drupal_render($form['page_path']); ?>
      <?php print drupal_render($form['delimiter']); ?>
      <?php print drupal_render($form['expand']); ?>
      <?php print drupal_render($form['is_disabled']); ?>
</div>