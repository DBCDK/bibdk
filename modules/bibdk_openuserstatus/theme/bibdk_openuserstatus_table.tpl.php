<section>
  <a name="loans"></a>

  <div class="element-wrapper">
    <div class="element">
      <div class="element-section padded">
        <?php !empty($actions) ? print $actions : print ''; ?>
        <div class="element-title">
          <h2><?php print t('your_loans', array(), array('context' => 'bibdk_openuserstatus')); ?><span><?php print ' ' . $count; ?></span></h2>
        </div>
      </div>
      <!-- element-section -->
      <div class="element-section">
        <div class="table">
          <?php print drupal_render($table); ?>
        </div>
      </div>
    </div>
  </div>
</section>