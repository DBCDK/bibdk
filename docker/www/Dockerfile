FROM docker.dbc.dk/dbc-apache-php7
MAINTAINER D-scrum <d-scrum@dbc.dk>

# mailhost for exim4
ENV smarthost=mailhost.dbc.dk
ENV cookie_domain=.bibliotek.dk
# set environment variables
# NOTICE vars are used to alter configuration feature, so names MUST be mapped from
# configuration file. see entry.sh for details
# All environment variables below should be production settings.
ENV AgencyRequest_url=http://openagency.addi.dk/2.35/ \
    AgencyRequest_xsd_url=http://openagency.addi.dk/2.35/openagency.xsd \
    bibdk_sbkopi_place_copy_request_url=https://webservice.statsbiblioteket.dk/copydanws/journal \
    bibdk_behaviour_url=http://miner-p01.dbc.dk/ \
    bibdk_borchk_url=https://borchk.addi.dk/2.5/ \
    bibdk_forsrights_url=http://forsrights.addi.dk/1.2/ \
    bibdk_openorder_url=https://openorder.addi.dk/3.0 \
    bibdk_openorder_xsd_url=https://openorder.addi.dk/3.0?xsd=1 \
    bibdk_openquestion_url=https://openorder.addi.dk/3.0?xsd=1 \
    bibdk_provider_webservice_url=http://openuserinfo-prod.mcp1-proxy.dbc.dk/server.php \
    bibdk_statsbib_url=https://webservice.statsbiblioteket.dk/ws-create-user1/CreateUser \
    openHoldingStatus_url=http://openholdingstatus.addi.dk/3.0.4/ \
    openHoldingStatus_xsd_url=http://openholdingstatus.addi.dk/3.0/openholdingstatus.xsd \
    open_moreinfo_url=http://moreinfo.addi.dk/2.11/?wsdl \
    OpenPlatformSuggestRequest_url=https://openplatform.dbc.dk/v3/suggest \
    openplatform_token_url=https://auth.dbc.dk/oauth/token \
    openplatform_url=https://openplatform.dbc.dk/v3/ \
    open_saou_url=https://saou.addi.dk/2.0/SaouWebService?wsdl \
    openuserstatus_url=https://openuserstatus.addi.dk/1.6.1/ \
    open_voxb_url=https://voxb.addi.dk/1.3.1/ \
    ting_infomedia_url=http://infomedia.mcp1-proxy.dbc.dk/server.php \
    ting_recommendation_url=http://openadhl.addi.dk/3.0/ \
    ting_recommendation_xsd=http://openadhl.addi.dk/3.0/adhl.xsd \
    ting_scan_url=http://openscan.addi.dk/2.0/ \
    ting_search_url=https://opensearch.addi.dk/b3.5_5.0/ \
    ting_spell_url=http://openspell.addi.dk/1.2/ \
    voxb_xsd_url=https://voxb.addi.dk/1.3.1/voxb.xsd

RUN apt-get update && \
	apt-get -q -y install cron logrotate php-gd php-mbstring php-pear php-soap php-yaml rsyslog sudo wget exim4 postgresql-client && \
	rm -rf /var/lib/apt/lists/* && \
	apt-get autoremove -y && \
  pecl install yaz && \
	wget -q https://github.com/drush-ops/drush/releases/download/8.2.3/drush.phar && \
	php drush.phar core-status && \
	chmod +x drush.phar && \
	mv drush.phar /usr/local/bin/drush && \
	drush dl -y registry_rebuild-7.x-2.5

COPY crontab /etc/crontab
COPY data-vol /etc/logrotate.d
COPY --chown=root:www-data www $APACHE_ROOT
COPY 000-default.conf /etc/apache2/sites-enabled
COPY entry.sh /
COPY healthcheck.sh /
COPY apache_ready.sh /
COPY www/profiles/bibdk/modules/bibdk_config/docker/settings.php $APACHE_ROOT/sites/default
ADD fqdn.conf /etc/apache2/conf-available
COPY apache_security.conf /etc/apache2/conf-enabled/
COPY run-tests-jenkins.sh $APACHE_ROOT/scripts
COPY run-tests-xunit.sh $APACHE_ROOT/scripts
COPY update-exim4.conf.conf /etc/exim4/

RUN mkdir -p $APACHE_ROOT/private && \
	sudo chown www-data:www-data $APACHE_ROOT/private && \
	chmod 755 /entry.sh && \
	chmod 755 /healthcheck.sh && \
	a2enmod rewrite && \
	a2enmod headers && \
	a2enconf fqdn && \
	mkdir /data && \
	sudo chown www-data:www-data /data && \
	update-exim4.conf

EXPOSE 80

HEALTHCHECK CMD ["/healthcheck.sh"]

ENTRYPOINT ["/entry.sh"]
