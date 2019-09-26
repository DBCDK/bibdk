FROM docker.dbc.dk/dbc-postgres

ENV POSTGRES_DB=filestore \
    POSTGRES_USER=filestore \
    POSTGRES_PASSWORD=filestore \
    POSTGRES_HOST=bibliotek-dk-db-develop.frontend-features.svc.cloud.dbc.dk \
    CONVENIENCY_NAME=.frontend-features.

ADD docker-entrypoint.d/ /docker-entrypoint.d/
