from selenium.webdriver.support import expected_conditions
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.common.by import By
import helpers

class bibliotekdkTestPager(helpers.BibdkUnitTestCase):
    def test_pager(self):
        browser = self.browser
        wait = WebDriverWait(browser, 30)
        browser.set_window_size(1440, 1800)

        browser.get(self.base_url+'/search/work/hest')

        #assert that the pager is present
        page = wait.until(
            expected_conditions.visibility_of_element_located(
                (By.CSS_SELECTOR, '.content')
            )
        )

        pager_next = wait.until(
            expected_conditions.visibility_of_element_located(
                (By.CSS_SELECTOR, '.bibdk-pager-next a')
            )
        )
        pager_next.click()

        # assert that pager_previous link is shown
        pager_next = wait.until(
            expected_conditions.visibility_of_element_located(
                (By.CSS_SELECTOR, '.bibdk-pager-previous a')
            )
        )

        #click the link again
        pager_next = wait.until(
            expected_conditions.visibility_of_element_located(
                (By.CSS_SELECTOR, '.bibdk-pager-next a')
            )
        )
        pager_next.click()

        #assert that pager_first element is shown
        pager_next = wait.until(
            expected_conditions.visibility_of_element_located(
                (By.CSS_SELECTOR, '.bibdk-pager-first')
            )
        )

        # For smaller viewports, the pager is a svg icon.
        browser.set_window_size(975, 1800)
        pager_next = wait.until(
            expected_conditions.visibility_of_element_located(
                (By.CSS_SELECTOR, '.bibdk-pager-next')
            )
        )
        pager_next.click()
