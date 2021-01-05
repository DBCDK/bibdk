<?php

/**
* @file
* Define class BibdkReview
*/

class BibdkReview {

public $xpath;
public $dom;

function __construct($xml) {
  $dom = new DomDocument('1.0', 'utf-8');
  @$dom->loadXML($xml);
  $this->xpath = new DomXPATH($dom);
  $this->xpath->registerNamespace('docbook', 'http://docbook.org/ns/docbook');
}

  /**
  * Get marcxchange subfield y for makeing link in material reviews
  * @return array
  */
  function getSubfields() {
    $this->xpath->registerNamespace('marcx', 'info:lc/xmlns/marcxchange-v1');
    $return = array();
    //search for subfield y
    $datafields = $this->xpath->query('/object/marcx:collection/marcx:record/marcx:datafield/marcx:subfield[@code="y"]');
    foreach ($datafields as $datafield) {
      foreach ($datafield->childNodes as $node) {
          $return[] = $node->nodeValue;
      }
    }
    return $return;
  }

  /**
   * Get section from DocBook (Materialevurderinger)
   * @return array
   */
  function getSections() {
    $sections = $this->xpath->query('/object/docbook:article/docbook:section');
    $return = array();
    foreach ($sections as $section) {
      $sec = array(
        'docbook:title' => '',
        'docbook:para' => '',
      );
      foreach ($section->childNodes as $node) {
        if (strpos($node->nodeName, '#') === FALSE)
          $sec[$node->nodeName] = $node->nodeValue;
      }
      $return[] = $sec;
    }

    return $return;

  }

  /**
   * Get title from DocBook (Materialevurderinger)
   * @return array
   */
  function getTitle() {
  $titles = $this->xpath->query('/object/docbook:article/docbook:title');
   $return = array();
   foreach ($titles as $title) {
      $return[] = $title->nodeValue;
    }
    return $return;
  }

  /**
   * Get author (reviewer) from DocBook (Materialevurderinger)
   * @return array
   */
  function getAuthor() {
    $authors = $this->xpath->query('/object/docbook:article/docbook:info/docbook:author/docbook:personname');
    $return = array();
    foreach ($authors as $author) {
      $auth = ' ';
      foreach ($author->childNodes as $node) {
        if ($node->nodeName == 'docbook:firstname')
          $auth = $node->nodeValue . $auth;
        if ($node->nodeName == 'docbook:surname')
          $auth .= $node->nodeValue;
      }
      $return[] = $auth;
    }
    return $return;

  }

  /**
   * Get relations from OpenSearch response
   * @return array
   */
  function getRelations() {
    $relations = $this->xpath->query('/object/relations/relation');
    $return = array();
    foreach ($relations as $relation) {
      $return[] = $relation->nodeValue;
    }
    return $return;
  }
}
