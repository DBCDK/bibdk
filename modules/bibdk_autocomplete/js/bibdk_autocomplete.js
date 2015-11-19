(function ($) {
  BibdkAutocomplete = {};
  BibdkAutocomplete.InputFields = {};
  BibdkAutocomplete.InputFields.fields = [];
  /**
   * Attaches the autocomplete behavior to all required fields.
   */
  Drupal.behaviors.bibdk_autocomplete_update_fields = {
    attach: function (context, settings) {
      $('#search-block-form').find('input.autocomplete').once(function (context) {
        var $input = $('#' + this.id.substr(0, this.id.length - 13));
        BibdkAutocomplete.InputFields.push($input.attr('id'));
        new BibdkAutocomplete.updateField($input);
      });
    }
  };

  // an input field object
  BibdkAutocomplete.InputField = function (id) {
    this.id = id;
    // the original autocomplete path
    this.original_url = $('#' + id + '-autocomplete').val();
    this.filter = [];
  };

  // a field updater object
  BibdkAutocomplete.updateField = function ($input) {
    // bind input to autocompleteSelect (@see misc/autocomplete.js::Drupal.jsAC.prototype.select
    $input.on('autocompleteSelect', function (node) {
      BibdkAutocomplete.DoChange($(this));
    });
  };

  BibdkAutocomplete.InputFields.push = function (field_id) {
    this.fields[field_id] = new BibdkAutocomplete.InputField(field_id);
  };

  BibdkAutocomplete.InputFields.getFields = function () {
    return this.fields;
  };

  BibdkAutocomplete.InputFields.getUrl = function (id) {
    var url = this.fields[id].original_url;
    var filters = this.fields[id].filter;
    for (var key in filters) {
      var value = filters[key];
      url += '::' + key + ':' + value;
    }
    //console.log(url);
    return url;
  };

  BibdkAutocomplete.InputFields.setFilter = function (id, $input) {
    var term = $input.attr('data-term');
    var filter = $input.val();
    this.fields[id].filter[term] = filter;
  };


  BibdkAutocomplete.DoChange = function ($input) {
    var fields = BibdkAutocomplete.InputFields.getFields();
    for (var key in fields) {
      var obj = fields[key];
      if (obj.id != $input.attr('id')) {
        BibdkAutocomplete.InputFields.setFilter(obj.id, $input);
        var url = BibdkAutocomplete.InputFields.getUrl(obj.id);
        // set the autocomplete url
        $('#' + obj.id + '-autocomplete').val(url);
      }
    }
  };

})(jQuery);