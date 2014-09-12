<?php

/**
 * Class for mocking structure returned from webservice containing data of
 * loaned items, reservations and fiscal information.
 */
class AgencyMockObject {
  private $responseStructure = NULL;

  public function __construct($group, $element, $data) {
    $this->responseStructure = array($group => array($element => $data));
  }

  public function getResponse() {
    return $this->responseStructure;
  }
}

