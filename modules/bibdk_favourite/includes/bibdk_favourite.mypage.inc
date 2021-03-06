<?php

/**
 * Implements hook_bibdk_mypage_tabs().
 */
function bibdk_favourite_bibdk_mypage_tabs($max_rows = 3) {
  global $user;

  $ret = array();
  $ret['bibdk_favourite']['header'] = 'Favourites';
  $ret['bibdk_favourite']['rows']['values'] = bibdk_favourite_my_page_get_rows($max_rows);
  $ret['bibdk_favourite']['link'] = array(
    'title' => t('Edit favorites'),
    'href' => 'user/' . $user->uid . '/bibdk_favourite_list',
  );

  $ret['bibdk_favourite']['weight'] = 20;
  $ret['bibdk_favourite']['help_text_key'] = 'favourite_mypage_help_key';

  return $ret;
}

function bibdk_favourite_my_page_get_rows($max_rows) {
  $agencies = bibdk_favourite_get_favourites();

  usort($agencies, '_bibdk_favourite_sort');
  if (sizeof($agencies) > 0) {
    $agencies = array_slice($agencies, 0, $max_rows);
    foreach ($agencies as $id => $favourite) {
      if (empty($favourite)) {
        continue;
      }
      global $language;
      $ret[] = array(
        'label_row' => $favourite->getBranchShortName($language->language),
        'value_row' => ($favourite->orderAgency) ? t('(Order agency)') : NULL,
      );
    }
  }
  else {
    $ret[] = array(
      'item_row' => t('No favourites selected yet'),
    );
  }

  return $ret;
}
