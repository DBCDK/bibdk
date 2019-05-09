#!groovy

def PRODUCT = 'bibliotekdk'
// remove 'feature/' from BRANCH_NAME
def BRANCH = BRANCH_NAME.replaceAll('feature/', '')

node('dscrum-is-builder-i01'){
  stage('Get code') {
    checkout scm
  }

  stage('build code'){
    echo BRANCH_NAME
  }

  stage('create database'){

  }

  stage('build stylesheet'){

  }

  stage('site install'){

  }

  stage('deploy'){

  }
}
