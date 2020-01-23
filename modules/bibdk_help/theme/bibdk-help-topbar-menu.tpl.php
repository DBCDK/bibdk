<?php
/**
 * @file
 * Template file for bibdk_help_topbar_menu
 */
?>
<ul id="user-help-topbar-menu" class="menu nav--horizontal">
<?php foreach ($links as $link) { ?>
  <li>
    <?php print l($link['title'], str_replace('node/','overlay/help/',$link['href']), $link); ?>
  </li>
<?php } ?>
</ul>
