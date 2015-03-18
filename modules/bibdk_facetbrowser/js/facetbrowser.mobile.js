/**
 * @file
 * Mobile Foundation reveal functionality for facets
 */

(function($) {

  Drupal.behaviors.bibdkFacetMobile = {
    attach: function(context, settings) {

      // select facet group
      var clickHandlerFacetGroup = function() {
        $(this).find('input').click();
      };

      $('.bibdk-facetbrowser-mobile.facet-group .facet-wrapper').each(function(event) {
        $(this).not('.processed').on("click", clickHandlerFacetGroup);
        $(this).addClass('processed'); // click event is attached twice(!?) otherwise
      });

      // check/uncheck facet values
      var clickHandlerFacetValues = function() {
        if ( $(this).find('.facet-select-actions input').prop('value') == '1' ) {
          $(this).find('.facet-select-actions input').prop('value', '0');
        } else {
          $(this).find('.facet-select-actions input').prop('value', '1');
        }
        $(this).find('.facet-checkmark-wrapper span').toggleClass("checked");
      };

      $('.bibdk-facetbrowser-mobile.facet-values .facet-wrapper').each(function(event) {
        $(this).not('.processed').on("click", clickHandlerFacetValues);
        $(this).addClass('processed'); // click event is attached twice(!?) otherwise
      });

    }
  };

})(jQuery);
