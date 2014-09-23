<?php

/**
 * SAMPLE REQUESST
 * <CU:CreateUserRequest xmlns:CU="http://statsbiblioteket.dk/xws/createuser_v1" 
 * xmlns:CPR="http://rep.oio.dk/cpr.dk/xml/schemas/core/2005/03/18/" 
 * xmlns:DKCC="http://rep.oio.dk/ebxml/xml/schemas/dkcc/2003/02/13/">
      <CPR:PersonCivilRegistrationIdentifier>$1</CPR:PersonCivilRegistrationIdentifier>
      <DKCC:PersonGivenName>$2</DKCC:PersonGivenName>
      <DKCC:PersonSurnameName>$3</DKCC:PersonSurnameName>
      <CU:EmailAddress>$4</CU:EmailAddress>
    </CU:CreateUserRequest>
 * 
 *  
 */


/**
 * KLIP FRA bestil.xml
 <content>
    <key>error_sb_create_user_diag</key>
    <value><![CDATA[<h3>Fejl!</h3>
Der opstod en fejl, fejlmeddelelse fra Statsbibliotekets server: $1]]></value>
    <editor></editor>
    <documentation></documentation>
  </content>
  <content>
    <key>error_sb_create_user_diag_mustbe18orabove</key>
    <value>Du skal v<E6>re mindst 18 <E5>r for at blive indmeldt p<E5> Statsbiblioteket.</value>
    <editor></editor>
    <documentation></documentation>
  </content>
  <content>
    <key>error_sb_create_user_diag_invalidname</key>
    <value>Det navn du har angivet, svarer ikke til CPR-registrets navn - g<E5> tilbage og ret navnet.</value>
    <editor></editor>
    <documentation></documentation>
  </content>
  <content>
    <key>error_sb_create_user_diag_invalidaddress</key>
    <value>Ud fra CPR-registrets adresseoplysninger kan du desv<E6>rre ikke oprettes som l<E5>ner p<E5> Statsbiblioteket.</value>
    <editor></editor>
    <documentation></documentation>
  </content>
  <content>
    <key>error_sb_create_user_diag_invalidsyntax</key>
    <value>Du har indtastet en ikke-gyldig mailadresse. G<E5> tilbage og ret mailadressen.</value>
    <editor></editor>
    <documentation></documentation>
  </content>
  <content>
    <key>error_sb_screate_user_userexists</key>
    <value><![CDATA[Du er allerede oprettet som bruger!<A0><br />G<E5> tilbage,<A0>skriv CPR-nummer og PIN-kode under <strong>Er du allerede indmeldt p<E5> Statsbiblioteket?</strong>]]></value>
   
 */


class bibdk_statsbib extends TingClientRequest Implements ITingClientRequestCache {

  protected $personCivilRegistrationIdentifier;
  //<DKCC:PersonGivenName> ; DKCC="http://rep.oio.dk/ebxml/xml/schemas/dkcc/2003/02/13/"
  protected $personGivenName;
  //<DKCC:PersonSurnameName> 
  protected $personSurName;
  // <CU:EmailAddress> ; CU="http://statsbiblioteket.dk/xws/createuser_v1
  protected $emailAddress;
  protected $action;
  protected $cacheKey;
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
    return 'cache_bibdk_statsbib_webservice';
  }

  public function setPersonCivilRegistrationIdentifier($value = NULL) {
    $this->PersonCivilRegistrationIdentifier = $value;
  }

  public function getPersonCivilRegistrationIdentifier() {
    // maybe add namespace (xmlns:CPR=http://rep.oio.dk/cpr.dk/xml/schemas/core/2005/03/18)
    return $this->PersonCivilRegistrationIdentifier;
  }

  
  public function setPersonGivenName($value = NULL) {
    $this->personGivenName = $value;
  }

  public function getPersonGivenName() {
    return $this->personGivenName;
  }

  public function setPersonSurName($value = NULL) {
    $this->personSurnameName = $value;
  }

  public function getPersonSurName() {
    return $this->personSurName;
  }

  public function setAction($value = NULL) {
    $this->action = $value;
  }

  public function getAction() {
    return $this->action;
  }

  public function setEmailAddress($value = NULL) {
    $this->emailAddress = $value;
  }

  public function getEmailAddress() {
    return $this->emailAddress;
  }

  public function setOutputType($value = NULL) {
    $this->outputType = $value;
  }

  public function getOutputType() {
    return $this->outputType;
  }

  public function getRequest() {
    $this->setParameter('action', 'CreateUserRequest');
    $params = array('PersonCivilRegistrationIdentifier', 'PersonGivenName', 'PersonSurName', 'EmailAddress');
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
