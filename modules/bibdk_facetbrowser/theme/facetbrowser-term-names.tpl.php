

<?php if(!$selected_facets):?>
<div class="expand" data-expand="more"><span class="icon icon-left icon-blue-plus">+</span><span><?php echo  t('label_facet_show_more', array(), array('context' => 'bibdk_facetbrowser')); ?></span></div>
<div class="expand" data-expand="less"><span class="icon icon-left icon-blue-minus">-</span><span><?php echo  t('label_facet_show_less', array(), array('context' => 'bibdk_facetbrowser')); ?></span></div>
<?php endif ?>

<div class="select" data-expand="select" data-reveal-id="<?php echo $facet_id; ?>"><span class="icon icon-left icon-blue-down">+</span><span><?php echo  t('label_facet_select_unselect', array(), array('context' => 'bibdk_facetbrowser')); ?></span></div>



