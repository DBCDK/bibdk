#!/usr/bin/env bash

# Prepare Drupal

# location of settings.php
SETTINGS=/var/www/html/sites/default/settings.php
APACHE_CONF=/etc/apache2/sites-enabled/000-default.conf
FQDN_CONF=/etc/apache2/conf-available/fqdn.conf
# location of configuration feature
CONFIG=$APACHE_ROOT/profiles/bibdk/modules/bibdk_config/features/bibdk_webservice_settings_operational/bibdk_webservice_settings_operational.strongarm.inc

if [[ "$NAMESPACE_NAME" != "frontend-prod" ]] ; then
  cd /tmp || return
  tar -xf files.tar.gz
  rm -rf /var/www/html/sites/default/files/*
  cp -Rf files /var/www/html/sites/default
  chown -Rf www-data:www-data /var/www/html/sites/default/files
  rm -rf files files.tar.gz
  cd /var/www/html
fi

# set configuration from environment vars
while IFS='=' read -r name value; do
  echo "$name $value"
  sed -i "s/@${name}@/$(echo $value | sed -e 's/\//\\\//g; s/&/\\\&/g')/g" $SETTINGS
  sed -i "s|\$export\['${name}|\$strongarm->value = '${value}';\n    &|" $CONFIG
done < <(env)

if [ -d '/data/log' ]; then
  echo "local0.* /data/log/watchdog.log" >>/etc/rsyslog.conf
  touch /data/log/watchdog.log
  chmod 644 /data/log/watchdog.log
fi
#ervice rsyslog start

# We need https=on in the 000-default.conf file.
sed -i '/^\s*Alias/a SetEnvIf X-Forwarded-Proto https HTTPS=on' $APACHE_CONF

# make a symbolic link to modules - for simpletest to run
/bin/sh -c "cd $APACHE_ROOT/sites/default && ln -sf $APACHE_ROOT/profiles/bibdk/modules"

# Update php ini to enable mail sending.
PHPINI=/etc/php/7.3/apache2/php.ini
# increase memory_limit
sed -i 's/memory_limit = 128M/memory_limit = 512M/' $PHPINI
# increase max_input_vars
sed -i 's/;max_input_vars = 128M/max_input_vars = 2048/' $PHPINI
# Enable mail sending
echo "sendmail_path = /usr/bin/msmtp -t" >>$PHPINI

if [ "$STARTUP" == 'cron' ]; then
  drush cron -r /var/www/html
else
  /entrypoint.sh
fi
