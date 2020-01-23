(function ($) {

    Drupal.cart_popup = function (href) {
        var settings = {
            height: 600, // sets the height in pixels of the window.
            width: 600, // sets the width in pixels of the window.
            toolbar: 0, // determines whether a toolbar (includes the forward and back buttons) is displayed {1 (YES) or 0 (NO)}.
            scrollbars: 1, // determines whether scrollbars appear on the window {1 (YES) or 0 (NO)}.
            status: 0, // whether a status line appears at the bottom of the window {1 (YES) or 0 (NO)}.
            resizable: 1, // whether the window can be resized {1 (YES) or 0 (NO)}. Can also be overloaded using resizable.
            left: 0, // left position when the window appears.
            top: 0, // top position when the window appears.
            location: 0, // determines whether the address bar is displayed {1 (YES) or 0 (NO)}.
            menubar: 0 // determines whether the menu bar is displayed {1 (YES) or 0 (NO)}.
        };
        var parameters = "location=" + settings.location + ",menubar=" + settings.menubar + ",height=" + settings.height + ",width=" + settings.width + ",toolbar=" + settings.toolbar + ",scrollbars=" + settings.scrollbars + ",status=" + settings.status + ",resizable=" + settings.resizable + ",left=" + settings.left + ",screenX=" + settings.left + ",top=" + settings.top + ",screenY=" + settings.top;
        window.open(href, 'actions', parameters);
    };

    Drupal.behaviors.cart_action = {
        attach: function (context) {
            $('.cart-action-btn', context).click(function (e) {
                e.preventDefault();
                var checkedVals = $('input:checkbox:checked').map(function () {
                    return this.value;
                }).get();
                if (checkedVals.length > 0) {

                    var href = $(this).attr('href');
                    if (href.substr(href.length - 1) != '/'){
                        href += '/';
                    }
                    href += checkedVals.join(";");

                    if ($(this).hasClass('cart-popup'))
                        Drupal.cart_popup(href);
                    else if ($(this).attr('target') == '_blank')
                        window.open(href, '_blank');
                    else
                        window.location = encodeURI(href);

                }
            });
        }
    };
}(jQuery));
