__author__ = 'vibjerg'

import helpers
import time

class TestAgencySearch(helpers.BibdkUnitTestCase):

    # Test if agency search
    def test_search_agency(self):
        browser = self.browser
        browser.get(self.base_url)

        browser.find_element(By.CLASS_NAME, "right-off-canvas-toggle").click()
        menu = browser.find_element(By.CLASS_NAME, "off-canvas-list")
        menu.find_element(By.XPATH, "//a[contains(@href, 'vejviser')]").click()

        browser.find_element(By.NAME, 'openagency_query').send_keys('frederiksberg')
        browser.find_element(By.ID, 'edit-openagency-submit').click()

        # assert list of libraries
        print(len(browser.find_elements(By.CSS_SELECTOR, ".bibdk-favourite-library")))
        self.assertTrue(len(browser.find_elements(By.CSS_SELECTOR, ".bibdk-favourite-library")) > 10)

        # assert frederiksberg hovedbibliotek is present
        browser.find_element(By.CSS_SELECTOR, '.bibdk-favourite-library.favourite-714700')

        # assert more info
        browser.find_element(By.CSS_SELECTOR, '.bibdk-favourite-library.favourite-714700').click()

        # assert Servicedeclaration (bug 17981)
        link = browser.find_element(By.CSS_SELECTOR, '.is-toggled > div:nth-child(1) > div:nth-child(2) > div:nth-child(4) > ul:nth-child(1) > li:nth-child(1) > a:nth-child(1)')
        assert link.get_attribute('href') == "https://fkb.dk/"
