#!groovy

properties([buildDiscarder(logRotator(artifactDaysToKeepStr: '', artifactNumToKeepStr: '', daysToKeepStr: '', numToKeepStr: dscrumDefaults.numToKeepStr())),
            pipelineTriggers([]),
            parameters([booleanParam(defaultValue: true, description: 'if not checked - run tests only', name: 'build_and_deploy')]),
            disableConcurrentBuilds()])


def PRODUCT = 'bibliotekdk'

node('master'){
  stage('Get code') {
    checkout scm
  }
}
