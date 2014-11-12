(function($) {

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
    Drupal.FoldFacetGroup();

    // Check for click in checkbox, and execute search
    $(Drupal.settings.bibdkFacetBrowser.mainElement + ' .form-type-checkbox input').change(function(e) {
      $('body').prepend('<div class="facetbrowser_overlay"><div class="spinner"></div></div>');
      window.location = $(e.target).parent().find('a').attr('href');
    });

    $("#bibdk-facetbrowser-form").find("div[data-expand='less']").hide();

    $("#bibdk-facetbrowser-form").delegate("div[data-expand='more'] span", "click", function() {
      var facetGroup = $(this).parents('fieldset');
      // var divExpand = $(this).parent();

      facetGroup.find('.form-type-checkbox:hidden').each(function(count, facetElement) {
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
      if ( ( facetGroup.find('.form-type-checkbox:visible').size() >= facetGroup.attr('data-count') ) && ( facetGroup.find("div[data-expand='more']").is(':visible') ) ) {
        facetGroup.find("div[data-expand='more']").hide();
      }

    });

    $("#bibdk-facetbrowser-form").delegate("div[data-expand='less'] span", "click", function() {
      var facetGroup = $(this).parents('fieldset');
      // var divExpand = $(this).parent();

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

    // Show/hide modal window
    // To do: Redo as Foundation Modal
    $("#bibdk-facetbrowser-form").delegate("div[data-expand='select'] span", "click", function() {
      $("#bibdk-facetbrowser-form").find("div.reveal-modal").hide();
      var facetGroup = $(this).parents('fieldset');
      // show popover element. 
      facetGroup.find(".reveal-modal").show();
      facetGroup.find(".reveal-modal .close").focus();
    });

    // Populate modal window
    $("#bibdk-facetbrowser-form").delegate("div[data-expand='select'] span", "click", function() {
      var facetGroup = $(this).parents('fieldset');
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
    $("#bibdk-facetbrowser-form").delegate(".reveal-modal input[type='checkbox']", "change", function() {
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
    $("#bibdk-facetbrowser-form").delegate(".save-facet-modal .btn", "click", function(event) {
      event.preventDefault();
      var facetsSelect   = new Array();
      var facetsDeselect = new Array();
      // $("#bibdk-facetbrowser-form").find("div.reveal-modal").hide();
      var modalGroup = $(this).parents('.reveal-modal');
      var facetKey   = $(this).parents('fieldset').attr('data-name');

      // get url from form data-uri attribute
      var url = $(this).parents('#bibdk-facetbrowser-form').attr('data-uri');
      // create anchor element, so we can access path from DOM
      var a = $('<a>', { href:url } )[0];
      /*
          console.log( elementLink[0].protocol );
          console.log( elementLink[0].host );
          console.log( elementLink[0].pathname );
          console.log( elementLink[0].search );
          console.log( elementLink[0].hash );
      */

      console.log( 'baseUri: ' + a.search );
      var myArray = decodeURIComponent(a.search).split('&');

      modalGroup.find("input[type='checkbox']").each(function(count, modalElement) {

        // delete facet values that are included in this group
        $.each( myArray, function( key, value ) {
          if ( value == 'facets[]=' + facetKey + ':' + $(modalElement).val() || value == 'facets[]=-' + facetKey + ':' + $(modalElement).val() ) {
            console.log( 'delete : ' + facetKey + ':' + $(modalElement).val() );
            myArray.splice(key, 1);
          }
        });

        if ( modalElement.checked ) {
          if ( $(modalElement).attr('data-deselect') ) {
            facetsDeselect.push( $(modalElement).val() );
          } else {
            facetsSelect.push( $(modalElement).val() );
          }
        }

      });

      for ( var i = 0; i < facetsSelect.length; i = i + 1 ) {
        myArray.push('facets[]=' + facetKey + ':' + facetsSelect[i]);
      }

      for ( var i = 0; i < facetsDeselect.length; i = i + 1 ) {
        myArray.push('facets[]=!' + facetKey + ':' + facetsDeselect[i]);
      }

      $.each( myArray, function( key, value ) {
        console.log( key + " : " + value );
      });
      
      newUri = a.protocol + '//' + a.host + a.pathname + myArray.join('&');
      
      // console.log( newUri );
      window.location.replace(newUri);

    });


    // close button - close and set focus back to opening link
    $("#bibdk-facetbrowser-form").delegate(".close-facet-modal .btn", "click", function(event) {
      event.preventDefault();
      var facetGroup = $(this).parents('fieldset');
      // hide popover element. 
      if ( facetGroup.find("div.reveal-modal").is(':visible') ) {
        facetGroup.find("div.reveal-modal").hide();
      }
      facetGroup.find("div[data-expand='select']").focus();
    });

  };

  /**
   * Fold facet groups to show only n per group.
   */
  Drupal.FoldFacetGroup = function() {
    $(Drupal.settings.bibdkFacetBrowser.mainElement + ' fieldset.form-wrapper').each(function() {
      // hide surplus facets, and show 'show more' element
      var facetGroup = $(this);
      if ( facetGroup.find('.form-type-checkbox').size() > Drupal.settings.bibdkFacetBrowser.showCount ) {
        facetGroup.find('.form-type-checkbox').each(function(counter, facetElement) {
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


