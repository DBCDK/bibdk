<?php

class bibdkHeimdalUser {

  public function __construct(array $attributes) {
    $culr_libraries = isset($attributes['attributes']['agencies']) ?
      $attributes['attributes']['agencies'] : array();

    $this->setLibraries($culr_libraries);
  }

  /**
   * Check if User has already been found via culr
   *
   * @return array
   *   empty or one/more usernames found
   */
  public function getBibdkUsers(){
    $libraries = self::getLibraries();
    if(empty($libraries)){
      return array();
    }

    $usernames = array();
    foreach($libraries as $agency){
      // check if provider is bibliotek.dk
      if($agency['agencyId'] == '190101'){
        $usernames[] = $agency['userId'];
      }
    }
    return $usernames;
  }

  public function setLibraries($agencies) {
    $_SESSION['culr_libraries'] = $agencies;
  }

  public static function getLibraries(){
    return isset($_SESSION['culr_libraries']) ?
      $_SESSION['culr_libraries'] : array();
  }

  public static function unset_libraries(){
    if(isset($_SESSION['culr_libraries'])) {
      unset($_SESSION['culr_libraries']);
    }
  }
}
