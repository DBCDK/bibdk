/**
 * @file
 * controls behaviour for cart button
 */

(function cartButton($) {

  /**
   * Attach cart behaviour to dom elements
   */
  Drupal.behaviors.cart = {
    attach: function(context) {
      $('.add-item-to-cart', context).click(function(e) {
        e.preventDefault();
        // Stop propagation in order to prevent the orderAnyButton to close on
        // click
        e.stopPropagation();
        var $element = $(this);
        if(!$element.hasClass('disabled')) {
          toggleItemInCart($element);
        }
      });
    }
  };

  /**
   * Toggle item state in cart
   */
  function toggleItemInCart($element) {
    addStateDisabled($element);
    doUpdateCart($element);
  }

  /**
   * Update cart state on server via ajax
   */
  function doUpdateCart($button) {
    var pid = $button.attr('data-cart-pid');
    $.ajax({
      url: Drupal.settings.basePath + 'cart/ajax',
      type: 'POST',
      data: {
        pid: pid
      },
      dataType: 'json',
      success: cartResponse
    });
  }

  /**
   * Handle response from ajax call
   */
  function cartResponse(data) {
    $button = $('[data-cart-pid="' + data.pid + '"]');
    removeStateDisabled($button);
    if(data.error) {
      alert(Drupal.t('error_refresh_page_and_try_again', {}, {context: 'bibdk_cart:error'}));
    }
    else {
      $button.toggleClass('in-cart');
    }
  }

  /**
   * Add throbber
   */
  function addStateDisabled($element) {
    $element.addClass('ajax-progress');
    $element.addClass('disabled');
    $element.append('<span class="throbber">&nbsp;</span>');
  }

  /**
   * remove throbber
   */
  function removeStateDisabled($element) {
    $element.removeClass('ajax-progress');
    $element.removeClass('disabled');
    $element.find('.throbber').remove();
  }

})(jQuery);
