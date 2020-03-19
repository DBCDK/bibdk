__author__ = 'ana'

import helpers
import time

class TestOpenUserStatusWithNoLibrary(helpers.BibdkUnitTestCase):

    # Test if favourite is added
    def test_add_favourite_libraries(self):
        browser = self.browser
        browser.implicitly_wait(10)
        # Create new user and login
        user = self.getUser('favourite_test.bibdk@guesstimate.dbc.dk', 'favourite_test_pass')
        user.create()
        self.assertTrue(user.login())

        time.sleep(1)
        # Click My page
        browser.get(self.base_url + "user")


        # Click Go to userstatus
        browser.find_element_by_id("selid-mypage-userstatus").click()
        time.sleep(10)

        browser.get(self.base_url + "user")

        # Click Go to userstatus
        #browser.find_element_by_id("selid-mypage-userstatus").click()

        # Assert Check for label: message--warning label_userstatus_no_favourite
        self.assertTrue(browser.find_element_by_class_name('message--warning'))

        # Logout and delete user
        self.assertTrue(user.logout())
        user.delete()
