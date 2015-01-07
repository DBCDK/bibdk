<?php
/* This template will toogle between show/hide 'export links'
 * Uses foundations dropdown to expand options
 */

?>
<div class="action_element_refexportlinks">
  <a class='refexport-toggle-link' data-dropdown="<?php print $export_id; ?>" aria-controls="<?php print $export_id; ?>" aria-expanded="false">
    <?php print t('refexport_more', array(), array('context' => 'bibdk_actions')); ?>
  </a>

  <div id="<?php print $export_id; ?>" class="f-dropdown" data-dropdown-content aria-hidden="true" tabindex="-1">
    <?php print drupal_render($linktext); ?>
  </div>
</div>
