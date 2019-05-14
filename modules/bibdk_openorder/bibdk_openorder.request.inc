<?php

class bibdk_openorder extends TingClientRequest {

  // attributes for checkOrderPolicyRequest
  protected $serviceRequester;
  protected $authentication;
  protected $pickUpAgencyId;
  protected $pid;
  protected $action;
  protected $outputType;
// extra attributes for placeOrderRequest
  protected $articleDirect;
  protected $author;
  protected $authorOfComponent;
  protected $bibliographicCategory;
  protected $bibliographicRecordAgencyId;
  protected $bibliographicRecordId;
  protected $callNumber;
  protected $copy;
  protected $edition;
  protected $exactEdition;
  protected $fullTextLink;
  protected $fullTextLinkType;
  protected $isbn;
  protected $issn;
  protected $issue;
  protected $itemId;
  protected $language;
  protected $localHoldingsId;
  protected $mediumType;
  protected $needBeforeDate;
  protected $orderId;
  protected $orderSystem;
  protected $pagination;
  protected $pickUpAgencySubdivision;
  protected $placeOfPublication;
  protected $placeOnHold;
  protected $publicationDate;
  protected $publicationDateOfComponent;
  protected $publisher;
  protected $requesterId;
  protected $requesterNote;
  protected $responderId;
  protected $seriesTitelNumber;
  protected $title;
  protected $titleOfComponent;
  protected $userAddress;
  protected $userAgencyId;
  protected $userDateOfBirth;
  protected $userId;
  protected $userIdAuthenticated;
  protected $userIdType;
  protected $userMail;
  protected $userName;
  protected $userReferenceSource;
  protected $userTelephone;
  protected $verificationReferenceSource;
  protected $volume;
  protected $callback;
  protected $agencyId;

  public function getAgencyId() {
    return $this->agencyId;
  }

  public function setAgencyId($agencyId) {
    $this->agencyId = $agencyId;
  }

  public function getCallback() {
    return $this->callback;
  }

  public function setCallback($callback) {
    $this->callback = $callback;
  }

  public function getArticleDirect() {
    return $this->articleDirect;
  }

  public function setArticleDirect($articleDirect) {
    $this->articleDirect = $articleDirect;
  }

  public function getAuthor() {
    return $this->author;
  }

  public function setAuthor($author) {
    $this->author = $author;
  }

  public function getAuthorOfComponent() {
    return $this->authorOfComponent;
  }

  public function setAuthorOfComponent($authorOfComponent) {
    $this->authorOfComponent = $authorOfComponent;
  }

  public function getBibliographicCategory() {
    return $this->bibliographicCategory;
  }

  public function setBibliographicCategory($bibliographicCategory) {
    $this->bibliographicCategory = $bibliographicCategory;
  }

  public function getCallNumber() {
    return $this->callNumber;
  }

  public function setCallNumber($callNumber) {
    $this->callNumber = $callNumber;
  }

  public function getEdition() {
    return $this->edition;
  }

  public function setEdition($edition) {
    $this->edition = $edition;
  }

  public function getFullTextLink() {
    return $this->fullTextLink;
  }

  public function setFullTextLink($fullTextLink) {
    $this->fullTextLink = $fullTextLink;
  }

  public function getFullTextLinkType() {
    return $this->fullTextLinkType;
  }

  public function setFullTextLinkType($fullTextLinkType) {
    $this->fullTextLinkType = $fullTextLinkType;
  }

  public function getIsbn() {
    return $this->isbn;
  }

  public function setIsbn($isbn) {
    $this->isbn = $isbn;
  }

  public function getIssn() {
    return $this->issn;
  }

  public function setIssn($issn) {
    $this->issn = $issn;
  }

  public function getIssue() {
    return $this->issue;
  }

  public function setIssue($issue) {
    $this->issue = $issue;
  }

  public function getItemId() {
    return $this->itemId;
  }

  public function setItemId($itemId) {
    $this->itemId = $itemId;
  }

  public function getLanguage() {
    return $this->language;
  }

  public function setLanguage($language) {
    $this->language = $language;
  }

  public function getLocalHoldingsId() {
    return $this->localHoldingsId;
  }

  public function setLocalHoldingsId($localHoldingsId) {
    $this->localHoldingsId = $localHoldingsId;
  }

  public function getMediumType() {
    return $this->mediumType;
  }

  public function setMediumType($mediumType) {
    $this->mediumType = $mediumType;
  }

  public function getOrderId() {
    return $this->orderId;
  }

  public function setOrderId($orderId) {
    $this->orderId = $orderId;
  }

  public function getPagination() {
    return $this->pagination;
  }

  public function setPagination($pagination) {
    $this->pagination = $pagination;
  }

  public function getPickUpAgencySubdivision() {
    return $this->pickUpAgencySubdivision;
  }

  public function setPickUpAgencySubdivision($pickUpAgencySubdivision) {
    $this->pickUpAgencySubdivision = $pickUpAgencySubdivision;
  }

  public function getPlaceOfPublication() {
    return $this->placeOfPublication;
  }

  public function setPlaceOfPublication($placeOfPublication) {
    $this->placeOfPublication = $placeOfPublication;
  }

  public function getplaceOnHold() {
    return $this->placeOnHold;
  }

  public function setplaceOnHold($placeOnHold) {
    $this->placeOnHold = $placeOnHold;
  }

  public function getPublicationDate() {
    return $this->publicationDate;
  }

  public function setPublicationDate($publicationDate) {
    $this->publicationDate = $publicationDate;
  }

  public function getPublicationDateOfComponent() {
    return $this->publicationDateOfComponent;
  }

  public function setPublicationDateOfComponent($publicationDateOfComponent) {
    $this->publicationDateOfComponent = $publicationDateOfComponent;
  }

  public function getPublisher() {
    return $this->publisher;
  }

  public function setPublisher($publisher) {
    $this->publisher = $publisher;
  }

  public function getRequesterId() {
    return $this->requesterId;
  }

  public function setRequesterId($requesterId) {
    $this->requesterId = $requesterId;
  }

  public function getRequesterNote() {
    return $this->requesterNote;
  }

  public function setRequesterNote($requesterNote) {
    $this->requesterNote = $requesterNote;
  }

  public function getResponderId() {
    return $this->responderId;
  }

  public function setResponderId($responderId) {
    $this->responderId = $responderId;
  }

  public function getSeriesTitelNumber() {
    return $this->seriesTitelNumber;
  }

  public function setSeriesTitelNumber($seriesTitelNumber) {
    $this->seriesTitelNumber = $seriesTitelNumber;
  }

  public function getTitle() {
    return $this->title;
  }

  public function setTitle($title) {
    $this->title = $title;
  }

  public function getTitleOfComponent() {
    return $this->titleOfComponent;
  }

  public function setTitleOfComponent($titleOfComponent) {
    $this->titleOfComponent = $titleOfComponent;
  }

  public function getUserAgencyId() {
    return $this->userAgencyId;
  }

  public function setUserAgencyId($userAgencyId) {
    $this->userAgencyId = $userAgencyId;
  }

  public function getUserDateOfBirth() {
    return $this->userDateOfBirth;
  }

  public function setUserDateOfBirth($userDateOfBirth) {
    $this->userDateOfBirth = $userDateOfBirth;
  }

  public function getUserReferenceSource() {
    return $this->userReferenceSource;
  }

  public function setUserReferenceSource($userReferenceSource) {
    $this->userReferenceSource = $userReferenceSource;
  }

  public function getVolume() {
    return $this->volume;
  }

  public function setVolume($volume) {
    $this->volume = $volume;
  }

  public function getBibliographicRecordAgencyId() {
    return $this->bibliographicRecordAgencyId;
  }

  public function setBibliographicRecordAgencyId($bibliographicRecordAgencyId) {
    $this->bibliographicRecordAgencyId = $bibliographicRecordAgencyId;
  }

  public function getBibliographicRecordId() {
    return $this->bibliographicRecordId;
  }

  public function setBibliographicRecordId($bibliographicRecordId) {
    $this->bibliographicRecordId = $bibliographicRecordId;
  }

  public function setNeedBeforeDate($value = NULL) {
    $this->needBeforeDate = $value;
  }

  public function getNeedBeforeDate() {
    return $this->needBeforeDate;
  }

  public function setOrderSystem($value = NULL) {
    $this->orderSystem = $value;
  }

  public function getOrderSystem() {
    return $this->orderSystem;
  }

  public function setUserId($value = NULL) {
    $this->userId = $value;
  }

  public function getUserId() {
    return $this->userId;
  }

  public function setCustomId($value = NULL) {
    $this->customId = $value;
  }

  public function getCustomId() {
    return $this->customId;
  }

  public function setUserAddress($userAddress) {
    $this->userAddress = $userAddress;
  }

  public function getUserAddress() {
    return $this->userAddress;
  }

  public function setUserName($userName) {
    $this->userName = $userName;
  }

  public function getUserName() {
    return $this->userName;
  }

  public function setUserMail($userMail) {
    $this->userMail = $userMail;
  }

  public function getUserMail() {
    return $this->userMail;
  }

  public function setUserTelephone($userTelephone) {
    $this->userTelephone = $userTelephone;
  }

  public function getUserTelephone() {
    return $this->userTelephone;
  }

  public function setVerificationReferenceSource($value = NULL) {
    $this->verificationReferenceSource = $value;
  }

  public function getVerificationReferenceSource() {
    return $this->verificationReferenceSource;
  }

  public function setCopy($value = NULL) {
    $this->copy = $value;
  }

  public function getCopy() {
    return $this->copy;
  }

  public function setExactEdition($value = NULL) {
    $this->exactEdition = $value;
  }

  public function getExactEdition() {
    return $this->exactEdition;
  }

  public function setUserIdAuthenticated($value = NULL) {
    $this->userIdAuthenticated = $value;
  }

  public function getUserIdAuthenticated() {
    return $this->userIdAuthenticated;
  }

  public function setUserIdType($userIdType) {
    $this->userIdType = $userIdType;
  }

  public function getUserIdType() {
    return $this->userIdType;
  }

  // setters/getters for checkOrderPolicyRequest
  public function setOutputType($value = NULL) {
    $this->outputType = $value;
  }

  public function getOutputType() {
    return $this->outputType;
  }

  public function setAction($value = NULL) {
    $this->action = $value;
  }

  public function getAction() {
    return $this->action;
  }

  public function setServiceRequester($value = NULL) {
    $this->serviceRequester = $value;
  }

  public function getServiceRequester() {
    return $this->serviceRequester;
  }

  public function getAuthentication() {
    return $this->authentication;
  }

  public function setAuthentication(array $value = array()) {
    $this->authentication = $value;
  }

  public function setPickupAgencyId($value = NULL) {
    $this->pickUpAgencyId = $value;
  }

  public function getPickupAgencyId() {
    return $this->pickUpAgencyId;
  }

  public function setPid($value = NULL) {
    $this->pid = $value;
  }

  public function getPid() {
    return $this->pid;
  }

  /**
   * do NOT set default outputType in TingClientRequestAdapter - we handle
   * response ourself - see this::parseResponse
   * @return bool
   */
  public function defaultOutputType() {
    return FALSE;
  }


  /**
   * Override TingClientRequest::parseResponse
   *
   * As of openorder 3.0 service returns xml only. Ting client is made for
   * parsing json supported by OLS webservices.
   *
   * Two classes from OLS are used to convert xml to json, to use same procedure as
   * before.
   *
   * @see ting-client/lib/ols_convert/xmlconvert_class.php and objconvert_class.php
   *
   * @param $responseString
   * @return mixed
   */
  public function parseResponse($responseString) {
    $dom = new DOMDocument();
    $dom->preserveWhiteSpace = FALSE;
    if(@$dom->loadXML($responseString)){
      $xmlconvert = new xmlconvert();
      $objconvert = new objconvert();
      $OLS_obj = $xmlconvert->xml2obj($dom);
      $badgerfish = $objconvert->obj2json($OLS_obj);
      return parent::parseResponse($badgerfish);
    }
    else{
      throw new Exception('failed to parse response from openorder: ' . $responseString);
    }
  }


  /**
   * Override TingClientRequest::processResponse
   *
   * Method above (parseResponse) converts soapxml answer to json. This one
   * does a check on SoapEnvelope and returns the body if found
   *
   * @param stdClass $result
   * @return mixed
   * @throws Exception
   */
  public function processResponse(stdClass $result) {
    if(isset($result->Envelope->Body)) {
      return $result->Envelope->Body;
    }
    else {
      throw new Exception('No soap envelope in response from openorder: ' . json_encode($result));
    }
  }

}

?>
