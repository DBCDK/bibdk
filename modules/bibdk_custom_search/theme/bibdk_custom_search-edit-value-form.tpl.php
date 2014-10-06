<?php

/**
 * @file
 * Default theme implementation to configure search page element.
 */

drupal_add_js(drupal_get_path('module', 'bibdk_custom_search') . '/js/bibdk_custom_search_value.js');

$form['value_title']['#title'] .= ' <span class="helptext" title="' . htmlspecialchars(strip_tags($form['value_title']['#description'])) . '">?</span>';
unset($form['value_title']['#description']);

$form['search_code']['#title'] .= ' <span class="helptext" title="' . htmlspecialchars(strip_tags($form['search_code']['#description'])) . '">?</span>';
unset($form['search_code']['#description']);

$form['default_value']['#title'] .= ' <span class="helptext" title="' . htmlspecialchars(strip_tags($form['default_value']['#description'])) . '">?</span>';
unset($form['default_value']['#description']);

$form['is_disabled']['#title'] .= ' <span class="helptext" title="' . htmlspecialchars(strip_tags($form['is_disabled']['#description'])) . '">?</span>';
unset($form['is_disabled']['#description']);

?>
<?php print drupal_render($form['v_uuid']); ?>
<?php print drupal_render($form['sort']); ?>
<table id="edit-search-page-value">
  <tbody>
    <tr>
      <td><?php print drupal_render($form['value_title']); ?></td>
      <td><?php print drupal_render($form['value_type']); ?></td>
      <td><?php print drupal_render($form['search_code']); ?></td>
      <td><?php print drupal_render($form['default_value']); ?></td>
      <td><?php print drupal_render($form['is_disabled']); ?></td>
    </tr>
  </tbody>
</table>
