<!-- work tabs -->
<div class="worktabs bibdk-tabs bibdk-tabs-light">
  <!-- tabs-nav -->
  <div class="tabs-nav clearfix">
    <?php foreach ($tabs as $type => $tab) : ?>
    <a href="#<?php print $type . $pid; ?>" id='<?php print drupal_html_id($type); ?>' class="<?php print $type; ?> <?php print $tab['class']; ?>"><?php print render($tab['title']); ?></a>
    <?php endforeach; ?>
  </div>
  <!-- tabs-nav -->
  <div class="tabs-sections-wrapper">
    <div class="tabs-sections">
      <?php foreach ($tabs as $type => $tab) : ?>
        <div id="<?php print $type . $pid; ?>" class="tabs-section <?php print $tab['active']; ?>">
          <dl class="accordion" data-accordion>
            <?php print render($tab['content']); ?>
          </dl>
        </div>
      <?php endforeach; ?>
      <!-- tabs-section -->
    </div>
    <!-- tabs-sections -->
  </div>
  <!-- tabs-sections-wrapper -->
</div>
<!-- work tabs -->
