from selenium.webdriver.common.by import By
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions
import time
import helpers


class TestBibdkUsersettings(helpers.BibdkUnitTestCase):
    def test_language_tab(self):
        browser = self.browser
        browser.implicitly_wait(10)
        wait = WebDriverWait(browser, 10)
        browser.get(self.base_url)
        self._check_pop_up()

        self.assertTrue(self.create_user('bibdk_settings_test_01'))
        time.sleep(2)
        wait.until(expected_conditions.element_to_be_clickable((By.CLASS_NAME, "right-off-canvas-toggle"))).click()

        settings = wait.until(expected_conditions.element_to_be_clickable((By.XPATH, "//a[contains(@href, '/settings')]")))
        settings.click()

        language = wait.until(expected_conditions.element_to_be_clickable((By.XPATH, "//a[contains(@href, '#bibdk_language')]")))
        language.click()

        browser.find_element_by_id("edit-elements-bibdk-language-locale-language-da")
        browser.find_element_by_id("edit-elements-bibdk-language-locale-language-en-gb")

    def test_tabs_is_present(self):
        browser = self.browser

        browser.implicitly_wait(10)
        wait = WebDriverWait(browser, 10)
        browser.get(self.base_url)
        self._check_pop_up()

        self.assertTrue(self.create_user('bibdk_settings_test_02'))

        # go to settings page and assert one or more tabs are present
        time.sleep(2)
        wait.until(expected_conditions.element_to_be_clickable((By.CLASS_NAME, "right-off-canvas-toggle"))).click()

        settings = wait.until(expected_conditions.element_to_be_clickable((By.XPATH, "//a[contains(@href, '/settings')]")))
        settings.click()

        wait.until(expected_conditions.element_to_be_clickable((By.XPATH, "//a[contains(@href, '#start_page')]")))
        browser.find_element_by_xpath("//a[contains(@href, '#bibdk_language')]")
        browser.find_element_by_xpath("//a[contains(@href, '#view')]")

    def create_user(self, password):
        name = time.time()
        username = str(name) + '@guesstimate.dbc.dk'

        # create new user and login
        user = self.getUser(username, password)
        user.create()
        time.sleep(2)
        return user.login()
