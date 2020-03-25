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
  # Enable Opcache settings
  sed -i 's/;opcache\.enable=0/opcache\.enable=1/' $PHPINI
  # Memory consumption
  sed -i 's/;opcache.memory_consumption=64/opcache.memory_consumption=192/' $PHPINI
  # Memory for interned strings
  sed -i 's/;opcache.interned_strings_buffer=4/opcache.interned_strings_buffer=16/' $PHPINI
  # Max accelerated files
  sed -i 's/;opcache.max_accelerated_files=2000/opcache.max_accelerated_files=7963/' $PHPINI
  # revalidate frequence.
  sed -i 's/;opcache.revalidate_freq=2/opcache.revalidate_freq=0/' $PHPINI
  # increase memory_limit
  sed -i 's/memory_limit = 128M/memory_limit = 512M/' $PHPINI
  # allow url include
  # sed -i 's/allow_url_include = Off/allow_url_include = On/' $PHPINI
  echo "sendmail_path = /usr/bin/msmtp -t" >> $PHPINI
  echo "sendmail_path = /usr/bin/msmtp -t" >> $PHPINI

  ### APACHE2.CONF FILE::::::
  # MaxKeepAliveRequests
  sed -i 's/MaxKeepAliveRequests 100/MaxKeepAliveRequests 500/' /etc/apache2/apache2.conf
  # KeepAliveTimeout
  sed -i 's/KeepAliveTimeout 5/KeepAliveTimeout 3/' /etc/apache2/apache2.conf
  # KeepAlive
  sed -i 's/KeepAlive On/KeepAlive Off/' /etc/apache2/apache2.conf

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
