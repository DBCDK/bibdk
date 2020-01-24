(function($) {

  function setClickListeners(context){
    $('.bibdk-favourite--add-remove-library', context).click(function(e){
      window.Foundation.reloadPageOnModalClose = 1;
    });
  }

  Drupal.behaviors.bibdk_favourite = {
    attach: function(context) {
      setClickListeners(context);
    }
  };
}(jQuery));
