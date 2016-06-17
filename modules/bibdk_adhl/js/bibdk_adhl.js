(function($) {

  var BibdkAdhl = {};
  /* set link action to popup link overlay */
  BibdkAdhl.setLinkActions = function(context) {
    $("a[href*='/overlay/adhl/top/20/'], a[href*='?q=overlay/adhl/top/20/']", context).attr({
    }).addClass('bibdk-popup-link');
  };

  /** Insert adhl results */
  function addRecommendation(adhl) {
    if(adhl.error) {
      $('.recommendation-load[data-pid="' + adhl.pid + '"]')
        .parent()
        .parent()
        .find('.toggle-text')
        .html(adhl.toggle_text);
      $('.recommendation-load[data-pid="' + adhl.pid + '"]').replaceWith(adhl.error_msg);
    }
    if(adhl.list) {
      $('.recommendation-load[data-pid="' + adhl.pid + '"]').replaceWith(adhl.list);
      $('.recommendation-more[data-pid="' + adhl.pid + '"]').removeClass('visuallyhidden');
    }
  };

  function loadRecommendation(element) {
    var pid = $(element).attr('data-pid');
    var isbn = $(element).attr('data-isbn');
    /* Add throbber*/
    $(element).addClass('ajax-progress');
    $(element).html('<span class="throbber">&nbsp;</span>');

    /* Call ajax */
    var request = $.ajax({
      url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'adhl/ajax',
      type: 'POST',
      data: {
        pid: pid
      },
      dataType: 'json',
      success: addRecommendation
    });
  };

  /** Get holdingstatus via ajax */
  Drupal.behaviors.recommendation = {
    attach: function(context) {
      $('.field-type-worktabs .bibdk-tabs', context).one("click", function() {
        $('.recommendation-load', context).each(function(i, element) {
          loadRecommendation(element);
        });
      });
      BibdkAdhl.setLinkActions(context);
    }
  };

}(jQuery));

