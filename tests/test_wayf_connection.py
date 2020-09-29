from selenium.webdriver.common.by import By
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import helpers
import time


class TestWayfConnection(helpers.BibdkUnitTestCase):
  def test_connection(self):
    browser = self.browser
    browser.get(self.base_url)
    self._check_pop_up()
    log_in_but = browser.find_element_by_xpath("//a[@href='/da/bibdk_modal/login']")
    log_in_but.click()
    wait = WebDriverWait(browser,10)
    wait.until(EC.presence_of_element_located((By.XPATH, "//a[contains(@href,'/da/wayf/login')]")))
    wayf_but =  browser.find_element_by_xpath("//a[contains(@href,'/da/wayf/login')]")
    wayf_but.click()
    time.sleep(2)
    current_url = browser.current_url
    self.assertTrue('wayf.wayf.dk' in current_url)
