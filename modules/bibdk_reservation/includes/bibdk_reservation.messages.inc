<?php

/** Printout messages for a work
 * @param $bibdk_work_entity
 */
function bibdk_reservation_get_messages($bibdk_work_entity) {
  $infotexts = _bibdk_reservation_get_infotext($bibdk_work_entity->getManifestations());
  if (!$bibdk_work_entity->isReservable() && empty($infotexts)) {
    $infotexts['status'][] = t('not_possible_to_borrow_material', array(), array('context' => 'bibdk_reservation'));
  }
  _bibdk_reservation_render_messages($infotexts);
}

/** Return action links for a work
 * @param $ids
 * @param $bibdk_work_entity
 * @return array
 */
function bibdk_reservation_get_actions($ids, $bibdk_work_entity) {
  if($links = bibdk_reservation_get_action_links($ids, $bibdk_work_entity)) {
    $form = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'reservation-online-links'
        ),
      )
    );
    $form['header'] = array(
      '#theme' => 'html_tag',
      '#tag' => 'h2',
      '#value' => t('Alternative access', array(), array('context' => 'bibdk_reservation')),
    );

    $form['description'] = array(
      '#theme' => 'html_tag',
      '#tag' => 'p',
      '#value' => t('description_text', array(), array('context' => 'bibdk_reservation')),
      '#attributes' => array(
        'class' => array(
          'bibdk-reservation-links-description'
        ),
      ),
    );

    $form['links'] = $links;

    return $form;

  }
  return $links;
}

function bibdk_reservation_get_action_links($ids, BibdkWork $bibdk_work_entity) {
  $links = array();
  $manifestation = reset($bibdk_work_entity->getManifestations());
  if ($link = bibdk_reservation_article_infomedia_link($manifestation)) {
    $links[] = $link;
  }
  if ($link = bibdk_reservation_get_sbkopi_link($ids)) {
    $links[] = $link;
  }
  if ($manifestation->hasDirectLink()) {
    $links[]['#markup'] = _ting_openformat_render_direct_link($manifestation->getInfotext(), $manifestation);
  }
  return $links;
}

/** return infomedia link for manifestation
 * @param Manifestation $manifestation
 * @return array
 */
function bibdk_reservation_article_infomedia_link(Manifestation $manifestation) {
  $link = array();
  if ($relation_link = $manifestation->getInfomediaLink()) {
    $link[] = array(
      '#theme' => 'ting_infomedia_button',
      '#ting_infomedia_button' => _ting_infomedia_get_link($manifestation->ding_entity_id, $manifestation->getInfomediaLink()),
      '#attr' => array(
        'class' => array('infomedia-button', 'text-small'),
      ),
    );
  }
  return $link;
}

/** Return sbkopi link for ids
 * @param $ids
 * @return array|null|string
 */
function bibdk_reservation_get_sbkopi_link($ids) {
  $result = bibdk_sbkopi_ajax_openorder_request($ids);
  if ($result !== 'error') {
    return $result;
  }
  return null;
}

/**
 * Parses the $infotext array and combines strings ordered by message type.
 * Returns an array of ajax commands for inserting the messages.
 *
 * @param array $infotext
 * @param string $selector
 */
function _bibdk_reservation_render_messages($infotext) {
  foreach ($infotext as $type => $text) {
    if (sizeof($text) > 0) {
      $text = implode("<br />", $text);
    }
    drupal_set_message($text, $type);
  }
}

/**
 * Extracts the infotext and renders the appropriate text.
 * If the material is available online, the link will be extracted and prepared
 * for display
 *
 * @param array $manifestations
 * @internal ManifestationMaster $manifestation
 * @return array
 */
function _bibdk_reservation_get_infotext($manifestations) {
  $infotext = array();
  $messages = array();

  /* @var $manifestation Manifestation */
  foreach ($manifestations as $manifestation) {
    $messages[$manifestation->getMessageCategory()][] = _bibdk_reservation_parse_infotext($manifestation);
  }

  ksort($messages);
  $firstMessageCategory = array_unique(reset($messages));

  foreach ($firstMessageCategory as $message) {
    $infotext[$message['type']][] = $message['infotext'];

  }
  return $infotext;
}

/** Get infotext for a given manifestation
 * @param Manifestation $manifestation
 * @return array
 */
function _bibdk_reservation_parse_infotext(Manifestation $manifestation) {
  $infocode = $manifestation->getInfotext();
  if ($manifestation->isEbook()) {
    $type = 'warning';
    $infotext = bibdk_reservation_translate('this_is_not_a_free_ebook');
  }
  else {
    $type = _bibdk_reservation_get_message_type($manifestation->getMessageCategory());
    $infotext = _bibdk_reservation_render_infotext($infocode);
  }

  return array(
    'type' => $type,
    'infotext' => $infotext,
  );
}

/**
 * Returns the appropriate type of message based on the given index param
 * @param int $index
 * @return string
 */
function _bibdk_reservation_get_message_type($index) {
  switch ($index) {
    case '1':
    case 'link':
    case 'plusLink':
      return 'status';
      break;
    case '2':
    case 'linkE17':
    case 'restrictedAccess':
      return 'warning';
      break;
    case '3':
    case '4':
    case 'noAccess':
      return 'error';
      break;
    default:
      return 'status';
      break;
  }
}


/**
 * @param string $infocode
 * @param Manifestation $manifestation
 * @return string
 */
function _ting_openformat_render_direct_link($infocode, $manifestation) {
  if($links = _bibdk_reservation_get_access_links($manifestation)) {
    return bibdk_reservation_translate("$infocode !links", array('!links' => $links));
  }
}

/**
 * Retrieves any accessUrl's from the given manifestation a string of links
 * seprated by <br />
 *
 * @param Manifestation $manifestation
 * @return string
 */
function _bibdk_reservation_get_access_links($manifestation) {
  $info = $manifestation->getAccessInformation();

  return _ting_openformat_parse_element($info, '<br/>');
}
