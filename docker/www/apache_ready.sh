#!/usr/bin/env bash
STATUS=$(curl -sI http://localhost | grep HTTP | cut -d' ' -f2)
EMPTY=$(curl -sI http://localhost | wc -l)
count=1
while [ $EMPTY > 0  ]  || [ $STATUS !=  200 ]
do
  count=$(expr $count + 1)
  EMPTY=$(curl -sI http://localhost | wc -l)
  STATUS=$(curl -sI http://localhost | grep HTTP | cut -d' ' -f2)
  if [ $count > 100 ]
  then
    exit 1
  fi
  sleep 1
done
