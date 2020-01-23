<?php

/**
 * @file
 * Theme implementation for table with sorting option.
 */

drupal_add_tabledrag('elements', 'order', 'sibling', 'element-weight');

?>
<table id="elements" class="sticky-enabled">
  <thead>
    <tr>
      <th><?php print t('Values'); ?></th>
      <th><?php print t(''); ?></th>
      <th><?php print t('Edit'); ?></th>
      <th><?php print t('Delete'); ?></th>
      <th><?php print t('Weight'); ?></th>
      <th><?php print t('Disabled'); ?></th>
    </tr>
  </thead>
  <tbody>
    <?php foreach (element_children($form) as $key => $element):
      $data = $form[$element]; ?>
        <tr class="draggable <?php print $key % 2 == 0 ? 'odd' : 'even'; ?>">
          <td class="element"><?php print $data['#title']; ?></td>
          <td><?php print drupal_render($data['e_uuid']); print drupal_render($data['element_title']); ?></td>
          <td><?php print drupal_render($data['edit']); ?></td>
          <td><?php print drupal_render($data['delete']); ?></td>
          <td><?php print drupal_render($data['sort']); ?></td>
          <td><?php print drupal_render($data['is_disabled']); ?></td>
        </tr>
    <?php endforeach; ?>
  </tbody>
</table>
