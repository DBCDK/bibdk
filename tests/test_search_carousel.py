import helpers
from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions
from selenium.webdriver.support.wait import WebDriverWait


class TestSearchCarousel(helpers.BibdkUnitTestCase):

    def test_loading_of_elements(self):

        self.browser.get(self.base_url)

        self.assertTrue(self.browser.find_element_by_id('carousel'), 'carousel panel-pane is present.')

        self.assertTrue(self.browser.find_element_by_css_selector('.slick-carousel'), 'Slick carousel is present')

        self.assertTrue(self.browser.find_element_by_css_selector('.slick-carousel-header'), 'carousel header div is present.')

        self.assertTrue(self.browser.find_element_by_css_selector('.slick-carousel-inner'), 'carousel content div is present.')

        self.assertTrue(self.browser.find_element_by_css_selector('.slick-carousel-tabs'), 'carousel tab content div is present.')

        WebDriverWait(self.browser, 60).until(expected_conditions.presence_of_element_located((By.CSS_SELECTOR, '.carousel-item-image')))

        self.assertTrue(self.browser.find_element_by_css_selector('.carousel-item-image a img'), 'carousel items has image.')

        self.assertTrue(self.browser.find_element_by_css_selector('.carousel-item-title'), 'carousel items has title.')

        self.assertTrue(self.browser.find_element_by_css_selector('.carousel-item-creator'), 'carousel items has creator.')

        self.assertTrue(self.browser.find_element_by_css_selector('.slick-next'), 'carousel has "next" button.')

        self.assertTrue(self.browser.find_element_by_css_selector('.slick-prev'), 'carousel has "previous" button.')
