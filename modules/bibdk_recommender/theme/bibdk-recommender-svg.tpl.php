<?php print drupal_render($variables['title_creator']['material_biblio']) ?>
<span class="svg-icon">
    <svg class="media-<?php print $material_type; ?>" title="" alt="">
      <use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="#svg-media-<?php var_dump( $material_type ); ?>" ></use>
    </svg>
  </span>
