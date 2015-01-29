<div class="linkme-wrapper">
  <a href="#<?php print $path; ?>" class="linkme-button js-linkme-dropdown bibdk-dropdown-link" data-dropdown="<?php print $selid ?>">
    <?php print $link_text; ?>
  </a>

  <div id="<?php print $selid ?>" class="linkme-content bibdk-dropdown" data-dropdown-content aria-hidden="true" tabindex="-1">
    <div class=''><?php print drupal_render_children($link_form) ?><span
  </div>
</div>
