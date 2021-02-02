<?php

class FavouriteAgency extends VipCoreAgencyBranch {

  public $userData;
  public $orderAgency;

  protected $branch;

  /**
   * FavouriteAgency constructor.
   * @param $favourite
   * @param null|stdClass $findLibraryResponse
   * @throws \GuzzleHttp\Exception\GuzzleException
   */
  public function __construct($favourite, $findLibraryResponse = NULL) {
    if (!isset($favourite['oui:agencyId'])) {
      return;
    }

    $this->userData = isset($favourite['oui:userData']) ? unserialize($favourite['oui:userData']) : NULL;
    $this->orderAgency = ($favourite['oui:orderAgency'] == 'TRUE');
    $this->agencyId = $favourite['oui:agencyId'];

    if (is_null($findLibraryResponse)) {
      try {
        $response = vip_core_findlibrary($favourite['oui:agencyId']);
        return parent::__construct($response);
      } catch (Exception $e) {
        throw new Exception($e);
      }
    } else {
      return parent::__construct($findLibraryResponse->branch);
    }
  }

  /**
   * @param $branch
   */
  public function setBranch($branch) {
    $this->branch = $branch;
  }

  /**
   * @return null
   */
  public function getBranch() {

    if (!is_null($this->branch)) {
      return new VipCoreAgencyBranch($this->branch);
    }
    return NULL;
  }

  public function getAgencyId() {
    return $this->getMainAgencyId();
  }

  /**
   * Get local lookup url for looking up
   * records in local library system.
   *
   * @return string|NULL
   */
  public function getMainAgencyId() {
    return (isset($this->branch->agencyId) ? $this->branch->agencyId :
      (isset($this->branch->branch->agencyId) ? $this->branch->branch->agencyId : NULL));
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
        return str_replace("-","",$this->userData[$pos]);
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
   * @return null|string
   * @throws \TingClientAgencyBranchException
   * @throws \TingClientException
   */
  public function getRenewOrderAllowed() {
    $branch = $this->getBranch();
    if (isset($branch)) {
      return $branch->getNcipRenewOrder();
    }
  }


  /**
   * @param $object
   * @return array
   */
  private function parseFields($object) {
    if (is_object($object)) {
      $object = (array) $object;
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
