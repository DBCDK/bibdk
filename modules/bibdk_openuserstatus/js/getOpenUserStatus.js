(function($) {
    Drupal.behaviors.bibdk_openuserstatus = {
        attach: function(context) {
            $('.bibdk-openuserstatus-mypage-info', context).each(function(element) {
                Drupal.bibdkGetUserStatus(element, context);
            });
        }
    };

    Drupal.setUserStatus = function(data) {
        $('.bibdk-openuserstatus-mypage-info').html(data.html);
    };

    Drupal.bibdkGetUserStatus = function(element, context) {
        Drupal.addSpinner();
        // save context in global var to reload later
        Drupal.settings.userStatus = context;
        // Call ajax
        $.ajax({
            url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'openuserstatus/getuserstatus',
            type: 'POST',
            dataType: 'json',
            success: Drupal.setUserStatus
        });
    };

    Drupal.addSpinner = function() {
        var element = $('.bibdk-openuserstatus-mypage-info .bibdk-mypage-row .item-row');
        element.addClass('ajax-progress');
        element.prepend('<span class="throbber">&nbsp;</span>');
    };

}(jQuery)); 

