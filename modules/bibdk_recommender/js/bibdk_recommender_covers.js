// <?php
/**
* @file
* bibdk_recommender_covers javascript file
*/
// ?>
(function($) {
  
  var BibdkRecommenderBehavior = {};
  
  // Attach behaviour
  Drupal.behaviors.bibdkCarouselCovers = {
    attach: function(context) {
      $( document, context).ready(function() {
        $('.bibdk-recommender-cover-placeholder', context).once('bibdk-recommender-cover').each(function(index, element) {
          Drupal.getBibdkCarouselCovers($(this));
        });
        $( ".bibdk-recommender-carousel .slick__slide" ).on( "click", "a", function() {
          Drupal.setBibdkCarouselOnclick($(this));
        })
      });
    }
  };

  // Send BibdkRecommenderBehavior on click.
  Drupal.setBibdkCarouselOnclick = function(elem) {
    recommendation = elem.find('.bibdk-recommender-cover-placeholder');
    var selected = recommendation.attr('data-pid');
    BibdkRecommenderBehavior.selected = selected;
    var pids = recommendation.closest('.js-slick-recommender').attr('data-recomole-pids').split(",");
    BibdkRecommenderBehavior.like = pids;
    var limit = recommendation.closest('.js-slick-recommender').attr('data-recomole-limit');
    BibdkRecommenderBehavior.limit = limit;
    var authorflood = recommendation.closest('.js-slick-recommender').attr('data-recomole-authorflood');
    BibdkRecommenderBehavior.authorflood = authorflood;
    var types = recommendation.closest('.js-slick-recommender').attr('data-recomole-types').split(",");
    BibdkRecommenderBehavior.filters_type = types;
    var recommendations = [];
    elem.closest('.slick-track').find('.bibdk-recommender-cover-placeholder').each(function(index, element) {
      recommendations.push($(this).attr('data-pid'));
    });
    BibdkRecommenderBehavior.result = unique(recommendations);
    var url = Drupal.settings.basePath + Drupal.settings.pathPrefix + 'bibdk/behaviour/recommender/';
console.log(BibdkRecommenderBehavior);
    var request = $.ajax({
      url: url,
      method: "POST",
      data: { recomole: BibdkRecommenderBehavior },
      dataType: 'json',
      async: true,
    });
  };
  
  // Retrieve  Recommender images
  Drupal.getBibdkCarouselCovers = function(elem) {
    pid   = elem.attr("data-pid");
    style = elem.attr("data-style"); // detail || thumbnail
    if (pid === undefined || style === undefined) {
      return;
    }
    var coverData = [];
    coverData.push(pid + ':' + style);
    request = $.ajax({
      url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'bibdk/covers',
      type: 'POST',
      data: {
        coverData: coverData // ex. array('28917074:detail')
      },
      dataType: "json",
      success: Drupal.insertCarouselCovers
    });

  };

  // AJAX callback: insert cover images on success.
  Drupal.insertCarouselCovers = function(coverData) {
    if (coverData === false) {
      return;
    }
    var style = "thumbnail";
    if (coverData["imageStyle"] !== false) {
      style = coverData["imageStyle"];
      delete coverData["imageStyle"];
    }
    $.each(coverData, function(coverInfo, url) {
      coverInfo = coverInfo.split(':');
      if (coverInfo[2] == style + 'Url') { // thumbnailUrl || detailUrl || backpagePdfUrl
        var img = '<img src="' + url + '" alt=""/>';
        var element = $('.bibdk-recommender-cover-placeholder[data-pid="' + coverInfo[0] + ':' + coverInfo[1] + '"] .bibdk-recommender-material-type');
        element.foundation('reflow').html(img);
        element.css('opacity', 1);
      }
    });
  };
  
  function unique(array) {
    return $.grep(array, function(el, index) {
        return index === $.inArray(el, array);
    });
  }

} (jQuery));
