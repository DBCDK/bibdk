<?php
/**
 * Created by IntelliJ IDEA.
 * User: pjo
 * Date: 2/19/14
 * Time: 12:37 PM
 */

require_once('bibdk_voxb.node.inc');

/** Parse response from OUI::bindVoxbRequest
 * @param $xml
 * @return bool|string
 */
function bibdk_voxb_parse_bind_voxb_response($xml, &$error_msg = '') {
  try {
    $xp = bibdk_voxb_get_xpath($xml);
  }
  catch (bibdkVoxbException $e) {
    // rethrow
    throw $e;
  }

  $query = '//voxb:error';
  $nodelist = $xp->query($query);
  if ($nodelist->length > 0) {
    $error_msg = $nodelist->item(0)->nodeValue;
    throw bibdkVoxbException::ouiError();
  }

  $query = '//oui:userId';
  $nodelist = $xp->query($query);
  if ($nodelist->length != 1) {
    // something is wrong
    return FALSE;
  }

  return $nodelist->item(0)->nodeValue;
}

/** Parse the response from VOXB::updateMyDataResponse
 * @param $xml
 * @return bool|string; FALSE if something is wrong; voxb_id (userId) from voxb-service
 * @throws Exception
 */
function bibdk_voxb_parse_update_data_response($xml, &$error_msg = '') {
  try {
    $xp = bibdk_voxb_get_xpath($xml);
  }
  catch (bibdkVoxbException $e) {
    // rethrow
    $error_msg = 'INVALID XML:' . $xml;
    throw $e;
  }

  $query = '//voxb:error';
  $nodelist = $xp->query($query);
  if ($nodelist->length > 0) {
    $error_msg = $nodelist->item(0)->nodeValue;
    throw bibdkVoxbException::ouiError();
  }

  $query = '//voxb:voxbIdentifier';
  $nodelist = $xp->query($query);
  if ($nodelist->length != 1) {
    // something is wrong
    return FALSE;
  }

  return $nodelist->item(0)->nodeValue;

}

/** Parse the response from VOXB::createUserRequest
 * @param $xml
 * @return bool|string
 */
function bibdk_voxb_parse_create_user_response($xml, &$error_msg = '', &$suggestion = '') {
  try {
    $xp = bibdk_voxb_get_xpath($xml);
  }
  catch (bibdkVoxbException $e) {
    // rethrow
    throw $e;
  }

  $query = '//voxb:error';
  $nodelist = $xp->query($query);
  if ($nodelist->length > 0) {
    $error_msg = $nodelist->item(0)->nodeValue;
    throw bibdkVoxbException::ouiError();
  }

  $query = '//voxb:userAliasSuggestion';
  $nodelist = $xp->query($query);
  if ($nodelist->length > 0) {
    $suggestion = $nodelist->item(0)->nodeValue;
  }

  $query = '//voxb:userId';
  $nodelist = $xp->query($query);
  if ($nodelist->length != 1) {
    // something is wrong
    return FALSE;
  }

  return $nodelist->item(0)->nodeValue;
}

/** Parse response from OUI::getVoxb
 * @param $xml
 * @return bool|string; FALSE if something is wrong; voxb_id (userId) from voxb-service
 * @throws Exception
 */
function _bibdk_voxb_parse_get_voxb_response($xml, &$error_msg = '') {
  try {
    $xp = bibdk_voxb_get_xpath($xml);
  }
  catch (bibdkVoxbException $e) {
    // rethrow
    throw $e;
  }

  $query = '//oui:error';
  $nodelist = $xp->query($query);
  if ($nodelist->length > 0) {
    // this is fatal: either a database error, or somehow user is not in database
    $error_msg = $nodelist->item(0)->nodeValue;
    throw bibdkVoxbException::ouiError();
  }

  $query = '//oui:voxbId';
  $nodelist = $xp->query($query);
  if ($nodelist->length != 1) {
    // this is NOT fatal, but something is wrong
    return FALSE;
  }
  $voxb_id = $nodelist->item(0)->nodeValue;

  return $voxb_id;
}

/** Parse response xml from VOXB::fetchDataRequest
 * @param $xml
 * @return mixed; stdObject ->ratingCount ->rating ->reviews
 * @throws Exception
 */
function bibdk_voxb_parse_fetchdata_request($xml) {
  try {
    $xpath = bibdk_voxb_get_xpath($xml);
  }
  catch (bibdkVoxbException $e) {
    // rethrow
    throw $e;
  }

  // parse for reatings
  $ret = bibdk_voxb_set_ratings($xpath);

  // parse for reviews

  $reviews = bibdk_voxb_set_reviews($xpath);
  if (!empty($reviews)) {
    $ret->reviews = $reviews;
  }

  return $ret;
}

/** Get the review node for a single voxb-item
 *
 * @param $xml
 * @throws bibdkVoxbException
 * @throws Exception
 */
function bibdk_voxb_get_review_node($xml) {
  try {
    $xpath = bibdk_voxb_get_xpath($xml);
  }
  catch (bibdkVoxbException $e) {
    // rethrow
    throw $e;
  }

  $query = '//voxb:userItems';
  $node_list = $xpath->query($query);
  $review = bibdk_voxb_set_review($node_list->item(0));

  return $review;
}

/**
 * @param $xpath
 * @return stdObject ->ratingCount, ->rating
 */
function bibdk_voxb_set_ratings($xpath) {
  // parse for ratings
  $query = '//voxb:averageRating';
  $nodelist = $xpath->query($query);
  if ($nodelist->length > 0) {
    $ret->rating = $nodelist->item(0)->nodeValue;
    $query = '//voxb:totalNumberOfRaters';
    $ret->ratingCount = $xpath->query($query)->item(0)->nodeValue;
  }
  if (empty($ret)) {
    $ret->ratingCount = (int) 0;
    $ret->rating = (int) 0;
  }

  return $ret;
}

/** Parse for reviews
 * @param $xpath
 * @return array [stdObject]
 */
function bibdk_voxb_set_reviews($xpath) {
  // parse for reviews
  $reviews = array();
  $query = '//voxb:userItems';
  $nodelist = $xpath->query($query);
  if ($nodelist->length > 0) {
    foreach ($nodelist as $node) {
      try {
        $review = bibdk_voxb_get_review($node);
      }
      catch (Exception $e) {
        watchdog('voxb', 'Caught exception on bibdk_voxb_get_review(): ' . $e->getMessage(), array(), WATCHDOG_ERROR);
      }
      if (!empty($review)) {
        $review->markup = bibdk_voxb_blog_node_view($review->node);
        $reviews[] = $review;
      }
    }
  }

  return $reviews;
}

/**
 * @param $node ; a node holding user-items from voxb (ratings, reviews ..)
 */
function bibdk_voxb_get_review($node) {
  $is_review = $node->getElementsByTagName('review');
  if ($is_review->length > 0) {
    $review = bibdk_voxb_set_review($node);
    // try to get the blog from drupal
    $blog_node = bibdk_voxb_blog_node_update($review);

    if (empty($blog_node)) {
      $blog_node = bibdk_voxb_blog_node_create($review);
      // Prepare node for saving
      $node = node_submit($blog_node);
      node_save($blog_node);
      // check if node has been saved correctly
      if (!isset($node->nid)) {
        throw new bibdkVoxbException('node not saved');
      }
    }
    $review->node = $blog_node;

    return $review;
  }

  return FALSE;
}

/** Parse for review. given node is an userItem which holds a review
 * @param $node
 * @return stdObject ->alias ->profileLink ->Title ->reviewData ->date
 *
 */
function bibdk_voxb_set_review($node) {
  global $user;
  $rev = new stdClass();
  $rev->voxb_userid = $node->getElementsByTagName('userId')->item(0)->nodeValue;
  $alias = $node->getElementsByTagName('aliasName')->item(0)->nodeValue;
  $rev->alias = bibdk_voxb_parsers_check_alias($alias);

  $rev->profileLink = $node->getElementsByTagName('profileLink')
    ->item(0)->nodeValue;
  $rev->date = $node->getElementsByTagName('timestampModified')
    ->item(0)->nodeValue;
  $identifier = $node->getElementsByTagName('voxbIdentifier')
    ->item(0)->nodeValue;
  $rev->voxb_identifier = $identifier;
  $rev->link = bibdk_voxb_review_teaser_link($identifier);
  $rev->edit_link = bibdk_voxb_review_edit_link($identifier, $rev->voxb_userid);
  if (isset($node->getElementsByTagName('reviewTitle')->item(0)->nodeValue)) {
    $rev->Title = $rev->Title = $node->getElementsByTagName('reviewTitle')
      ->item(0)->nodeValue;
  }
  if (isset($node->getElementsByTagName('reviewData')->item(0)->nodeValue)) {
    $rev->reviewData = $node->getElementsByTagName('reviewData')
      ->item(0)->nodeValue;
  }
  if (isset($rev->reviewData)) {
    $rev->teaser = bibdk_voxb_make_review_teaser($rev->reviewData);
  }

  return $rev;
}

function bibdk_voxb_parsers_check_alias($alias) {
  // is this an autogenerated alias from bibliotek.dk?
  if (strpos($alias, 'bibliotek.dk:') === 0) {
    $alias_not_set = t('bibdk_voxb_auto_alias', array(), array('context' => 'bibdk_voxb'));

    return 'bibliotek.dk:' . $alias_not_set;
  }

  return $alias;
}

function bibdk_voxb_review_teaser_link($identifier) {
  $path = 'voxb/review/' . $identifier;
  $link = array(
    '#type' => 'link',
    '#title' => t('Read_review', array(), array('context' => 'voxb')),
    '#href' => $path,
    '#attributes' => array('class' => array('bibdk-voxb-link')),
  );

  return drupal_render($link);
}

function bibdk_voxb_make_review_teaser($reviewTxt) {
  $teaser = substr($reviewTxt, 0, 100);
  $teaser .= ' ... ';

  return $teaser;
}

function bibdk_voxb_parser_parse_createReview($xml) {
  $xpath = bibdk_voxb_get_xpath($xml);

  return '1234';
}

/** Initialize an xpath object from given xml
 * @param $xml
 * @return bool|DOMXPath; False on failure, object on success
 */
function bibdk_voxb_get_xpath($xml) {
  $dom = new DOMDocument();
  if (!@$dom->loadXML($xml)) {
    throw bibdkVoxbException::malformedXml($xml);
  }
  $xp = new DOMXPath($dom);
  $xp->registerNamespace('voxb', 'http://oss.dbc.dk/ns/voxb');
  $xp->registerNamespace('oui', 'http://oss.dbc.dk/ns/openuserinfo');

  return $xp;
}

/** Helper function. Check if needle is in multidimensional array
 * @param $needle
 * @param array $haystack
 * @return mixed; the array holding the needle if found, FALSE if not
 */
function bibdk_voxb_in_multi_array($needle, array $haystack) {
  if (empty($haystack)) {
    return FALSE;
  }
  foreach ($haystack as $item) {
    // NOTICE recursive
    if (($item == $needle) || (is_array($item) && bibdk_voxb_in_multi_array($needle, $item))) {
      return $item;
    }
  }

  return FALSE;
}

/** Helper function. Check if user has already reviewed (ie. accepted use of review terms)
 * @param array $data
 * @return boolean
 */
function bibdk_voxb_accepted_review_terms(array $data) {
  if (empty($data)) {
    return FALSE;
  }
  foreach ($data as $item) {
    if (isset($item['voxb:item']) && isset($item['voxb:item']['voxb:review'])) {
      return TRUE;
    }
  }

  return FALSE;
}
