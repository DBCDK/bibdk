#!/usr/bin/env bash

cd $APACHE_ROOT || return
drush cron
