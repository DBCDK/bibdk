import unittest
import time

__author__ = 'vibjerg'

import helpers


class TestFavouriteLibraries(helpers.BibdkUnitTestCase):

    # Test if favourite libraries are correctly added cf. bug 17303
    def test_add_favourite_libraries(self):
        browser = self.browser
        browser.implicitly_wait(10)
        # Create new user and login
        user = self.getUser('favourite_test.bibdk@guesstimate.dbc.dk', 'favourite_test_pass')
        user.create()
        self.assertTrue(user.login())


        # Add library to favourites
        browser.get(self.base_url + 'vejviser')
        user.do_consent(browser)
        agency_input = browser.find_element(BY.ID, "edit-openagency-query")
        agency_input.clear()
        agency_input.send_keys('Lyngby')

        browser.find_element(BY.ID, "edit-openagency-submit").click()
        browser.find_element(BY.XPATH, "//a[contains(@href,'/bibdk_favourite_list?agency=717300')]").click()


        browser.get(self.base_url + "user")
        user.do_consent(browser)
        browser.find_element(BY.XPATH, "//div[@id='block-bibdk-frontend-bibdk-tabs']//a[contains(@href,'/bibdk_favourite_list')]").click()

        # Assert library with id 714700 (frederiksberg) has been added
        self.assertTrue(browser.find_element(BY.CLASS_NAME, 'favourite-717300'))

    def test_favourite_link_presence(self):
        browser = self.browser
        browser.implicitly_wait(10)

        name = time.time()
        username = str(name) + '@guesstimate.dbc.dk'
        password = 'test_favourite_link_presence'

        # create new user and login
        user = self.getUser(username, password)
        user.create()
        self.assertTrue(user.login())

        browser.get(self.base_url + "user")
        browser.find_element(BY.XPATH, "//div[@id='block-bibdk-frontend-bibdk-tabs']//a[contains(@href, '/bibdk_favourite_list')]")

if __name__ == '__main__':
    unittest.main()
