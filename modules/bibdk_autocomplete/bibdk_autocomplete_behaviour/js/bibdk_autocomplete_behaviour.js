(function ($) {
 
  var BibdkAutocompleteBehavior = {};
  BibdkAutocompleteBehavior.InputFields = {};
  BibdkAutocompleteBehavior.InputFields.fields = [];

  /**
   * Trigger Bibdk_behaviors AJAX call on form submit
   */
  Drupal.behaviors.bibdk_autocomplete_behavior__search_form_submit = {
    attach: function (context, settings) {
      $('#search-block-form').submit(function( event ) {
        alert( "Handler for .submit() called." );
        event.preventDefault();
      });
    }
  };

  /**
   * Register all autocomplete fields in search block form
   */
  Drupal.behaviors.bibdk_autocomplete_behavior__update_fields = {
    attach: function (context, settings) {
      $('#search-block-form', context).find('input.autocomplete').once('register-autocomplete-fields', function (context) {
        BibdkAutocompleteBehavior.InputFields.push(this);
      });
      console.log(BibdkAutocompleteBehavior.InputFields);
    }
  };
  
  /**
   * Register all autocomplete list items
   */
  Drupal.behaviors.bibdk_autocomplete_behavior__register_autocomplete_items = {
    // BibdkAutocompleteBehavior.InputFields.push(this);
    attach: function (context, settings) {
      $('#autocomplete li.selected', context).click(function () {
        alert($(this).value);
      });
    }
  };

  /**
   *  An input field object
   *
   * @param elem
   */
  BibdkAutocompleteBehavior.InputField = function (elem) {
    this.id = elem.id;
    this.inputField = '#' + this.id.substr(0, this.id.length - 13);
    var uuids = BibdkAutocompleteBehavior.InputFields.splitUrl(elem.value);
    this.inputUuid = uuids[0];
    this.pageUuid = uuids[1];
  };

  /**
   * Push an inputfield on fields array
   *
   * @param elem
   */
  BibdkAutocompleteBehavior.InputFields.push = function (elem) {
    this.fields[elem.id] = new BibdkAutocompleteBehavior.InputField(elem);
  };

  /**
   * Split autocomplete url and find the filter values
   *
   * @param url
   * @returns {*[]}
   */
  BibdkAutocompleteBehavior.InputFields.splitUrl = function (url) {
    var parts = url.split("/");
    var length = parts.length;
    // last is v_uuid
    var v_uuid = parts[length - 1];
    // second to last is p_uuid
    var p_uuid = parts[length - 2];
    return [v_uuid, p_uuid];
  };

  /**
   * Fills the suggestion popup with any matches received.
   * Overwrite found to add behaviour log.
   *  copied from misc/autocomplete.js
   *
   * @param matches
   */
   Drupal.jsAC.prototype.found = function (matches) {
    alert('bas');
    // If no value in the textfield, do not show the popup.
    if (!this.input.value.length) {
      return false;
    }

    // Prepare matches.
    var ul = $('<ul></ul>');
    var ac = this;
    for (key in matches) {
      $('<li></li>')
        .html($('<div></div>').html(matches[key]))
        .mousedown(function () { ac.hidePopup(this); })
        .mouseover(function () { ac.highlight(this); })
        .mouseout(function () { ac.unhighlight(this); })
        .data('autocompleteValue', key)
        .appendTo(ul);
    }
    
    // Show popup with matches, if any.
    if (this.popup) {
      if (ul.children().length) {
        $(this.popup).empty().append(ul).show().click(function () {
          alert('foo');
        });
        $(this.ariaLive).html(Drupal.t('Autocomplete popup'));
        alert('bar');
      }
      else {
        $(this.popup).css({ visibility: 'hidden' });
        this.hidePopup();
      }
    }
  };

})(jQuery);