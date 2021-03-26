<?php

class bibdk_borchk extends TingClientRequest Implements ITingClientRequestCache {

  protected $serviceRequester;
  protected $libraryCode;
  protected $userPincode;
  protected $userId;
  protected $action;
  protected $cacheKey;

  /** Implementation of ITingClientRequestCache */

  /** \brief ITingClientRequestCache::cacheKey; get a cachekey
   *
   * @return string
   */
  public function cacheKey() {
    $params = $this->getParameters();
    $ret = '';
    $this->make_cache_key($params, $ret);

    return md5($ret);
  }

  /** \brief make a cachekey based on request parameters
   *
   * @param array $params
   * @param string $ret
   */
  private function make_cache_key($params, &$ret) {
    foreach ($params as $key => $value) {
      if (is_array($value)) {
        // recursive
        $ret.=$key;
        $this->make_cache_key($value, $ret);
      }
      else {
        $ret.=$value;
      }
    }
  }

  /** \brief ITingClientRequestCache::cacheEnable; Check if cache is enabled
   *
   * @param string|null $value
   * @return value of variable (drupal_get)
   */
  public function cacheEnable($value = NULL) {
    $class_name = get_class($this);
    return variable_get($class_name . TingClientRequest::cache_enable);
  }

  /**   * \brief set timeout of cache
   *
   * @param string|null $value
   * @return mixed value of variable (variable_get)
   */

  public function cacheTimeout($value = NULL) {
    $class_name = get_class($this);
    return variable_get($class_name . TingClientRequest::cache_lifetime, '1');
  }

  /**
   * Override TingClientRequest::parseResponse
   *
   * As of openorder 3.0 service returns xml only. Ting client is made for
   * parsing json supported by OLS webservices.
   *
   * Two classes from OLS are used to convert xml to json, to use same procedure as
   * before.
   *
   * @see ting-client/lib/ols_convert/xmlconvert_class.php and objconvert_class.php
   *
   * @param $responseString
   * @return mixed
   * @throws Exception
   */
  public function parseResponse($responseString) {
    $dom = new DOMDocument();
    $dom->preserveWhiteSpace = FALSE;
    if (@$dom->loadXML($responseString)) {
      $xmlconvert = new xmlconvert();
      $objconvert = new objconvert();
      $OLS_obj = $xmlconvert->xml2obj($dom);
      $badgerfish = $objconvert->obj2json($OLS_obj);
      return parent::parseResponse($badgerfish);
    }
    else {
      throw new Exception('failed to parse response from borchk: ' . $responseString);
    }
  }

  /* \brief implements ITingClientRequestCache::cacheBin
   *
   * @return string; name of cachebin
   */

  public function cacheBin() {
    return 'cache_borchk_webservice';
  }

  /**
   * @param string|null
   */
  public function setServiceRequester($value = NULL) {
    $this->serviceRequester = $value;
  }

  /**
   * @return string
   */
  public function getServiceRequester() {
    return $this->serviceRequester;
  }

  /**
   * @param string|null
   */
  public function setLibraryCode($value = NULL) {
    $this->libraryCode = $value;
  }

  /**
   * @return string
   */
  public function getLibraryCode() {
    return $this->libraryCode;
  }

  /**
   * @param string|null
   */
  public function setUserPincode($value = NULL) {
    $this->userPincode = $value;
  }

  /**
   * @return string
   */
  public function getUserPincode() {
    return $this->userPincode;
  }

  /**
   * @param string|null
   */
  public function setAction($value = NULL) {
    $this->action = $value;
  }

  /**
   * @return string
   */
  public function getAction() {
    return $this->action;
  }

  /**
   * @param string|null
   */
  public function setUserId($value = NULL) {
    $this->userId = $value;
  }

  /**
   * @return string
   */
  public function getUserId() {
    return $this->userId;
  }

  public function getRequest() {
    $this->setParameter('action', 'borrowerCheckRequest');
    $params = array('serviceRequester', 'libraryCode', 'userPincode', 'userId');
    foreach ($params as $parameter) {
      $getter = 'get' . ucfirst($parameter);
      $value = $this->$getter();
      // Additional check due to PHP considers the string '0' as FALSE
      if ($value || is_string($value) && $value != '') {
        $this->setParameter($parameter, $value);
      }
    }
    return $this;
  }

  // empty;
  public function processResponse(stdClass $result) {
    return $result;
  }

  /**
 * do NOT set default outputType in TingClientRequestAdapter - we handle
 * response ourself - see this::parseResponse
 * @return bool
 */
  public function defaultOutputType() {
    return FALSE;
  }

}
