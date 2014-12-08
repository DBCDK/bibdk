<?php
/**
 * TODO needs refactoring
 * @file
 * Theme implementation for bibliotek.dk search controls: Select.
 */
$selected = $selected_label = '';
$options = array();
foreach ( $variables['form'] as $key => $elem ) {
  if ( !empty($elem['#options']) && $elem['#type'] == 'select' ) {
    $selected = ( !empty($elem['#default_value']) ) ? $elem['#default_value'] : '';
    $accesskey = ( !empty($elem['#attributes']['accesskey'][0]) ) ? ' accesskey="' . $elem['#attributes']['accesskey'][0] . '"' : '';
    $tabindex = ( !empty($elem['#attributes']['tabindex'][0]) ) ? ' tabindex="' . $elem['#attributes']['tabindex'][0] . '"': '';
    $options  = $elem['#options'];
    $selected_label = ( !empty($options[$selected]) ) ? $options[$selected] : '';
    $name = $key;
  }
}

$action[0] = '';
if ( !empty($variables['form']['#action']) ) {
  $action = explode('?', $variables['form']['#action']);
  if (count($action) > 1){
    parse_str($action[1], $query);
    if ( isset($query['page']) ) {
      unset($query['page']);
    }
  }
}
?>

<a class="works-control works-sort dropdown-toggle" href="#">
  <span class="selected-text"<?php print $tabindex; ?><?php print $accesskey; ?>><?php print t($selected_label); ?></span>
</a>

<ul class="dropdown-menu dropdown-leftalign hidden">
<?php foreach ( $options as $value => $label ) { ?>
  <?php $query[$name] = $value; ?>
  <li>
    <a id="<?php print "selid_search_controls_$value"; ?>" class="<?php print ( $value == $selected ) ? 'current' : ''; ?>" href="<?php echo $action[0] . '?' . http_build_query($query, '', '&amp;'); ?>" data-value="<?php print $value; ?>"><?php print $label; ?></a>
  </li>
<?php } ?>
</ul>
