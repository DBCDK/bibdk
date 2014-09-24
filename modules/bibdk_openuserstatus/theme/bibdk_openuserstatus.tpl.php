<p class="userstatus-intro">
  <?php if (isset($variables['label_userstatus_intro'])): ?>
    <?php print t($variables['label_userstatus_intro'], array(), array('context' => 'bibdk_openuserstatus')) ?>
  <?php endif; ?>
</p>

<div class="userstatus-menu">
  <p class="userstatus-menu-label">
    <?php print t('label_userstatus_go_to', array(), array('context' => 'bibdk_openuserstatus')) ?>
  </p>

  <p class="userstatus-menu-item">
    <a href="#loans"><?php print t('label_userstatus_loans', array(), array('context' => 'bibdk_openuserstatus')) ?></a>
  </p>

  <p class="userstatus-menu-item">
    <a href="#reservations"><?php print t('label_userstatus_reservations', array(), array('context' => 'bibdk_openuserstatus')) ?></a>
  </p>

  <p class="userstatus-menu-item">
    <a href="#fiscal"><?php print t('label_userstatus_fiscal', array(), array('context' => 'bibdk_openuserstatus')) ?></a>
  </p>

</div>