/**
 * javascript to get sb_kopi options
 * script attached in bibdk_sbkopi.field.inc::bibdk_sbkopi_field_formatter_view
 **/
(function($) {
  Drupal.addCopyLink = function(data) {
    if(data.link != 'error') {
      var $tag = $(".bibdk-sb_kopi-replaceme[pid=\"" + data.pid + "\"]");
      //the link needs to wrapped for attachBehaviors to work
      var $link = $("<div class=\"link-wrapper\"></div>").html($(data.link));
      $tag.replaceWith($link);
      var settings = data.settings || Drupal.settings;
      Drupal.attachBehaviors($link, settings);
    }
  };

    Drupal.bibdkKopiOptions = function(element, context) {
      var issn = $(element).attr("issn");
      var pid = $(element).attr("pid");
      // save context in global var to reload later
      Drupal.settings.sbkopi = context;
      // Call ajax
      $.ajax({
        url: Drupal.settings.basePath + Drupal.settings.pathPrefix + "sbkopi/ajax",
        type: "POST",
        data: {
          issn: issn,
          pid: pid
        },
        dataType: "json",
        success: Drupal.addCopyLink
      });
    };

    /** Get copy options via ajax */
    Drupal.behaviors.sbKopi = {
      attach: function(context) {
        $(".bibdk-sb_kopi-replaceme", context).each(function(i, element) {
          Drupal.bibdkKopiOptions(element, context);
        });
      },

      detach: function(context) {
      }
    };

  }
  )
  (jQuery);
