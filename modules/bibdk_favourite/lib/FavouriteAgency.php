<?php

require_once module_load_include('inc', 'vip_core', '/includes/VipCoreFindLibrary');

class FavouriteAgency extends VipCoreFindLibrary {

  public $userData;
  public $orderAgency;
  public $branch;

  /**
   * FavouriteAgency constructor.
   * @param stdClass $favourite
   * @param null|VipCoreFindLibrary $vipCoreAgencyBranch
   * @throws \GuzzleHttp\Exception\GuzzleException
   */
  public function __construct($favourite, $vipCoreAgencyBranch = null) {
    if (!isset($favourite['oui:agencyId'])) {
      return;
    }

    parent::__construct(NULL);

    $userData = unserialize($favourite['oui:userData']);

    $this->userData = (FALSE === $userData) ? $favourite['oui:userData'] : $userData;
    $this->orderAgency = ($favourite['oui:orderAgency'] == 'TRUE');
    $this->agencyId = $favourite['oui:agencyId'];
    // If $vipCoreAgencyBranch is an array - there has been an error somewhere.
    if (!is_null($vipCoreAgencyBranch) && !is_array($vipCoreAgencyBranch)) {
      $this->branch = $vipCoreAgencyBranch->getBranch();
    } else {
      watchdog(
        'bibdk_favourite',
        '@agency does not exist. Clean up OpenUserInfo',
        array('@agency' => $this->agencyId),
        WATCHDOG_WARNING
      );
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
      return new VipCoreFindLibrary($this->branch);
    }
    return NULL;
  }

  /**
   * Return the favourite agency id
   *
   * @return string|null
   */
  public function getAgencyId() {
    return $this->agencyId ?? NULL;
  }

  public function setAgencyId($agencyId) {
    $this->branch->agencyId = $agencyId;
  }

  /**
   * Get local lookup url for looking up
   * records in local library system.
   *
   * @return string|NULL
   */
  public function getMainAgencyId() {
    return (isset($this->branch->agencyId) ? $this->branch->agencyId : NULL);
  }

  /**
   * @return bool
   */
  public function getOrderAgency() {
    return $this->orderAgency;
  }

  /**
   * @return mixed
   */
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

  /**
   * @return false|mixed
   */
  public function getPinCode() {
    return $this->userData['pincode'] ?? FALSE;
  }

  /**
   * Retrieve the status of the user. This also includes loans and reservations.
   * Therefore we need an expiration date.
   *
   * @return array|false|mixed
   */
  public function getUserStatus() {
    // check if userstatus is already in $_SESSION and that it hasn't expired.
    if (isset($_SESSION['userStatus'])) {
      if (isset($_SESSION['userStatus'][$this->getAgencyId()])) {
        $expired = ($_SESSION['userStatus'][$this->getAgencyId()]['expires']) ?? NULL;
        if (!is_null($expired) && $expired > time()) {
          return $_SESSION['userStatus'][$this->getAgencyId()];
        }
      }
    }

    if (module_exists('ting_openuserstatus')) {
      // get parameters
      $userId = $this->getUserId();
      $userPincode = $this->getPinCode();
      $libraryCode = $this->getAgencyId();

      // get userstatus from webservice
      $response = ting_openuserstatus_do_userstatus($userId, $userPincode, $libraryCode);
      if (isset($response['error'])) {
        return $response;
      }
      // no errors found. add response to $_SESSION
      $_SESSION['userStatus'][$this->getAgencyId()] = $response;
      // We need to set an expiration time for the user data.
      $session_durability = (int)variable_get('userstatusExpires', 600);
      $_SESSION['userStatus'][$this->getAgencyId()]['expires'] = (time() + $session_durability);
      // last check
      return $_SESSION['userStatus'][$this->getAgencyId()] ?? FALSE;
    }
    // cannot retrieve userstatus
    return FALSE;
  }

  /**
   * @param array $orders
   *
   * @return array|false
   */
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
   * @throws \Exception
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
