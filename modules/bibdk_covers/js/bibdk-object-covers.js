// <?php
/**
* @file
* bibdk_covers javascript file
*/
// ?>
(function($) {

  Drupal.extractCoverData = function(e) {
  // extract style and IDs from classnames in div.
    var ids = new Array();
    classname = $(e).attr('class');
    imageStyle = classname.match(/bibdk-cover-style-(\S+)/);
    work_id = classname.match(/bibdk-cover-work-object-id-(\S+)/);
    if (work_id) {
      var len=work_id.length;
      for(var i=0; i<len; i++) {
        if (!work_id[i].match(/bibdk-cover-work-object-id/)) {
          ids.push(work_id[i] + ':' + imageStyle[1]);
        }
      }
      return ids;
    }
    id = classname.match(/bibdk-cover-object-id-(\S+)/);
    ids.push(id[1] + ':' + imageStyle[1]);
    if (ids) {
      return ids;
    }
    return false;
  };

  Drupal.insertCovers = function(coverData) {
    if(coverData === false){
      return;
    }
    $.each(coverData, function(coverInfo, url) {
      coverInfo = coverInfo.split(':');
      // thumbnail
      if (coverInfo[1] == 'thumbnailUrl') {
        var img = '<img src="' + url + '" alt=""/>';
        $('.bibdk-cover-processing' + '.bibdk-cover-work-object-id-' + coverInfo[0] + ' a').html(img);
        $('.bibdk-cover-processing' + '.bibdk-cover-work-object-id-' + coverInfo[0] + ' a').parents('.work-cover').show();
      }
      // large
      if (coverInfo[1] == 'detailUrl') {
        var img = '<img src="' + url + '" alt=""/>';
        $('.bibdk-cover-processing' + '.bibdk-cover-work-object-id-' + coverInfo[0]).parents('.field-items').find('.reveal-cover-large-image').foundation('reflow').html(img);
      }
      // back cover
      if (coverInfo[1] == 'backpagePdfUrl' && url != '') {
        var pdf = '<object data="' + url + '?page=1&amp;view=Fit" type="application/pdf" width="590" height="925"><p>It appears you dont have a PDF plugin for this browser. No biggie... you can <a href="' + url + '">click here to download the PDF file.</a></p></object>';
        $('.bibdk-cover-processing' + '.bibdk-cover-work-object-id-' + coverInfo[0]).parents('.work-cover').find('.work-cover-front').show().foundation('reflow');
        $('.bibdk-cover-processing' + '.bibdk-cover-work-object-id-' + coverInfo[0]).parents('.work-cover').find('.work-cover-back').show().foundation('reflow');
        $('.bibdk-cover-processing' + '.bibdk-cover-work-object-id-' + coverInfo[0]).parents('.field-items').find('.reveal-cover-back-image').html(pdf).foundation('reflow');
      }
    });
  };

  Drupal.behaviors.bibdkCovers = {

    attach: function(context) {
      // Assemble information regarding covers
      var coverData = [];
      $('.bibdk-cover:not(.bibdk-cover-processing, .bibdk-cover-processed)', context).each(function(i, e) {
          coverData = coverData.concat(Drupal.extractCoverData(e));
      }).addClass('bibdk-cover-processing');

      if ( coverData.length > 0 ) {
        // Retrieve covers
        request = $.ajax({
          url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'bibdk/covers',
          type: 'POST',
          data: {
            coverData: coverData // ex. array('28917074:medium')
          },
          dataType: "json",
          success: Drupal.insertCovers,
          // Keep state using classes
          complete: function(request, status) {
            var processing = $('.bibdk-cover-processing', context);
            if (status == 'success') {
              processing.addClass('bibdk-cover-processed');
            }
            processing.removeClass('bibdk-cover-processing');
          }
        });

        // Associate the request with the context so we can abort the request
        // if the context is detached removed before completion
        $(context).data('request', request);
      }
    },
    detach: function(context) {
      //If we have a request associated with the context then abort it.
      //It is obsolete.
      var request = $(context).data('request');
      if (request) {
        request.abort();
      }
    }
  };

} (jQuery));
