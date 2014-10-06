(function ($) {

    $(document).ready(function () {
        Drupal.bibdkCustomSearchOptionsSubgroup();
        Drupal.bibdkCustomSearchClearEmptyFields();
    });

    Drupal.bibdkCustomSearchClearEmptyFields = function () {
        $('#search-block-form').submit(function(e) {
            $('input[name]').each(function(){
                if($(this).val() === '') {
                    $(this).attr('name', '');
                }
            });
        });
    }

    Drupal.bibdkCustomSearchOptionsSubgroup = function () {
        $('fieldset[data-child]').hide();
        // $('div[data-child]').hide();
        // If child checkbox is checked remove checked from parent
        $('fieldset[data-child] input').change(function () {
            if ($(this).attr('checked') == true) {
                var parentKey = $(this).closest('fieldset[data-child]').attr('data-child');
                $('[data-parent=' + parentKey + ']').attr('checked', false);
            }
        });
        // If parent checkbox is checked remove checked from children
        $('input[data-parent]').change(function () {
            if ($(this).attr('checked') == true) {
                var childKey = $(this).attr('data-parent');
                $('fieldset[data-child=' + childKey + '] input').attr('checked', false);
            }
        });
        $('.toggle-subgroup').click(function (e) {
            e.preventDefault();
            $(this).toggleClass('toggled');
            var childKey = $(this).attr('data-child');
            $('fieldset[data-child=' + childKey + ']').toggle();
        });

        /* Expand all subgroups with selected values*/
        $('fieldset[data-child] input:checked').each(function (i, element) {
            var childKey = $(element).closest('fieldset[data-child]').attr('data-child');
            var trigger = $('[data-child=' + childKey + ']:not(.toggled).toggle-subgroup');
            trigger.trigger('click');
        });

        // Autoselect the 'all' values under checkboxes
        $('input[type=checkbox].master').attr('checked', true);
        $('input[type=checkbox].default-value').attr('checked', true);
        $('input[type=checkbox]').change(function (e) {
            var group = $(this).attr('data-group');
            if ($(this).attr('checked')) {
                if ($(this).hasClass('master')) {
                    $('[data-group=' + group + ']').attr('checked', false);
                    $(this).attr('checked', true);
                }
                else {
                    $('[data-group=' + group + '].master').attr('checked', false)
                }
            }
            else if ($('[data-group=' + group + ']:checked').length == 0) {
                $('[data-group=' + group + '].master').attr('checked', true);
            }
        });
        $('input[type=checkbox]:checked:not(.default-value)').closest(".bibdk-custom-search-element").find("input").each(function (i) {
            if ($(this).hasClass('default-value')) {
                $(this).attr('checked', false);
            }
        });
    };

    Drupal.setBodyClass = function (currClass) {
        var classesArr = $('body').attr('class').split(' ');

        for (var i = 0; i < classesArr.length; i++) {
            if (classesArr[i].indexOf('page-bibdk-frontpage') >= 0) {
                classesArr.splice(i, 1);
            }
        }
        classesArr.push(currClass);

        $('body').removeClass();
        $('body').addClass(classesArr.join(' '));
    };

    Drupal.response = function (response) {
        $('.panel-left').empty();
        $('.works').empty();

        $('#search-form').html(response.form);

        $(document).attr('title', response.label_type);
        Drupal.setBodyClass(response.bodyclass);
        Drupal.bibdkCustomSearchOptionsSubgroup();
        Drupal.attachBehaviors('.container', Drupal.settings);
        Drupal.toggleSearchPage();

        if (typeof(window.history.pushState) == 'function') {
            window.history.pushState({}, '', Drupal.settings.basePath + Drupal.settings.pathPrefix + response.request); //TODO IE Fix
        }
    };

    Drupal.toggleSearchPage = function () {
        $('.text-white').addClass('toggled');
    };

    Drupal.behaviors.bibdkCustomSearchCheckboxes = {
        attach: function (context, settings) {
            $('.form-type-checkbox input').change(function () {
                // clear other checkboxes if top-level default is selected, and default value is null.
                if ($(this).hasClass('default-value') && $(this).is(':checked') && !$(this).val()) {
                    $(this).closest(".bibdk-custom-search-element").find("input").each(function (i) {
                        if (!$(this).hasClass('default-value')) {
                            $(this).attr('checked', false);
                        }
                    })
                }
                // clear top-level default if other checkboxes is selected, and default value is null.
                if (!$(this).hasClass('default-value') && $(this).is(':checked')) {
                    $(this).closest(".bibdk-custom-search-element").find("input").each(function (i) {
                        if ($(this).hasClass('default-value')) {
                            $(this).attr('checked', false);
                        }
                    })
                }
                // set top-level default as selected, if all other checkboxes are unchecked.
                if (!$(this).is(':checked')) {
                    var counter = 0;
                    $(this).closest(".bibdk-custom-search-element").find("input").each(function (i) {
                        if ($(this).is(':checked')) {
                            counter++;
                        }
                    })
                    if (!counter) {
                        $(this).closest(".bibdk-custom-search-element").find("input.default-value").attr('checked', true);
                    }
                }
            });
        }
    };
}(jQuery));

