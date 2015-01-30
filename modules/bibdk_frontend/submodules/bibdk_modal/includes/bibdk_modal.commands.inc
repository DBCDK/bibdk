<?php

/**
 * Returns array with command for the bibdk_custom_reload command.
 *
 * Instead of just reloading the page the bibdk_custom_reload command requests
 * the browser to go to the current URL, which is done to avoid pop-up messages
 * in FF and IE when the logs in from a page with a form displayed.
 *
 * The command is implemented in bibdk.modal.js
 *
 * @return array
 */
function bibdk_modal_command_reload() {
  return array(
    'command' => 'bibdk_modal_reload',
  );
}

/**
 * Replace the form currently displayed in a modal
 *
 * @param string $html Rendered HTML
 * @param string $selector the selector whose content should be replaced
 * @return array
 */
function bibdk_modal_command_replace_form($html, $selector = '#bibdk-modal-form'){
  return array(
    'command' => 'bibdk_modal_replace_form',
    'selector' => $selector,
    'html' => $html,
  );
}

/**
 * Dismiss the current modal
 *
 * @return array
 */
function bibdk_modal_command_dismiss(){
  return array(
    'command' => 'bibdk_modal_dismiss',
  );
}

/**
 * Do a client side redirect
 *
 * @param string $url
 * @param array $options
 * @return array
 */
function bibdk_modal_command_redirect($url, $options = array()){
  return array(
    'command' => 'bibdk_modal_redirect',
    'url' => url($url, $options),
  );

}