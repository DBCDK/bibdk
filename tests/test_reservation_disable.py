# coding=utf-8
from selenium.webdriver.common.by import By
from selenium.webdriver.support.select import Select
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions
import time

import helpers


# This tess tests the reservation flow
class TestReservation(helpers.BibdkUnitTestCase):

    ##
    # Test that verifies that the order button is disabled
    #
    # This test ensures that the user is presented a link to the local
    # userstatuspage
    ##
    def test_order_button_is_disabled_after(self):
        browser = self.browser
        self._new_test()

        browser.implicitly_wait(20)

        # store the mainwindow
        mainwindow = browser.current_window_handle

        # ensure we have only one window available
        self.assertEqual(1, len(browser.window_handles))

        pid = "870970-basis:28373988"
        pid_id = "any_edition_but_870970basis28373988"

        user = self.getUser()
        self.assertTrue(user.login())

        # do a search
        self._goto("search/work/rec.id=" + pid)
        order_btn = WebDriverWait(browser, 20).until(expected_conditions.presence_of_element_located((By.ID, pid_id)))

        # click the order any edition button
        order_btn.click()

        # click the order link
        browser.find_element_by_id("any_edtion_order_870970basis28373988").click()

        # wait for the PopUpWindow to visible
        WebDriverWait(browser, 20).until(self.found_window('PopUpWindowreservation'))
        # ensure we have two windows available
        self.assertEqual(2, len(browser.window_handles))

        # wait for the selector and select it when it's available
        selector = WebDriverWait(browser, 20).until(expected_conditions.presence_of_element_located((By.CLASS_NAME, "reservation-favourite-selector")))

        # select Guldborgsund
        Select(selector).select_by_value("790900")

        # click the next button
        # remove this step - only three steps now
        #browser.find_element_by_id("edit-next").click()

        # click the next button again
        #browser.find_element_by_xpath("//input[@id='edit-next' and @class='already-clicked']")
        #browser.find_element_by_id("edit-next").click()



        # Check for disabled order button
        #browser.find_element_by_xpath("//input[@id='edit-next' and (@disabled)]")

        # esnure all steps are disabled  -- we are on the last page in the reservation flow
        #browser.find_element_by_xpath("//input[@id='edit-1' and @disabled]")
        #browser.find_element_by_xpath("//input[@id='edit-2' and @disabled]")
        #browser.find_element_by_xpath("//input[@id='edit-3' and @disabled]")
        #browser.find_element_by_xpath("//input[@id='edit-4' and @disabled]")








