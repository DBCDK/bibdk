#!/usr/bin/env bash

set -e

DAEMON=apache2

stop() {
  echo "Received SIGINT or SIGTERM. Shutting down $DAEMON"
  exit 0
  # Get PID
  pid=$(cat /var/run/$DAEMON/$DAEMON.pid)
  # Set TERM
  kill -SIGTERM "${pid}"
  # Wait for exit
  wait "${pid}"
  # All done.
  echo "Done."
}

if [ "$1" == '' ]; then
  # Make sure Apache shuts down properly
  trap stop SIGINT SIGTERM


  # Prepare Drupal
  # location of configuration feature
  CONFIG=$APACHE_ROOT/profiles/bibdk/modules/bibdk_config/features/bibdk_webservice_settings_operational/bibdk_webservice_settings_operational.strongarm.inc
  # set configuration from environment vars
  while IFS='=' read -r name value; do
    echo "$name $value"
    #old expression - overwrite value by adding a line with new value
    #sed -i "s|\$export\['${name}|\$strongarm->value = '${value}';\n    &|" $CONFIG
    #new expression - replace line holding the value (it must be JUST AFTER the $strongarm->name AND BE A SINGLE LINE for this to work)
    #sed -i "/\$strongarm->name = '${name}'/{n;s/.*/  \$strongarm->value = '${value}';/;}" $CONFIG
    #sed -i "s|\$strongarm->name = '${name}'/{n;s/.*|\$strongarm->value = '${value}';|;}" $CONFIG
    sed -i "/\$strongarm->name = '${name}'/{n;s|.*|  \$strongarm->value = '${value}';|;}" $CONFIG
  done < <(env)

  ### PHP.INI FILE::::::
  PHPINI=/etc/php/7.3/apache2/php.ini
  # sendmail
  sed -i 's:;sendmail_path =:sendmail_path = /usr/sbin/ssmtp -t:' $PHPINI
  # increase memory_limit
  sed -i 's/memory_limit = 128M/memory_limit = 512M/' $PHPINI
  # increase max_input_vars
  sed -i 's/;max_input_vars = 128M/max_input_vars = 2048/' $PHPINI

  # allow url include
  # sed -i 's/allow_url_include = Off/allow_url_include = On/' $PHPINI
  echo "sendmail_path = /usr/bin/msmtp -t" >>$PHPINI

  ### APACHE2.CONF FILE::::::
  # MaxKeepAliveRequests
  sed -i 's/MaxKeepAliveRequests 100/MaxKeepAliveRequests 500/' /etc/apache2/apache2.conf
  # KeepAliveTimeout
  sed -i 's/KeepAliveTimeout 5/KeepAliveTimeout 3/' /etc/apache2/apache2.conf
  # KeepAlive
  sed -i 's/KeepAlive On/KeepAlive Off/' /etc/apache2/apache2.conf

  ### SETTINGS.PHP FILE::::::
  # location of settings.php
	SETTINGS=/var/www/html/sites/default/settings.php
	# COOKIE DOMAIN
	#sed -i "s/\.bibliotek\.dk/$COOKIE_DOMAIN/" $SETTINGS
  # POSTGRES_DB
  sed -i "s/'database' => '',/'database' => '$POSTGRES_DB',/" $SETTINGS
  # POSTGRES_USER
  sed -i "s/'username' => '',/'username' => '$POSTGRES_USER',/" $SETTINGS
  # POSTGRES_PASSWORD
  sed -i "s/'password' => '',/'password' => '$POSTGRES_PASSWORD',/" $SETTINGS
  # POSTGRES_HOST
  sed -i "s/'host' => '',/'host' => '$POSTGRES_HOST',/" $SETTINGS
  # NAMESPACE_NAME
  sed -i "s/frontend-staging/$NAMESPACE_NAME/" $SETTINGS
  # MEMCACHE_SERVER
  sed -i "s/@MEMCACHE_SERVER@/$MEMCACHE_SERVER/" $SETTINGS

  # We do not want this on frontend-features where we don't use https.
  if [ "$NAMESPACE_NAME" != 'frontend-features' ]; then
    ### HTACCESS FILE::::::::::
    # location of .htaccess
    HTACCESS=/var/www/html/.htaccess
    # Make apache jump to https when accessed with http.
    echo 'Header always set Content-Security-Policy "upgrade-insecure-requests;"' >>$HTACCESS
  fi

  # only set files files folder if we are NOT in prod
  if [ "$NAMESPACE_NAME" != "frontend-prod" ]; then
    cd /tmp || return
    tar -xf files.tar.gz
    mkdir files/private
    #rm -rf /var/www/html/sites/default/files/
    cp -Rf files /var/www/html/sites/default
    chown -Rf www-data:www-data /var/www/html/sites/default/files
    rm -rf files files.tar.gz
  fi

  service rsyslog start

  # Make a symbolic link to modules - for simpletest to run.
  /bin/sh -c "cd $APACHE_ROOT/sites/default && ln -sf $APACHE_ROOT/profiles/bibdk/modules"

  # Start Apache
  /bin/sh -c ". /etc/apache2/envvars && /usr/sbin/apache2 -D FOREGROUND"

elif [ "$1" == 'cron' ]; then
  trap stop SIGINT SIGTERM
  /bin/sh -c "cron -f"

else
  exec "$@"
fi
