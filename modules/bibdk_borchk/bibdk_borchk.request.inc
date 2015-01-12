<?php

class bibdk_borchk extends TingClientRequest Implements ITingClientRequestCache {

  protected $serviceRequester;
  protected $libraryCode;
  protected $userPincode;
  protected $userId;
  protected $action;
  protected $cacheKey;
  protected $outputType;

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
   * @return value of variable (drupal_get)
   */
  public function cacheEnable($value = NULL) {
    $class_name = get_class($this);
    return variable_get($class_name . TingClientRequest::cache_enable);
  }

  /*   * \brief set timeout of cache
   * 
   * @return mixed value of variable (variable_get)  
   */

  public function cacheTimeout($value = NULL) {
    $class_name = get_class($this);
    return variable_get($class_name . TingClientRequest::cache_lifetime, '1');
  }

  public function checkResponse($response) {
    if ($this->isJson($response)) {
      $ret = json_decode($response);
      if (isset($ret->borrowerCheckResponse->requestStatus)) {
        $status = $ret->borrowerCheckResponse->requestStatus->{'$'};
        if ($status == 'service_unavailable') {
          return FALSE;
        }
      }
    }
    else {
      //response is assumed xml -- could be serialized php
      $dom = new DomDocument();
      if (@$dom->loadXML($response)) {
        $xpath = new DomXPATH($dom);
        $xpath->registerNamespace('hest', "http://oss.dbc.dk/ns/borchk");
        $query = '//hest:requestStatus';
        $nodes = $xpath->query($query);
        $status = $nodes->item(0)->nodeValue;
        if ($status == 'service_unavailable') {
          return FALSE;
        }
      }
    }
    return TRUE;
  }

  private function isJson($response){
    if(is_string($response)){
      if(is_object(json_decode($response))){
        return TRUE;
      }
    }
    return FALSE;
  }

  /* \brief implements ITingClientRequestCache::cacheBin
   * 
   * @return string; name of cachebin
   */

  public function cacheBin() {
    return 'cache_borchk_webservice';
  }

  public function setServiceRequester($value = NULL) {
    $this->serviceRequester = $value;
  }

  public function getServiceRequester() {
    return $this->serviceRequester;
  }

  public function setLibraryCode($value = NULL) {
    $this->libraryCode = $value;
  }

  public function getLibraryCode() {
    return $this->libraryCode;
  }

  public function setUserPincode($value = NULL) {
    $this->userPincode = $value;
  }

  public function getUserPincode() {
    return $this->userPincode;
  }

  public function setAction($value = NULL) {
    $this->action = $value;
  }

  public function getAction() {
    return $this->action;
  }

  public function setUserId($value = NULL) {
    $this->userId = $value;
  }

  public function getUserId() {
    return $this->userId;
  }

  public function setOutputType($value = NULL) {
    $this->outputType = $value;
  }

  public function getOutputType() {
    return $this->outputType;
  }

  public function getRequest() {
    $this->setParameter('action', 'borrowerCheckRequest');
    $params = array('serviceRequester', 'libraryCode', 'userPincode', 'userId', 'outputType');
    foreach ($params as $parameter) {
      $getter = 'get' . ucfirst($parameter);
      if ($value = $this->$getter()) {
        $this->setParameter($parameter, $value);
      }
    }
    return $this;
  }

  // empty;
  public function processResponse(stdClass $result) {
    return $result;
  }

}