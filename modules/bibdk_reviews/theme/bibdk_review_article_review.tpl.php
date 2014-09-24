<div class='bibdk-article-review clearfix' >
  <div class='openformat-info'>
    <b><?php print $title ?></b> <?php print $publisher ?> <br/>
    <?php print $creator ?> <br/>
    <?php print drupal_render($rating) ?>
  </div>
  <div class='bibdk-review-link'>
    <?php print drupal_render($link); ?>
  </div>
<?php if ( !empty($netarchive) ) { ?>
  <div class='bibdk-review-link'>
<?php print drupal_render($netarchive); ?>
  </div>
<?php } ?>
</div>
