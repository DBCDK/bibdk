# -*- coding: utf-8 -*-
from selenium.webdriver.common.by import By
import helpers
import time

class TestBriefDisplay(helpers.BibdkUnitTestCase):

    def test_language_on_brief_display(self):

        browser = self.browser

        # English title (Language added after title)
        browser.get(self.base_url)
        self.search_pid('870970-basis:45553973')
        self.assertEqual(browser.find_element(By.CSS_SELECTOR, 'h2.searchresult-work-title').text, 'Washington, Oregon & the Pacific Northwest (engelsk)')

        # Undefined language (no language added)
        self.search_pid('870971-tsart:34480990')
        self.assertEqual(browser.find_element(By.CSS_SELECTOR, 'h2.searchresult-work-title').text, u'Køge Kyst (dansk)')

        # Danish title (no language added)
        self.search_pid('870970-basis:51048830')
        self.assertEqual(browser.find_element(By.CSS_SELECTOR, 'h2.searchresult-work-title').text, u'Fasandræberne : krimithriller. Bind 1 (dansk)')

    # Helper method : Search for element with specific pid
    def search_pid(self, pid):
        self.browser.find_element(By.ID, "edit-search-block-form--2").clear()
        self.browser.find_element(By.ID, "edit-search-block-form--2").send_keys("rec.id=" + pid)
        self.browser.find_element(By.ID, "edit-submit").click()
