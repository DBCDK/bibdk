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
        toggleItemInCart($(this));
      });
    }
  };

  /**
   * Toggle item state in cart
   */
  function toggleItemInCart($button) {
    addStateDisabled($button);
    var pid = $button.attr('data-pid');
    doUpdateCart(pid);
  }

  /**
   * Update cart state on server via ajax
   */
  function doUpdateCart(pid) {
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
    if(data.error) {
      alert(Drupal.t('error_refresh_page_and_try_again', {}, {context: 'bibdk_cart:error'}));
    }
    $button = $('[data-pid=' + data.pid + ']');
    removeStateDisabled($button);
    $button.toggleClass('in-cart');
  }

  /**
   * Add throbber
   */
  function addStateDisabled($element) {
    $element.addClass('ajax-progress');
    $element.append('<span class="throbber">&nbsp;</span>');
  }

  /**
   * remove throbber
   */
  function removeStateDisabled($element) {
    $element.removeClass('ajax-progress');
    $element.find('.throbber').remove();
  }

}(jQuery));
