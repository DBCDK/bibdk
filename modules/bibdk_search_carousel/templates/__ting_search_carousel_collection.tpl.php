<?php
/**
 * @file
 */
?>

<li class="slick-carousel-item">
  <div class="slick-carousel-item-image">
    <a href="search/work/rec.id=<?php echo urlencode($pid); ?>" title="<?php print check_plain($title); ?>">
      <img src="<?php echo $image; ?>" alt=""/>
    </a>
  </div>
  <div class="slick-carousel-item-title">
    <a href="search/work/rec.id=<?php echo urlencode($pid); ?>">
      <?php print check_plain($title); ?>
    </a>
  </div>
  <div class="slick-carousel-item-creator">
    <a href="search/work/rec.id=<?php echo urlencode($pid); ?>">
      <?php print check_plain($creator); ?>
    </a>
  </div>
</li>
