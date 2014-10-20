<?php

/**
 * @file
 * Theme implementation for table with sorting option on weight and region.
 */

$element_regions = array(
  'main' => array('title' => t('Main'), 'count' => 0),
  'expand' => array('title' => t('Expanded'), 'count' => 0),
  'add' => array('title' => t('Add element'), 'count' => 0),
);
foreach (element_children($form) as $element) $element_regions[$form[$element]['region']['#value']]['count']++;

// Add table javascript.
drupal_add_js('misc/tableheader.js');
drupal_add_js(drupal_get_path('module', 'bibdk_custom_search') . '/js/bibdk_custom_search_sort.js');
foreach ($element_regions as $region => $title) {
  drupal_add_tabledrag('elements', 'match', 'sibling', 'region-select', 'region-select-' . $region, NULL, FALSE);
  drupal_add_tabledrag('elements', 'order', 'sibling', 'sort-select', 'sort-select-' . $region);
}

?>
<table id="elements" class="sticky-enabled">
  <thead>
    <tr>
      <th><?php print t('Element'); ?></th>
      <th><?php print t(''); ?></th>
      <th><?php print t('Region'); ?></th>
      <th><?php print t('Edit'); ?></th>
      <th><?php print t('Remove'); ?></th>
      <th><?php print t('Weight'); ?></th>
      <th><?php print t('Disabled'); ?></th>
    </tr>
  </thead>
  <tbody>
    <?php foreach ($element_regions as $region => $region_data): ?>
    <?php $row = 1; ?>
      <tr class="region-title region-title-<?php print $region?>">
        <td colspan="7"><?php print $region_data['title']; ?></td>
      </tr>
      <tr class="region-message region-<?php print $region?>-message <?php print((!$region_data['count']) ? 'region-empty' : 'region-populated'); ?>">
        <td colspan="7"><em><?php print t('No elements in this region'); ?></em></td>
      </tr>
      <?php foreach (element_children($form) as $key => $element):
        $data = $form[$element];
        if ($data['region']['#value'] == $region): ?>
          <tr class="draggable <?php print $row % 2 == 0 ? 'odd' : 'even'; ?>">
            <td class="element"><?php print $data['#title']; ?></td>
            <td><?php print drupal_render($data['e_uuid']); print drupal_render($data['v_uuid']); ?></td>
            <td><?php print drupal_render($data['region']); ?></td>
            <td><?php print drupal_render($data['edit']); ?></td>
            <td><?php print drupal_render($data['delete']); ?></td>
            <td><?php print drupal_render($data['sort']); ?></td>
            <td><?php print drupal_render($data['is_disabled']); ?></td>
          </tr>
          <?php $row++;
        endif;
      endforeach;
    endforeach; ?>
  </tbody>
</table>