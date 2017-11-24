(function ($) {
  var bibdk_heimdal = {};

  /**
   * Do ajax to get write email form
   * @param modal
   */
  bibdk_heimdal.getEmail = function (modal) {
    var url = Drupal.settings.basePath + Drupal.settings.pathPrefix + 'bibdk_modal/heimdal/email';
    var request = $.ajax({
      url: url,
      type: 'GET',
      success: function (data) {
        modal.html(data);
        modal.foundation('reveal', 'open');
      },
      error: function (data) {
        var options = [];
        options['context'] = 'heimdal';
        alert(Drupal.t('Something went wrong, please try again', [], options));
      }
    });
  };

  /**
   * Get bibdk-modal, set attributes to make it stay open
   * and pass it on for further handling
   */
  bibdk_heimdal.openModal = function () {
    // get the modal
    var modal = $('#bibdk-modal');
    // make modal stay open
    modal.attr("data-options", "close_on_background_click:false;close_on_esc:false");
    bibdk_heimdal.getEmail(modal);
  };


  Drupal.behaviors.bibdk_heimdal = {
    attach: function (context, settings) {
      $('#bibdk-modal',context).once('bibdk-heimdal-modal', function(){
        bibdk_heimdal.openModal();
      })
    }
  };
}(jQuery));


