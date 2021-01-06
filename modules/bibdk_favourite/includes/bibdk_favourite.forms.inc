<?php

/**
 * @file bibdk_favourite forms related methods
 */

/**
 * Returns the users favourite libraries as a form render array
 *
 * @param $form
 * @param $form_state
 * @return array
 */
function bibdk_favourite_get_favourites_form($form, $form_state) {
  // Link to vejviser
  $form['vejviser_link_wrapper'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('bibdk-favourite-vejviser-link'),
    ),
  );
  $form['vejviser_link_wrapper']['vejviser_link'] = _bibdk_favourite_get_vejviser_link();

  // Make sure new agencies are pulled from webservice
  $name = bibdk_favourite_check_for_new_agency();
  if ($name) {
    bibdk_favourite_forms_set_message($name);
  }

  // Get all user agencies
  $agencies = bibdk_favourite_get_favourites();

  $form['favorites'] = array(
    '#type' => 'container',
    '#prefix' => '<div class="element">',
    '#suffix' => '</div>',
    '#attributes' => array(
      'class' => array(
        'element-wrapper'
      ),
    ),
  );

  // Build agency elements
  if (!empty($agencies)) {
    $count = 0;
    foreach ($agencies as $id => $branch) {

      $form['favorites']['bibdk_favourite_' . $id] = bibdk_favourite_form_view_items_from_session($branch, $count++);
    }
  }
  else {
    $form['empty'] = bibdk_favourite_empty_favourite_form_element();
  }

  return $form;
}

function bibdk_favourite_empty_favourite_form_element() {
  $form['container'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('element-section'),
    ),
  );
  $form['container']['no_agencies'] = array(
    '#markup' => t('no_favourites_saved'),
  );
  return $form;
}

/**
 * Checks through the GET paramter if new agencies are added.
 *
 * @return array|bool|null|string
 */
function bibdk_favourite_check_for_new_agency() {
  $name = FALSE;
  if (isset($_GET['agency'])) {
    if (!isset($_SESSION['bibdk_favourites'][$_GET['agency']])) {
      if (_bibdk_favourite_save_on_webservice($_GET['agency'])) {
        if (isset($_SESSION['bibdk_favourites'])) {
          // unset favourites to reload from webservice
          unset($_SESSION['bibdk_favourites']);
        }
        // get the agency

        try {
          $cache = \DBC\VC\CacheMiddleware\MemcachedCacheMiddleware::createCacheMiddleware(
            array(array('url' => 'localhost', 'port' => 11211)), 3600, 'bibdk'
          );
          $url = variable_get('vip_core_url', 'http://vipcore.iscrum-vip-prod.svc.cloud.dbc.dk');

          $vipcore = new \DBC\VC\VipCore($url, 10, 'bibdk-bibdk_favorite', $cache);
          $response = $vipcore->findLibrary($_GET['agency']);

        } catch (Exception $e) {
          throw new Exception($e);
        }

        $agency = new VipCoreAgencyBranch($response);
        global $language;
        $name = $agency->getBranchName();
      }
    }
    else {
      $agency = unserialize($_SESSION['bibdk_favourites'][$_GET['agency']]);
      global $language;
      $name = $agency->getBranchName();
    }
  }
  return $name;
}

function bibdk_favourite_forms_set_message($name) {
  $editpath = 'overlay/favourite/userdata/' . $_GET['agency'];
  $options = array('attributes' => array('class' => array(' bibdk-popup-link')));
  $linktext = t('add_user_data', array(), array('context' => 'bibdk_favorite'));
  $link = l($linktext, $editpath, $options);
  $text = t('%bibname has been added. Remember to ', array('%bibname' => $name), array('context' => 'bibdk_favourite'));
  drupal_set_message($text . $link, 'warning');
}

/**
 * the form to be displayed on profile tab
 * */
function bibdk_favourite_form_view_items_from_session($favourite, $weight, $toggle_enabled = TRUE, $action_enabled = TRUE) {
  global $language;

  $form = array();
  $branch = $favourite->getBranch();

  if (empty($branch)) {
    return;
  }
  // check if given branch is set as order-agency
  $links = bibdk_favourite_get_action_links($favourite);
  $actions = ($action_enabled) ? theme('bibdk_favourite_action_links', array('links' => $links)) : NULL;

  $moreinfo = array(
    '#theme' => 'bibdk_favourite_more_info',
    '#branch' => $branch,
    '#openingHours' => theme('bibdk_favourite_opening_hours', array('branch' => $favourite)),
    '#tools' => array('#theme' => 'bibdk_favourite_tools', '#branch' => $favourite),
    '#address' => theme('bibdk_favourite_address', array('branch' => $favourite)),
    '#contact' => theme('bibdk_favourite_contact', array('branch' => $favourite)),
    '#toggle_enabled' => $toggle_enabled,
  ) ;
  $classes = array();
  $classes[] = 'favourite-' . $favourite->getAgencyId();
  if ($favourite->getOrderAgency()) {
    $classes[] = 'order-agency';
  }

  $form[$favourite->getAgencyId()]['library'] = array(
    '#theme' => 'bibdk_favourite_library',
    '#branchName' => $favourite->getBranchShortName($language->language),
    '#agencyName' => $favourite->getAgencyName(),
    '#actions' => $actions,
    '#add_classes' => $classes,
    '#moreinfo' => $moreinfo,
    '#branchid' => $favourite->branchId,
    '#toggle_enabled' => $toggle_enabled
  );

  // place branch on top if set as order-agency
  $form[$favourite->getAgencyId()]['#weight'] = ($favourite->getOrderAgency()) ? -1 : $weight;

  return $form;
}

/**
 * Get links for editing favourite agency (delete, set as order-agency, edit
 * user data)
 *
 * @param FavouriteAgency $favourite
 * @return array $links HTML (unordered list)
 *
 * NOTICE text and classes are also set in javascript. @see js/setFavourite.js
 */
function bibdk_favourite_get_action_links($favourite) {
  // add ajax library to intrepret the use-ajax class
  drupal_add_library('system', 'drupal.ajax');
  $order_agency = ($favourite->getOrderAgency());
  if ($order_agency) {
    $order_txt = t('Order agency');
    $link_class = 'selected-agency';
  }
  else {
    $order_txt = t('set_as_favourite');
    $link_class = 'not-selected-agency';
  }
  $edit_text = ($favourite->getUserData()) ?
    t('edit_user_data', array(), array('context' => 'bibdk_favorite')) :
    t('add_user_data', array(), array('context' => 'bibdk_favorite'));

  $links = array();
  $links[] = array(
    '#theme' => 'link',
    '#text' => $order_txt,
    '#path' => 'favourite/add/' . $favourite->getAgencyId(),
    '#options' => array(
      'attributes' => array(
        'alt' => $order_txt,
        'class' => array(
          'use-ajax',
          'set-default-order-agency',
          $link_class
        ),
      ),
      'html' => FALSE,
    ),
  );

  $links[] = array(
    '#theme' => 'link',
    '#text' => $edit_text,
    '#path' => 'overlay/favourite/userdata/' . $favourite->getAgencyId(),
    '#options' => array(
      'attributes' => array(
        'alt' => $order_txt,
        'data-rel' => array('bibdkFavorite'),
        'class' => array(
          'edit-personal-info',
          'bibdk-popup-link',
        ),
      ),
      'html' => FALSE,
    ),
  );

  $links[] = array(
    '#theme' => 'link',
    '#text' => t('Remove favoritelibrary', array(), array('context' => 'bibdk_favourite')),
    '#path' => 'favourite_delete/ajax/' . $favourite->getAgencyId(),
    '#options' => array(
      'attributes' => array(
        'alt' => t('Remove favoritelibrary', array(), array('context' => 'bibdk_favourite')),
        'class' => array(
          'use-ajax',
          'bibdk-favourite--add-remove-library',
          'bibdk-favourite--library-is-favourited',
        ),
      ),
      'html' => FALSE,
      'svg' => 'svg-star',
    ),
  );

  return $links;
}

/**
 * Render user fields;
 */
function bibdk_favourite_user_form_fields($form, &$form_state, $branchid = NULL) {

  if (!$branchid && !empty($form_state['branchid'])) {
    $branchid = $form_state['branchid'];
  }

  // set title of page
  $page_title = _bibdk_favourite_set_user_data_page_title($branchid);
  drupal_set_title($page_title);

  $favourites = bibdk_favourite_get_favourites();
  if (isset($favourites[$branchid])) {
    $agency = $favourites[$branchid];
    $userData = $agency->getUserData();
    $action = array(
      '#type' => 'submit',
      '#value' => t('Save'),
      '#submit' => array('bibdk_favourite_set_userdata'),
      '#attributes' => array(
        'class' => array('favourite-data-save-button'),
      ),
    );
  }
  else {
    $userData = array();
    $action = array(
      '#type' => 'submit',
      '#value' => t('Save as favourite agency'),
      '#submit' => array('bibdk_favourite_save_favourite'),

    );
  }

  $fields = bibdk_favourite_get_agency_fields($branchid);

  $form = bibdk_favourite_userdata_form($form, $form_state, $fields, $userData, $branchid);

  $form['branchid'] = array(
    '#type' => 'hidden',
    '#value' => $branchid,
  );

  $form['#validate'][] = 'bibdk_favourite_borchk';
  $form['#validate'][] = 'bibdk_favourite_validate_email';
  $form['#attributes'] = array(
    'id' => array('bibdk-favourite-user-form'),
  );

  $form['wrapper']['submit'] = $action;

  return $form;
}

/**
 * Set the page title of the userdata page
 *
 * @param $branchid
 * @return null|string
 */
function _bibdk_favourite_set_user_data_page_title($branchid) {
  $branchName = '';
  $favourites = bibdk_favourite_get_favourites();
  if (isset($favourites[$branchid])) {
    global $language;
    $name = $favourites[$branchid]->getBranchName();
    $branchName = isset($name) ? $name : '';
  }

  return t('Edit data for @library', array('@library' => $branchName));
}

function bibdk_favourite_validate_email($form, $form_state) {
  if (!empty($form_state['values']['userMail']) && !valid_email_address($form_state['values']['userMail'])) {
    form_set_error('userEmail', t('Email needs to be a valid email', array(), array('context' => 'bibdk_favourite:userdata')));
  }
}
