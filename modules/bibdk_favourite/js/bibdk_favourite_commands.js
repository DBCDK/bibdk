/*
 * add this function to Drupal.ajax.prototype commands
 * to use it as standard drupal #ajax
 */

(function($) {
  if(typeof(Drupal.ajax) == 'undefined') {
    return false;
  }
  // add this function to Drupal ajax commands
  Drupal.ajax.prototype.commands.favourite_set = function(ajax, response, status) {
    var standard_txt = Drupal.t('set_as_favourite', null, null);
    // remove order-agency class for all articles
    var $article = $('article');
    $article.removeClass('order-agency');
    $article.each(function(index) {
      var link = $(this).find('a').first();
      link.removeClass('selected-agency');
      link.addClass('not-selected-agency');
      link.text(standard_txt);
    });

    // set given artice as selected
    var selector = response['selector'];
    var $element = $('.' + selector);
    $element.addClass('order-agency');
    var orderagency = $element.find('a').first();
    orderagency.addClass('selected-agency');
    var text = Drupal.t('Order agency', null, null);
    orderagency.text(text);
  };

})(jQuery);