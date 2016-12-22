(function ($) {

    /** @namespace Namespace for BibdkSaou classes and functions. */
    var BibdkSaou = {

        bibdkActivateSaouRessource: function (ressource) {
             $('html').click(function() {
               $('.dropdown-menu-link').removeClass('hidden');
               $('.soau-ressource-click-links').addClass('hidden');
              });
        }
    };

    Drupal.behaviors.bibdk_saou_load = {
        attach: function (context) {
            $('.soau-ressource-click-links', context).click(function (e) {
                e.preventDefault();
                BibdkSaou.bibdkActivateSaouRessource($(this));
            });
        }
    };
}
(jQuery));