/**
 * javascript to get sb_kopi options
 * script attached in bibdk_sbkopi.field.inc::bibdk_sbkopi_field_formatter_view
 **/
(function ($) {
    Drupal.addCopyLink = function (data) {
        if( data.link != 'error') {
            var tag = $('.bibdk-sb_kopi-replaceme[pid=' + data.pid + ']');
            tag.replaceWith(data.link);
            Drupal.attachBehaviors(tag);
        }
    },

    Drupal.bibdkKopiOptions =  function(element,context) {
        var pid = $(element).attr('pid');
        // save context in global var to reload later
        Drupal.settings.sbkopi = context;
        // Call ajax
        $.ajax({
            url:Drupal.settings.basePath + Drupal.settings.pathPrefix + 'sbkopi/ajax',
            type:'POST',
            data:{
                pid:pid
            },
            dataType:'json',
            success:Drupal.addCopyLink
        });
    }


    /** Get copy options via ajax */
    Drupal.behaviors.sbKopi = {
        attach:function (context) {
            $('.bibdk-sb_kopi-replaceme', context).each(function (i, element) {
                Drupal.bibdkKopiOptions(element,context);
            });
        },

        detach:function (context) {}
    };

})(jQuery);
