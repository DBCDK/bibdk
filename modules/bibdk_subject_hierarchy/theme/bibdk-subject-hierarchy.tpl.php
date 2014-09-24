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
        <?php print $helptext; ?>
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
