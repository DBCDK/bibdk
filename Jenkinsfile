#! groovy
@Library('pu-deploy')
@Library('frontend-dscrum')

def k8sDeployEnvId = findLastSuccessfulBuildNumber('Docker-k8s-deploy-env')
def DEVELOP = true

pipeline {
  agent {
    node { label 'devel10-head' }
  }
  options {
    buildDiscarder(logRotator(artifactDaysToKeepStr: "", artifactNumToKeepStr: "", daysToKeepStr: "", numToKeepStr: "5"))
    timestamps()
    gitLabConnection('gitlab.dbc.dk')
    // Limit concurrent builds to one pr. branch.
    disableConcurrentBuilds()
  }
  environment {
    PRODUCT = "bibliotek-dk"
    BRANCH = BRANCH_NAME.replaceAll('feature/', '').replaceAll('_', '-')
    // artifactory data
    NAMESPACE = 'frontend-features'
    DOCKER_REPO = "docker-dscrum.dbc.dk"
    BUILDNAME = "Bibliotek-dk :: ${BRANCH}"
    WEBSITE = "http://${PRODUCT}-www-${BRANCH}.${NAMESPACE}.svc.cloud.dbc.dk"
    DISTROPATH = "https://raw.github.com/DBCDK/bibdk/develop/distro.make"
  }
  triggers {
    gitlab(
      triggerOnPush: true,
      triggerOnMergeRequest: true,
      branchFilterType: 'All'
    )
  }
  stages {
    // Build the Drupal website image.
    stage('Docker Drupal Site') {
      steps {
        script {
          docker.build("${DOCKER_REPO}/${PRODUCT}-www-${BRANCH}:${currentBuild.number}",
            "-f ./docker/www/Dockerfile --no-cache --build-arg BRANCH=${BRANCH_NAME} ./docker/www")
          if (BRANCH == 'develop') {
            docker.build("${DOCKER_REPO}/${PRODUCT}-www-${BRANCH}:latest", "-f ./docker/www/Dockerfile --build-arg BRANCH=${BRANCH_NAME} --no-cache ./docker/www")
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
      steps {
        script {
          docker.build("${DOCKER_REPO}/${PRODUCT}-db-${BRANCH}:${currentBuild.number}", "./docker/db -f ./docker/db/Dockerfile --no-cache")
          // we need a latest tag for development setup
          if (BRANCH == 'develop') {
            docker.build("${DOCKER_REPO}/${PRODUCT}-db-${BRANCH}:latest", "./docker/db -f ./docker/db/Dockerfile --no-cache")
          }
        }
      }
    }
    stage('Push to artifactory') {
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
            build job: 'Bibliotek DK/Deployments/staging'
            NAMESPACE = 'frontend-staging'
          } else {
            build job: 'Bibliotek DK/Deployments/develop', parameters: [string(name: 'deploybranch', value: BRANCH)]
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
        KUBECTL = "kubectl -n ${NAMESPACE} --kubeconfig '${KUBECONFIG}'"
      }
      steps {
        script {
          sh """
            POD=\$(${KUBECTL} get pod --field-selector=status.phase=Running -l app=bibliotek-dk-www-$BRANCH -o jsonpath="{.items[0].metadata.name}")
            ${KUBECTL} exec -it \${POD} -- /bin/bash -c "drush -r /var/www/html -y en bibdk_mockup"
          """
        }
      }
    }
    stage('run selenium and simpletest tests') {
      when {
        // Only run if branch is not master.
        expression { BRANCH != 'master' }
      }
      parallel {
        stage('Selenium') {
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
                    export FEATURE_BUILD_URL=${WEBSITE}
                    export BIBDK_WEBDRIVER_URL=${WEBSITE}/
                    export BIBDK_OPENUSERINFO_URL="http://openuserinfo-prod.frontend-prod.svc.cloud.dbc.dk/server.php"
                    py.test --junitxml=selenium.xml --driver Remote --host selenium.dbc.dk --port 4444 --capability browserName chrome -v tests/ -o base_url=${WEBSITE} || true
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
        }
        stage('Simpletest') {
          agent {
            docker {
              image "docker.dbc.dk/k8s-deploy-env:latest"
              label 'devel9'
              args '-u 0:0'
            }
          }
          environment {
             KUBECONFIG = credentials("kubecert-frontend")
             KUBECTL = "kubectl -n ${NAMESPACE} --kubeconfig '${KUBECONFIG}'"
          }
          steps {
            script {
              testURL = "http://bibliotek-dk-www-${BRANCH}.frontend-features.svc.cloud.dbc.dk"
              sh """
                rm -rf simpletest
                rm -f simpletest*.xml
                POD=\$(${KUBECTL} get pod -l app=bibliotek-dk-www-$BRANCH -o jsonpath="{.items[0].metadata.name}")
                ${KUBECTL} exec -i \${POD} -- /bin/bash -c "cd /tmp && rm -rf simpletest"
                ${KUBECTL} exec -i \${POD} -- /bin/bash -c "drush -r /var/www/html en -y simpletest"
                ${KUBECTL} exec -i \${POD} -- /bin/bash -c "php /var/www/html/scripts/run-tests-xunit.sh --clean"
                ${KUBECTL} exec -i \${POD} -- /bin/bash -c 'php /var/www/html/scripts/run-tests-xunit.sh --php /usr/bin/php --xml /tmp/simpletest-bibdk.xml --url ${testURL} --concurrency 20 "Ting Client","Netpunkt / Bibliotek.dk","Ding! - WAYF","Bibliotek.dk - ADHL","Bibliotek.dk - Bibdk Behaviour","Bibliotek.dk - captcha","Bibliotek.dk - Cart","Bibliotek.dk - Facetbrowser","Bibliotek.dk - Favourites","Bibliotek.dk - Frontend","Bibliotek.dk - Further Search","Bibliotek.dk - Heimdal","Bibliotek.dk - Helpdesk","Bibliotek.dk - Holdingstatus","Bibliotek.dk - OpenOrder","Bibliotek.dk - Open Platform Client","Bibliotek.dk - OpenUserstatus","Bibliotek.dk - Provider",bibliotek.dk,Bibliotek.dk,"Bibliotek.dk - SB Kopi","Bibliotek.dk - Provider" || true'
                kubectl cp $NAMESPACE/\${POD}:/tmp/simpletest-bibdk.xml ./simpletest-bibdk.xml  --kubeconfig '${KUBECONFIG}'
                ${KUBECTL} exec -i \${POD} -- /bin/bash -c "drush -r /var/www/html dis -y simpletest"
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
        KUBECTL = "kubectl -n ${NAMESPACE} --kubeconfig '${KUBECONFIG}'"
      }
      steps {
        script {
          sh """
            POD=\$(${KUBECTL} get pod -l app=bibliotek-dk-www-$BRANCH -o jsonpath="{.items[0].metadata.name}")
            ${KUBECTL} exec -it \${POD} -- /bin/bash -c "drush -r /var/www/html -y dis bibdk_mockup"
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
