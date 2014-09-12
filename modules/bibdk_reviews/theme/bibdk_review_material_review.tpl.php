<div class='bibdk-review' >
  <?php foreach($sections as $section) : ?>
  <div class='section'>
    <h6>
      <?php print $section['title']; ?>
    </h6>
    <p>
      <?php print $section['para']; ?>
    </p>
  </div>
  <?php endforeach; ?>
    <div class='type'>
      <?php print $titles; ?>
    </div>
    <div class='author'>
      <?php print $authors; ?>
    </div>
  </div>
</div>
