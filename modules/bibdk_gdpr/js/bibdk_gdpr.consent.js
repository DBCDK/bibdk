/**
 * @file
 * JS for creating modal for giving consent.
 */
(function ($) {

  $(document).ready(function() {
    if ($('#bibdk-gdpr-login-modal').length) {
      var modal = $("#bibdk-modal");
      modal.html($('#bibdk-gdpr-login-modal').html());
      modal.foundation('reveal', 'open');
      // make modal stay open
      modal.attr("data-options", "close_on_background_click:false;close_on_esc:false");
      modal.find('.message').hide();
      modal.find('.see-more').click(function(event) {
        $(this).toggleClass('open');
        if ($(this).hasClass('open')) {
          $(this).text(Drupal.t('See less', {}, {context: 'bibdk_gdpr'}));
          modal.find('.message').slideDown();
        }
        else {
          $(this).text(Drupal.t('See more', {}, {context: 'bibdk_gdpr'}));
          modal.find('.message').slideUp();
        }
      });
      modal.find('button').click(function() {
        if (modal.find('input:checked').length) {
          $.post(Drupal.settings.basePath + 'bibdk-gdpr-consent', {consent: 1});
          modal.foundation('reveal', 'close');
        }
        return false;
      });
    }
  });

}(jQuery));

