<?php
/**
 * @file
 *
 */

?>
<div class="voxb-details pid-<?php echo $pid; ?>">
  <div class="voxb-rating rate-enabled">
    <?php for ($i = 1; $i <= 5; $i++): ?>
      <?php $star_class = ($i * 20 > $object->rating) ? 'star negative' : 'star positive'; ?>
      <a href="voxb/ajax/set_rating/<?php echo $pid; ?>/<?php echo $i; ?>" class="rating left" title=" <?php echo $title . ' ' . $i; ?>">
        <span class="<?php echo $star_class; ?>"></span>
      </a>
    <?php endfor; ?>
    <p class="rating-count left">
        <?php echo t('Number of ratings: ', array(), array('contexb' => 'voxb')) . $object->ratingCount; ?>
    </p>
    <?php print drupal_render($login_link);?>
  </div>
  <div class="bibdk-write-review-link">
    <?php print drupal_render($review_link); ?>
  </div>
  <div class="bibdk_voxb_clear">
    <?php if (!empty($teasers)): ?>
      <?php print drupal_render($teasers); ?>
    <?php endif; ?>
  </div>
</div>