
An attempt to make development easier with docker and docker compose.

prerequisites:
docker and docker-compose (and git)

-----------------------------------------------------------------------------------------------
to install bibliotek.dk:

1. Copy bibdk_development folder to whereever you want your installation to reside.
    NOTICE - it is important that you copy ENTIRE folder and contents - do not rename the folder - docker-compose
    names its network and containers from the folder it is run in, and scripts uses naming of containers to exec commands
2. cd into bibdk_development folder
3. run build.sh ($ . build.sh) && run.sh ($ . run.sh)

wait ... containers may show up as unhealthy for a little while - be patient it takes about 5 minutes for database and drupal
to initialize and synchronize

bibliotek.dk can now be seen on localhost:8080

In the folder a html/ dir is generated - the bibdk repo is in html/profiles/bibdk, so go ahead and do your development.
Changes in code will be reflected on localhost:8080.

To run on another port you will have to edit the docker-compose.yml file.

--------------------------------------------------------------------------------------------------
to clean up:
- minimal: run
    `$docker-compose down`
this will close the docker network and release port 8080

- total: run
    `$docker-compose down --rmi all`
this will close the docker network, release port 8080 and delete all containers and images in the network

Downloaded files will have to be deleted manually

