<?php
/**
 * @file
 * JavaScript for Bibliotek.dk carousel
 */
?>
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
        slidesToScroll: 1,
        autoplay: true,
        autoplaySpeed: 8000,
        responsive: [
          {
            breakpoint: 768,
            settings: {
              infinite: true,
              slidesToShow: 4,
              slidesToScroll: 1,
            }
          }
        ]
      });
    }
  };


  Drupal.getCovers = function(index) {
    // Retrieve covers
    request = $.ajax({
      url: Drupal.settings.basePath + 'bibdk_search_carousel/results/ajax/' + index,
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
