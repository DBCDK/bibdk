ARG BRANCH=develop

FROM docker-frontend.artifacts.dbccloud.dk/d7-php7-builder-bibdk923-node:3 as builder
ARG BRANCH
ENV BRANCH=${BRANCH}

USER jenkins
# build drupal code
RUN cd /var/lib/jenkins && \
    drush make -v --working-copy --strict=0 --dbc-modules=${BRANCH} --no-gitinfofile --contrib-destination=profiles/bibdk "https://raw.github.com/DBCDK/bibdk/develop/distro.make" www

# Build composer code
RUN cd /var/lib/jenkins/www/profiles/bibdk && composer up

# build stylesheet
RUN cd /var/lib/jenkins/www/profiles/bibdk/themes/bibdk_theme/.npm && \
    npm install && \
    ./node_modules/gulp/bin/gulp.js build --production

FROM docker-dbc.artifacts.dbccloud.dk/dbc-apache-php7
MAINTAINER D-scrum <d-scrum@dbc.dk>

# set environment variables
# mailhost for exim4
ENV smarthost=mailhost.dbc.dk
ENV cookie_domain=.bibliotek.dk

# database settings
ENV POSTGRES_DB=filestore \
    POSTGRES_USER=filestore \
    POSTGRES_PASSWORD=filestore \
    POSTGRES_HOST=bibliotek-dk-db-develop.frontend-features.svc.cloud.dbc.dk \
    NAMESPACE_NAME=frontend-features \
    STARTUP=drupal \
    USE_MEMCACHE=no

# get pgp key to use debian packages from indexdata ( for installing yaz )
# see also yaz.list which is added in Dockerfile
# REMOVE when yaz is no longer used
ADD ["http://ftp.indexdata.dk/debian/indexdata.asc", "/"]
RUN apt-key add indexdata.asc
COPY conf/yaz.list /etc/apt/sources.list.d/

RUN apt-get update && apt-get install -q -y libtinfo5
ADD ["http://ftp.us.debian.org/debian/pool/main/r/readline/libreadline7_7.0-3_amd64.deb", "/"]
RUN dpkg -i libreadline7_7.0-3_amd64.deb
ADD ["http://ftp.us.debian.org/debian/pool/main/i/icu/libicu63_63.1-6+deb10u3_amd64.deb", "/"]
RUN dpkg -i libicu63_63.1-6+deb10u3_amd64.deb
ADD ["https://github.com/drush-ops/drush/releases/download/8.4.11/drush.phar", "/"]

RUN apt-get update && \
  apt-get -q -y install tar sudo cron logrotate php-gd php-mbstring php-pear php-soap php-yaml php-memcached \
  make php-dev rsyslog msmtp postgresql-client libyaz5 yaz libyaz5-dev && \
  pecl channel-update pecl.php.net && \
  pecl install yaz && \
  rm -rf /var/lib/apt/lists/* && \
  php drush.phar core-status && \
  chmod +x /drush.phar && \
  mv /drush.phar /usr/local/bin/drush && \
  drush dl -y registry_rebuild-7.x-2.5 && \
  apt-get -q -y remove php-dev php-pear && \
  rm -rf /var/lib/apt/lists/* && \
  apt-get autoremove -y

# Copy application folders to image.
COPY --from=builder --chown=root:www-data /var/lib/jenkins/www $APACHE_ROOT
RUN mkdir $APACHE_ROOT/sites/default/files
# COPY --from=builder /var/lib/jenkins/www/profiles/bibdk/modules/bibdk_config/docker/settings.php $APACHE_ROOT/sites/default
COPY settings.php $APACHE_ROOT/sites/default
RUN chown root:www-data $APACHE_ROOT


# Copy linux stuff
COPY conf/data-vol /etc/logrotate.d
COPY conf/apache_security.conf /etc/apache2/conf-enabled/
ADD conf/fqdn.conf /etc/apache2/conf-available
ADD --chown=www-data:www-data ["https://is.dbc.dk/view/fbiscrum/job/BibliotekDK/job/Tools/job/Fetch%20Bibliotek%20DK%20files%20folder/lastSuccessfulBuild/artifact/files.tar.gz","/tmp"]
COPY conf/robots.txt $APACHE_ROOT
COPY conf/msmtprc /etc/
COPY conf/20-yaz.ini /etc/php/7.4/apache2/conf.d/

# Copy startup scripts
COPY script/run_cron.sh /
COPY script/start_bibdk.sh /

# Copy test scripts
COPY script/healthcheck.sh /
COPY script/run-tests-jenkins.sh $APACHE_ROOT/scripts
COPY script/run-tests-xunit.sh $APACHE_ROOT/scripts

RUN mkdir -p $APACHE_ROOT/private && \
  chmod 755 /healthcheck.sh && \
  chmod 755 /run_cron.sh && \
  chmod 755 /start_bibdk.sh && \
  chmod 777 /etc/php/7.4/apache2/conf.d/20-yaz.ini && \
  sudo chown www-data:www-data $APACHE_ROOT/private && \
  sudo chown -R www-data:www-data $APACHE_ROOT/sites/default/files && \
  # Set up apache modules and configuration.
  a2enmod rewrite && \
  a2enmod headers && \
  a2enconf fqdn

WORKDIR $APACHE_ROOT

EXPOSE 80

HEALTHCHECK CMD ["/healthcheck.sh"]

ENTRYPOINT ["/start_bibdk.sh"]
