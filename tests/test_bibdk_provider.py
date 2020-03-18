from selenium.webdriver.common.by import By
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.keys import Keys
import helpers


class BibdkProviderTestCase(helpers.BibdkUnitTestCase):
    def test_provider_user_edit(self):
        """
        Verify the submit button is triggered on enter (and not cancel).
        """
        browser = self.browser
        browser.get(self.base_url)
        wait = WebDriverWait(browser, 10)

        user = self.getUser()
        self.assertTrue(user.login())

        browser.get(self.base_url + "user/me/edit")

        pass1 = wait.until(
            EC.visibility_of_element_located((By.ID, "edit-pass-pass1"))
        )
        pass1.send_keys('new_pswd')

        pass2 = wait.until(
            EC.visibility_of_element_located((By.ID, "edit-pass-pass2"))
        )
        pass2.send_keys('new_pswd_foo')

        pass2.send_keys(Keys.RETURN)

        message = wait.until(
            EC.visibility_of_element_located((By.CLASS_NAME, "message--error"))
        )
        print (message.text)
        assert message.text == u'De indtastede oplysninger matcher ikke hinanden'
