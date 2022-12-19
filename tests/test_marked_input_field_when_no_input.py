import helpers
import time
from selenium.webdriver.common.by import By

class TestMarkedInputFieldWhenNoInput(helpers.BibdkUnitTestCase):
    def test_red_rings(self):
        self._goto_frontpage()
        browser = self.browser
        self._check_pop_up()
        searchbox = self.browser.find_element(By.ID, 'edit-search-block-form--2')
        searchbox.send_keys('rec.id=820030-katalog:1887566')
        self.browser.find_element(By.ID, 'edit-submit').click()
        order_any_btn = self.browser.find_element(By.CLASS_NAME, 'dropdown-wrapper')
        order_any_btn.find_element(By.TAG_NAME, 'a').click()
        order_book_btn = self.browser.find_element(By.CLASS_NAME, 'order-any-btn-list')
        order_book_btn.find_element(By.TAG_NAME, 'a').click()
        self.browser.switch_to.window('PopUpWindowreservation')
        anyfield = self.browser.find_element(By.ID, 'edit-anyfield')
        anyfield.clear()
        anyfield.send_keys(u'frederiksværk')
        self.browser.find_element(By.ID, 'edit-search').click()
        time.sleep(2)
        self.browser.find_element(By.NAME, 'branch-726000').click()
        time.sleep(5)
        self.browser.find_element(By.ID, 'edit-next').click()
        userid = self.browser.find_element(By.ID, 'edit-userid')
        self.assertEqual(userid.get_attribute('class'),
            u'bibdk-password-field form-text required error')
        pincode = self.browser.find_element(By.ID, 'edit-pincode')
        self.assertEqual(pincode.get_attribute('class'),
            u'bibdk-password-field form-text required error')
        username = self.browser.find_element(By.ID, 'edit-pincode')
        self.assertEqual(username.get_attribute('class'),
            u'bibdk-password-field form-text required error')
        useraddress = self.browser.find_element(By.ID, 'edit-pincode')
        self.assertEqual(useraddress.get_attribute('class'),
            u'bibdk-password-field form-text required error')
