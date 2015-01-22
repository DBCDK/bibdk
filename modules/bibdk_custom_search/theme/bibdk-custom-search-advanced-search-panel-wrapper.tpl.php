<div id="custom-search--advanced-toggle" data-toggle-state-hidden="<?php print $form['#toggled']; ?>" class="<?php print $form['#toggled']; ?> show-for-large-up">
  <a id="selid_custom_search_expand" class="text-darkgrey" href="#">
    <span class="toggle-text <?php print $form['#expand_hidden']; ?>">
      <svg class="custom-search--advanced-toggle-icon">
        <use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="#svg-plus-circle"></use>
      </svg>
      <span class="custom-search--advanced-toggle-text">
        <?php print t('Expand search options'); ?>
      </span>
    </span>

    <span class="toggle-text <?php print $form['#collaps_hidden']; ?>">
      <svg class="custom-search--advanced-toggle-icon">
        <use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="#svg-minus-circle"></use>
      </svg>
      <span class="custom-search--advanced-toggle-text">
        <?php print t('Collapse search options'); ?>
      </span>
    </span>

  </a>
</div>
<div id="search-advanced" class="<?php print $form['#collaps_hidden']; ?> show-for-large-up">
  <div id="search-advanced-panel">
    <!-- ADVANCED SEARCH-->
    <?php print drupal_render_children($form); ?>
    <!-- END ADVANCED SEARCH-->
  </div>
</div>