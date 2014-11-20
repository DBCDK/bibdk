(function($) {
  Drupal.behaviors.updateCart = {
    attach: function(context) {
      $(window).unload(function() {
        window.opener.Drupal.markCheckboxes(false, null);
        window.opener.location.reload(false);
      });
    }
  }
}(jQuery));
