FROM docker.dbc.dk/dbc-postgres

ENV POSTGRES_DB=filestore \
    POSTGRES_USER=filestore \
    POSTGRES_PASSWORD=filestore \
    POSTGRES_HOST=bibliotekdk-postgres-5432.frontend-features.svc.cloud.dbc.dk \
    CONVENIENCY_NAME=.frontend-features.

ADD bibdk_db.sql /docker-entrypoint.d/bibdk_db.sql
