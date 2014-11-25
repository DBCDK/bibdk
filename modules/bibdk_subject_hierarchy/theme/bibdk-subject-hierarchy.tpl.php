<?php

/**
 * @file
 * Theme implementation for bibdk_subject_hierarchy.
 */
?>

<div id="bibdk-subject-hierarchy" class="themes clearfix">
  <div class="container clearfix">
    <div class="clearfix">
      <div class="bibdk-subject-hierarchy-header">
        <?php print $header; ?>
      </div>
      <div class="bibdk-subject-hierarchy-helptext">
        <p class="helptext popover-button" title="<?php print $helptext; ?>">
          <a href="#" tabindex="0" aria-label="<?php print t('Help', array(), array('context' => 'bibdk_theme')); ?>" role="button">?</a>
        </p>
        <div class="popover element-wrapper linkme-wrapper visuallyhidden hide-text">
          <p class="user-msg ">
            <?php print $helptext; ?>
          </p>
          <a href="#"  tabindex="0" aria-label="<?php print t('Close help', array(), array('context' => 'bibdk_theme')); ?>" 
             role="button" class="close icon icon-left icon-red-x "> 
          </a>
        </div>
      </div>
      <div class="subject-hierarchy-searchfield">
        <?php print drupal_render($searchfield); ?>
      </div>
    </div>
    <div id="bibdk-subject-hierarchy-content">
    <?php foreach ($rows as $row) : ?>
      <?php print $row; ?>
    <?php endforeach; ?>
    </div>
    <div id="bibdk-subject-hierarchy-searchresult">
    </div>
    </div>
</div>
