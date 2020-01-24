(function($) {
  function worktabsClick(item) {
    var id = item[0].getAttribute('href');
    $(id + ' .tab-content').bind('DOMNodeInserted', function() {
      var list = $(id + ' .tab-content .worktabs-no-content');
      list.map(function(i, e) {
        var p = $(e).parents().filter('.tab-item');
        var txt = e.getAttribute('data-button-txt');
        if(txt) {
          p.find('.toggle-worktab-content .toggle-text').map(function(j, t) {
            t.innerHTML = txt;
          });
        }
      });
    });
  }

  Drupal.behaviors.worktabs = {
    attach: function(context) {
      $('.worktabs .tabs-nav a', context).once().click(function(e) {
        e.preventDefault();
        worktabsClick($(this));
      });
    }
  };
}(jQuery));
