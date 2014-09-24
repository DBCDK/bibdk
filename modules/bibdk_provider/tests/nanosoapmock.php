<?php

class NanoSOAPClient {

  private $request;
  private $requestType;
  public static $cart = 0;
  public static $cart_response_path;

  public function __construct($url) {

  }

  public function setUserAgent($useragent) {

  }

  private function soapEnveloping($bodyTag, $message) {
    return '<?xml version="1.0" encoding="utf-8"?>'
        . '<SOAP-ENV:Envelope xmlns:SOAP-ENV="http://schemas.xmlsoap.org/soap/envelope" xmlns:oui="http://oss.dbc.dk/ns/openuserinfo"><SOAP-ENV:Body>'
        . '<oui:' . $bodyTag . '>'
        . $message
        . '</oui:' . $bodyTag . '>'
        . '</SOAP-ENV:Body></SOAP-ENV:Envelope>';
  }

  private function soapFault() {
    return '<?xml version="1.0" encoding="utf-8"?><SOAP-ENV:Fault xmlns:SOAP-ENV="http://schemas.xmlsoap.org/soap/envelope"><faultcode>SOAP-ENV:Server</faultcode><faultstring>Incorrect SOAP envelope or wrong/unsupported request</faultstring></SOAP-ENV:Fault>';
  }

  public function call($requestType, $request) {
    $this->requestType = $requestType;
    $this->request = $request;

    list($dummy, $requestType) = explode(':', $requestType);
    return $this->$requestType($request);
  }

  public function getRequest() {
    return $this->request;
  }

  public function getAction() {
    return $this->requestType;
  }

  private function verifyUserRequest($request) {
    $userId = $request['oui:userId'];
    if (empty($userId)) {
      $response = '<oui:error>Missing</oui:error>';
    }
    else {
      if ($userId == 'validUser') {
        $response = '<oui:verified>true</oui:verified>';
      }
      else {
        $response = '<oui:verified>false</oui:verified>';
      }
    }
    debug($response);

    return $this->soapEnveloping('verifyUserResponse', $response);
  }

  private function loginRequest($request) {
    $userId = $request['oui:userId'];
    $password = $request['oui:userPinCode'];

    if (empty($userId) || empty($password)) {
      $response = '<oui:error>Missing</oui:error>';
    }
    else {
      if ($userId == 'validUser' && $password == '123456') {
        $response = "<oui:userId>$userId</oui:userId>";
      }
      else {
        $response = '<oui:error>Wrong userid or password</oui:error>';
      }
    }

    return $this->soapEnveloping('loginResponse', $response);
  }

  private function createUserRequest($request) {
    $userId = $request['oui:userId'];
    $password = $request['oui:userPinCode'];

    if (empty($userId) || empty($password)) {
      $response = '<oui:error>Missing</oui:error>';
    }
    else {
      if ($userId == 'createUser' && $password == '123456') {
        $response = "<oui:userId>$userId</oui:userId>";
      }
      else {
        $response = '<oui:error>user already exists</oui:error>';
      }
    }

    return $this->soapEnveloping('createUserResponse', $response);
  }

  private function updatePasswordRequest($request) {
    $userId = $request['oui:userId'];
    $password = $request['oui:userPinCode'];

    if (empty($userId) || empty($password)) {
      $response = '<oui:error>Missing</oui:error>';
    }
    else {
      if ($userId == 'updateUser') {
        $response = "<oui:userId>$userId</oui:userId>";
      }
      else {
        $response = '<oui:error>can\'t update user</oui:error>';
      }
    }

    return $this->soapEnveloping('updatePasswordResponse', $response);
  }

  private function deleteUserRequest($request) {
    $userId = $request['oui:userId'];

    if (empty($userId)) {
      $response = '<oui:error>Missing</oui:error>';
    }
    else {
      $response = "<oui:userId>$userId</oui:userId>";
    }

    return $this->soapEnveloping('deleteUserResponse', $response);
  }

  private function loginWayfRequest($request) {
    $userId = $request['oui:userId'];
    $wayfId = $request['oui:loginId'];

    if (empty($userId) || empty($wayfId)) {
      $response = '<oui:error>Missing</oui:error>';
    }
    else {
      if ($userId == 'validUser') {
        if ($wayfId == 'wayfid12345') {
          $response = "<oui:userId>$userId</oui:userId>";
        }
        else {
          $response = '<oui:error>no binding</oui:error>';
        }
      }
      elseif ($userId == 'noBindUser') {
        $response = '<oui:error>no binding</oui:error>';
      }
      else {
        $response = '<oui:error>no such user</oui:error>';
      }
    }

    return $this->soapEnveloping('loginWayfResponse', $response);
  }

  private function bindWayfRequest($request) {
    $userId = $request['oui:userId'];
    $wayfId = $request['oui:loginId'];

    if (empty($userId) || empty($wayfId)) {
      $response = '<oui:error>Missing</oui:error>';
    }
    else {
      if ($userId == 'validUser') {
        $response = "<oui:userId>$userId</oui:userId>";
      }
      else {
        $response = '<oui:error>no such user</oui:error>';
      }
    }

    return $this->soapEnveloping('bindWayfResponse', $response);
  }

  private function deleteWayfRequest($request) {
    $userId = $request['oui:userId'];

    if (empty($userId)) {
      $response = '<oui:error>Missing</oui:error>';
    }
    else {
      if ($userId == 'validUser') {
        $response = "<oui:userId>$userId</oui:userId>";
      }
      else if ($userId == 'invalidUser'){
        $response = '<oui:error>no such user</oui:error>';
      }
    }

    return $this->soapEnveloping('deleteWayfResponse', $response);
  }

  private function getCartRequest(){
    $path = self::$cart_response_path;
    if (self::$cart == 0)
      $response = file_get_contents($path.'/xml/get_cart_no_results.xml');
    else
      $response = file_get_contents($path.'/xml/get_cart_one_result.xml');
    return $this->soapEnveloping('getCartResponse', $response);
  }

  private function addCartContentRequest(){
    self::$cart++;
    $path = self::$cart_response_path;
    $response = file_get_contents($path.'/xml/add_cart_content_result.xml');
    return $this->soapEnveloping('addCartContentResponse', $response);
  }

  private function removeCartContentRequest(){
    self::$cart--;
    $path = self::$cart_response_path;
    $response = file_get_contents($path.'/xml/add_cart_content_result.xml');
    return $this->soapEnveloping('removeCartContentResponse', $response);
  }

}
