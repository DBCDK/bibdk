<?php
  // #type = translatable render array only work out-of-the-box on plain text.
  // Link text as translatable has to be rendered into a string before the link is rendered.
  $infotext['link']['#text'] = drupal_render($infotext['link']['#text']);
?>
    <div class="dropdown-wrapper">
      <a <?php print drupal_attributes($addi_attributes);?> class="btn btn-blue order-any-btn dropdown-toggle" href="#"><?php print t('Order any edition', array(), array('context'=>'bibdk_reservation')); ?></a>
      <div class="dropdown-menu order-any-btn-list hidden">
        <?php print drupal_render($table); ?>
        <div class="reservation-btn-infotext <?php print $hide; ?>"><?php print drupal_render($infotext); ?></div>
      </div>
    </div>
