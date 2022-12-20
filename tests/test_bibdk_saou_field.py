import helpers
import time
from selenium.common.exceptions import NoSuchElementException


class TestSaouField(helpers.BibdkUnitTestCase):
    # Use against scepticism
    pid1 = "150008-academic:ebr10655298"

    # Gorilla gorilla film(net)
    pid2 = "870970-basis:28124635"


    #bibdk_saou_walkin_access - access ok

    '''
    OUTCOMMENT FOLLOWING TWO TESTS while waiting for a new pid to test on: 150008-academic:ebr10655298 is GONE
    def test_saou_walkin_access(self):
        browser = self.browser
        browser.implicitly_wait(10)
        self.login("saou_test.bibdk@guesstimate.dbc.dk", "content")
        # gentofte
        bibno = '715700'
        self._set_favourite_library(bibno)
        path = self.base_url + "search/work/rec.id=" + self.pid2
        browser.get(path)
        text = "checkAccess Gentofte Bibliotekerne "
        browser.find_element(By.XPATH, "//div[contains(.,'"+text+"')]")

    #bibdk_saou_click_here_for_access



    def test_logged_in_with_permission(self):
        browser = self.browser
        browser.implicitly_wait(10)
        self.login("saou_test.bibdk@guesstimate.dbc.dk", "content")
        # gentofte
        bibno = '715700'
        self._set_favourite_library(bibno)
        path = self.base_url + "search/work/rec.id=" + self.pid1
        browser.get(path)
        text = "checkAccess Gentofte Bibliotekerne "
        browser.find_element(By.XPATH, "//div[contains(.,'"+text+"')]")


    #saou_log_in_to_accesss_ressource

    def test_not_logged_in(self):
        browser = self.browser
        browser.implicitly_wait(10)
        path = self.base_url + "search/work/rec.id=" + self.pid1
        browser.get(path)
        element = browser.find_element(By.ID, "selid-150008academicebr10655298")
        element.click()
        text = "saou_log_in_to_accesss_ressource"
        browser.find_element(By.XPATH, "//div[contains(.,'"+text+"')]")
    '''

    def _pid_to_id(self, pid):
        string = pid.replace(':', '_')
        returnstring = string.replace('-', '_')
        return returnstring

    def text_is_present(self, element, text):
        try:
            self.browser.find_element(By.XPATH, "//div[contains(.,'"+text+"')]")
        except NoSuchElementException:
                return False

        return True

    def _set_favourite_library(self, bibno):
        browser = self.browser
        browser.implicitly_wait(10)
        url = self.base_url + "user"
        browser.get(url)
        # @TODO id is selid-mypage-favorites. Fix when changes are merged
        browser.find_element(By.CLASS_NAME, "right-off-canvas-toggle").click()
        browser.find_element(By.XPATH, "//a[contains(@href,'bibdk_favourite_list')]").click()
        # click 'set order library
        selector = "//a[contains(@href,'/favourite/add/" + bibno + "')]"
        browser.find_element(By.XPATH, selector).click()


if __name__ == '__main__':
    unittest.main()
