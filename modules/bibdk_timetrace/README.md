bibdk_timetrace
===============

trace request time.
For now only trace of SEARCH requests are timed. 

drupal's search cycle includes a redirect, where the POST request is
transformed to a GET request, so we have to log

POST_START -> POST_END -> GET_START -> GET_END to get total time

in the watchdog log a search cycle will be logged as follows

WATCHDOG output :
  SERVICE_PREFIX::TRACKINGID::OPERATION::METHOD_[END,START]::TIMESTAMP
  
  EXAMPLE:
  BIBDK_GUI::2014-01-16T14:18:35:985027:9895::SEARCH::GET_END::2014-01-16T14:18:42:667730
  BIBDK_GUI::2014-01-16T14:18:35:985027:9895::SEARCH::GET_START::2014-01-16T14:18:40:769062
  BIBDK_GUI::2014-01-16T14:18:35:985027:9895::SEARCH::POST_END::2014-01-16T14:18:40:550547
  BIBDK_GUI::2014-01-16T14:18:35:985027:9895::SEARCH::POST_START::2014-01-16T14:18:35:985049