#!/usr/bin/env bash
function check_and_wait(){
URL=$1
echo $URL
OK="200"
count=1
success=1
# eternal loop
echo "wait for site:"
while :
do
  # wait for the old container to shut up
  sleep 2
  echo -n '.'
  count=$((count+1))
  if [ $count -gt 180 ]
  then
    echo -n "TIMEOUT"
    exit 1
  fi
  STATUS=$(curl -sI --max-time 5 $URL | grep HTTP | cut -d' ' -f2)
  if [ -z "$STATUS" ]
  then
    continue
  fi
  if [ "$STATUS" = "$OK" ]
  then
    success=$((success+1))
    if [ $success -gt 2 ]
    then
      echo -n $STATUS 
      echo "running drush commands"
      exit 0
    else
      continue
    fi
  fi
done
}

check_and_wait $1

