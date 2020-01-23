(function($) {

    Drupal.addThrobber = function(element) {
        $(element).parent().addClass('ajax-progress');
        $(element).toggleClass('visuallyhidden');
        $(element).parent().append('<span class="throbber" style=" margin-top:120px; margin-left:200px;">&nbsp;</span>');
    };

    Drupal.removeThrobber = function(element) {
        $(element).parent().removeClass('ajax-progress');
        $('span[class="throbber"]').remove();
        $(element).toggleClass('visuallyhidden');
    };

    Drupal.addSpinner = function() {
        var element = $('.bibdk-openuserstatus-mypage-info .bibdk-mypage-row .item-row');
        element.addClass('ajax-progress');
        //element.prepend('<span class="throbber">&nbsp;</span>');
        element.prepend('<span class="throbber" style=" margin-top:120px; margin-left:200px;">&nbsp;</span>');
    };

    // Get openuserstatus data
    Drupal.viewOpenuserStatus = function(element) {
        Drupal.addSpinner();

        $.ajax({
            url: Drupal.settings.basePath + Drupal.settings.pathPrefix +  'bibdk_openuserstatus_ajax',
            type: 'POST',
            data: {},
            dataType: 'json',
            success: function(data){
                Drupal.removeThrobber(element);
                $(element).html(data.markup);

                //attach behaviors for modifying collectlibrary
                var select=$('#bibdk-openuserstatus-form');
                Drupal.attachBehaviors(select);
            },
            error: function(){
                Drupal.removeThrobber(element);
            }

        });
    };

    Drupal.behaviors.userstatusajax = {
        attach: function(context) {
            $('.ajax_get_user_status' , context).once(function() {
                var element = $(this);
                Drupal.addThrobber(element);
                Drupal.viewOpenuserStatus(element);
            });
        }
    };

}(jQuery));
