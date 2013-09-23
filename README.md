bibdk
============

Besides the info provided the info on the wiki: ````https://github.com/DBCDK/bibdk/wiki/Installation-af-bibdk````
the following procedure for downloading the bibdk-profile including core can be used:

 1. clone this repo to e.g. your local web-root
 2. Run the following command from the command-line:
 ````$ drush make --working-copy --dbc-modules=develop --no-gitinfofile --contrib-destination=profiles/bibdk prof/dist.make [NAME]````