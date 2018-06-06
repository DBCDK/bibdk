// <?php
/**
* @file
* bibdk_recommender_covers javascript file
*/
// ?>
(function($) {
  // Attach behaviour
  Drupal.behaviors.bibdkCarouselCovers = {
    attach: function(context) {
      $( document, context).ready(function() {
        $('.bibdk-recommender-cover-placeholder', context).once('bibdk-recommender-cover').each(function(index, element) {
          Drupal.getBibdkCarouselCovers($(this));
        });        
      });
    }
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
        coverData: coverData, // ex. array('28917074:detail')
      },
      dataType: "json",
      success: Drupal.insertCarouselCovers,
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
        $('.bibdk-recommender-cover-placeholder[data-pid="' + coverInfo[0] + ':' + coverInfo[1] + '"] .bibdk-recommender-material-type').foundation('reflow').html(img);
        $('.bibdk-recommender-cover-placeholder[data-pid="' + coverInfo[0] + ':' + coverInfo[1] + '"] .bibdk-recommender-material-type').css('opacity', 1);
      }
    });
    Drupal.attachBehaviors();
  };

} (jQuery));
