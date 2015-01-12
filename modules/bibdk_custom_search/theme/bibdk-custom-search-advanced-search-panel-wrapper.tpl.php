<div id="search-advanced-toggle" data-toggle-state-hidden="<?php print $toggled; ?>" class="clearfix <?php print $toggled; ?>">
  <a id="selid_custom_search_expand" class="text-darkgrey <?php print $toggled; ?>" href="#">
    <span class="icon icon-left icon-blue-minus">&nbsp;</span>
    <span class="toggle-text <?php print $expand_hidden; ?>"><?php print t('Expand search options'); ?></span>
    <span class="toggle-text <?php print $collaps_hidden; ?>"><?php print t('Collapse search options'); ?></span>
  </a>
</div>
<div id="search-advanced" class="clearfix <?php print $collaps_hidden; ?>">
  <div id="search-advanced-panel" class="clearfix">
    <?php print $advanced_search_panel; ?>
  </div>
</div>