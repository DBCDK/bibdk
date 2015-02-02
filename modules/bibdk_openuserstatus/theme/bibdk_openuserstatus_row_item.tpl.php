<p class="userstatus-row-item">
  <?php if (!empty($title)): ?>
    <span class="userstatus-row-item--title"><?php print $title; ?></span>
  <?php endif; ?>

  <?php if (!empty($author)): ?>
    <span class="userstatus-row-item--additional"><?php print $author; ?></span>
  <?php endif; ?>

  <?php if (!empty($library)): ?>
    <span class="userstatus-row-item--library-name"><?php print $library; ?></span>
  <?php endif; ?>
</p>
