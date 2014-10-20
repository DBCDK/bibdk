<?php

/** Implements hook_bibdk_usersettings_user_tabs
 * @return array
 */
function bibdk_actions_bibdk_usersettings_user_tabs() {

  $tab['export'] = array(
    'title' => t('Export'),
    'description' => t('tab_export_description'),
    'weight' => 1,
  );

  return $tab;
}

/** Implements hook_bibdk_usersettings_user_settings
 * @return array
 */
function bibdk_actions_bibdk_usersettings_user_settings() {

  $paths = array(
    'direct' => '',
    'refworks' => 'http://www.refworks.com/express/ExpressImport.asp?vendor=bibliotek.dk&filter=RefWorks Tagged Format&encoding=28591&url=',
    'endnote' => 'http://www.myendnoteweb.com/EndNoteWeb.html?func=directExport&partnerName=bibliotek.dk&dataIdentifier=1&dataRequestUrl='
  );


  foreach ($paths as $key => $path) {
    $form['export']['bibdk_actions_' . $key] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable @type', array('@type' => t($key))),
      '#default_value' => bibdk_usersettings_user_settings_get('bibdk_actions_' . $key, TRUE),
    );
  }

  $form['export'] += array(
    '#type' => 'container',
    '#weight' => 0,
    '#tab' => 'export',
  );

  return $form;
}


/** Page that will generate a file with reference information
 * @param $ids
 * @return null The proces is killed after the file has been echoed
 */
function bibdk_actions_refexport_page($format, $ids) {
  $pids = preg_replace('@;@', ',', $ids);
  $pids = explode(',', $pids);

  try {
    bibdk_actions_refexport_file($pids, $format);
    $ids = explode(';', $ids);
    foreach ($ids as $id) {
      bibdk_cart_reservation_update_status('export_complete', $id);
    }
    die();
  }
  catch (Exception $e) {
    drupal_set_message(t('export_cannot_be_generated'), 'error');
  }

}


/**
 * Implements hook_ting_openformat_actions
 */

function bibdk_actions_ting_openformat_actions($type, $entity, $view_mode, $langcode) {
  if ($type == 'bibdkManifestation') {
    
    $refexport_links = bibdk_actions_refexport_links($entity->id);
    if (count($refexport_links)== 0 ) {
      // Nothing to display
      return $refexport_links;
    }
      
    $links = array(
      '#theme' => 'links',
      '#links' =>$refexport_links,
      '#heading' => t('export links'),
    );

    $actions['export'] = array(
      '#theme' => 'bibdk_actions_refexport',
      '#linktext' => $links,
      '#weight' => 0.5,
    );

    return $actions;
  }
}

/** link for cart actions hook
 * @param $actions
 * @return mixed
 */
function bibdk_actions_get_refexport_actions($actions) {

  $attributes = array(
    'class' => array(
      'cart-action-btn',
      'inactive'
    ),
  );

  $actions['export'] = array(
    '#theme' => 'links',
    '#links' => bibdk_actions_refexport_links(NULL, $attributes),
    '#weight' => 0,
  );

  return $actions;
}


/**
 * Return links for export of manifestations
 *
 * @param null $pid
 * @param array $attributes
 * @return array
 */
function bibdk_actions_refexport_links($pid = NULL, $attributes = array()) {
  $paths = array(
    'direct' => array(
      'path' => '',
      'target' => '_self',
      'format' => 'ris',
    ),
    'refworks' => array(
      'path' => 'http://www.refworks.com/express/ExpressImport.asp?vendor=bibliotek.dk&filter=RefWorks Tagged Format&encoding=28591&url=',
      'target' => '_blank',
      'format' => 'refWorks',
    ),
    'endnote' => array(
      'path' => 'http://www.myendnoteweb.com/EndNoteWeb.html?func=directExport&partnerName=bibliotek.dk&dataIdentifier=1&dataRequestUrl=',
      'target' => '_blank',
      'format' => 'ris',
    ),
  );

  $links = array();

  foreach ($paths as $type => $value) {
    $attributes['target'] = $value['target'];
    if (!bibdk_usersettings_user_settings_get('bibdk_actions_' . $type, TRUE)) {
      continue;
    }

    $callbackUrl = url('export/cart/', array('absolute' => TRUE)) . $value['format'] . '/' . $pid;
    if (strpos($callbackUrl, 'https') === 0) {
      $callbackUrl = substr_replace($callbackUrl, 'http', 0, 5);
    }
    $path = $value['path'] . $callbackUrl;

    $links[$type] = array(
      'title' => t('export_manifestation_' . $type, array(), array('context' => 'bibdk_actions')),
      'href' => $path,
      'attributes' => $attributes,
      'html' => TRUE,
    );
  }

  return $links;
}


/**
 * @param $ids
 * @param string $format
 */
function bibdk_actions_refexport_file($ids, $format = 'ris') {

  $ris = _bibdk_actions_refexport_get_manifestations_from_webservice($ids, $format);
  $result = _bibdk_actions_refexport_convert_result_to_ref_format($ris, $format);

  $filename = 'bibdk_' . date('Ymd_His') . '.' . $format;

  drupal_add_http_header('Content-Type', 'application/x-endnote-refer; charset=utf-8');
  drupal_add_http_header('Content-Disposition', 'attachment; filename=' . $filename);

  echo $result;
}

/** Get references with ids $ids
 * @param $ids
 * @return xml
 */
function _bibdk_actions_refexport_get_manifestations_from_webservice($ids, $objectFormat) {
  $params = array(
    'objectFormat' => $objectFormat,
    'objectId' => $ids,
    'outputType' => 'xml',
  );

  $client = new ting_client_class();

  return $client->do_request('object',$params);

}

/** extract reference format from webservice result
 * @param $result xml
 * @return array
 */
function _bibdk_actions_refexport_convert_result_to_ref_format($result, $format) {
  $dom = new DomDocument();

  if (!@$dom->loadXML($result)) {
    throw new Exception();
  }
  $xpath = new DomXPATH($dom);
  $xpath->registerNamespace('ns', 'http://oss.dbc.dk/ns/openformat');

  $nodelist = $xpath->query('//ns:' . $format);
  $ref_nodes = array();
  foreach ($nodelist as $node) {
    $ref_nodes[] = $node->nodeValue;
  }
  return implode("\n\n", $ref_nodes);
}
