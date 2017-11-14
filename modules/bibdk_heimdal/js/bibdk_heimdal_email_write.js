(function ($) {
  var bibdk_heimdal = {};

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

  bibdk_heimdal.openModal = function () {
    // get the modal
    var modal = $('#bibdk-modal');
    // make modal stay open
    modal.attr("data-options", "close_on_background_click:false;close_on_esc:false");
    bibdk_heimdal.getEmail(modal);
  };


  Drupal.behaviors.bibdk_heimdal = {
    attach: function (context, settings) {
      $('#bibdk-modal',context).once('fisk', function(){
        bibdk_heimdal.openModal();
      })
    }
  };
}(jQuery));


