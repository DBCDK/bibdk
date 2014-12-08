(function($) {

  var button;

  Drupal.cartResponse = function(data) {
    if(data.error) {
      alert(Drupal.t('error_refresh_page_and_try_again', {}, {context: 'bibdk_cart:error'}));
    }

    if(data.saved === 1) {
      $('.link-add-basket[data-pid=' + data.pid + ']').text(Drupal.t('remove_item_from_cart', {}, {context: 'bibdk_cart'}));
    }
    else {
      $('.link-add-basket[data-pid=' + data.pid + ']').text(Drupal.t('add_item_to_cart', {}, {context: 'bibdk_cart'}));
      Drupal.updateCartview(data.classid);
    }
    $('.link-add-basket[data-pid=' + data.pid + ']').removeClass('ajax-progress');

    if(data.cartcount != 'undefined') {
      Drupal.updateCartcount(data.cartcount);
    }

    Drupal.setCheckboxState(data);
  };

  Drupal.setCheckboxState = function(data) {
    if(button !== null) {
      if(data.saved === 1) {
        $(button).toggleClass('btn-grey', true);
        $(button).toggleClass('btn-blue', false);
        $(button).toggleClass('disabled', false);
      }
      else {
        $(button).toggleClass('btn-grey', false);
        $(button).toggleClass('btn-blue', true);
        $(button).toggleClass('disabled', false);
      }
      button = null;
    }
  };

  Drupal.addRemoveItem = function(element) {
    var pid = $(element).attr('data-pid');
    /* Add throbber*/
    $(element).addClass('ajax-progress');
    $(element).html('<span class="throbber">&nbsp;</span>');

    Drupal.doUpdateCart(pid);
  };

  Drupal.addRemoveItemButton = function(element) {
    button = element;
    $(button).toggleClass('btn-grey', false);
    $(button).toggleClass('disabled', true);
    var pid = $(button).attr('data-pid');

    Drupal.doUpdateCart(pid);
  };

  Drupal.doUpdateCart = function(pid) {
    var request = $.ajax({
      url: Drupal.settings.basePath + 'cart/ajax',
      type: 'POST',
      data: {
        pid: pid
      },
      dataType: 'json',
      success: Drupal.cartResponse
    });
  };

  Drupal.updateCartcount = function(cartcount) {
    var text = Drupal.formatPlural(cartcount, '1 item in cart', '@count items in cart');
    $('.cartcount').text(text);
  };

  Drupal.updateCartview = function(id) {
    var cid = '.cart-item-id-' + id;
    $(cid).remove();
  };

  Drupal.behaviors.cart = {
    attach: function(context) {
      $('.link-add-basket', context).click(function() {
        Drupal.addRemoveItem($(this));
      });

      $('.add-item-to-cart', context).click(function(e) {
        e.preventDefault();
        Drupal.addRemoveItemButton($(this));
      });
    }
  };
}(jQuery));
