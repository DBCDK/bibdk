/*
 * @file
 * JavaScript for bibdk_searchhistory.
 * Adding Memolist checkbox functionality
 *
 */

(function ($) {
    Drupal.behaviors.bibdk_searchhistory = {
        attach: function (context) {
            var basePath = Drupal.settings.basePath;

            $('.select-all', context).click(function (e) {
                e.preventDefault();
                if ($('input.combine-select').length == $('input.combine-select:checked').length) {
                    $('input.combine-select').attr('checked', false);
                }
                else {
                    $('input.combine-select').attr('checked', true);
                }
                countSelected();
            });

            $('.delete-selected', context).click(function (e) {
                e.preventDefault();
                $('#delete-selected-buffer', context).val("delete");
                $(this).parents('form').submit();
            });

            //single rows
            $('input.combine-select', context).change(function () {
                countSelected()
            });

            function countSelected() {
                $('#edit-delete, #edit-combine').attr('disabled', 1);
                var count = $('input.combine-select:checked').length;
                if (count >= 1) {
                    $('#edit-delete').removeAttr('disabled');
                }
                if (count >= 2) {
                    $('#edit-combine').removeAttr('disabled');
                }
            }

        }
    };
})(jQuery);
