    <a href="#<?php print $path; ?>" class="load-holdings bibdk-dropdown-link" data-dropdown="<?php print $data_id ?>">
      <?php print $link_text; ?>
    </a>
    <div id="<?php print $data_id ?>" class='linkme-content bibdk-dropdown' data-dropdown-content>
      <div class=''>
        <?php print drupal_render($favourites) ?><span class="close icon icon-left icon-red-x">&nbsp;</span>
      </div>
    </div>
