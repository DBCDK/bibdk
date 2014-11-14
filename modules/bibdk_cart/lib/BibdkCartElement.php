<?php

class BibdkCartElement {

  public $status = array();
  public $element;
  public $manifestation;
  public $id;

  function __construct() {
  }

  public function setId($id) {
    $this->id = $id;
  }

  public function getId() {
    return $this->id;
  }

  public function setElement($pids) {
    if (!is_array($pids)) {
      $pids = array($pids);
    }
    $this->element = implode(',', $pids);
  }

  public function getElement() {
    return $this->element;
  }

  public function getElementArray() {
    return explode(',', $this->element);
  }

  public function setStatus($status) {
    $status = explode(',', $status);
    foreach ($status as $value) {
      $this->status[$value] = $value;
    }
  }

  /** Get status for element. I type is not set. All elements are returned
   *
   * @param null $type
   * @return null|string
   */
  public function getStatus($type = null) {
    if (!$type) {
      return $this->status;
    }
    else {
      return isset($this->status[$type]) ? $this->status[$type] : null;
    }
  }

  public function getStatusView() {
    $view = array();
    if (isset($this->status)) {
      foreach ($this->status as $status) {
        $view[] = t($status);
      }
    }
    return $view;
  }

  public function setManifestation($manifestation) {
    $this->manifestation = $manifestation;
  }

  public function getManifestation() {
    return $this->manifestation;
  }

  public function toService() {
    return array(
      'oui:cartContentId' => $this->getId(),
      'oui:cartContentElement' => $this->getElement(),
      'oui:cartContentStatus' => implode(',', $this->getStatus()),
    );
  }

  public function getElementId() {
    return reset($this->getElementArray());
  }

  public function save() {
    BibdkCart::update($this);
  }
}
