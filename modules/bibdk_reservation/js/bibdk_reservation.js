(function($) {
  var BibdkReservation = {};

  BibdkReservation.redirectToUserStatus = function(context) {
    $('.redirect-parent', context).click(function(event) {
      event.preventDefault();
      var href = $(this).attr('href');
      var target = $(this).attr('target');

      if(window.opener != null) {
        window.opener.open(href, target);
        close();
      }
      else {
        window.open(href, target);
      }
    });

  };

  Drupal.behaviors.bibdk_reservation = {
    attach: function(context) {
      BibdkReservation.redirectToUserStatus(context);

      $('.bibdk-popup-order-work').click(function(e) {
        $('.dropdown-toggle').not($(this)).removeClass('toggled');
        $('.dropdown-toggle').not($(this)).next().addClass('hidden');
      });
    }
  };

  Drupal.behaviors.chgLibLink = {
    attach: function(context, settings) {
      $('.chg-lib-link', context).click(function(event) {
        event.preventDefault();
        $('#edit-prev').click();
      });

    }
  };

  //Confirm box for id's already ordered in reservation step 2
  Drupal.behaviors.alreadyOrder = {
    attach: function(context, settings) {
      $('.edit-needbeforedate').once().ready(function(){
        if(typeof Drupal.settings.alreadyOrder != 'undefined') {
          if (Drupal.settings.alreadyOrder.alert_already_showed) {
            var r = confirm(Drupal.settings.alreadyOrder.alert_message);
            if (!r) {
              window.close();
            }
          }
        }
        });
    }
  };

})(jQuery);