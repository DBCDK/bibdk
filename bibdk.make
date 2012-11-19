api = 2
core = 7.x

; --- Libraries ---

; Profiler lib for profile
libraries[profiler][download][type] = git
libraries[profiler][download][url] = http://git.drupal.org/project/profiler.git
libraries[profiler][download][revision] = d0137cb42bc7a4e9ce0a0431f875806285d09758
; Patch from http://drupal.org/node/1328796
libraries[profiler][patch][] = http://drupal.org/files/profiler-reverse.patch

libraries[ckeditor][destination] = libraries
libraries[ckeditor][directory_name] = ckeditor
libraries[ckeditor][download][type] = get
libraries[ckeditor][download][url] = http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.6.2/ckeditor_3.6.2.zip


; --- Theming ---
;; New bibliotek.dk theme
projects[bibdk_theme][type] = theme
projects[bibdk_theme][download][type] = git
projects[bibdk_theme][download][url] = git@github.com:DBCDK/bibdk_theme.git
projects[bibdk_theme][download][tag] = 7.x-0.2


; --- Bibliotek.dk versions of Ding2 modules ---

projects[ding_base][type] = module
projects[ding_base][download][type] = git
projects[ding_base][download][url] = git@github.com:DBCDK/ding_base.git
projects[ding_base][download][tag] = 7.x-0.4

projects[ding_entity][type] = module
projects[ding_entity][download][type] = git
projects[ding_entity][download][url] = git@github.com:DBCDK/ding_entity.git
projects[ding_entity][download][tag] = 7.x-0.7+dbc.1

projects[ding_facetbrowser][type] = module
projects[ding_facetbrowser][download][type] = git
projects[ding_facetbrowser][download][url] = git@github.com:DBCDK/ding_facetbrowser.git
projects[ding_facetbrowser][download][tag] = 7.x-0.13+dbc.1

projects[ding_frontpage][type] = module
projects[ding_frontpage][download][type] = git
projects[ding_frontpage][download][url] = git@github.com:DBCDK/ding_frontpage.git
projects[ding_frontpage][download][tag] = 7.x-0.7+dbc.1

projects[ding_wayf][type] = module
projects[ding_wayf][download][type] = git
projects[ding_wayf][download][url] = git@github.com:DBCDK/ding_wayf.git
projects[ding_wayf][download][tag] = 7.x-0.3

projects[ding_persistent_login][type] = module
projects[ding_persistent_login][download][type] = git
projects[ding_persistent_login][download][url] = git@github.com:DBCDK/ding_persistent_login.git
projects[ding_persistent_login][download][tag] = 7.x-0.1

projects[ding_popup][type] = module
projects[ding_popup][download][type] = git
projects[ding_popup][download][url] = git@github.com:DBCDK/ding_popup.git
projects[ding_popup][download][tag] = 7.x-0.4+dbc.1

projects[ding_provider][type] = module
projects[ding_provider][download][type] = git
projects[ding_provider][download][url] = git@github.com:DBCDK/ding_provider.git
projects[ding_provider][download][tag] = 7.x-0.13+dbc.2

projects[ding_user][type] = module
projects[ding_user][download][type] = git
projects[ding_user][download][url] = git@github.com:DBCDK/ding_user.git
projects[ding_user][download][tag] = 7.x-0.19+dbc.2

projects[ting_agency][type] = module
projects[ting_agency][download][type] = git
projects[ting_agency][download][url] = git@github.com:DBCDK/ting_agency.git
projects[ting_agency][download][tag] = 7.x-0.1

projects[ting-client][type] = module
projects[ting-client][download][type] = git
projects[ting-client][download][url] = git@github.com:DBCDK/ting-client.git
projects[ting-client][download][tag] = 7.x-2.2

projects[ting_covers][type] = module
projects[ting_covers][download][type] = git
projects[ting_covers][download][url] = git@github.com:DBCDK/ting_covers.git
projects[ting_covers][download][tag] = 7.x-0.22+dbc.1

projects[ting_openformat][type] = module
projects[ting_openformat][download][type] = git
projects[ting_openformat][download][url] = git@github.com:DBCDK/ting_openformat.git
projects[ting_openformat][download][tag] = 7.x-0.2.1

; --- Bibliotek.dk ---

projects[bibdk_borchk][type] = module
projects[bibdk_borchk][download][type] = git
projects[bibdk_borchk][download][url] = git@github.com:DBCDK/bibdk_borchk.git
projects[bibdk_borchk][download][tag] = 7.x-0.1

projects[bibdkcaptcha][type] = module
projects[bibdkcaptcha][download][type] = git
projects[bibdkcaptcha][download][url] = git@github.com:DBCDK/bibdkcaptcha.git
projects[bibdkcaptcha][download][tag] = 7.x-0.1

projects[bibdk_custom_search][type] = module
projects[bibdk_custom_search][download][type] = git
projects[bibdk_custom_search][download][url] = git@github.com:DBCDK/bibdk_custom_search.git
projects[bibdk_custom_search][download][tag] = 7.x-0.2

projects[bibdk_custom_search_preprocess][type] = module
projects[bibdk_custom_search_preprocess][download][type] = git
projects[bibdk_custom_search_preprocess][download][url] = git@github.com:DBCDK/bibdk_custom_search_preprocess.git
projects[bibdk_custom_search_preprocess][tag] = 7.x-0.1

projects[bibdk_favourite][type] = module
projects[bibdk_favourite][download][type] = git
projects[bibdk_favourite][download][url] = git@github.com:DBCDK/bibdk_favourite.git
projects[bibdk_favourite][download][tag] = 7.x-0.2

projects[bibdk_frontend][type] = module
projects[bibdk_frontend][download][type] = git
projects[bibdk_frontend][download][url] = git@github.com:DBCDK/bibdk_frontend.git
projects[bibdk_frontend][download][tag] = 7.x-0.2

projects[bibdk_help][type] = module
projects[bibdk_help][download][type] = git
projects[bibdk_help][download][url] = git@github.com:DBCDK/bibdk_help.git
projects[bibdk_help][download][tag] = 7.x-0.2

projects[bibdk_helpdesk][type] = module
projects[bibdk_helpdesk][download][type] = git
projects[bibdk_helpdesk][download][url] = git@github.com:DBCDK/bibdk_helpdesk.git
projects[bibdk_helpdesk][download][tag] = 7.x-0.2

projects[bibdk_linkme][type] = module
projects[bibdk_linkme][download][type] = git
projects[bibdk_linkme][download][url] = git@github.com:DBCDK/bibdk_linkme.git
projects[bibdk_linkme][download][tag] = 7.x-0.1

projects[bibdk_openorder][type] = module
projects[bibdk_openorder][download][type] = git
projects[bibdk_openorder][download][url] = git@github.com:DBCDK/bibdk_openorder.git
projects[bibdk_openorder][download][tag] = 7.x-0.2

projects[bibdk_provider][type] = module
projects[bibdk_provider][download][type] = git
projects[bibdk_provider][download][url] = git@github.com:DBCDK/bibdk_provider.git
projects[bibdk_provider][download][tag] = 7.x-0.2

projects[bibdk_reservation][type] = module
projects[bibdk_reservation][download][type] = git
projects[bibdk_reservation][download][url] = git@github.com:DBCDK/bibdk_reservation.git
projects[bibdk_reservation][download][tag] = 7.x-0.2

projects[bibdk_searchhistory][type] = module
projects[bibdk_searchhistory][download][type] = git
projects[bibdk_searchhistory][download][url] = git@github.com:DBCDK/bibdk_searchhistory.git
projects[bibdk_searchhistory][download][tag] = 7.x-0.2

projects[bibdk_vejviser][type] = module
projects[bibdk_vejviser][download][type] = git
projects[bibdk_vejviser][download][url] = git@github.com:DBCDK/bibdk_vejviser.git
projects[bibdk_vejviser][download][tag] = 7.x-0.2

projects[microcurl][type] = module
projects[microcurl][download][type] = git
projects[microcurl][download][url] = git@github.com:DBCDK/microcurl.git
projects[microcurl][download][tag] = 7.x-0.1

; --- Contrib modules ---

projects[captcha][subdir] = contrib
projects[captcha][type] = module
projects[captcha][version] = 1.0-beta2

projects[ctools][subdir] = contrib
projects[ctools][type] = module
projects[ctools][version] = 1.0
projects[ctools][patch][] = https://raw.github.com/gist/2044786/6b4ef8173f080715a8752067f7b1511a99b8b816/ctools-page_manager_load_task_handlers_alter.patch

projects[entity][subdir] = contrib
projects[entity][type] = module
projects[entity][version] = 1.0-rc3

projects[features][subdir] = contrib
projects[features][type] = module
projects[features][version] = 1.0-rc3

projects[features_extra][subdir] = contrib
projects[features_extra][type] = module
projects[features_extra][version] = 1.x-dev

projects[i18n][subdir] = contrib
projects[i18n][type] = module
projects[i18n][version] = 1.5

projects[libraries][subdir] = contrib
projects[libraries][type] = module
projects[libraries][version] = 1.0

projects[memcache][subdir] = contrib
projects[memcache][type] = module
projects[memcache][version] = 1.0

projects[menu_attributes][subdir] = contrib
projects[menu_attributes][type] = module
projects[menu_attributes][version] = 1.0-rc2

projects[nanosoap][subdir] = contrib
projects[nanosoap][type] = module
projects[nanosoap][version] = 1.0

projects[node_export][subdir] = contrib
projects[node_export][type] = module
projects[node_export][version] = 3.0-rc4

projects[panels][subdir] = contrib
projects[panels][type] = module
projects[panels][version] = 3.2

projects[panels_breadcrumbs][subdir] = contrib
projects[panels_breadcrumbs][type] = module
projects[panels_breadcrumbs][version] = 1.6

projects[persistent_login][subdir] = contrib
projects[persistent_login][type] = module
projects[persistent_login][version] = 1.x-dev

projects[profile2][subdir] = contrib
projects[profile2][type] = module
projects[profile2][version] = 1.2

projects[rules][subdir] = contrib
projects[rules][type] = module
projects[rules][version] = 2.1

projects[securepages][subdir] = contrib
projects[securepages][type] = module
projects[securepages][version] = 1.x-dev
projects[securepages][patch][] = http://drupal.org/files/securepages_1226702_secure_user_login_block_and_keep_form_action_secured.patch

projects[strongarm][subdir] = contrib
projects[strongarm][type] = module
projects[strongarm][version] = 2.0

projects[uuid][subdir] = contrib
projects[uuid][type] = module
projects[uuid][version] = 1.0-alpha3

projects[variable][subdir] = contrib
projects[variable][type] = module
projects[variable][version] = 2.1

projects[views][subdir] = contrib
projects[views][type] = module
projects[views][version] = 3.0

projects[virtual_field][subdir] = contrib
projects[virtual_field][type] = module
projects[virtual_field][version] = 1.0

projects[wysiwyg][subdir] = contrib
projects[wysiwyg][type] = module
projects[wysiwyg][version] = 2.1
