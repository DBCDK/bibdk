(function ($) {
    Drupal.behaviors.custom_search_usersettings = {

        attach: function (context) {

            $('[data-setting-child]', context).each(function (i, element) {
                var parentId = this.getAttribute('data-setting-child');
                var parentValue = $('[data-setting-parent="' + parentId + '"]:checked').val();
                if (parentValue == 1) {
                    $('[data-setting-child=' + parentId + ']').hide();
                }
            });

            $('[data-setting-parent]', context).change(function (e) {
                var parentId = this.getAttribute('data-setting-parent')

                if (this.value == 1) {
                    $('[data-setting-child=' + parentId + '] input[value=0]').attr('checked', 'checked');
                }

                $('[data-setting-child=' + parentId + ']').toggle();
            });
        },
        detach: function (context) {

        }


    };
}(jQuery));

