<?php
/**
 * Created by IntelliJ IDEA.
 * User: pjo
 * Date: 4/23/14
 * Time: 5:10 PM
 */
?>

<?php foreach ($reviews as $review): ?>

  <div id="voxb-review-<?php print $review->voxb_identifier;?>" class="bibdk-voxb-review clearfix">

    <div class="element-section bibdk-voxb-review-header">

      <div>
        <?php print $date_text; ?>
        <b><?php print $review->date; ?></b>
      </div>

      <div>
        <?php print $author_text; ?>
        <b><?php print$review->alias; ?></b>
      </div>
    </div>

    <div class="element-section bibdk-voxb-review-toggle">
      <div class="toggle-next-section">
        <a class="show-more visuallyhidden" href="#"><?php print t('view_more'); ?></a>
        <a class="show-less" href="#"><?php print t('view_less'); ?></a>
      </div>
      <div class="bibdk-edit-review">
        <?php print drupal_render($review->edit_link); ?>
      </div>
    </div>

    <div class="element-section bibdk-voxb-review-text">
      <?php print $review->markup; ?>
    </div>

    <div class="clearfix"></div>
    <div id="bibdk-voxb-review-message-<?php print $review->voxb_identifier;?>"></div>
  </div>


<?php endforeach; ?>
