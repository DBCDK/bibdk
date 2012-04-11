api = 2
core = 7.x

includes[] = https://raw.github.com/DBCDK/dbcore/feature/omega/dbcore.make

; Profiler lib for profile
;libraries[profiler][download][type] = "git"
;libraries[profiler][download][url] = "http://git.drupal.org/project/profiler.git"
;libraries[profiler][download][revision] = d0137cb42bc7a4e9ce0a0431f875806285d09758
; Patch from http://drupal.org/node/1328796
;libraries[profiler][patch][] = http://drupal.org/files/profiler-reverse.patch

projects[artesis_user_frontend][type] = "module"
projects[artesis_user_frontend][download][type] = "git"
projects[artesis_user_frontend][download][url] = "git@github.com:DBCDK/artesis_user_frontend.git"
projects[artesis_user_frontend][download][tag] = "7.x-0.1"

projects[snapengage][type] = "module"
projects[snapengage][download][type] = "git"
projects[snapengage][download][url] = "http://git.drupal.org/sandbox/arnested/1418742.git"
projects[snapengage][download][branch] = "7.x-1.x"

;; bibliOmega is a subtheme for Bibliotek.dk on ding2omega
projects[bibliOmega][type] = "theme"
projects[bibliOmega][download][type] = "git"
projects[bibliOmega][download][url] = "git@github.com:DBCDK/bibliOmega.git"
;; No tags yet.
; projects[bibliOmega][download][tag] = "7.x-1.0"


; --- Artois versions of Ding2 modules ---

projects[ding_frontend][type] = "module"
projects[ding_frontend][download][type] = "git"
projects[ding_frontend][download][url] = "git@github.com:DBCDK/ding_frontend.git"
projects[ding_frontend][download][tag] = "7.x-0.20.4"

projects[ding_library][type] = module
projects[ding_library][download][type] = git
projects[ding_library][download][url] = git@github.com:DBCDK/ding_library.git
projects[ding_library][download][tag] = "7.x-0.17"

projects[ding_user_frontend][type] = "module"
projects[ding_user_frontend][download][type] = "git"
projects[ding_user_frontend][download][url] = "git@github.com:DBCDK/ding_user_frontend.git"
projects[ding_user_frontend][download][tag] = "7.x-0.21.1+dbc.3"

projects[ding_ting_frontend][type] = "module"
projects[ding_ting_frontend][download][type] = "git"
projects[ding_ting_frontend][download][url] = "git@github.com:DBCDK/ding_ting_frontend.git"
projects[ding_ting_frontend][download][tag] = "7.x-0.36+dbc.5"

projects[ding_dibs][type] = "module"
projects[ding_dibs][download][type] = "git"
projects[ding_dibs][download][url] = "git@github.com:DBCDK/ding_dibs.git"
projects[ding_dibs][download][tag] = "7.x-0.36+dbc.5"

projects[ding_debt][type] = "module"
projects[ding_debt][download][type] = "git"
projects[ding_debt][download][url] = "git@github.com:DBCDK/ding_debt.git"
projects[ding_debt][download][tag] = "7.x-0.36+dbc.5"


; --- Bibliotek.dk ---

projects[bibdk_provider][type] = module
projects[bibdk_provider][download][type] = git
projects[bibdk_provider][download][url] = git@github.com:DBCDK/bibdk_provider.git
; projects[bibdk_provider][download][tag] =

projects[bibliomega_frontend][type] = module
projects[bibliomega_frontend][download][type] = git
projects[bibliomega_frontend][download][url] = git@github.com:DBCDK/bibliomega_frontend.git
;projects[bibliomega_frontend][download][tag] =

projects[bibliomega_frontend_blocks][type] = module
projects[bibliomega_frontend_blocks][download][type] = git
projects[bibliomega_frontend_blocks][download][url] = git@github.com:DBCDK/bibliomega_frontend_blocks.git
;projects[bibliomega_frontend_blocks][download][tag] =

projects[features_extra][subdir]=contrib
projects[features_extra][version]=1.x-dev

projects[bibdkcaptcha][type] = module
projects[bibdkcaptcha][download][type] = git
projects[bibdkcaptcha][download][url] = git@github.com:DBCDK/bibdkcaptcha.git
;projects[bibdkcaptcha][download][tag] =

projects[captcha][subdir]=contrib
projects[captcha][type] = module
projects[captcha][version]=7.x-1.0-beta2



