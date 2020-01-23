drop table ddbuser;
create table ddbuser
       (USERNAME character varying(64) not null,
       PASSWORD character varying(64) not null,
       SETTINGS text,
       CREATION_DATE date not null,
       LASTLOGIN date,
       LASTMOD date,
       CONFIRMED integer,
       IMPORTED character varying(1) not null,
       USERALIAS character varying(64),
       WAYF_ID character varying(64),
       UCD_CONCENT character varying(1) not null,
       CPR_HASH character varying(32),
       CPR_CONSENT character varying(1) not null);
alter table ddbuser add constraint pk_username primary key(USERNAME);
create index idx_password on ddbuser(PASSWORD);
drop user bibdk;
create user bibdk with password 'testhest';
grant select,insert,update,delete on ddbuser to bibdk;
