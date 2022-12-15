from selenium.webdriver.common.by import By
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.action_chains import ActionChains
import helpers


class TestAltTexts(helpers.BibdkUnitTestCase):
  def test_bibdk_article_img_alt(self):
    browser = self.browser
    browser.get(self.base_url)
    self._check_pop_up()
    img = browser.find_element(BY.XPATH, "//div[contains(@class,'views-field-field-image')]//img")
    alt = img.get_attribute('alt')
    self.assertTrue(len(alt)>1, "alt text found on article image")

  def test_carousel_img_alt(self):
    browser = self.browser
    browser.get(self.base_url)
    self._check_pop_up()
    img = browser.find_element(BY.XPATH, "//div[contains(@class,'carousel-item-image')]//img")
    alt = img.get_attribute('alt')
    self.assertTrue(len(alt)>1, "alt text found on carousel image")



