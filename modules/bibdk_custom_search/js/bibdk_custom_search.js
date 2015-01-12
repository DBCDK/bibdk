(function($) {

  /**
   * If we are on devicesize large and up request and insert the advanced
   * search panel
   */
  function getAdvancedSearchPanel() {
    console.clear();
    console.log("getAdvancedSearchPanel");
    if(window.matchMedia(window.Foundation.media_queries.large).matches){
      console.log("get advanced search panel...");
    }
  };

  Drupal.behaviors.bibdk_custom_search = {
    attach: function(context) {
      getAdvancedSearchPanel();
    }
  };
}(jQuery));
