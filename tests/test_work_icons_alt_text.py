import helpers
from selenium.webdriver.common.by import By

class TestWorkIconsAltText(helpers.BibdkUnitTestCase):
    def test_alt_text(self):
        browser = self.browser
        browser.implicitly_wait(10)
        url = self.base_url + '/search/work/rec.id=820030-katalog%3A626417'
        browser.get(url)
        element = browser.find_elements(By.CSS_SELECTOR, '.media-book title')
        if not u"Bog" in element[0].text:
            assert False
