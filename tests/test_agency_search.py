__author__ = 'vibjerg'

import helpers
import time

class TestAgencySearch(helpers.BibdkUnitTestCase):

    # Test if agency search
    def test_search_agency(self):
        browser = self.browser
        browser.get(self.base_url)

        browser.find_element_by_class_name("right-off-canvas-toggle").click()
        menu = browser.find_element_by_class_name("off-canvas-list")
        menu.find_element_by_xpath("//a[contains(@href, 'vejviser')]").click()

        browser.find_element_by_name('openagency_query').send_keys('frederiksberg')
        browser.find_element_by_id('edit-openagency-submit').click()

        # assert list of libraries
        print(len(browser.find_elements_by_css_selector(".bibdk-favourite-library")))
        self.assertTrue(len(browser.find_elements_by_css_selector(".bibdk-favourite-library")) > 10)

        # assert frederiksberg hovedbibliotek is present
        browser.find_element_by_css_selector('.bibdk-favourite-library.favourite-714700')

        # assert more info
        browser.find_element_by_css_selector('.bibdk-favourite-library.favourite-714700').click()

        # assert Servicedeclaration (bug 17981)
        link = browser.find_element_by_css_selector('.is-toggled > div:nth-child(1) > div:nth-child(2) > div:nth-child(4) > ul:nth-child(1) > li:nth-child(1) > a:nth-child(1)')
        assert link.get_attribute('href') == "https://fkb.dk/"
