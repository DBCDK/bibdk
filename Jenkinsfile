#!groovy

properties([buildDiscarder(logRotator(artifactDaysToKeepStr: '', artifactNumToKeepStr: '', daysToKeepStr: '', numToKeepStr: '5')),
            pipelineTriggers([]),
            disableConcurrentBuilds()])

def PRODUCT = 'bibliotekdk'
// remove 'feature/' from BRANCH_NAME
def BRANCH = BRANCH_NAME.replaceAll('feature/', '')
// this is a static installation while we wait for the docker world
def WWW_PATH = '/data/www/'
// postgres database to use for bibliotek.dk installation
def PG_NAME = "feature_${BRANCH}"
// path to npm
def NPM_PATH = "${WWW_PATH}${BRANCH}/profiles/bibdk/themes/bibdk_theme/.npm/"
// path to distro make (develop version)
def DISTRO_PATH = "https://raw.githubusercontent.com/DBCDK/bibdk/develop/distro.make"


node('dscrum-is-builder-i01') {

  stage('cleanup old code') {
    sh """
      if [ -d ${WWW_PATH}${BRANCH} ]; then
        chmod -R u+w ${WWW_PATH}${BRANCH} | true
        rm -rf ${WWW_PATH}${BRANCH}* | true
      fi
      """
  }



  stage('build code') {
    dir(WWW_PATH + BRANCH) {
      sh """
        drush make -v --working-copy --strict=0 --dbc-modules=$BRANCH_NAME --no-gitinfofile --contrib-destination=profiles/bibdk $DISTRO_PATH .
      """
    }
  }


  stage('create database') {
    sh """
     dropdb $PG_NAME | true
     createdb $PG_NAME
   """
  }


  stage('site install') {
    dir(WWW_PATH + BRANCH) {
      // get secret settings for site install
      def DB_SETTINGS = readYaml file: 'profiles/bibdk/modules/bibdk_config/docker/environment.yml'

      sh """
       PGPASSWORD=$DB_SETTINGS.db.pg_password drush -y si bibdk \
       --db-url=pgsql://$DB_SETTINGS.db.pg_user:$DB_SETTINGS.db.pg_password@$DB_SETTINGS.db.pg_host/$PG_NAME \
       --uri=$DB_SETTINGS.gui.uri$BRANCH/ --account-pass=$DB_SETTINGS.gui.gui_pass \
       --site-name=bibliotek.dk
     """
    }
  }

  stage('drush: finish installation') {
    dir(WWW_PATH + BRANCH) {
      sh """
         drush en bibdk_webservice_settings_develop -y
         drush cc all
         drush rr
         drush updb
         drush fra -y
       """
    }
  }

  stage('build stylesheet') {
    dir(NPM_PATH) {
      sh """
         export PATH="$PATH:/home/isworker/.nvm/versions/node/v8.0.0/bin"
         npm install
         gulp build
         drush cc all
       """
    }
  }

  stage('run selenium test') {
    git 'https://git.dbc.dk/BibdkWebdriver.git'
    sh """
     git checkout develop
     git pull
     export PATH=/home/isworker/bin/:$PATH
     export BIBDK_WEBDRIVER_URL=http://dscrum-is-builder-i01.dbc.dk/$BRANCH/
     # start python virtual environment for deploying selenium test
     # virtualenv venv
     . /home/isworker/venv/bin/activate
     nosetests tests/test*.py --with-xunit -v
   """
    // TODO generate junit report
  }

  // @TODO run simpletest also

}
