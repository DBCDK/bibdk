<?php

/**
 * Class policyResponseMuckup
 * Mockup class to test _bibdk_reservation_generate_policy_messages
 */
class PolicyResponseMockup {

  public $lookUpUrl = array(), $agencyId, $orderPossibleReason, $agencyCatalogueUrl;

  public function getLookUpUrl() {
    return $this->lookUpUrl;
  }

  public function getAgencyCatalogueUrl() {
    return $this->agencyCatalogueUrl;
  }

  public function getOrderPossibleReason() {
    return $this->orderPossibleReason;
  }

  public function getAgencyId() {
    return $this->agencyId;
  }
}