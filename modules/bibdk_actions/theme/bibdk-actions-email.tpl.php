<?php /* Outlook autoremoves linebreaks. Workaround: add tab at end of line */ ?>
<?php foreach ($strings as $string): ?>
<?php print $string . "\t\r\n"; ?>
<?php endforeach; ?>
   <?php print "\r\n"; ?>
