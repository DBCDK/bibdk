/**
 * @file
 * Javascript functionality for bibdk_gdpr
 */
(function ($) {
  Drupal.behaviors.bibdk_gdpr = {
    attach: function (context) {
      $('#button-gdpr-print', context).click(function (e) {
          e.preventDefault();
          window.print();
      });
    }
  };
}(jQuery));

