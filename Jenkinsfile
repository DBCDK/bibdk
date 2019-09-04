#! groovy
// general vars
def DOCKER_REPO = "docker-dscrum.dbc.dk"
def PRODUCT = 'bibliotek.dk'
def BRANCH = 'master'
// var for kubernetes
def NAMESPACE = 'frontend-prod'

def TARFILE
// artifactory vars
def BUILDNAME = 'Bibliotek.dk :: ' + BRANCH
def ARTYSERVER = Artifactory.server 'arty'
def ARTYDOCKER

def DISTROPATH = "https://raw.github.com/DBCDK/bibdk/develop/distro.make"

pipeline {
  agent {
    node { label 'dscrum-is-builder-i01' }
  }
  options {
    buildDiscarder(logRotator(artifactDaysToKeepStr: "", artifactNumToKeepStr: "", daysToKeepStr: "", numToKeepStr: "5"))
    timestamps()
    gitLabConnection('gitlab.dbc.dk')
    // Limit concurrent builds to one pr. branch.
    disableConcurrentBuilds()
  }
  stages {
    stage('jenkins cleanup') {
      steps {
        script {
          cleanWs()
        }
      }
    }
    stage('build bibdk') {
      agent {
        docker {
          image "docker-dscrum.dbc.dk/d7-php7-builder:latest"
          alwaysPull true
        }
      }
      steps {
        sh """
            pwd
            ls -la
            
        """
        script {
          withCredentials([sshUserPrivateKey(credentialsId: "frontend-github", keyFileVariable: 'keyfile')]) {
            sh """
            drush make -v --strict=0 --dbc-modules=master --concurrency=30 --no-gitinfofile --contrib-destination=profiles/bibdk $DISTROPATH www
            """
          }
        }
      }
    }
  }
}
