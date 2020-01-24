<?php
/**
 * @file
 * Contains PhpYazConverter
 */

/**
 * Class PHPYazConverter
 *
 * Converts ccl strings to cql
 */
class PhpYazConverter {

  private $cclmap, $cqlmap;
  private static $connection;

  /**
   * Create new PhpYazConverter
   */
  public function __construct() {
    $this->loadMaps();
  }

  /**
   * Convert ccl string to cql
   *
   * @param $ccl
   * @return array
   */
  public function CclToCql($ccl) {
    $connection = $this->getConnection();
    try {
      $rpn = $this->cclToRpn($ccl, $connection);
      $cql = $this->rnpToCql($rpn, $connection);
      return array('cql' => $cql);
    }
    catch (Exception $e) {
      return array('error' => $e->getMessage());
    }
  }

  /**
   * Convert ccl to cql
   *
   * @param $ccl
   * @param $connection
   * @return mixed
   * @throws Exception
   */
  private function cclToRpn($ccl, $connection) {
    $response = array();
    if (!yaz_ccl_parse($connection, $ccl, $response)) {
      throw new Exception(yaz_error($connection));
    }
    return $response['rpn'];
  }

  /**
   * Convert rnp to cql
   *
   * @param $rpn
   * @param $connection
   * @return string
   * @throws Exception
   */
  private function rnpToCql($rpn, $connection) {
    $cql = array();
    if (!yaz_cql_parse($connection, $rpn, $cql, TRUE)) {
      throw new Exception(yaz_error($connection));
    }

    return $cql['cql'];
  }

  /**
   * Create a yaz connection.
   *
   * We use a local ccl/cql maps, therefore connecting to an arbitrary "none:"
   * and adding the mappings afterwards
   *
   * @return mixed
   */
  private function getConnection() {
    if (isset(self::$connection)) {
      return self::$connection;
    }
    $connection = yaz_connect("none:");
    yaz_ccl_conf($connection, $this->cclmap);
    yaz_cql_conf($connection, $this->cqlmap);

    return self::$connection = $connection;
  }

  /**
   * Loads ccl/cql maps from include file
   *
   * @return array
   */
  private function loadMaps() {
    $cclmap = array();
    $cqlmap = array();
    include_once 'cqlmap.inc';
    $this->cclmap = $cclmap;
    $this->cqlmap = $cqlmap;
  }
}
