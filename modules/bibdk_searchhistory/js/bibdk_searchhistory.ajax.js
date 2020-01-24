/*
 * @file
 * Ajax for bibdk_searchhistory.
 * Adding Memolist functionality
 *
 */

(function($) {
  Drupal.ajax.prototype.commands.searchhistory_remove = function(ajax, response, status) {
    var selector = response['selector'];
    $(selector).closest('tr').remove();
  }
})(jQuery);
