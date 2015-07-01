<div class="bibdk-modal-content">
  <div class="checkbox-elements" ?>
    <?php foreach ($element['#options'] as $name => $link): ?>
      <div class="checkbox-element">
        <p class="checkbox-element-label">
          <label class="option" for="edit-<?php print $element['#facet_key']; ?>-<?php print $name; ?>">
            <?php print $link; ?>
          </label>
        </p>

        <?php $selected = (isset($element['#selected_facets'][$name]) && $element['#selected_facets'][$name] == $element['#facet_name']); ?>
        <?php $deselected = (isset($element['#deselected_facets'][$name]) && $element['#deselected_facets'][$name] == $element['#facet_name']); ?>

        <p class="checkbox-element-select">
          <input id="<?php print $element['#facet_key']; ?>-<?php print $name; ?>"
                 class="form-checkbox form-item" type="checkbox" <?php ($selected) ? print 'checked' : print '';?> value=1
                 name="<?php print $element['#facet_key'] . '[' . $name . '][]';?>">
        </p>

        <p class="checkbox-element-deselect">
          <input id="<?php print $element['#facet_key']; ?>-<?php print $name; ?>"
                 class="form-checkbox form-item" type="checkbox" <?php ($deselected) ? print 'checked' : print '';?> value=0
                 name="<?php print $element['#facet_key'] . '[' . $name . '][]';?>" data-deselect="true"">
        </p>

      </div>

    <?php endforeach; ?>

  </div>
</div>
