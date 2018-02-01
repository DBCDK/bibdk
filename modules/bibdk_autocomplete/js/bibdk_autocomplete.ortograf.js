(function ($) {

  /**
   * Add customSearch method to Drupal.ADCB
   *  @see misc/autocomplete.js
   *
   * @param input
   * @param searchString
   */
  Drupal.ACDB.prototype.customSearch = function (input, searchString) {
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
    this.popup = $('<div id="autocomplete" data-owner="' + $input.attr('id') + '"></div>')[0];
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

})(jQuery);