<?php

class bibdkHelpdeskRequest extends TingClientRequest Implements ITingClientRequestCache {

  protected $agencyId;
  protected $qandaServiceName;
  protected $userName;
  protected $editorial;
  protected $userEmail;
  protected $userMobilePhone;
  protected $userAnswerPreference;
  protected $userAge;
  protected $userGender;
  protected $userPostalCode;
  protected $questionTitle;
  protected $questionContent;
  protected $questionNote;
  protected $questionDeadline;
  protected $questionUsage;
  protected $outputType;

  /** Implementation of ITingClientRequestCache */

  /** \brief ITingClientRequestCache::cacheKey; get a cachekey
   *
   * @return string
   */
  public function cacheKey() {
    $params = $this->getParameters();
    $ret = '';
    $this->make_cache_key($params, $ret);

    return md5($ret);
  }

  /** \brief make a cachekey based on request parameters
   *
   * @param array $params
   * @param string $ret
   */
  private function make_cache_key($params, &$ret) {
    foreach ($params as $key => $value) {
      if (is_array($value)) {
        // recursive
        $ret.=$key;
        $this->make_cache_key($value, $ret);
      }
      else {
        $ret.=$value;
      }
    }
  }

  /** \brief ITingClientRequestCache::cacheEnable; Check if cache is enabled
   *
   * @return value of variable (drupal_get)
   */
  public function cacheEnable($value = NULL) {
    $class_name = get_class($this);
    return variable_get($class_name . TingClientRequest::cache_enable);
  }

  /*   * \brief set timeout of cache
   *
   * @return mixed value of variable (variable_get)
   */

  public function cacheTimeout($value = NULL) {
    $class_name = get_class($this);
    return variable_get($class_name . TingClientRequest::cache_lifetime, '1');
  }

  /* \brief implements ITingClientRequestCache::cacheBin
   *
   * @return string; name of cachebin
   */

  public function cacheBin() {
    return 'cache_borchk_webservice';
  }

  /**
   * @param mixed $agencyId
   */
  public function setAgencyId($agencyId) {
    $this->agencyId = $agencyId;
  }

  /**
   * @return mixed
   */
  public function getAgencyId() {
    return $this->agencyId;
  }

  /**
   * @param mixed $cacheKey
   */
  public function setCacheKey($cacheKey) {
    $this->cacheKey = $cacheKey;
  }

  /**
   * @return mixed
   */
  public function getCacheKey() {
    return $this->cacheKey;
  }


  /**
   * @param mixed $outputType
   */
  public function setOutputType($outputType) {
    $this->outputType = $outputType;
  }

  /**
   * @return mixed
   */
  public function getOutputType() {
    return $this->outputType;
  }

  /**
   * @param mixed $qandaServiceName
   */
  public function setQandaServiceName($qandaServiceName) {
    $this->qandaServiceName = $qandaServiceName;
  }

  /**
   * @return mixed
   */
  public function getQandaServiceName() {
    return $this->qandaServiceName;
  }

  /**
   * @param mixed $editorial
   */
  public function setEditorial($editorial) {
    $this->editorial = $editorial;
  }

  /**
   * @return mixed
   */
  public function getEditorial() {
    return $this->editorial;
  }

  /**
   * @param mixed $questionContent
   */
  public function setQuestionContent($questionContent) {
    $this->questionContent = $questionContent;
  }

  /**
   * @return mixed
   */
  public function getQuestionContent() {
    return $this->questionContent;
  }

  /**
   * @param mixed $questionDeadline
   */
  public function setQuestionDeadline($questionDeadline) {
    $this->questionDeadline = $questionDeadline;
  }

  /**
   * @return mixed
   */
  public function getQuestionDeadline() {
    return $this->questionDeadline;
  }

  /**
   * @param mixed $questionNote
   */
  public function setQuestionNote($questionNote) {
    $this->questionNote = $questionNote;
  }

  /**
   * @return mixed
   */
  public function getQuestionNote() {
    return $this->questionNote;
  }

  /**
   * @param mixed $questionTitle
   */
  public function setQuestionTitle($questionTitle) {
    $this->questionTitle = $questionTitle;
  }

  /**
   * @return mixed
   */
  public function getQuestionTitle() {
    return $this->questionTitle;
  }

  /**
   * @param mixed $questionUsage
   */
  public function setQuestionUsage($questionUsage) {
    $this->questionUsage = $questionUsage;
  }

  /**
   * @return mixed
   */
  public function getQuestionUsage() {
    return $this->questionUsage;
  }

  /**
   * @param mixed $userAge
   */
  public function setUserAge($userAge) {
    $this->userAge = $userAge;
  }

  /**
   * @return mixed
   */
  public function getUserAge() {
    return $this->userAge;
  }

  /**
   * @param mixed $userAnswerPreference
   */
  public function setUserAnswerPreference($userAnswerPreference) {
    $this->userAnswerPreference = $userAnswerPreference;
  }

  /**
   * @return mixed
   */
  public function getUserAnswerPreference() {
    return $this->userAnswerPreference;
  }

  /**
   * @param mixed $userEmail
   */
  public function setUserEmail($userEmail) {
    $this->userEmail = $userEmail;
  }

  /**
   * @return mixed
   */
  public function getUserEmail() {
    return $this->userEmail;
  }

  /**
   * @param mixed $userGender
   */
  public function setUserGender($userGender) {
    $this->userGender = $userGender;
  }

  /**
   * @return mixed
   */
  public function getUserGender() {
    return $this->userGender;
  }

  /**
   * @param mixed $userMobilePhone
   */
  public function setUserMobilePhone($userMobilePhone) {
    $this->userMobilePhone = $userMobilePhone;
  }

  /**
   * @return mixed
   */
  public function getUserMobilePhone() {
    return $this->userMobilePhone;
  }

  /**
   * @param mixed $userName
   */
  public function setUserName($userName) {
    $this->userName = $userName;
  }

  /**
   * @return mixed
   */
  public function getUserName() {
    return $this->userName;
  }

  /**
   * @param mixed $userPostalCode
   */
  public function setUserPostalCode($userPostalCode) {
    $this->userPostalCode = $userPostalCode;
  }

  /**
   * @return mixed
   */
  public function getUserPostalCode() {
    return $this->userPostalCode;
  }

  public function getRequest() {
    $this->setParameter('action', 'createQuestionRequest');
    $params = array('agencyId','qandaServiceName', 'editorial', 'userName', 'userEmail', 'userMobilePhone', 'userAnswerPreference', 'userAge', 'userGender', 'userPostalCode',
      'questionTitle', 'questionContent', 'questionNote', 'questionDeadline', 'questionUsage', 'outputType'
    );
    foreach ($params as $parameter) {
      $getter = 'get' . ucfirst($parameter);
      if ($value = $this->$getter()) {
        $this->setParameter($parameter, $value);
      }
    }
    return $this;
  }

  // empty;
  public function processResponse(stdClass $result) {
    return $result;
  }

}
