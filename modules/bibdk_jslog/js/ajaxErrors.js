
/**
 * NOTES; we might want to redefine msic/drupal.js::Drupal.ajaxError method
 */


/**
 * Handler for the form redirection error.
 *
 * NOTICE this script overwrites misc/ajax.inc::Drupal.ajax.prototype.error
 *
 */
if ( Drupal.ajax ) {
    Drupal.ajax.prototype.error = function (response, uri) {
        // this is what Drupal.ajax.prototype.error normally alerts:
        // alert(Drupal.ajaxError(response, uri));
        //alert(Drupal.t('An ajax error occurred. Please contact administrator if problem persists'));
        // remove the spinner
        if( this.progress.element ){
            this.progress.element.remove();
        }
        var variables = new Array();
        Drupal.watchdog('ajax-error','an ajax error occurred', variables, Drupal.watchdog.ERROR, window.location.pathname);
    };
};


// following script is a (modified) copy from http://drupal.org/project/jswatchdog
Drupal.watchdog = function(type, message, variables, severity, link) {
    var data, i;
    data = {
        type: 'js:' + type,
        message: message,
        severity: severity || Drupal.watchdog.NOTICE,
        link: link || window.location.pathname
    };

    // Serialize the variables object.
    for (i in variables) {
        if (variables.hasOwnProperty(i)) {
            data['variables[' + i +']'] = variables[i];
        }
    }

 // Some basic flood control to prevent drupal from bootstrapping if
 // not needed
  if (Drupal.settings.jslog_flood > 0) {
    jQuery.post(Drupal.settings.basePath + 'jslog', data);
  }

  Drupal.settings.jslog_flood--;
};

// @see watchdog_severity_levels();
Drupal.watchdog.EMERG    = 0;
Drupal.watchdog.ALERT    = 1;
Drupal.watchdog.CRITICAL = 2;
Drupal.watchdog.ERROR    = 3;
Drupal.watchdog.WARNING  = 4;
Drupal.watchdog.NOTICE   = 5;
Drupal.watchdog.INFO     = 6;
Drupal.watchdog.DEBUG    = 7;



