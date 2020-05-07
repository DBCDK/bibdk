from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.common.action_chains import ActionChains
import time

__author__ = 'hrmoller'

import helpers


class TestBibdkSubjectHierachy(helpers.BibdkUnitTestCase):

    def test_direct_links(self):

        # testing on default size (W:1024)
        browser = self.browser
        wait = WebDriverWait(browser, 30)
        self._goto_frontpage()
        self._check_pop_up()

        wait = WebDriverWait(browser, 30)
        agree = wait.until(
          expected_conditions.visibility_of_element_located((By.CLASS_NAME, "agree-button"))
        )
        agree.click()

        # ensure that the subject hierachy is present
        subject_hierarchy = wait.until(
            expected_conditions.visibility_of_element_located(
                (By.ID, "subjectshierarchy")
            )
        )

        # move to subject hierarchy - it might not be visible
        actions = ActionChains(browser)
        actions.move_to_element(subject_hierarchy)
        actions.perform()

        # click the 6th element in the subject hierachy
        subject_hierarchy.find_element_by_id("subject-hierarchy-note-link-0-6").click()

        subject_hierarchy.find_element_by_class_name("row-2")
        WebDriverWait(browser, 20).until(expected_conditions.presence_of_element_located((By.CLASS_NAME, "subjects-sublists")))

        # find wrapper on items list
        subject_hierarchy.find_element_by_class_name("subjects-sublist")

        # extract a direct link
        href = subject_hierarchy.find_element_by_link_text("Computere").get_attribute("href")

        # goto to the page
        browser.get(href)
        self._check_pop_up()
        subject_hierarchy = wait.until(
            expected_conditions.visibility_of_element_located(
                (By.ID, "bibdk-subject-hierarchy")
            )
        )
        subject_hierarchy.find_element_by_class_name("subjects-sublists")

        subject_hierarchy.find_element_by_id("subject-hierarchy-label-link-0-1").click()
        WebDriverWait(browser, 20).until(expected_conditions.presence_of_element_located((By.LINK_TEXT, "Sygdomme")))

        row_1 = subject_hierarchy.find_element_by_class_name("row-1")
        row_1.find_element_by_class_name("subjects-sublists")

        browser.find_element_by_id("subject-hierarchy-label-link-0-11").click()
        WebDriverWait(browser, 20).until(expected_conditions.presence_of_element_located((By.LINK_TEXT, "Erindringer og biografier")))

        row_3 = browser.find_element_by_class_name("row-1")
        row_3.find_element_by_class_name("subjects-sublist")

    def test_subject_hierachy_breadcrumb(self):
        """
        We test the subject hierachy breadcrumb and unsure the links are correct.
        related to bug #18024 - breadcrumblinks are broken
        """

        browser = self.browser
        browser.implicitly_wait(5)
        self._goto_frontpage()

        wait = WebDriverWait(browser, 30)
        agree = wait.until(
          expected_conditions.visibility_of_element_located((By.CLASS_NAME, "agree-button"))
        )
        agree.click()

        link_a = "bibdk_subject_hierarchy/nojs/4"
        link_b = "bibdk_subject_hierarchy/nojs/4%2C5"
        link_c = "bibdk_subject_hierarchy/nojs/4%2C5%2C0"
        link_d = "search_block_form=dk%20%3D%2035.57"

        # click the fifth item in the subjectbrowser
        # browser.find_element_by_id("subject-hierarchy-label-link-0-4").click()
        self._check_pop_up()
        link_element = browser.find_element_by_xpath("//a[contains(@href,'" + link_a + "')]")

        actions = ActionChains(browser)
        actions.move_to_element(link_element)
        actions.click(link_element)
        actions.perform()

        #browser.find_element_by_xpath("//a[contains(@href,'" + link_a + "')]").click()

        # wait for the subjects to be loaded by AJAX
        WebDriverWait(browser, 5).until(expected_conditions.visibility_of_element_located((By.XPATH, "//a[contains(@href,'" + link_b + "')]")))

        breadcrumb = browser.find_element_by_class_name("subjects-breadcrumb")

        # verify that the breadcrumb has one item only
        a_tags = breadcrumb.find_elements_by_tag_name("a")
        self.assertEqual(len(a_tags), 0, "No link is present in the breadcrumb")

        div_tag = breadcrumb.find_elements_by_tag_name("div")
        self.assertEqual(len(div_tag), 1, "End element is present in the breadcrumb")

        # click the fourth item in the newly opened subjectbrowser
        breadcrumb.find_element_by_xpath("//a[contains(@href,'" + link_b + "')]").click()

        # wait for the subjects to be loaded by AJAX
        WebDriverWait(browser, 5).until(expected_conditions.visibility_of_element_located((By.XPATH, "//a[contains(@href,'" + link_c + "')]")))

        breadcrumb = browser.find_element_by_class_name("subjects-breadcrumb")

        # verify that the breadcrumb has one item only
        a_tags = breadcrumb.find_elements_by_tag_name("a")
        self.assertEqual(len(a_tags), 1, "One link only is present in the breadcrumb")

        div_tag = breadcrumb.find_elements_by_tag_name("div")
        self.assertEqual(len(div_tag), 1, "End element is present in the breadcrumb")

        # verify that the first link we clicked is the first link in the breadcrumb
        index = a_tags[0].get_attribute("href").find(link_a)
        self.assertTrue(index is not -1, "Found link")

        # click the first item in the nwely opened subjectbrowser
        breadcrumb.find_element_by_xpath("//a[contains(@href,'" + link_c + "')]").click()

        # wait for the subjects to be loaded by AJAX
        WebDriverWait(browser, 5).until(expected_conditions.visibility_of_element_located((By.XPATH, "//a[contains(@href,'" + link_d + "')]")))

        breadcrumb = browser.find_element_by_class_name("subjects-breadcrumb")

        # verify that the breadcrumb has two item only
        a_tags = breadcrumb.find_elements_by_tag_name("a")
        self.assertEqual(len(a_tags), 2, "Two links only is present in the breadcrumb")

        div_tag = breadcrumb.find_elements_by_tag_name("div")
        self.assertEqual(len(div_tag), 1, "End element is present in the breadcrumb")

        # verify that the first link we clicked is the first link in the breadcrumb
        index = a_tags[0].get_attribute("href").find(link_a)
        self.assertTrue(index is not -1, "Found link")

        # verify that the second link we clicked is the second link in the breadcrumb
        index = a_tags[1].get_attribute("href").find(link_b)
        self.assertTrue(index is not -1, "Found link")

        # verify that when the first link in the subject browser is clicked we
        # will be taken to the right place
        a_tags[0].click()

        # wait for the subjects to be loaded by AJAX
        WebDriverWait(browser, 5).until(expected_conditions.visibility_of_element_located((By.XPATH, "//a[contains(@href,'bibdk_subject_hierarchy/nojs/4%2C7')]")))

        breadcrumb = browser.find_element_by_class_name("subjects-breadcrumb")

        # verify that the breadcrumb has one item only
        a_tags = breadcrumb.find_elements_by_tag_name("a")
        self.assertEqual(len(a_tags), 0, "No link is present in the breadcrumb")

        # verify heading
        heading = browser.find_element_by_class_name("subjects-sublists-heading")
        self.assertTrue(heading is not -1, "Found heading element")

        # self.assertTrue(div_tag.text equals heading.text, "heading element text equals breadcrumb text")
        div_tag = breadcrumb.find_element_by_class_name('container-last')
        assert div_tag.text in heading.text


    def test_subject_hierarchy_search(self):
        """
        Testing subject hierarchy search
        """
        browser = self.browser
        browser.implicitly_wait(5)
        browser.get(self.base_url)

        wait = WebDriverWait(browser, 30)
        agree = wait.until(
          expected_conditions.visibility_of_element_located((By.CLASS_NAME, "agree-button"))
        )
        agree.click()

        # ensure that the subject hierachy is present
        subject_hierachy_searchfield = browser.find_element_by_class_name("subject-hierarchy-searchfield")
        subject_hierachy_link_wrapper = subject_hierachy_searchfield.find_element_by_class_name("show-for-large-up")
        # move to subject hierarchy - it might not be visible
        actions = ActionChains(browser)
        actions.move_to_element(subject_hierachy_link_wrapper)
        actions.perform()

        # searchresult start hidden and empty
        subject_hierachy_searchresult = browser.find_element_by_id("bibdk-subject-hierarchy-searchresult")
        self.assertFalse(subject_hierachy_searchresult.is_displayed(), "subject hierachy search result block should not be visible")

        self._check_pop_up()

        subject_hierachy_link_wrapper.find_elements_by_tag_name("a")[0].click()
        WebDriverWait(browser, 5).until(expected_conditions.element_to_be_clickable((By.ID, "edit-search-hierarchy-submit")))

        subject_hierachy_input = browser.find_element_by_id("edit-search-hierarchy-input")
        self.assertTrue(subject_hierachy_input.is_displayed(), "subject hierachy search input field should be visible")

        subject_hierachy_submit = browser.find_element_by_id("edit-search-hierarchy-submit")
        self.assertTrue(subject_hierachy_submit.is_displayed(), "subject hierachy search submit button should be visible")

        subject_hierachy_input.send_keys("foo")

        subject_hierachy_submit.click()

        # wait for search result to be loaded by AJAX
        WebDriverWait(browser, 5).until(expected_conditions.visibility_of_element_located((By.ID, "bibdk-subject-hierarchy-searchresult")))

        hierarchy_searchresult = browser.find_element_by_id("bibdk-subject-hierarchy-searchresult")
        self.assertTrue(hierarchy_searchresult.is_displayed(), "subject hierachy search result should be visible")

        hierarchy_searchresult_header = hierarchy_searchresult.find_element_by_class_name("header")
        self.assertTrue(hierarchy_searchresult_header.is_displayed(), "hierarchy searchresult header should be visible")

        hierarchy_searchresult_subjects_breadcrumb = hierarchy_searchresult.find_element_by_class_name("subjects-breadcrumb")
        self.assertTrue(hierarchy_searchresult_subjects_breadcrumb.is_displayed(), "hierarchy searchresult breadcrumb should be visible")

        hierarchy_searchresult_item_list = hierarchy_searchresult.find_element_by_class_name("item-list")
        self.assertTrue(hierarchy_searchresult_item_list.is_displayed(), "hierarchy searchresult item list should be visible")


    '''
    PJO 19/05/19 outcommented - FIX IT

    def test_subject_hierarchy_responsive(self):
        """
        We test visiblity of subject hierarchy on small devices
        """
        browser = self.browser
        browser.implicitly_wait(30)
        browser.get(self.base_url)

        # ensure that the subject hierachy is present
        subject_hierachy = browser.find_element_by_id("subjectshierarchy")
        # move to subject hierarchy - it might not be visible
        actions = ActionChains(browser)
        actions.move_to_element(subject_hierachy)
        actions.perform()

        self._check_pop_up()

        # click the 6th element in the subject hierachy
        subject_hierachy.find_element_by_id("subject-hierarchy-note-link-0-6").click()
        WebDriverWait(browser, 30).until(expected_conditions.presence_of_element_located((By.CLASS_NAME, "subjects-sublists")))

        subject_hierachy.find_element_by_class_name("subject-item")
        subject_hierachy.find_element_by_class_name("subjects-sublist")

        searchfield = subject_hierachy.find_element_by_class_name("subject-hierarchy-searchfield")
        show_for_large_up = searchfield.find_element_by_class_name("show-for-large-up")
        self.assertTrue(show_for_large_up.is_displayed(), "searchfield.show-for-large-up should be visible")

        hide_for_large_up = searchfield.find_element_by_class_name("hide-for-large-up")
        self.assertFalse(hide_for_large_up.is_displayed(), "searchfield.hide-for-large-up should not be visible")

        # testing on medium size (W: 480 - 768)
        #browser.set_window_size(492, 768)
        browser.set_window_size(479, 768)
        # - needs fixing? No longer shows at width 481.

        time.sleep(10)
        visible = subject_hierachy.find_element_by_id("bibdk-subject-hierarchy")
        self.assertTrue(visible.is_displayed(), "bibdk-subject-hierarchy should be visible")

        subject_hierachy.find_element_by_class_name("subject-item")

        show_for_large_up = searchfield.find_element_by_class_name("show-for-large-up")
        self.assertFalse(show_for_large_up.is_displayed(), "searchfield.show-for-large-up should not be visible")

        hide_for_large_up = searchfield.find_element_by_class_name("hide-for-large-up")
        self.assertTrue(hide_for_large_up.is_displayed(), "searchfield.hide-for-large-up should be visible")

        # testing on small size (W: < 480)
        browser.set_window_size(479, 768)

        not_visible = subject_hierachy.find_element_by_id("bibdk-subject-hierarchy")
        self.assertFalse(not_visible.is_displayed(), "bibdk-subject-hierarchy should not be visible")
    '''
