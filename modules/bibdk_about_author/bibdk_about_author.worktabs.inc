<?php
/**
 * @file
 * bibdk_about_author.worktabs.inc
 */

/**
 * Implements hook_worktabs_items().
 *
 * @param bibdkWork $entity
 */
function bibdk_about_author_worktabs_items($entity) {
  $tabs = array();
  $about_author = urlencode(serialize($entity->getAboutAuthor()));

  $tabs['more-about']['about-author'] = array(
    '#title' => t('bibdk_about_authors', array(), array('context' => 'bibdk_about_author')),
    '#btn_txt_closed' => t('view_more', array(), array('context' => 'bibdk_about_author')),
    '#weight' => 20,
    '#content' => array(
      '#type' => 'fieldset',
      '#attributes' => array(
        'class' => array('about-author-load'),
        'data-query' => $about_author,
      ),
      '#attached' => array(
        'js' => array(drupal_get_path('module', 'bibdk_about_author') . '/js/bibdk_about_author.js'),
      ),
    ),
  );

  return $tabs;
}

/**
 * Return a list of links from a list of manifestations
 *
 * @param $pids
 * @return string html formatted list of links
 */
function bibdk_about_author_get_link_list_view($queries, $target = '_self') {

  $items = array();
  foreach ( $queries as $id => $query ) {
    $title = t("bibdk_about_author_read @display", array('@display' =>   $query['display']), array('context' => 'bibdk_about_author'));
    $link = array(
      '#type'  => 'link',
      '#title' => $title,
      '#href'  => 'search/work/' . $query['searchCode'],
      '#attributes' => array(
        'class' => array('about-author-links'),
        'target' => $target,
        'title'  =>  $title,
      ),

    );
    $items[]= render($link);
  }
  
  // make itemlist for display in single items
  $itemlist = array(
   '#theme'  => 'item_list',   
   '#items'  => $items,   
  ); 
  
  return $itemlist;

}
