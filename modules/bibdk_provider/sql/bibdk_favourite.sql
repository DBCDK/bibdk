drop table bibdk_favourite;
create table bibdk_favourite( username character varying(64) not null, agencyid character varying(16) not null, userdata text, orderagency boolean not null default FALSE);
alter table bibdk_favourite add constraint FK_username foreign key(username) references ddbuser(username) on delete cascade;
alter table bibdk_favourite add constraint UN_username_agencyid UNIQUE(username,agencyid);
create index bibdk_favourite_agencyid_idx on bibdk_favourite (agencyid);
comment on column bibdk_favourite.username is 'bibdk username is email address. References ddbuser.username. cascade on delete';
comment on column bibdk_favourite.agencyid is 'id of favourite agency';
comment on column bibdk_favourite.userdata is 'serialized userdata. username,pincode etc.';
comment on column bibdk_favourite.orderagency is 'selected agency to order from';

<!-- TESTDATA -->
insert into bibdk_favourite(username, agencyid, userdata, orderagency) values('pjohans@gmail.com', '710100', 'HEST', TRUE);
insert into bibdk_favourite(username, agencyid, userdata, orderagency) values('pjohans@gmail.com', '612934', 'ZEBRA', FALSE);