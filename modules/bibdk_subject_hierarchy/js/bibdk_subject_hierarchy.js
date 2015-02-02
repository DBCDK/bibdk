// <?php
/**
 * @file
 * bibdk_subject_hierarchy javascript file
 */
// ?>

(function ($) {
    Drupal.behaviors.subject_hierarchy_action = {
        attach: function (context) {
            $('.subjects-close-button a', context).click(function (e) {
                e.preventDefault();
                $('.subject-item').removeClass('subject-item--active');
                $('.subjects-sublist-wrapper').fadeOut('200');
            });
        }
    };
    Drupal.ajax.prototype.commands.afterAjaxSubmit = function(ajax, response, status) {
        $(response.selector).replaceWith(response.value);
        $('#bibdk-subject-hierarchy-content').hide();
        $(response.selector).hide();
        $(response.selector).fadeIn('200');
        $('.close', response.selector).click(function (event) {
            event.preventDefault();
            $(response.selector).hide();
            $('#bibdk-subject-hierarchy-content').fadeIn('200');
        });
        Foundation.libs.dropdown.close($('#searchfield-dropdown'));
    }

    Drupal.behaviors.subject_hierarchy_suggestion_close = {
        attach: function (context) {
            $('.close', context).click(function (e) {
                e.preventDefault();
                $('#bibdk-subject-hierarchy-searchresult').hide();
                $('#bibdk-subject-hierarchy-content').fadeIn('200');
            });
        },
        detach: function (context) {
        }
    };

}(jQuery));
