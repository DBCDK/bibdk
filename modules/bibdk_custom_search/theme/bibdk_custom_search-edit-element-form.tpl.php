<?php

/**
 * @file
 * Default theme implementation to configure search page element.
 */

$form['element_title']['#title'] .= ' <span class="helptext" title="' . htmlspecialchars(strip_tags($form['element_title']['#description'])) . '">?</span>';
unset($form['element_title']['#description']);

$form['element_label']['#title'] .= ' <span class="helptext" title="' . htmlspecialchars(strip_tags($form['element_label']['#description'])) . '">?</span>';
unset($form['element_label']['#description']);

$form['description']['#title'] .= ' <span class="helptext" title="' . htmlspecialchars(strip_tags($form['description']['#description'])) . '">?</span>';
unset($form['description']['#description']);

$form['help_text']['#title'] .= ' <span class="helptext" title="' . htmlspecialchars(strip_tags($form['help_text']['#description'])) . '">?</span>';
unset($form['help_text']['#description']);

$form['is_disabled']['#title'] .= ' <span class="helptext" title="' . htmlspecialchars(strip_tags($form['is_disabled']['#description'])) . '">?</span>';
unset($form['is_disabled']['#description']);

?>
<?php print drupal_render($form['id']); ?>
<?php print drupal_render($form['sort']); ?>
<table id="edit-search-page-element">
  <tbody>
    <tr>
      <td><?php print drupal_render($form['element_title']); ?></td>
      <td><?php print drupal_render($form['element_label']); ?></td>
      <td><?php print drupal_render($form['access_key']); ?></td>
      <td><?php print drupal_render($form['tab_index']); ?></td>
      <td><?php print drupal_render($form['is_disabled']); ?></td>
    </tr>
    <tr>
      <td><?php print drupal_render($form['description']); ?></td>
      <td colspan="4"><?php print drupal_render($form['help_text']); ?></td>
    </tr>
  </tbody>
</table>
