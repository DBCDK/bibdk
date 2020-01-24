<?php

/*
 * We use $content['help_url'] instead of $node_url, in order to make
 * the links in the bibdk_help_list viewmode point to our content_type.
 *
 * Copy this file to the active theme's '/templates' folder
 */
?>

<div class="<?php print implode(' ', $classes_array); ?>">
  <?php print render($title_prefix); ?>
    <h2<?php print $title_attributes; ?>>
      <?php print $title; ?>
    </h2>
  <?php print render($title_suffix); ?>

  <div class="content clearfix"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      hide($content['newsroom_field_image']);
      print render($content);
    ?>
  </div>

  <?php
    // Remove the "Add new comment" link on the teaser page or if the comment
    // form is being displayed on the same page.
    if ($teaser || !empty($content['comments']['comment_form'])) {
      unset($content['links']['comment']['#links']['comment-add']);
    }
    // Only display the wrapper div if there are links.
    $links = render($content['links']);
    if ($links):
  ?>
    <div class="link-wrapper">
      <?php print $links; ?>
    </div>
  <?php endif; ?>

  <?php print render($content['comments']); ?>

</div>
