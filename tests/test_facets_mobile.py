from selenium.webdriver.common.by import By
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions
import helpers
import time


class TestMobileFacets(helpers.BibdkUnitTestCase):

    def test_mobile_facets(self):
        browser = self.browser
        browser.implicitly_wait(10)
        browser.get(self.base_url)
        self._check_pop_up()

        # testing on medium size (W: 480 - 768)
        browser.set_window_size(460, 768)

        # execute a search
        browser.get(self.base_url + "search/work/danmark")

        # check that the desktop facetbrowser is hidden
        WebDriverWait(browser, 60).until(expected_conditions.presence_of_element_located((By.ID, "bibdk-facetbrowser-form")))
        desktop_facetbrowser = browser.find_element_by_id("bibdk-facetbrowser-form")
        self.assertFalse(desktop_facetbrowser.is_displayed(), "bibdk-facetbrowser-form should not be visible")

        # check that link to mobile bacetbrowser is visible
        # mobile_facetbrowser_link = browser.find_element_by_class_name("bibdk-facets-mobile")
        mobile_facetbrowser_link = browser.find_element_by_id("selid-bibdk-facets-mobile")
        self.assertTrue(mobile_facetbrowser_link.is_displayed(), "mobile_facetbrowser link should be visible")

        # select 'material type' facets, and submit form
        mobile_facetbrowser_link.click()


        # facet groups form is shown
        #WebDriverWait(browser, 10).until(expected_conditions.presence_of_element_located((By.ID, "bibdk-facetbrowser-mobile-form")))
        WebDriverWait(browser, 10).until(expected_conditions.presence_of_element_located((By.XPATH,"//form[@id='bibdk-facetbrowser-mobile-form']")))
        time.sleep(1)

        # check that the reset facet link  is visible
        reset_facet_link  = browser.find_element_by_class_name("reset-facets")
        self.assertTrue(reset_facet_link.is_displayed(), "reset facet link should be visible")

        # check that the material type facet is visible
        material_type_facet = browser.find_element_by_id("facet-mobile-type")
        self.assertTrue(material_type_facet.is_displayed(), "material type facet element should be visible")

        # check that the material type facet is clickable
        # WebDriverWait(browser, 60).until(expected_conditions.element_to_be_clickable((By.CLASS_NAME, "form-submit")))
        WebDriverWait(browser, 60).until(expected_conditions.element_to_be_clickable((By.NAME, "facetgroup-facet.type")))

        # select 'material type' facets, and submit form
        material_type_facet.find_element_by_class_name("form-submit").click()


        # facet values form is shown
        #WebDriverWait(browser, 10).until(expected_conditions.presence_of_element_located((By.ID, "bibdk-facetbrowser-mobile-form--2")))
        WebDriverWait(browser, 10).until(expected_conditions.presence_of_element_located((By.XPATH,"//form[@id='bibdk-facetbrowser-mobile-form--2']")))

        # check that the facet checkmark for bog is invisible
        facet_value_bog = browser.find_element_by_id("mobile-facet-value-bog")

        checkmark = facet_value_bog.find_element_by_class_name("svg-icon")
        self.assertFalse(checkmark.is_displayed(), "checkmark should be hidden")

        # check that the mobile-facet-value-bog is clickable
        WebDriverWait(browser, 60).until(expected_conditions.element_to_be_clickable((By.ID, "mobile-facet-value-bog")))
        browser.find_element_by_id("mobile-facet-value-bog").click()

        self.assertTrue(checkmark.is_displayed(), "checkmark should be visible")

        # submit form
        WebDriverWait(browser, 60).until(expected_conditions.element_to_be_clickable((By.NAME, "facetgroup-facet.type")))
        browser.find_element_by_name("facetgroup-facet.type").click()


        # new search is executed
        WebDriverWait(browser, 60).until(expected_conditions.presence_of_element_located((By.CLASS_NAME, "search-results")))
