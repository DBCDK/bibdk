from selenium.webdriver.common.by import By
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from urllib.parse import urljoin

import helpers

class TestCcl2Cql(helpers.BibdkUnitTestCase):
    def test_ccl_url(self):
        browser = self.browser
        wait = WebDriverWait(browser, 5)
        url = urljoin(self.base_url, "linkme.php?ccl=cl%3D78.9064:9&start=5&step=10")
        browser.get(url)
        # wait for a searchresult
        result = wait.until(
            EC.visibility_of_element_located(
                (
                    By.CLASS_NAME, "search-results"
                )
            )
        )





