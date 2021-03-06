// <?php
/**
* @file
* bibdk_recommender javascript file
*/
// ?>
// @codingStandardsIgnoreStart
(function($) {

  // Attach Slick Recommender.
  Drupal.behaviors.initRecommenderExample = {
    attach: function(context) {
      $('.js-slick-recommender', context).once('slick-recommender').each(function(index, element) {
        Drupal.getSlickRecommender($(this));
      });
    }
  };

  // Retrieve Slick Recommender carousel
  Drupal.getSlickRecommender = function(elem) {
    var id = elem.attr("id");
    var pids = elem.attr("data-recomole-pids");
    var filters = elem.attr("data-recomole-types");
    if (!id || !pids) {
      return;
    }
    if (!filters) {
      filters = null;
    }
    request = $.ajax({
      url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'bibdk_recommender/ajax/slick_carousel/' + id + '/' + pids + '/' + filters,
      type: 'POST',
      dataType: 'json',
      async: true,
      success: Drupal.insertSlickRecommender
    });
  };

  // Insert Slick Recommender carousel on AJAX success
  Drupal.insertSlickRecommender = function(slickRecommender) {
    if (slickRecommender === false) {
      return;
    }
    var slider = $('#' + slickRecommender.id);
    slider.foundation('reflow').html(slickRecommender.slick);
    Drupal.attachBehaviors(slider);
  };

} (jQuery));
// @codingStandardsIgnoreEnd
