<div>
  <a href="#<?php print $path; ?>" class="popover-button text-small" id="<?php print $selid ?>">
    <span class="icon icon-left icon-lightgrey-link">&nbsp;</span>
    <?php print $link_text; ?>
  </a>

  <div class='popover element-wrapper visuallyhidden linkme-wrapper hide-text'>
    <div class=''><?php print drupal_render_children($link_form) ?><span
        class="close icon icon-left icon-red-x">&nbsp;</span></div>
  </div>
</div>
