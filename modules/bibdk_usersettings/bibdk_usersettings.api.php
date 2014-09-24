<?php

/** Implements hook_bibdk_usersettings_user_tabs
 * @return array
 */
function hook_bibdk_usersettings_user_tabs(){

  $tab['export'] = array(
    'title'  => t('Export'),
    'description' => t('tab_export_description'),
    'weight' => 5,
  );

  return $tab;
}

/** Implements hook_bibdk_usersettings_user_settings
 * @return array
 */
function hook_bibdk_usersettings_user_settings(){

  $paths = array(
    'direct' => '',
    'refworks' => 'http://www.refworks.com/express/ExpressImport.asp?vendor=bibliotek.dk&filter=RefWorks Tagged Format&encoding=28591&url=',
    'endnote' => 'http://www.myendnoteweb.com/EndNoteWeb.html?func=directExport& partnerName=bibliiotek.dk&dataIdentifier=1&dataRequestUrl='
  );


  foreach($paths as $key => $path){
    $form['export']['bibdk_actions_' . $key] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable @type', array('@type' => t($key))),
      '#default_value' => bibdk_usersettings_user_settings_get('bibdk_actions_' . $key, TRUE),
    );
  }

  $form['export'] += array(
    '#type' => 'container',
    '#weight' => 5,
    '#tab' => 'export',
  );

  return $form;
}
