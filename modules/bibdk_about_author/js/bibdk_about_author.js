(function ($) {

    /** Insert about_author results */
    Drupal.addAboutAuthor = function (about_author) {
        if ( about_author.error ) {
          $('.about-author-load[data-query=' + about_author.query + ']').parent().parent().find('.toggle-text').html(about_author.toggle_text);
          $('.about-author-load[data-query=' + about_author.query + ']').replaceWith(about_author.error_msg);
        }
        if ( about_author.list ) {
          $('.about-author-load[data-query=' + about_author.query + ']').replaceWith(about_author.list);
          $('.about-author-more[data-query=' + about_author.query + ']').removeClass('visuallyhidden');
        }
    },

    Drupal.loadAboutAuthor = function (element) {
        var query = $(element).attr('data-query');
        /* Add throbber*/
        $(element).addClass('ajax-progress');
        $(element).html('<span class="throbber">&nbsp;</span>');

        /* Call ajax */
        var request = $.ajax({
            url:Drupal.settings.basePath + 'about_author/ajax',
            type:'POST',
            data:{
                query:query
            },
            dataType:'json',
            success:Drupal.addAboutAuthor
        });
    };

    /** Get holdingstatus via ajax */
    Drupal.behaviors.aboutAuthor = {
        attach:function (context) {
            $('.field-type-worktabs .bibdk-tabs', context).one( "click", function() {
                $('.about-author-load', context).each(function (i, element) {
                    Drupal.loadAboutAuthor(element);
                });
            });
        },
        detach:function (context) {
        }
    };
}(jQuery));
