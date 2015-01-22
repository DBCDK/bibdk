<?php
if ($overdue) {
  $date_overdue = t('Delivery_date_overdue', array(), array('context' => 'bibdk_openuserstatus'));
  $alert_class = 'red-alert';
  $title_attr = 'title="' . $date_overdue . '"';
}
else {
  $alert_class = 'no-alert';
  $title_attr = '';
}
?>

<span><?php print $date; ?></span>
<span class="<?php print $alert_class; ?>" <?php print $title_attr; ?>>
   <?php if ($renewable) : ?>
     <?php print '<p>' . $renewable . '</p>'; ?>
   <?php endif; ?>
  </span>
