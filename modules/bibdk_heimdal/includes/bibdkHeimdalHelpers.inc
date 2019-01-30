<?php
class bibdkHeimdalHelpers{
  /**
   * Returns absolute url - url is made up of _SERVER variables, drupal base_path and
   * given relative path
   *
   * @param $relative_path
   *  do NOT add '/' to beginning of parameter
   *
   * @return string
   */
  public static function bibdk_heimdal_get_full_url($relative_path = ''){
    if (isset($_SERVER['HTTPS']) &&
      ($_SERVER['HTTPS'] == 'on' || $_SERVER['HTTPS'] == 1) ||
      isset($_SERVER['HTTP_X_FORWARDED_PROTO']) &&
      $_SERVER['HTTP_X_FORWARDED_PROTO'] == 'https') {
      $protocol = 'https:/';
    }
    else {
      $protocol = 'http:/';
    }
    $drupal_path = base_path();

    // pjo hardcoded for my ip on the network and my localhost
    $drupal_path = '/172.17.28.60/postgres/';

    return $protocol.$drupal_path.$relative_path;
  }
}
