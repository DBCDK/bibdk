from selenium.webdriver.common.by import By
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions
import helpers
import time

__author__ = 'hrmoller'


class TestModalLogin(helpers.BibdkUnitTestCase, helpers.BibdkUser):

    #############################################
    ################### TESTS ###################
    #############################################
    def test_login_after_search(self):
        searchterm = "gormenghast"
        browser = self.browser
        browser.get(self.base_url)

        browser.implicitly_wait(5)
        wait = WebDriverWait(browser, 60)
        #do a search
        self.searchFormSubmit(wait, searchterm)
        #open a manifestation
        container = browser.find_element_by_id('870970basis27002609')
        div = container.find_element_by_class_name('work-header')
        div.click()
        time.sleep(1)
        # login - bug 18342 login fails after a manifestatin has been opened
        self.login()

    def test_wrong_username_password_desktop(self):
        browser = self.browser
        self._new_test()
        self._check_pop_up()
        wait = WebDriverWait(browser, 60)
        modallogin = wait.until(expected_conditions.visibility_of_element_located((By.CLASS_NAME, "bibdk-modal-login")))
        # find the loginlink and click it
        modallogin.click()
        # store the modal container
        modal = browser.find_element_by_id("bibdk-modal")
        # wait for the presence of "edit-name. If it ain't found within 10 secs a
        # TimeoutException will be thrown.
        # If the element is found, it is returned for further use
        user = WebDriverWait(modal, 20).until(expected_conditions.visibility_of_element_located((By.ID, "edit-name")))
        # input username
        user.send_keys("wrong_username")
        # get password field
        passw = browser.find_element_by_id("edit-pass")
        # insert (wrong) password
        passw.send_keys("wrong_password")
        # submit the form
        modal.find_element_by_id("bibdk-login-submit").click()

        # ensure that we get a warning and an error
        # we haven't typed an emailadress
        # and the combination is not correct
        wait.until(expected_conditions.presence_of_element_located((By.CLASS_NAME, "error")))

        # get the modal-content element to ensure that the error and warning are placed witin it
        modal = browser.find_element_by_id("bibdk-modal")

        modal.find_element_by_class_name("message--warning")
        modal.find_element_by_class_name("message--error")

        # close the window
        # as there might be more elements in the DOM with the class "close" we
        # will start out with selecting our modal window
        modal.find_element_by_class_name("close-reveal-modal").click()

    def test_successfull_login_desktop(self):
        browser = self.browser
        wait = WebDriverWait(browser, 60)

        user = self.getTestUser('190101')
        username = user['mail']
        password = user['passwd']

        # when testing with PhantomJS we have to explicitly set window size to
        # ensure that the modalbox will be displayed within the visible area
        browser.set_window_size(1000, 1000)
        self._new_test()
        self._check_pop_up()
        self._click_login()

        # wait for the modal-box to be displayed
        wait.until(expected_conditions.visibility_of_element_located((By.ID, "bibdk-modal")))
        # wait for the name input field to be visible
        wait.until(expected_conditions.visibility_of_element_located((By.NAME, "name")))
        # get the modal box
        modal = browser.find_element_by_id("bibdk-modal")
        # input username
        modal.find_element_by_name("name").send_keys(username)
        # input password
        modal.find_element_by_name("pass").send_keys(password)
        # click the input button
        modal.find_element_by_name("op").click()
        # wait for the actions to happen by waiting for the #modalContent to be invisible
        wait.until(expected_conditions.invisibility_of_element_located((By.ID, "bibdk-modal")))

        # just to be sure that the page reload has happend we're waiting for the 'my page' 'link to be visible
        wait.until(expected_conditions.visibility_of_element_located((By.ID, "topbar-my-page-link")))

        # ensure we are logged in by checking for the 'my page' link
        topbar_links = browser.find_element_by_class_name("topbar-links")
        topbar_links.find_element_by_xpath("//a[contains(@href,'/user')]")

    def test_forgot_password_desktop(self):
        browser = self.browser
        wait = WebDriverWait(browser, 60)

        username = 'test_modal_login-test_forgot_password@guesstimate.dbc.dk'
        password = 'test_forgot_password'

        user = self.getUser(username, password)
        user.create()

        # when testing with PhantomJS we have to explicitly set window size to
        # ensure that the modalbox will be displayed within the visible area
        browser.set_window_size(1000, 1000)

        self._new_test()
        self._check_pop_up()

        self._click_login()

        # wait for the modal-box to be displayed
        wait.until(expected_conditions.visibility_of_element_located((By.ID, "bibdk-modal")))

        # wait for the forgot password link to be visible
        wait.until(expected_conditions.visibility_of_element_located((By.CLASS_NAME, "forgot-pword-link")))

        # get the modal box
        modal = browser.find_element_by_id("bibdk-modal")

        WebDriverWait(modal, 30).until(expected_conditions.visibility_of_element_located((By.CLASS_NAME, 'ajax-processed')))

        # get and click the forgot password link
        modal.find_element_by_class_name("forgot-pword-link").click()

        # wait for the new form to be loaded
        wait.until(expected_conditions.presence_of_element_located((By.XPATH, "//form[@id='user-pass']")))

        # select the entire form, input out username and submit it
        form = browser.find_element_by_xpath("//form[@id='user-pass']")
        form.find_element_by_name("name").send_keys(username)
        form.find_element_by_name("op").click()

        # wait for the actions to happen by waiting for the #modalContent to be invisible
        wait.until(expected_conditions.invisibility_of_element_located((By.ID, "bibdk-modal")))

        messages = WebDriverWait(browser, 60).until(expected_conditions.visibility_of_element_located((By.ID, "messages")))
        # ensure that a confirmation message is displayed to the user
        messages.find_element_by_class_name("message--status")

    def test_create_new_user_desktop(self):
        browser = self.browser
        browser.implicitly_wait(20)
        wait = WebDriverWait(browser, 60)

        # when testing with PhantomJS we have to explicitly set window size to
        # ensure that the modalbox will be displayed within the visible area
        browser.set_window_size(1000, 1000)
        self._new_test()
        self._check_pop_up()
        self._click_login()

        # wait for the modal-box to be displayed
        wait.until(expected_conditions.visibility_of_element_located((By.ID, "bibdk-modal")))
        # wait for the register link to be visible
        wait.until(expected_conditions.visibility_of_element_located((By.CLASS_NAME, "register-link")))
        # get the modal box
        modal = browser.find_element_by_id("bibdk-modal")
        WebDriverWait(modal, 60).until(expected_conditions.visibility_of_element_located((By.CLASS_NAME, 'ajax-processed')))
        # get the modal box
        modal = browser.find_element_by_id("bibdk-modal")
        # get and click the create new user
        modal.find_element_by_class_name("register-link").click()
        # wait for the new form to be loaded and store it in a local variable
        form = wait.until(expected_conditions.visibility_of_element_located((By.XPATH, "//form[@id='user-register-form']")))
        # assert that the email imput field is displayed
        form.find_element_by_id("edit-mail")
        # assert that the captcha is displayed
        #form.find_element_by_id("bibdkcaptcha-controls")
        # assert that a input field for the captcha riddle is displayed
        form.find_element_by_id("edit-captcha-response")
        # assert that we have a submit button
        action = form.find_element_by_class_name("form-submit")

        # do a submit. Use an already existing user
        user = self.getTestUser('190101')
        username = user['mail']

        form.find_element_by_id("edit-mail").send_keys(username)
        action.click()

        # assert that an error is displayed
        browser.find_element_by_class_name('message--error')


    '''
    PJO 19/05/19 outcommented - FIX IT
    def test_form_direct_links_desktop(self):
        browser = self.browser

        # when testing with PhantomJS we have to explicitly set window size to
        # ensure that the modalbox will be displayed within the visible area
        browser.set_window_size(1000, 1000)
        self._new_test()

        # Test nojs forgot password form
        browser.get(self.base_url + "user/password")

        # wait for the login form to be present
        WebDriverWait(browser, 20).until(expected_conditions.presence_of_element_located((By.XPATH, "//form[@id='user-pass']")))

        # Test nojs register new userform
        browser.get(self.base_url + "user/register")

        # wait for the login form to be present
        WebDriverWait(browser, 20).until(expected_conditions.presence_of_element_located((By.XPATH, "//form[@id='user-register-form']")))
    '''    

    def test_redirect_after_login(self):
        browser = self.browser
        wait = WebDriverWait(browser, 60)
        username = 'test_redirect_after_login@guesstimate.dbc.dk'
        password = 'test_redirect_after_login'

        user = self.getUser(username, password)
        user.create()

        # when testing with PhantomJS we have to explicitly set window size to
        # ensure that the modalbox will be displayed within the visible area
        browser.set_window_size(1000, 1000)
        self._new_test()
        # execute a search
        self.searchFormSubmit(wait, "harry potter")
        # wait for the search result to load
        wait.until(expected_conditions.presence_of_element_located((By.CLASS_NAME, "pane-ting-openformat-search-result")))
        self.login()
        # check that the carousel is present - it is only on the frontpage
        wait.until(expected_conditions.presence_of_element_located((By.CLASS_NAME, "pane-carousel")))
    '''
    def test_modal_in_reservation_step_one_and_two(self):
        browser = self.browser

        # when testing with PhantomJS we have to explicitly set window size to
        # ensure that the modalbox will be displayed within the visible area
        browser.set_window_size(1000, 1000)

        self._new_test()

        browser.implicitly_wait(10)

        # goto a reservation url
        browser.get(self.base_url + "reservation?ids=870970-basis%3A44673215")

        # as we're not logged we should get a message (status) shown
        messages = browser.find_element_by_id("messages")
        messages.find_element_by_class_name("message--warning")

        # ensure that we have a login link shown within the messages
        login = messages.find_element_by_xpath("//a[contains(@href,'bibdk_modal/login')]")

        # click the login link
        login.click()

        # wait for the modal-box to be displayed
        modal = WebDriverWait(browser, 30).until(expected_conditions.presence_of_element_located((By.ID, "bibdk-modal")))

        # wait for the login form to be loaded
        WebDriverWait(browser, 30).until(expected_conditions.visibility_of_element_located((By.XPATH, "//form[@id='user-login']")))

        # close the modal
        modal.find_element_by_class_name("close-reveal-modal").click()

        # get the form
        form = browser.find_element_by_id("bibdk-reservation-create-wizard-form")

        # get the agency search box and input Guldborgsund
        form.find_element_by_id("edit-anyfield").send_keys("Guldborgsund")

        # submit the form
        form.find_element_by_class_name("form-submit").click()

        # wait for the search results to be displayed
        select_lib = WebDriverWait(browser, 30).until(expected_conditions.presence_of_element_located((By.NAME, "branch-737600")))

        # select out agency
        select_lib.click()

        # wait for the #edit-manifestation to be visible
        WebDriverWait(browser, 20).until(expected_conditions.presence_of_element_located((By.ID, "edit-manifestation")))

        # as we're not logged we should get a message (status) shown
        messages = browser.find_element_by_id("messages")
        messages.find_element_by_class_name("message--warning")

        # ensure that we have a login link shown within the messages
        login = messages.find_element_by_xpath("//a[contains(@href,'bibdk_modal/login')]")

        # click the login link
        login.click()

        # wait for the modal-box to be displayed
        modal = WebDriverWait(browser, 30).until(expected_conditions.presence_of_element_located((By.ID, "bibdk-modal")))

        # wait for the login form to be loaded
        WebDriverWait(browser, 30).until(expected_conditions.visibility_of_element_located((By.XPATH, "//form[@id='user-login']")))

        # close the modal
        modal.find_element_by_class_name("close-reveal-modal").click()
    '''

    #############################################
    ################## HELPERS ##################
    #############################################
    def _click_login(self):
        browser = self.browser
        topbar_links = browser.find_element_by_class_name("topbar-links")
        topbar_links.find_element_by_xpath("//a[contains(@href, 'bibdk_modal/login')]").click()
