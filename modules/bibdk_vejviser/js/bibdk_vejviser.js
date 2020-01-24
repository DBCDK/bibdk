(function($) {

  Drupal.behaviors.bibdkVejviserOnChange = {
    attach: function(context, settings) {
      $('input[name="openagency_query"]').change(function() {
        var value = $(this).val();
        value = value.replace('*', '?');
        $(this).val(value);
      });
    }
  };

} (jQuery));
