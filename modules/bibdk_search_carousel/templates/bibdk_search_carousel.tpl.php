<?php
/**
 * @file
 * Template for showing carousel tabs
 *
 * Available variables:
 * - $tab_position: current tab
 * - $searches: Array with each tab search.
 *
 */
?>


<div class="slick-carousel">

  <div class="slick-carousel-header">

    <div class="slick-carousel-header-title">

      <?php if (count($searches) > 1): ?>

       <div class="slick-carousel-tab-select">
         <form class="bibdk-search-controls-form" data-control-name="controls_carousel">
           <ul class="tab slick-carousel-tabs">
             <li>
               <div><?php print t('LABEL_HEAD ', array(), array('context' => 'ting_search_carousel')); ?></div>
             </li>
             <?php foreach ($searches as $i => $search): ?>
               <li>
                 <?php if ($tab_position == $i): ?>
                   <a class="tab<?php print $i; ?> active" href="#<?php print $i; ?>" data-value="<?php print $i; ?>"><?php print t($searches[$i]['title'], array(), array('context' => 'ting_search_carousel')) ?></a>
                 <?php else: ?>
                   <a class="tab<?php print $i; ?>" href="#<?php print $i; ?>" data-value="<?php print $i; ?>"><?php print t($searches[$i]['title'], array(), array('context' => 'ting_search_carousel')) ?></a>
                 <?php endif; ?>
               </li>
             <?php endforeach; ?>
           </ul>
         </form>
       </div>
      <?php endif; ?>

    </div>

  </div>
  <!-- slick-carousel-header -->

  <div class="slick-carousel-inner">
    <div class="ajax-loader"></div>
    <div id="bibdk-slick-carousel"></div>
  </div>
  <!-- slick-carousel-inner -->

</div>
<!-- slick-carousel -->
