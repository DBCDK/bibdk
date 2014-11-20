<?php
/**
 * @file
 * remaining field definitions for the bibdk_saou field
 *
 * field_info and field_load hooks are in the bibdk_saou_field module to enable
 * deletion of field
 *
 * see http://drupal.org/node/1285540
 */

/**
 * Implements hook_field_formatter_info().
 */
function bibdk_saou_field_formatter_info() {
  return array(
    'bibdk_saou_link_default' => array(
      'label' => t('Default'),
      'field types' => array(
        'bibdk_saou_link',
      ),
    )
  );
}

/**
 * Implements hook_field_formatter_view().
 */
function bibdk_saou_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();
  foreach ($items as $delta => $item) {
    // check if entity has fields with restricted access and is a link
    if ($entity->getRestrictedUse() === 'restrictedAccess' && $entity->getRequestMethod() == 'link') {
      $link = bibdk_soau_field_get_link($entity);
      $element[$delta] = $link;
      $element['#attached']['js'][] = drupal_get_path('module', 'bibdk_saou') . '/js/bibdk_saou.js';

    }
  }

  return $element;
}

/**
 * get and check favourites for saou request.
 * @return string: empty if fvaourite is found and data complete; errormessage if not
 */
function bibdk_soau_field_check_favourites($entity) {
  $favourites = bibdk_favourite_get_favourites();
  $message = '';
  if (empty($favourites)) {
    $message = t('bibdk_saou_no_fvaourites', array(), array('context' => 'bibdk_saou'));
  }
  else {
    $fav = current($favourites);
    $agency_id = $fav->getAgencyId();
    $userid = $fav->getUserId();
    // only handle agencyId that starts with 7 (public libraries)
    if (strpos($agency_id, '7') !== 0) {
      $message = bibdk_saou_field_get_wrong_library_link($entity);
    }
    elseif (empty($userid)) {
      $message = t('bibdk_saou_incomplete_favorite_data', array(), array('context' => 'bibdk_saou'));
    }
  }

  return $message;
}

/**
 * get a link stating that this is an unknown library
 * @param $entity
 * @return string
 */
function bibdk_saou_field_get_wrong_library_link($entity) {
  $message = t('bibdk_saou_unknown_library', array(), array('context' => 'bibdk_saou'));
  $uri = $entity->getRemoteAccess();

  if (empty($uri)) {
    $uri = $entity->getRelationUri();
  }

  $pid = $entity->id;

  $link = array(
    '#theme' => 'link',
    '#text' => $message,
    '#path' => $uri,
    '#options' => array(
      'attributes' => array(
        'data-pid' => $pid,
        'id' => 'bibdk_saou_' . bibdk_saou_field_pid_to_selector($pid),
      ),
      'html' => FALSE,
    ),
  );

  return drupal_render($link);
}

/** get a link to ressource.
 * @param $entity; the entity to handle
 * @return string; html to display
 */
function bibdk_soau_field_get_link($entity) {
  $message = bibdk_saou_get_user_message($entity);

  if (empty($message)) {
    $output['wrapper'] = bibdk_saou_field_get_dropdown_wrapper();
    $output['wrapper']['link'] = bibdk_saou_link_to_soau_ressource($entity);
  }
  else {
    $output = bibdk_saou_field_get_link_and_toggle_element($entity, $message);
  }

  return drupal_render($output);
}

/** Get a render array with link to saou ressorce
 * @param $entity; the entity to handle
 * @param $message; text for the link
 * @return array; render array as expected by drupal_render
 */
function bibdk_saou_field_get_link_and_toggle_element($entity, $message) {
  $output['wrapper'] = bibdk_saou_field_get_dropdown_wrapper();
  $output['wrapper']['link'] = bibdk_saou_field_get_message_link($entity);
  $output['wrapper']['toggle'] = bibdk_saou_field_get_element_to_toggle($message);

  return $output;
}

/** get a render array with no link to reesource. this is to diplay messages
 * for users not logged in or incomplete userdata in favourites
 * @param $entity
 * @return array
 */
function bibdk_saou_field_get_message_link($entity) {
  $text = t($entity->getRestrictedUse(), array(), array('context' => 'bibdk_saou'));
  $link = array(
    '#theme' => 'link',
    '#text' => $text,
    '#path' => '#',
    '#options' => array(
      'attributes' => array(
        'data-pid' => $entity->id,
        'class' => array('dropdown-toggle'),
        //'id' => 'bibdk_saou_' . $entity->id,
        'id' => 'bibdk_saou_' . bibdk_saou_field_pid_to_selector($entity->id),
      ),
      'html' => FALSE,
    ),
  );

  return $link;
}

/** get a wrapper for dropdown message
 * @return array
 */
function bibdk_saou_field_get_dropdown_wrapper() {
  return array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('dropdown-wrapper'),
    )
  );
}

/** check if user is provider user, and favourite library is complete
 * @return string; appropiate message for user
 */
function bibdk_saou_get_user_message($entity) {
  if (!ding_user_is_provider_user()) {
    return bibdk_saou_link_to_login();
  }
  else {
    return bibdk_soau_field_check_favourites($entity);
  }
}

/** Get a render array to toggle
 * @param $message; the message to display
 * @return array; render array as expected by drupal_render
 */
function bibdk_saou_field_get_element_to_toggle($message) {
  $element = array();
  if (empty($message)) {
    return $element;
  }

  $element['container'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('dropdown-menu', 'btn', 'hidden'),
    )
  );
  $element['container']['text'] = array(
    '#markup' => $message,
  );

  return $element;
}

/** Render array for link to soau ressource
 * @param $entity
 * @return array
 */
function bibdk_saou_link_to_soau_ressource($entity) {
  $message = t($entity->getRestrictedUse(), array(), array('context' => 'bibdk_saou'));
  $path = 'saou/ajax';
  $uri = $entity->getRemoteAccess();

  if (empty($uri)) {
    $uri = $entity->getRelationUri();
  }

  $pid = $entity->id;
  $link_collection_identifier = $entity->getlinkCollectionIdentifier();

  $link = array(
    '#theme' => 'link',
    '#text' => $message,
    '#path' => $path,
    '#options' => array(
      'attributes' => array(
        'data-pid' => $pid,
        'data-url' => ($uri) ? $uri : 'NONE',
        'data-alt-pid' => ($link_collection_identifier) ? $link_collection_identifier : 'NONE',
        'class' => array('soau-ressource-link'),
        'id' => 'bibdk_saou_' . bibdk_saou_field_pid_to_selector($pid),
      ),
      'html' => FALSE,
    ),
  );

  return $link;
}

/** Make a valid html id from given pid
 * @param $pid; id for entity
 * @return string; valid html id (no ':' and '_')
 */
function bibdk_saou_field_pid_to_selector($pid) {
  $pattern = array('/-/', '/:/');
  $replacement = array('_', '_');

  return preg_replace($pattern, $replacement, $pid);

}

/** Get a link to login
 * @return string; rendered array
 */
function bibdk_saou_link_to_login() {
  $message = t('saou_log_in_to_accesss_ressource', array(), array('context' => 'bibdk_saou'));
  $path = 'user/login';
  $link = array(
    '#theme' => 'link',
    '#text' => $message,
    '#path' => $path,
    '#options' => array(
      'attributes' => array(),
      'html' => FALSE,
    ),
  );

  return drupal_render($link);
}