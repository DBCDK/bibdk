from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions
from selenium.webdriver.support.wait import WebDriverWait
import helpers
import time

class TestBug18049messages(helpers.BibdkUnitTestCase, helpers.BibdkUser):
    def test_warning_message_on_login(self):
        browser = self.browser
        browser.implicitly_wait(5)
        browser.get(self.base_url)

        # click the loginlink
        topbar = browser.find_element_by_class_name("topbar-links")
        topbar.find_element_by_xpath("//a[contains(@href,'bibdk_modal/login')]").click()

        WebDriverWait(browser, 20).until(expected_conditions.visibility_of_element_located((By.ID, 'edit-name')))

        # ensure a warning is displayed
        #browser.find_element_by_class_name("message--warning")

        form = browser.find_element_by_id('user-login')
        username = self._username
        password = self._password

        # fill the fields
        form.find_element_by_id("edit-name").send_keys(username)
        form.find_element_by_id("edit-pass").send_keys(password)
        time.sleep(1)
        self._check_pop_up()

        # login
        form.find_element_by_class_name("form-submit").click()

        # wait a little -- for the modal to disappear and the 'my page' link to be visible
        WebDriverWait(browser, 20).until(expected_conditions.presence_of_element_located((By.ID, "topbar-my-page-link")))

        # verify that no warnings are displayed
        self.assertFalse(self._class_is_present("message--warning"), "Dit not find any warnings")

