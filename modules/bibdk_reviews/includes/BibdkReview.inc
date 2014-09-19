<?php

/**
* @file
* Define class BibdkReview
*/

class BibdkReview {

public $xpath;
public $dom;

function __construct($xml) {
  $dom = new DomDocument();
  @$dom->loadXML($xml);
  $this->xpath = new DomXPATH($dom);
  $this->xpath->registerNamespace('docbook', 'http://docbook.org/ns/docbook');
}

  function getSections() {
    $sections = $this->xpath->query('/object/article/section');
    $return = array();
    foreach ($sections as $section) {
      $sec = array(
        'title' => '',
        'para' => '',
      );
      foreach ($section->childNodes as $node) {
        if (strpos($node->nodeName, '#') === FALSE)
          $sec[$node->nodeName] = $node->nodeValue;
      }
      $return[] = $sec;
    }
    return $return;

  }

  function getTitle() {
  $titles = $this->xpath->query('/object/article/title');
   $return = array();
   foreach ($titles as $title) {
      $return[] = $title->nodeValue;
    }
    return $return;
  }


  function getAuthor() {
    $authors = $this->xpath->query('/object/article/info/author/personname');
    $return = array();
    foreach ($authors as $author) {
      $auth = ' ';
      foreach ($author->childNodes as $node) {
        if ($node->nodeName == 'firstname')
          $auth = $node->nodeValue . $auth;
        if ($node->nodeName == 'surname')
          $auth .= $node->nodeValue;
      }
      $return[] = $auth;
    }
    return $return;

  }
}
