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
; New bibliotek.dk theme
projects[bibdk_theme][type] = theme
projects[bibdk_theme][download][type] = git
projects[bibdk_theme][download][url] = git@github.com:DBCDK/bibdk_theme.git
projects[bibdk_theme][download][tag] = 7.x-0.73.1


; --- Bibliotek.dk versions of Ding2 modules ---

projects[ding_base][type] = module
projects[ding_base][download][type] = git
projects[ding_base][download][url] = git@github.com:DBCDK/ding_base.git
projects[ding_base][download][tag] = 7.x-0.4

projects[ding_entity][type] = module
projects[ding_entity][download][type] = git
projects[ding_entity][download][url] = git@github.com:DBCDK/ding_entity.git
projects[ding_entity][download][tag] = 7.x-0.7+dbc.3

projects[ding_persistent_login][type] = module
projects[ding_persistent_login][download][type] = git
projects[ding_persistent_login][download][url] = git@github.com:DBCDK/ding_persistent_login.git
projects[ding_persistent_login][download][tag] = 7.x-0.1

projects[ding_popup][type] = module
projects[ding_popup][download][type] = git
projects[ding_popup][download][url] = git@github.com:DBCDK/ding_popup.git
projects[ding_popup][download][tag] = 7.x-0.4+dbc.3

projects[ding_provider][type] = module
projects[ding_provider][download][type] = git
projects[ding_provider][download][url] = git@github.com:DBCDK/ding_provider.git
projects[ding_provider][download][tag] = 7.x-0.13+dbc.9

projects[ding_user][type] = module
projects[ding_user][download][type] = git
projects[ding_user][download][url] = git@github.com:DBCDK/ding_user.git
projects[ding_user][download][tag] = 7.x-0.19+dbc.14.2

projects[ding_wayf][type] = module
projects[ding_wayf][download][type] = git
projects[ding_wayf][download][url] = git@github.com:DBCDK/ding_wayf.git
projects[ding_wayf][download][tag] = 7.x-0.6+dbc.10

projects[ding_webtrends][type] = module
projects[ding_webtrends][download][type] = git
projects[ding_webtrends][download][url] = git@github.com:DBCDK/ding_webtrends.git
projects[ding_webtrends][download][tag] = 7.x-0.2+dbc.2

projects[ding_webtrends_2014][type] = module
projects[ding_webtrends_2014][download][type] = git
projects[ding_webtrends_2014][download][url] = git@github.com:DBCDK/ding_webtrends_2014.git
projects[ding_webtrends_2014][download][tag] = 7.x-0.3

projects[ting-client][type] = module
projects[ting-client][download][type] = git
projects[ting-client][download][url] = git@github.com:DBCDK/ting-client.git
projects[ting-client][download][tag] = 7.x-2.27

projects[ting_agency][type] = module
projects[ting_agency][download][type] = git
projects[ting_agency][download][url] = git@github.com:DBCDK/ting_agency.git
projects[ting_agency][download][tag] = 7.x-0.38

projects[ting_covers][type] = module
projects[ting_covers][download][type] = git
projects[ting_covers][download][url] = git@github.com:DBCDK/ting_covers.git
projects[ting_covers][download][tag] = 7.x-0.22+dbc.14

projects[ting_infomedia][type] = module
projects[ting_infomedia][download][type] = git
projects[ting_infomedia][download][url] = git@github.com:DBCDK/ting_infomedia.git
projects[ting_infomedia][download][tag] = 7.x-1.29

projects[ting_openformat][type] = module
projects[ting_openformat][download][type] = git
projects[ting_openformat][download][url] = git@github.com:DBCDK/ting_openformat.git
projects[ting_openformat][download][tag] = 7.x-0.63

projects[ting_openuserstatus][type] = module
projects[ting_openuserstatus][download][type] = git
projects[ting_openuserstatus][download][url] = git@github.com:DBCDK/ting_openuserstatus.git
projects[ting_openuserstatus][download][tag] = 7.x-0.2

projects[ting_search_carousel][type] = module
projects[ting_search_carousel][download][type] = git
projects[ting_search_carousel][download][url] = git@github.com:DBCDK/ting_search_carousel.git
projects[ting_search_carousel][download][tag] = 7.x-0.5+dbc.7

; --- Bibliotek.dk ---
projects[microcurl][type] = module
projects[microcurl][download][type] = git
projects[microcurl][download][url] = git@github.com:DBCDK/microcurl.git
projects[microcurl][download][tag] = 7.x-0.2

projects[open_adhl][type] = module
projects[open_adhl][download][type] = git
projects[open_adhl][download][url] = git@github.com:DBCDK/open_adhl.git
projects[open_adhl][download][tag] = 7.x-0.3

projects[open_holdingstatus][type] = module
projects[open_holdingstatus][download][type] = git
projects[open_holdingstatus][download][url] = git@github.com:DBCDK/open_holdingstatus.git
projects[open_holdingstatus][download][tag] = 7.x-0.11

projects[open_moreinfo][type] = module
projects[open_moreinfo][download][type] = git
projects[open_moreinfo][download][url] = git@github.com:DBCDK/open_moreinfo.git
projects[open_moreinfo][download][tag] = 7.x-0.3

projects[open_saou][type] = module
projects[open_saou][download][type] = git
projects[open_saou][download][url] = git@github.com:DBCDK/open_saou.git
projects[open_saou][download][tag] = 7.x-0.3

projects[open_voxb][type] = module
projects[open_voxb][download][type] = git
projects[open_voxb][download][url] = git@github.com:DBCDK/open_voxb.git
projects[open_voxb][download][tag] = 7.x-0.1.5

projects[cql_strict_parser][type] = module
projects[cql_strict_parser][download][type] = git
projects[cql_strict_parser][download][url] = git@github.com:DBCDK/cql_strict_parser.git
projects[cql_strict_parser][download][tag] = 7.x-0.4


; THIS MODULE IS ONLY AVAILABLE WITHIN THE DBC A/S ORGANISATION
; PLEASE UNCOMMENT AS THE MODULE WONT BE DOWNLOADABLE OUTSIDE DBC A/S
projects[bibdk_config][type] = module
projects[bibdk_config][download][type] = git
projects[bibdk_config][download][url] = git.dbc.dk:/repos/bibliotek.dk/bibdk_config.git
projects[bibdk_config][download][tag] = 7.x-0.26

projects[bibdk_behaviour][type] = module
projects[bibdk_behaviour][download][type] = git
projects[bibdk_behaviour][download][url] = git.dbc.dk:/repos/bibdk_behaviour.git
projects[bibdk_behaviour][download][tag] = 7.x-0.8


; --- Non Ding2 or Bibliotek.dk specific

projects[translatable][type] = module
projects[translatable][subdir] = contrib
projects[translatable][download][url] = git@github.com:DBCDK/translatable.git
projects[translatable][download][tag] = 7.x-1.1

; --- Contrib modules ---

projects[uuid][subdir] = contrib
projects[uuid][type] = module
projects[uuid][version] = 1.0-alpha6

projects[node_export][subdir] = contrib
projects[node_export][type] = module
projects[node_export][version] = 3.0

projects[admin_menu][subdir] = contrib
projects[admin_menu][type] = module
projects[admin_menu][version] = 3.0-rc4

projects[advagg][subdir] = contrib
projects[advagg][type] = module
projects[advagg][version] = 2.7

projects[captcha][subdir] = contrib
projects[captcha][type] = module
projects[captcha][version] = 1.0-beta2

projects[ctools][subdir] = contrib
projects[ctools][type] = module
projects[ctools][version] = 1.2
projects[ctools][patch][] = https://raw.github.com/DBCDK/drush-features-export-page-variant/master/ctools-page_manager_load_task_handlers_alter.patch
projects[ctools][patch][] = https://www.drupal.org/files/issues/jquery_object_always_true_whether_empty_or_not.diff

projects[date][subdir] = contrib
projects[date][type] = module
projects[date][version] = 2.6

projects[entity][subdir] = contrib
projects[entity][type] = module
projects[entity][version] = 1.5

projects[eu-cookie-compliance][subdir] = contrib
projects[eu-cookie-compliance][type] = module
projects[eu-cookie-compliance][version] = 1.8

projects[features][subdir] = contrib
projects[features][type] = module
projects[features][version] = 1.0

projects[features_extra][subdir] = contrib
projects[features_extra][type] = module
projects[features_extra][version] = 1.0-alpha1

projects[i18n][subdir] = contrib
projects[i18n][type] = module
projects[i18n][version] = 1.12

projects[ie6nomore][subdir] = contrib
projects[ie6nomore][type] = module
projects[ie6nomore][version] = 1.0-beta4

projects[l10n_client][subdir] = contrib
projects[l10n_client][type] = module
projects[l10n_client][version] = 1.1
projects[l10n_client][patch][] = https://raw.github.com/DBCDK/patches/master/dbc_l10n_client/dbc_l10n_client_patch.patch

projects[l10n_update][subdir] = contrib
projects[l10n_update][type] = module
projects[l10n_update][version] = 1.0-beta3
projects[l10n_update][patch][] = http://drupal.org/files/l10n_update-drush_l10n_update_specify_modules-1982580-3.patch

projects[lightbox2][subdir] = contrib
projects[lightbox2][type] = module
projects[lightbox2][version] = 1.0-beta1

projects[libraries][subdir] = contrib
projects[libraries][type] = module
projects[libraries][version] = 2.1

projects[memcache][subdir] = contrib
projects[memcache][type] = module
projects[memcache][version] = 1.0

projects[menu_attributes][subdir] = contrib
projects[menu_attributes][type] = module
projects[menu_attributes][version] = 1.0-rc2

projects[nanosoap][subdir] = contrib
projects[nanosoap][type] = module
projects[nanosoap][version] = 1.0
projects[nanosoap][patch][] = https://raw.github.com/DBCDK/patches/master/nanosoap_simpletest_enabled.patch
projects[nanosoap][patch][] = https://raw.github.com/DBCDK/patches/master/nanosoap_curl_info_getter.patch
projects[nanosoap][patch][] = https://raw.github.com/DBCDK/patches/master/nanosoap-added_curl_cookie.patch

projects[node_export][subdir] = contrib
projects[node_export][type] = module
projects[node_export][version] = 3.0-rc4

projects[panels][subdir] = contrib
projects[panels][type] = module
projects[panels][version] = 3.3

projects[panels_breadcrumbs][subdir] = contrib
projects[panels_breadcrumbs][type] = module
projects[panels_breadcrumbs][version] = 1.6

projects[persistent_login][subdir] = contrib
projects[persistent_login][type] = module
projects[persistent_login][version] = 1.0-beta1

projects[profile2][subdir] = contrib
projects[profile2][type] = module
projects[profile2][version] = 1.2

projects[rules][subdir] = contrib
projects[rules][type] = module
projects[rules][version] = 2.2

projects[securepages][subdir] = contrib
projects[securepages][type] = module
projects[securepages][version] = 1.0-beta1
projects[securepages][patch][] = http://drupal.org/files/securepages_1226702_secure_user_login_block_and_keep_form_action_secured_7.x-1.0-beta1.patch

projects[shortcode][subdir] = contrib
projects[shortcode][type] = module
projects[shortcode][version] = 2.1

projects[strongarm][subdir] = contrib
projects[strongarm][type] = module
projects[strongarm][version] = 2.0

projects[variable][subdir] = contrib
projects[variable][type] = module
projects[variable][version] = 2.1

projects[views][subdir] = contrib
projects[views][type] = module
projects[views][version] = 3.5

projects[virtual_field][subdir] = contrib
projects[virtual_field][type] = module
projects[virtual_field][version] = 1.0

projects[wysiwyg][subdir] = contrib
projects[wysiwyg][type] = module
projects[wysiwyg][version] = 2.1

projects[user_alert][subdir] = contrib
projects[user_alert][type] = module
projects[user_alert][version] = 1.10
projects[user_alert][patch][] = https://raw.githubusercontent.com/DBCDK/patches/master/user_alert_almost_no_ajax_and_no_exceptions.patch

projects[scheduler][subdir] = contrib
projects[scheduler][type] = module
projects[scheduler][version] = 1.1

projects[simple_mobile_redirect][subdir] = contrib
projects[simple_mobile_redirect][type] = module
projects[simple_mobile_redirect][version] = 1.1
