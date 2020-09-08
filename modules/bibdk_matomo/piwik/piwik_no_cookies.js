/**
 * Collects bibliotek.dk statistic for stats.dbc.dk.
 * this one does tracking only. @see https://developer.matomo.org/guides/tracking-consent
 * by setting ['requireCookieConsent']
 */
var _paq = _paq || [];
_paq.push(['requireCookieConsent']);
_paq.push(['trackPageView']);
_paq.push(['enableLinkTracking']);
(function() {
  var u="//stats.dbc.dk/";
  _paq.push(['setTrackerUrl', u+'piwik.php']);
  _paq.push(['setSiteId', 32]);
  var d=document, g=d.createElement('script'), s=d.getElementsByTagName('script')[0];
  g.type='text/javascript'; g.async=true; g.defer=true; g.src=u+'piwik.js'; s.parentNode.insertBefore(g,s);
})();




