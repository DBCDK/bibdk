# -*- coding: utf-8 -*-

import helpers
import time

class TestBriefDisplay(helpers.BibdkUnitTestCase):

    def test_language_on_brief_display(self):

        browser = self.browser

        # English title (Language added after title)
        browser.get(self.base_url)
        self.search_pid('870970-basis:45553973')
        self.assertEqual(browser.find_element_by_css_selector('h3.searchresult-work-title').text, 'Washington, Oregon & the Pacific Northwest (Engelsk)')

        # Undefined language (no language added)
        self.search_pid('870971-tsart:34480990')
        self.assertEqual(browser.find_element_by_css_selector('h3.searchresult-work-title').text, 'Køge Kyst')

        # Danish title (no language added)
        self.search_pid('870970-basis:51048830')
        self.assertEqual(browser.find_element_by_css_selector('h3.searchresult-work-title').text, "Fasandræberne : krimithriller")

    # Helper method : Search for element with specific pid
    def search_pid(self, pid):
        self.browser.find_element_by_id("edit-search-block-form--2").clear()
        self.browser.find_element_by_id("edit-search-block-form--2").send_keys("rec.id=" + pid)
        self.browser.find_element_by_id("edit-submit").click()
