(function($) {

  $(document).on("opened", '.bibdk-facetbrowser-modal', function () {
    $(document).foundation('dropdown', 'reflow');
  });

  Drupal.SetFacets = function(facets) {
    if(facets.error) {
      $('.bibdk_facetbrowser_facets_placeholder').prepend(facets.error);
    }
    else {
      $('.bibdk_facetbrowser_facets_placeholder').html(facets.markup);
      Drupal.facetBrowserInit();

      var facetsObj = {
        timestamp: Date.now(),
        markup: facets.markup
      };
      Drupal.tingOpenformatSetSessionStorage(facetsObj);
    }
  };

  Drupal.tingOpenFormatGetStorageKey = function(){
    var key = Drupal.settings.ting_openformat.search_key + Drupal.settings.pathPrefix;
    return key;
  }


  /**
   * Used when setting facets with data from sessionStorage to avoid
   * unnecessary update of the sessionStorage
   */
  Drupal.tingOpenformatGetFacetsFromSessionStorage = function(markup) {
    $('.bibdk_facetbrowser_facets_placeholder').html(markup);
    Drupal.facetBrowserInit();
  };

  /**
   * Asks for facets based on the current search result. If the browser
   * supports sessionStorage it will check for saved facets otherwise facets
   * will be retrieved by AJAX.
   */
  Drupal.tingOpenformatGetFacets = function() {
    if(Modernizr.sessionstorage && !Drupal.settings.ting_openformat.isAdmin) {
      Drupal.tingOpenformatCheckSessionStorage();
    }
    else {
      Drupal.tingOpenformatGetFacetsByAjax();
      if(Drupal.settings.ting_openformat.isAdmin) {
        console.log("You are logged in as admin and to avoid caching of facets when changes are to facets, facets are retrieved by AJAX on every page request.");
      }
      if(!Modernizr.sessionstorage) {
        console.log("sessionStorage is not supoorted by this browser. Facets will be retrieved by AJAX on every page request.");
      }
    }
  };

  /**
   * Returns facets stored in the sessionStorage. If none is found facets will
   * be retrieved by AJAX.
   *
   * If the facets currently stored in the sessionStorage has an age of
   * 24 hours or more, the stored facets will get deleted and new ones will
   * be retrieved by AJAX.
   */
  Drupal.tingOpenformatCheckSessionStorage = function() {
    var key = Drupal.tingOpenFormatGetStorageKey();

    var facetsObj = sessionStorage.getItem(key);

    facetsObj = JSON.parse(facetsObj);

    if(!facetsObj || !facetsObj.markup || !facetsObj.timestamp) {
      Drupal.tingOpenformatGetFacetsByAjax();
    }
    else {
      var now = Date.now();
      if(now - facetsObj.timestamp >= 86400000) {
        Drupal.tingOpenformatGetFacetsByAjax();
      }
      else {
        Drupal.tingOpenformatGetFacetsFromSessionStorage(facetsObj.markup);
      }
    }
  };

  /**
   * Stores the given value object in the sessionStorage with the key
   * parameter as key.
   * If the browser doesn't support sessionStorage the operation will be
   * aborted silently.
   *
   * @param value mixed
   * @param key string
   * @param retry bool idicating if the attempt so store is a retry after sessionStorage have been cleared
   */
  Drupal.tingOpenformatSetSessionStorage = function( value, retry) {
    var key = Drupal.tingOpenFormatGetStorageKey();
    if(!Modernizr.sessionstorage) {
      console.log("sessionStorage is not supported by this browser");
      return;
    }

    try {
      sessionStorage.setItem(key, JSON.stringify(value));
      Drupal.tingOpenformatStoreSearchKey(key);
    } catch(e) {
      if(!retry) {
        Drupal.tingOpenformatClearSessionStorageSearches();
        Drupal.tingOpenformatSetSessionStorage( value, true);
      }
    }
  };

  /**
   * Stores the key associated witn the current search ion the searches array
   * that keeps track of the searces stored in the sessionStorage.
   *
   * @param key string
   * @return {boolean}
   */
  Drupal.tingOpenformatStoreSearchKey = function(key) {
    var searches = sessionStorage.getItem('searches');
    searches = JSON.parse(searches);

    if(!searches) {
      searches = [];
    }

    if(searches.indexOf(key) == -1) {
      searches.push(key);
      sessionStorage.setItem('searches', JSON.stringify(searches));
    }
  };

  /**
   * Clears out the seartches stored in sessionStorage.
   *
   * @return {boolean}
   */
  Drupal.tingOpenformatClearSessionStorageSearches = function() {
    var searches = sessionStorage.getItem('searches');
    searches = JSON.parse(searches);

    if(!searches) {
      searches = [];
    }

    searches.forEach(function(value) {
      sessionStorage.removeItem(value);
    });

    sessionStorage.setItem('searches', JSON.stringify([]));
  };

  /**
   * Retrieves the facets from the server by AJAX.
   */
  Drupal.tingOpenformatGetFacetsByAjax = function() {
    // var url =  Drupal.settings.basePath + Drupal.settings.pathPrefix + 'ting_openformat/ajax/facets';
    $.ajax({
      url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'bibdk_facetbrowser/ajax/facets',
      type: 'POST',
      dataType: 'json',
      success: Drupal.SetFacets
    });
  };

  Drupal.behaviors.tingOpenformatLoad = {
    attach: function(context) {
      var element = $('.bibdk_facetbrowser_facets_placeholder');
      if(element.length == 0) {
        Drupal.facetBrowserInit();
      }
      else {
        element = $('#bibdk-facetbrowser-form');
        if(element.length < 1) {
          $('.bibdk_facetbrowser_facets_placeholder', context).ready(function() {
            var div = $('.bibdk_facetbrowser_facets_placeholder');
            div.html('<div class="ajax-progress ajax-progress-throbber"><div class="throbber"></div></div>');
            Drupal.tingOpenformatGetFacets();
          });
        }
      }
    }
  };

  Drupal.facetBrowserInit = function() {

    // Check for click in checkbox, and execute search
    $(Drupal.settings.bibdkFacetBrowser.mainElement + ' .form-type-checkbox input').change(function(e) {
      $('body').prepend('<div class="facetbrowser_overlay"><div class="spinner"></div></div>');
      window.location = $(e.target).parent().find('a').attr('href');
    });

    // disambiguate facets that are hidden because some facets are already selected, and facets that are not yet shown.
    $("#bibdk-facetbrowser-form").find("a[data-hidden='0']").each(function(count, facetElement) {
      $(this).parents('div.form-type-checkbox').addClass('facetShow');
    });
    $("#bibdk-facetbrowser-form").find("a[data-hidden='1']").each(function(count, facetElement) {
      $(this).parents('div.form-type-checkbox').hide().addClass('facetNoShow');
    });

    Drupal.FoldFacetGroup();

    $("#bibdk-facetbrowser-form").find("div[data-expand='less']").hide();

    $("#bibdk-facetbrowser-form").delegate("div[data-expand='more'] span", "click", function() {
      var facetGroup = $(this).parents('fieldset');
      facetGroup.find('.form-type-checkbox.facetShow:hidden').each(function(count, facetElement) {
        if ( count < Drupal.settings.bibdkFacetBrowser.showCountConsecutive ) {
          $(facetElement).slideDown('fast', function() {
          });
        }
      });
      // add 'less' element, if there isn't one already
      if ( facetGroup.find("div[data-expand='less']").is(':hidden') ) {
        facetGroup.find("div[data-expand='less']").show();
      }
      // remove 'more' element, if we're at the end
      if ( 
          ( facetGroup.find('.form-type-checkbox:visible').size() >= facetGroup.attr('data-count') ) && 
          ( facetGroup.find("div[data-expand='more']").is(':visible') )
        ) {
        facetGroup.find("div[data-expand='more']").hide();
      }
    });

    $("#bibdk-facetbrowser-form").delegate("div[data-expand='less'] span", "click", function() {
      var facetGroup = $(this).parents('fieldset');
      facetGroup.find('.form-type-checkbox:visible').each(function(count, facetElement) {
        if(count >= Drupal.settings.bibdkFacetBrowser.showCount) {
          $(facetElement).slideUp('fast', function() {
          });
        }
      });
      // we're at the start, so add 'more' element, and remove 'less' element
      facetGroup.find("div[data-expand='less']").hide();
      if ( facetGroup.find("div[data-expand='more']").is(':hidden') ) {
        facetGroup.find("div[data-expand='more']").show();
      }
    });

    // Populate modal window
    $("#bibdk-facetbrowser-form").delegate("div[data-expand='select'] span", "click", function() {
      // get url from form data-uri attribute
      var url = $(this).parents('#bibdk-facetbrowser-form').attr('data-uri');
      var facetGroup = $(this).parents('fieldset');
      facetGroup.find(".bibdk-facetbrowser-modal").attr('data-uri', url);
      var divTemplate = facetGroup.find(".reveal-modal .checkbox-element").clone();
      if ( !facetGroup.find(".reveal-modal .checkbox-elements").html().trim() ) {
        facetGroup.find('.form-type-checkbox').each(function(count, facetElement) {
          var checkboxElem         = divTemplate.clone();
          var checkboxElemLabel    = $(facetElement).find('label').clone();
          var checkboxElemSelect   = $(facetElement).find('input').clone();
          var checkboxElemDeselect = $(facetElement).find('input').clone();
          // checkboxElemDeselect.val(checkboxElemDeselect.val());
          checkboxElemDeselect.attr("checked", false);
          checkboxElemDeselect.attr("data-deselect", true);
          checkboxElem.find(".checkbox-element-label").append(checkboxElemLabel);
          checkboxElem.find(".checkbox-element-select").append(checkboxElemSelect);
          checkboxElem.find(".checkbox-element-deselect").append(checkboxElemDeselect);
          facetGroup.find(".reveal-modal .checkbox-elements").append(checkboxElem);
        });
      }
    });

    // simulate radio buttons functionality
    $(".bibdk-facetbrowser-modal").delegate(".reveal-modal input[type='checkbox']", "change", function() {
      // ought to use .prop() instead of .attr(), but that requires jQuery 1.6 or greater
      if ( this.checked ) { 
        var elemName = $(this).attr('name');
        var modalGroup = $(this).parents('.reveal-modal');
        modalGroup.find("input[type='checkbox']").each(function(count, modalElement) {
          if ( $(modalElement).attr('name') == elemName ) {
            $(modalElement).attr("checked", false);
          }
        });
        $(this).attr("checked", true);
      }
    });
    
    // modal window submit button
    $(".bibdk-facetbrowser-modal").delegate(".save-facet-modal .btn", "click", function(event) {
      event.preventDefault();
      var myArray        = new Array();
      var facetsSelect   = new Array();
      var facetsDeselect = new Array();
      var modalGroup = $(this).parents('.bibdk-facetbrowser-modal');
      var facetKey = $(this).parents('.bibdk-facetbrowser-modal').attr('data-facet-key');

      // get url from modal div data-uri attribute
      var url = $(this).parents('.bibdk-facetbrowser-modal').attr('data-uri');
      // create anchor element, so we can access path from DOM
      var a = $('<a>', { href:url } )[0];
      var uriArray = decodeURI(a.search).split('&');

      $.each( uriArray, function( key, value ) {
        // clear facet values in this group
        if ( !Drupal.paramIsFacet(value, facetKey, modalGroup.find("input[type='checkbox']")) ) {
          if ( jQuery.inArray( value, myArray ) == -1 ) {
            myArray.push(value);
          }
        }
      });

      modalGroup.find("input[type='checkbox']").each(function(count, modalElement) {
        if ( modalElement.checked ) {
          if ( $(modalElement).attr('data-deselect') ) {
            facetsDeselect.push( $(modalElement).val() );
          } else {
            facetsSelect.push( $(modalElement).val() ); 
          }
        }
      });

      for ( var i = 0; i < facetsSelect.length; i = i + 1 ) {
        myArray.push('facets[]=' + 'facet.' + facetKey + ':' + encodeURI(facetsSelect[i]));
      }

      for ( var i = 0; i < facetsDeselect.length; i = i + 1 ) {
        myArray.push('facets[]=!' + 'facet.' + facetKey + ':' + encodeURI(facetsDeselect[i]));
      }

      newUri = a.protocol + '//' + a.host + '/' + encodeURI(a.pathname) + myArray.join('&') + '#content';
      window.location.replace(newUri);

    });

  };


  /**
   * Check if param is a facet in group
   *
   * @param key string
   * @return {boolean}
   */
  Drupal.paramIsFacet = function(value, facetKey, facetGroup) {
    var result = false;
    facetGroup.each(function(count, modalElement) {
      if ( 
           decodeURI(value) == 'facets[]=facet.' + facetKey + ':' + $(modalElement).val() || 
           decodeURI(value) == 'facets[]=-facet.' + facetKey + ':' + $(modalElement).val() ||
           decodeURI(value) == 'facets[]=facet.' + facetKey + '%3A' + $(modalElement).val() || 
           decodeURI(value) == 'facets[]=-facet.' + facetKey + '%3A' + $(modalElement).val()
         ) {
           result = true;
      }
    });
    return result;
  };


  /**
   * Fold facet groups to show only n per group.
   */
  Drupal.FoldFacetGroup = function() {
    $(Drupal.settings.bibdkFacetBrowser.mainElement + ' fieldset.form-wrapper').each(function() {
      // hide surplus facets, and show 'show more' element
      var facetGroup = $(this);
      if ( facetGroup.find('.form-type-checkbox.facetShow').size() > Drupal.settings.bibdkFacetBrowser.showCount ) {
        facetGroup.find('.form-type-checkbox.facetShow').each(function(counter, facetElement) {
          if ( counter >= Drupal.settings.bibdkFacetBrowser.showCount ) {
            $(facetElement).hide();
          }
        });
        if ( facetGroup.find("div[data-expand='more']").is(':hidden') ) {
          facetGroup.find("div[data-expand='more']").show();
        }
      } else {
        facetGroup.find("div[data-expand='more']").hide();
      }
    });

  };

})(jQuery);


