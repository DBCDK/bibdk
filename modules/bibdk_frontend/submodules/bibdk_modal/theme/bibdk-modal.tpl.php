<?php
 /**
  * @file
  * Theme file for the basic bibdkmodal
  *
  * Available variables:
  *   - $title: The of the modal
  *   - $content: The rendered content that should be displayed within the modal.
  */
?>

<div id="bibdk-modal-form">
  <div class="bibdk-modal-header">
    <span class="bibdk-modal-title"><?php print $title; ?></span>
    <a class="close-reveal-modal">&#215;</a>
  </div>
  <div class="bibdk-modal-content">
    <?php print $content; ?>
  </div>
</div>