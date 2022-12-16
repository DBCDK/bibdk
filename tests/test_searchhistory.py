from selenium.webdriver.support import expected_conditions
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.common.by import By
import helpers
from selenium.webdriver.common.action_chains import ActionChains

class TestSearhhistory(helpers.BibdkUnitTestCase):

    def test_searchhistory(self):
        browser = self.browser
        browser.get(self.base_url)
        wait = WebDriverWait(browser, 30)
        # search jungersen + book
        self.browser.find_element(By.ID, "edit-search-block-form--2").send_keys('jungersen')
        # expand advanced search.
        expand = wait.until(
            expected_conditions.visibility_of_element_located(
                (By.ID, "selid_custom_search_expand")
            )
        )
        expand.click()
        # expand books subgroup.
        browser.set_window_size(1440, 1800)

        toggle_books = wait.until(
            expected_conditions.visibility_of_element_located(
                (By.CSS_SELECTOR, 'span[data-child="term.workType%3D%22literature%22"]')
            )
        )

        toggle_books.click()
        # select printed books, and submit search.
        browser.find_element(By.ID, 'edit-namaterialetype-termtypebog').click()
        browser.find_element(By.ID, "edit-submit").click()

        # search "huden jeg bor i" + spanish + movie
        browser.get(self.base_url)
        # show advanced search.
        toggle = wait.until(
            expected_conditions.visibility_of_element_located(
                (By.ID, "selid_custom_search_expand")
            )
        )
        toggle.click()
        wait.until(
            expected_conditions.visibility_of_element_located(
                (By.ID, "search-advanced-panel")
            )
        )
        # Material page select.
        browser.find_element(By.CSS_SELECTOR, 'select[name="select_material_type"] option[value="bibdk_frontpage/film"]').click()

        wait.until(
            expected_conditions.visibility_of_element_located(
                (By.CSS_SELECTOR, 'div[data-selenium-page-id="bibdk_frontpage/film"]')
            )
        )

        browser.find_element(By.NAME, 'term_title[titel]').send_keys('huden jeg bor i')

        select_spanish_films = wait.until(
            expected_conditions.visibility_of_element_located(
                (By.CSS_SELECTOR, 'input[name="term_nationality[%22spanske+film%22+]"]')
            )
        )

        actions = ActionChains(self.browser)
        actions.move_to_element(select_spanish_films)
        actions.click(select_spanish_films)
        actions.perform()

        select_online_access = wait.until(
            expected_conditions.visibility_of_element_located(
                (By.CSS_SELECTOR, 'input[name="n/amaterialetype[term.type%3D%22film%22+and+term.accessType%3D%22online%22]"]')
            )
        )

        actions = ActionChains(self.browser)
        actions.move_to_element(select_online_access)
        actions.click(select_online_access)
        actions.perform()


        browser.find_element(By.ID, "edit-submit").click()

        # search "du forsvinder"
        browser.get(self.base_url)
        self.browser.find_element(By.ID, "edit-search-block-form--2").send_keys('du forsvinder')
        browser.find_element(By.ID, "edit-submit").click()

        # Test search history elements exists
        browser.get(self.base_url + 'user/searchhistory')
        elements = browser.find_elements_by_class_name('searchhistory-searchstring')
        self.assertEqual(len(elements), 3)

        # test cql is present (Bug 17914)
        elements = browser.find_elements_by_class_name('searchhistory-cql')
        self.assertEqual(len(elements), 3)

        # test and combination
        elements = browser.find_elements_by_class_name('combine-select')
        elements[1].click()
        elements[3].click()
        browser.find_element(By.ID, 'edit-and-or-radios-and-').click()
        browser.find_element(By.ID, 'edit-combine').click()
        self.assertEqual(self.browser.find_element(By.ID, "edit-search-block-form--2").get_attribute('value'), '((((term.type="bog"))) and (jungersen)) and ((du and forsvinder))')
        #assert warning does not exist
        elementList = browser.find_elements_by_css_selector(".message--warning")
        self.assertTrue(len(elementList) == 0)

        # test or combination
        browser.get(self.base_url + 'user/searchhistory')
        elements = browser.find_elements_by_class_name('combine-select')
        elements[1].click()
        elements[3].click()
        browser.find_element(By.ID, 'edit-and-or-radios-or-').click()
        browser.find_element(By.ID, 'edit-combine').click()
        self.assertEqual(self.browser.find_element(By.ID, "edit-search-block-form--2").get_attribute('value'), '((((term.type="bog"))) and (jungersen)) or ((du and forsvinder))')
        #assert warning does not exist
        elementList = browser.find_elements_by_css_selector(".message--warning")
        self.assertTrue(len(elementList) == 0)

    # Test for bug 17975
    def test_combine_cql(self):
        browser = self.browser

        # search gamle hankat
        browser.get(self.base_url)
        search = self.browser.find_element(By.ID, "edit-search-block-form--2");
        search.clear();
        search.send_keys('gammel hankat')
        browser.find_element(By.ID, "edit-submit").click()

         # search kim larsen
        browser.get(self.base_url)
        search = self.browser.find_element(By.ID, "edit-search-block-form--2");
        search.clear();
        search.send_keys('kim larsen')
        browser.find_element(By.ID, "edit-submit").click()

        # test and combination
        browser.get(self.base_url + 'user/searchhistory')
        elements = browser.find_elements_by_class_name('combine-select')
        elements[1].click();
        elements[2].click();
        browser.find_element(By.ID, 'edit-and-or-radios-and-').click()
        browser.find_element(By.ID, 'edit-combine').click()
        self.assertEqual(self.browser.find_element(By.ID, "edit-search-block-form--2").get_attribute('value'), '((gammel and hankat)) and ((kim and larsen))')
        browser.find_element(By.XPATH, "//h2[text()='Gammel hankat']")

        #assert warning does not exist
        elementList = browser.find_elements_by_css_selector(".message--warning")
        self.assertTrue(len(elementList) == 0)
