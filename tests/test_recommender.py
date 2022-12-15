from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.wait import WebDriverWait
import helpers
from selenium.webdriver.common.by import By
from selenium.common.exceptions import NoSuchElementException
import time

class TestRecommender(helpers.BibdkUnitTestCase):
    def test_recommendations_in_search_result(self):
        browser = self.browser
        browser.get(self.base_url)
        wait = WebDriverWait(browser, 10)
        # do a search
        search_field = wait.until(EC.visibility_of_element_located((By.XPATH, "//input[starts-with(@id, 'edit-search-block-form')]")))
        search_field.send_keys("flaskepost fra p")
        #time.sleep(5)
        search_but = browser.find_element(BY.XPATH, "//div[@id='search-block-primary']//input[@id='edit-submit']")
        search_but.click()
        #find and click first result in search
        search_result = wait.until(EC.visibility_of_element_located((By.CLASS_NAME, "work-header")))
        search_result.click()
        #assert that recommender is present
        try:
            recommender = wait.until((EC.visibility_of_element_located((By.CLASS_NAME, "bibdk-recommender-carousel-content"))))
        except NoSuchElementException:
            assert False


