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

<p>
  <span class="alert <?php print $alert_class;?>" <?php print $title_attr;?>></span>
  <span><?php print $date;?></span>
</p>

<?php
if ( $renewable ) {
  print '<p>' . $renewable . '</p>';
}
?>
