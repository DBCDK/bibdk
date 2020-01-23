<?php
/**
 * @file
 * Bibliotek.dk theme implementation to display a pop-up help page.
 *
 * Copy this file to the active theme's '/templates' folder
 */
?>
  <div id="wrap-right">
    <div id="wrap-left">

      <div<?php print $attributes; ?>>
        <?php if (isset($page['header'])) : ?>
          <?php print render($page['header']['header']['branding']); ?>
        <?php endif; ?>

        <?php if (isset($page['content'])) : ?>
          <?php print render($page['content']); ?>
        <?php endif; ?>

        <?php if (isset($page['footer'])) : ?>
          <?php print render($page['footer']); ?>
        <?php endif; ?>

      </div>

    </div>
  </div>
