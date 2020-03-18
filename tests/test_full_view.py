# coding=utf-8
from selenium.common.exceptions import NoSuchElementException
from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions
from selenium.webdriver.support.wait import WebDriverWait
import time

import helpers


class FullViewTestCase(helpers.BibdkUnitTestCase):
    _multiprocess_can_split_ = True

    searchterm = "harry potter"
    base_search_url = helpers.BibdkHelpers().base_url() + "search/work/"

    #############################################
    ################### TESTS ###################
    #############################################+
    def test_one(self):
        browser = self.browser
        url = self.base_search_url + self.searchterm + "?full_view=1"
        browser.get(url)

        more_infos = browser.find_elements_by_class_name('work')
        count = len(more_infos)
        expected = 10

        try:
            self.assertEqual(count, expected)
        except AssertionError:
            raise AssertionError("Got: " + str(count) + " Expected: " + str(expected))

        try:
            self.assertFalse(self.class_is_present("error"))
        except AssertionError:
            raise AssertionError("Found class messages-error")

    def test_two(self):
        browser = self.browser
        url = self.base_search_url + self.searchterm + "?full_view=0"
        browser.get(url)

        more_infos = browser.find_elements_by_class_name('work')
        count = len(more_infos)
        expected = 10

        try:
            self.assertEqual(count, expected)
        except AssertionError:
            raise AssertionError("Got: " + str(count) + " Expected: " + str(expected))

        try:
            self.assertFalse(False, self.class_is_present("error"))
        except AssertionError:
            raise AssertionError("Found class messages-error")

    def test_two_more_info(self):
        browser = self.browser
        browser.implicitly_wait(20)

        pid = "820030katalog246833"
        work_id = "selid-" + pid
        url = self.base_search_url + self.searchterm + "?full_view=0"
        browser.get(url)
        try:
            browser.find_element_by_id(work_id).click()
        except AssertionError:
            raise AssertionError("Did not find element with href: " + work_id)

        try:
            browser.find_element_by_class_name('work-information')
        except AssertionError:
            raise AssertionError("work did not unfold")

    def test_three_ccl_full_view(self):
        browser = self.browser

        seach = 'dkcclphrase.lem="heste"?full_view=1'
        url = self.base_search_url + seach

        element = '*'
        text = '"Error handling search request: CQL-4: Unknown register"'

        ## browser.get(url) tend to time out, and causes a 504 Gateway Time-out error.
        #browser.get(url)
        #try:
        #    self.assertFalse(self.text_is_present(element, text))
        #except AssertionError:
        #    raise AssertionError("Found string: " + text)

    def test_full_view_user_setting(self):
        browser = self.browser
        browser.implicitly_wait(10)

        user = self.getUser('fullview_usersetting_test.bibdk@guesstimate.dbc.dk', 'fullview_usersetting_test')
        user.delete()
        self.assertTrue(user.create())
        self.assertTrue(user.login())

        WebDriverWait(browser, 30).until(expected_conditions.presence_of_element_located((By.ID, "topbar-my-page-link")))

        browser.get(self.base_url + 'user')
        WebDriverWait(browser, 30).until(expected_conditions.presence_of_element_located((By.XPATH, "//a[contains(@href,'settings')]")))

        self._user.do_consent(browser)
        time.sleep(1)
        # click the usersettings link
        browser.find_element_by_xpath("//div[@id='block-bibdk-frontend-bibdk-tabs']//a[contains(@href,'/settings')]").click()

        time.sleep(1)
        self._user.do_consent(browser)
        # verify that we do se the views tab and click it
        browser.find_element_by_xpath("//a[contains(@href,'#view')]").click()

        # ensure that the checkbox is unchecked
        full_view_selected = browser.find_element_by_name("elements[view][ting_openformat_fullview_usersetting]").is_selected()

        if full_view_selected is True:
            browser.find_element_by_name("elements[view][ting_openformat_fullview_usersetting]").click()
            browser.find_element_by_id("edit-elements-view-actions-submit").click()
            WebDriverWait(browser, 30).until(expected_conditions.presence_of_element_located((By.CLASS_NAME, "message--status")))

        # store the usersettings url for later use
        usersettings_url = browser.current_url

        # perform a search
        browser.get(self.base_search_url + self.searchterm)

        # wait for the search to be completed
        WebDriverWait(browser, 30).until(expected_conditions.presence_of_element_located((By.ID, "ting-openformat-full-view-button-closed")))

        # select the list button
        list_btn = browser.find_element_by_id("ting-openformat-full-view-button-closed")
        # assert it has the inactive class
        self.assertTrue("inactive" in list_btn.get_attribute("class"))

        # select the detail button
        detail_btn = browser.find_element_by_id("ting-openformat-full-view-button-expanded")
        # assert it doesn't have the inactive class
        self.assertFalse("inactive" in detail_btn.get_attribute("class"))

        # go to the usersetttings page
        browser.get(usersettings_url)

        # set the detailed view as our prefered
        browser.find_element_by_xpath("//a[contains(@href,'#view')]").click()
        browser.find_element_by_name("elements[view][ting_openformat_fullview_usersetting]").click()
        browser.find_element_by_id("edit-elements-view-actions-submit").click()
        WebDriverWait(browser, 30).until(expected_conditions.presence_of_element_located((By.CLASS_NAME, "message--status")))

        # perform a search
        browser.get(self.base_search_url + self.searchterm)

        # wait for the search to be completed
        WebDriverWait(browser, 30).until(expected_conditions.presence_of_element_located((By.ID, "ting-openformat-full-view-button-closed")))

        # select the list button
        list_btn = browser.find_element_by_id("ting-openformat-full-view-button-closed")
        # assert it doesn't have the inactive class
        self.assertFalse("inactive" in list_btn.get_attribute("class"))

        # select the detail button
        detail_btn = browser.find_element_by_id("ting-openformat-full-view-button-expanded")
        # assert it has the inactive class
        self.assertTrue("inactive" in detail_btn.get_attribute("class"))

        # Logout and delete user
        self.assertTrue(user.logout())
        user.delete()

    #############################################
    ################## HELPERS ##################
    #############################################
    def class_is_present(self, selector):
        try:
            self.browser.find_element_by_class_name(selector)
        except NoSuchElementException:
            return False

        return True

    def text_is_present(self, element, text):
        try:
            xpath = "//" + element + "[text()[contains(., " + text + ")]]"
            self.browser.find_element_by_xpath(xpath)
        except NoSuchElementException:
            return False

        return True
