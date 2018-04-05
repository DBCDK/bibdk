<?php

/**
 * @file
 * Theme implementation for bibdk_mypage.
 */
?>

<h1 class="gdpr-header"><?php print $header; ?></h1>

<div class="gdpr-intro"><?php print $intro; ?></div>

<?php print drupal_render($values); ?>

<div class="gdpr-extro"><?php print $extro; ?></div>

<div class="gdpr-button">
  <button type="button" id="button-gdpr-print" class="btn"><?php print $print_button_value; ?></button> 
</div>