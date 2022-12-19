from selenium.webdriver.common.by import By
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions
import helpers
import re

class TestNoLogoPrefix(helpers.BibdkUnitTestCase):
    '''Check that there is no prefix in link on logo for default langauge which
       should be Danish (da).'''

    default_lang = 'da'
    other_langauges = ['eng']

    @staticmethod
    def add_slash(x):
        return re.sub('(?<!/)$', '/', x)

    def test_default_no_prefix(self):
        browser = self.browser
        url = self.add_slash(self.base_url)
        self.assertFalse(re.match('/' + self.default_lang + '/$', url), 'Default langauge found at the end of base url.')
        browser.get(url)
        logo_link = browser.find_element(By.XPATH, "//div[@class='topbar-logo']/a")
        href = logo_link.get_attribute('href')
        self.assertEqual(href, url, 'No language prefix found.')


    def test_other_has_prefix(self):
        browser = self.browser
        url = self.add_slash(self.base_url)

        for lang in self.other_langauges:
            lang_url = url + lang
            browser.get(lang_url)
            logo = browser.find_element(By.CSS_SELECTOR, '.topbar-logo a[title="Go to frontpage"]')
            href = logo.get_attribute('href')
            self.assertEqual(href, lang_url, 'Logo link has prefix: ' + lang)
