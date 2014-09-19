(function($) {
    Drupal.doSearch = function(element) {
        var tableClass = '.further-search-table-' + element.attr('data-id');

        var types = '';
        var elements = '';
        var fictions = '';

        $(tableClass + ' input[type=checkbox]').each(function() {
            if(this.checked) {
                switch($(this).attr('data-type')) {
                    case 'type':
                        types = Drupal.addType(types, $(this).attr('data-code'));
                        break;
                    case 'element':
                        elements = Drupal.addElement(elements, $(this).attr('data-code'));
                        break;
                    case 'fiction':
                        fictions = Drupal.addFiction(fictions, $(this).attr('data-code'));
                        break;
                    default:
                        throw new Error('no data-type provided');
                        break;
                }
            }
        });

        var url = Drupal.makeUrl(types, elements, fictions);
        window.open(Drupal.settings.basePath + Drupal.settings.pathPrefix + 'search/work/' + url, '_self');
    };

    Drupal.makeUrl = function(types, elements, fictions) {
        var url = elements;
        if(fictions !== ''){
            url += ' and ' + fictions;
        }

        if(types !== '') {
            url += types;
        }

        return url;
    };

    Drupal.addType = function(types, type) {
        if(types === '') {
            types = '?facets[]=' + type;
        } else {
            types += '&' + type;
        }
        return types;
    };

    Drupal.addElement = function(elements, element) {
        if(elements === '') {
            elements = element;
        } else {
            elements += ' and ' + element;
        }
        return elements;
    };

    Drupal.addFiction = function(fictions, type) {
        if(fictions === '') {
            fictions = type;
        } else {
            fictions += ' and ' + type;
        }
        return fictions;
    };

    Drupal.isOneElementSelected = function(element) {
        var tableClass = '.further-search-table-' + element.attr('data-id');
        var counter = 0;
        $(tableClass + ' input[type=checkbox]').each(function() {
            if(this.checked && $(this).attr('data-type') === 'element') {
                ++counter;
            }
        });
        return counter;
    };

    Drupal.behaviors.furthersearch = {
        attach: function(context) {
            $('.further-search-btn', context).click(function() {
                if(Drupal.isOneElementSelected($(this))) {
                    Drupal.doSearch($(this));
                } else {
                    alert(Drupal.t('alert_please_select_at_least_one_element', {}, {context: 'bibdk_furthersearch'}));
                }
            });
        }
    };
}(jQuery));
