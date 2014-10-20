<li>
    <a href="#<?php print $path; ?>" class="popover-button load-holdings text-small text-lightgrey">
        <span class="icon icon-left icon-lightgrey-link">&nbsp;</span><?php print $link_text; ?>
    </a>
    <div class='popover element-wrapper visuallyhidden linkme-wrapper'>
        <div class=''>
          <?php print drupal_render($favourites) ?><span class="close icon icon-left icon-red-x">&nbsp;</span>
        </div>
    </div>
</li>
