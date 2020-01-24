<!-- item -->
<dd class="accordion-navigation tab-item">
  <?php if (!$single) : ?>
  <a id="selid-<?php print $tab_id;?>" href="#<?php print $tab_id;?>" class="tab-link toggle-worktab-content text-small<?php ($single) ? print ' toggled' : print ''; ?>">
    <?php print render($title); ?><span class="toggle-text"></span>
  </a>
  <?php endif; ?>

  <div id="<?php print $tab_id;?>" class="tab-content content clearfix <?php ($single) ? print 'active' : print ''; ?>">
    <?php print render($content); ?>
  </div>
</dd>
<!-- item -->
