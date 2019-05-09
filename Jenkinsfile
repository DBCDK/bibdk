#!groovy

def PRODUCT = 'bibliotekdk'
// remove 'feature/' from BRANCH_NAME
def BRANCH = BRANCH_NAME.replaceAll('feature/', '')
// this is a static installation while we wait for the docker world
def WWW_PATH = '/data/www/'
// postgres database to use for bibliotek.dk installation
def PG_NAME = "feature_${BRANCH}"

node('dscrum-is-builder-i01'){
  stage('Get code') {
    checkout scm
  }

  stage('build code'){
    echo BRANCH
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
      createdb $PG_NAME
    """
  }

  stage('build stylesheet'){

  }

  stage('site install'){

  }

  stage('deploy'){

  }
}
