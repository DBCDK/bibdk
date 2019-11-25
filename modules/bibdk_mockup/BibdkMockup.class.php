<?php

/**
 * @file
 * Class BibdkMockup
 */
class BibdkMockup {

  protected $cache_folder;

  /**
   * Constructor
   */
  public function __construct() {
    $this->cache_folder = DRUPAL_ROOT . '/' . drupal_get_path('module', 'bibdk_mockup') . '/cache';
    $this->log = variable_get('Bibdk_mockup_log', FALSE);
  }
  
  /**
   * Set cache folder path.
   *
   * @param string $cache_folder
   */
  public function setCacheFolder($cache_folder) {
    $this->cache_folder = $cache_folder;
  }

  /**
   * Get cache folder path.
   *
   * @return string
   */
  public function getCacheFolder() {
    return $this->cache_folder;
  }

  /**
   * check if cache file exist.
   *
   * @return bool
   */
  public function hasKey($key) {
    $filename = $this->filename($key);
    return file_exists($filename);
  }
  
  /**
   * Get cache value.
   *
   * @param string $key
   *
   * @return object
   */
  public function get($key) {
    $filename = $this->filename($key);
    if (file_exists($filename)) {
      $handle = fopen($filename, "r");
      $contents = fread($handle, filesize($filename));
      fclose($handle);
      $this->log('Get cached file: ' . $filename);
      return unserialize($contents);
    }
    else {
      $this->log('File: ' . $filename . ' is not cached.');
    }
  }

  /**
   * Set cache value.
   *
   * @param string $key
   * @param object $data
   *
   * @return bool
   */
  public function record($key, $data) {
    $filename = $this->filename($key);
    $this->log('Record file: ' . $filename);
    if (empty($data)) {
      $this->log('Failed to save mockup:' . $filename . ' is empty');
      throw new BibdkMockupException('Failed to save mockup:' . $filename . ' is empty');
    }
    if ($f = fopen($filename, 'w')) {
      fwrite($f, serialize($data));
      fclose($f);
    } else {
      $this->log('Failed to save mockup:' . $filename . ' is not writeable');
      throw new BibdkMockupException('Failed to save mockup:' . $filename . ' is not writeable');
    }
    return TRUE;
  }

  /**
   * Get cache file name.
   *
   * @return string
   */
  private function filename($key) {
    $filename = $this->cache_folder . '/' . $key;
    return $filename;
  }

  /**
   * Cache log function.
   */
  private function log($text) {
    if ( !$this->log ) {
      return;
    }
    $f = fopen(sys_get_temp_dir() . '/bibdk_mockup_log.txt', 'a');
    fwrite($f, date('Ymd H:i:s - ') . "\n" . print_r($text, 1) . "\n\n");
    fclose($f);
  }

}

class BibdkMockupException extends Exception {}

?>
