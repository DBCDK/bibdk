<?php
/**
 * @file
 * Default theme implementation for displaying captcha refresh and audio button.
 */
?>


<div id="bibdkcaptcha-controls">
  <?php print $captcha; ?>
  <br />
  <button aria-label="<?php print t('New audio captcha', array('context' => 'bibdkcaptcha'));?>" id="bibdkcaptcha-controls-refreshbtn" type="button"><img alt="<?php print t('New audio captcha', array('context' => 'bibdkcaptcha'));?>" title="<?php print t('New audio captcha', array('context' => 'bibdkcaptcha'));?>" src="<?php print $module_path; ?>/graphics/refresh.gif" /></button>
  <button aria-label="<?php print t('Play audio captcha', array('context' => 'bibdkcaptcha'));?>" id="bibdkcaptcha-controls-audiobtn" type="button"><img alt="<?php print t('Play audio captcha', array('context' => 'bibdkcaptcha'));?>" title="<?php print t('Play audio captcha', array('context' => 'bibdkcaptcha'));?>" src="<?php print $module_path; ?>/graphics/audio_icon.gif" /></button>
  <audio id="bibdkcaptcha-controls-playcaptcha-embed" autoplay="true" autostart="true" hidden="true"></audio>
</div>
