(function($) {

  function addTogglers(context) {
    $("[data-bibdk-favourite-more-info-toggler]", context).once("agency").click(function(e) {
      var self = $(this);
      var target = $(e.target);
      if(!target.hasClass("bibdk-favourite--add-remove-library") &&
        !target.hasClass("agencylist-link")) {
        self.next(".bibdk-favourite--more-info").toggleClass("is-toggled");
        self.next(".bibdk-favourite--more-info-toggle-indicator").toggleClass("is-toggled");
      }
    });
  }

  function setClickListeners(context){
    $('.bibdk-favourite--add-remove-library', context).click(function(e){
      window.Foundation.reloadPageOnModalClose = 1;
    });
  }

  Drupal.behaviors.bibdk_favourite = {
    attach: function(context) {
      setClickListeners(context);
      addTogglers(context);
    }
  };
}(jQuery));
