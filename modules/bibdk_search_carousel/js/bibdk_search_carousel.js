// <?php
/**
* @file
* bibdk_search_carousel javascript file
*/
// ?>
// @codingStandardsIgnoreStart
(function($) {

  var initialized = false;

  Drupal.insertCovers = function(coverData) {
    var content = "";
    if (coverData) {
      $('.slick-carousel-inner .ajax-loader').addClass('hidden');
      $('#bibdk-slick-carousel').html(coverData["cover_list"]);
      // init slick
      $('#bibdk-slick-carousel').slick({
        dots: false,
        infinite: true,
        speed: 300,
        slidesToShow: 6,
        slidesToScroll: 6,
        autoplay: false,
        autoplaySpeed: 8000,
        responsive: [
          {
            breakpoint: 840,
            settings: {
              infinite: true,
              slidesToShow: 4,
              slidesToScroll: 4,
            }
          }
        ]
      });
    }
  };


  Drupal.getCovers = function(index) {
    // Retrieve covers
    if(typeof Drupal.settings.displayindex != 'undefined') {
      if ( Drupal.settings.displayindex.show_carousel_index != -1) {
        // just use show_carousel_index firsttime
        index = Drupal.settings.displayindex.show_carousel_index;
        Drupal.settings.displayindex.show_carousel_index = -1;
      }
    }
    request = $.ajax({
      url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'bibdk_search_carousel/results/ajax/' + index,
      type: 'POST',
      dataType: 'json',
      success: Drupal.insertCovers,
    });
  };


  Drupal.behaviors.initCovers = {
    attach: function(context) {
      $( document ).ready(function() {
        if ( !initialized ) {
          $('.slick-carousel-tabs li a').each(function( index ) {
            $(this).click(function(e) {
              e.preventDefault();
              // Remove current content, show spinner and get new content.
              $('.slick-carousel-inner .ajax-loader').removeClass('hidden');
              $('#bibdk-slick-carousel').removeClass('slick-initialized');
              $('#bibdk-slick-carousel').removeClass('slick-slider');
              $('#bibdk-slick-carousel').html('');
              for(var i=0; i<10; i++) {
                var tabindex = '.tab' + i.toString();
                $(tabindex).removeClass('active');
              }
              var index = $(this).attr('data-value');
              $(index).addClass('active');
              Drupal.getCovers(index);
            });
          });
          Drupal.getCovers(0);
          initialized = true;
        }
      });
    }
  };

} (jQuery));
// @codingStandardsIgnoreEnd
