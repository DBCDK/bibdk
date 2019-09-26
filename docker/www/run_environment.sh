#!/usr/bin/env bash

SETTINGS=/var/www/html/sites/default/settings.php

### SETTINGS.PHP FILE::::::# POSTGRES_DB
sed -i "s/'database' => '',/'database' => '$POSTGRES_DB',/" $SETTINGS
# POSTGRES_USER
sed -i "s/'username' => '',/'username' => '$POSTGRES_USER',/" $SETTINGS
# POSTGRES_PASSWORD
sed -i "s/'password' => '',/'password' => '$POSTGRES_PASSWORD',/" $SETTINGS
# POSTGRES_HOST
sed -i "s/'host' => '',/'host' => '$POSTGRES_HOST',/" $SETTINGS