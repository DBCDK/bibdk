api = 2
core = 7.x

; --- Libraries ---

; Profiler lib for profile
libraries[profiler][download][type] = git
libraries[profiler][download][url] = http://git.drupal.org/project/profiler.git
libraries[profiler][download][revision] = d0137cb42bc7a4e9ce0a0431f875806285d09758
; Patch from http://drupal.org/node/1328796
libraries[profiler][patch][] = http://drupal.org/files/profiler-reverse.patch


; --- Theming ---

projects[omega][type] = theme
;; Currently we'll track the latest released version of Omega. When we
;; get closer to a release we will settle on the latest released
;; version.
; projects[omega][version] = 3.1

projects[ding2omega][type] = theme
projects[ding2omega][download][type] = git
projects[ding2omega][download][url] = git@github.com:DBCDK/ding2omega.git
;; No tags for ding2omega yet.
; projects[ding2omega][download][tag] = 7.x-1.0

;; bibliOmega is a subtheme for Bibliotek.dk on ding2omega
projects[bibliOmega][type] = theme
projects[bibliOmega][download][type] = git
projects[bibliOmega][download][url] = git@github.com:DBCDK/bibliOmega.git
;; No tags yet.
; projects[bibliOmega][download][tag] = 7.x-1.0


; --- Bibliotek.dk versions of Ding2 modules ---

projects[ding_base][type] = module
projects[ding_base][download][type] = git
projects[ding_base][download][url] = git@github.com:DBCDK/ding_base.git
projects[ding_base][download][tag] = 7.x-0.4

projects[ding_campaign][type] = module
projects[ding_campaign][download][type] = git
projects[ding_campaign][download][url] = git@github.com:DBCDK/ding_campaign.git
projects[ding_campaign][download][tag] = 7.x-0.4+dbc.1

projects[ding_entity][type] = module
projects[ding_entity][download][type] = git
projects[ding_entity][download][url] = git@github.com:DBCDK/ding_entity.git
projects[ding_entity][download][tag] = 7.x-0.7

projects[ding_provider][type] = module
projects[ding_provider][download][type] = git
projects[ding_provider][download][url] = git@github.com:DBCDK/ding_provider.git
projects[ding_provider][download][tag] = 7.x-0.13+dbc.1

projects[ding_user][type] = module
projects[ding_user][download][type] = git
projects[ding_user][download][url] = git@github.com:DBCDK/ding_user.git
projects[ding_user][download][tag] = 7.x-0.19

projects[ting][type] = module
projects[ting][download][type] = git
projects[ting][download][url] = git@github.com:DBCDK/ting.git
projects[ting][download][tag] = 7.x-0.22

projects[ting-client][type] = module
projects[ting-client][download][type] = git
projects[ting-client][download][url] = git@github.com:DBCDK/ting-client.git
;projects[ting-client][download][tag] = 7.x-2.1-dev

projects[ting_search][type] = module
projects[ting_search][download][type] = git
projects[ting_search][download][url] = git@github.com:DBCDK/ting_search.git
projects[ting_search][download][tag] = 7.x-0.26


; --- Bibliotek.dk ---

projects[bibliomega_frontend][type] = module
projects[bibliomega_frontend][download][type] = git
projects[bibliomega_frontend][download][url] = git@github.com:DBCDK/bibliomega_frontend.git
;projects[bibliomega_frontend][download][tag] =

projects[bibliomega_frontend_blocks][type] = module
projects[bibliomega_frontend_blocks][download][type] = git
projects[bibliomega_frontend_blocks][download][url] = git@github.com:DBCDK/bibliomega_frontend_blocks.git
;projects[bibliomega_frontend_blocks][download][tag] =

projects[bibdkcaptcha][type] = module
projects[bibdkcaptcha][download][type] = git
projects[bibdkcaptcha][download][url] = git@github.com:DBCDK/bibdkcaptcha.git
;projects[bibdkcaptcha][download][tag] =

projects[bibdk_provider][type] = module
projects[bibdk_provider][download][type] = git
projects[bibdk_provider][download][url] = git@github.com:DBCDK/bibdk_provider.git
; projects[bibdk_provider][download][tag] =

projects[bibdk_searchhistory][type] = module
projects[bibdk_searchhistory][download][type] = git
projects[bibdk_searchhistory][download][url] = git@github.com:DBCDK/bibdk_searchhistory.git
;projects[bibdk_searchhistory][download][tag] =

projects[ding_persistent_login][type] = module
projects[ding_persistent_login][download][type] = git
projects[ding_persistent_login][download][url] = git@github.com:DBCDK/ding_persistent_login.git
;projects[ding_persistent_login][download][tag] =


; --- Contrib modules ---

projects[captcha][subdir] = contrib
projects[captcha][type] = module
projects[captcha][version] = 1.0-beta2

projects[features_extra][subdir]=contrib
projects[features_extra][version]=1.x-dev

projects[persistent_login][subdir] = contrib
projects[persistent_login][type] = module
projects[persistent_login][version] = 1.x-dev

projects[blackhole][subdir] = contrib
projects[blackhole][type] = module
projects[blackhole][download][type] = git
projects[blackhole][download][url] = git@github.com:DBCDK/blackhole.git

projects[virtual_field][subdir] = contrib
projects[virtual_field][type] = module
projects[virtual_field][version] = 1.0
