(function($) {


  Drupal.behaviors.bibdkCarousel = {
    attach: function(context) {
      var owl = $("#bibdk-owl-carousel");
      owl.owlCarousel({
        items : 6,                   // 10 items above 1000px browser width
        itemsDesktop : [1000,5],     // 5 items between 1000px and 901px
        itemsDesktopSmall : [900,3], // betweem 900px and 601px
        itemsTablet: [600,2],        // 2 items between 600 and 0
        itemsMobile : false,         // itemsMobile disabled - inherit from itemsTablet option
        jsonPath: 'bibdk_search_carousel/results/ajax',
        jsonSuccess : coverDataSuccess
      });

    }
  };

  function coverDataSuccess(data) {
    var content = "";
    if (data) {
      for (var i in data["items"]) {
         var img = data["items"][i].img;
         var alt = data["items"][i].alt;
         content += "<img src=\"" +img+ "\" alt=\"" +alt+ "\">"
      }
    }
    $("#bibdk-owl-carousel").html(content);
  }


  // Custom Navigation Events
  // $(".owl-next").click(function(){
  //   owl.trigger('owl.next');
  // })

  // $(".owl-prev").click(function(){
  //   owl.trigger('owl.prev');
  // })

} (jQuery));
