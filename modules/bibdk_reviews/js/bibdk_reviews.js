(function ($) {
    Drupal.behaviors.bibdk_reviews = {
        attach: function (context) {
            $('.reviews', context).click(function () {
                var href= $(this).attr('href');
                $(href).find('.ajax-trigger').trigger('click');
            });

        }
    };
})(jQuery);

