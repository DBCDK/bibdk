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
        browser.find_element(By.ID, "selid_custom_search_expand").click()

        browser.implicitly_wait(20)
        browser.find_element(By.ID, "selid_custom_search_expand").click()

        browser.find_element(By.ID, "input-filmens-titel").send_keys('den tredje mand')
        browser.find_element(By.ID, "input-personer").send_keys('or')
        WebDriverWait(browser, 30).until(expected_conditions.visibility_of_element_located((By.ID, "autocomplete")))

        # assert that there is only one Orson Welles
        auto = browser.find_element(By.ID, 'autocomplete')
        auto.find_element(By.XPATH, "//*[contains(text(), 'Orson Welles' )]")
        list = auto.find_elements(By.TAG_NAME, ('li')
        self.assertTrue(len(list) == 1)

    def test_escaping_character(self):
        browser = self.browser
        browser.get(self.base_url)
        wait = WebDriverWait(browser, 30)

        input = wait.until(
            expected_conditions.visibility_of_element_located(
                (By.NAME, 'search_block_form')
            )
        )
        input.send_keys('hvem pukler')

        # Check that there is one suggestion
        auto = wait.until(
            expected_conditions.visibility_of_element_located
            (
                (
                    By.ID, 'autocomplete'
                )
            )
        )
        list = auto.find_elements(By.TAG_NAME, ('li')
        self.assertTrue(len(list) == 1)

        # Check that the '?' has been escaped
        message = wait.until(
            expected_conditions.visibility_of_element_located(
                (
                    By.XPATH, "//*[contains(text(), 'hvem pukler kamelerne for\\?' )]"
                )
            )
        )


    def test_single_word(self):
        browser = self.browser
        browser.get(self.base_url)

        browser.implicitly_wait(20)
        # find and click the expanded search
        browser.find_element(By.ID, "selid_custom_search_expand").click()

        #creator = browser.find_element(By.ID, "input-forfatter")
        creator = browser.find_element(By.XPATH, "//input[starts-with(@id, 'input-forfatter')]")
        creator.send_keys("fis")

        #creator = browser.find_element(By.CLASS_NAME, "form-item-term-creator-ophav")

        WebDriverWait(browser, 30).until(expected_conditions.visibility_of_element_located((By.ID, "autocomplete")))

        autocomplete = browser.find_element(By.ID, "autocomplete")
        self.assertTrue(autocomplete.is_displayed(), "Autosomplete is visible in at creator field")
        creator.clear()
        time.sleep(1)

        # testing title field
        title = browser.find_element(By.XPATH, "//input[starts-with(@id, 'input-titel')]")
        title.send_keys("and")

        WebDriverWait(browser, 30).until(expected_conditions.visibility_of_element_located((By.ID, "autocomplete")))

        autocomplete = browser.find_element(By.ID, "autocomplete")
        self.assertTrue(autocomplete.is_displayed(), "Autosomplete is visible in at creator field")
        #reset title
        title.clear()
        time.sleep(1)

        # testing subject field
        subject = browser.find_element(By.XPATH, "//input[starts-with(@id, 'input-emne')]")
        subject.send_keys("surf")

        #subject = browser.find_element(By.CLASS_NAME, "form-item-term-subject-emne")

        WebDriverWait(browser, 30).until(expected_conditions.visibility_of_element_located((By.ID, "autocomplete")))

        autocomplete = browser.find_element(By.ID, "autocomplete")
        self.assertTrue(autocomplete.is_displayed(), "Autosomplete is visible in at creator field")
        subject.clear()
        time.sleep(1)
        # related to bug 17967 - autocomplete on non-frontpage

        '''
        # doing a search and testing everything again
        browser.get(self.base_url + "search/work?search_block_form=hest&op=Søg&year_op=%2522year_eq%2522&form_id=search_block_form&sort=date_descending&page_id=bibdk_frontpage")

        WebDriverWait(browser, 30).until(expected_conditions.visibility_of_element_located((By.ID, "bibdk-facetbrowser-form")))

        # find and click the expanded search
        browser.find_element(By.ID, "selid_custom_search_expand").click()

        creator = browser.find_element(By.ID, "input-forfatter")
        creator.send_keys("Jo")

        WebDriverWait(browser, 30).until(expected_conditions.visibility_of_element_located((By.ID, "autocomplete")))

        autocomplete = browser.find_element(By.ID, "autocomplete")
        self.assertTrue(autocomplete.is_displayed(), "Autosomplete is visible in at creator field")
        creator.clear()
        time.sleep(1)

        # testing title field
        title = browser.find_element(By.ID, "input-titel")
        title.send_keys("and")

        WebDriverWait(browser, 30).until(expected_conditions.visibility_of_element_located((By.ID, "autocomplete")))

        autocomplete = browser.find_element(By.ID, "autocomplete")
        self.assertTrue(autocomplete.is_displayed(), "Autosomplete is visible in at creator field")
        title.clear()
        time.sleep(1)

        # testing subject field
        subject = browser.find_element(By.ID, "input-emne")
        subject.send_keys("surf")

        WebDriverWait(browser, 30).until(expected_conditions.visibility_of_element_located((By.ID, "autocomplete")))

        autocomplete = browser.find_element(By.ID, "autocomplete")
        self.assertTrue(autocomplete.is_displayed(), "Autosomplete is visible in at creator field")
        subject.clear()
        '''

    #obsolete test - disabled for now
    def _test_multiple_words(self):
        browser = self.browser
        browser.get(self.base_url)

        # find and click the expanded search
        browser.find_element(By.ID, "selid_custom_search_expand").click()

        creator = browser.find_element(By.ID, "input-forfatter")
        creator.send_keys("Jo Nesb")
        WebDriverWait(browser, 60).until(expected_conditions.visibility_of_element_located((By.ID, "autocomplete")))

        autocomplete = browser.find_element(By.ID, "autocomplete")
        self.assertTrue(autocomplete.is_displayed(), "Autosomplete is visible in at creator field")
        creator.clear()

        # testing title field
        title = browser.find_element(By.ID, "input-titel")
        title.send_keys("Anders And")
        WebDriverWait(browser, 60).until(expected_conditions.visibility_of_element_located((By.ID, "autocomplete")))

        autocomplete = browser.find_element(By.ID, "autocomplete")
        self.assertTrue(autocomplete.is_displayed(), "Autosomplete is visible in at creator field")
        title.clear()

        # testing subject field
        subject = browser.find_element(By.ID, "input-emne")
        subject.send_keys("dansk politik")
        WebDriverWait(browser, 60).until(expected_conditions.visibility_of_element_located((By.ID, "autocomplete")))

        autocomplete = browser.find_element(By.ID, "autocomplete")
        self.assertTrue(autocomplete.is_displayed(), "Autosomplete is visible in at creator field")

        # related to bug 17967 - autocomplete on non-frontpage

        # doing a search and testing everything again
        browser.get(self.base_url + "search/work?search_block_form=hest&op=Søg&year_op=%2522year_eq%2522&form_id=search_block_form&sort=date_descending&page_id=bibdk_frontpage")

        WebDriverWait(browser, 60).until(expected_conditions.visibility_of_element_located((By.ID, "bibdk-facetbrowser-form")))

        # find and click the expanded search
        browser.find_element(By.ID, "selid_custom_search_expand").click()

        creator = browser.find_element(By.ID, "input-forfatter")
        creator.send_keys("Jo Nes")
        creator.send_keys("b")
        WebDriverWait(browser, 60).until(expected_conditions.visibility_of_element_located((By.ID, "autocomplete")))

        autocomplete = browser.find_element(By.ID, "autocomplete")
        self.assertTrue(autocomplete.is_displayed(), "Autosomplete is visible in at creator field")
        creator.clear()

        # testing title field
        title = browser.find_element(By.ID, "input-titel")
        title.send_keys("Anders And")
        WebDriverWait(browser, 60).until(expected_conditions.visibility_of_element_located((By.ID, "autocomplete")))

        autocomplete = browser.find_element(By.ID, "autocomplete")
        self.assertTrue(autocomplete.is_displayed(), "Autosomplete is visible in at creator field")
        title.clear()


        # testing subject field
        subject = browser.find_element(By.ID, "input-emne")
        subject.send_keys("dansk politik")
        WebDriverWait(browser, 60).until(expected_conditions.visibility_of_element_located((By.ID, "autocomplete")))

        autocomplete = browser.find_element(By.ID, "autocomplete")
        self.assertTrue(autocomplete.is_displayed(), "Autosomplete is visible in at creator field")
