<?php if ( !empty($RSlibrarySubheader) ) { ?>
  <h2 class="subheader"><?php print $RSlibrarySubheader; ?></h2>
<?php } ?>

<?php if ( !empty($branchId) ) { ?>
<div id="<?php print $branchId ?>" class="localisation-agency">
<?php if ( $branchName != $agencyName ) { ?>
  <p class="branchName"><?php print $branchName; ?></p>
<?php } ?>
  <p class="agencyName"><?php print $agencyName; ?></p>
  <p class="postalCode"><?php print $postalCode; ?></p>
  <p class="city"><?php print $city; ?></p>
<?php if ( !empty($email) ) { ?>
  <p class="email"><?php print $email; ?></p>
<?php } ?>
  <?php echo drupal_render($lookupUrl); ?>
  <p class="note"><?php print $note; ?></p>
  <p class="note"><?php print $error; ?></p>
</div>
<?php } ?>
