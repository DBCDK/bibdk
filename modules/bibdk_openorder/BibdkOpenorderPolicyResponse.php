<?php

class BibdkOpenorderPolicyResponse {

  private $agencyCatalogueUrl;
  private $lookUpUrls;
  private $orderPossible;
  private $orderPossibleReason;
  private $orderCondition;
  private $response;
  private $checkOrderPolicyError;
  private $agencyId;

  public function getAgencyCatalogueUrl() {
    return isset($this->response->checkOrderPolicyResponse->agencyCatalogueUrl) ? $this->response->checkOrderPolicyResponse->agencyCatalogueUrl->{'$'} : NULL;
  }

  public function getLookUpUrl() {
    $urls = array();
    if (isset($this->response->checkOrderPolicyResponse->lookUpUrl)) {
      foreach($this->response->checkOrderPolicyResponse->lookUpUrl as $lookup_url){
        $urls[] = array(
          'url' => isset($lookup_url->{'$'}) ? $lookup_url->{'$'} : NULL,
          'agencyId' => isset($lookup_url->{'@agencyId'}->{'$'}) ? $lookup_url->{'@agencyId'}->{'$'} : NULL,
        );
      }
    }
    return $urls;
  }

  public function getOrderPossible() {
    $bool = isset($this->response->checkOrderPolicyResponse->orderPossible) ? $this->response->checkOrderPolicyResponse->orderPossible->{'$'} : FALSE;
    return ($bool === 'TRUE' || $bool === "true" || $bool === '1');
  }

  public function getOrderPossibleReason() {
    return isset($this->response->checkOrderPolicyResponse->orderPossibleReason) ? $this->response->checkOrderPolicyResponse->orderPossibleReason->{'$'} : NULL;
  }

  public function getOrderCondition($lang = 'dan') {
    $lang = $this->drupalLangToServiceLang($lang);
    $order_conditions = isset($this->response->checkOrderPolicyResponse->orderCondition) ? $this->response->checkOrderPolicyResponse->orderCondition : NULL;
    if ( is_array($order_conditions) ) {
      foreach ($order_conditions as $order_condition)
        if ($order_condition->{'@language'}->{'$'} == $lang) {
          $ret = $order_condition->{'$'};
        }
      if ( empty($ret) ) {
        // given lanuguage was not found..simply return first in array
        $ret = $order_condition->{'$'};
      }
      return $ret;
    }
    else {
      return ( $order_conditions ) ? $order_conditions->{'$'} : NULL;
    }
  }

  public function getCheckOrderPolicyError() {
    return isset($this->response->checkOrderPolicyResponse->checkOrderPolicyError) ? $this->response->checkOrderPolicyResponse->checkOrderPolicyError->{'$'} : NULL;
  }

  public function setResponse($response) {
    $this->response = $response;
  }

  public function getAgencyId() {
    return $this->agencyId;
  }

  public function setAgencyId($agencyId) {
    $this->agencyId = $agencyId;
  }

  /**
   * @return BibdkOpenorderPolicyResponse
   */
  public static function SetObject() {
    $_SESSION['orderpolicy'] = new BibdkOpenorderPolicyResponse();
    return $_SESSION['orderpolicy'];
  }

  /**
   * @return BibdkOpenorderPolicyResponse
   */
  public static function GetObject() {
    return $_SESSION['orderpolicy'];
  }

  private function parseFields($object, array $fields) {
    $ret = null;
    if (!isset($object)) {
      return NULL;
    }
    if (is_array($object)) {
      foreach ($object as $o) {
        if (isset($o)) {
          $ret[] = self::parseFields($o, $fields);
        }
      }
      return $ret;
    }

    foreach ($fields as $field => $value) {
      if (is_array($value) && isset($object->$field)) {
        $ret[$field][] = self::parseFields($object->$field, $value);
      }
      elseif ($value == 'searchCode' && isset($object->$field)) {
        $ret[$field][] = self::_parseSearchCode($object->$field);
      }
      elseif ($value == 'header' && isset($object->$field)) {
        $ret[$value] = $object->$field->{'$'};
      }
      elseif (!is_array($value) && isset($object->$value) && is_array($object->$value)) {

        foreach ($object->$value as $val) {
          $ret[$value][] = $val->{'$'};
        }
      }
      elseif (!is_array($value) && isset($object->$value) && is_object($object->$value)) {
        $ret[$value] = $object->$value->{'$'};
      }
    }
    return $ret;
  }

  /* \brief parse searchCode,display elements
   * @param array of stdObjects
   * return array of form []['display','searchCode']
   */
  private static function _parseSearchCode($stdObjects) {
    if (!is_array($stdObjects)) {
      $stdObjects = array($stdObjects);
    }

    foreach ($stdObjects as $object) {
      $subject['searchCode'] = self::_getSearchCodeElement($object->searchCode);
      $subject['display'] = isset($object->display) ? $object->display->{'$'} : NULL;
      $ret[] = $subject;
    }

    return $ret;
  }

  private static function _getSearchCodeElement($stdObject) {
    $value = (isset($stdObject->{'$'})) ? $stdObject->{'$'} : NULL;

    if (isset($stdObject->{'@phrase'})) {
      $term = $stdObject->{'@phrase'}->{'$'};
    }
    elseif (isset($stdObject->{'@word'})) {
      $term = $stdObject->{'@word'}->{'$'};
    }

    if (isset($value) && isset($term)) {
      return $term . "=" . $value;
    }
    else {
      return;
    }
  }

  private function drupalLangToServiceLang($lang) {
    // drupal en & en-gb = openformat eng
    if ($lang == 'en' || $lang == 'en-gb') {
      $lang = 'eng';
    }
    //drupal da = openformat dan
    if ($lang == 'da') {
      $lang = 'dan';
    }
    return $lang;
  }

}
