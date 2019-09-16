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
	if [ -d '/data/files' ]; then
		rm -rf $APACHE_ROOT/sites/default/files
		ln -s /data/files $APACHE_ROOT/sites/default/files
		chown -R www-data:www-data /data/files
	fi

	if [ -d '/data/log' ]; then
		rm -rf /var/log/apache2
		ln -s /data/log /var/log/apache2
	fi
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

	if [ -d '/data/log' ]; then
		echo "local0.* /data/log/watchdog.log" >> /etc/rsyslog.conf
		touch /data/log/watchdog.log
		chmod 644 /data/log/watchdog.log
	fi
	service rsyslog start

# make a symbolic link to netpunkt modules - for simpletest to run
	/bin/sh -c "cd $APACHE_ROOT/sites/default && ln -sf $APACHE_ROOT/profiles/bibdk/modules"

  /bin/sh -c "cd $APACHE_ROOT && drush cc all"

	# Start Apache
	/bin/sh -c ". /etc/apache2/envvars && /usr/sbin/apache2 -D FOREGROUND"

elif [ "$1" == 'cron' ]; then
	trap stop SIGINT SIGTERM
	/bin/sh -c "cron -f"

else
	exec "$@"
fi
