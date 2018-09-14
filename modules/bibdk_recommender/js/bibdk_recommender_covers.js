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
        $( ".bibdk-recommender-carousel .slick__slide" ).on( "click", ".slide__content", function(event) {
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
    elem.closest('.slick-track').find('.slick__slide').not('.slick-cloned').each(function(index, element) {
      recommendations.push($(this).find('.bibdk-recommender-cover-placeholder').attr('data-pid'));
    });
    // BibdkRecommenderBehavior.result = unique(recommendations);
    BibdkRecommenderBehavior.result = recommendations;
    
    var url = Drupal.settings.basePath + Drupal.settings.pathPrefix + 'bibdk/behaviour/recommender/';
    
    // navigator.sendBeacon is a new method that solves the problem of sending data to server on document unload. 
    // Data is transmitted asynchronously without affecting loading performance of the next page
    // There are browser compatibilty issues: Firefox, Chrome, Opera & Edge support it. Safari and IE don't support it.
    if (navigator.sendBeacon) {
      var fd = new FormData();
      fd.append('navigator_sendBeacon', JSON.stringify(BibdkRecommenderBehavior));
      navigator.sendBeacon(url, fd);
    } else {
      var request = $.ajax({
        url: url,
        method: "POST",
        data: {ajax: BibdkRecommenderBehavior},
        dataType: 'json',
        async: false, // Or page may reload before request is sent.
      });
    }
  };
  
  // Retrieve Recommender images
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
  
} (jQuery));
