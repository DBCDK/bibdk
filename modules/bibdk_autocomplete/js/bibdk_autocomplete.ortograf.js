(function ($) {
 
  var BibdkAutocompleteBehavior = {};
  BibdkAutocompleteBehavior.fields = {};
  
  /**
   * Trigger Bibdk_behaviors AJAX call on form submit
   */
  Drupal.behaviors.bibdk_autocomplete_behavior__search_form_submit = {
    attach: function (context, settings) {
      $('#search-block-form', context).bind('submit',function(event) {
        $('.form-autocomplete', context).each(function(index) {
          var elemId = $(this).attr('id') + '-autocomplete';
          var elemValue = $(this).attr('value');
          BibdkAutocompleteBehavior.submitValues(elemId, elemValue);
        });
        var url = Drupal.settings.basePath + Drupal.settings.pathPrefix + 'bibdk/behaviour/autocomplete/';
        var request = $.ajax({
          url: url,
          method: "POST",
          data: { ortograf: BibdkAutocompleteBehavior.fields },
          dataType: 'json',
          async: false, // Or the call is not sent.
        });
        event.preventDefault();
      });
    }
  };

  /**
   * Register all autocomplete fields in search block form
   */
  Drupal.behaviors.bibdk_autocomplete_behavior__register_fields = {
    attach: function (context, settings) {
      $('#search-block-form', context).find('input.autocomplete').once('register-autocomplete-fields', function (context) {
        BibdkAutocompleteBehavior.push(this);
      });
    }
  };
  
  /**
   * Get BibdkAutocompleteBehavior fields.
   */
  BibdkAutocompleteBehavior.getFields = function () {
    return this.fields;
  };

  /**
   * Push an item on the suggestions array
   *
   * @param elemId
   * @param item
   */
  BibdkAutocompleteBehavior.addSuggestion = function (elemId, item) {
    this.fields[elemId].suggestions.push(item);
  };

  /**
   * Reset Suggestions
   *
   * @param elemId
   */
  BibdkAutocompleteBehavior.resetSuggestions = function (elemId) {
    this.fields[elemId].suggestions.length = 0;
  };

  /**
   * Register selected suggestion
   *
   * @param elemId
   * @param counter
   */
  BibdkAutocompleteBehavior.selectedSuggestion = function (elemId, counter) {
    this.fields[elemId].selected = counter;
  };

  /**
   * Register suggestion query.
   *
   * @param elemId
   * @param elemValue
   */
  BibdkAutocompleteBehavior.addQuery = function (elemId, elemValue) {
    this.fields[elemId].query = elemValue;
  };

  /**
   *  An input field object
   *
   * @param elem
   */
  BibdkAutocompleteBehavior.InputField = function (elem) {
    this.id = elem.id;
    var uuids = BibdkAutocompleteBehavior.splitUrl(elem.value);
    this.inputUuid = uuids[0];
    this.pageUuid = uuids[1];
    this.suggestions = [];
  };

  /**
   * Push an inputfield on fields array
   *
   * @param elem
   */
  BibdkAutocompleteBehavior.push = function (elem) {
    this.fields[elem.id] = new BibdkAutocompleteBehavior.InputField(elem);
  };

  /**
   * Update fields with submitted string.
   *
   * @param elemId
   * @param elemValue
   */
  BibdkAutocompleteBehavior.submitValues = function (elemId, elemValue) {
    this.fields[elemId].submitValue = elemValue;
  };

  /**
   * Split autocomplete url and find the filter values
   *
   * @param url
   * @returns {*[]}
   */
  BibdkAutocompleteBehavior.splitUrl = function (url) {
    var parts = url.split("/");
    var length = parts.length;
    // last is v_uuid
    var v_uuid = parts[length - 1];
    // second to last is p_uuid
    var p_uuid = parts[length - 2];
    return [v_uuid, p_uuid];
  };

  /**
   * overrides Drupal.jsAC.prototype.found
   * overrides bibdk_frontend_autocomplete Drupal.jsAC.prototype.found
   * @see misc/autocomplete.js
   * @see modules/bibdk_frontend/submodules/bibdk_frontend_autocomplete/autocomplete.js
   *
   * Add behaviour logging for autocomplete.
   */
  function found(matches) {
    // If no value in the textfield, do not show the popup.
    if (!this.input.value.length){
      return false;
    }

    // Prepare matches.
    var ul = $('<ul></ul>');
    var ac = this;
    var counter = 0;
    var elemId = this.input.id + '-autocomplete';
    var elemValue = this.input.value;
    BibdkAutocompleteBehavior.resetSuggestions(elemId);
    BibdkAutocompleteBehavior.addQuery(elemId, elemValue);
    for (key in matches) {
      BibdkAutocompleteBehavior.addSuggestion(elemId, matches[key]);
      $('<li></li>')
        .html($('<div></div>').html(matches[key]))
        .mouseover(function() {
          ac.highlight(this);
        })
        .mouseout(function() {
          ac.unhighlight(this);
        })
        .data('autocompleteValue', key)
        .appendTo(ul)
        .on( "click", { counter: counter }, function( event ) {
          BibdkAutocompleteBehavior.selectedSuggestion(elemId, event.data.counter);
          ac.select(this);
        })
        counter++;
    }

    // Show popup with matches, if any.
    if (this.popup) {
      if (ul.children().length) {
        $(this.popup).empty().append(ul).show();
        $(this.ariaLive).html(Drupal.t('Autocomplete popup'));
      }
      else {
        $(this.popup).css({ visibility: 'hidden' });
        this.hidePopup();
      }
    }
  };

  /** 
   * overrides for drupal autocomplete w/o ajax
   */
  if (Drupal.jsAC){
    Drupal.jsAC.prototype.found = found;
  }
  Drupal.behaviors.bibdk_autocomplete = {
    attach: function(context, settings) {
      if (Drupal.jsAC) {
        Drupal.jsAC.prototype.found = found;
      }
    }
  }

})(jQuery);