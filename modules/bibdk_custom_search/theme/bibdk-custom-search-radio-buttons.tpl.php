<?php

/*
See: function template_preprocess_bibdk_custom_search_radio_buttons() in template.php
  $variables['form'][$key]['#title'] = '<span data-child="' . drupal_html_id($key) . '" class="toggle-subgroup"> + </span>' . $key;
  $variables['form'][$first]['#prefix'] = '<fieldset id="edit-term-' . $key . '" class="sub-elements form-wrapper" data-child="' . $key . '" style="display: block;">';
  $variables['form'][$last]['#suffix'] = '</fieldset>';
*/

echo drupal_render_children($form);

?>
