#! groovy
// general vars
def DOCKER_REPO = "docker-dscrum.dbc.dk"
def PRODUCT = 'bibliotek-dk'
def BRANCH = BRANCH_NAME
// var for kubernetes
def NAMESPACE = 'frontend-prod'

def TARFILE
// artifactory vars
def BUILDNAME = 'Bibliotek-dk :: ' + BRANCH
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
    stage('build and stash bibdk code') {
      agent {
        docker {
          image "docker-dscrum.dbc.dk/d7-php7-builder:latest"
          alwaysPull true
        }
      }
      steps {
        // Where the heck are we?
        sh """
          pwd
          echo ${env.WORKSPACE}
        """
        // Drush Make
        sh """
          drush make -v --working-copy --strict=0 --dbc-modules=$BRANCH --no-gitinfofile --contrib-destination=profiles/bibdk $DISTROPATH www
        """
        // Building CSS
        dir('www/profiles/bibdk/themes/bibdk_theme/.npm') {
          sh """
            npm install
            ./node_modules/gulp/bin/gulp.js build --production
          """
        }
        // Stuffing a tar with the code.
        sh """
        tar -czf www.tar www
        """
        stash name: "www", includes: "www.tar"
      }
    }

    // @TODO NOT NOW only build develop and master switch on branch - if feature call feature build job

    stage('Docker: Drupal Site') {
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
            docker.build("${DOCKER_REPO}/${PRODUCT}-www${BRANCH}:${currentBuild.number}")
          }
        }

      }
    }
    stage('Docker: Drupal database') {
      agent {
        node { label 'devel8-head' }
      }
      steps {
        dir('docker/db') {
          sh """
            wget https://is.dbc.dk/view/Bibliotek.dk/job/dscrum-is-bibdk_dump_prod_db/lastSuccessfulBuild/artifact/bibdk_db.sql
            mv bibdk_db.sql docker-entrypoint.d/
          """
          script {
            docker.build("${DOCKER_REPO}/${PRODUCT}-db${BRANCH}:${currentBuild.number}")
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
            def buildInfo_www = Artifactory.newBuildInfo()
            buildInfo_www.name = BUILDNAME
            buildInfo_www.env.capture = true
            buildInfo_www.env.collect()
            buildInfo_www = artyDocker.push("${DOCKER_REPO}/${PRODUCT}-www${BRANCH}:${currentBuild.number}", 'docker-dscrum', buildInfo_www)

            def buildInfo_db = Artifactory.newBuildInfo()
            buildInfo_db.name = BUILDNAME
            buildInfo_db = artyDocker.push("${DOCKER_REPO}/${PRODUCT}-db${branchname}:${currentBuild.number}", 'docker-dscrum', buildInfo_db)

            buildInfo_www.append buildInfo_db

            artyServer.publishBuildInfo buildInfo_www

            sh """
            	docker rmi ${DOCKER_REPO}/${PRODUCT}-www${branchname}:${currentBuild.number}
            	docker rmi ${DOCKER_REPO}/${PRODUCT}-db${branchname}:${currentBuild.number}
            """
          }
        }
      }
    }
  }
  post{
    always{
      sh """
      echo WORKSPACE: ${env.WORKSPACE}
      """
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
    }
  }
}
