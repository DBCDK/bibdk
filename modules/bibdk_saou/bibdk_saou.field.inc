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
 * Implements hook_field_formatter_view()
 */
function bibdk_saou_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();
  $link = '';
  foreach ($items as $delta => $item) {
    if ($entity->getRestrictedExtendedUse() != '') {
      $link = bibdk_soau_field_get_link($entity);
      if ($link != '') {
        $element[$delta] = $link;
        $element['#attached']['js'][] = drupal_get_path('module', 'bibdk_saou') . '/js/bibdk_saou.js';
      }
    } else {
      // do check for access the old way
      if ($entity->getRestrictedUse() === 'restrictedAccess') {
        $method = $entity->getRequestMethod();
        if ($method[0] === 'link' || method === 'link') {
          $link = bibdk_soau_field_get_link($entity);
          if ($link != '') {
            $element[$delta] = $link;
            $element['#attached']['js'][] = drupal_get_path('module', 'bibdk_saou') . '/js/bibdk_saou.js';
          }
        }
      }
    }
  }
  return $element;
}

/**
 * get and check for valid favourites for saou request - find at least one valid.
 * @return string: empty if fvaourite is found and data complete; errormessage if not
 */
function bibdk_soau_field_check_valid_favourites($entity) {
  $favourites = bibdk_favourite_get_favourites();
  $message = '';
  if (empty($favourites)) {
    $message = t('bibdk_saou_no_fvaourites', array(), array('context' => 'bibdk_saou'));
  }
  else {
    foreach ($favourites as $id => $favourite) {
      $agency_id = $favourite->getAgencyId();
      $userid = $favourite->getUserId();
      // only handle agencyId that starts with 7 or 8 (public and education libraries)
      if (strpos($agency_id, '7') !== 0 && strpos($agency_id, '8') !== 0 || (empty($userid))) {
        if (empty($userid)) {
          // incomplete favorite data
          $message = t('bibdk_saou_incomplete_favorite_data', array(), array('context' => 'bibdk_saou'));
        } else {
          // wrong type of library
          $message = bibdk_saou_field_get_wrong_library_link($entity);
        }
      }
      else {
        //Found one valid fvorite, clear message
        $message = '';
        return $message;
      }
    }
  }

  if ($message != '' && !is_array($message) ) {
    return array('#markup' => $message);
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
    $uri = $entity->getRestrictedExtendedUse();
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
  return $link;
}

/** get a link to ressource.
 * @param $entity; the entity to handle
 * @return string; html to display
 */
function bibdk_soau_field_get_link($entity) {
  $message = bibdk_saou_get_user_message($entity);

  if (empty($message)) {
    $output['wrapper'] = bibdk_saou_field_get_dropdown_wrapper();
    $output['wrapper']['item_list_link'] = bibdk_saou_link_to_soau_ressource($entity);
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
  $text = t('restrictedAccess', array(), array('context' => 'bibdk_saou'));
  $link = array(
    '#theme' => 'link',
    '#text' => $text,
    '#path' => '#',
    '#options' => array(
      'attributes' => array(
        'data-pid' => $entity->id,
        'class' => array('dropdown-toggle'),
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
    return bibdk_soau_field_check_valid_favourites($entity);
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
    '#markup' => drupal_render($message),
  );
  return $element;
}

/** Render array for links to soau ressource for all valid favourite libraries
 * @param $entity
 * @return array
 */
function bibdk_saou_link_to_soau_ressource($entity) {
  $message = t('restrictedAccess', array(), array('context' => 'bibdk_saou'));
  $link = array();
  $path = 'saou/ajax';
  $uri = $entity->getRemoteAccess();
  if (empty($uri)) { $uri = $entity->getRestrictedExtendedUse();}
  $pid = $entity->id;
  $favourites = bibdk_favourite_get_favourites();
  foreach ($favourites as $id => $favourite) {
    $agency_id = $favourite->getAgencyId();
    $user_id = $favourite->getUserId();
    // only handle agencyId that starts with 7 or 8 (public and education libraries)
    if (strpos($agency_id, '7') !== 0 && strpos($agency_id, '8') !== 0 || (empty($user_id))) {
      //do nothing not valid favourite
    }
    else {
      //Found valid favorite - add one link for each library
      $link[] = array(
        '#theme' => 'link',
        '#text' => $message . ' ' . $favourite->getInformation()->getAgencyName() . ' ',
        '#path' => $path,
        '#options' => array(
          'attributes' => array(
            'data-pid' => $pid,
            'data-url' => ($uri) ? $uri : 'NONE',
            'data-alt-pid' => $pid,
            'class' => array('soau-ressource-link'),
            'id' => 'bibdk_saou_' . bibdk_saou_field_pid_to_selector($pid),
            'data-agency-id' => $agency_id,
          ),
          'html' => FALSE,
        ),
      );
    } //end else
  }
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
  return $link;
}