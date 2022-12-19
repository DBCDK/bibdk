import helpers
import time
from selenium.webdriver.common.by import By

class TestTopbarResponiveness(helpers.BibdkUnitTestCase):
    def test_topbar_large(self):
        """
        Testing vivsiblity of links in topbar on large devices
        """
        browser = self.browser
        browser.get(self.base_url)
        browser.implicitly_wait(10)

        # testing on default size (W:1024)
        topbar = browser.find_element(By.CLASS_NAME, "topbar")

        helpdesk = topbar.find_element(By.CSS_SELECTOR, "[data-rel='helpdesk']")
        self.assertTrue(helpdesk.is_displayed(), "helpdesk is displayed in topbar")

        login = topbar.find_element(By.XPATH, "//a[contains(@href, 'login')]")
        self.assertTrue(login.is_displayed(), "loginis displayed in topbar")

        browser.find_element(By.CLASS_NAME, "right-off-canvas-toggle").click()
        offcanvas_menu = browser.find_element(By.CLASS_NAME, "off-canvas-list")
        helpdesk_link = offcanvas_menu.find_element(By.CLASS_NAME, "hide-for-large-only")
        self.assertFalse(helpdesk_link.is_displayed(), "helpdesk is visible in menu on small screens")

        # testing ask_vopos link is present with agency_id and agency_mail
        askvopos_id = topbar.find_element(By.XPATH, "//a[contains(@href, 'adm.biblioteksvagten')]")


    def test_topbar_small(self):
        """
        Testing vivsiblity of links in topbar on small devices
        """
        browser = self.browser
        # testing on small size (W:480)
        browser.set_window_size(480, 768)
        browser.get(self.base_url)

        topbar = browser.find_element(By.CLASS_NAME, "topbar")

        helpdesk = topbar.find_element(By.CSS_SELECTOR, "[data-rel='helpdesk']")
        #helpdesk = topbar.find_element(By.XPATH, "//a[contains(@href, 'overlay/helpdesk')]")
        self.assertTrue("visible-for-large-up" in helpdesk.get_attribute('class').split(' '), "helpdesk is visible on large devices and up")

        hest = topbar.find_element(By.CLASS_NAME, "visible-for-large-up")

        browser.find_element(By.CLASS_NAME, "right-off-canvas-toggle").click()
        offcanvas_menu = browser.find_element(By.CLASS_NAME, "off-canvas-list")
        helpdesk_link = offcanvas_menu.find_element(By.CLASS_NAME, "hide-for-large-only")
        self.assertTrue(helpdesk_link.is_displayed(), "helpdesk is visible in menu on small screens")
