#!/usr/bin/env bash

# Check if we're running Apache

ps cax | grep apache2 > /dev/null

if [ $? -eq "0" ]; then
  # Check if Drupal is in maintenance mode. only get the value
  MAINT_MODE=`cd $APACHE_ROOT && drush vget --exact maintenance_mode`
  if [ $? -ne "0" ]; then
    MAINT_MODE=0
  fi
  # Get HEAD of health_check URL
  STATUS=`curl -sI http://localhost | grep HTTP | cut -d' ' -f2`
  if [[ "$MAINT_MODE" -eq "0" && "$STATUS" -eq "200" ]]; then
    # Non-maintenance running fine
    exit 0
  elif [[ "$MAINT_MODE" -eq "1" && "$STATUS" -eq "503" ]]; then
    # Maintenance mode - return OK
    exit 0
  else
    exit 1
  fi

else

  # Check if we're running cron

  ps cax | grep cron > /dev/null
  if [ $? -eq 0 ]; then
    exit 0
  # Everything else is an error
  else
    exit 1
  fi
fi
