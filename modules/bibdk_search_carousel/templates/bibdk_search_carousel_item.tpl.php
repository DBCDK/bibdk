<?php
/**
 * @file
 */
?>

<div class="carousel-item">
  <div class="carousel-item-image-wrapper">
    <div class="carousel-item-image">
      <a href="<?php echo $url; ?>" title="<?php print check_plain($title); ?>">
        <img src="<?php echo $image; ?>" alt=""/>
      </a>
    </div>
  </div>
  <div class="carousel-item-data-wrapper">
    <div class="carousel-item-title">
      <a href="<?php echo $url; ?>">
        <?php print check_plain($title); ?>
      </a>
    </div>
    <div class="carousel-item-creator">
      <a href="<?php echo $url; ?>">
        <?php print check_plain($creator). 'FISK'; ?>
      </a>
    </div>
  </div>
</div>
