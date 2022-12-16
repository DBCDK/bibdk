from selenium.webdriver.common.by import By
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions
import helpers


class BibdkHoldingsTestCase(helpers.BibdkUnitTestCase):
    def test_holdnings_manifestation_link(self):
        """
        Verify the holdingslink on manifestation level is actually shown
        """
        browser = self.browser
        browser.implicitly_wait(10)
        browser.get(self.base_url)

        user = self.getUser()
        self.assertTrue(user.login())

        browser.get(self.base_url + "search/work/rec.id=870970-basis%3A51229312")
        browser.find_element(By.ID, "selid-870970basis51229312").click()

        bibdk_holdings_favourites_link = browser.find_element(By.CLASS_NAME, "bibdk-holdings-favourites")
        WebDriverWait(bibdk_holdings_favourites_link, 30).until(expected_conditions.invisibility_of_element_located((By.CLASS_NAME, "throbber")))

        bibdk_holdings_favourites_link.find_element(By.CLASS_NAME, "icon-left")
