(function($) {

  Drupal.insertCovers = function(coverData) {

    var content = "";

    if (coverData) {

      $('#bibdk-slick-carousel:not(.slick-cover-processed)').html(coverData["cover_list"]);

      // init slick
      $('#bibdk-slick-carousel').slick({
        dots: false,
        infinite: true,
        speed: 300,
        slidesToShow: 6,
        slidesToScroll: 1,
        autoplay: true,
        autoplaySpeed: 2000,
        responsive: [
          {
            breakpoint: 820,
            settings: {
              infinite: true,
              slidesToShow: 4,
              slidesToScroll: 1,
            }
          },
          {
            breakpoint: 480,
            settings: {
              infinite: true,
              slidesToShow: 2,
              slidesToScroll: 2
            }
          }
        ]
      });
    }

    $('#bibdk-slick-carousel').addClass('slick-cover-processed');

  };

  Drupal.behaviors.getCovers = {
    attach: function(context) {

      // Current list number
      var index = $('.bibdk-search-controls-form').index();

      // Retrieve covers
      request = $.ajax({
        url: Drupal.settings.basePath + 'bibdk_search_carousel/results/ajax/' + index,
        type: 'POST',
        dataType: 'json',
        success: Drupal.insertCovers,
      });
    }
  };

} (jQuery));
