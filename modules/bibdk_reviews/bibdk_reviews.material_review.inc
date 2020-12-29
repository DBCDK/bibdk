<?php

/**
* @file
* Include file for material review content.
*/

/** Ajax submit callback. Returns rendered reviews
 * @param $form
 * @param $form_state
 * @return array
 */
function bibdk_reviews_material_ajax_trigger_form_submit($form, $form_state) {
  $ids = $form['ajax_trigger']['#ids'];
  $entity = _bibdk_reviews_get_work_entity_from_manifestation_ids($ids);
  $ids = $entity->getMaterialReview();
  $commands = array(
    ajax_command_replace('#' . $form['#id'], bibdk_reviews_view($ids))
  );

  return array('#type' => 'ajax', '#commands' => $commands);

}


/** Create view for reviews
 * @param $review_ids
 * @return bool|string
 */
function bibdk_reviews_view($review_ids) {
  $no_reviews_found = array(
    '#theme' => 'worktabs_no_content',
    '#no_content' => t('no_reviews_found', array(), array('context' => 'bibdk_reviews')),
  );
  $no_reviews_found = drupal_render($no_reviews_found);

  if (!isset($review_ids) || !is_array($review_ids) || count($review_ids) == 0) {
    return $no_reviews_found;
  }

  $type = $review_ids['type'];
  unset($review_ids['type']);

  $xml = _bibdk_reviews_getReview_from_webservice($review_ids);
  $reviews = _bibdk_review_convert_result_to_bibdk_reviews($xml);

  // Render the view
  $elements = array();
  $note = '';
  foreach ($reviews as $review) {
    if ($type === 'dbcaddi:hasReusedReview') {
      $relations = $review->getRelations();
      $pid = '';
      foreach ($relations as $relation) {
        if (strpos($relation, 'dbcaddi:isReviewOf') > -1) {
          $pid = str_replace('dbcaddi:isReviewOf', '', $relation);
          break;
        }
      }
      $note = _bibdk_create_original_note($pid);
    }
    $link_field = $review->getSections($reviews);
    $elements[] = array(
      '#theme' => 'bibdk-review-material-review',
      '#reusednote' => render($note),
      '#titles' => implode(', ', $review->getTitle()),
      '#authors' => implode(', ', $review->getAuthor()),
      '#sections' => $link_field,
    );
  }

  if (count($elements)) {
    $reviews_marcxs = _bibdk_review_convert_result_to_bibdk_reviews_marc($xml);
    foreach ($reviews_marcxs as $review_marc) {
      $reviews_marcx_link = $review_marc->getSubfields();
    }
    $return_review = drupal_render($elements);
    //replace marcxchange
    return _bibdk_reviews_insert_link($return_review, $reviews_marcx_link);
  }
  return $no_reviews_found;
}

/** Create note with link to originally reviewed material.
 * @param string $pid
 * @return array
 */
function _bibdk_create_original_note($pid) {
  $note = t('This review was originally created for ', array(), array('context' => 'bibdk_reviews'));
  $link = array(
    '#theme' => 'link',
    '#text' => t('this version', array(), array('context' => 'bibdk_reviews')),
    '#path' => 'search/work',
    '#options' => array(
      'query' => array(
        'search_block_form' => $pid,
      ),
      'attributes' => array('class' => array('bibliotekdk-primary-version-link'), 'target' => '_blank'),
      'html' => TRUE,
    ),
  );
  $render_array = array(
    '#type' => 'html_tag',
    '#tag' => 'div',
    '#attributes' => array(
      'class' => array('reused-note'),
    ),
    '#value' => $note . render($link),
  );
  return $render_array;
}


/** Get reviews with ids $ids
 * @param $ids
 * @return array An array of BibdkReview objects
 */
function _bibdk_reviews_getReview_from_webservice($ids) {

  $params = array(
    'objectFormat' => array('docbook','marcxchange'),
    'objectId' => $ids,
    'outputType' => 'xml',
    'relationData' => 'uri',
  );

  $client = new ting_client_class();

  return $client->do_request('object',$params);

}

/** Converts result from webservice to BibdkReview Objects - marcxchange attribute
 * @param $result xml
 * @return array
 */
function _bibdk_review_convert_result_to_bibdk_reviews_marc($result) {
  $dom = new DomDocument();

  if (!$dom->loadXML($result)) {
    watchdog('bibdk_reviews', t('BIBDK material review could not load response: %xml', array('%xml' => var_export($xml, TRUE))), array(), WATCHDOG_ERROR);
  }
  $xpath = new DomXPATH($dom);
  $xpath->registerNamespace('ns', 'http://oss.dbc.dk/ns/opensearch');

  $nodelist = $xpath->query('//ns:object');
  $reviews = array();
  foreach ($nodelist as $node) {
    // domdocument wants the xmlns on the node
    $node->setAttribute('xmlns:marcx', 'info:lc/xmlns/marcxchange-v1');
    $reviews[] = new BibdkReview($node->ownerDocument->saveXML($node));
  }
  return $reviews;
}


/** Converts result from webservice to BibdkReview Objects - docbook attribute
 * @param $result xml
 * @return array
 */
function _bibdk_review_convert_result_to_bibdk_reviews($result) {
  $dom = new DomDocument();

  if (!$dom->loadXML($result)) {
    watchdog('bibdk_reviews', t('BIBDK material review could not load response: %xml', array('%xml' => var_export($xml, TRUE))), array(), WATCHDOG_ERROR);
  }
  $xpath = new DomXPATH($dom);
  $xpath->registerNamespace('ns', 'http://oss.dbc.dk/ns/opensearch');

  $nodelist = $xpath->query('//ns:object');
  $reviews = array();
  foreach ($nodelist as $node) {
    // domdocument wants the xmlns on the node
    $node->setAttribute('xmlns:docbook', 'http://docbook.org/ns/docbook');
    $reviews[] = new BibdkReview($node->ownerDocument->saveXML($node));
  }

  return $reviews;
}

/** Replace all replace tags in review text
 * @param $replace_link string
 * @param $replace_targets array
 * @return string
 */
function _bibdk_reviews_insert_link($replace_link, $replace_targets) {
  $return_replace_link = $replace_link;
  foreach ($replace_targets as $replace_target){
    $target_link = bibdk_review_make_search_link($replace_target);
    $return_replace_link = str_replace($replace_target, $target_link, $return_replace_link);
  }
  return $return_replace_link;
}

/** Makes link to replace into review text
 * @param $title string
 * @return string
 */
function bibdk_review_make_search_link($title) {

  $review_link = array(
    '#theme' => 'link',
    '#text' => $title,
    '#path' => 'search/work/',
    '#prefix' =>'<span class="bibdk-review-link">',
    '#suffix' => '</span>',
    '#options' => array(
      'query' => array('search_block_form' => '"' . $title . '"'),
      'fragment' => 'content',
      'attributes' => array(
        'title' => $title,
      ),
      'html' => TRUE,
    ),
  );
  return  drupal_render($review_link);

}
