<?php
/**
 *
 * This file is part of Open Library System.
 * Copyright © 2009, Dansk Bibliotekscenter a/s,
 * Tempovej 7-11, DK-2750 Ballerup, Denmark. CVR: 15149043
 *
 * Open Library System is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Open Library System is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with Open Library System.  If not, see <http://www.gnu.org/licenses/>.
*/


/**
 * \brief Verbose singleton class for loggin to a file or screen
 *
 * Usage: \n
 * verbose::open(logfile_name, log_mask); \n
 * verbose::log(FATAL,'could not find value x')\n
 *
 * Example:
 * verbose::open('my_trace_file.log', 'WARNING+FATAL+TIMER'); \n
 * verbose::log(FATAL, 'Cannot find database');\n
 *
 * Example:
 * verbose::open('my_trace_file.log', WARNING+FATAL+TIMER); \n
 * verbose::log(FATAL, 'Cannot find database');\n
 *
 * Example (will add process-id to all verbose lines):
 * verbose::open('my_trace_file.log', PID+WARNING+FATAL+TIMER); \n
 * verbose::log(FATAL, 'Cannot find database');\n
 *
 * Example:
 * verbose::open('my_trace_file.log', 77, 'H:i:s d:m:y'); \n
 * verbose::log(TRACE, 'db::look_up_user()');\n
 */

@ define('WARNING',0x01);
@ define('ERROR',0x02);
@ define('FATAL',0x04);
@ define('STAT',0x08);
@ define('TIMER',0x10);
@ define('DEBUG',0x20);
@ define('TRACE',0x40);
@ define('Z3950',0x80);
@ define('OCI',0x100);

class verbose {

  static $verbose_file_name;
  static $verbose_mask;
  static $date_format;
  static $my_pid = '';
  static $tracking_id = '';

  private function __construct() {}
  private function __destruct() {}
  private function __clone() {}

  /**
   * \brief Sets loglevel and logfile
   * @param verbose_file_name (string)
   * @param verbose_mask (string or integer)
   * @param date_format (string) - format-string for date()
   **/

  public function open($verbose_file_name, $verbose_mask, $date_format='') {
    self::$tracking_id = date('Y-m-d\TH:i:s:') . substr((string)microtime(), 2, 6) . ':' . getmypid();
    if (!self::$date_format = $date_format)
      self::$date_format='H:i:s-d/m/y';
    self::$verbose_file_name=$verbose_file_name;
    if (!is_string($verbose_mask)) {
      self::$verbose_mask=(empty($verbose_mask) ? 0 : $verbose_mask);
    }
    else {
      foreach (explode('+', $verbose_mask) as $vm) {
        if (defined(trim($vm))) self::$verbose_mask |= constant(trim($vm));
        if ($vm == 'PID') self::$my_pid = ' [' . getmypid() . ']';
      }
    }
  }

  /**
   * \brief Logs to a file, or prints out log message.
   * @param verbose_level Level of verbose output (string)
   * @param str Log string to write (string)
   */

  public function log($verbose_level, $str) {
    if (self::$verbose_file_name && $verbose_level & self::$verbose_mask) {
      switch ($verbose_level) {
        case WARNING :
          $vtext = 'WARNING';
          break;
        case ERROR :
          $vtext = 'ERROR';
          break;
        case FATAL :
          $vtext = 'FATAL';
          break;
        case STAT :
          $vtext = 'STAT';
          break;
        case TIMER :
          $vtext = 'TIMER';
          break;
        case DEBUG :
          $vtext = 'DEBUG';
          break;
        case TRACE :
          $vtext = 'TRACE';
          break;
        case Z3950 :
          $vtext = 'Z3950';
          break;
        case OCI :
          $vtext = 'OCI';
          break;
        default :
          $vtext = 'UNKNOWN';
          break;
      }

      if ($fp = @ fopen(self::$verbose_file_name,'a')) {
        if (substr($str, strlen($str)-1, 1) <> "\n") $str .= "\n";
        fwrite($fp, $vtext . self::$my_pid . ' ' . date(self::$date_format) . ' os:' . self::$tracking_id . ' ' . $str);
        fclose($fp);
      }
      else {
        throw new Exception('FATAL: Cannot open ' . self::$verbose_file_name);
      }
    }
  }

  /**
   * \brief Make a unique tracking id
   * @param t_service_prefix Service prefix that identifies the service
   * @param t_id Current tracking_id
   */

  public function set_tracking_id($t_service_prefix, $t_id = '') {
    self::$tracking_id = $t_service_prefix . ':' .  self::$tracking_id .  ($t_id ? '<' . $t_id : '');
    return self::$tracking_id;
  }

}
?>
