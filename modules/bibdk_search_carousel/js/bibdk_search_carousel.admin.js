// <?php
/**
* @file
* bibdk_search_carousel javascript file
*/
// ?>
// @codingStandardsIgnoreStart
(function ($) {
  Drupal.behaviors.bibdkSearchCarousel = {
    attach: function(context) {
      $('.search-carousel-query .remove').click(function () {
        $(this).parent('tr').remove();
        return false;
      });
    }
  }
})(jQuery);
// @codingStandardsIgnoreEnd
