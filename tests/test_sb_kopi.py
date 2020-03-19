from selenium.webdriver.common.by import By
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions
import helpers


class TestSBKopi(helpers.BibdkUnitTestCase):
    def test_bestil_gratis_e_kopi_link(self):
        browser = self.browser
        single_work_pid = "work/870971-tsart:34276501"
        browser.get(self.base_url + single_work_pid)

        browser.find_element_by_id("870971-tsart34276501")

    '''
    def test_bestil_kopi_on_single_work(self):
        browser = self.browser
        single_work_pid = "work/870971-tsart:35977937"
        browser.get(self.base_url + single_work_pid)
        manifestation = browser.find_element_by_id("870971-tsart35977937")
        WebDriverWait(manifestation, 20).until(expected_conditions.visibility_of_element_located((By.XPATH, "//a[contains(@href,'reservation/sbkopi/870971-tsart%3A35977937')]")))

    def test_sbkopi_popup_window(self):
        browser = self.browser
        browser.get(self.base_url + 'search/work/870971-tsart:35977937')
        self.browser.find_element_by_id('selid-870971tsart35977937').click()
        browser.implicitly_wait(20)
        browser.find_element_by_xpath("//a[contains(@href,'reservation/sbkopi/870971-tsart%3A35977937')]").click()
        # wait for the PopUpWindow to visible
        WebDriverWait(browser, 20).until(self.found_window('PopUpWindowreservation'))
        # ensure we have two windows available
        self.assertEqual(2, len(browser.window_handles))

    # tests for US 1456 (New flow)
    # Test for library with subscription and postal delivery
    def test_sbkopi_with_subscription(self):
        # setup new user
        username = 'test_sbkopi@guesstimate.dbc.dk'
        password = 'test_sbkopi_pass'
        user = self.getUser(username, password)
        user.delete()
        user.create()
        browser = self.browser

        browser.get(self.base_url + 'reservation/sbkopi/870971-tsart:35977937');

        # user is not logged in
        browser.find_element_by_id('bibdk-sbkopi-reservation-form').find_element_by_xpath("//a[contains(@href,'login')]").click()

        # log in user
        form = WebDriverWait(browser, 30).until(expected_conditions.visibility_of_element_located((By.XPATH, "//form[@id='user-login']")))
        form.find_element_by_id("edit-name").clear()
        form.find_element_by_id("edit-name").send_keys(username)
        form.find_element_by_id("edit-pass").clear()
        form.find_element_by_id("edit-pass").send_keys(password)
        form.find_element_by_class_name("form-submit").click()

        # search for favourite library (dbc test library)
        WebDriverWait(browser, 30).until(expected_conditions.visibility_of_element_located((By.ID, "edit-openagency-query")))
        browser.find_element_by_id('edit-openagency-query').clear()
        browser.find_element_by_id('edit-openagency-query').send_keys('790900')
        browser.find_element_by_id('edit-openagency-submit').click()
        browser.find_element_by_id('edit-openagency-submit').click()

        # select library
        browser.find_element_by_css_selector('input[name="branch-790900"]').click()

        # add userdata
        browser.find_element_by_css_selector('input[name="customId"]').send_keys('pass')
        browser.find_element_by_css_selector('#edit-useraddress').send_keys('adress')
        browser.find_element_by_css_selector('#edit-usermail').send_keys(username)
        browser.find_element_by_css_selector('#edit-submit').click()

        # check message
        message = browser.find_elements_by_css_selector('#messages .message--status')[2].text
        self.assertEqual(message, 'sb_subscription_and_electronic')

        # add required info for order
        browser.find_element_by_name('userName').send_keys('real name')
        # check if mail is pre-inserted
        mail_text_is_set = browser.find_element_by_name('userMail').get_attribute('value')
        self.assertEqual(mail_text_is_set, username)

        # send order
        browser.find_element_by_css_selector('#edit-submit').click()

        # test if user is redirected to receipt
        # browser.find_element_by_css_selector('.browser.find_element_by_css_selector')

    # Test for library without subscription
    def test_sbkopi_no_subscription(self):
        # setup new user
        username = 'test_sbkopi@guesstimate.dbc.dk'
        password = 'test_sbkopi_pass'
        user = self.getUser(username, password)
        user.delete()
        user.create()
        browser = self.browser

        browser.get(self.base_url + 'reservation/sbkopi/870971-tsart:35977937');

        # user is not logged in
        browser.find_element_by_id('bibdk-sbkopi-reservation-form').find_element_by_xpath("//a[contains(@href,'login')]").click()

        # log in user
        form = WebDriverWait(browser, 30).until(expected_conditions.visibility_of_element_located((By.XPATH, "//form[@id='user-login']")))
        form.find_element_by_id("edit-name").clear()
        form.find_element_by_id("edit-name").send_keys(username)
        form.find_element_by_id("edit-pass").clear()
        form.find_element_by_id("edit-pass").send_keys(password)
        form.find_element_by_class_name("form-submit").click()

        # search for favourite library (dbc test library)
        WebDriverWait(browser, 30).until(expected_conditions.visibility_of_element_located((By.ID, "edit-openagency-query")))

        # add Guldborgsund
        browser.find_element_by_id('edit-openagency-query').clear()
        browser.find_element_by_id('edit-openagency-query').send_keys('737600')
        browser.find_element_by_id('edit-openagency-submit').click()
        browser.find_element_by_id('edit-openagency-submit').click()
        browser.find_element_by_name('branch-737600').click()

        # get guldborgsund test user
        user = self.getTestUser("737600")
        # add user data
        browser.find_element_by_name('userId').send_keys(user['userid'])
        browser.find_element_by_name('pincode').send_keys(user['pin'])
        browser.find_element_by_name('userName').send_keys('testUser')
        browser.find_element_by_id('edit-submit').click()

        # check message
        message = browser.find_elements_by_css_selector('#messages .message--status')[2].text
        self.assertEqual(message, 'sb_subscription_and_electronic')

        # add required info for order
        browser.find_element_by_name('userMail').send_keys('test@dbc.dk')
        # check if name is pre-inserted
        name_text_is_set = browser.find_element_by_name('userName').get_attribute('value')
        self.assertEqual(name_text_is_set, 'testUser')

        # send order
        browser.find_element_by_css_selector('#edit-submit').click()

        # test if user is redirected to receipt
        # browser.find_element_by_css_selector('.browser.find_element_by_css_selector')

        #Test manifestation with article fields
    '''
