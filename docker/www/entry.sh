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

	# Check if external storage is mounted
	#if [ -d '/data/files' ]; then
#		rm -rf $APACHE_ROOT/sites/default/files
#		ln -s /data/files $APACHE_ROOT/sites/default/files
#		chown -R www-data:www-data /data/files
#	fi

#	if [ -d '/data/log' ]; then
#		rm -rf /var/log/apache2
#		ln -s /data/log /var/log/apache2
#	fi
# set mailhost
MAILCONF=/etc/exim4/update-exim4.conf.conf
	sed -i "s/mailhost\.dbc\.dk/$smarthost/" $MAILCONF

	# Prepare Drupal
# location of settings.php
	SETTINGS=/var/www/html/sites/default/settings.php
	# set cookie domain
	sed -i "s/\.bibliotek\.dk/$cookie_domain/" $SETTINGS
# location of configuration feature
	CONFIG=$APACHE_ROOT/profiles/bibdk/modules/bibdk_config/features/bibdk_webservice_settings_operational/bibdk_webservice_settings_operational.strongarm.inc
# set configuration from environment vars
	while IFS='=' read -r name value ; do
    	echo "$name $value"
	    sed -i "s|\$export\['${name}|\$strongarm->value = '${value}';\n    &|" $CONFIG
	done < <(env)

  ### OPCACHE IN PHP.INI FILE::::::
  # Enable Opcache settings
  sed -i 's/;opcache\.enable=0/opcache\.enable=1/' /etc/php/7.0/apache2/php.ini
  # Memory consumption
  sed -i 's/;opcache.memory_consumption=64/opcache.memory_consumption=192/' /etc/php/7.0/apache2/php.ini
  # Memory for interned strings
  sed -i 's/;opcache.interned_strings_buffer=4/opcache.interned_strings_buffer=16/' /etc/php/7.0/apache2/php.ini
  # Max accelerated files
  sed -i 's/;opcache.max_accelerated_files=2000/opcache.max_accelerated_files=7963/' /etc/php/7.0/apache2/php.ini
  # revalidate frequence.
  sed -i 's/;opcache.revalidate_freq=2/opcache.revalidate_freq=0/' /etc/php/7.0/apache2/php.ini
  # allow url include
  # sed -i 's/allow_url_include = Off/allow_url_include = On/' /etc/php/7.0/apache2/php.ini

  ### APACHE2.CONF FILE::::::
  # MaxKeepAliveRequests
  # sed -i 's/MaxKeepAliveRequests 100/MaxKeepAliveRequests 500/' /etc/apache2/apache2.conf
  # KeepAliveTimeout
  # sed -i 's/KeepAliveTimeout 5/KeepAliveTimeout 3/' /etc/apache2/apache2.conf
  # KeepAlive
  # sed -i 's/KeepAlive On/KeepAlive Off/' /etc/apache2/apache2.conf

  ### SETTINGS.PHP FILE::::::
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



	if [ -d '/data/log' ]; then
		echo "local0.* /data/log/watchdog.log" >> /etc/rsyslog.conf
		touch /data/log/watchdog.log
		chmod 644 /data/log/watchdog.log
	fi
	service rsyslog start

# Make a symbolic link to netpunkt modules - for simpletest to run.
	/bin/sh -c "cd $APACHE_ROOT/sites/default && ln -sf $APACHE_ROOT/profiles/bibdk/modules"

	# Start Apache
	/bin/sh -c ". /etc/apache2/envvars && /usr/sbin/apache2 -D FOREGROUND"

elif [ "$1" == 'cron' ]; then
	trap stop SIGINT SIGTERM
	/bin/sh -c "cron -f"

else
	exec "$@"
fi
