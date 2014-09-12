(function($) {
    Drupal.changePickupLib = function(element) {

        var oid = element.data('oid');
        var aid = element.val();
        var caid = element.data('caid');

        if(!oid || !aid || !caid) {
            console.log('error: No oid, aid or caid found');
        }

        var request = $.ajax({
            url: Drupal.settings.basePath + 'userstatus/pickuplib',
            type: 'POST',
            data: {
                oid: oid,
                aid: aid,
                caid: caid
            },
            dataType: 'json',
            success: function(data){
                Drupal.userstatusResponse(data);
                Drupal.removeThrobber(element);
                Drupal.activateSelects();
            }
        });
    };

    Drupal.userstatusResponse = function(data) {
        if(data.error) {
            var error = data.error;
            alert(error.msg);
        }
    };

    Drupal.addThrobber = function(element) {
        $(element).parent().addClass('ajax-progress');
        $(element).toggleClass('visuallyhidden');
        $(element).parent().append('<span class="throbber">&nbsp;</span>');
    };


    Drupal.removeThrobber = function(element) {
        $(element).parent().removeClass('ajax-progress');
        $('span[class="throbber"]').remove();
        $(element).toggleClass('visuallyhidden');
    };

    Drupal.deactivateSelects = function(){
        $('.form-select').attr('disabled', true);
        $('#edit-reservations-delete').attr('disabled', true);
    };

    Drupal.activateSelects = function() {
        $('.form-select').attr('disabled', false);
        $('#edit-reservations-delete').attr('disabled', false);
    };

    Drupal.behaviors.userstatus = {
        attach: function(context) {
            $('.form-select', context).change(function() {
                var element = $(this);
                Drupal.deactivateSelects();
                Drupal.addThrobber(element);
                Drupal.changePickupLib(element);
            });
        }
    };
}(jQuery));
