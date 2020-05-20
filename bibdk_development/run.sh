# run containers
docker-compose up -d
# wait for site
./check_and_wait.sh "http://localhost:8080"
# run drush commands
docker exec -it bibdk_development_drupal_1 /bin/bash -c "cd /var/www/html/ && drush fra -y"
# we need to delete the bibdk sql file in case of restarts
docker exec -it bibdk_development_postgres_db_1 /bin/bash -c "cd /docker-entrypoint.d && rm -f bibdk_db.sql"
