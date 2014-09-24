<?php

class FavouriteAgency extends TingAgency {

  public $userData;
  public $orderAgency;

  public function __construct($favourite) {
    if (!isset($favourite['oui:agencyId'])) {
      die('no agencyid in FavouriteAgency constructor');
    }
    parent::__construct($favourite['oui:agencyId']);
    $this->userData = isset($favourite['oui:userData']) ? unserialize($favourite['oui:userData']) : NULL;
    $this->orderAgency = ($favourite['oui:orderAgency'] == 'TRUE') ? TRUE : FALSE;
  }

  public function getOrderAgency() {
    return $this->orderAgency;
  }

  public function getUserData() {
    return $this->userData;
  }

  /** Get userid for favourite
   * 
   * There are a number of possible userids. Run through userdata and return
   * the first found
   * 
   * @return boolean 
   */
  public function getUserId() {
    $possibilities = array('cpr', 'userId', 'barcode', 'cardno', 'customId',);
    foreach ($possibilities as $pos) {
      if (isset($this->userData[$pos])) {
        return $this->userData[$pos];
      }
    }
    return FALSE;
  }

  public function getPinCode() {
    return isset($this->userData['pincode']) ? $this->userData['pincode'] : FALSE;
  }

  public function getUserStatus() {
    // check if userstatus is already in $_SESSION
    if (isset($_SESSION['userStatus'][$this->getAgencyId()])) {
      return $_SESSION['userStatus'][$this->getAgencyId()];
    }
    // get parameters
    $userId = $this->getUserId();
    $userPincode = $this->getPinCode();
    $libraryCode = $this->getAgencyId();

    if (module_exists('ting_openuserstatus')) {
      // get userstatus from webservice
      $response = ting_openuserstatus_do_userstatus($userId, $userPincode, $libraryCode);
      if (isset($response['error'])) {
        return $response;
      }
      // no errors found. add response to $_SESSION
      $_SESSION['userStatus'][$this->getAgencyId()] = $response;
      // last check
      return isset($_SESSION['userStatus'][$this->getAgencyId()]) ? $_SESSION['userStatus'][$this->getAgencyId()] : FALSE;
    }
    // cannot retrive userstatus
    return FALSE;
  }

  public function cancelOrder(array $orders) {
    $userId = $this->getUserId();
    $userPincode = $this->getPinCode();
    $libraryCode = $this->getAgencyId();

    if (module_exists('ting_openuserstatus')) {
      $response = ting_openuserstatus_do_cancelorder($userId, $userPincode, $libraryCode, $orders);
      if (empty($response['error'])) {
        // an order has been cancelled. clear userstatus to update
        $this->clearUserStatus();
      }
      return $response;
    }
    return FALSE;
  }

  public function updateOrder(array $updateOrders) {
    $userId = $this->getUserId();
    $userPincode = $this->getPinCode();
    $libraryCode = $this->getAgencyId();

    if (module_exists('ting_openuserstatus')) {
      $response = ting_openuserstatus_do_update_order($userId, $userPincode, $libraryCode, $updateOrders);
      if (empty($response['error'])) {
        // an order has been updated. clear userstatus to update
        $this->clearUserStatus();
      }
      return $response;
    }
    return FALSE;
  }

  public function renewLoan(array $loans) {
    $userId = $this->getUserId();
    $userPincode = $this->getPinCode();
    $libraryCode = $this->getAgencyId();
    if (module_exists('ting_openuserstatus')) {
      $response = ting_openuserstatus_do_renew_loan($userId, $userPincode, $libraryCode, $loans);
      if (empty($response['error'])) {
        // an order has been updated. clear userstatus to update
        $this->clearUserStatus();
      }
      return $this->parseFields($response);
    }
    return FALSE;
  }

  public function clearUserStatus() {
    global $drupal_test_info;
    if (isset($_SESSION['userStatus'][$this->getAgencyId()]) && !isset($drupal_test_info)) {
      unset($_SESSION['userStatus'][$this->getAgencyId()]);
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
