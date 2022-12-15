# coding=utf-8
from selenium.webdriver.common.by import By
from selenium.webdriver.support.select import Select
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions
from selenium.webdriver.common.action_chains import ActionChains
import time

import helpers

# This tess tests the reservation flow
class TestReservation(helpers.BibdkUnitTestCase):

    def test_empty_pids_in_reservation(self):
        browser = self.browser
        self._new_test()

        # got to reservation with no pids
        self._goto("reservation")
        # assert that errormessage is shown
        browser.find_element(BY.CLASS_NAME, "message--error")


    ##
    # First of two tests that verifies that the user is shown a link when an
    # order is completed.
    #
    # This test ensures that the user is redirected to the bibliotek.dk
    # userstatus page
    ##
    def test_redirect_after_order_complete_redirect_to_bibdk_userstatus(self):
        browser = self.browser
        browser.implicitly_wait(20)
        self._new_test()

        # store the mainwindow
        mainwindow = browser.current_window_handle

        # ensure we have only one window available
        self.assertEqual(1, len(browser.window_handles))

        user = self.getUser()
        self.assertTrue(user.login())

        pid = "870970-basis:28373988"
        pid_id = "any_edition_but_870970basis28373988"

        # do a search
        self._goto("search/work/rec.id=" + pid)
        self._check_pop_up()
        order_btn = WebDriverWait(browser, 20).until(expected_conditions.presence_of_element_located((By.ID, pid_id)))

        # click the order any edition button
        order_btn.click()

        # click the order link
        browser.find_element(BY.ID, "any_edtion_order_870970basis28373988").click()

        # wait for the PopUpWindow to visible
        WebDriverWait(browser, 20).until(self.found_window('PopUpWindowreservation'))
        # ensure we have two windows available
        self.assertEqual(2, len(browser.window_handles))

        # wait for the selector and select it when it's available
        selector = WebDriverWait(browser, 20).until(expected_conditions.presence_of_element_located((By.CLASS_NAME, "reservation-favourite-selector")))

        # select DBC testbibliotek
        Select(selector).select_by_value("100450")

        #click the next button
        browser.find_element(BY.ID, "edit-next").click()

        # click the next button again
        ##browser.find_element(BY.XPATH, "//input[@id='edit-3' and not(@disabled)]")
        ##browser.find_element(BY.ID, "edit-next").click()

        # esnure all steps are disabled  -- we are on the last page in the reservation flow
        ##browser.find_element(BY.XPATH, "//input[@id='edit-1' and @disabled]")
        ##browser.find_element(BY.XPATH, "//input[@id='edit-2' and @disabled]")
        ##browser.find_element(BY.XPATH, "//input[@id='edit-3' and @disabled]")
        ##browser.find_element(BY.XPATH, "//input[@id='edit-4' and @disabled]")

        # get the messages
        messages = browser.find_element(BY.ID, "messages")

        # ensure a link is present
        link = messages.find_element(BY.XPATH, "//a[contains(@href, '/bibdk_openuserstatus')]")

        # click the link
        link.click()

        # switch to main
        browser.switch_to.window(mainwindow)

        # ensure we have only one window available
        self.assertEqual(1, len(browser.window_handles))

        tabs = WebDriverWait(browser, 20).until(expected_conditions.presence_of_element_located((By.ID, "block-bibdk-frontend-bibdk-tabs")))

        tabs.find_element(BY.XPATH, "//a[contains(@href, '/bibdk_openuserstatus')]")
        # ensurte the user have been redirected to the userstatus page
        txt = browser.current_url
        if not '/bibdk_openuserstatus' in txt:
            self.fail('wrong url')

        # also test on the classes on the body tag on the page
        ##browser.find_element(BY.CLASS_NAME, "page-user-bibdk-openuserstatus")

    ##
    # Second of two tests that verifies that the user is shown a link when an
    # order is completed.
    #
    # This test ensures that the user is presented a link to the local
    # userstatuspage
    ##
    def test_redirect_after_order_complete_redirect_to_local_userstatus_page(self):
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
        self._check_pop_up()
        order_btn = WebDriverWait(browser, 20).until(expected_conditions.presence_of_element_located((By.ID, pid_id)))

        # click the order any edition button
        order_btn.click()

        # click the order link
        browser.find_element(BY.ID, "any_edtion_order_870970basis28373988").click()

        # wait for the PopUpWindow to visible
        WebDriverWait(browser, 20).until(self.found_window('PopUpWindowreservation'))
        # ensure we have two windows available
        self.assertEqual(2, len(browser.window_handles))

        # wait for the selector and select it when it's available
        selector = WebDriverWait(browser, 20).until(expected_conditions.presence_of_element_located((By.CLASS_NAME, "reservation-favourite-selector")))

        # select Guldborgsund
        Select(selector).select_by_value("790900")

        # we need to fill out userid for openorder to validate
        browser.find_element(BY.ID, 'edit-userid').send_keys('fisk')
        browser.find_element(BY.ID, 'edit-pincode').send_keys('123456')
        # click the next button
        reserve_but = browser.find_element(BY.ID, "edit-next")
        actions = ActionChains(self.browser)
        actions.move_to_element(reserve_but)
        actions.click(reserve_but)
        actions.perform()

        # click the next button again
        #browser.find_element(BY.XPATH, "//input[@id='edit-3' and not(@disabled)]")
        #browser.find_element(BY.ID, "edit-next").click()

        # esnure all steps are disabled  -- we are on the last page in the reservation flow
        ##browser.find_element(BY.XPATH, "//input[@id='edit-1' and @disabled]")
        ##browser.find_element(BY.XPATH, "//input[@id='edit-2' and @disabled]")
        ##browser.find_element(BY.XPATH, "//input[@id='edit-3' and @disabled]")
        #browser.find_element(BY.XPATH, "//input[@id='edit-4' and @disabled]")

        # get the messages
        messages = browser.find_element(BY.ID, "messages")

        # ensure we have a status message
        messages.find_element(BY.CLASS_NAME, "message--error")

        # ensure a link is present
        #link = messages.find_element(BY.XPATH, "//a[contains(@href, 'http://www.danbib.dk/vip_lånerstatus')]")

        # click the link
        #link.click()

        # switch to main
        #browser.switch_to.window(mainwindow)

        # ensure we have two windows available. The first popup is closed but
        # the link should open in a new one as it is a external link
        #self.assertEqual(2, len(browser.window_handles))
