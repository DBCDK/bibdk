/* 
 * add this function to Drupal.ajax.prototype commands 
 * to use it as standard drupal #ajax
 */

(function ($){
    if(typeof(Drupal.ajax) == 'undefined') {
      return false;   
    }
    // add this function to Drupal ajax commands
    Drupal.ajax.prototype.commands.favourite_set = function(ajax, response, status){
        var standard_txt = Drupal.t('set_as_favourite');
        // remove order-agency class for all articles
        $('article').removeClass('order-agency');
        $('article').each(function(index){
            var hest = $(this).find('a').first();
            hest.removeClass('selected-agency');
            hest.addClass('not-selected-agency');
            hest.text(standard_txt);            
        });
        
        // set given artice as selected
        var selector = response['selector'];        
        $('.'+selector).addClass('order-agency');
        var orderagency = $('.'+selector).find('a').first();
        orderagency.addClass('selected-agency');
        var text = Drupal.t('Order agency');
        orderagency.text(text);
    }
})(jQuery);