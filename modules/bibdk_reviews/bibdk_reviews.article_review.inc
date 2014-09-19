<?php

/**
* @file
* Include file for article review content.
*/

/** Ajax submit callback. Returns rendered reviews
 * @param $form
 * @param $form_state
 * @return array
 */
function bibdk_reviews_article_ajax_trigger_form_submit($form, $form_state) {
  $ids = $form['ajax_trigger']['#ids'];
  $entity = _bibdk_reviews_get_work_entity_from_manifestation_ids($ids);
  $ids = $entity->getArticleReviews();
  $commands = array(
    ajax_command_replace('#' . $form['#id'], bibdk_reviews_get_view_for_articles($ids))
  );

  return array('#type' => 'ajax', '#commands' => $commands);
}


/** Get views for a number of articles. Takes an array of article ids as argument. Returns rendered html
 * @param $ids
 * @return null|string
 */
function bibdk_reviews_get_view_for_articles($ids) {
  $no_reviews = array(
    '#theme' => 'worktabs_no_content',
    '#no_content' => t('no reviews', array(), array('context' => 'bibdk_reviews')),
  );
  $no_reviews = drupal_render($no_reviews);

  if (!isset($ids) || !count($ids)) {
    return $no_reviews;
  }
  $works = ting_openformat_get_manifestations($ids);

  /* @var $work BibdkWork */
  $work = reset($works);
  $manifestations = $work->getManifestations();
  if (!count($manifestations)) {
    return $no_reviews;
  }

  foreach ($manifestations as $manifestation) {
    $view [] = bibdk_reviews_article_view($manifestation);
  }

  return drupal_render($view);

}

/**
 * Get render array for a single article
 *
 * @param Manifestation $manifestation
 * @return array
 */
function bibdk_reviews_article_view($manifestation) {

  $link = array(
    '#theme'   => NULL,
    '#text'    => NULL,
    '#path'    => NULL,
    '#options' => array(
      'attributes' => array(
        'title' => t('access link'),
        'id' => drupal_html_id('reviews-' . $manifestation->id),
        'class' => array('review-link'),
      ),
      'html' => TRUE,
    ),
  );

  if ( $url = $manifestation->getInfomediaLink() ) {
    $link = _ting_infomedia_get_link($manifestation->id, $url);
    $link = array(
      '#theme'                => 'ting_infomedia_button',
      '#ting_infomedia_button' => $link,
    );
  }
  elseif ( $url = $manifestation->getAccessInformation() ) {
    $request_method = $manifestation->getRequestMethod();
    $text_string = isset($request_method) ? 'review_link_text_' . $request_method : 'review_link_text';
    $accessInformation = $manifestation->getAccessInformation();
    $link['#theme'] = 'bibdk_netarchive_link';
    $link['#text'] = t($accessInformation['accessInformation'][0]['accessUrlDisplay'], array(), array('context' => 'bibdk_reviews'));
    $link['#path'] = $accessInformation['accessInformation'][0]['accessUrl'];
  }

  $rating = $manifestation->getReviewRatings();

  $title = _ting_openformat_parse_element($manifestation->getTitle());
  $title_url = l($title, 'work/' . $manifestation->id);
  $creator = $manifestation->getCreator();
  $host_publication = $manifestation->getHostPublication();
  $publisher = isset($host_publication) ? $host_publication : $manifestation->getPublisher();

  // check if there's a pdf in DBC Web archive
  $netarchive_link = NULL;
  if ( method_exists($manifestation, 'getWebArchive') && $manifestation->getWebArchive() ) {
    $local_id = urlencode($manifestation->id);
    // render array for netarchive link:
    $netarchive_link = array(
      '#theme' => 'bibdk_netarchive_link',
      '#text' => t('label_netarchive_link', array(), array('context' => 'bibdk_reviews')),
      '#path' => 'moreinfo/netarchive/' . $local_id,
      '#options' => array(
        'attributes' => array(
          'title' => t('netarchive link'),
          'id' => drupal_html_id('netarchive-' . $local_id),
          'class' => array('netarchive'),
        ),
        'html' => TRUE,
      ),
    );
  }

  return array(
    '#theme' => 'bibdk_review_article_review',
    '#title' => $title_url,
    '#creator' => t('reviewed by !creator', array('!creator' => _ting_openformat_parse_element($creator)), array('context' => 'bibdk_reviews')),
    '#publisher' => t('in !publisher', array('!publisher' => _ting_openformat_parse_element($publisher)), array('context' => 'bibdk_reviews')),
    '#link' => $link,
    '#rating' => bibdk_reviews_get_rating($rating),
    '#netarchive' => $netarchive_link,
  );

}


/** Create rating render array
 * @param $rating
 * @return array
 */
function bibdk_reviews_get_rating($rating) {
  if (!isset($rating) || !strpos($rating, '/')) {
    return;
  }

  $values = explode('/', $rating);

  $i = 0;

  while ($i < $values[1]) {
    $type = ($i < $values[0]) ? 'positive' : 'negative';
    $stars[] = array(
      '#type' => 'html_tag',
      '#tag' => 'span',
      '#value' => '*',
      '#attributes' => array(
        'class' => array('star', $type)
      ),
    );
    $i++;
  }

  return $stars;
}
