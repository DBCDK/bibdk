#! groovy
@Library('frontend-dscrum') _
// The job will fail, if we do not have the underscore above.
// https://issues.jenkins.io/browse/JENKINS-42807

pipeline {
  agent {
    node { label 'devel10' }
  }
  options {
    buildDiscarder(logRotator(artifactDaysToKeepStr: "", artifactNumToKeepStr: "", daysToKeepStr: "", numToKeepStr: "5"))
    timestamps()
    gitLabConnection('gitlab.dbc.dk')
    // Limit concurrent builds to one pr. branch.
    disableConcurrentBuilds()
  }
  environment {
    BRANCH = BRANCH_NAME.replaceAll('feature/', '').replaceAll('_', '-')
    // artifactory data
    NAMESPACE = 'fbiscrum-dev'
    BASE_NAME = "docker-fbiscrum.artifacts.dbccloud.dk/bibliotekdk"
    IMAGE_TAG = "${env.BRANCH_NAME.toLowerCase().replace("feature", "").replace("/", "").replace("_", "-").replace(".", "-")}-${BUILD_NUMBER}"
    IMAGE_WWW_NAME = "${BASE_NAME}:${IMAGE_TAG}"
    IMAGE_DB_NAME = "${BASE_NAME}-db:${IMAGE_TAG}"
    DISTROPATH = "https://raw.github.com/DBCDK/bibdk/develop/distro.make"
    TESTWEBSITE = "http://bibliotekdk-test-www-${BRANCH}.fbiscrum-dev.svc.cloud.dbc.dk"
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
          ansiColor("xterm") {
            docker.withRegistry('https://docker-fbiscrum.artifacts.dbccloud.dk', 'DOCKER_LOGIN') {
              docker.build(
                "${IMAGE_WWW_NAME}", "-f ./docker/www/Dockerfile --no-cache --build-arg BRANCH=${BRANCH_NAME} ./docker/www"
              ).push()
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
      steps {
        script {
          docker.withRegistry('https://docker-fbiscrum.artifacts.dbccloud.dk', 'DOCKER_LOGIN') {
            docker.build(
              "${IMAGE_DB_NAME}", "-f ./docker/db/Dockerfile --no-cache --build-arg BRANCH=${BRANCH_NAME} ./docker/db"
            ).push()
          }
        }
      }
    }
    stage('Deploy') {
      steps {
        script {
          if (BRANCH != 'master') {
            // Website for manually testing.
            build job: 'BibliotekDK/Deployments/dev',
              parameters: [string(name: 'BuildId', value: "${currentBuild.number}"),
                           string(name: 'Branch', value: BRANCH),
                           booleanParam(name: 'test', value: false)]
            // Website for automatically testing.
            build job: 'BibliotekDK/Deployments/dev',
              parameters: [string(name: 'BuildId', value: "${currentBuild.number}"),
                           string(name: 'Branch', value: BRANCH),
                           booleanParam(name: 'test', value: true)]
            if (BRANCH == 'develop') {
              // FBS-TEST must be updated whenever develop is updated.
              // Get ready for committing the code to Git.
              def gitPath = 'd-scrum/deployments/bibliotek-dk/bibliotek-dk-deploy'
              // Which files should we change and commit.
              def files = [
                [filename: "drupal-deployment", type: "deployment", imagetag: "${IMAGE_TAG}"],
                [filename: "postgres-deployment", type: "deployment", imagetag: "${IMAGE_TAG}"],
                [filename: "drush-job", type: "job", imagetag: "${IMAGE_TAG}"],
                [filename: "drupal-cron", type: "cron", imagetag: "${IMAGE_TAG}"]
              ]
              // Which credential to use. The 'commitAndPush' uses 'dscrum_ssh_gitlab' as standard.
              def credentialsId = 'gitlab-isworker'
              // Let the magic begin.
              dscrumUtil.commitAndPush(files, env.BUILD_NUMBER, gitPath, credentialsId, 'fbs-test')
            }
          } else {
            // Get ready for committing the code to Git.
            def gitPath = 'd-scrum/deployments/bibliotek-dk/bibliotek-dk-deploy'
            // Which files should we change and commit.
            def files = [
             [filename: "drupal-deployment", type: "deployment", imagetag: "${IMAGE_TAG}"],
              [filename: "drush-job", type: "job", imagetag: "${IMAGE_TAG}"],
              [filename: "drupal-cron", type: "cron", imagetag: "${IMAGE_TAG}"]
            ]
            // Which credential to use. The 'commitAndPush' uses 'dscrum_ssh_gitlab' as standard.
            def credentialsId = 'gitlab-isworker'
            // Let the magic begin.
            dscrumUtil.commitAndPush(files, env.BUILD_NUMBER, gitPath, credentialsId, 'staging')
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
          image "docker-dbc.artifacts.dbccloud.dk/k8s-deploy-env:latest"
          label 'devel10'
          args '-u 0:0'
        }
      }
      environment {
        KUBECONFIG = credentials("kubecert-fbiscrum")
        KUBECTL = "kubectl -n ${NAMESPACE} --kubeconfig '${KUBECONFIG}'"
      }
      steps {
        script {
          sh """
            ${KUBECTL} exec -it deployment/bibliotekdk-test-www-${BRANCH} -- /bin/bash -c "drush -r /var/www/html -y en bibdk_mockup"
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
              image "docker-fbiscrum.artifacts.dbccloud.dk/selenium-tester:latest"
              alwaysPull true
              label "devel10"
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
                sh """
                  export FEATURE_BUILD_URL=${TESTWEBSITE}
                  export BIBDK_WEBDRIVER_URL=${TESTWEBSITE}/
                  export BIBDK_OPENUSERINFO_URL="http://openuserinfo-prod.frontend-prod.svc.cloud.dbc.dk/server.php"
                  py.test --junitxml=selenium.xml -v tests/ -o base_url=${TESTWEBSITE} || true
                  xsltproc xunit-transforms/pytest-selenium.xsl selenium.xml > ${env.WORKSPACE}/selenium-bibdk.xml
                """
                stash name: "selenium-bibdk", includes: "${env.WORKSPACE}/selenium-bibdk.xml"
              }
            }
          }
        }
        stage('Simpletest') {
          agent {
            docker {
              image "docker-dbc.artifacts.dbccloud.dk/k8s-deploy-env:latest"
              label 'devel10'
              args '-u 0:0'
            }
          }
          environment {
             KUBECONFIG = credentials("kubecert-fbiscrum")
             KUBECTL = "kubectl -n ${NAMESPACE} --kubeconfig '${KUBECONFIG}'"
          }
          steps {
            script {
              sh """
                rm -rf simpletest
                rm -f simpletest*.xml
                ${KUBECTL} exec -i deployment/bibliotekdk-test-www-${BRANCH} -- /bin/bash -c "cd /tmp && rm -rf simpletest"
                ${KUBECTL} exec -i deployment/bibliotekdk-test-www-${BRANCH} -- /bin/bash -c "drush -r /var/www/html en -y simpletest"
                ${KUBECTL} exec -i deployment/bibliotekdk-test-www-${BRANCH} -- /bin/bash -c "php /var/www/html/scripts/run-tests-xunit.sh --clean"
                ${KUBECTL} exec -i deployment/bibliotekdk-test-www-${BRANCH} -- /bin/bash -c 'php /var/www/html/scripts/run-tests-xunit.sh --php /usr/bin/php --xml /tmp/simpletest-bibdk.xml --url ${TESTWEBSITE} --concurrency 20 "Ting Client","Ting Openformat","Netpunkt / Bibliotek.dk","Ding! - WAYF","Bibliotek.dk - ADHL","Bibliotek.dk - Bibdk Behaviour","Bibliotek.dk - captcha","Bibliotek.dk - Cart","Bibliotek.dk - Facetbrowser","Bibliotek.dk - Favourites","Bibliotek.dk - Frontend","Bibliotek.dk - Further Search","Bibliotek.dk - Heimdal","Bibliotek.dk - Helpdesk","Bibliotek.dk - Holdingstatus","Bibliotek.dk - OpenOrder","Bibliotek.dk - Open Platform Client","Bibliotek.dk - OpenUserstatus","Bibliotek.dk - Provider","bibliotek.dk","Bibliotek.dk - SB Kopi" || true'
                POD=\$(${KUBECTL} get pod -l app=bibliotekdk-test-www-${BRANCH} -o jsonpath="{.items[0].metadata.name}")
                ${KUBECTL} cp \${POD}:/tmp/simpletest-bibdk.xml ./simpletest-bibdk.xml
                ${KUBECTL} exec -i deployment/bibliotekdk-test-www-${BRANCH} -- /bin/bash -c "drush -r /var/www/html dis -y simpletest"
              """
              stash name: "simpletest-bibdk", includes: "simpletest-bibdk.xml"
            }
          }
        }
      }
    }

    stage('simpletest / Selenium report') {
      when {
        // Only run if branch is not master.
        expression { BRANCH != 'master' }
      }
      steps{
        unstash name: "simpletest-bibdk"
        generateTestReport('simpletest-bibdk.xml')

        unstash name: "selenium-bibdk"
        generateTestReport('selenium-bibdk.xml')
      }
    }

    stage('disabling mockup module') {
      when {
        // Only run if branch is not master.
        expression { BRANCH != 'master' }
      }
      agent {
        docker {
          image "docker-dbc.artifacts.dbccloud.dk/k8s-deploy-env:latest"
          label 'devel10'
          args '-u 0:0'
        }
      }
      environment {
        KUBECONFIG = credentials("kubecert-fbiscrum")
        KUBECTL = "kubectl -n ${NAMESPACE} --kubeconfig '${KUBECONFIG}'"
      }
      steps {
        script {
          sh """
            ${KUBECTL} delete deployment,service bibliotekdk-test-www-${BRANCH}
            ${KUBECTL} delete deployment,service bibliotekdk-test-memcached-${BRANCH}
            ${KUBECTL} delete deployment,service bibliotekdk-test-db-${BRANCH}
            ${KUBECTL} delete cronJob bibliotekdk-test-cron-${BRANCH}
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

/**
 * function to generate test-report
 * @param String pattern
 *  the pattern to look for (path to junit xml. eg. test-report.xml)
 */
void generateTestReport(String pattern, String type = "JUnit") {
  if (type == "JUnit") {
    step([$class        : 'XUnitPublisher',
          testTimeMargin: '3000',
          thresholdMode : 1,
          thresholds    : [failed(failureNewThreshold: '0',
            failureThreshold: '0',
            unstableNewThreshold: '0',
            unstableThreshold: '0')],
          tools         : [JUnit(deleteOutputFiles: true,
            failIfNotNew: true,
            pattern: pattern,
            skipNoTestFiles: false,
            stopProcessingIfError: true)]])
  }
  if (type == "PHPUnit") {
    step([$class        : 'XUnitPublisher',
          testTimeMargin: '3000',
          thresholdMode : 1,
          thresholds    : [failed(failureNewThreshold: '0',
            failureThreshold: '0',
            unstableNewThreshold: '0',
            unstableThreshold: '0')],
          tools         : [PHPUnit(deleteOutputFiles: true,
            failIfNotNew: true,
            pattern: pattern,
            skipNoTestFiles: false,
            stopProcessingIfError: true)]])
  }
}
