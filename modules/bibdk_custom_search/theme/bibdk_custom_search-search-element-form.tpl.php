<?php
/**
 * @file
 * Theme implementation for bib.dk custom search elements.
 */
?>
<div class='fieldset-legend'><label for="<?php print $element_id; ?>"><?php print $title; ?></label></div>
<div class="fieldset-description"><?php print $description;?></div>
<p class="helptext popover-button" title="<?php print strip_tags($help); ?>">
  <a href="#" aria-label="<?php print t('Help', array(), array('context' => 'bibdk_theme')); ?>" role="button">?</a>
</p>
<div class="popover element-wrapper linkme-wrapper visuallyhidden hide-text">
  <p class="user-msg ">
    <?php print $help; ?>
  </p>
  <a href="#" aria-label="<?php print t('Close help', array(), array('context' => 'bibdk_theme')); ?>" 
     role="button" class="close icon icon-left icon-red-x "> 
  </a>
</div>
<div class="bibdk-custom-search-element clearfix">
  <?php print drupal_render_children($form); ?>
</div>