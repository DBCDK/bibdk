<?php

/**
 * Created by IntelliJ IDEA.
 * User: pjo
 * Date: 2/19/14
 * Time: 3:50 PM
 */
class bibdkVoxbException extends Exception {

  public function __construct($message) {
    parent::__construct('BIBDK_VOXB: ' . $message);
  }

  public static function malformedXml($xml) {
    return new bibdkVoxbException('could not load xml:' . $xml);
  }

  public static function ouiError() {
    return new bibdkVoxbException('unexpected reply from OUI');
  }

}