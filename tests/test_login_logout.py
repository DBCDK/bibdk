from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions
from selenium.webdriver.support.wait import WebDriverWait
import helpers
import time
__author__ = 'hrmoller'

class TestLoginLogout(helpers.BibdkUnitTestCase, helpers.BibdkUser):

    def test_login_logout_desktop(self):
        browser = self.browser

        username = 'test_login_logout.bibdk@guesstimate.dbc.dk'
        password = 'test_login_logout_pass'

        user = self.getUser(username, password)
        user.create()

        self._goto_frontpage()
        self._check_pop_up()

        # click the loginlink
        topbar_links = browser.find_element(By.CLASS_NAME, "topbar-links")
        topbar_links.find_element(By.CLASS_NAME, "bibdk-modal-login").click()

        # wait for the form to be loaded
        form = WebDriverWait(browser, 30).until(expected_conditions.visibility_of_element_located((By.XPATH, "//form[@id='user-login']")))

        # enure that we have a WAYF link (ding_wayf module is enabled)
        browser.find_element(By.XPATH, '//a[@class="wayflogin-logo"]')

        # fill the fields
        form.find_element(By.ID, "edit-name").send_keys(username)
        form.find_element(By.ID, "edit-pass").send_keys(password)

        # hit submit
        form.find_element(By.CLASS_NAME, "form-submit").click()

        # wait for the logout link to appear (the page have been reloaded)
        WebDriverWait(browser, 30).until(expected_conditions.presence_of_element_located((By.ID, "topbar-my-page-link")))

        # logout -- currently we have no visible logout link
        browser.get(self.base_url + "user/logout")

        # wait for the login link to visible -- if ding_wayf is misconfigured it wont be possible to logout
        WebDriverWait(browser, 30).until(expected_conditions.presence_of_element_located((By.CLASS_NAME, "bibdk-modal-login")))
        topbar_links = browser.find_element(By.CLASS_NAME, "topbar-links")
        topbar_links.find_element(By.CLASS_NAME, "bibdk-modal-login")

        # delete user
        user.delete()

    def test_login_logout_mobile(self):
        browser = self.browser
        browser.set_window_size(480, 768)

        username = 'test_login_logout.bibdk@guesstimate.dbc.dk'
        password = 'test_login_logout_pass'

        user = self.getUser(username, password)
        user.create()

        self._goto_frontpage()

        time.sleep(5)

        self._check_pop_up()

        # click the loginlink
        browser.find_element(By.CLASS_NAME, "right-off-canvas-toggle").click()
        WebDriverWait(browser, 10).until(expected_conditions.visibility_of_element_located((By.CLASS_NAME, "offcanvas-login")))
        browser.find_element(By.CLASS_NAME, "offcanvas-login").click()

        # wait for the form to be loaded
        form = WebDriverWait(browser, 30).until(expected_conditions.visibility_of_element_located((By.XPATH, "//form[@id='user-login']")))

        # enure that we have a WAYF link (ding_wayf module is enabled)
        browser.find_element(By.XPATH, '//a[@class="wayflogin-logo"]')

        # fill the fields
        form.find_element(By.ID, "edit-name").send_keys(username)
        form.find_element(By.ID, "edit-pass").send_keys(password)

        # hit submit
        form.find_element(By.CLASS_NAME, "form-submit").click()

        # wait for the logout link to appear (the page have been reloaded)
        WebDriverWait(browser, 30).until(expected_conditions.presence_of_element_located((By.ID, "topbar-my-page-link")))

        # logout -- currently we have no visible logout link
        browser.get(self.base_url + "user/logout")

        # wait for the login link to visible -- if ding_wayf is misconfigured it wont be possible to logout
        WebDriverWait(browser, 30).until(expected_conditions.presence_of_element_located((By.CLASS_NAME, "bibdk-modal-login")))
        topbar_links = browser.find_element(By.CLASS_NAME, "topbar-links")
        topbar_links.find_element(By.CLASS_NAME, "bibdk-modal-login")

        # delete user
        user.delete()

    def test_information_text_on_login_box(self):
        """
        Verify that information is displayed to user about what kind of login
        to use
        """
        browser = self.browser
        browser.get(self.base_url)
        browser.implicitly_wait(10)
        self._check_pop_up()

        # click the loginlink
        topbar_links = browser.find_element(By.CLASS_NAME, "topbar-links")
        topbar_links.find_element(By.CLASS_NAME, "bibdk-modal-login").click()
        # wait for the form to be loaded
        modal = WebDriverWait(browser, 30).until(expected_conditions.presence_of_element_located((By.ID, "bibdk-modal")))

        # verify that links are present on login form
        browser.find_element(By.XPATH, '//a[@id="bibdk-heimdal-login-link"]')
        browser.find_element(By.CLASS_NAME, 'wayflogin-logo')

        #WebDriverWait(modal, 30).until(expected_conditions.presence_of_element_located((By.CLASS_NAME, "message--warning")))
        #browser.find_element(By.CLASS_NAME, "message--warning")
