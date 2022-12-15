from selenium.webdriver.common.by import By
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions
from selenium.webdriver.common.action_chains import ActionChains


import helpers
import time

class TestInfomediaLink(helpers.BibdkUnitTestCase):

    def test_link_present_short_view(self):

        wait = WebDriverWait(self.browser, 20)
        # Search for article 870971:avis-89724244
        self.browser.get(self.base_url)

        self.search_pid('870971-avis:89724244')
        self.assertTrue(self.browser.find_element(BY.ID, 'selid-870971avis89724244'))

        # Expand article view - wait for result
        self.browser.find_element(BY.ID, 'selid-870971avis89724244').click()
        wait.until(expected_conditions.presence_of_element_located((By.ID, "870971-avis89724244")))

        # Assert infomedialink is present
        but = wait.until(expected_conditions.presence_of_element_located((By.CLASS_NAME, 'infomedia-button')))

    def test_link_present_full_view(self):

        wait = WebDriverWait(self.browser, 20)
        # Search for article 870971:avis-89724244
        self.browser.get(self.base_url)
        self.search_pid('870971-avis:89724244')
        self.assertTrue(self.browser.find_element(BY.ID, 'selid-870971avis89724244'))

        # Make a new search with expanded view and wait for result
        self.browser.find_element(BY.ID, 'ting-openformat-full-view-button-expanded').click()
        wait.until(expected_conditions.presence_of_element_located((By.ID, "870971-avis89724244")))

        # Assert infomedialink is present
        but = wait.until(expected_conditions.presence_of_element_located((By.CLASS_NAME, 'infomedia-button')))

    def test_infomedia_view_article(self):
        browser = self.browser
        browser.implicitly_wait(10)
        user = self.getTestUser('190101')
        self.login(user['mail'], user['passwd'])
        url = self.base_url + 'search/work/?search_block_form=rec.id=870971-avis:89724244'
        browser.get(url)
        self._check_pop_up()
        browser.find_element(BY.ID, 'selid-870971avis89724244').click()
        WebDriverWait(self.browser, 30).until(expected_conditions.presence_of_element_located((By.ID, "870971-avis89724244")))

        # open infomedia window
        but = browser.find_element(BY.CLASS_NAME, 'infomedia-button')
        actions = ActionChains(self.browser)
        actions.move_to_element(but)
        actions.click(but)
        actions.perform()

        # wait for popup
        WebDriverWait(browser, 30).until(self.found_window('PopUpWindowreservation'))
        # seitch to popup
        browser.switch_to.window('PopUpWindowreservation')
        # Show article
        browser.find_element(BY.XPATH, '//div[@class="infomedia_HeadLine"]')

    def test_infomedia_login_link(self):
        browser = self.browser
        browser.implicitly_wait(10)
        url = self.base_url + 'search/work/?search_block_form=rec.id=870971-avis:89724244'
        browser.get(url)
        browser.find_element(BY.ID, 'selid-870971avis89724244').click()
        WebDriverWait(self.browser, 30).until(expected_conditions.presence_of_element_located((By.ID, "870971-avis89724244")))

        self._check_pop_up()
        # open infomedia window
        wait = WebDriverWait(self.browser, 20)
        but = wait.until(expected_conditions.presence_of_element_located((By.CLASS_NAME, "infomedia-button")))
        # open infomedia window
        but.click()

        #assert that a link to login is shown
        login_link = browser.find_element(BY.ID, 'infomedia_toggle_link')
        login_link.click()

        browser.find_element(BY.XPATH, '//form[@id="user-login"]')
        #assert that login popup is shown


    # Test flow in infomedia window
    def test_infomedia_popup(self):
        # create user
        user = self.getUser('infomedia_test.bibdk@guesstimate.dbc.dk', 'infomedia_test')
        user.delete()
        user.create()

        # init browser
        browser = self.browser
        browser.implicitly_wait(10)
        # store the mainwindow
        mainwindow = browser.current_window_handle

        wait = WebDriverWait(self.browser, 20)
        # search object with infomedia
        url = self.base_url + 'search/work/?search_block_form=rec.id=870971-avis:89724244'
        browser.get(url)
        browser.find_element(BY.ID, 'selid-870971avis89724244').click()
        WebDriverWait(self.browser, 30).until(expected_conditions.presence_of_element_located((By.ID, "870971-avis89724244")))
        self._check_pop_up()
        but = wait.until(expected_conditions.presence_of_element_located((By.CLASS_NAME, 'infomedia-button')))
        # open infomedia window
        but.click()


    ## Helper method : login using modal window
    def login_with_modal(self, username, password):
        browser = self.browser

        browser.find_element(BY.CLASS_NAME, "bibdk-modal-login").click()

        WebDriverWait(browser, 20).until(expected_conditions.visibility_of_element_located((By.ID, 'edit-name')))

        # get the modal
        modal = browser.find_element(BY.ID, "bibdk-modal")

        # input username
        user = modal.find_element(BY.ID, "edit-name")
        user.clear()
        user.send_keys(username)

        # insert password
        passw = modal.find_element(BY.ID, "edit-pass")
        passw.clear()
        passw.send_keys(password)

        # get submit button
        modal.find_element(BY.ID, "edit-submit").click()

    # Helper method : Search for element with specific pid
    def search_pid(self, pid):
        self.browser.find_element(BY.ID, "edit-search-block-form--2").send_keys("rec.id=" + pid)
        self.browser.find_element(BY.ID, "edit-submit").click()


