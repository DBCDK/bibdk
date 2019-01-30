<?php

/**
 * @file
 * Hooks provided by the bibdk_gdpr module.
 */

/**
 * Implements hook_bibdk_gdpr_items().
 *
 * @return array
 */
function bibdk_favourite_bibdk_gdpr_items() {
  $items['bibdk_favourite']['#weight'] = 20;
  $items['bibdk_favourite']['#header'] = t('label_gdpr_favorite_libraries', array(), array('context' => 'bibdk_gdpr'));
  $items['bibdk_favourite']['#theme'] = 'bibdk_gdpr_item_theme';
  if ($rows = bibdk_favourite_gdpr_get_rows()) {
    $items['bibdk_favourite']['#content'] = $rows;
  }
  else {
    $items['bibdk_favourite']['#content'] = array(
      '#type' => 'container',
      'text' => array(
        '#markup' => t('label_no_favorite_libraries', array(), array('context' => 'bibdk_gdpr'))
      ),
    );
  }
  return $items;
}

/**
 * Collect render array for gdpr.
 *
 * @return array
 */
function bibdk_favourite_gdpr_get_rows() {
  global $language;
  $ret = array();
  $agencies = bibdk_favourite_get_favourites();
  usort($agencies, '_bibdk_favourite_sort');
  if (sizeof($agencies) == 0) {
    return $ret;
  }
  foreach ($agencies as $id => $favourite) {
    /** @var FavouriteAgency $favourite */
    $branch = $favourite->getBranch();
    if (empty($branch)) {
      continue;
    }
    $userdata_container = $userData = array();
    foreach ($favourite->userData as $key => $val) {
      $userData['userdata'] = array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => array('gdpr-favourite-data'),
        ),
      );
      $userData['userdata']['label'] = array(
        '#type' => 'html_tag',
        '#tag' => 'span',
        '#value' => t($key, array(), array('context' => 'bibdk_favorite'))
      );
      $userData['userdata']['value'] = array(
        '#type' => 'html_tag',
        '#tag' => 'span',
        '#value' => bibdk_favourite_gdpr_mask_me($key,$val)
      );
      $userdata_container[] = $userData;
    }
    $ret[] = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array('gdpr-favourite'),
      ),
      'label' => array(
        '#type' => 'container',
        'branchname' => array('#markup' => $branch->getBranchShortName($language->language)),
        '#attributes' => array(
          'class' => array('gdpr-favourite-name'),
        ),
      ),
      'value' => $userdata_container,
    );
  }
  return $ret;
}

/**
 * Mask (replace characters with '*') fields that should not be shown.
 * @param $key
 * @param $value
 * @return string
 */
function bibdk_favourite_gdpr_mask_me($key, $value) {
  if (bibdk_favourite_gdpr_masked_field($key)) {
    $password = str_repeat("*", strlen($value));
    return $password;
  }

  return $value;
}

/**
 * Check if given key is to be masked or not
 * @param $key
 * @return bool
 */
function bibdk_favourite_gdpr_masked_field($key){
  $fields_to_mask = array(
    'pincode',
    'cpr',
    'userid',
    'cardno',
    'customid',
    'userdateofbirth'
  );

  return in_array(strtolower($key), $fields_to_mask);
}
