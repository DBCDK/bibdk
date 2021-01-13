from selenium.webdriver.common.by import By
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions
from selenium.common.exceptions import NoSuchElementException
from selenium.webdriver.common.action_chains import ActionChains
import helpers
import time


class TestFacets(helpers.BibdkUnitTestCase):
    def test_facets_delivered_by_client_side_storage(self):
        browser = self.browser
        browser.get(self.base_url)

        #execute a search
        browser.get(self.base_url + "search/work/danmark")

        #wait for the facetbrowser to be loaded
        WebDriverWait(browser, 20).until(expected_conditions.presence_of_element_located((By.ID, "bibdk-facetbrowser-form")))


        #go to page 2 and enusre we do not see a throbber as facets are delivered from the client-side sessionStorage
        browser.get(self.base_url + "search/work/danmark?page=2")

        #find the left column holding the facets
        left_column = browser.find_element_by_class_name("panel-left")

        #enusre we have no throbber -- if this one fails it might be because facets are not being retrieved by AJAX see /admin/config/ting/facets
        self._assert_no_class("throbber", left_column)
        left_column.find_element_by_id("bibdk-facetbrowser-form")

    def test_facetbrowser(self):
        browser = self.browser
        browser.get(self.base_url)
        wait = WebDriverWait(browser, 5)
        #execute a search
        self.searchFormSubmit(wait,"harry")
        #browser.get(self.base_url + "search/work/harry")
        #wait for the facetbrowser to be loaded
        wait.until(expected_conditions.presence_of_element_located((By.ID, "bibdk-facetbrowser-form")))

        harry_warren = browser.find_element(By.PARTIAL_LINK_TEXT, "harry james")

        facet_subjects = wait.until(
        expected_conditions.visibility_of_element_located((By.XPATH,"//fieldset[@id='facet-subject']")))

        #click show more link
        more = wait.until(
        expected_conditions.visibility_of_element_located((By.XPATH,"//fieldset[@id='facet-subject']//div[@class='fieldset-wrapper']//div[@data-expand='more']/span")))
        ActionChains(browser).move_to_element(more).click().perform()

        # Check if the facetbrowser has any content
        facet_subject_instrumental = browser.find_elements_by_xpath('input[@id="edit-subject-instrumental"]')

        # Check if the facetbrowser has a 'selected' and a 'deselected' fieldset
        facets_selected = browser.find_element(By.ID, "selected-terms")
        facets_deselected = browser.find_element(By.ID, "deselected-terms")

        # Check if the facetbrowser has a 'label_facet_select_unselect' and a 'label_facet_show_more' link
        facet_select_unselect = browser.find_element_by_xpath("//div[@data-expand='select'][@id='edit-filter']/a")
        # open filter form
        facet_select_unselect.click()
        filter_form = wait.until(expected_conditions.presence_of_element_located((By.XPATH, "//form[@id='bibdk-facetbrowser-filter-form']")))

        # PJO outcommented - 'label_facet_deselect' is translated
        #refine_facet_select = browser.find_element_by_xpath("//div[contains(.,'label_facet_deselect')]")

        close = filter_form.find_element_by_xpath("//input[@id='edit-close']")
        close.click()
        #self.assertEqual('label_facet_close', close.get_attribute('value'),'Close button found')
        open = filter_form.find_element_by_xpath("//input[@id='edit-submit']")

    def test_facetbrowser_link_open(self):
        browser = self.browser
        browser.get(self.base_url)

        #execute a search
        browser.get(self.base_url + "search/work/harry")

        #wait for the facetbrowser to be loaded
        WebDriverWait(browser, 20).until(expected_conditions.presence_of_element_located((By.ID, "bibdk-facetbrowser-form")))

        #find the left column holding the facets
        left_column = browser.find_element_by_class_name("panel-left")

        #enusre we have no throbber -- if this one fails it might be because facets are not being retrieved by AJAX see /admin/config/ting/facets
        self._assert_no_class("throbber", left_column)

        #click on unfolded link
        self._check_pop_up()
        left_column.find_element_by_id("facet-form").find_element_by_class_name("icon").click()

        #Check for present of facet viser
        facet_subject_viser = left_column.find_element_by_id('edit-form-viser')

