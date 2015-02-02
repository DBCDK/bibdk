(function($) {

  var BibdkModal = {};

  // ===========================================================================
  //   COMMANDS
  // ---------------------------------------------------------------------------
  if (typeof(Drupal.ajax) != 'undefined') {
      Drupal.ajax.prototype.commands.bibdk_modal_reload = function (ajax, data, status) {
          BibdkModal.detachBehaviorsOnModal();
          var currentUrl = document.URL;
          if (currentUrl.indexOf("reservation?ids") != -1) {
              window.location.href = currentUrl;
              if (window.opener != null) {
                  window.opener.location.reload(true);
              }
          }
          else {
              location.reload(true);
              if (window.opener != null) {
                  window.opener.location.reload(true);
              }
          }
      };

      Drupal.ajax.prototype.commands.bibdk_modal_replace_form = function (ajax, data, status) {
          if (status === 'success') {
              var selector = data.selector;
              var html = data.html;
              $(selector).replaceWith(html);
              BibdkModal.detachBehaviorsOnModal(true);
              onLoad.setFocus();
          }
          else {
              console.log('error');
          }
      };

      Drupal.ajax.prototype.commands.bibdk_modal_dismiss = function (ajax, data, status) {
          BibdkModal.detachBehaviorsOnModal();
          jQuery('a.close-reveal-modal').trigger('click');
      };

      Drupal.ajax.prototype.commands.bibdk_modal_redirect = function (ajax, data, status) {
          location.href = data.url;
      };
  }
  // ---------------------------------------------------------------------------
  //   COMMANDS -- END
  // ===========================================================================

  BibdkModal.detachBehaviorsOnModal = function(reattach) {
    var reattach = reattach || false;
    var modal = document.getElementById('bibdk-modal');
    Drupal.detachBehaviors(modal, null, null);
    if(reattach) {
      BibdkModal.attachBehaviorsOnModal();
    }
  };

  BibdkModal.attachBehaviorsOnModal = function() {
    var modal = document.getElementById('bibdk-modal');
    Drupal.attachBehaviors(modal, null);
  };

  BibdkModal.setLinkActions = function(context) {
    //Rewrite login link
    $("a[href*='/user/login'], a[href*='?q=user/login']", context).attr({
      'data-reveal-id': 'bibdk-modal',
      'data-reveal-ajax': 'true',
      'href': function(key, value) {
        return value.replace(/user\/login/, 'bibdk_modal/login');
      }
    }).addClass('bibdk-modal-login');

    //Rewrite 'my page' menu login link
    $(".not-logged-in.page-user .tabs.primary a[href$='/user'], .not-logged-in.page-user .tabs.primary a[href$='?q=user']", context).attr({
      'data-reveal-id': 'bibdk-modal',
      'data-reveal-ajax': 'true',
      'href': function(key, value) {
        return value.replace(/user/, 'bibdk_modal/login');
      }
    }).addClass('bibdk-modal-login');

    //Rewrite edit favourite user data link
    $("a[href*='/overlay/favourite/userdata/'], a[href*='?q=overlay/favourite/userdata/']", context).attr({
      'data-reveal-id': 'bibdk-modal',
      'data-reveal-ajax': 'true',
      'href': function(key, value) {
        return value.replace(/overlay\/favourite\/userdata/, 'bibdk_modal/favourite/userdata');
      }
    }).addClass('bibdk-modal-favourites').removeClass('bibdk-popup-link');

    //Rewrite add favourite library - but only if user is logged in
    if(Drupal.settings.uid) {
      var url = 'user/' + Drupal.settings.uid + '/bibdk_favourite_list?';
      $("a[href*='/" + url + "'], a[href*='?q=" + url + "']", context).attr({
        'data-reveal-id': 'bibdk-modal',
        'data-reveal-ajax': 'true',
        'href': function(key, value) {
          return value.replace(url, 'bibdk_modal/bibdk_favourite_list?');
        }
      }).addClass('bibdk-modal-favourites').removeClass('bibdk-popup-link');
    }

    //Rewrite create review link
    $("a[href*='/voxb/ajax/review/create'], a[href*='?q=voxb/ajax/review/create']", context).attr({
      'data-reveal-id': 'bibdk-modal',
      'data-reveal-ajax': 'true',
      'href': function(key, value) {
        return value.replace(/voxb\/ajax\/review\/create/, 'bibdk_modal/voxb/review/create');
      }
    }).addClass('bibdk-modal-voxb-create');

    //Rewrite edit review link
    $("a[href*='/voxb/ajax/review/edit'], a[href*='?q=voxb/ajax/review/edit']", context).attr({
      'data-reveal-id': 'bibdk-modal',
      'data-reveal-ajax': 'true',
      'href': function(key, value) {
        return value.replace(/voxb\/ajax\/review\/edit/, 'bibdk_modal/voxb/review/edit');
      }
    }).addClass('bibdk-modal-voxb-edit');

    //Rewrite offensive content link
    $("a[href*='/voxb/offensive'], a[href*='?q=voxb/offensive']", context).attr({
      'data-reveal-id': 'bibdk-modal',
      'data-reveal-ajax': 'true',
      'href': function(key, value) {
        return value.replace(/voxb\/offensive/, 'bibdk_modal/voxb/offensive');
      }
    }).addClass('bibdk-modal-voxb-edit');
  };

  BibdkModal.addAccessibilityInfo = function(context) {
    var $modal = $("#bibdk-modal", context);
    $modal.attr("aria-hidden", false);
    $modal.attr("role", 'dialog');
  };

  BibdkModal.removeAccessibilityInfo = function() {
    var $modal = $("#bibdk-modal");
    $modal.attr("aria-hidden", true);
    $modal.removeAttr("role");
  };

  BibdkModal.setMainwrapperAttr = function() {
    $('#mainwrapper').attr("aria-hidden", false);
  };

  Drupal.behaviors.bibdk_modal = {
    attach: function(context, settings) {
      BibdkModal.setLinkActions(context);
    },

    detach: function(context) {
      BibdkModal.removeAccessibilityInfo(context);
    }
  };

  Drupal.bibdkModal = BibdkModal;

})(jQuery);