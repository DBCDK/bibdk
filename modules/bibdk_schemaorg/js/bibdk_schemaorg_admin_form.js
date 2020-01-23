(function($) {

  $(document).ready(function() {
    Drupal.schemaToggleDatatypeProperty();
  });

  Drupal.behaviors.schemaToggleDataType = {
    attach: function(context, settings) {
      $('#edit-bibdk-schemaorg-field-typeof').change(function() {
        Drupal.schemaToggleDatatypeProperty();
      });
    }
  };

  Drupal.schemaToggleDatatypeProperty = function() {
    
    if ( $('#edit-bibdk-schemaorg-field-typeof-property').val() != '' ) {
      $('.form-item-bibdk-schemaorg-field-typeof-property').show();
      return;
    }
    
    if ( $('#edit-bibdk-schemaorg-field-typeof').val() != '' ) {
      $('.form-item-bibdk-schemaorg-field-typeof-property label .form-required').show('');
      $('.form-item-bibdk-schemaorg-field-typeof-property').show();
      return;
    }
    
    $('.form-item-bibdk-schemaorg-field-typeof-property').hide();
    $('.form-item-bibdk-schemaorg-field-typeof-property label .form-required').hide('');
    
  };

} (jQuery));

