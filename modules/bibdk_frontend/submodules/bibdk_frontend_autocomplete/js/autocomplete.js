(function($){
  /**
   * Scroll input field to top to make room for autocomplete suggestions
   */

  /**
   * overrides for drupal autocomplete w/o ajax
   */
  if (Drupal.jsAC){
    Drupal.jsAC.prototype.found = found;
    Drupal.autocompleteSubmit = autocompleteSubmit;
  }
  Drupal.behaviors.bibdk_autocomplete = {
    attach: function(context, settings){
      if (Drupal.jsAC){
        Drupal.jsAC.prototype.found = found;
        Drupal.autocompleteSubmit = autocompleteSubmit;
      }
    }
  }

  /**
   * overrides Drupal.jsAC.prototype.found
   * @see misc/autocomplete.js
   *
   * Fixes autocomplete for touch devices using click instead of mousedown
   */
  function found(matches){
    // If no value in the textfield, do not show the popup.
    if (!this.input.value.length){
      return false;
    }

    // Prepare matches.
    var ul = $('<ul></ul>');
    var ac = this;
    var elemId = this.input.id + '-autocomplete';
    // BibdkAutocompleteBehavior.InputFields.resetSuggestions(elemId);
    for (key in matches) {
      // BibdkAutocompleteBehavior.InputFields.addSuggestion(elemId, matches[key]);
      // BibdkAutocompleteBehavior.register_autocomplete_items(this, matches[key]);
      $('<li></li>')
        .html($('<div></div>').html(matches[key]))
        .click(function(){
          ac.select(this);
        })
        .mouseover(function(){
          ac.highlight(this);
        })
        .mouseout(function(){
          ac.unhighlight(this);
        })
        .data('autocompleteValue', key)
        .appendTo(ul);
    }

    // Show popup with matches, if any.
    if (this.popup){
      if (ul.children().length){
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
   * overrides Drupal.autocompleteSubmit
   * @see misc/autocomplete.js
   *
   * We want to submit on enter
   */
  function autocompleteSubmit(){
    $('#autocomplete').each(function(){
      this.owner.hidePopup();
    });
    return true;
  };

})(jQuery);

