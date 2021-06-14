from selenium.webdriver.common.by import By
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions
import helpers


class TestSBKopi(helpers.BibdkUnitTestCase):
    def test_bestil_gratis_e_kopi_link(self):
        browser = self.browser
        single_work_pid = "work/870971-tsart:34276501"
        browser.get(self.base_url + single_work_pid)

        browser.find_element_by_id("870971-tsart34276501")

    def test_bestil_kopi_on_single_work(self):
        browser = self.browser
        single_work_pid = "work/870971-tsart:35977937"
        browser.get(self.base_url + single_work_pid)
        manifestation = browser.find_element_by_id("870971-tsart35977937")
        WebDriverWait(manifestation, 20).until(expected_conditions.visibility_of_element_located((By.XPATH, "//a[contains(@href,'reservation/sbkopi/870971-tsart%3A35977937')]")))

    def test_sbkopi_popup_window(self):
        browser = self.browser
        browser.get(self.base_url + 'search/work/870971-tsart:35977937')
        self._check_popup()
        self.browser.find_element_by_id('selid-870971tsart35977937').click()
        browser.implicitly_wait(20)
        browser.find_element_by_xpath("//a[contains(@href,'reservation/sbkopi/870971-tsart%3A35977937')]").click()
        # wait for the PopUpWindow to visible
        WebDriverWait(browser, 20).until(self.found_window('PopUpWindowreservation'))
        # ensure we have two windows available
        self.assertEqual(2, len(browser.window_handles))
