
// bibdk_reservation_order_disable.js
// in order reservation step 2 - disable order button when click - to prevent multiorders

(function($) {
  // Disable order button after in reservation next step 2.
  Drupal.behaviors.alreadyOrder = {
    attach: function() {
      $('#bibdk-reservation-create-wizard-form').submit(function(event){
        if ($(this).hasClass('submitted')) {
          event.preventDefault();
        }
        else {
          $(this).addClass('submitted');
          $('#edit-next').parent().append('<div class="ajax-progress ajax-progress-throbber"><div class="throbber"></div></div>');
          $('#edit-navigation input[type="submit"]').css({"background-color": 'grey', 'pointer-events': 'none'});
        }
      });
    }
  };
})(jQuery);