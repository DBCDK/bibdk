(function ($) {
  var BibdkAutocomplete = {};
  BibdkAutocomplete.InputFields = {};
  BibdkAutocomplete.InputFields.fields = [];
  /**
   * Register all autocomplete fields in search block form
   */
  Drupal.behaviors.bibdk_autocomplete_update_fields = {
    attach: function (context, settings) {
      $('#search-block-form').find('input.autocomplete').once(function (context) {
        var $input = $('#' + this.id.substr(0, this.id.length - 13));
        BibdkAutocomplete.InputFields.push($input.attr('id'));
      });
    }
  };

  /**
   * Add customSearch method to Drupal.ADCB
   *  @see misc/autocomplete.js
   *
   * @param input
   * @param searchString
   */
  Drupal.ACDB.prototype.customSearch = function (input, searchString) {
    var fields = BibdkAutocomplete.InputFields.fields;
    for (var key in fields) {
      var obj = fields[key];
      if (obj.id != input.input.id) {
        if ($('#' + obj.id).val().length > 0) {
          var filter = obj.filter;
          searchString += '::::' + obj.filter + '$$' + $('#' + obj.id).val();
        }
      }
    }
    return this.search(searchString);
  };

  /**
   * Overwrite populatePopup to use customsearch method.
   *  copied from misc/autocomplete.js
   */
  Drupal.jsAC.prototype.populatePopup = function () {
    var $input = $(this.input);
    var position = $input.position();
    // Show popup.
    if (this.popup) {
      $(this.popup).remove();
    }
    this.selected = false;
    this.popup = $('<div id="autocomplete"></div>')[0];
    this.popup.owner = this;
    $(this.popup).css({
      top: parseInt(position.top + this.input.offsetHeight, 10) + 'px',
      left: parseInt(position.left, 10) + 'px',
      width: $input.innerWidth() + 'px',
      display: 'none'
    });
    $input.before(this.popup);

    // Do search.
    this.db.owner = this;
    // call custom search function to change search string
    this.db.customSearch(this, this.input.value);
  };


  /**
   *  An input field object
   */
  BibdkAutocomplete.InputField = function (id) {
    this.id = id;
    // the original autocomplete path
    this.original_url = $('#' + id + '-autocomplete').val();
    // vars describing the filter
    var uuids = BibdkAutocomplete.InputFields.splitUrl(this.original_url);
    this.filter = uuids[0] + "$$" + uuids[1];
  };

  /**
   * Push an inputfield on fields array
   *
   * @param field_id
   */
  BibdkAutocomplete.InputFields.push = function (field_id) {
    this.fields[field_id] = new BibdkAutocomplete.InputField(field_id);
  };

  /**
   * Get values for the filter
   * @param id
   * @param $input
   */
  BibdkAutocomplete.InputFields.setFilter = function (id, $input) {
    var url = BibdkAutocomplete.InputFields.fields[$input.attr('id')].original_url;
    var uuids = BibdkAutocomplete.InputFields.splitUrl(url);
    var key = uuids[0] + "$$" + uuids[1];
    this.fields[id].filter[key] = $input.val();
  };

  /**
   * Split autocomplete url and find the filter values
   *
   * @param url
   * @returns {*[]}
   */
  BibdkAutocomplete.InputFields.splitUrl = function (url) {
    var parts = url.split("/");
    var length = parts.length;
    // last is v_uuid
    var v_uuid = parts[length - 1];
    // second to last is p_uuid
    var p_uuid = parts[length - 2];
    return [v_uuid, p_uuid];
  };

})(jQuery);