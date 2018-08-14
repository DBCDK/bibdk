<div <?php print drupal_attributes(array('class' => 'bibdk-adhl-toplist')); ?>>
  <h1><?php print $title; ?></h1>

  <p class="adhl-toplist-before-text"><?php print $before_text; ?></p>

  <div class="adhl-toplist">
    <?php print drupal_render($list); ?>
  </div>
  <p class="adhl-toplist-after-text"><?php print $after_text; ?></p>
</div>
