<?php

/**
 * @file
 * Define class BibdkSearchHistory.
 */

class BibdkSearchHistory {

  private static $elements = NULL;

  /**
   * Add pid to bibdk_cart
   */
  public static function addElementToWebservice($element) {
    $object = array(
      'oui:searchHistoryString' => $element['string'],
      'oui:searchHistoryParams' => (isset($element['params'])) ? json_encode($element['params']) : json_encode(array()),
      'oui:searchHistoryTime' => $element['timestamp'],
      'oui:searchHistoryCount' => $element['count'],
    );
    $element['id'] = _bibdk_searchhistory_add_element_webservice($object);

    return $element;
  }

  /**
   * Remove pid from cart
   */
  public static function removeElementFromWebservice($element) {
    $object = array(
      'oui:searchHistoryId' => $element['id'],
    );
    $string = $element['string'];
    if (array_key_exists($string, $_SESSION['searches'])) {
      unset($_SESSION['searches'][$string]);
    }

    return _bibdk_searchhistory_remove_element_webservice($object);
  }


  /**
   * Get all searchhistory elements
   */
  public static function getAllElements() {
    $elements = _bibdk_searchhistory_get_elements_webservice();
    $elements += self::getSession();

    return $elements;
  }

  /** Get single element with specific searchstring
   * @param $string
   * @return null
   */
  public static function getElement($string) {
    $elements = self::getAllElements();

    return (isset($elements[$string])) ? $elements[$string] : NULL;
  }


  /** Get session object
   * @return array
   */
  public static function getSession() {
    if (!isset($_SESSION['searches'])) {
      $_SESSION['searches'] = array();
    }

    return $_SESSION['searches'];
  }

  /** Add single element to Session
   * @param $element
   */
  public static function addElementToSession($element) {
    $key = $element['string'];
    $_SESSION['searches'][$key] = $element;
    self::_checkSessionLimit();
  }

  /** Remove single element to Session
   * @param $element
   */
  public static function removeElementFromSession($element) {
    $string = $element['string'];
    if (isset($_SESSION['searches'][$string])) {
      unset($_SESSION['searches'][$string]);
    }
  }

  /**
   * If where are more searches in session than limit allows remove oldest element
   */
  private static function _checkSessionLimit() {
    $limit = (int) variable_get('search_history_save_limit');
    if (count($_SESSION['searches']) > $limit && $limit > 0) {
      array_shift($_SESSION['searches']);
    }
  }

  public static function clearAllSearchHistory() {
    $elements = self::getAllElements();
    foreach ($elements as $element) {
      if (isset($element['id'])) {
        self::removeElementFromWebservice($element);
      }
    }
    unset($_SESSION['searches']);
  }

}
