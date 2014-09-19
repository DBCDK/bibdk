<!-- table actions -->
<div class="table-actions">
  <button class="markall-button">
    <input type="checkbox" value="0"><?php print t('label_mark_all_loans', array(), array('context' => 'bibdk_openuserstatus')) ?>
  </button>
  <?php foreach ($actions as $action) : ?>
    <?php print drupal_render($action); ?>
  <?php endforeach; ?>
  <!--
  <button class="delete-button" href="#">
    <span class="icon icon-left icon-green-refresh">?</span><?php print t('label_renew_loans', array(), array('context' => 'bibdk_openuserstatus')) ?>
  </button> -->
</div>
<!-- table actions -->