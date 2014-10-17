(function ($) {
    Drupal.behaviors.sbCopy = {
        attach: function(context, settings) {
            $('.switch-views').click(function(e){
                e.preventDefault();
                // find element with class switch-me
                $('.switch-me').each(function(e){
                    if($(this).hasClass('visuallyhidden')){
                        $(this).removeClass('visuallyhidden');
                    }
                    else{
                        $(this).addClass('visuallyhidden');
                    }
                });
            });
        }
    };
})(jQuery);

