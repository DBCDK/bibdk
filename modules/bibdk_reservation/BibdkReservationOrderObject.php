<?php

class BibdkReservationOrderObject {

  private $branchId;
  private $branch;
  private $favourites;
  private $favourite;
  private $manifestationIds = array();
  private $subtypeOrder;
  private $subtypeOrderIds = array();
  private $manifestation;
  private $userData;
  private $userOrderData;
  private $fields;
  private $needBeforeDate;
  private $orderParameters;
  private $orderId;
  private $agency;
  private $sbKopi;
  private $articleDirect;
  private $sbKopiUser;
  

  public function getSbKopiUser() {
    return $this->sbKopiUser;
  }

  public function setSbKopiUser($value) {
    $this->sbKopiUser = $value;
    return $this;
  }

  public function getArticleDirect() {
    return $this->articleDirect;
  }

  public function setArticleDirect($value) {
    $this->articleDirect = $value;
    return $this;
  }

  public function getSbKopi() {
    return $this->sbKopi;
  }

  public function setSbKopi($value) {
    $this->sbKopi = $value;
    return $this;
  }

  public function getOrderId() {
    return $this->orderId;
  }

  public function setOrderId($orderId) {
    $this->orderId = $orderId;
    return $this;
  }

  public function setManifestationIds($ids) {
    $this->manifestationIds = $ids;
    return $this;
  }

  public function getManifestationIds() {
    return $this->manifestationIds;
  }

  public function setSubtypeOrderIds($ids) {
    $this->subtypeOrderIds = $ids;
    return $this;
  }

  public function getSubtypeOrderIds() {
    return $this->subtypeOrderIds;
  }

  public function setSubtypeOrder($bool) {
    $this->subtypeOrder = $bool;
    return $this;
  }

  public function getSubtypeOrder() {
    return $this->subtypeOrder;
  }

  public function setManifestation($manifestation) {
    $this->manifestation = $manifestation;
    return $this;
  }

  public function setWork($work) {
    $this->work = $work;
    return $this;
  }

  /**
   * @return Manifestation
   */
  public function getManifestation() {
    $parm = $this->work->getManifestations();
    return reset($parm);
  }

  public function getwork() {
    return $this->work;
  }

  public function setBranchId($id) {
    $this->branchId = "DK-" . $id;
    return $this;
  }

  public function getBranchId() {
    return $this->branchId;
  }

  public function setBranch($branch) {
    $this->branch = $branch;
    $this->setBranchId($branch->branchId);
    $this->agency = new TingAgency($branch->branchId);
    return $this;
  }

  public function setFavourite(FavouriteAgency $favourite) {
    $this->favourite = serialize($favourite);
    $branch = $favourite->getBranch();
    if($branch) {
      $this->setBranch($branch);
    }
    return $this;
  }

  public function getFavourite() {
    return unserialize($this->favourite);
  }

  /**
   * @return TingAgency
   */
  public function getAgency() {
    return $this->agency;
  }

  /**
   * @return TingClientAgencyBranch
   */
  public function getBranch() {
    return $this->branch;
  }

  public function getFavourites() {
    $ret = array();
    if (is_array($this->favourites)) {
      foreach ($this->favourites as $bibnr => $favourite) {
        $ret[$bibnr] = unserialize($favourite);
      }
    }

    return $ret;
  }

  public function setFavourites($favourites) {
    $this->favourites = $favourites;
    return $this;
  }

  public function setUserData($userData) {
    $this->userData = $userData;
    return $this;
  }

  public function getUserData() {
    return $this->userData;
  }

  public function setUserOrderData($userOrderData) {
    $this->userOrderData = $userOrderData;
    return $this;
  }

  public function getUserOrderData() {
    return $this->userOrderData;
  }

  public function setNeedBeforeDate($needBeforeDate) {
    $this->needBeforeDate = $needBeforeDate;
    return $this;
  }

  public function getNeedBeforDate() {
    return $this->needBeforeDate;
  }

  public function getOrderParameters() {
    return $this->orderParameters;
  }

  public function setOrderParameters($orderParameters) {
    $this->orderParameters = $orderParameters;
    return $this;
  }

  public function setFields($fields) {
    $this->fields = $fields;
    return $this;
  }

  /**
   * @return AgencyFields
   */
  public function getFields() {
    return $this->fields;
  }

  public static function reset() {
    if (isset($_SESSION['orderobject'])) {
      unset($_SESSION['orderobject']);
    }
  }

  /**
   * @return BibdkReservationOrderObject
   */
  public static function GetObject() {
    if (!isset($_SESSION['orderobject'])) {
      self::SetObject();
    }

    return $_SESSION['orderobject'];
  }

  /**
   * @return BibdkReservationOrderObject
   */
  private static function SetObject() {
    if (!isset($_SESSION['orderobject'])) {
      $_SESSION['orderobject'] = new BibdkReservationOrderObject();
    }

    return $_SESSION['orderobject'];
  }
}
