<?php
/**
 * @file
 * Datebase handling for bibdk_heimdal. When a user inserts an email
 * a row in bibdk_heimdal_email_verify table is inserted for later
 * verification by link
 *
 */

class heimdalDatabase {
  /**
   * Get all rows from bibdk_heimdal_email_verify table
   * @return mixed
   */
  public static function getAll(){
    $rows = db_select('bibdk_heimdal_email_verify', 'b')
      ->fields('b')
      ->execute()
      ->fetchAssoc();

    return $rows;
  }

  /**
   * Insert a row in bibdk_heimdal_email_verify table
   *
   * @param string $email
   * @param array $agencies
   * @return mixed (string)
   *  uuid (primary key of table) to be used when generating an email link
   */
  public static function insert($email, array $agencies) {
    $key = uuid_generate();
    $libraries = serialize($agencies);
    $date = time();

    if(!self::checkUniqueMail($email)){
      // email already exist - maybe user asked for another link? ..
      // anyway delete it before insert
      self::deleteByMail($email);
    }

    db_insert('bibdk_heimdal_email_verify')
      ->fields(
        array(
          'uuid' => $key,
          'libraries' => $libraries,
          'email' => $email,
          'date' => $date,
        )
      )->execute();

    return $key;
  }

  /**
   * Email is unique - check if it is
   * @param $email
   *   The email to check for
   * @return bool
   *   FALSE if user already exists
   */
  private static function checkUniqueMail($email){
    $rows = db_select('bibdk_heimdal_email_verify', 'b')
      ->fields('b')
      ->condition('email',$email,'=')
      ->execute()
      ->fetchAssoc();

    if(count($rows) !== 0){
      return FALSE;
    }

    return TRUE;
  }

  /**
   * Delete a row by email
   * @param $email
   * @return int
   */
  public static function deleteByMail($email) {
    $result = db_delete('bibdk_heimdal_email_verify')
      ->condition('email', $email, '=')
      ->execute();

    return $result;
  }

  /**
   * Delete a row by uuid
   * @param string $uuid
   * @return int
   */
  public static function deleteByUUID($uuid) {
    $result = db_delete('bibdk_heimdal_email_verify')
      ->condition('uuid', $uuid, '=')
      ->execute();

    return $result;
  }

  /**
   * Get a row by uuid from bibdk_heimdal_email_verify table
   * @param $uuid
   *   primary key of row
   * @return array|bool
   */
  public static function get($uuid){
    $rows = db_select('bibdk_heimdal_email_verify', 'b')
      ->fields('b')
      ->condition('uuid',$uuid,'=')
      ->execute()
      ->fetchAssoc();

    return $rows;
  }
}

