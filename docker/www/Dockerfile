FROM docker.dbc.dk/dbc-apache-php7
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
    NAMESPACE_NAME=frontend-features

COPY indexdata.asc /
RUN apt-key add indexdata.asc
COPY yaz.list /etc/apt/sources.list.d/

RUN apt-get update && \
  apt-get -q -y install cron logrotate php-gd php-pear wget php-soap php-yaml make php-dev rsyslog sudo wget ms mtp postgresql-client libyaz5 yaz libyaz5-dev && \
  pecl channel-update pecl.php.net && \
  pecl install yaz && \
  rm -rf /var/lib/apt/lists/* && \
  wget -q https://github.com/drush-ops/drush/releases/download/8.2.3/drush.phar && \
  php drush.phar core-status && \
  chmod +x drush.phar && \
  mv drush.phar /usr/local/bin/drush && \
  drush dl -y registry_rebuild-7.x-2.5 && \
  apt-get -q -y remove php-dev php-pear && \
  rm -rf /var/lib/apt/lists/* && \
  apt-get autoremove -y

COPY crontab /etc/crontab
COPY data-vol /etc/logrotate.d
COPY --chown=root:www-data www $APACHE_ROOT
COPY 000-default.conf /etc/apache2/sites-enabled
COPY entry.sh /
COPY healthcheck.sh /
COPY apache_ready.sh /
COPY run_environment.sh /
COPY www/profiles/bibdk/modules/bibdk_config/docker/settings.php $APACHE_ROOT/sites/default
COPY robots.txt $APACHE_ROOT
ADD fqdn.conf /etc/apache2/conf-available
COPY apache_security.conf /etc/apache2/conf-enabled/
COPY run-tests-jenkins.sh $APACHE_ROOT/scripts
COPY run-tests-xunit.sh $APACHE_ROOT/scripts
COPY msmtprc /etc/
COPY 20-yaz.ini /etc/php/7.3/apache2/conf.d/

RUN mkdir -p $APACHE_ROOT/private && \
  sudo chown www-data:www-data $APACHE_ROOT/private && \
  chmod 755 /entry.sh && \
  chmod 755 /healthcheck.sh && \
  chmod 777 /etc/php/7.0/apache2/conf.d/20-yaz.ini && \
  a2enmod rewrite && \
  a2enmod headers && \
  a2enconf fqdn

EXPOSE 80

HEALTHCHECK CMD ["/healthcheck.sh"]

ENTRYPOINT ["/entry.sh"]
