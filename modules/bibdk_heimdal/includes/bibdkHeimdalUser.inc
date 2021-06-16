<?php

/**
 * @file  Class bibdkHeimdalUser
 *
 * This one has two parts. The constructor is called when accessing heimdal access
 * platform. Libraries are set/get in SESSION with static function
 * due to the many redirects that might occur
 */
class bibdkHeimdalUser {
  private $culrAgency;
  private $cpr;

  /**
   * Parse and set attributes from heimdal access platform
   * bibdkHeimdalUser constructor.
   * @param array $attributes
   */
  public function __construct(array $attributes) {
    $this->culrAgency = variable_get('bibdk_provider_culr_agency', NULL);
    if(empty($this->culrAgency)){
      watchdog('HEIMDAL', 'NO AGENCYID FOR CULR ACTIONS', WATCHDOG_ERROR);
    }

    $this->cpr = $attributes['attributes']['cpr'] ?? NULL;

    $culr_libraries = $attributes['attributes']['agencies'] ?? [];

    $libraries = self::getLibraries();
    if(empty($culr_libraries) && empty($libraries)){
      $culr_libraries[] = $this->setBibliotekDkAgency($attributes['attributes']);
    }
    if(!empty($culr_libraries)) {
      $this->setLibraries($culr_libraries);
    }
    // always set a bibliotek.dk agency

  }

  private function setBibliotekDkAgency($attributes) {
    return array(
      'agencyId' => $this->culrAgency,
      'cpr' => $attributes['cpr']
    );
  }


  /**
   * Check if User has already been found via culr
   *
   * @return array
   *   empty or one/more usernames found
   */
  public function getBibdkUsers() {
    $libraries = self::getLibraries();

    if (empty($libraries)) {
      return array();
    }

    $usernames = array();
    foreach ($libraries as $agency) {
      // check if provider is bibliotek.dk
      if ($agency['agencyId'] == $this->culrAgency) {
        if(isset($agency['userId'])) {
          $usernames[] = $agency['userId'];
        }
      }
    }
    return $usernames;
  }

  /**
   * Set libraries in SESSION
   * @param $agencies
   */
  public function setLibraries($agencies) {
    $_SESSION['culr_libraries'] = $agencies;
  }

  /**
   * Get libraries from SESSION
   * @return array
   */
  public static function getLibraries() {
    return $_SESSION['culr_libraries'] ?? [];
  }

  /**
   * Unset libraries in SESSION
   */
  public static function unset_libraries() {
    if (isset($_SESSION['culr_libraries'])) {
      unset($_SESSION['culr_libraries']);
    }
  }
}
