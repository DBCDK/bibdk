<div id="search-advanced-toggle" data-toggle-state-hidden="<?php print $form['#toggled']; ?>" class="clearfix <?php print $form['#toggled']; ?>">
  <a id="selid_custom_search_expand" class="text-darkgrey <?php print $form['#toggled']; ?>" href="#">
    <span class="toggle-text">
      <svg class="custom-search--expand-toggle-icon">
        <use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="#svg-plus-circle"></use>
      </svg>
      <?php print t('Expand search options'); ?>
    </span>

    <span class="toggle-text <?php print $form['#collaps_hidden']; ?>">
      <svg class="custom-search--expand-toggle-icon">
        <use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="#svg-minus-circle"></use>
      </svg>
      <?php print t('Collapse search options'); ?>
    </span>

  </a>
</div>
<div id="search-advanced" class="clearfix <?php print $form['#collaps_hidden']; ?>">
  <div id="search-advanced-panel" class="clearfix">
    <!-- ADVANCED SEARCH-->
    <?php print drupal_render_children($form); ?>
    <!-- END ADVANCED SEARCH-->
  </div>
</div>