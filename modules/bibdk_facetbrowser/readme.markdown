# Bibdk Facetbrowser

## Important note

This module is still active developed, will try to keep the facetbrowser builder the way it is now. So do a git pull on regular basis to get updates.

## Usage

All search modules in this installation is implemented by `hook_search_info()`, `hook_search_execute()`, and `hook_bibdk_facetbrowser()` to implement the facetbrowser.

Check the `test_facetbrowser_search` module, which is placed in `bibdk_facetbrowser/test_facetbrowser_search/` for how to implement your search module into the facetbrowser.

Remember to enable the test_facetbrowser_search module and enable the module as a search tab in `'Admin -> Search settings'`  or via the hook_install in `test_facetbrowser_search.install`.

The only custom part is `hook_bibdk_facetbrowser()` where you have to use this precise format for the facets.

If you want to have an empty facetbrowser block, in which you can put data into with your custom module, do something like this

    function CUSTOM_bibdk_facetbrowser() {
      $results             = new stdClass();
      // Show an empty facetbrowser block, even if search didn't return any results
      $results->show_empty = TRUE; 
      $results->facets = array();
      return $results;
    }

## Installation

`git clone git@github.com:bibdk/bibdk_facetbrowser.git`

From your drupal installation go to

1. Admin -> Modules And enable "Bibdk Facet browser"
2. Admin -> Structure -> Blocks and enable "Search form" and "Facetbrowser"

Based on Bibdk facetbrowser
