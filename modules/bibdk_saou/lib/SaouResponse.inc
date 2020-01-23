<?php

/**
 * @file
 *
 * Class to handle response from saou webservice.
 * Basically you get two kinds of responses
 *
 * Either yóu get <responseCode>OK_NO_LICENSES</responseCode> which means
 * that SAOU has no licenses
 *
 * Or you get <Licenses> which means that one or more licenses are returned.
 *
 */
class SaouResponse {

  private $response;
  private $License;
  private $errorCode;

  /** Constructor
   * @param stdClass $response ; Response from SAOU webservice
   */
  public function __construct(stdClass $response) {
    $this->response = $response;
    $this->errorCode = isset($response->Licenses->ResponseStatus->responseCode) ? $response->Licenses->ResponseStatus->responseCode : NULL;
  }

  /**
   * Get the response
   * @return stdClass
   */
  public function get_response() {
    return $this->response;
  }

  /**
   * Get info for licenses, and set private member License
   * @return mixed; array licenseinfo if licenses are found; FALSE if not
   */
  public function getlicenseInfo() {
    if (!isset($this->response->Licenses)) {
      return FALSE;
    }

    // there might be more than one license
    if (isset($this->response->Licenses->License)) {
      if (is_array($this->response->Licenses->License)) {
        // use the first license found
        $this->License = current($this->response->Licenses->License);
      }
      else {
        $this->License = isset($this->response->Licenses->License) ? $this->response->Licenses->License : FALSE;
      }
    }
    // check if licenseinfo is set
    return isset($this->License->licenseInfo) ? $this->License->licenseInfo : FALSE;
  }

  /**
   * Get ipAccess for license
   * @return bool
   */
  public function get_ipAccess() {
    return isset($this->License->licenseInfo->ipAccess) ? $this->License->licenseInfo->ipAccess : FALSE;
  }

  /**
   * Get remote user access
   * @return mixed; BOOL if license is given; NULL if not
   */
  public function get_remoteUserAccess() {
    return isset($this->getlicenseInfo()->remoteUserAccess) ? $this->getlicenseInfo()->remoteUserAccess : NULL;
  }

  /**
   * Get link to ressource
   * @return mixed; string link if set; FALSE if not
   */
  public function get_link() {
    return isset($this->License->linkResponseType->link) ? $this->License->linkResponseType->link : FALSE;
  }

  /**
   * Get proxy link to ressource
   * @return mixed; string proxyurl if given; FALSE if not
   */
  public function get_proxyLink() {
    return isset($this->License->linkResponseType->proxyLink) ? $this->License->linkResponseType->proxyLink : FALSE;
  }

  /**
   * Get the repoonse code
   * @return string
   */
  public function get_responseCode() {
    return 'bibdk_saou_' . $this->errorCode;
  }
}