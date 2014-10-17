<?php
/* This template will toogle between show/hide 'export links'
 * Calls script.js toggle-next-section 
 */
?>
<div class="action_element_refexportlinks">
  <div class="element-section">
    <div class="toggle-next-section">
      <a class="show-more" href="#">
        <span class="icon icon-left icon-blue-down">&nbsp;</span>
        <?php print t('refexport_more', array(), array('context' => 'bibdk_actions')); ?>
      </a>
      <a class="show-less visuallyhidden" href="#">
        <span class="icon icon-left icon-blue-up">&nbsp;</span>
        <?php print t('refexport_less', array(), array('context' => 'bibdk_actions')); ?>
      </a>
    </div>
  </div>
  <div class="element-section visuallyhidden">
    <?php print drupal_render($linktext); ?>
  </div>
</div>