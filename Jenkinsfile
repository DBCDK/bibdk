#!groovy

def PRODUCT = 'bibliotekdk'
// remove 'feature/' from BRANCH_NAME
def BRANCH = BRANCH_NAME.replaceAll('feature/', '')
// this is a static installation while we wait for the docker world
def WWW_PATH = '/data/www/'
// postgres database to use for bibliotek.dk installation
def PG_NAME = "feature_${BRANCH}"


node('dscrum-is-builder-i01'){
  stage('delete and build code'){
    sh """
        rm -rf $WWW_PATH$BRANCH
      """
    dir(WWW_PATH+BRANCH){
      checkout scm
      sh """
        git checkout develop
        drush make -v --working-copy --strict=0 --dbc-modules=$BRANCH_NAME --no-gitinfofile --contrib-destination=profiles/netpunkt distro.make .
      """
    }
  }

  stage('create database'){
    sh """
      dropdb $PG_NAME | true
      createdb $PG_NAME
    """
  }

  stage('build stylesheet'){
    dir(WWW_PATH+BRANCH+'profiles/bibdk/themes/bibdk_theme/.npm') {
      sh """
          npm install
          gulp build
        """
    }
  }

  stage('site install'){
    def PROFILE = 'bibdk'
    def URI =
    dir(WWW_PATH+BRANCH) {
      // get secret settings for site install
      def DB_SETTINGS = readYaml file: 'profiles/bibdk/modules/bibdk_config/docker/environment.yml'
      echo DB_SETTINGS.db.pg_user

      sh """
        PGPASSWORD=$DB_SETTINGS.db.pg_password drush -y si $PROFILE \
        --db-url=pgsql://$DB_SETTINGS.db.pg_user:$DB_SETTINGS.db.pg_password@$DB_SETTINGS.db.pg_host/$PG_NAME \
        --uri=$DB_SETTINGS.gui.uri$BRANCH --account-pass=$DB_SETTINGS.gui.gui_pass \
        --site-name=bibliotek.dk
      """


    }
  }

  stage ('drush: finish installation'){
    dir(WWW_PATH+BRANCH){
      sh """
          drush cc all
          drush rr
          drush updb
          drush fra -y
        """
    }
  }

  stage('run selenium test'){
    git 'https://git.dbc.dk/BibdkWebdriver.git'
    sh """
      export PATH=/home/isworker/bin/:$PATH
      export BIBDK_WEBDRIVER_URL=http://dscrum-is-builder-i01.dbc.dk/$WWW_PATH$BRANCH
      # start python virtual environment for deploying selenium test
      # virtualenv venv
      . /home/isworker/venv/bin/activate
      nosetests tests/test*.py --with-xunit -v
    """
  }
}
