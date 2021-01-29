<div class="library-details text clearfix">
  <!-- first column -->
  <div class="library-details-column-1">
    <?php if (isset($address)) : ?>
      <p class="subheader">
        <strong><?php print t('ting_agency_address'); ?></strong>
      </p>
      <p class="address"><?php print $address; ?></p>
    <?php endif; ?>
    <?php if (isset($pickupallowed) && $pickupallowed !== '1') : ?>
      <p class="pickupallowed"><?php print $pickupallowed; ?></p>
    <?php endif; ?>
    <?php if (isset($contact)) : ?>
      <p class="subheader">
        <strong><?php print t('ting_agency_contact'); ?></strong>
      </p>
      <p class="contact"><?php print $contact; ?></p>
    <?php endif; ?>
    <?php if (isset($more)) : ?>
      <?php print drupal_render($more); ?>
    <?php endif; ?>
  </div>
  <!-- first column -->
  <!-- second column -->
  <div class="library-details-column-2">
    <?php if ($openingHours != 'bibdk_favourite_no_opening_hours') { ?>
      <p class="subheader">
        <strong><?php print t('ting_agency_opening_hours'); ?></strong></p>
      <p class="openinghours"><?php print $openingHours; ?></p>
    <?php } ?>
    <?php if (isset($tools)) : ?>
      <p class="subheader">
        <strong><?php print t('ting_agency_tools'); ?></strong>
      </p>
      <?php print drupal_render($tools); ?>
    <?php endif; ?>
  </div>
  <!-- second column -->
</div>
