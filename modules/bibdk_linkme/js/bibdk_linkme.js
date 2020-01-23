(function($) {
  var linkme = {
    setFocus: function(e){
      setTimeout(function(){
        $(e.target).closest(".secondary-actions").find("input[type='text']").select();
      }, 10);
    }
  };

  Drupal.behaviors.bibdk_linkme = {
    attach: function(context) {
      $('.linkme-button', context).once().click(function(e){
        linkme.setFocus(e);
      });
    }
  };
}(jQuery));
