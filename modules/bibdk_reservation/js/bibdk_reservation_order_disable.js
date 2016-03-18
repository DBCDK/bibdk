
// bibdk_reservation_order_disable.js
// in order reservation step 3 - disable order button when click - to prevent multiorders
//

(function($) {
  //disable order button after in reservation next step 4
  Drupal.behaviors.alreadyOrder = {
    attach: function() {
      $('#edit-next').click (function(){
        $('#edit-next').prop('disabled', true);
      });
    }
  };
})(jQuery);