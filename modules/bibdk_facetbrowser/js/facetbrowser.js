(function ($) {


  /**
   * entry point for facetbrowser.
   *
   * @type {{attach: attach}}
   */
  Drupal.behaviors.tingOpenformatLoad = {
    attach: function (context) {

      if(context !== document){
        return;
      }

      console.log('FACET ATTACH');


      // check if placeholder for ajax is present
      var element = $('.bibdk_facetbrowser_facets_placeholder');
      if(element.length == 0) {
        // this is a standard pageload (no ajax)
        BibdkFacets.setAllGroupEvents(context);
        BibdkFacets.setOtherEvents();
      }
      else {
        element = $('#bibdk-facetbrowser-form');
        if (element.length < 1) {

          $('.bibdk_facetbrowser_facets_placeholder', context).ready(function () {
            var div = $('.bibdk_facetbrowser_facets_placeholder');
            // show a spinner while we are waiting for the facets
            div.html('<div class="ajax-progress ajax-progress-throbber"><div class="throbber"></div></div>');
            BibdkFacets.getFacets(context);
          });
        }
      }
    },
    detach: function(context){
      if(context !== document){
        return;
      }
      console.log('FACET DETACH');
      var groups = $('#bibdk-facetbrowser-form fieldset:visible');
      groups.each(function(){
        BibdkFacets.offGroupEvent($(this), context);
      });
    }
  };

  /**
   * Object for BibdkFacet functionality
   * @type {{}}
   */
  var BibdkFacets = {}

  /*
   * set facets
   */
  BibdkFacets.setFacets = function (facets, group, context) {
    // call for a single group of facets
    if(group !== false) {
      // hold length of old group
      var len = BibdkFacets.facetGroupLength(group);
      // replace group
      group.replaceWith(facets.markup);
      // update group element
      var new_group = $('#'+group.attr('id'));
      BibdkFacets.setGroupEvents(new_group);
      BibdkFacets.FoldFacetGroup(new_group, len, context);
      BibdkFacets.SetFilterEvent(new_group);

    }
    // call for whole facetbrowser
    else {
      $('.bibdk_facetbrowser_facets_placeholder').html(facets.markup);
      BibdkFacets.setAllGroupEvents();
    }
    // set session storage
    var key = BibdkFacets.getCacheKey(group);
    BibdkFacets.setSessionStorage(facets,key);
    // set common event
    BibdkFacets.setOtherEvents();
  };

  BibdkFacets.SetFilterEvent = function(group){
    if(typeof Drupal.bibdkModal.setLinkActions === 'function'){
      Drupal.bibdkModal.setLinkActions(group);
    }
  };

  BibdkFacets.setAllGroupEvents = function(context){
    var groups = $('#bibdk-facetbrowser-form fieldset:visible');
    groups.each(function(){
      BibdkFacets.setGroupEvents($(this),context);
      BibdkFacets.FoldFacetGroup($(this), 0, context);
      BibdkFacets.SetFilterEvent($(this));
    });
  };


  /**
   * get lenght of visible checkbox elements in facetgroup
   * @param group
   * @returns {*}
   */
  BibdkFacets.facetGroupLength = function(group){
    // this could be an updated group
    var element = $('#'+group.attr('id'));
    var len = element.find('.form-item.form-type-checkbox:visible').length;
    return len;
  };

  /**
   *
   * @param len
   *   current length of facetgroup
   * @returns int
   *   the number of terms to show
   */
  BibdkFacets.numberToShow = function(len){
    // first time load.
    if(len === 0){
      return parseInt(Drupal.settings.bibdkFacetBrowser.showCount);
    }
    // consecutive loads
    var toggle = parseInt(Drupal.settings.bibdkFacetBrowser.showCountConsecutive);
    return len + toggle;
  };

  /**
   * get facets from sessonstorage
   * @param group
   * @returns {*}
   */
  BibdkFacets.getFromSessionStorage = function (group) {
    if (!Modernizr.sessionstorage || Drupal.settings.ting_openformat.isAdmin) {
      return false;
    }

    var key = BibdkFacets.getCacheKey(group);
    var facetsObj = sessionStorage.getItem(key);
    facetsObj = JSON.parse(facetsObj);
    if (!facetsObj || !facetsObj.markup) {
      console.log('CACHE MISS');
      return false;
    }
    console.log('CACHE HIT');
    return facetsObj;
  };

  /**
   * set sessionstorage
   * @param facets
   * @param key
   */
  BibdkFacets.setSessionStorage = function (facets, key) {
    if (!Modernizr.sessionstorage) {
      console.log("sessionStorage is not supported by this browser");
      return;
    }
    try {
      sessionStorage.setItem(key, JSON.stringify(facets));
    } catch (e) {
      sessionStorage.clear();
    }
  };

  /**
   * clear sessionstorage
   */
  BibdkFacets.clearSessionStorage = function () {
    if (!Modernizr.sessionstorage) {
      console.log("sessionStorage is not supported by this browser");
      return;
    }
    sessionStorage.clear();
  };

  /**
   * Fold facet groups to show only n per group.
   */
  BibdkFacets.FoldFacetGroup = function(group, len, context) {
    // hide checkboxes in facetgroup
    var limit = parseInt(BibdkFacets.numberToShow(len));
    var count = parseInt(group.attr('data-count'));
    group.find('.form-item.form-type-checkbox').each(function(index){
      if($(this).css("visibility") == "visible") {
        if (index < limit) {
          $(this).show();
        }
        else{
          $(this).hide();
        }
      }
    });

    // first load - hide show less
    if(len === 0){
      group.find($("div[data-expand='less']")).hide();
    }
    // less facet in group than to show
    if(count < limit){
      group.find($("div[data-expand='more']")).hide();
    }
    // more facets
    if(count > limit){
      group.find($("div[data-expand='more']")).show();
    }
    // special case same number in facetgroup as to show initially
    if(len != 0 && count === parseInt(Drupal.settings.bibdkFacetBrowser.showCount)){
      group.find($("div[data-expand='more']")).hide();
      group.find($("div[data-expand='less']")).hide();
    }
    // special case exactly the number of facets as to show consecutively
    if(len != 0 && count==limit){
      group.find($("div[data-expand='more']")).hide();
    }
  };

  /**
   * set group event (show more, show less)
   * @param group
   */
  BibdkFacets.setGroupEvents = function (group,context) {
    // show more event
    group.not('#selected-terms, #deselected-terms').find($("div[data-expand='more'] span")).bind('click', function () {
      BibdkFacets.getFacetGroup(group);
    });

    // special handler for selected/deselected terms
    BibdkFacets.SetNoGroupEvents($('#selected-terms'));
    BibdkFacets.SetNoGroupEvents($('#deselected-terms'));


    // show less event
    group.find($("div[data-expand='less'] span")).on('click', function () {
      BibdkFacets.FoldFacetGroup(group, 0);
      BibdkFacets.showAndHide();
    });
  };

  BibdkFacets.SetNoGroupEvents = function(nogroup){
    $(nogroup).find($("div[data-expand='more'] span")).on('click', function () {
      $(nogroup).find($("div[data-expand='less']")).show();
      var len = BibdkFacets.facetGroupLength(nogroup);
      BibdkFacets.FoldFacetGroup(nogroup, len);
    });
  };

  BibdkFacets.offGroupEvent = function(group, context){
    group.find($("div[data-expand='less'] span")).off('click');
    group.find($("div[data-expand='more'] span")).off('click');
  };

  /*
   * get a single facetgroup to replace the old one
   */
  BibdkFacets.getFacetGroup = function (group) {
    // check if group is already in cache
    var facets = BibdkFacets.getFromSessionStorage(group);
    if (facets) {
      BibdkFacets.setFacets(facets,  group);
      return;
    }

    // show a spinner while waiting
    group.find($("div[data-expand='more']")).html('<div class="ajax-progress ajax-progress-throbber"><div class="throbber"></div></div>');
    var facet = group.attr('data-name');
    $.ajax({
      url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'bibdk_facetbrowser/ajax/facetgroup/' + facet,
      type: 'POST',
      dataType: 'json',
      // set async to false to prevent eventhandler from acting on old facetgroup
      async:false,
      success: function(data){BibdkFacets.setFacets(data,  group);},
      error:BibdkFacets.setError
    });
  };

  BibdkFacets.setOtherEvents = function(){
    // Check for click in checkbox, and execute search
    $(Drupal.settings.bibdkFacetBrowser.mainElement + ' .form-type-checkbox input').change(function(e) {
      $('body').prepend('<div class="facetbrowser_overlay"><div class="spinner"></div></div>');
      window.location = $(e.target).parent().find('a').attr('href');
    });

    BibdkFacets.showAndHide();
  };

  BibdkFacets.showAndHide = function(){
    // @TODO why would you wanna hide valid facets ??
    // disambiguate facets that are hidden because some facets are already selected, and facets that are not yet shown.
    $("#bibdk-facetbrowser-form").find("a[data-hidden='0']").each(function(count, facetElement) {
      $(this).parents('div.form-type-checkbox').addClass('facetShow');
    });
    $("#bibdk-facetbrowser-form").find("a[data-hidden='1']").each(function(count, facetElement) {
      $(this).parents('div.form-type-checkbox').hide().addClass('facetNoShow');
    });
  };

  /**
   * get facets
   */
  BibdkFacets.getFacets = function (context) {
    var facets = BibdkFacets.getFromSessionStorage(false);
    if (facets) {
      BibdkFacets.setFacets(facets, false, context );
      return;
    }
    $.ajax({
      url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'bibdk_facetbrowser/ajax/facets',
      type: 'POST',
      dataType: 'json',
      success: function(data){BibdkFacets.setFacets(data, false )},
      error:BibdkFacets.setError
    });
  };

  BibdkFacets.setError = function(response){
    var facets=[];
    facets.markup = '<div>Could not get facets</div>';
    BibdkFacets.setFacets(facets, false);
    BibdkFacets.clearSessionStorage();
  };

  BibdkFacets.getCacheKey = function(group){
    if(group === false){
      return Drupal.settings.ting_openformat.search_key + Drupal.settings.pathPrefix;
    }
    else{
      return group.attr('id')+Drupal.settings.ting_openformat.search_key + Drupal.settings.pathPrefix;
    }
  };
})(jQuery);