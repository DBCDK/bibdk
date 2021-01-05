<div class='bibdk-review' >
  <?php print $reusednote; ?>
  <?php foreach($sections as $section) : ?>
  <div class='section'>
    <h6>
      <strong>
        <?php print $section['docbook:title']; ?>
      </strong>
    </h6>
    <p>
      <?php print $section['docbook:para']; ?>
    </p>
  </div>
  <?php endforeach; ?>
    <br/>
    <div class='type'>
      <?php print $titles; ?>
    </div>
    <div class='author'>
      <?php print $authors; ?>
    </div>
  </div>
</div>
