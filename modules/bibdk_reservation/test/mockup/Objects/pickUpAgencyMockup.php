<?php

/**
 * Class PickUpAgencyMockup
 */
class PickUpAgencyMockup {

  private $ncipLookUpUser;
  private $userStatusUrl;

  /**
   * @param $ncipLookUpUser
   */
  public function setNcipLookUpUser($ncipLookUpUser) {
    $this->ncipLookUpUser = $ncipLookUpUser;
  }

  /**
   * @return mixed
   */
  public function getNcipLookUpUser() {
    return $this->ncipLookUpUser;
  }

  /**
   * @param $userStatusUrl
   */
  public function setUserStatusUrl($userStatusUrl) {
    $this->userStatusUrl = $userStatusUrl;
  }

  /**
   * @return mixed
   */
  public function getUserStatusUrl() {
    return $this->userStatusUrl;
  }
} 