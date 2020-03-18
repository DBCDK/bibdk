from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions
from selenium.webdriver.support.wait import WebDriverWait
import helpers

class TestAdvancedSearchButtonToggle(helpers.BibdkUnitTestCase):
    def test_advanced_search_button_unfold(self):
        self._goto_frontpage()
        button = self.browser.find_element_by_id('selid_custom_search_expand')
        text_element1 = button.find_elements_by_css_selector('span[class="toggle-text"]')
        button.click()
        text_element2 = button.find_elements_by_css_selector('span[class="toggle-text"]')
        self.assertNotEqual(text_element1, text_element2)


    def test_advanced_search_button_collapse(self):
        browser = self.browser
        self._goto_frontpage()

        button = browser.find_element_by_id('selid_custom_search_expand')
        text_element1 = browser.find_element_by_id('selid_custom_search_expand').text
        button.click()
        button.click()
        text_element2 = browser.find_element_by_id('selid_custom_search_expand').text
        self.assertEqual(text_element1, text_element2)

    def test_advanced_search_panel_loaded_by_ajax(self):
        browser = self.browser
        browser.implicitly_wait(10)
        browser.get(self.base_url)

        WebDriverWait(browser, 10).until(expected_conditions.presence_of_element_located((By.CLASS_NAME, "forfatter")))
        browser.find_element_by_id("search-advanced-panel").find_element_by_class_name("forfatter")

    def test_advanced_search_panel_loaded_by_ajax_on_search_result(self):
        browser = self.browser
        browser.implicitly_wait(10)
        browser.get(self.base_url)
        browser.find_element_by_id("edit-search-block-form--2").send_keys("flodhest")
        browser.find_element_by_id("edit-submit").click()

        WebDriverWait(browser, 10).until(expected_conditions.presence_of_element_located((By.CLASS_NAME, "forfatter")))
        browser.find_element_by_id("search-advanced-panel").find_element_by_class_name("forfatter")

    def test_material_dropdown_overrides_pagetype(self):
        browser = self.browser
        browser.implicitly_wait(10)

        # This test should ensure that material selector dropdown overrides the
        # search page we're on
        # First we go to searchpage: books and then we resizes the browser to
        # hide the search page navigation bar and show the material selector.
        # Then a saerch is executed with a material type other than books.
        browser.get(self.base_url + "bibdk_frontpage/bog")

        browser.set_window_size(480, 768)

        self.assertTrue(
            browser.find_element_by_name("select_material_type").is_displayed(),
            "element with name 'select_material_type' is hidden - it should be visible"
        )

        selector = browser.find_element_by_name("select_material_type")

        # select the 'musik' option
        option = browser.find_element_by_css_selector('select[name="select_material_type"] option[value="bibdk_frontpage/musik"]')
        option.click()

        browser.find_element_by_id("edit-search-block-form--2").send_keys("peter belli")
        browser.find_element_by_id("edit-submit").click()

        selector = browser.find_element_by_name("select_material_type")
        # select the 'musik' option
        for option in selector.find_elements_by_tag_name("option"):
            if option.get_attribute("selected"):
                self.assertEqual(option.get_attribute("value"), "bibdk_frontpage/musik", "value in dropdown wasn't set correctly")
                break

        browser.set_window_size(1024, 768)

        select_material_type = WebDriverWait(browser, 30).until(
            expected_conditions.visibility_of_element_located(
                (By.CSS_SELECTOR, 'select[name="select_material_type"] option[value="bibdk_frontpage/musik"]')
            )
        )
        self.assertEqual(
            select_material_type.get_attribute("selected"),
            "true",
            "The music tab should be active now. Apparently it isn't"
        )
