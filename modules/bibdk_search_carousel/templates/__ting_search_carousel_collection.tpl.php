<?php
/**
 * @file
 *
 */
?>
<li class="rs-carousel-item">
  <div class="rs-carousel-item-image"><a href="search/work/rec.id=<?php echo urlencode($collection->pid); ?>" title="<?php print check_plain($collection->title); ?>"><img src="<?php echo $collection->image; ?>" alt=""/></a></div>
  <div class="rs-carousel-item-title"><a href="search/work/rec.id=<?php echo urlencode($collection->pid); ?>"><?php print check_plain($collection->title); ?></a></div>
  <div class="rs-carousel-item-creator"><a href="search/work/rec.id=<?php echo urlencode($collection->pid); ?>"><?php print check_plain($collection->creator); ?></a></div>
</li>
