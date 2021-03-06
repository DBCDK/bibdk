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
        slidesToShow: 5,
        slidesToScroll: 5,
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
          $('.slick-carousel-tabs li a').each(function( index, element ) {
            $(this).click(function(e) {
              e.preventDefault();
              // Remove current content, show spinner and get new content.
              $('.slick-carousel-inner .ajax-loader').removeClass('hidden');
              $('#bibdk-slick-carousel').removeClass('slick-initialized');
              $('#bibdk-slick-carousel').removeClass('slick-slider');
              $('#bibdk-slick-carousel').html('');
              // remove all active tabs
              $('.tab.slick-carousel-tabs li a').removeClass('active');
              // set selected tab
              $(element).addClass('active');
              var index = $(this).attr('data-value');
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
