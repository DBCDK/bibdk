import helpers

class TestMarkedInputFieldWhenNoInput(helpers.BibdkUnitTestCase):
    def test_red_rings(self):
        self._goto_frontpage()
        browser = self.browser
        self._check_pop_up()
        searchbox = self.browser.find_element_by_id('edit-search-block-form--2')
        searchbox.send_keys('rec.id=820030-katalog:1887566')
        self.browser.find_element_by_id('edit-submit').click()
        order_any_btn = self.browser.find_element_by_class_name('dropdown-wrapper')
        order_any_btn.find_element_by_tag_name('a').click()
        order_book_btn = self.browser.find_element_by_class_name('order-any-btn-list')
        order_book_btn.find_element_by_tag_name('a').click()
        self.browser.switch_to.window('PopUpWindowreservation')
        anyfield = self.browser.find_element_by_id('edit-anyfield')
        anyfield.clear()
        anyfield.send_keys('frederiksberg')
        self.browser.find_element_by_id('edit-search').click()
        self.browser.find_element_by_name('branch-714700').click()
        self.browser.find_element_by_id('edit-next').click()
        customid = self.browser.find_element_by_id('edit-customid')
        self.assertEqual(customid.get_attribute('class'),
            u'bibdk-password-field form-text required error')
        pincode = self.browser.find_element_by_id('edit-pincode')
        self.assertEqual(pincode.get_attribute('class'),
            u'bibdk-password-field form-text required error')
        username = self.browser.find_element_by_id('edit-pincode')
        self.assertEqual(username.get_attribute('class'),
            u'bibdk-password-field form-text required error')
        useraddress = self.browser.find_element_by_id('edit-pincode')
        self.assertEqual(useraddress.get_attribute('class'),
            u'bibdk-password-field form-text required error')
