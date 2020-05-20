#!/usr/bin/env bash
# run temporary container - we need to run it with env vars to match docker-compose setup
# see www_env.list
docker run -d --env-file www_env.list --name fisk docker-dscrum.dbc.dk/bibliotek-dk-www-develop
# copy vcs files
docker cp fisk:/var/www/html/ .
# stop and remove containers
docker kill fisk
docker rm fisk
echo "done - see html folder for code"

