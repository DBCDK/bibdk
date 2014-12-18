<?php

/**
 * Created by IntelliJ IDEA.
 * User: pjo
 * Date: 2/17/14
 * Time: 1:23 PM
 */
class bibdkVoxbUser {

  private $userId;
  private $xp;
  private $userData;
  private $userInfo;

  public function __construct($voxb_id) {
    if (empty($voxb_id)) {
      throw new bibdkVoxbException('empty voxb_id');
    }
    $this->userId = $voxb_id;
  }

  public function getUserId() {
    return $this->userId;
  }

  public function userData() {
    if (!isset($this->userData)) {
      $response = open_voxb_fetchMyDataRequest($this->userId);
      // @TODO errorcheck
      $this->userData = $this->parseFetchMyDataResponse($response);
    }

    return $this->userData;
  }

  public function getAliasName() {
    $xp = $this->getUserInfo();
    if (empty($xp)) {
      return FALSE;
    }

    $query = '//voxb:aliasName';
    $nodelist = $xp->query($query);

    if ($nodelist->length != 1) {
      return FALSE;
    }

    return $nodelist->item(0)->nodeValue;
  }

  public function getUserIdentifierValue() {
    $xp = $this->getUserInfo();
    if (empty($xp)) {
      return FALSE;
    }

    $query = '//voxb:userIdentifierValue';
    $nodelist = $xp->query($query);

    if ($nodelist->length != 1) {
      return FALSE;
    }

    return $nodelist->item(0)->nodeValue;
  }

  public function fetchUserId() {
    $xp = $this->getUserInfo();
    if (empty($xp)) {
      return FALSE;
    }

    $query = '//voxb:userId';
    $nodelist = $xp->query($query);

    if ($nodelist->length != 1) {
      return FALSE;
    }

    return $nodelist->item(0)->nodeValue;
  }

  private function getUserInfo() {
    if (!empty($this->userInfo)) {
      return $this->userInfo;
    }

    $response = open_voxb_fetch_user($this->userId);
    try {
      $xp = bibdk_voxb_get_xpath($response);
    }
    catch (bibdkVoxbException $e) {
      // this is malformed xml - LOG
      watchdog('voxb', $e->getMessage(), array(), WATCHDOG_ERROR);

      return FALSE;
    }

    $this->userInfo = $xp;

    return $xp;
  }

  public function setUserData($xml) {
    $this->userData = $this->parseFetchMyDataResponse($xml);
  }

  private function parseFetchMyDataResponse($xml) {

    try {
      $xp = bibdk_voxb_get_xpath($xml);
    }
    catch (bibdkVoxbException $e) {
      // this is malformed xml - LOG
      watchdog('voxb', $e->getMessage(), array(), WATCHDOG_ERROR);

      return FALSE;
    }

    $query = '//voxb:result';
    $nodelist = $xp->query($query);

    if ($nodelist->length == 0) {
      return array();
    }

    foreach ($nodelist as $node) {
      $ret[] = $this->parseNode($node);
    }

    return $ret;
  }

  private function parseNode($node) {
    foreach ($node->childNodes as $child) {
      if ($child->hasChildNodes()) {
        // NOTICE recursive
        $ret[$child->nodeName] = $this->parseNode($child);
      }
      else {
        $ret[$child->nodeName] = $child->nodeValue;
      }
    }

    return $ret;
  }
}