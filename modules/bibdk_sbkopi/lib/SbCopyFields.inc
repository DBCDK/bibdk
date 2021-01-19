<?php
/**
 * @file
 * Class for Setting up input fields for a SB request
 */

/**
 * Class SbCopyFields
 *
 * Controller like class for SB reservation flow
 */
class SbCopyFields {

  private $articleFields = array(
    'publicationTitle' => array('required' => FALSE),
    'authorOfComponent' => array('required' => TRUE),
    'titleOfComponent' => array('required' => TRUE),
    'publicationDateOfComponent' => array('required' => FALSE),
    'publicationYearOfComponent' => array('required' => TRUE),
    'issueOfComponent' => array('required' => FALSE),
    'volumeOfComponent' => array('required' => FALSE),
    'pagesOfComponent' => array('required' => TRUE),
  );
  private $articleOpenOrderMapping = array(
    'authorOfComponent' => 'authorOfComponent',
    'titleOfComponent' => 'titleOfComponent',
    'publicationDateOfComponent' => 'publicationYearOfComponent',
    'volume' => 'volumeOfComponent',
    'issue' => 'issueOfComponent',
    'pagination' => 'pagesOfComponent',
  );
  private $defaultFields = array(
    'pid' => array('required' => TRUE, 'type' => 'value'),
    'agencyId' => array('required' => TRUE, 'type' => 'value'),
    'pickupAgencyId' => array('required' => TRUE, 'type' => 'value'),
    'userName' => array('required' => TRUE),
    'userMail' => array('required' => TRUE),
  );
  private $fields = array();
  private $defaultValues = array();

  public function _construct() {
  }

  /**
   * Adds default values
   *
   * @param array $defaultValues
   * @return SbCopyFields $this
   */
  public function setDefaultValues($defaultValues) {
    $this->defaultValues = $defaultValues;
    return $this;
  }

  /**
   * Adds default fields
   *
   * @return SbCopyFields $this
   */
  public function setDefaultFields() {
    $this->fields += $this->mapDefaultValues($this->defaultFields, $this->defaultValues);
    return $this;
  }

  /**
   * Maps default values with fields
   *
   * @param array $fields
   * @param array $defaultValues
   * @return array
   */
  private function mapDefaultValues($fields, $defaultValues) {
    $elements = array();

    foreach ($fields as $name => $field) {
      $elements[$name] = array(
        'name' => $name,
        'title' => $name,
        'required' => $field['required'],
        'value' => isset($defaultValues[$name]) ? $defaultValues[$name] : NULL,
        'type' => isset($field['type']) ? $field['type'] : 'textfield',
      );
    }

    return $elements;
  }

  /**
   * Adds article fields
   *
   * @param array $agencyFields
   * @return SbCopyFields $this
   */
  public function setArticleFields() {
    $this->fields += $this->mapDefaultValues($this->articleFields, $this->defaultValues);
    return $this;
  }

  /**
   * Maps article fields from Agency with with SB article fields
   *
   * @param array $fields
   * @param array $agencyFields
   * @param array $map
   * @return array
   */
  private function mapOpenOrderFields($fields, $agencyFields, $map) {
    $orderFields = array();
    if (!empty($agencyFields)) {
      foreach ($agencyFields as $agencyField) {
        if (array_key_exists($agencyField['type'], $map)) {
          $type = $map[$agencyField['type']];
          $orderFields[$type] = $fields[$type];
          $orderFields[$type]['required'] = $agencyField['required'];
        }
      }
    }
    return $orderFields;
  }

  /**
   * return Fields
   *
   * @return array
   */
  public function getFields() {
    return $this->fields;
  }

  /**
   * Makes it possible to alter fields using a callback method
   *
   * @param callable $cb
   * @return SbCopyFields $this
   */
  public function alterFields($cb) {
    $this->fields = array_map($cb, $this->fields);
    return $this;
  }

  /**
   * Converts fields to render array
   *
   * @return array
   */
  public function render() {
    return array_map(array($this, '_getSingleFieldRenderArray'), $this->fields);
  }

  /**
   * Returns relevant messages
   *
   * @param string $deliveryMethod
   * @param string $subscription
   * @return array
   */
  public function messages($deliveryMethod, $subscription) {
    // $subscription = $this->orderLibrary->getStateAndUniversityLibraryCopyService();
    if (!$deliveryMethod) {
      return array('error' => 'sb_not_possible_on_manifestation');
    }
    if (!$subscription) {
      return array('warning' => 'sb_no_subscription');
    }
    if ($deliveryMethod == 'postal') {
      return array('status' => 'sb_subscription_and_postal');
    }
    return array('status' => 'sb_subscription_and_electronic');
  }

  /**
   * Assert type of render array and return render array
   *
   * @param array $field
   * @return array
   */
  private function _getSingleFieldRenderArray($field) {
    switch ($field['type']) {
      case 'textfield':
        return $this->textField($field);
      case 'value':
        return $this->valueField($field);
      case 'date':
        return $this->dateField($field);
    }
  }

  /**
   * Create textfield render array from field
   *
   * @param array $field
   * @return array
   */
  private function textField($field) {
    $render = array();
    $render[$field['name']] = array(
      '#type' => 'textfield',
      '#title' => $field['title'],
      '#default_value' => $field['value'],
      '#required' => $field['required'],
    );
    return $render;
  }

  /**
   * Create value field render array from field
   *
   * @param array $field
   * @return array
   */
  private function valueField($field) {
    $render = array();
    $render[$field['name']] = array(
      '#type' => 'value',
      '#value' => $field['value'],
    );
    return $render;
  }

  /**
   * Create date field render array from field
   *
   * @param array $field
   * @param string $future
   * @param string $range
   * @return array
   */
  private function dateField($field, $future = '+ 3 month', $range = '0:+3') {
    $timestamp = strtotime(date('Y-m-d') . $future);
    $date = date('Y-m-d', $timestamp);
    $render = array();
    $render[$field['name']] = array(
      '#type' => 'date_select',
      '#title' => $field['title'],
      '#required' => $field['required'],
      '#date_label_position' => 'within',
      '#date_format' => 'd-m-Y',
      '#default_value' => $date,
      '#date_year_range' => $range,
    );
    return $render;
  }
}
