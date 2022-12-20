from selenium.webdriver.common.by import By
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions
import helpers
import time


class TestFavouriteModals(helpers.BibdkUnitTestCase):
    """
    Test that it is possible to find, add/remove and enter user data
    relatedto favourite libraries in a modal.
    """

    def test_add_button_is_invisibble(self):
        """
        Verify that it is not possible to add a favourite while not logged in.
        """
        browser = self.browser
        browser.get(self.base_url + "vejviser?openagency_query=hovedbibliotek")

        self.assertFalse(self._class_is_present("btn-add-library"), "Did not find a \"add\" button")

    def test_add_favourite_library_and_wrong_userdata(self):
        """
        Verify that it is possible to add a favourite when logged in and that an
        error will be shown when no userdata is entered.
        """
        browser = self.browser
        username = 'test_favourite_modal_02.bibdk@guesstimate.dbc.dk'
        password = 'test_favourite_modal_02'
        # create new user and login
        user = self.getUser(username, password)
        user.create()
        self.assertTrue(user.login())
        # search for libraries
        #browser.get(self.base_url + "vejviser?openagency_query=hovedbibliotek")
        self.do_agency_search("hovedbibliotek")
        # add a library to favourites
        browser.find_element(By.XPATH, "//a[contains(@href, 'bibdk_modal/bibdk_favourite_list?agency=715700')]").click()
        #self._user.do_consent(browser)
        WebDriverWait(browser, 30).until(expected_conditions.visibility_of_element_located((By.ID, 'bibdk-favourite-user-form')))
        #self._user.do_consent(browser)
        # get the form and click the submit button (to verify that we will get a error message)
        browser.find_element(By.ID, "bibdk-favourite-user-form").find_element(By.CLASS_NAME, "form-submit").click()
        time.sleep(5)
        browser.find_element(By.ID, "bibdk-modal").find_element(By.CLASS_NAME, "message--error")

    def do_agency_search(self, bib):
        browser = self.browser
        browser.get(self.base_url + "vejviser")
        self._user.do_consent(browser)
        form = browser.find_element(By.ID, 'bibdk-vejviser-form')
        input = form.find_element(By.ID, 'edit-openagency-query')
        input.send_keys(bib)
        submit = form.find_element(By.ID, 'edit-openagency-submit')
        submit.click()

    '''
    ############ THIS TEST HAS BEEN DISABLED - DBC TESTBIBLIOTEK IS BEING SET UP TO USE FBS - WHEN READY FIX IT ######
    def test_entering_favourite_userdata(self):
        """
        Test the process of entering and saving userdata related to a favourite
        library
        """

        browser = self.browser
        browser.implicitly_wait(10)

        browser.get(self.base_url)

        username = 'test_favourite_modal_03.bibdk@guesstimate.dbc.dk'
        password = 'test_favourite_modal_03'

        # create new user and login
        user = self.getUser(username, password)
        user.create()
        self.assertTrue(user.login())

        # search for libraries
        browser.get(self.base_url + "vejviser?openagency_query=DBCTestBibliotek")

        # click an 'add' button and wait for the modal to load
        browser.find_element(By.XPATH, "//a[contains(@href, 'bibdk_modal/bibdk_favourite_list?agency=790900')]").click()
        WebDriverWait(browser, 30).until(expected_conditions.visibility_of_element_located((By.ID, 'bibdk-favourite-user-form')))

        # input required userdata
        valgfri_text = "testhest"
        address = "1234"

        browser.find_element(By.NAME, "customId").send_keys(valgfri_text)
        browser.find_element(By.ID, "edit-useraddress").send_keys(address)
        browser.find_element(By.ID, "edit-usermail").send_keys(username)

        type = browser.find_element(By.ID, 'edit-userid').get_attribute('type')
        self.assertEqual(type,'password','input type is password')
        browser.find_element(By.ID, 'edit-uncheck').click()
        type = browser.find_element(By.ID, 'edit-userid').get_attribute('type')
        self.assertEqual(type,'text','input type is text')


        # submit the form and go to mypage favourites page
        browser.find_element(By.ID, "bibdk-favourite-user-form").find_element(By.CLASS_NAME, "form-submit").click()
        WebDriverWait(browser, 30).until(expected_conditions.visibility_of_element_located((By.XPATH, "//a[contains(@href, 'favourite/remove/790900')]")))

        url = self.base_url + "user"
        browser.get(url)
        browser.find_element(By.CLASS_NAME, "right-off-canvas-toggle").click()
        browser.find_element(By.XPATH, "//a[contains(@href,'bibdk_favourite_list')]").click()

        # verify that the library we just selected is visible in the list
        browser.find_element(By.CLASS_NAME, "favourite-790900")

        # click the edit button and verify that the userdata we entered above is
        # visible (saved)
        browser.find_element(By.XPATH, "//a[contains(@href, 'favourite/userdata/790900')]").click()

        # wait for the form to load
        WebDriverWait(browser, 30).until(expected_conditions.visibility_of_element_located((By.ID, "bibdk-favourite-user-form")))
        self.assertEqual(browser.find_element(By.NAME, "customId").get_attribute('value'), valgfri_text, "valgfri_text is correct")
        self.assertEqual(browser.find_element(By.ID, "edit-useraddress").get_attribute('value'), address, "address is correct")
        self.assertEqual(browser.find_element(By.ID, "edit-usermail").get_attribute('value'), username, "username is correct")
    '''



