<?php

/**
 *
 * @file
 * define a request for heimdal library login
 *
 */

class bibdkHeimdalCurl extends MicroCURL {

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
  public function getAttributes($auth_code) {
    //exchange authorization code for access token
    $token = $this->getAccessToken($auth_code);
    if(empty($token)){
      return FALSE;
    }

    $token_as_json = json_decode($token);
    $bearer = $token_as_json->access_token;

    $attributes = $this->getUserInfo($bearer);
    if ($this->checkMe()) {
      $attributes = json_decode($attributes, true);
      if (empty($attributes)) {
        return array();
      }
      // all is well - set access_token (bearer) in SESSION for later use
      $_SESSION['heimdal']['access_token'] = $bearer;
      return $attributes;
    }
    return FALSE;
  }

  private function getUserInfo($bearer) {
    $config = variable_get('ding_wayf', NULL);
    $this->set_url($config['clientplatform'] . '/userinfo/');
    $this->set_option(CURLOPT_HTTPHEADER, array("Authorization: Bearer $bearer"));
    $attributes = $this->get();

    return $attributes;
  }


  /**
   * Get a link to heimdal access platform to retrive attributes associated
   * with given clientId and token
   * @param $clientId
   * @param $token
   * @return string
   */
  private function getAccessToken($auth_code) {
    $config = variable_get('ding_wayf', NULL);
    $client_secret = $config['clientsecret'];
    $client_id = $config['clientid'];

    $redirect_url = bibdkHeimdalHelpers::bibdk_heimdal_get_full_url('heimdal/login');

    $token_post_data = "grant_type=authorization_code&code=$auth_code&client_id=$client_id&client_secret=$client_secret&redirect_uri=$redirect_url";
    $this->set_post($token_post_data);
    $this->set_url($config['clientplatform'] . '/oauth/token');

    $this->set_option(CURLOPT_RETURNTRANSFER, TRUE);
    $this->set_option(CURLOPT_HTTPHEADER, array('Content-Type: application/x-www-form-urlencoded'));

    $response = $this->get();
    if($this->checkMe()){
      return $response;
    }
    return '';
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
