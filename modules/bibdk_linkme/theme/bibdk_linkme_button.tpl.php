<div class="linkme-wrapper">
  <a href="#<?php print $path; ?>" class="linkme-button js-linkme-dropdown bibdk-dropdown-link" data-dropdown="<?php print $selid ?>">
    <span class="icon icon-left icon-lightgrey-link">&nbsp;</span>
    <?php print $link_text; ?>
  </a>

  <div id="<?php print $selid ?>" class="linkme-content bibdk-dropdown" data-dropdown-content aria-hidden="true" tabindex="-1">
    <div class=''><?php print drupal_render_children($link_form) ?><span
        class="close icon icon-left icon-red-x">&nbsp;</span></div>
  </div>
</div>
