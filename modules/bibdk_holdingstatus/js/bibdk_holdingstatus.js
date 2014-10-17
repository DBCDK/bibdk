(function ($) {

    /** Insert holding status */
    Drupal.addHoldingStatus = function (holdingstatus) {
        $('.holding-status-load[data-pid=' + holdingstatus.pid + '][data-lid=' + holdingstatus.lid + ']').parent('a').attr('href',holdingstatus.href);
        $('.holding-status-load[data-pid=' + holdingstatus.pid + '][data-lid=' + holdingstatus.lid + ']').replaceWith(holdingstatus.data);
    },
    Drupal.loadHoldingStatus = function(element){
        var pid = $(element).attr('data-pid');
        var lid = $(element).attr('data-lid');
        var href = $(element).parent('a').attr('href');
        
        /* Add throbber*/
        $(element).addClass('ajax-progress');
        $(element).html('<span class="throbber">&nbsp;</span>');

        /* Call ajax */
        var request = $.ajax({
            url:Drupal.settings.basePath + Drupal.settings.pathPrefix + 'holdings/status',
            type:'POST',
            data:{
                pid:pid,
                lid:lid,
                href:href
            },
            dataType:'json',
            success:Drupal.addHoldingStatus
        });
    }
    
    Drupal.setFavouriteHoldings = function(data){
        var div = $('.bibdk-holdings-favourites[data-pid=' + data.pid + ']');
        if(data.html){
        var html = data.html.replace('<!--','');
        html = html.replace('-->',''); 
            div.html(html);
            Drupal.attachBehaviors($('.holding-status-element'));
            div.find('.holding-status-element').each(function (i, element) {
                $(element).removeClass('holding-status-element').addClass('holding-status-load');
                Drupal.loadHoldingStatus(element);
            });
        }
        else{
           div.html('');
        }
    }
    
    Drupal.loadFavouriteHoldings = function(element){
        var pid = $(element).attr('data-pid');
        $(element).text(pid);
        /* Add throbber*/
        $(element).addClass('ajax-progress');
        $(element).html('<span class="throbber">&nbsp;</span>');

        /* Call ajax */
        var request = $.ajax({
            url:Drupal.settings.basePath + Drupal.settings.pathPrefix + 'holdings/favourites',
            type:'POST',
            data:{
                pid:pid
            },
            dataType:'json',
            success:Drupal.setFavouriteHoldings
        });
    }
    /** Get holdingstatus via ajax */
    Drupal.behaviors.holdingsstatus = {

        attach:function (context) {
            $('.bibdk-holdings-favourites', context).each(function (i, element) {
                Drupal.loadFavouriteHoldings(element);
            });
            
            $('.holding-status-load', context).each(function (i, element) {
                Drupal.loadHoldingStatus(element);
            });
            $('.load-holdings', context).click(function(e){
                $(this).siblings().find('.holding-status-element').each(function (i, element) {
                    $(element).removeClass('holding-status-element').addClass('holding-status-load');
                    Drupal.loadHoldingStatus(element);
                });
            });

        },
        detach:function (context) {

        }
    };

}(jQuery));

