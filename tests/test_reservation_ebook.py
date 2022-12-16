# coding=utf-8
from selenium.webdriver.common.by import By
from selenium.webdriver.support.select import Select
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions
import helpers
import time

# This tests the reservation flow for ebook with multi-volume and sb copy link

class TestReservation(helpers.BibdkUnitTestCase):

    ##
    # Verifies that the multi volume ebook is shown a link when an
    # order is made.
    #
    ##
    def test_multi_volume_order_link_test(self):
        browser = self.browser
        browser.implicitly_wait(5)
        self._new_test()

        # store the mainwindow
        mainwindow = browser.current_window_handle

        # ensure we have only one window available
        self.assertEqual(1, len(browser.window_handles))

        # E.bog - Kaptajn Dinesen
        pid = "874310-katalog:DBB0701046"

        # do a search
        self._goto("search/work/rec.id=" + pid)
        order_btn = WebDriverWait(browser, 20).until(expected_conditions.presence_of_element_located((By.ID, "any_edition_but_874310katalogdbb0701046")))

        # click the order button
        order_btn.click()

        parent_handle = browser.current_window_handle
        # click the order link
        browser.find_element(By.ID, "any_edtion_order_874310katalogdbb0701046").click()
        handles = browser.window_handles
        browser.switch_to_window(handles[1])

        pop = browser.find_element(By.ID, 'popup')
        wait = WebDriverWait(browser, 5)
        link = wait.until((expected_conditions.presence_of_element_located((By.XPATH, "//span[@class='openformat-field']/a"))))

        href = link.get_attribute("href")
        found = False
        if "nota.dk" in href:
            found = True
        self.assertTrue(found, 'link to nota found')

    ##
    # Verifies that the sb copy link is shown a link when an
    # order is made.
    #
    ##
    '''
    pjo 26-11-19 disabled while sbcopy is closed
    def test_sb_order_link_test(self):
        browser = self.browser
        browser.implicitly_wait(20)
        self._new_test()

        # store the mainwindow
        mainwindow = browser.current_window_handle

        # ensure we have only one window available
        self.assertEqual(1, len(browser.window_handles))

        pid = "870971-tsart:34276501"

        # do a search
        self._goto("search/work/rec.id=" + pid)
        order_btn = WebDriverWait(browser, 20).until(expected_conditions.presence_of_element_located((By.ID, "any_edition_but_870971tsart34276501")))

        # click the order button
        order_btn.click()

        # click the order link
        browser.find_element(By.ID, "any_edtion_order_870971tsart34276501").click()

        # wait for the PopUpWindow to visible
        WebDriverWait(browser, 20).until(self.found_window('PopUpWindowreservation'))

        # ensure we have two windows available
        self.assertEqual(2, len(browser.window_handles))

        # wait for the selector and select it when it's available
        browser.implicitly_wait(20)

        link = browser.find_element(By.CLASS_NAME, "link-sbkopi")
        # Get linktext
        # linktext = browser.find_element_by_link_text('sb_order_copy')
    '''



