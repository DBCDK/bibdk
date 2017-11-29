<?php

/**
 *
 * @file
 * define a request for heimdal library login
 */

class bibdkHeimdalCurl extends MicroCURL {
  /**
   * Get a token from access platform
   *
   * @return bool|string
   */
  public function getAccessToken() {
    $config = variable_get('ding_wayf', NULL);

    $token_client_secret = $config['clientsecret'];
    $token_client_ID = $config['clientid'];
    $token_platform = $config['clientplatform'];
    $token_post_data = 'grant_type=password&username=@&password=@';
    $this->set_authentication($token_client_ID, $token_client_secret);
    $this->set_post($token_post_data);
    $this->set_url($token_platform);
    $this->set_option(CURLOPT_RETURNTRANSFER, TRUE);
    $this->set_option(CURLOPT_HTTPHEADER, array('Content-Type: application/x-www-form-urlencoded'));
    $heimdal_token_attributes = $this->get();

    if ($this->checkMe()) {
      return $this->parseToken($heimdal_token_attributes);
    }
    else {
      return FALSE;
    }
  }

  public function __destruct() {
    $this->close();
  }

  /**
   * Overwrite parent::get .. mainly to do some logging
   *
   * @param bool $urls
   * @return string
   */
  public function get($urls = FALSE) {
    $response = parent::get($urls);
    // @TODO some logging
    return $response;
  }

  /**
   * Do a request for attributes and parse response into an array
   *
   * @param $clientId
   * @param $token
   * @return array | bool
   *   Json response parsed into an array or empty array if
   *   something goes wrong
   */
  public function getAttributes($clientId, $token) {
    $ticketLink = $this->getTicketLink($clientId, $token);
    $response = $this->get($ticketLink);
    if ($this->checkMe()) {
      $attributes = json_decode($response, true);
      if (empty($attributes)) {
        return array();
      }
      return $attributes;
    }
    return FALSE;
  }


  /**
   * Get a link to heimdal access platform to retrive attributes associated
   * with given clientId and taken
   * @param $clientId
   * @param $token
   * @return string
   */
  private function getTicketLink($clientId, $token) {
    $config = variable_get('ding_wayf', NULL);
    $ticket_link = $config['hosturl'] . '/getTicket/' . $token . '/' . $clientId;
    return $ticket_link;
  }

  /**
   * Check status of given status array from parent class (@see MicroCURL::get_status()).
   * @param array $curlStatus
   * @return bool
   */
  private function checkMe() {
    $curlStatus = $this->get_status();
    // check for httpcode
    $flag = TRUE;
    if ($curlStatus['http_code'] !== 200) {
      watchdog('HEIMDAL', 'url: @url returned: @code', array('@url' => $curlStatus['url'], '@code' => $curlStatus['http_code']), WATCHDOG_ERROR);
      $flag = FALSE;
    }
    // @TODO more checks

    return $flag;
  }

  /**
   * Get token key from attributes
   *
   * @param string $token_attributes , $attribute_name default = 'access_token'
   * @return string|bool
   *
   *  * attribute example:
   * {
   * "token_type": "bearer",
   * "access_token": "40cddc1d15798122519ce435ddf65352b3a3eb8c",
   * "expires_in": 2592000
   * }
   *
   */
  private function parseToken($token_attributes) {
    if (!empty($token_attributes)) {
      $result = json_decode($token_attributes);
      if (!empty($result->access_token)) {
        $new_token = $result->access_token;
        return $new_token;
      }
    }
    return FALSE;
  }
}
