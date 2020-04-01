#! groovy
@Library('pu-deploy')
@Library('frontend-dscrum')

def k8sDeployEnvId = findLastSuccessfulBuildNumber('Docker-k8s-deploy-env')

// general vars
def DOCKER_REPO = "docker-dscrum.dbc.dk"
def PRODUCT = 'bibliotek-dk'
def BRANCH = 'develop'
BRANCH = BRANCH_NAME.replaceAll('feature/', '')
BRANCH = BRANCH.replaceAll('_', '-')

def NAMESPACE = 'frontend-features'

// artifactory buildname
def BUILDNAME = 'Bibliotek-dk :: ' + BRANCH
def URL = 'http://'+PRODUCT+'-www-'+BRANCH+'.'+NAMESPACE+'.svc.cloud.dbc.dk'
def DISTROPATH = "https://raw.github.com/DBCDK/bibdk/develop/distro.make"

pipeline {
  agent {
    node { label 'devel9-head' }
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
          label "devel9-head"
          image "docker-dscrum.dbc.dk/d7-php7-builder:latest"
          alwaysPull true
        }
      }
      steps {
        // Drush Make
        sh """
          drush make -v --working-copy --strict=0 --dbc-modules=$BRANCH_NAME --no-gitinfofile --contrib-destination=profiles/bibdk $DISTROPATH www
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

    stage('Docker: Drupal Site') {
      agent {
        node { label 'devel9-head' }
      }
      steps {
        dir('docker/www') {
          unstash "www"
          sh """
          tar -xf www.tar
          """
          // get pgp key to use debian packages from indexdata ( for installing yaz )
          // see also yaz.list which is added in Dockerfile
          // REMOVE when yaz is no longer used
          sh """
          wget http://ftp.indexdata.dk/debian/indexdata.asc
          """

          script {
            docker.build("${DOCKER_REPO}/${PRODUCT}-www-${BRANCH}:${currentBuild.number}")
            // we need a latest tag for development setup
            if (BRANCH == 'develop') {
              docker.build("${DOCKER_REPO}/${PRODUCT}-www-${BRANCH}:latest")
            }
          }
        }

      }
    }
    // if sessions table grows to big - delete sessions more than a day old
    // select count(*) from sessions where to_timestamp(timestamp) < now() - INTERVAL '1 DAY';
    // delete from sessions where to_timestamp(timestamp) < now() - INTERVAL '1 DAY';
    stage('Docker: Drupal database') {
      when {
        // Only run if branch is not master.
        expression { BRANCH != 'master' }
      }
      agent {
        node { label 'devel9-head' }
      }
      steps {
        dir('docker/db') {
          sh """
            wget -P docker-entrypoint.d https://is.dbc.dk/job/Bibliotek%20DK/job/Tools/job/Fetch%20Bibliotek%20DK%20database/lastSuccessfulBuild/artifact/bibdk_db_sql.tar.gz
          """
        }
        dir('docker/db/docker-entrypoint.d') {
          sh """
            tar -xf bibdk_db_sql.tar.gz
            rm -rf bibdk_db_sql.tar.gz
          """
        }
        dir('docker/db') {
          script {
            docker.build("${DOCKER_REPO}/${PRODUCT}-db-${BRANCH}:${currentBuild.number}")
            // we need a latest tag for development setup
            if (BRANCH == 'develop') {
              docker.build("${DOCKER_REPO}/${PRODUCT}-db-${BRANCH}:latest")
            }
          }
        }
      }
    }
    stage('Push to artifactory ') {
      steps {
        script {
          def artyServer = Artifactory.server 'arty'
          def artyDocker = Artifactory.docker server: artyServer, host: env.DOCKER_HOST

          def buildInfo_www = Artifactory.newBuildInfo()
          buildInfo_www.name = BUILDNAME
          buildInfo_www = artyDocker.push("${DOCKER_REPO}/${PRODUCT}-www-${BRANCH}:${currentBuild.number}", 'docker-dscrum', buildInfo_www)
          buildInfo_www.env.capture = true
          buildInfo_www.env.collect()

          if (BRANCH != 'master') {
            def buildInfo_db = Artifactory.newBuildInfo()
            buildInfo_db.name = BUILDNAME
            buildInfo_db = artyDocker.push("${DOCKER_REPO}/${PRODUCT}-db-${BRANCH}:${currentBuild.number}", 'docker-dscrum', buildInfo_db)
            buildInfo_www.append buildInfo_db
          }
          artyServer.publishBuildInfo buildInfo_www

          // we need a latest tag for development setup
          if (BRANCH == 'develop') {
            def buildInfo_www_latest = Artifactory.newBuildInfo()
            buildInfo_www_latest.name = BUILDNAME
            buildInfo_www_latest = artyDocker.push("${DOCKER_REPO}/${PRODUCT}-www-${BRANCH}:latest", 'docker-dscrum', buildInfo_www_latest)
            buildInfo_www_latest.env.capture = true
            buildInfo_www_latest.env.collect()

            def buildInfo_db_latest = Artifactory.newBuildInfo()
            buildInfo_db_latest.name = BUILDNAME
            buildInfo_db_latest = artyDocker.push("${DOCKER_REPO}/${PRODUCT}-db-${BRANCH}:latest", 'docker-dscrum', buildInfo_db_latest)

            buildInfo_www_latest.append buildInfo_db_latest
            artyServer.publishBuildInfo buildInfo_www_latest
          }
          if (BRANCH != 'master') {
            sh """
            	docker rmi ${DOCKER_REPO}/${PRODUCT}-www-${BRANCH}:${currentBuild.number}
            	docker rmi ${DOCKER_REPO}/${PRODUCT}-db-${BRANCH}:${currentBuild.number}
            """
          } else {
            sh """
            	docker rmi ${DOCKER_REPO}/${PRODUCT}-www-${BRANCH}:${currentBuild.number}
            """
          }
          // cleanup development setup
          if (BRANCH == 'develop') {
             sh """
                docker rmi ${DOCKER_REPO}/${PRODUCT}-www-${BRANCH}:latest
                docker rmi ${DOCKER_REPO}/${PRODUCT}-db-${BRANCH}:latest
               """
           }
        }
      }
    }
    stage('Deploy') {
      steps {
        script {
          if (BRANCH == 'master') {
            build job: 'Bibliotek DK/Deploy jobs for Bibliotek DK/Deploy Bibliotek DK staging'
            $NAMESPACE = 'frontend-staging'
          } else {
            build job: 'Bibliotek DK/Deploy jobs for Bibliotek DK/Deploy Bibliotek DK develop', parameters: [string(name: 'deploybranch', value: BRANCH)]
          }
        }
      }
    }
    stage('enabling mockup module') {
      when {
        // Only run if branch is not master.
        expression { BRANCH != 'master' }
      }
      agent {
        docker {
          image "docker.dbc.dk/k8s-deploy-env:latest"
          label 'devel9'
          args '-u 0:0'
        }
      }
      environment {
        KUBECONFIG = credentials("kubecert-frontend")
        KUBECTL = "kubectl --kubeconfig '${KUBECONFIG}'"
      }
      steps {
        script {
          sh """
            POD=\$(kubectl -n $NAMESPACE --kubeconfig '${KUBECONFIG}' get pod -l app=bibliotek-dk-www-$BRANCH -o jsonpath="{.items[0].metadata.name}")
            kubectl -n $NAMESPACE --kubeconfig '${KUBECONFIG}' exec -it \${POD} -- /bin/bash -c "drush -r /var/www/html -y en bibdk_mockup"
          """
        }
      }
    }
    stage('run selenium and simpletest tests') {
      when {
        // Only run if branch is not master.
        expression { BRANCH != 'master' }
      }
      parallel Selenium: {
        agent {
          docker {
            image "docker-dscrum.dbc.dk/selenium-tester:latest"
            alwaysPull true
            label "devel9"
          }
        }
        steps {
          git branch: 'develop',
            credentialsId: 'dscrum_ssh_gitlab',
            url: 'gitlab@gitlab.dbc.dk:d-scrum/d7/BibdkWebdriver.git'

          dir('bibdk') {
            checkout scm
            dir('xunit-transforms') {
              git credentialsId: 'dscrum_ssh_gitlab',
                  url: 'gitlab@gitlab.dbc.dk:d-scrum/jenkins-jobs/xunit-transform.git'
            }
          }
          sh """
          mv helpers.py bibdk/tests
          """
          dir('bibdk') {
            script {
              withCredentials([[$class: 'UsernamePasswordMultiBinding', credentialsId: 'netpunkt-user', usernameVariable: 'NETPUNKT_USER', passwordVariable: 'NETPUNKT_PASS']]) {
                sh """
                  export FEATURE_BUILD_URL=${URL}
                  export BIBDK_WEBDRIVER_URL=${URL}/
                  export BIBDK_OPENUSERINFO_URL="http://openuserinfo-prod.frontend-prod.svc.cloud.dbc.dk/server.php"
                  py.test --junitxml=selenium.xml --driver Remote --host selenium.dbc.dk --port 4444 --capability browserName chrome -v tests/ -o base_url=${URL} || true
                  xsltproc xunit-transforms/pytest-selenium.xsl selenium.xml > selenium-result.xml
                """
              }

              step([$class: 'XUnitBuilder', testTimeMargin: '3000', thresholdMode: 1,
                thresholds: [
                  [$class: 'FailedThreshold', failureNewThreshold: '', failureThreshold: '0', unstableNewThreshold: '', unstableThreshold: ''],
                  [$class: 'SkippedThreshold', failureNewThreshold: '', failureThreshold: '', unstableNewThreshold: '', unstableThreshold: '']],
                tools     : [
                  [$class: 'JUnitType', deleteOutputFiles: true, failIfNotNew: true, pattern: 'selenium-result.xml', skipNoTestFiles: false, stopProcessingIfError: false]]
              ])
            }
          }
        }
      },
      Simpletest: {
        agent {
          docker {
            image "docker.dbc.dk/k8s-deploy-env:latest"
            label 'devel9'
            args '-u 0:0'
          }
        }
        environment {
           KUBECONFIG = credentials("kubecert-frontend")
           KUBECTL = "kubectl --kubeconfig '${KUBECONFIG}'"
        }
        steps {
          script {
            testURL = "http://bibliotek-dk-www-${BRANCH}.frontend-features.svc.cloud.dbc.dk"
            sh """
            rm -rf simpletest
            rm -f simpletest*.xml
            POD=\$(kubectl -n $NAMESPACE --kubeconfig '${KUBECONFIG}' get pod -l app=bibliotek-dk-www-$BRANCH -o jsonpath="{.items[0].metadata.name}")
            kubectl -n $NAMESPACE --kubeconfig '${KUBECONFIG}' exec -i \${POD} -- /bin/bash -c "cd /tmp && rm -rf simpletest"
            kubectl -n $NAMESPACE --kubeconfig '${KUBECONFIG}' exec -i \${POD} -- /bin/bash -c "drush -r /var/www/html en -y simpletest"
            kubectl -n $NAMESPACE --kubeconfig '${KUBECONFIG}' exec -i \${POD} -- /bin/bash -c "php /var/www/html/scripts/run-tests-xunit.sh --clean"
            kubectl -n $NAMESPACE --kubeconfig '${KUBECONFIG}' exec -i \${POD} -- /bin/bash -c 'php /var/www/html/scripts/run-tests-xunit.sh --php /usr/bin/php --xml /tmp/simpletest-bibdk.xml --url ${testURL} --concurrency 20 "Ting Client","Netpunkt / Bibliotek.dk","Ding! - WAYF","Bibliotek.dk - ADHL","Bibliotek.dk - Bibdk Behaviour","Bibliotek.dk - captcha","Bibliotek.dk - Cart","Bibliotek.dk - Facetbrowser","Bibliotek.dk - Favourites","Bibliotek.dk - Frontend","Bibliotek.dk - Further Search","Bibliotek.dk - Heimdal","Bibliotek.dk - Helpdesk","Bibliotek.dk - Holdingstatus","Bibliotek.dk - OpenOrder","Bibliotek.dk - Open Platform Client","Bibliotek.dk - OpenUserstatus","Bibliotek.dk - Provider",bibliotek.dk,Bibliotek.dk,"Bibliotek.dk - SB Kopi","Bibliotek.dk - Provider" || true'
            kubectl cp $NAMESPACE/\${POD}:/tmp/simpletest-bibdk.xml ./simpletest-bibdk.xml  --kubeconfig '${KUBECONFIG}'
            kubectl -n $NAMESPACE --kubeconfig '${KUBECONFIG}' exec -i \${POD} -- /bin/bash -c "drush -r /var/www/html dis -y simpletest"
            """

            step([
              $class: 'XUnitBuilder', testTimeMargin: '3000', thresholdMode: 1,
              thresholds: [
                [$class: 'FailedThreshold', failureNewThreshold: '', failureThreshold: '0', unstableNewThreshold: '', unstableThreshold: ''],
                [$class: 'SkippedThreshold', failureNewThreshold: '', failureThreshold: '', unstableNewThreshold: '', unstableThreshold: '']
              ],
              tools: [
                [$class: 'JUnitType', deleteOutputFiles: true, failIfNotNew: true, pattern: 'simpletest*.xml', skipNoTestFiles: false, stopProcessingIfError: false]
              ]
            ])
          }
        }
      }
    }

    stage('disabling mockup module') {
      when {
        // Only run if branch is not master.
        expression { BRANCH != 'master' }
      }
      agent {
        docker {
          image "docker.dbc.dk/k8s-deploy-env:${k8sDeployEnvId}"
          label 'devel9'
          args '-u 0:0'
        }
      }
      environment {
        KUBECONFIG = credentials("kubecert-frontend")
        KUBECTL = "kubectl --kubeconfig '${KUBECONFIG}'"
      }
      steps {
        script {
          sh """
            POD=\$(kubectl -n $NAMESPACE --kubeconfig '${KUBECONFIG}' get pod -l app=bibliotek-dk-www-$BRANCH -o jsonpath="{.items[0].metadata.name}")
            kubectl -n $NAMESPACE --kubeconfig '${KUBECONFIG}' exec -it \${POD} -- /bin/bash -c "drush -r /var/www/html -y dis bibdk_mockup"
          """
        }
      }
    }
  }
  post {
    always {
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
