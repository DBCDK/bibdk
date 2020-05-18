FROM docker.dbc.dk/dbc-postgres
USER root
ADD --chown=postgres:postgres ["https://is.dbc.dk/job/Bibliotek%20DK/job/Tools/job/Fetch%20Bibliotek%20DK%20database/lastSuccessfulBuild/artifact/bibdk_db_sql.tar.gz", "/docker-entrypoint.d/"]
ENV POSTGRES_DB=bibdk_db
RUN tar xf /docker-entrypoint.d/bibdk_db_sql.tar.gz -C /docker-entrypoint.d && \
    rm /docker-entrypoint.d/bibdk_db_sql.tar.gz
USER $POSTGRES_LINUX_USER
HEALTHCHECK CMD pg_isready -h localhost -p 5432
