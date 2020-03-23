<p class="userstatus-intro">
  <?php if (isset($variables['label_userstatus_intro'])): ?>
    <?php print t($variables['label_userstatus_intro'], array(), array('context' => 'bibdk_openuserstatus')) ?>
  <?php endif; ?>
</p>

<div class="userstatus-menu show-for-large-up">
  <p class="userstatus-menu-item">
    <a href="#loans">
      <svg class="svg-icon">
        <title><?php print t('label_userstatus_loans', array(), array('context' => 'bibdk_openuserstatus')); ?></title>
        <use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="#svg-arrow-right"></use>
      </svg>
      <span><?php print t('label_userstatus_loans', array(), array('context' => 'bibdk_openuserstatus')) ?></span>
    </a>
  </p>

  <p class="userstatus-menu-item">
    <a href="#reservations">
      <svg class="svg-icon">
        <title><?php print t('label_userstatus_reservations', array(), array('context' => 'bibdk_openuserstatus')); ?></title>
        <use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="#svg-arrow-right"></use>
      </svg>
      <span><?php print t('label_userstatus_reservations', array(), array('context' => 'bibdk_openuserstatus')) ?></span>
    </a>
  </p>

  <p class="userstatus-menu-item">
    <a href="#fiscal">
      <svg class="svg-icon">
        <title><?php print t('label_userstatus_fiscal', array(), array('context' => 'bibdk_openuserstatus')); ?></title>
        <use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="#svg-arrow-right"></use>
      </svg>
      <span><?php print t('label_userstatus_fiscal', array(), array('context' => 'bibdk_openuserstatus')) ?></span>
    </a>
  </p>

</div>
