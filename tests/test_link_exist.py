__author__ = 'ana'

import helpers
from selenium.webdriver.common.by import By
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions
from selenium.webdriver.common.action_chains import ActionChains
from urllib.parse import urlparse
import time

class LinkMeTestCase(helpers.BibdkUnitTestCase):
    base_search_url = helpers.BibdkHelpers().base_url() + "search/work/"

    def testLinkMeText(self):

        #Check that 'link_me' text is not empty
        browser = self.browser
        search = 'rec.id=870971-tsart:35908412'
        url = self.base_search_url + search
        browser.get(url)
        browser.implicitly_wait(10)
        self._check_pop_up()

        # Click on 'vis mere'
        show_more = browser.find_element_by_id("selid-870971tsart35908412")
        show_more.click()

        time.sleep(2)
        # Click on 'link til dennne post'
        linkme = WebDriverWait(browser, 60).until(
            expected_conditions.element_to_be_clickable((
                By.XPATH, "//a[contains(@data-dropdown, 'selid-linkme-870971-tsart35908412--2')]"
            ))
        )
        linkme.click()

        # Get linktext
        linktext = browser.find_element_by_id('edit-link')
        href = linktext.get_attribute('value')

        expected="/linkme.php?rec.id=870971-tsart%3A35908412"
        # take out host part - to make it work on different hosts
        parts = urlparse(href)
        actual=parts.path + '?' + parts.query
        # Test linktext result - can not be empty
        self.assertEqual(expected,actual, "URL's doesn't match ")

    '''
    pjo 26-11-19 disabled while sbcopy is closed
    def testLinkMeTextSbKopi(self):
        #Check that 'sbkopi link exists, when called with linkme'
        browser = self.browser
        url = self.base_url + "linkme.php?rec.id=870971-tsart%3A34276501"
        browser.get(url)
        browser.implicitly_wait(6)

        # Click on 'link to sbkopi'
        linksbkopi = WebDriverWait(browser, 60).until(expected_conditions.element_to_be_clickable((By.CLASS_NAME, "link-sbkopi")))
        self._check_pop_up()
        linksbkopi.click()
    '''
