(function($) {

  /**
   * If we are on devicesize large and up request and insert the advanced
   * search panel
   */
  function getAdvancedSearchPanel() {
    if(window.matchMedia(window.Foundation.media_queries.large).matches && !Drupal.settings.bibdk_custom_search.advancedSearchIsLoaded) {
      jQuery.get('bibdk_custom_search_ajax/get_search_panel', {page_id:'bibdk_frontpage'})
        .done(function(data, response) {
          Drupal.settings.bibdk_custom_search.advancedSearchIsLoaded = true;
          var $new = $('#search-advanced-panel', data);
          var $selector = $('#search-advanced-panel');
          $selector.replaceWith($new);
          Drupal.attachBehaviors($selector, Drupal.settings);
        })
        .fail(function() {
          throw new Error('An error happend while loading search pages');
        })
    }
  };

  Drupal.behaviors.bibdk_custom_search = {
    attach: function(context) {
      getAdvancedSearchPanel();
    }
  };
}(jQuery));
