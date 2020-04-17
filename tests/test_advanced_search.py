import helpers
from selenium.webdriver.support import expected_conditions
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.common.by import By
from selenium.webdriver.common.action_chains import ActionChains
import time

class TestAdvancedSearch(helpers.BibdkUnitTestCase):

    def test_columns_frontpage(self):
        browser = self.browser
        # Test that languages are in three columns on frontpage - cf. bug 17239
        browser.get(self.base_url)
        browser.find_element_by_id('selid_custom_search_expand').click()
        self.assertTrue(browser.find_element_by_css_selector('.sprog .column2'))
        self.assertTrue(browser.find_element_by_css_selector('.column2').find_element_by_name('n/asprog[term.language%3D%22som%22]'))

        # Same test in english
        browser.get(self.base_url + 'eng')
        browser.find_element_by_id('selid_custom_search_expand').click()
        self.assertTrue(browser.find_element_by_css_selector('.sprog .column2'))
        self.assertTrue(browser.find_element_by_css_selector('.column2').find_element_by_name('n/asprog[term.language%3D%22som%22]'))


    def test_load_search_pages(self):
        browser = self.browser
        browser.get(self.base_url)
        # show advanced search.
        toggle = WebDriverWait(browser, 30).until(
            expected_conditions.visibility_of_element_located(
                (By.ID, "selid_custom_search_expand")
            )
        )
        toggle.click()
        WebDriverWait(browser, 30).until(
            expected_conditions.visibility_of_element_located(
                (By.ID, "search-advanced-panel")
            )
        )
        # Check for book search options.
        browser.find_element_by_css_selector('select[name="select_material_type"] option[value="bibdk_frontpage/bog"]').click()
        WebDriverWait(browser, 30).until(
            expected_conditions.visibility_of_element_located(
                (By.CSS_SELECTOR, 'div[data-selenium-page-id="bibdk_frontpage/bog"]')
            )
        )


    def test_strict_cql(self):
        browser = self.browser
        browser.set_window_size(1440, 1800)
        # url: master chief
        #url = self.base_url + 'search/work/master chief'
        url = self.base_url + 'search/work/51450515'
        browser.get(url)
        self.assertTrue(browser.find_element_by_id('870970basis51450515'))

        #id_to_verify = '870970basis27143474'
        #id_to_verify = '870970basis51010132'
        #id_to_verify = '820010katalog3744833'
        #id_to_verify = '870970basis29818967'
        #id_to_verify = '870970basis44111543'
        #id_to_verify =  '870970basis28014260'
        id_to_verify =  'selid-870970basis28014260'

        # url: term.workType=movie and term.accessType=online
        url = self.base_url + 'search/work/ti="de vilde hjerter" and term.workType=movie and term.accessType=online'
        browser.get(url)

        time.sleep(10)
        self.assertTrue(browser.find_element_by_id(id_to_verify))

        url = self.base_url + 'search/work/term.workType="movie" and term.accessType="online" and mango'
        browser.get(url)
        time.sleep(10)

        id_to_verify =  'selid-870970basis52312205'
        id_to_verify =  'selid-150052ekurser460'
        self.assertTrue(browser.find_element_by_id(id_to_verify))

        # searchpages: Online movies in spanish
        browser.get(self.base_url + '/bibdk_frontpage/film')
        # expand search options
        toggle = WebDriverWait(browser, 30).until(
            expected_conditions.visibility_of_element_located(
                (By.ID, "selid_custom_search_expand")
            )
        )
        toggle.click()

        browser.find_element_by_name('n/amaterialetype[term.type%3D%22film%22+and+term.accessType%3D%22online%22]').click()
        browser.find_element_by_name('term_title[titel]').send_keys('huden jeg bor i')
        browser.find_element_by_id("edit-submit").click()
        self.assertTrue(browser.find_element_by_id('selid-870970basis29829934'))
        browser.get(self.base_url)
        browser.find_element_by_id('selid_custom_search_expand').click()
        WebDriverWait(browser, 30).until(expected_conditions.presence_of_element_located((By.NAME, "term_title[titel]")))

        browser.find_element_by_name('term_title[titel]').send_keys('"huden jeg bor i" not dansk')
        browser.find_element_by_id("edit-submit").click()
        self.assertTrue(browser.find_element_by_id('selid-870970basis28973047'))

        # google-field: r'n'b
        browser.get(self.base_url)
        browser.find_element_by_name('search_block_form').send_keys("r'n'b")
        browser.find_element_by_id("edit-submit").click()

        self.assertTrue(browser.find_element_by_id('870971tsart34869790'))

        # google-field: term.workType="movie" and term.accessType="online"
        browser.get(self.base_url)
        browser.find_element_by_name('search_block_form').send_keys('term.workType="movie" and term.accessType="online" and Kaos')
        browser.find_element_by_id("edit-submit").click()
        id_to_verify ='870970basis52873479'
        self.assertTrue(browser.find_element_by_id(id_to_verify))

    # test for BUG 17887
    def test_advanced_subgroups(self):
        browser = self.browser
        browser.get(self.base_url)
        browser.set_window_size(1024, 768)
        self._check_pop_up()

        browser.find_element_by_id('selid_custom_search_expand').click()
        browser.find_element_by_css_selector('span[data-child="term.workType%3D%22literature%22"]').click()
        browser.find_element_by_id('edit-namaterialetype-termtypebog').click()
        browser.find_element_by_id("edit-submit").click()
        self.assertTrue(browser.find_element_by_id('edit-namaterialetype-termtypebog'))
        self.assertTrue(browser.find_element_by_id('edit-namaterialetype-termtypebog').is_selected())

    # tests for #1030
    def test_no_search_results(self):
        browser = self.browser
        browser.get(self.base_url)

        # test search gives result
        browser.find_element_by_name('search_block_form').send_keys("good search")
        browser.find_element_by_id("edit-submit").click()
        self.assertTrue(browser.find_element_by_class_name('ting-openformat-search-amount-block'))
        self.assertTrue(browser.find_element_by_class_name('pane-bibdk-facetbrowser'))
        self.assertTrue(browser.find_element_by_class_name('works-control'))
        self.assertTrue(browser.find_element_by_class_name('search-results'))

        # test search gives NO result

        browser.find_element_by_name('search_block_form').clear()
        browser.find_element_by_name('search_block_form').send_keys("nogoodsearch")
        browser.find_element_by_id("edit-submit").click()
        self.assertTrue(len(browser.find_elements_by_class_name('ting-openformat-search-amount-block')) == 0)
        self.assertTrue(len(browser.find_elements_by_class_name('pane-bibdk-facetbrowser')) == 0)
        self.assertTrue(len(browser.find_elements_by_class_name('works-control')) == 0)
        self.assertTrue(len(browser.find_elements_by_class_name('search-results')) == 0)
        self.assertTrue(len(browser.find_elements_by_class_name('message--warning')) == 1)

        # test invalid cql search gives NO result
        browser.find_element_by_name('search_block_form').clear()
        browser.find_element_by_name('search_block_form').send_keys("(nogoodsearch and)")
        browser.find_element_by_id("edit-submit").click()
        time.sleep(1)
        self.assertTrue(len(browser.find_elements_by_class_name('ting-openformat-search-amount-block')) == 0)
        self.assertTrue(len(browser.find_elements_by_class_name('pane-bibdk-facetbrowser')) == 0)
        self.assertTrue(len(browser.find_elements_by_class_name('works-control')) == 0)
        self.assertTrue(len(browser.find_elements_by_class_name('search-results')) == 0)
        self.assertTrue(len(browser.find_elements_by_class_name('message--warning')) == 1)
        self.assertTrue(len(browser.find_elements_by_class_name('message--error')) != 0)

    # tests for BUG #18354
    def test_open_manifestation(self):
        browser = self.browser
        wait = WebDriverWait(browser, 30)

        # search
        browser.get(self.base_url + '/bibdk_frontpage/bog')
        search_block_form = wait.until(
          expected_conditions.visibility_of_element_located((By.NAME, "search_block_form"))
        )
        search_block_form.send_keys("jungersen undtagelsen")
        browser.find_element_by_id("edit-submit").click()

        # Click on result
        work = wait.until(
          expected_conditions.visibility_of_element_located((By.ID, "selid-870970basis25419766"))
        )
        work.click()

        # Show manifestation for lydbog cd
        lydbog = wait.until(
          expected_conditions.visibility_of_element_located((By.ID, "manifestation-toggle-button-Lydbog-cd-870970-basis54708513"))
        )
        lydbog.click()

        # Temporarily closed becaused ordering is closed
        #order_button = wait.until(
        #  expected_conditions.visibility_of_element_located((By.ID, "this_edition_870970-basis:25109066"))
        #)
