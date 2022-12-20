from selenium.webdriver.support import expected_conditions
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.common.by import By
import helpers
import time

class TestMultipleCreators(helpers.BibdkUnitTestCase):
    '''Test edit-dkcclterm-fo-musik-alle-ophav1 and edit-dkcclterm-fo-musik-alle-ophav1 contains correct informations after search'''

    def test_music_page(self):
        browser = self.browser
        browser.get(self.base_url + '/bibdk_frontpage/musik')
        # show advanced search.
        toggle = WebDriverWait(browser, 30).until(
            expected_conditions.visibility_of_element_located(
                (By.ID, "selid_custom_search_expand")
            )
        )
        #toggle.click()
        WebDriverWait(browser, 30).until(
            expected_conditions.visibility_of_element_located(
                (By.ID, "search-advanced-panel")
            )
        )
        #ophav1 = 'form-item-dkcclterm-fo-musik,-alle-ophav1'
        ophav1 = 'input-medvirkende--2'
        #ophav2 = 'form-item-dkcclterm-fo-musik,-alle-ophav2'
        ophav2 = 'input-medvirkende-3'
        creator1 = 'nash'
        creator2 = 'crosby'
        browser.find_element(By.ID, ophav1).send_keys(creator1)
        browser.find_element(By.ID, ophav2).send_keys(creator2)
        browser.find_element(By.ID, 'edit-submit').click()
        creator1_result = browser.find_element(By.ID, ophav1).get_attribute('value')
        creator2_result = browser.find_element(By.ID, ophav2).get_attribute('value')
        self.assertEqual(creator1, creator1_result)
        self.assertEqual(creator2, creator2_result)
