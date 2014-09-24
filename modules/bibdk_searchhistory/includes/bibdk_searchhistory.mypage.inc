<?php

/**
 * @file
 * Implements hook_bibdk_mypage_tabs().
 */

function bibdk_searchhistory_bibdk_mypage_tabs($max_rows = 3) {
  global $user;

  $ret = array();
  $ret['bibdk_searchhistory']['header'] = t('Search history');
  $ret['bibdk_searchhistory']['rows']['values'] = bibdk_searchhistory_my_page_get_rows($max_rows);
  $ret['bibdk_searchhistory']['link'] = array(
    'title' => t('Go to search history'),
    'href' => 'user/' . $user->uid . '/searchhistory',
  );
  $ret['bibdk_searchhistory']['weight'] = 15;
  $ret['bibdk_searchhistory']['help_text_key'] = 'search_history_mypage_help_key';
 
  return $ret;
}

function bibdk_searchhistory_my_page_get_rows($max_rows) {
  global $user;
  $ret = array();

  $session_history = array();
  if (ding_user_is_provider_user($user)) {
    $header['memolist'] = t('Memolist');
    $session_history = BibdkSearchHistory::getAllElements();
  }

  if (sizeof($session_history) > 0) {
    $session_history = array_slice($session_history, 0, $max_rows);
    foreach ($session_history as $searchstring => $search) {
      $ret[] = array(
        'item_row' => _bibdk_searchhistory_get_markup_for_search($search),
      );
    }
  }
  else {
    $ret[] = array(
      'item_row' => t('No searches executed yet'),
    );
  }

  return $ret;

}
