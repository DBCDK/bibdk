<?php
/**
 * @file
 *
 * Available variables:
 * - $tab_position: String with settings info, values: top,bottom,left,right.
 * - $searches: Array with each tab search.
 *
 */
?>


<div class="rs-carousel">

  <div class="rs-carousel-header">

    <div class="rs-carousel-header-title">
      <?php print t('LABEL_CAROUSEL_HEADER', array(), array('context' => 'ting_search_carousel')); ?>
    </div>

    <?php if (count($searches) > 1): ?>
      <div class="rs-carousel-header-select">
        <form class="bibdk-search-controls-form" data-control-name="controls_carousel">
          <a class="works-control dropdown-toggle" href="#">
            <span class="selected-text" tabindex="" accesskey=""><?php print $searches[0]['title'] ?></span>
          </a>
          <ul class="dropdown-menu dropdown-rightalign rs-carousel-tabs hidden">
            <?php foreach ($searches as $i => $search): ?>
              <li>
                <a class="foo<?php print $i; ?>" href="#<?php print $i; ?>" data-value="<?php print $i; ?>"><?php print $searches[$i]['title'] ?></a>
              </li>
            <?php endforeach; ?>
          </ul>
        </form>
      </div>
    <?php endif; ?>

  </div>
  <!-- rs-carousel-header -->

  <div class="rs-carousel-inner">


    <div class="-ajax-loader"></div>

    <ul class="rs-carousel-runner"></ul>

    <div id="bibdk-owl-carousel" class="owl-carousel owl-theme"></div>

  </div>
  <!-- rs-carousel-inner -->

</div>
<!-- rs-carousel -->
