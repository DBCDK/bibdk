#! groovy
// general vars
def DOCKER_REPO = "docker-dscrum.dbc.dk"
def PRODUCT = 'bibliotek_dk'
def BRANCH = 'develop'
// var for kubernetes
def NAMESPACE = 'frontend-prod'

def TARFILE
// artifactory vars
def BUILDNAME = 'Bibliotek_dk :: ' + BRANCH
def ARTYSERVER = Artifactory.server 'arty'
def ARTYDOCKER

def DISTROPATH = "https://raw.github.com/DBCDK/bibdk/develop/distro.make"

pipeline {
  agent {
    node { label 'devel8-head' }
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
    stage('build and stash bibdk code') {
      agent {
        docker {
          image "docker-dscrum.dbc.dk/d7-php7-builder:latest"
          alwaysPull true
        }
      }
      steps {
        sh """
            pwd
            echo ${env.WORKSPACE}
          """

        sh """
             drush make -v --working-copy --strict=0 --dbc-modules=$BRANCH --no-gitinfofile --contrib-destination=profiles/bibdk $DISTROPATH www
        """
        // make it a tar
        sh """
        tar -czf www.tar www
        """
        stash name: "www", includes: "www.tar"
      }
    }

    stage('build docker') {
      agent {
        node { label 'devel8-head' }
      }
      steps {
        sh """
            pwd
          """
        dir('docker/www') {
          unstash "www"
          sh """
          tar -xf www.tar
          """
          script {
            docker.build("${DOCKER_REPO}/${PRODUCT}-${BRANCH}:${currentBuild.number}")
          }
        }

      }
    }
    stage('Push to artifactory ') {
      steps {
        script {
          // we only push to artifactory if we are handling develop or master branch
          if (BRANCH == 'master' || BRANCH == 'develop') {
            def artyServer = Artifactory.server 'arty'
            def artyDocker = Artifactory.docker server: artyServer, host: env.DOCKER_HOST
            def buildInfo = Artifactory.newBuildInfo()
            buildInfo.name = BUILDNAME
            buildInfo.env.capture = true
            buildInfo.env.collect()
            buildInfo = artyDocker.push("${DOCKER_REPO}/${PRODUCT}-${BRANCH}:${currentBuild.number}", 'docker-dscrum', buildInfo)

            artyServer.publishBuildInfo buildInfo
          }
        }
      }
    }
  }
  post{
    always{
      cleanWs()
      dir("${env.WORKSPACE}@2") {
        deleteDir()
      }
      dir("${env.WORKSPACE}@2@tmp") {
        deleteDir()
      }
      dir("${env.WORKSPACE}@tmp") {
        deleteDir()
      }
      sh """
      echo WORKSPACE: ${env.WORKSPACE}
      """
    }
  }
}
