import helpers
from selenium.webdriver.common.by import By

class TestNo_hit_suggestion(helpers.BibdkUnitTestCase, helpers.BibdkUser):

    def test_no_search_result_suggestion(self):
        browser = self.browser

        # do a actiual search request
        self._goto("search/work/tjajkov")
        browser.find_element(By.ID, "edit-submit").click()

        # get all messages
        messages = browser.find_element(By.ID, "messages")

        # ensure that we have a message og type warning
        messages.find_element(By.CLASS_NAME, "message--warning")

        # ensure some suggestion is actually displayed
        ## 05/17/05/2017: Suggestion service is disabled due to performance issues
        ## browser.find_element(By.CLASS_NAME, "bibdk-suggest-label")





