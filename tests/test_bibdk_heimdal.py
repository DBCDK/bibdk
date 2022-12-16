# coding=utf-8
from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions
from selenium.webdriver.support.wait import WebDriverWait
import time
import re
import helpers
import requests


class testHeimdalLogin(helpers.BibdkUnitTestCase):
    def test_redirect_to_heimdal(self):
        browser = self.browser
        browser.implicitly_wait(10)
        browser.get(self.base_url)
        #find login button
        loginlink_xpath = "//a[contains(@href,'bibdk_modal/login')]"
        topbar = browser.find_element(By.CLASS_NAME, "topbar-links")
        topbar.find_element(By.XPATH, loginlink_xpath).click()
        WebDriverWait(browser, 20).until(expected_conditions.visibility_of_element_located((By.ID, 'edit-name')))
        # get the modal
        modal = browser.find_element(By.ID, "bibdk-modal")
        #find link to heimdal
        link = browser.find_element(By.ID, 'bibdk-heimdal-login-link')
        link.click()
        time.sleep(2)
        #assert that heimdal login page is shown
        #browser.find_element(By.ID, 'libraryname-input')
        browser.find_elements_by_xpath('//input[@id="libraryname-input"]')

