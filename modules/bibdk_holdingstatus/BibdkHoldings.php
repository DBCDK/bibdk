<?php

class BibdkHoldings {

  private $data;
  private static $holdings = array();
  private static $agencyInformation = array();

  function __construct($holdingsResponse) {
    $this->data = $holdingsResponse;
  }

  public static function setHoldings($holding, $pid, $lid) {
    self::$holdings[$pid][$lid] = $holding;
  }

  static public function getHoldings($pid, $lid) {
    return (isset(self::$holdings[$pid]) && isset(self::$holdings[$pid][$lid])) ? self::$holdings[$pid][$lid] : NULL;
  }

  static public function getAllHoldings() {
    return self::$holdings;
  }

  public static function setAgencyInformation($agencyInformation) {
    self::$agencyInformation = $agencyInformation;
  }

  public static function getAgencyInformation() {
    return self::$agencyInformation;
  }

  public function getResponderId() {
    return isset($this->data->responderId) ? $this->data->responderId->{'$'} : NULL;
  }

  private function getWillLend() {
    return isset($this->data->willLend) ? $this->data->willLend->{'$'} : false;
  }

  private function getExpectedDelivery() {
    return isset($this->data->expectedDelivery) ? strtotime($this->data->expectedDelivery->{'$'}) : null;
  }

  private function getErrorMessage() {
    return isset($this->data->errorMessage) ? $this->data->errorMessage->{'$'} : null;
  }

  /**
   * Check if material is home
   * @return bool
   */
  public function isItHome() {
    if (!$this->getExpectedDelivery()) {
      return false;
    }
    return (time() - $this->getExpectedDelivery() < 0) ? false : true;
  }

  public function hasNote() {
    return isset($this->data->note) ? $this->data->note->{'$'} : false;
  }

  /**
   * return the holding status ()
   * @return string green, yellow or red
   */
  public function status() {
    if ($this->getWillLend()) {
      if ($this->isItHome()) {
        return 'green';
      }
      else {
        return 'yellow';
      }
    }
    else {
      return 'red';
    }
  }

  /**
   * return an untranslated message
   */
  public function rawMessage(){
    $return = array(
      'message' => '',
      'options' => array(),
    );
    if ($this->getWillLend() && $this->isItHome()) {
      $return['message'] = 'bibdk_holding_material_is_home';
    }
    else if (!$this->isItHome() && $this->getExpectedDelivery()) {
      $return['message'] = 'bibdk_holding_material_will_be_home @date';
      $return['options'] = array('@date' => format_date($this->getExpectedDelivery(), 'custom', 'd.m.Y'));
    }
    else if ($note = $this->hasNote()){
      $return['message'] = $note;
    }
    else if ($error = $this->getErrorMessage()) {
      $return['message'] = $error;
    }
    else {
      $return['message'] = 'bibdk_holding_someting_went_wrong';
    }

    return $return;
  }

  /**
   * return a translated status message
   * @return string
   */
  public function message() {
    $message = $this->rawMessage();

    return t($message['message'], $message['options'], array('context' => 'bibdk_holdingstatus'));;
  }
}
