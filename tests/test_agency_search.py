__author__ = 'vibjerg'

import helpers

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
        print(len(browser.find_elements_by_css_selector(".ting-agency-library")))
        self.assertTrue(len(browser.find_elements_by_css_selector(".bibdk-favourite-library")) > 10)

        # assert frederiksberg hovedbibliotek is present
        browser.find_element_by_css_selector('.bibdk-favourite-library.favourite-714700')

        # assert more info
        browser.find_element_by_css_selector('.bibdk-favourite-library.favourite-714700').click()

        # assert Servicedeclaration (bug 17981)
        browser.find_element_by_xpath("//a[contains(@href,'http://www.fkb.dk/page85.asp')]")
