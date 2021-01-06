<article class="<?php print $classes; ?>">
  <div class="element-section clearfix" data-bibdk-favourite-more-info-toggler>
    <div class="bibdk-favourite--header">
      <h2 class="bibdk-favourite--branch-name"><?php print $branchName; ?></h2>
      <span class="bibdk-favourite--more-info-toggle-indicator"></span>
      <?php if (!empty($agencyName)) : ?>
        <span class="bibdk-favourite--agency-name"><?php print $agencyName; ?></span>
      <?php endif; ?>
      <?php if (!empty($temporarilyClosedReason)) : ?>
        <strong><br/><?php print $temporarilyClosedReason; ?></strong>
      <?php endif; ?>
    </div>
    <?php if (!empty($actions)) : ?>
      <div class="bibdk-favourite--actions"><?php print $actions; ?></div>
    <?php endif; ?>
    <div class="messages-<?php print $branchid ?> clearfix"></div>
  </div>
  <?php if (!empty($moreinfo)): ?>
    <div class="element-section bibdk-favourite--more-info">
      <?php print drupal_render($moreinfo); ?>
    </div>
  <?php endif; ?>
</article>
