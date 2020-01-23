(function($) {
  var BibdkSearchControls = {};

  BibdkSearchControls.setCheckboxes = function() {
    $('.bibdk-search-controls-form').change(function() {
      var value = "";
      var idHidden = $(this).attr('data-control-name');

      if(selectValue = $(this).find(".form-type-select select").val()) {
        value = selectValue;
      }

      if(radiosValue = $(this).find(".form-type-radios input:checked").val()) {
        value = radiosValue;
      }

      $(this).find(".form-type-checkboxes .form-item input:checked").each(function(i) {
        if($(this).val()) {
          if(value) {
            value += "|";
          }
          value += $(this).val();
        }
      });
      $("#" + idHidden).val(value);
    });
  };

  BibdkSearchControls.hideSearchControls = function(context) {
    if(Drupal.settings.ting_openformat == undefined){
      $('.works-controls', context).css({
        display: 'none'
      });

      $('.panel-left', context).css({
        display: 'none'
      })
    }
  };

  Drupal.behaviors.bibdkSearchControlsValues = {
    attach: function(context, settings) {
      BibdkSearchControls.setCheckboxes();
      BibdkSearchControls.hideSearchControls(context);
    }
  };
}(jQuery));

