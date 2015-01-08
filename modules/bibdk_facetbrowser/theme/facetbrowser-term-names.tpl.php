<?php
  echo drupal_render_children($form);
  $facet_key = current(array_filter($form['#parents']));
  $facet_id = drupal_html_id('modal-' . $facet_key);
?>

<div class="expand" data-expand="more"><span class="icon icon-left icon-blue-plus">+</span><span><?php echo  t('label_facet_show_more', array(), array('context' => 'bibdk_facetbrowser')); ?></span></div>

<div class="expand" data-expand="less"><span class="icon icon-left icon-blue-minus">-</span><span><?php echo  t('label_facet_show_less', array(), array('context' => 'bibdk_facetbrowser')); ?></span></div>

<div class="select" data-expand="select" data-reveal-id="<?php echo $facet_id; ?>"><span class="icon icon-left icon-blue-down">+</span><span><?php echo  t('label_facet_select_unselect', array(), array('context' => 'bibdk_facetbrowser')); ?></span></div>

<div class="bibdk-facetbrowser-modal element-wrapper reveal-modal" id="<?php echo $facet_id; ?>" data-reveal="" data-facet-key="<?php echo $facet_key; ?>">

  <div class="bibdk-modal-header">
    <span class="bibdk-modal-title"><?php echo t('header_refine_facet_select', array(), array('context' => 'bibdk_facetbrowser')); ?></span>
  </div>

  <div class="bibdk-modal-content">

    <div class="checkbox-buttons clearfix">
      <div class="checkbox-element-submit save-facet-modal">
        <a id="" class="btn btn-blue" href="#">
          <?php echo t('label_facet_save', array(), array('context' => 'bibdk_facetbrowser')); ?>
        </a>
      </div>
      <div class="checkbox-element-submit close-reveal-modal">
        <a id="" class="btn btn-blue" href="#">
          <?php echo t('label_facet_close', array(), array('context' => 'bibdk_facetbrowser')); ?>
        </a>
      </div>
    </div>

    <div class="checkbox-elements-header">
      <p class="checkbox-element-label">&nbsp;</p>
      <p class="checkbox-element-select"><?php echo t('label_facet_select', array(), array('context' => 'bibdk_facetbrowser')); ?></p>
      <p class="checkbox-element-deselect"><?php echo t('label_facet_deselect', array(), array('context' => 'bibdk_facetbrowser')); ?></p>
    </div>

    <div class="checkbox-elements"></div>

    <div class="checkbox-element">
      <p class="checkbox-element-label"></p>
      <p class="checkbox-element-select"></p>
      <p class="checkbox-element-deselect"></p>
    </div>

    <div class="checkbox-buttons clearfix">
      <div class="checkbox-element-submit save-facet-modal">
        <a id="" class="btn btn-blue" href="#">
          <?php echo t('label_facet_save', array(), array('context' => 'bibdk_facetbrowser')); ?>
        </a>
      </div>
      <div class="checkbox-element-submit close-reveal-modal">
        <a id="" class="btn btn-blue" href="#">
          <?php echo t('label_facet_close', array(), array('context' => 'bibdk_facetbrowser')); ?>
        </a>
      </div>
    </div>

  </div>

</div>


