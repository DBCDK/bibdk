/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 *
 * Change article depending on which tab was pressed in advanced search tabs
 * @see bibdk_custom_search module for implementation of advanced search
 */
/*(function($) {

Drupal.behaviors.GetArticlesOnClick = {
    attach: function(context) {
        $('#search-form .nav--horizontal li', context).click(function(e) {
            Drupal.bibdkArticlesGet($(this));
        });
    }
};

Drupal.bibdkArticlesGet = function(element) {
    var type = element.find('input').attr('data-type');
    $.ajax({
        url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'bibdk_article/searchpage_callback',
        type: 'GET',
        data: {
            type: type
        },
        dataType: 'json',
        success: Drupal.bibdkArticlesReplace
    });
};

Drupal.bibdkArticlesReplace = function(response) {
    $('.bibdk_article_ajax_replace').replaceWith(response.output);
}

}(jQuery));*/
