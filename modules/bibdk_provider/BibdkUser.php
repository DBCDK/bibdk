<?php

/**
 * Singleton class for querying the Bibdk provider webservice.
 */
class BibdkClient {

  private static $instance;
  private static $service_url;
  private static $security_code;
  public static $enable_logging;

  /**
   * Private constructor so a static function must be call to create an instance of the class.
   */
  private function __construct() {
    self::$service_url = variable_get('bibdk_provider_webservice_url', '');
    self::$security_code = variable_get('bibdk_provider_security_code', '');
    self::$enable_logging = variable_get('bibdk_provider_enable_logging');

    if (empty(self::$service_url)) {
      if (self::$enable_logging) {
        watchdog('bibdk_provider', t('Provider url is not set'), array(), WATCHDOG_ERROR, l(t('Set provider url'), 'admin/config/ding/provider/bibdk_provider'));
      }
    }

    if (empty(self::$security_code)) {
      // somehow bibdk_provider security code is not set - FATAL
      if (self::$enable_logging) {
        watchdog('bibdk_provider', t('Security code is not set'), array(), WATCHDOG_ERROR, l(t('Set securitycode'), 'admin/config/ding/provider/bibdk_provider'));
      }
    }
  }

  /**
   * Request function for querying the webservice.
   *
   * @param $action string The request type as a string.
   * @param $params Array containing the structure of the request.
   *
   * @return bool|string The response which is an XML string.
   */
  public static function request($action, $params) {
    if (!isset(self::$instance)) {
      self::$instance = new BibdkClient();
    }

    if (!is_array($params)) {
      return FALSE;
    }

    $request = array();

    // Nanosoap does an htmlspecialchars + this function does not support deep arrays
    /*foreach ($params as $key => $value) {
      $request['oui:' . $key] = htmlspecialchars($value);
    }*/

    // add securitycode
    if (isset(self::$security_code)) {
      $params['oui:' . 'securityCode'] = htmlspecialchars(self::$security_code);
    }

    $nano = new NanoSOAPClient(self::$service_url, array('namespaces' => array('oui' => 'http://oss.dbc.dk/ns/openuserinfo')));

    if ($simpletest_prefix = drupal_valid_test_ua()) {
      NanoSOAPClient::setUserAgent(drupal_generate_test_ua($simpletest_prefix));
    }

    $ret = $nano->call('oui:' . $action, $params);
    if (self::$enable_logging) {
      watchdog('bibdk_provider', 'BIBDK client completed request: %xml', array('%xml' => $nano->requestBodyString), WATCHDOG_INFO);
    }
    return $ret;
  }

}

/**
 * A wrapper class for calls to the Bibdk provider webservice.
 *
 * This is a singleton class.
 */
class BibdkUser {

  private static $instance;
  /** @var  DOMXPath $xpath */
  private $xpath;

  /**
   * Private constructor so a static function must be call to create an instance of the class.
   */
  private function __construct() {
  }

  /**
   * Function to get a BibdkUser object.
   *
   * @return object Singleton BibdkUser object.
   */
  public static function instance() {
    if (!isset(self::$instance)) {
      self::$instance = new BibdkUser();
    }

    return self::$instance;
  }

  /**
   * Create a DomXPATH object for parsing XML.
   *
   * @param $xml String containing XML.
   *
   * @return Boolean indicating if DomXPATH object is created.
   */
  private function set_xpath($xml) {
    $dom = new DomDocument();
    if (!@$dom->loadXML($xml)) {
      if (BibdkClient::$enable_logging) {
        watchdog('bibdk_provider', t('BIBDK client could not load response: %xml', array('%xml' => var_export($xml, TRUE))), array(), WATCHDOG_ERROR);
      }
      return FALSE;
    }
    $this->xpath = new DomXPATH($dom);
    $this->xpath->registerNamespace('oui', 'http://oss.dbc.dk/ns/openuserinfo');
    return TRUE;
  }

  /**
   * Function which hands the request to the BibdkClient.
   *
   * @param $action string The request type as a string.
   * @param $params array structure representing the request parameters.
   * @return string Response from BibdkClient as xml string.
   */
  private function makeRequest($action, $params) {
    return BibdkClient::request($action, $params);
  }

  /**
   * Function which parses the response.
   *
   * @param $xmlstring string The reponse as a xml string.
   * @param $xmltag string Which XPath element should extracted from the response.
   *
   * @return DomNode|bool FALSE if the xpath can't be set otherwise value of the xmltag
   */
  private function responseExtractor($xmlstring, $xmltag) {
    if (!@$this->set_xpath($xmlstring)) {
      return FALSE;
    }
    $pos = strpos($xmltag, 'oui:');
    if ($pos === FALSE) {
      $xmltag = 'oui:' . $xmltag;
    }
    $query = '//' . $xmltag;

    $tagcontent = $this->xpath->query($query);

    if ($tagcontent->item(0)) {
      return $tagcontent->item(0)->firstChild;
    }
    else {
      return FALSE;
    }
  }

  /************** CULR *********************/

  /**
   * Create an account on culr
   * @param string $userId
   * @param string $borrowerId
   * @param string $uidType
   * @return array
   */
  public function insertCulr($userId, $borrowerId, $uidType) {
    $params = array(
      'oui:userId' => $userId,
      'oui:borrowerId' => $borrowerId,
      'oui:uidType' => $uidType
    );

    $response = $this->makeRequest('insertCulrRequest', $params);

    $xmlmessage = $this->responseExtractor($response, 'insertCulrResponse');
    $ret = array('status' => 'error', 'response' => '');
    if ($xmlmessage->nodeName != 'oui:error') {
      $ret['status'] = TRUE;
      $ret['message'] = $response;
    }
    else {
      $ret['status'] = FALSE;
      $ret['message'] = $xmlmessage->nodeValue;
    }
    return $ret;
  }

  /************* END CULR ******************/


  /************** VOXB *********************/

  public function verifyVoxb($voxbid) {
    $params = array('oui:voxbId' => $voxbid);
    $response = $this->makeRequest('verifyVoxbRequest', $params);

    $xmlmessage = $this->responseExtractor($response, 'verifyVoxbResponse');

    if ($xmlmessage != FALSE && $xmlmessage->nodeName == 'oui:userId') {
      return $xmlmessage->nodeValue;
    }
    else {
      return FALSE;
    }
  }

  public function getVoxbId($username) {
    static $response;
    $params = array('oui:userId' => $username);
    $response = $this->makeRequest('getVoxbRequest', $params);

    return $response;
  }

  public function bindVoxb($username, $voxb_id) {
    static $response;
    $params = array(
      'oui:userId' => $username,
      'oui:voxbId' => $voxb_id,
    );

    $response = $this->makeRequest('bindVoxbRequest', $params);
    return $response;
  }

  /*********** END VOXB **********************/

  /*   * **************  USERSETTING(S) ************** */

  /** \brief get usersetting(s) for a given user. Empty $settingType gives all setting(s) for user
   * @staticvar type $response
   * @param $username string
   * @param $settingtype
   * @return string xml
   */
  public function getUserSetting($username, $settingtype) {
    static $response;
    $params = array(
      'oui:userId' => $username,
      'oui:settingType' => $settingtype
    );
    $response = $this->makeRequest('getSettingRequest', $params);

    return $response;
  }

  /**
   * Set usersetting for a given user. If settingtype don't exist it will be created with data from settingtypeString
   * @staticvar type $response
   * @param $username
   * @param $settingtype
   * @param $settingString
   * @return bool
   */
  public function setUserSetting($username, $settingtype, $settingString) {
    //make setting info
    $paramsSettings = array(
      'oui:settingType' => $settingtype,
      'oui:settingString' => $settingString
    );
    //make user array with settings information
    $params = array(
      'oui:userId' => $username,
      'oui:setting' => $paramsSettings
    );

    $response = $this->makeRequest('addSettingRequest', $params);
    $xmlmessage = $this->responseExtractor($response, 'addSettingResponse');
    if ($xmlmessage != FALSE && $xmlmessage->nodeName == 'oui:userId') {
      return TRUE;
    }
    else {
      return FALSE;
    }
  }

  /**
   * Delete an settingtype for a given user
   * @param string $username
   * @param $settingtype
   * @return bool
   */
  public function deleteSetting($username, $settingtype) {
    $params = array(
      'oui:userId' => $username,
      'oui:settingType' => $settingtype
    );
    $response = $this->makeRequest('removeSettingRequest', $params);
    $xmlmessage = $this->responseExtractor($response, 'removeSettingResponse');
    if ($xmlmessage != FALSE && $xmlmessage->nodeName == 'oui:userId') {
      return TRUE;
    }
    else {
      return FALSE;
    }
  }

  /*   * **************  FAVOURITES ************** */

  public function setFavourite($username, $agencyid, $encrypted = FALSE) {
    // Always force encryption on save.
    $params = array(
      'oui:userId' => $username,
      'oui:agencyId' => $agencyid,
      'oui:encrypted' => $encrypted,
    );
    $response = $this->makeRequest('setFavouriteRequest', $params);

    $xmlmessage = $this->responseExtractor($response, 'setFavouriteResponse');

    if ($xmlmessage != FALSE && $xmlmessage->nodeName == 'oui:userId') {
      return TRUE;
    }
    else {
      return FALSE;
    }
  }

  /**
   * Get all favourite agencies for a given user
   *
   * @param string $username
   * @param boolean $encrypted
   *   If we are getting encrypted data.
   *
   * @return string xml
   */
  public function getFavourites($username, $encrypted = FALSE) {
    $params = array(
      'oui:userId' => $username,
      'oui:encrypted' => $encrypted,
    );
    $response = $this->makeRequest('getFavouritesRequest', $params);

    return $response;
  }

  public function getCart($username) {
    static $ret;
    if (!empty($ret)) {
      return $ret;
    }

    $params = array('oui:userId' => $username);
    $response = $this->makeRequest('getCartRequest', $params);

    $xmlmessage = $this->responseExtractor($response, 'getCartResponse');

    $ret = array('status' => 'error', 'response' => '');
    if ($xmlmessage->nodeName != 'oui:error') {
      $ret['status'] = 'success';
      $ret['response'] = $response;
    }
    else {
      $ret['response'] = $xmlmessage->nodeValue;
    }
    return $ret;
  }

  /**
   * Get cart count from from webservice
   *
   * @param $username
   * @return array
   */
  public function getCartCount($username) {
    static $ret;
    $params = array('oui:userId' => $username);
    $response = $this->makeRequest('getCartCountRequest', $params);

    $xmlmessage = $this->responseExtractor($response, 'getCartCountResponse');

    $ret = array('status' => 'error', 'response' => '');
    if ($xmlmessage->nodeName != 'oui:error') {
      $ret['status'] = 'success';
      $ret['response'] = $response;
    }
    else {
      $ret['response'] = $xmlmessage->nodeValue;
    }

    return $ret;
  }

  public function addCartContent($username, $content) {
    static $response;
    $params = array(
      'oui:userId' => $username,
      'oui:cartContent' => $content
    );
    $response = $this->makeRequest('addCartContentRequest', $params);
    $xmlmessage = $this->responseExtractor($response, 'addCartContentResponse');

    $ret = array('status' => 'error', 'response' => '');

    if ($xmlmessage->nodeName != 'oui:error') {
      $ret['status'] = 'success';
      $ret['response'] = $response;
    }
    else {
      $ret['response'] = $xmlmessage->nodeValue;
    }
    return $ret;
  }

  public function updateCartContent($username, $content) {
    static $response;
    $params = array(
      'oui:userId' => $username,
      'oui:cartContent' => $content
    );
    $response = $this->makeRequest('updateCartContentRequest', $params);
    $xmlmessage = $this->responseExtractor($response, 'updateCartContentResponse');

    $ret = array('status' => 'error', 'response' => '');

    if ($xmlmessage->nodeName != 'oui:error') {
      $ret['status'] = 'success';
      $ret['response'] = $response;
    }
    else {
      $ret['response'] = $xmlmessage->nodeValue;
    }
    return $ret;
  }

  public function removeCartContent($username, $content) {
    static $response;
    $params = array(
      'oui:userId' => $username,
      'oui:cartContent' => $content,
    );
    $response = $this->makeRequest('removeCartContentRequest', $params);

    $xmlmessage = $this->responseExtractor($response, 'removeCartContentResponse');

    $ret = array('status' => 'error', 'response' => '');

    if ($xmlmessage->nodeName != 'oui:error') {
      $ret['status'] = 'success';
      $ret['response'] = $response;
    }
    else {
      $ret['response'] = $xmlmessage->nodeValue;
    }
    return $ret;
  }

  /** Get searchhistory for user
   * @param $username
   * @return array
   */
  public function getSearchHistory($username) {
    static $response;
    $params = array('oui:userId' => $username);
    $response = $this->makeRequest('getSearchHistoryRequest', $params);
    $xmlmessage = $this->responseExtractor($response, 'getSearchHistoryResponse');

    $ret = array('status' => 'error', 'response' => '');
    if ($xmlmessage->nodeName != 'oui:error') {
      $ret['status'] = 'success';
      $ret['response'] = $response;
    }
    else {
      $ret['response'] = $xmlmessage->nodeValue;
    }
    return $ret;
  }

  /**v Add search history element to user
   * @param $username
   * @param $content
   * @return array
   */
  public function addSearchHistory($username, $content) {
    static $response;
    $params = array(
      'oui:userId' => $username,
      'oui:searchHistory' => $content
    );

    $response = $this->makeRequest('addSearchHistoryRequest', $params);
    $xmlmessage = $this->responseExtractor($response, 'addSearchHistoryResponse');

    $ret = array('status' => 'error', 'response' => '');

    if ($xmlmessage->nodeName != 'oui:error') {
      $ret['status'] = 'success';
      $ret['response'] = $response;
    }
    else {
      $ret['response'] = $xmlmessage->nodeValue;
    }
    return $ret;
  }

  /** Remove Search History element
   * @param $username
   * @param $content
   * @return array
   */
  public function removeSearchHistory($username, $content) {
    static $response;
    $params = array(
      'oui:userId' => $username,
      'oui:searchHistory' => $content,
    );
    $response = $this->makeRequest('removeSearchHistoryRequest', $params);
    $xmlmessage = $this->responseExtractor($response, 'removeSearchHistoryResponse');

    $ret = array('status' => 'error', 'response' => '');

    if ($xmlmessage->nodeName != 'oui:error') {
      $ret['status'] = 'success';
      $ret['response'] = $response;
    }
    else {
      $ret['response'] = $xmlmessage->nodeValue;
    }
    return $ret;
  }

  /**
   * \brief add an agency to favourites for given user
   * @param string $username
   * @param string $agencyid
   * @param bool $encrypted
   * @return array
   */
  public function addFavourite($username, $agencyid, $encrypted = FALSE) {
    // Always force encryption on save.
    $params = array(
      'oui:userId' => $username,
      'oui:agencyId' => $agencyid,
      'oui:encrypted' => $encrypted,
    );

    $response = $this->makeRequest('addFavouriteRequest', $params);

    $xmlmessage = $this->responseExtractor($response, 'addFavouriteResponse');

    $ret = array('status' => 'error', 'response' => '');
    if (!isset($xmlmessage->nodeName) || $xmlmessage->nodeName != 'oui:error') {
      $ret['status'] = 'success';
      $ret['response'] = $response;
    }
    else {
      $ret['response'] = $xmlmessage->nodeValue;
    }
    return $ret;
  }

  /**
   * Delete an agency on a given user.
   *
   * @param string $username
   *   The ID of the user to delete the agency for.
   * @param string $agencyid
   *   The ID of the agency to delete.
   * @param boolean $encrypted
   *   If deleting agency from encrypted table or not.
   *
   * @return bool
   */
  public function deleteFavourite($username, $agencyid, $encrypted = FALSE) {
    $params = array(
      'oui:userId' => $username,
      'oui:agencyId' => $agencyid,
      'oui:encrypted' => $encrypted
    );
    $response = $this->makeRequest('deleteFavouriteRequest', $params);

    $xmlmessage = $this->responseExtractor($response, 'deleteFavouriteResponse');

    if ($xmlmessage != FALSE && $xmlmessage->nodeName == 'oui:userId') {
      return TRUE;
    }
    else {
      return FALSE;
    }
  }

  /**
   * Save an agency on a given user.
   *
   * @param string $name
   * @param string $agencyid
   * @param string $data
   * @param false $encrypted
   *
   * @return bool|string
   */
  public function saveFavouriteData($name, $agencyid, $data, $encrypted = FALSE) {
    if ($encrypted) {
      $data = bibdk_provider_encrypt_data($data);
    }
    // Force all data saved to be encrypted.
    $params = array(
      'oui:userId' => $name,
      'oui:agencyId' => $agencyid,
      'oui:favouriteData' => $data,
      'oui:encrypted' => $encrypted,
    );
    return $this->makeRequest('setFavouriteDataRequest', $params);
  }

  /**
   * Get the status of the GDPR consent
   *
   * @param string $name
   *   The ID of users, actually their name but we call it name for consistency.
   *
   * @return bool
   *   True of user is given consent, false otherwise.
   */
  public function getGdprConsent($name) {
    $params = array('oui:userId' => $name);
    $response = $this->makeRequest('getGdprConsentRequest', $params);
    $element = $this->responseExtractor($response, 'getGdprConsentResponse');
    return (bool) $element->nodeValue;
  }

  /**
   * Set the status of the GDPR consent
   *
   * @param string $name
   *   The ID of users, actually their name but we call it name for consistency.
   *
   * @return bool
   *   True if user gave consent, false otherwise.
   */
  public function setGdprConsent($name, $consent) {
    $params = array('oui:userId' => $name, 'oui:consent' => $consent);
    $response = $this->makeRequest('setGdprConsentRequest', $params);
    $element = $this->responseExtractor($response, 'setGdprConsentResponse');
    return (bool) $element->nodeValue;
  }

  /**
   * Function to logging in a user.
   *
   * @param $name
   *   Username (e-mail address).
   * @param $pass
   *   Password for the user.
   *
   * @return bool Boolean telling if the login attempt was successful.
   */
  public function login($name, $pass) {
    $params = array(
      'oui:userId' => $name,
      'oui:userPinCode' => $pass,
      'oui:outputType' => 'xml',
    );
    $response = $this->makeRequest('loginRequest', $params);
    $xmlmessage = $this->responseExtractor($response, 'loginResponse');

    if ($xmlmessage != FALSE && $xmlmessage->nodeName == 'oui:userId') {
      return TRUE;
    }
    else {
      return FALSE;
    }
  }

  /**
   * Function for creating a new user
   *
   * @param $name
   *   E-mail address which is used as username.
   * @param $pass
   *   Password for the user.
   *
   * @return bool
   *   Boolean telling whether the user was created or not.
   */
  public function create($name, $pass) {
    $params = array(
      'oui:userId' => $name,
      'oui:userPinCode' => $pass,
      'oui:outputType' => 'xml',
    );
    $response = $this->makeRequest('createUserRequest', $params);

    $xmlmessage = $this->responseExtractor($response, 'createUserResponse');

    return ($xmlmessage != FALSE && $xmlmessage->nodeName == 'oui:userId');
  }

  /**
   * Function to check if the username already exists.
   *
   * @param $name
   *   E-mail address which is used as username.
   *
   * @return
   *   Boolean telling if the user already exists.
   */
  public function verify($name) {
    $response = array();

    if (empty($response[$name])) {
      $params = array(
        'oui:userId' => $name,
        'oui:outputType' => 'xml',
      );
      $response[$name] = $this->makeRequest('verifyUserRequest', $params);
    }

    $xmlmessage = $this->responseExtractor($response[$name], 'verifyUserResponse');

    if ($xmlmessage != FALSE && $xmlmessage->nodeName == 'oui:verified') {
      return preg_match('/true/i', $xmlmessage->nodeValue);
    }
    else {
      return FALSE;
    }
  }

  /**
   * Function to update password.
   *
   * @param $name
   *   Username for which the password is changed.
   * @param $pass
   *   New password for the user.
   *
   * @return
   *   Boolean telling if the change of password succeed.
   */
  public function update_password($name, $pass) {
    $params = array(
      'oui:userId' => $name,
      'oui:userPinCode' => $pass,
      'oui:outputType' => 'xml',
    );
    $response = $this->makeRequest('updatePasswordRequest', $params);
    $xmlmessage = $this->responseExtractor($response, 'updatePasswordResponse');

    if ($xmlmessage != FALSE && $xmlmessage->nodeName == 'oui:userId') {
      return TRUE;
    }
    else {
      return FALSE;
    }
  }

  /**
   * Function to delete a user.
   *
   * @param $name
   *   Username which should be deleted.
   * @param $pass
   *   Password for the user.
   *
   * @return
   *   Boolean telling if the deletion was successful.
   */
  public function delete($name) {
    $params = array(
      'oui:userId' => $name,
      'oui:outputType' => 'xml',
    );
    $response = $this->makeRequest('deleteUserRequest', $params);
    $xmlmessage = $this->responseExtractor($response, 'deleteUserResponse');

    if ($xmlmessage != FALSE && $xmlmessage->nodeName == 'oui:userId') {
      return TRUE;
    }
    else {
      return FALSE;
    }
  }

  /**
   * Function to delete the user on culr. Creation of user on culr is handled from
   * the provider (OpenUserInfo) - thus deletion of the user should be handled
   * likewise.
   *
   * @param string $name
   *
   * @return bool
   * @throws \Exception
   */
  public function deleteCulrUser($name) {
    $params = array(
      'oui:userId' => $name,
      'oui:outputType' => 'xml',
    );
    $response = $this->makeRequest('deleteCulrRequest', $params);
    $xmlmessage = $this->responseExtractor($response, 'deleteCulrUserResponse');

    if($xmlmessage === FALSE){
      return FALSE;
    }

    if ($xmlmessage !== FALSE && $xmlmessage->nodeName == 'oui:userId') {
      return TRUE;
    }
    else {
      if ($xmlmessage->nodeName == 'oui:error') {
        throw new Exception($xmlmessage->nodeValue);
      }
      else {
        return FALSE;
      }
    }
  }

  /** Verify user with wayfid exists
   *
   * @param string $wayfId
   * @param string $loginType
   * @return false|string userid(string) if user exists, FALSE if not
   * @throws Exception
   */
  public function verifyWayf($wayfId, $loginType) {
    $params = array(
      'oui:loginType' => $loginType,
      'oui:loginId' => $wayfId,
      'oui:outputType' => 'xml',
    );
    $response = $this->makeRequest('verifyWayfRequest', $params);
    $xmlmessage = $this->responseExtractor($response, 'verifyWayfResponse');

    if ($xmlmessage != FALSE && $xmlmessage->nodeName == 'oui:userId') {
      return $xmlmessage->nodeValue;
    }
    else {
      if ($xmlmessage->nodeName == 'oui:error') {
        throw new Exception($xmlmessage->nodeValue);
      }
      else {
        return FALSE;
      }
    }
  }

  /**
   * Login using WAYF.
   *
   * Throws an exception if an error is return from the web service.
   *
   * @param $name
   *   Email address of the user.
   * @param $wayfId
   *   Unique id return by WAYF
   * @return boolean
   *   Indicates if operation was successful.
   * @throws Exception
   *   If web service returns an error.
   */
  public function loginWayf($name, $loginId, $loginType = 'wayf_id') {
    $params = array(
      'oui:userId' => $name,
      'oui:loginType' => $loginType,
      'oui:loginId' => $loginId,
      'oui:outputType' => 'xml',
    );
    $response = $this->makeRequest('loginWayfRequest', $params);
    $xmlmessage = $this->responseExtractor($response, 'loginWayfResponse');

    if ($xmlmessage != FALSE && $xmlmessage->nodeName == 'oui:userId') {
      return TRUE;
    }
    else {
      if ($xmlmessage->nodeName == 'oui:error') {
        throw new Exception($xmlmessage->nodeValue);
      }
      else {
        return FALSE;
      }
    }
  }

  /**
   * Binds WAYF id to a user.
   *
   * Old WAYF id will be overwritten.
   *
   * @param $name
   * @param $wayfId
   *   WAYF id of user.
   * @return boolean
   *   Indicates if operation was successful.
   * @throws Exception
   *   If web service returns an error.
   */
  public function bindWayf($name, $loginId, $loginType = 'wayf_id') {
    $params = array(
      'oui:userId' => $name,
      'oui:loginId' => $loginId,
      'oui:loginType' => $loginType,
      'oui:outputType' => 'xml',
    );
    $response = $this->makeRequest('bindWayfRequest', $params);
    $xmlmessage = $this->responseExtractor($response, 'bindWayfResponse');

    if ($xmlmessage != FALSE && $xmlmessage->nodeName == 'oui:userId') {
      return TRUE;
    }
    else {
      if ($xmlmessage->nodeName == 'oui:error') {
        throw new Exception($xmlmessage->nodeValue);
      }
      else {
        return FALSE;
      }
    }
  }

  /**
   * Deletes WAYF binding for a user.
   *
   * @param $name
   *   User who should have removed binding.
   * @return boolean
   *   Indicates if operation was successful.
   * @throws Exception
   *   If web service returns an error.
   */
  public function deleteWayf($name) {
    $params = array(
      'oui:userId' => $name,
      'oui:outputType' => 'xml',
    );
    $response = $this->makeRequest('deleteWayfRequest', $params);
    $xmlmessage = $this->responseExtractor($response, 'deleteWayfResponse');

    if ($xmlmessage != FALSE && $xmlmessage->nodeName == 'oui:userId') {
      return TRUE;
    }
    else {
      if ($xmlmessage->nodeName == 'oui:error') {
        throw new Exception($xmlmessage->nodeValue);
      }
      else {
        return FALSE;
      }
    }
  }
}
