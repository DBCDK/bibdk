<div id="print">
          <?php if (!empty($title)): ?>
            <h1 id="title"><?php print $title; ?></h1>
          <?php endif; ?>
          <?php print render($page['content']); ?>
</div>
<!-- #popup -->
