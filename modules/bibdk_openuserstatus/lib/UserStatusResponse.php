<?php

/**
 * Class UserStatusResponse
 */
class UserStatusResponse {

  public $response;
  public $error;
  public $userId;


  /**
   * @param stdClass $response
   */
  public function __construct($response=NULL,$error=FALSE) {
    if (!empty($error)) {
      $this->setError($error);
    }
    else if (isset($response->getUserStatusResponse)) {
      $this->_parseResponse($response->getUserStatusResponse);
    }
  }

  /**
   * @param $error
   */
  public function setError($error) {
    $this->error = $error;
  }

  public function getError() {
    return $this->error;
  }

  /**
   * @param $userId
   */
  public function setUserId($userId) {
    $this->userId = $userId;
  }

  public function getUserId() {
    return $this->userId;
  }

  /**
   * @param $response
   */
  public function setResponse($response) {
    $this->response = $response;
  }

  public function getResponse() {
    return $this->response;
  }

  /**
   * @param $response
   */
  private function _parseResponse($response) {
    if (isset($response->userId)) {
      $this->setUserId($response->userId->{'$'});
    }

    if (isset($response->userStatus)) {
      $this->setResponse($this->parseFields($response->userStatus));
    }
  }

  /**
   * @param $object
   * @return array
   */
  private function parseFields($object) {
    if (is_object($object)) {
      $object = (array)$object;
    }
    if (is_array($object)) {
      $arr = array();
      foreach ($object as $key => $val) {
        if ($key !== '@') {
          if ($key === '$') {
            $arr = $this->parseFields($val);
          }
          else {
            $arr[$key] = $this->parseFields($val);
          }
        }
      }
    }
    else {
      $arr = $object;
    }
    return $arr;
  }
}