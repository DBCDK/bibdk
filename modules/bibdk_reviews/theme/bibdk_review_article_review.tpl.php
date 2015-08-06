<div class='bibdk-article-review clearfix' >
  <div class='openformat-info'>
    <b><?php print drupal_render($title) ?></b> <?php print drupal_render($publisher) ?> <br/>
    <?php print drupal_render($creator) ?> <br/>
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
