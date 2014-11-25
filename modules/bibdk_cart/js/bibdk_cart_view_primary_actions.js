(function($) {
  Drupal.deSelectAll = function() {
    var element = $('.table input[type=checkbox]');
    var items = element.length;
    var selected = 0;

    element.each(function() {
      if(this.checked) {
        selected++;
      }
    });

    Drupal.markCheckboxes(!(selected === items), element);
    Drupal.deActivateDeleteAllBtn();
  };

  Drupal.markCheckboxes = function(asSelected, element) {
    if(!element) {
      element = $('.table input[type=checkbox]');
    }

    if(!asSelected) {
      element.each(function() {
        this.checked = false;
      });
    }
    else {
      element.each(function() {
        this.checked = true;
      });
    }
  };

  Drupal.deActivateDeleteAllBtn = function() {
    var selected = 0;
    var element = $('.table input[type=checkbox]');
    var deleteAllBtn = $('.cart-view-delete-selected');
    element.each(function() {
      if(this.checked) {
        selected++;
      }
    });

    if(selected !== 0) {
      deleteAllBtn.removeClass('inactive');
      $('.cart-action-btn').removeClass('inactive');
    }
    else {
      deleteAllBtn.addClass('inactive');
      $('.cart-action-btn').addClass('inactive');
    }
  };

  Drupal.deleteSelected = function() {
    var element = $('.table input[type=checkbox]');

    var items = [];
    var elements = [];

    element.each(function() {
      if(this.checked) {
        items.push(this.value);
        elements.push(this);
        this.checked = false;
      }
    });
    $('.cart-view-delete-selected').addClass('inactive');

    if ( items.length == element.length ) {
      var r = confirm(Drupal.t('confirm_delete_bibdk_cart', {}, {context: 'bibdk_cart'}));
      if ( r == false ) {
        return false;
      }
    }

    $.ajax({
      url: Drupal.settings.basePath + 'cart/ajax/deleteitems',
      type: 'POST',
      data: {
        pids: items
      },
      dataType: 'json',
      success: function(data) {
        if ( data.error ) {
          alert(Drupal.t('error_please_refresh_page_and_try_again', {}, {context: 'bibdk_cart'}));
          return false;
        }
        else {
          $('.cart-view-delete-selected').removeClass('ajax-progress');
          $('.cart-view-delete-selected').find('.throbber').remove();
          elements.forEach(function(element) {
            $(element).closest('tr').remove();
          });
          var text = Drupal.formatPlural(data.cartcount, '1 item in cart', '@count items in cart');
          $('.cartcount').text(text);
          return true;
        }
      }
    });
  };

  Drupal.behaviors.cart = {
    attach: function(context) {
      $('.cart-view-mark-all', context).click(function(e) {
        e.preventDefault();
        Drupal.deSelectAll();
      });

      $('.table input[type=checkbox]', context).click(function(e) {
        Drupal.deActivateDeleteAllBtn();
      });

      $('.cart-view-delete-selected', context).click(function(e) {
       e.preventDefault();
        if($(this).hasClass('inactive')) {
          return false;
        }
        else {
          var deleted = Drupal.deleteSelected();
          if ( deleted ) {
            $(this).addClass('ajax-progress');
            $(this).addClass('inactive');
            $(this).append('<span class="throbber">&nbsp;</span>');
            return false;
          }
          return false;
        }
      });
    }
  };
}(jQuery));
