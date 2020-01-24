(function ($) {

  /**
   *
   */
  Drupal.behaviors.bibdk_autocomplete_update_fields = {
    attach: function (context, settings) {
      $('#bibdk-autocomplete-admin .bibdk-autocomplete-admin-operation').each(function (context) {
        bibdk_autocomplete_update_fields($(this));
      });
      $('#bibdk-autocomplete-admin .bibdk-autocomplete-admin-operation').change(function (context) {
        bibdk_autocomplete_update_fields($(this));
      });
    }
  };

  /**
   * Disable sort order control, if scan function is elected
   * Disable facetIndex control, if scan or terms function is elected
   */
  bibdk_autocomplete_update_fields = function ($obj) {
    if ($obj.val() == 'scan') {
      $obj.parent().parent().find('.bibdk-autocomplete-admin-sort').attr('disabled',true);
      $obj.parent().parent().find('.bibdk-autocomplete-admin-sort').closest('div.form-item').addClass('disabled');
      if ( jQuery.isFunction( $obj.parent().parent().find('.bibdk-autocomplete-admin-aggregate').prop ) ) {
        //  jQuery 1.6+
        $obj.parent().parent().find('.bibdk-autocomplete-admin-aggregate').prop('checked', false);
      } else {
        $obj.parent().parent().find('.bibdk-autocomplete-admin-aggregate').attr('checked', false);
      }
      $obj.parent().parent().find('.bibdk-autocomplete-admin-aggregate').attr('disabled',true);
      $obj.parent().parent().find('.bibdk-autocomplete-admin-aggregate').closest('div.form-item').addClass('disabled');
    } else {
      $obj.parent().parent().find('.bibdk-autocomplete-admin-sort').attr('disabled',false);
      $obj.parent().parent().find('.bibdk-autocomplete-admin-sort').closest('div.form-item').removeClass('disabled');
      $obj.parent().parent().find('.bibdk-autocomplete-admin-aggregate').attr('disabled',false);
      $obj.parent().parent().find('.bibdk-autocomplete-admin-aggregate').closest('div.form-item').removeClass('disabled');
    }
    if ($obj.val() == 'terms' || $obj.val() == 'scan') {
      $obj.parent().parent().find('.bibdk-autocomplete-admin-facetIndex').attr('disabled',true);
      $obj.parent().parent().find('.bibdk-autocomplete-admin-facetIndex').closest('div.form-item').addClass('disabled');
    } else {
      $obj.parent().parent().find('.bibdk-autocomplete-admin-facetIndex').attr('disabled',false);
      $obj.parent().parent().find('.bibdk-autocomplete-admin-facetIndex').closest('div.form-item').removeClass('disabled');
    }
  };

})(jQuery);