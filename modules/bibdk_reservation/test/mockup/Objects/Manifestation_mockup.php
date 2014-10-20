<?php

/**
 * Class Manifestation_mockup
 */
class Manifestation_mockup extends Manifestation{

  public $bibdk_order;
  public $messageCategory;
  public $infoText = NULL;
  public $type = array();
  public $isLink;
  public $creator = array();
  public $subtype;

  public function __construct() {

  }

  public function getTitleSpecific() {
    return $this->_getTitle();
  }

  public function getTitle() {
    return $this->_getTitle();
  }

  public function getInfotext(){
    return (!empty($this->infoText)) ? $this->infoText : 'infotext';
  }

  public function getMessageCategory(){
    return $this->messageCategory;
  }

  public function getAccessInformation(){
    return array(
      'accessUrl' => "http://accessurl.url",
    );
  }

  public function getType(){
    return $this->type;
  }

  public function isLink(){
    return $this->isLink;
  }

  public function getCreator() {
    return $this->creator;
  }

  public function getSubType(){
    return $this->subtype;
  }

  /**
   * @return bool|string
   */
  private function _getTitle() {
    switch ($this->bibdk_order) {
      case 'titleSpecfic':
        return 'TITLESPECIFIC_RETURN';
        break;
      case 'title':
        return 'TITLE_RETURN';
        break;
      case 'no_title':
        return '';
        break;
      default:
        return FALSE;
        break;
    }
  }
}
