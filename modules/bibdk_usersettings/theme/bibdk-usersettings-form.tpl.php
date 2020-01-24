  <div class="tabs-nav clearfix">
    <?php foreach ($tabs as $type => $tab) : ?>
      <a href="#<?php print $type; ?>" <?php print drupal_attributes($tab['attributes']); ?>><?php print $tab['title']; ?></a>
    <?php endforeach; ?>
  </div>
<!-- tabs-sections -->
