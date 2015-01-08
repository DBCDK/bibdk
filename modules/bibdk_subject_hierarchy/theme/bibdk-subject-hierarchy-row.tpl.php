
<div class="subjects-row clearfix">

  <?php foreach ($items as $index => $item): ?>
    <div class="<?php print $item['wrapper_classes']; ?>">
      <p>
        <span class="header">
          <a href="<?php print $item['url']; ?>" id="<?php print $item['label_id']; ?>" class="use-ajax" >
          <?php print $item['ord']; ?>
          </a>
        </span>

        <span class="note">
          <a href="<?php print $item['url']; ?>" id="<?php print $item['note_id']; ?>" class="use-ajax" >
          <?php print $item['note']; ?>
          </a>
        </span>
      </p>
    </div>
  <?php endforeach; ?>

  <?php print "<div class='subjects-sublist-wrapper row-$row' style='display: $display'>" . $visible_row . "</div>"; ?>

</div>