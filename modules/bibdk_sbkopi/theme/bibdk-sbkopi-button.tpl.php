<?php
/**
 * @file
 * Template for sb button with dropdown helptext
 *
 * theme variables
 * $link render array with link
 * $helptext string with helptext
 * $pid uniqe id for dropdown
 */
?>
<div class="sbkopi-button-wrapper">
  <?php echo drupal_render($link); ?>
  <a data-dropdown="<?php print $pid; ?>" class="dropdown-link" href="#"
     aria-label="<?php print t('Help', array(), array('context' => 'bibdk_theme')); ?>"
     role="button" title="<?php print strip_tags($helptext); ?>">?</a>

  <div id="<?php print $pid; ?>" class="bibdk-dropdown" data-dropdown-content aria-hidden="true" tabindex="-1">
    <p class="user-msg">
      <?php print $helptext; ?>
    </p>
  </div>
</div>
