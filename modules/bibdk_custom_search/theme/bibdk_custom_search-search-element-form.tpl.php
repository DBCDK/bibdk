<?php
/**
 * @file
 * Theme implementation for bib.dk custom search elements.
 */
?>
<div class='fieldset-legend'>
  <label for="<?php print $element_id; ?>"><?php print $title; ?></label>
</div>

<div class="custom-search--helptext-container">

  <p class="helptext" title="<?php print strip_tags($help); ?>">
    <a data-dropdown="custom-search-elements-help-<?php print $element_id; ?>"
       aria-controls="custom-search-elements-help-<?php print $element_id; ?>"
       aria-expanded="false"
       aria-label="<?php print t('Help', array(), array('context' => 'bibdk_theme')); ?>"
       role="button">
      <svg class="svg-icon svg-question">
        <use xlink:href="#svg-question" xmlns:xlink="http://www.w3.org/1999/xlink">
      </svg>
    </a>
  </p>
  <div id="custom-search-elements-help-<?php print $element_id; ?>"
       data-dropdown-content
       class="f-dropdown tiny"
       aria-hidden="true"
       tabindex="-1">
    <p class="helptext-content">
      <?php print $help; ?>
    </p>
  </div>

</div>

<div class="bibdk-custom-search-element">
  <?php print drupal_render_children($form); ?>
</div>