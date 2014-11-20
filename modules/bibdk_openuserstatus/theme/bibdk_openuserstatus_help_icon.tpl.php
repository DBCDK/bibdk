<p class="helptext popover-button" title="<?php print $label; ?>">
  <a href="#" aria-label="<?php print t('Help', array(), array('context' => 'bibdk_theme')); ?>" role="button">?</a>
</p>
<div class="popover element-wrapper linkme-wrapper visuallyhidden hide-text">
  <p class="user-msg ">
    <?php print $label; ?>
  </p>
  <a href="#" aria-label="<?php print t('Close help', array(), array('context' => 'bibdk_theme')); ?>" 
     role="button" class="close icon icon-left icon-red-x "> 
  </a>
</div>
