#!/usr/bin/env bash
STATUS=$(curl -sI http://localhost | grep HTTP | cut -d' ' -f2)
count=1
while [ -z "$STATUS" ] || [ "$STATUS" -ne "200" ]
do
  count=$(expr $count + 1)
  echo $count
  STATUS=$(curl -sI http://localhost | grep HTTP | cut -d' ' -f2)
  if [ $count -gt "200" ]
  then
    exit 1
  fi
  sleep 1
done
