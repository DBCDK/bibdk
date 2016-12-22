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
        if ((is_array($method) && $method[0] === 'link' ) || $method === 'link') {
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
        //Found one valid favorite, clear message
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
    // logged in
    $output['wrapper'] = bibdk_saou_field_get_dropdown_wrapper();
    $output['wrapper']['main_link'] = bibdk_saou_field_get_restricted_link($entity);
    $output['wrapper']['item_list_link'] = bibdk_saou_link_to_soau_ressource($entity);
  }
  else {
    //not logged in - redirect to login
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
function bibdk_saou_field_get_restricted_link($entity) {
  $text = t('getRestrictedAccess', array(), array('context' => 'bibdk_saou'));
  $link = array(
    '#theme' => 'link',
    '#text' => $text,
    '#path' => '#',
    '#options' => array(
      'attributes' => array(
        'data-pid' => $entity->id,
        'class' => array('soau-ressource-click-links'),
        'id' => 'bibdk_saou_' . bibdk_saou_field_pid_to_selector($entity->id),
      ),
      'html' => FALSE,
    ),
  );
  return $link;
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
  $link['container'] = bibdk_saou_field_get_dropdown_link_wrapper();
  $uri = $entity->getRemoteAccess();
  if (empty($uri)) { $uri = $entity->getRestrictedExtendedUse();}

  $favourites = bibdk_favourite_get_favourites();
  foreach ($favourites as $id => $favourite) {
    $agency_id = $favourite->getAgencyId();
    $user_id = $favourite->getUserId();
    // only handle agencyId that starts with 7 or 8 (public and education libraries)
    if (strpos($agency_id, '7') !== 0 && strpos($agency_id, '8') !== 0 || (empty($user_id))) {
      //do nothing not valid favourite
    }
    else {
      $idlink = bibdk_saou_get_data($entity->id, $uri, $agency_id, $saou_error);
      if ($saou_error) {
        $link['container'][] = bibdk_saou_field_get_saou_error_link_wrapper($idlink, $favourite);
      } else {
        $link['container'][] = bibdk_saou_field_get_saou_link_wrapper($idlink, $favourite);
      }
    }
  }
  return $link;
}

/** get a wrapper for dropdown link message
 * @return array
 */
function bibdk_saou_field_get_dropdown_link_wrapper() {
  return array(
    '#type' => 'container',
    '#attributes' => array(
       'class' => array('dropdown-menu-link', 'hidden'),
    )
  );
}

/** get a wrapper for dropdown saou error link message
 * @return array
 */
function bibdk_saou_field_get_saou_error_link_wrapper($idlink, $favourite) {
  return array(
    '#theme' => 'link',
    '#text' => t($idlink, array(), array('context' => 'bibdk_saou')) . ' ' . $favourite->getInformation()->getAgencyName() . ' ',
    '#path' => '',
    '#options' => array(
      'attributes' => array(
        'disabled' => 'disabled',
        'class' => array('inactive'),
      ),
      'html' => FALSE,
    ),
  );
}

/** get a wrapper for dropdown saou error link message
 * @return array
 */
function bibdk_saou_field_get_saou_link_wrapper($idlink, $favourite) {
  return array(
    '#theme' => 'link',
    '#text' => t('checkAccess', array(), array('context' => 'bibdk_saou')) . ' ' . $favourite->getInformation()->getAgencyName() . ' ',
    '#path' => $idlink,
    '#options' => array(
      'attributes' => array(
        'target' => '_blank',
      ),
      'html' => FALSE,
    ),
  );
}

/** get a saou data - error or link message
 * @return array
 */
function bibdk_saou_get_data($pid = NULL, $url = NULL, $agency_id = NULL, &$sou_error ) {
  $alt_pid = $pid;
  if ($url == 'NONE') { $url = NULL; }
  if ($alt_pid == 'NONE') { $alt_pid = NULL; }
  $sou_error = FALSE;

  //use case: pid starts with 870970-basis and no relationurl is given
  if (strpos($pid, '870970-basis') === 0 && empty($url)) {
    $output = bibdk_saou_ajax_fetchLicensByPid($pid, $agency_id);
  }
  elseif (!empty($url)) {
    $output = bibdk_saou_fetchLicenseByUrl($pid, $url, $alt_pid, $agency_id);
  }
  else {
    // default behoviour
    $output = bibdk_saou_ajax_fetchLicensByPid($pid, $agency_id);
  }

  if ( $output['error'] == '' ) {
    $return_output = $output['redirect'];
  } else {
    $sou_error = TRUE;
    $return_output = $output['error'];
  }

  return $return_output;
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