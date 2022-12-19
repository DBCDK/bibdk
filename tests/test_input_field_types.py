from selenium.webdriver.common.by import By
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions
import helpers
import time

class TestInputFieldType(helpers.BibdkUnitTestCase, helpers.BibdkUser):

    #############################################
    ################### test input field types ###################
    #############################################

    def test_name_is_email(self):
        browser = self.browser
        browser.implicitly_wait(30)
        browser.get(self.base_url)
        # go to new user
        loginlink_xpath = "//a[contains(@href,'bibdk_modal/login')]"
        login_link = browser.find_element(By.XPATH, loginlink_xpath)
        login_link.click()
        WebDriverWait(browser, 30).until(expected_conditions.visibility_of_element_located((By.ID, "bibdk-modal")))
        time.sleep(10)

        user_register_xpath = "//a[contains(@href,'bibdk_modal/register')]"
        register_link = browser.find_element(By.XPATH, user_register_xpath)
        register_link.click()
        time.sleep(10)

        name_input = browser.find_element(By.ID, 'edit-mail')
        type = name_input.get_attribute('type')
        #assert that input name is of type email
        self.assertEqual(type,'email','input type is email')








