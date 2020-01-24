<?php

/**
 * @file
 * Theme implementation for table with sorting option.
 */

drupal_add_tabledrag('options', 'order', 'sibling', 'element-weight');

?>
<table id="options" class="sticky-enabled">
  <thead>
    <tr>
      <th><?php print t('Label'); ?></th>
      <th><?php print t('Value'); ?></th>
      <th><?php print t('Submenu'); ?></th>
      <th><?php print t('Delete'); ?></th>
      <th><?php print t('Weight'); ?></th>
      <th><?php print t('Disabled'); ?></th>
    </tr>
  </thead>
  <tbody>
    <?php foreach (element_children($form) as $key => $element):
      $data = $form[$element]; ?>
        <tr class="draggable <?php print $key % 2 == 0 ? 'odd' : 'even'; ?>">
          <td class="element"><?php print drupal_render($data['oid']); print drupal_render($data['label']); ?></td>
          <td><?php print drupal_render($data['value']); ?></td>
          <td><?php print drupal_render($data['expand']); ?></td>
          <td><?php print drupal_render($data['delete']); ?></td>
          <td><?php print drupal_render($data['sort']); ?></td>
          <td><?php print drupal_render($data['is_disabled']); ?></td>
        </tr>
    <?php endforeach; ?>
  </tbody>
</table>
