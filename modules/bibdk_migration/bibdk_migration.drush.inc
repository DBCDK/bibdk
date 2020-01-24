<?php

/**
 * TODO : Fix menu import/export (80% of this can be done with menu_import). Alt. look for patch for node_export
 * TODO : User interface: Add endpoint instead of using alias' + choose types/nodeIDs to export
 */


/**
 * Implements hook_drush_command().
 */
function bibdk_migration_drush_command()
{
  $items = array();

  $items['bibdk-deploy-nodes'] = array(
    'description' => "Deploy nodes from one installation to another",
    'arguments' => array(
      'source' => 'The site-alias to export the nodes from',
      'destination' => 'The site-alias to import the nodes to',
    ),
    'examples' => array(
      'drush bibdk-deploy-nodes @source @destination --type=bibdk_article, ' => 'Move bibdk_articles from @source to @destination.',
    ),
    'options' => array(
      'type' => 'types to export',
    ),
    'aliases' => array('bib-ne'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH, // No bootstrap at all.
  );
  return $items;
}

/**
 * Implements hook_drush_help().
 */
function bib_migration_drush_help($section)
{
// TODO Write help instructions
  switch ($section) {
    case 'meta:bibdk_migration:title':
      return dt('Bibliotek.dk migration');
    case 'meta:ding_deploy:summary':
      return dt('Deploy nodes to installations');
    case 'drush:bibdk-deploy-nodes':
      return dt("Move nodes from one installation to another. E.g. ");
  }
}

/**
 * Implements hook_drush_validate()
 */
function drush_bibdk_migration_bibdk_deploy_nodes_validate($source = null, $destination = null){

  if (!isset($source) || !isset($destination)) {
    return drush_set_error('DRUSH_ARGUMENTS_MISSING', 'You have to add both a source and destination installation');
  }
}

/**
 *
 * Exports nodes from one drupal installation into another using the node_export module
 *
 * @param null $source alias for the source site
 * @param null $destination alias for the destination site
 * @return mixed
 */
function drush_bibdk_migration_bibdk_deploy_nodes($source, $destination)
{
  $source_settings = drush_sitealias_get_record($source);
  if (empty($source_settings)) {
    return drush_set_error('DRUSH_ALIAS_NOT_FOUND', dt('Error: no alias record could be found for !source', array('!source' => $source)));
  }
  $destination_settings = drush_sitealias_get_record($destination);
  if (empty($destination_settings)) {
    return drush_set_error('DRUSH_ALIAS_NOT_FOUND', dt('Error: no alias record could be found for !destination', array('!destination' => $destination)));
  }
  if (drush_confirm(dt('move nodes from @source to @destination', array('@source' => $source, '@destination' => $destination)))) {
    $result = _copy_nodes_from_source_to_destination($source_settings, $destination_settings);
    if ($result == TRUE) {
      drush_print("Nodes have been exportet/importet");
    } else {
      drush_set_error('UNKNOWN_ERROR', 'Something went wrong. No nodes exported/importet');
    }
  }
}

function _copy_nodes_from_source_to_destination($source_settings, $destination_settings)
{
  // Export to dump-file
  $source_file = drush_node_export_dump_file($source_settings);
  if ($source_settings['remote-host']){
    if ($types = drush_get_option('type', FALSE)) {
      $types = ' --type=' . $types;
    }
    $drush_path = drush_sitealias_get_path_option($source_settings, 'drush');
    $root = $source_settings['root'];
    $username = $source_settings['remote-user'];
    $hostname = $source_settings['remote-host'];
    $ssh_options = $source_settings['ssh-options'];
    $cmd = 'cd ' . $root . '; ' . $drush_path . '/drush node-export --file=' . $source_file . $types . ' -y';
    $cmd = "ssh " . $ssh_options . " " . escapeshellarg($username) . "@" . escapeshellarg($hostname) . " " . escapeshellarg($cmd);
    drush_op_system($cmd);
  } else{
    drush_invoke_process($source_settings, 'node-export', array(), array('file' => $source_file, 'type' => drush_get_option('type', FALSE)));
  }
  // Copy Dump file to destination

  // if both source and destination is local
  if (!isset($source_settings['remote-host']) && !isset($destination_settings['remote-host'])){
    $destination_file = $source_file;
  }
  else{
    $destination_file = drush_node_export_dump_file($destination_settings);
    if(isset($source_settings['remote-host'])){
      $rsync_source_file = $source_settings['remote-user'] . '@' . $source_settings['remote-host'] . ':' . $source_file;
    }
    else {
      $rsync_source_file = $source_file;
    }
    if(isset($destination_settings['remote-host'])){
      $rsync_destination_file = $destination_settings['remote-user'] . '@' . $destination_settings['remote-host'] . ':' . $destination_file;
    }
    else {
      $rsync_destination_file = $destination_file;
    }
    require_once DRUSH_BASE_PATH . '/commands/core/rsync.core.inc';
    if (!drush_core_call_rsync($rsync_source_file, $rsync_destination_file)) {
      return FALSE;
    }
  }

  /* DO IMPORT */

  // if destination is remote
  if (!isset($destination_settings['remote-host'])){
    drush_invoke_process($destination_settings, 'node-export-import', array(), array('file' => $destination_file));
  }
  else {
    $drush_path = drush_sitealias_get_path_option($destination_settings, 'drush');
    $root = $destination_settings['root'];
    $username = $destination_settings['remote-user'];
    $hostname = $destination_settings['remote-host'];
    $ssh_options = $destination_settings['ssh-options'];
    $cmd = 'cd ' . $root . '; ' . $drush_path . '/drush node-export-import --file=' . $destination_file;
    $cmd = "ssh " . $ssh_options . " " . escapeshellarg($username) . "@" . escapeshellarg($hostname) . " " . escapeshellarg($cmd);
    drush_op_system($cmd);
  }
  return TRUE;
}

function drush_node_export_dump_file(&$site_record)
{
  $site_record['dump-is-temp'] = FALSE;
  // use the exact name provided.
  $dump_file = drush_sitealias_get_path_option($site_record, 'dump-export');
  if (!isset($dump_file)) {
    $databases = sitealias_get_databases_from_record($site_record);
    if (isset($databases)) {
      $db_spec = $databases['default']['default'];
      // Make a base filename pattern to use to name the dump file
      $filename_pattern = 'node_export';
      if (isset($db_spec['remote-host'])) {
        $filename_pattern = $db_spec['remote-host'] . '_' . $filename_pattern;
      }
    }
// If the user has set the --dump-dir option, then
// store persistant sql dump files there.
    $dump_dir = drush_sitealias_get_path_option($site_record, 'dump-dir');
    if (!isset($dump_dir)) {
// If this is a remote site, try to find a writable tmpdir.
      if (isset($site_record['remote-host'])) {
        $result = drush_invoke_process($site_record, 'ev', array('drush_print(drush_find_tmp())'), array(), array('integrate' => FALSE, 'override-simulated' => TRUE));
// If the call to invoke process does not work for some reason (e.g. drush not
// installed on the target machine), then we will just presume that the tmp dir is '/tmp'.
        if (!array_key_exists('output', $result) || empty($result['output'])) {
          $dump_dir = '/tmp';
        } else {
          $dump_dir = trim($result['output']);
        }
        $dump_file = $dump_dir . '/' . $filename_pattern . '.txt';
      } else {
        $dump_file = drush_tempnam($filename_pattern . '.txt.');
      }
      $site_record['dump-is-temp'] = TRUE;
    } else {
      $dump_file = $dump_dir . '/' . $filename_pattern . '.txt';
    }
  }
  drush_print($dump_file);
  return $dump_file;
}