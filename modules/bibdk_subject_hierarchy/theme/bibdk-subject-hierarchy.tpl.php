<?php

/**
 * @file
 * Theme implementation for bibdk_subject_hierarchy.
 */
?>

<div id="bibdk-subject-hierarchy">

  <div class="bibdk-subject-hierarchy-header">

    <div class="bibdk-subject-hierarchy-header-title">
      <?php print $header; ?>
    </div>

    <div class="bibdk-subject-hierarchy-header-helptext">
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
      <div class="show-for-large-up">
        <?php print drupal_render($searchfield_link); ?>
      </div>
      <div class="hide-for-large-up">
        <?php
          $searchfield_link['#printed'] = FALSE;
          $searchfield_link['#attributes']['data-options'] = 'align:bottom';
          print drupal_render($searchfield_link);
        ?>
      </div>

      <div id="searchfield-dropdown" data-dropdown-content class="f-dropdown content medium" aria-hidden="true" tabindex="-1">
        <?php print drupal_render($searchfield); ?>
      </div>
    </div>

  </div>

  <div id="bibdk-subject-hierarchy-content" class="bibdk-subject-hierarchy-inner clearfix">
  <?php foreach ($rows as $row) : ?>
    <?php print $row; ?>
  <?php endforeach; ?>
  </div>

  <div id="bibdk-subject-hierarchy-searchresult"></div>

</div>
