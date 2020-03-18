# coding=utf-8
from selenium.webdriver.common.by import By
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions
import time
import helpers

############################################################################
## 2017/05/18: Autocomplete service is disabled due to performance issues ##
##             Disable test for now                                       ##
############################################################################

class BibdkAutocompleteTestCase(helpers.BibdkUnitTestCase):
    ## obsolete test - disabled
    def _test_filter_query(self):
        browser = self.browser
        browser.get(self.base_url + 'bibdk_frontpage/film')
        browser.find_element_by_id("selid_custom_search_expand").click()

        browser.implicitly_wait(20)
        browser.find_element_by_id("selid_custom_search_expand").click()

        browser.find_element_by_id("input-filmens-titel").send_keys('den tredje mand')
        browser.find_element_by_id("input-personer").send_keys('or')
        WebDriverWait(browser, 30).until(expected_conditions.visibility_of_element_located((By.ID, "autocomplete")))

        # assert that there is only one Orson Welles
        auto = browser.find_element_by_id('autocomplete')
        auto.find_element_by_xpath("//*[contains(text(), 'Orson Welles' )]")
        list = auto.find_elements_by_tag_name('li')
        self.assertTrue(len(list) == 1)

    def test_single_word(self):
        browser = self.browser
        browser.get(self.base_url)

        browser.implicitly_wait(20)
        # find and click the expanded search
        browser.find_element_by_id("selid_custom_search_expand").click()

        #creator = browser.find_element_by_id("input-forfatter")
        creator = browser.find_element_by_xpath("//input[starts-with(@id, 'input-forfatter')]")
        creator.send_keys("fis")

        #creator = browser.find_element_by_class_name("form-item-term-creator-ophav")

        WebDriverWait(browser, 30).until(expected_conditions.visibility_of_element_located((By.ID, "autocomplete")))

        autocomplete = browser.find_element_by_id("autocomplete")
        self.assertTrue(autocomplete.is_displayed(), "Autosomplete is visible in at creator field")
        creator.clear()
        time.sleep(1)

        # testing title field
        title = browser.find_element_by_xpath("//input[starts-with(@id, 'input-titel')]")
        title.send_keys("and")

        WebDriverWait(browser, 30).until(expected_conditions.visibility_of_element_located((By.ID, "autocomplete")))

        autocomplete = browser.find_element_by_id("autocomplete")
        self.assertTrue(autocomplete.is_displayed(), "Autosomplete is visible in at creator field")
        #reset title
        title.clear()
        time.sleep(1)

        # testing subject field
        subject = browser.find_element_by_xpath("//input[starts-with(@id, 'input-emne')]")
        subject.send_keys("surf")

        #subject = browser.find_element_by_class_name("form-item-term-subject-emne")

        WebDriverWait(browser, 30).until(expected_conditions.visibility_of_element_located((By.ID, "autocomplete")))

        autocomplete = browser.find_element_by_id("autocomplete")
        self.assertTrue(autocomplete.is_displayed(), "Autosomplete is visible in at creator field")
        subject.clear()
        time.sleep(1)
        # related to bug 17967 - autocomplete on non-frontpage

        '''
        # doing a search and testing everything again
        browser.get(self.base_url + "search/work?search_block_form=hest&op=Søg&year_op=%2522year_eq%2522&form_id=search_block_form&sort=date_descending&page_id=bibdk_frontpage")

        WebDriverWait(browser, 30).until(expected_conditions.visibility_of_element_located((By.ID, "bibdk-facetbrowser-form")))

        # find and click the expanded search
        browser.find_element_by_id("selid_custom_search_expand").click()

        creator = browser.find_element_by_id("input-forfatter")
        creator.send_keys("Jo")

        WebDriverWait(browser, 30).until(expected_conditions.visibility_of_element_located((By.ID, "autocomplete")))

        autocomplete = browser.find_element_by_id("autocomplete")
        self.assertTrue(autocomplete.is_displayed(), "Autosomplete is visible in at creator field")
        creator.clear()
        time.sleep(1)

        # testing title field
        title = browser.find_element_by_id("input-titel")
        title.send_keys("and")

        WebDriverWait(browser, 30).until(expected_conditions.visibility_of_element_located((By.ID, "autocomplete")))

        autocomplete = browser.find_element_by_id("autocomplete")
        self.assertTrue(autocomplete.is_displayed(), "Autosomplete is visible in at creator field")
        title.clear()
        time.sleep(1)

        # testing subject field
        subject = browser.find_element_by_id("input-emne")
        subject.send_keys("surf")

        WebDriverWait(browser, 30).until(expected_conditions.visibility_of_element_located((By.ID, "autocomplete")))

        autocomplete = browser.find_element_by_id("autocomplete")
        self.assertTrue(autocomplete.is_displayed(), "Autosomplete is visible in at creator field")
        subject.clear()
        '''

    #obsolete test - disabled for now
    def _test_multiple_words(self):
        browser = self.browser
        browser.get(self.base_url)

        # find and click the expanded search
        browser.find_element_by_id("selid_custom_search_expand").click()

        creator = browser.find_element_by_id("input-forfatter")
        creator.send_keys("Jo Nesb")
        WebDriverWait(browser, 60).until(expected_conditions.visibility_of_element_located((By.ID, "autocomplete")))

        autocomplete = browser.find_element_by_id("autocomplete")
        self.assertTrue(autocomplete.is_displayed(), "Autosomplete is visible in at creator field")
        creator.clear()

        # testing title field
        title = browser.find_element_by_id("input-titel")
        title.send_keys("Anders And")
        WebDriverWait(browser, 60).until(expected_conditions.visibility_of_element_located((By.ID, "autocomplete")))

        autocomplete = browser.find_element_by_id("autocomplete")
        self.assertTrue(autocomplete.is_displayed(), "Autosomplete is visible in at creator field")
        title.clear()

        # testing subject field
        subject = browser.find_element_by_id("input-emne")
        subject.send_keys("dansk politik")
        WebDriverWait(browser, 60).until(expected_conditions.visibility_of_element_located((By.ID, "autocomplete")))

        autocomplete = browser.find_element_by_id("autocomplete")
        self.assertTrue(autocomplete.is_displayed(), "Autosomplete is visible in at creator field")

        # related to bug 17967 - autocomplete on non-frontpage

        # doing a search and testing everything again
        browser.get(self.base_url + "search/work?search_block_form=hest&op=Søg&year_op=%2522year_eq%2522&form_id=search_block_form&sort=date_descending&page_id=bibdk_frontpage")

        WebDriverWait(browser, 60).until(expected_conditions.visibility_of_element_located((By.ID, "bibdk-facetbrowser-form")))

        # find and click the expanded search
        browser.find_element_by_id("selid_custom_search_expand").click()

        creator = browser.find_element_by_id("input-forfatter")
        creator.send_keys("Jo Nes")
        creator.send_keys("b")
        WebDriverWait(browser, 60).until(expected_conditions.visibility_of_element_located((By.ID, "autocomplete")))

        autocomplete = browser.find_element_by_id("autocomplete")
        self.assertTrue(autocomplete.is_displayed(), "Autosomplete is visible in at creator field")
        creator.clear()

        # testing title field
        title = browser.find_element_by_id("input-titel")
        title.send_keys("Anders And")
        WebDriverWait(browser, 60).until(expected_conditions.visibility_of_element_located((By.ID, "autocomplete")))

        autocomplete = browser.find_element_by_id("autocomplete")
        self.assertTrue(autocomplete.is_displayed(), "Autosomplete is visible in at creator field")
        title.clear()


        # testing subject field
        subject = browser.find_element_by_id("input-emne")
        subject.send_keys("dansk politik")
        WebDriverWait(browser, 60).until(expected_conditions.visibility_of_element_located((By.ID, "autocomplete")))

        autocomplete = browser.find_element_by_id("autocomplete")
        self.assertTrue(autocomplete.is_displayed(), "Autosomplete is visible in at creator field")