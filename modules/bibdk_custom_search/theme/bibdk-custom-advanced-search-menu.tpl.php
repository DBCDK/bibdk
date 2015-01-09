<div id="search-advanced-toggle" data-toggle-state-hidden="<?php print $form['#toggled']; ?>" class="clearfix <?php print $form['#toggled']; ?>">
  <a id="selid_custom_search_expand" class="text-darkgrey <?php print $form['#toggled']; ?>" href="#">
    <span class="icon icon-left icon-blue-minus">&nbsp;</span>
    <span class="toggle-text <?php print $form['#expand_hidden']; ?>"><?php print t('Expand search options'); ?></span>
    <span class="toggle-text <?php print $form['#collaps_hidden']; ?>"><?php print t('Collapse search options'); ?></span>
  </a>
</div>
<div id="search-advanced" class="clearfix <?php print $form['#collaps_hidden']; ?>">
  <div id="search-advanced-panel" class="clearfix">
    <!-- ADVANCED SEARCH-->
    <?php print drupal_render_children($form); ?>
    <!-- END ADVANCED SEARCH-->
  </div>
</div>
