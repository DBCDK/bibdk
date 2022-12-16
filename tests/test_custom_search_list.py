from selenium.webdriver.common.by import By
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions
import helpers
import time
from selenium.webdriver.common.action_chains import ActionChains

class TestCustomSearchList(helpers.BibdkUnitTestCase, helpers.BibdkUser):

    #############################################
    ################### TESTS ###################
    #############################################

    ### Skip test until we update chromedriver.
    def _test_list_link_is_present(self):
        browser = self.browser
        browser.implicitly_wait(10)
        browser.get(self.base_url)
        self._check_pop_up()
        # open expanded search
        browser.find_element(By.ID, 'selid_custom_search_expand').click()
        self._check_pop_up()
        wait = WebDriverWait(browser,20)
        # load list
        wait.until(expected_conditions.visibility_of_element_located((By.ID, "edit-namaterialetype-container-link-facet-type")))
        link_all = browser.find_element(By.ID, 'edit-namaterialetype-container-link-facet-type')

        actions = ActionChains(self.browser)
        actions.move_to_element(link_all)
        actions.click(link_all)
        actions.perform()

        wait.until(expected_conditions.visibility_of_element_located((By.ID, "bibdk-modal")))
        # select element form list

        facet = wait.until(expected_conditions.visibility_of_element_located((By.XPATH, "//option[@value=\"facet.type='billedbog'\"]")))
        #browser.find_element(By.ID, 'select-from-list-facet-type').find_element(By.CSS_SELECTOR, "[value='facet.type=billedbog']").click()
        facet.click()
        browser.find_element(By.CLASS_NAME, 'custom-search-list-action').click()
        browser.find_element(By.CLASS_NAME, 'custom-search-list-save').click()
        # Assert element is present

        #browser.find_element(By.CSS_SELECTOR, 'input[value="facet.type=billedbog"]')
        # Make search + assert element
        time.sleep(1)
        facet = wait.until(expected_conditions.visibility_of_element_located((By.XPATH, "//input[@value=\"facet.type='billedbog'\"]")))
        browser.find_element(By.ID, "edit-submit").click()
        WebDriverWait(browser, 30).until(expected_conditions.presence_of_element_located((By.ID, "selid-870970basis47558964")))
