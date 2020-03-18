from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions
from selenium.webdriver.support.wait import WebDriverWait
import helpers

__author__ = 'hrmoller'


class TestSpecifyArticleData(helpers.BibdkUnitTestCase, helpers.BibdkUser):

    pid1 = "159011-lokalbibl:91285843"
    pid2 = "870970-basis:03301044"
    pid3 = "870970-basis:03243796"
    pid4 = "870970-basis:21921173"
    reservation_path = "reservation/?ids="

    def test_pid_1(self):
        browser = self.browser
        browser.implicitly_wait(10)
        self.login()
        url = self.reservation_path + self.pid1
        self._goto(url)

        #if self._class_is_present("bibdk-modal-login") is True:
        #    self._logmein(browser)

        self.assertFalse(self._xpath_is_present("//fieldset[@id='edit-orderparameters']"))

    def test_pid_2(self):
        browser = self.browser
        browser.implicitly_wait(10)

        self.login()

        url = self.reservation_path + self.pid2
        self._goto(url)

        #if self._class_is_present("bibdk-modal-login") is True:
        #    self._logmein(browser)

        # ensure the fiels is shown as expected
        browser.find_element_by_xpath("//fieldset[@id='edit-orderparameters']")

    def test_pid_3(self):
        browser = self.browser
        browser.implicitly_wait(10)

        self.login()
        url = self.reservation_path + self.pid3
        self._goto(url)

        #if self._class_is_present("bibdk-modal-login") is True:
        #    self._logmein(browser)

        # ensure the fiels is shown as expected
        browser.find_element_by_xpath("//fieldset[@id='edit-orderparameters']")

    def test_pid_4(self):
        browser = self.browser
        browser.implicitly_wait(10)
        self.login()

        url = self.reservation_path + self.pid4
        self._goto(url)

        #if self._class_is_present("bibdk-modal-login") is True:
        #    self._logmein(browser)

        self.assertFalse(self._xpath_is_present("//fieldset[@id='edit-orderparameters']"))


    def _logmein(self, browser):
        # click the login link
        browser.find_element_by_class_name("bibdk-modal-login").click()

        # wait for the form to be loaded in a modal overlay
        form = WebDriverWait(browser, 20).until(expected_conditions.visibility_of_element_located((By.ID, "user-login")))

        # input username
        form.find_element_by_id("edit-name").send_keys(self._username)

        # input password
        form.find_element_by_id("edit-pass").send_keys(self._password)

        #submit
        form.find_element_by_class_name("form-submit").click()

        # wait for the modal window to be gone
        WebDriverWait(browser, 20).until(expected_conditions.invisibility_of_element_located((By.ID, "bibdk-modal")))
