from selenium.webdriver.common.by import By
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions
import helpers
import re
import time

class TestJavascriptFocus(helpers.BibdkUnitTestCase):
    """Test focus is placed correctly by javascript"""

    def test_front_page(self):
        browser = self.browser
        element_id = 'subject-hierarchy-label-link-0-0'
        search_input = r'^edit-search-block-form(--[0-9]+)?'
        browser.get(self.base_url)
        focus_element = browser.switch_to.active_element.get_attribute('id')
        self.assertTrue(re.match(search_input, focus_element) is not None,
        'Main input search field has focus.')

        self._check_pop_up()
        subject_element = browser.find_element_by_id(element_id)
        subject_element.click()
        WebDriverWait(browser, 15).until(expected_conditions.presence_of_element_located((By.CLASS_NAME, 'subjects-sublist-wrapper')))

        time.sleep(1)
        active_element =  browser.switch_to.active_element
        focus_element = active_element.get_attribute('id')
        self.assertEqual(focus_element, element_id, 'Focus is on clicked element: ' + element_id + ' ' + focus_element)

    #def test_helpdesk(self):
    #    browser = self.browser
    #    question_input = 'edit-questioncontent'
    #    browser.get(self.base_url + 'overlay/helpdesk')
    #    focus_element = browser.switch_to.active_element.get_attribute('id')
    #    self.assertEqual(focus_element, question_input, 'Focus is on input field for question.')

    # outcomment for now
    '''
    PJO 19/05/19 outcommented - FIX IT
    def test_user_login(self):
        browser = self.browser
        browser.implicitly_wait(10)
        browser.get(self.base_url)

        # ensure that we can see a login link
        WebDriverWait(browser, 20).until(expected_conditions.presence_of_element_located((By.XPATH, "//a[contains(@href,'bibdk_modal/login')]")))
        login_link = browser.find_element_by_xpath("//a[contains(@href,'bibdk_modal/login')]")

        # click the login link
        login_link.click()
        user_input = 'edit-name'
        WebDriverWait(browser, 20).until(expected_conditions.presence_of_element_located((By.ID, user_input)))
        focus_element = browser.switch_to.active_element.get_attribute('id')
        self.assertEqual(focus_element, user_input, 'Focus is on input field for username.')
    '''    

    def test_user_register_form(self):
        browser = self.browser
        browser.implicitly_wait(10)
        email_input = 'edit-mail'
        browser.get(self.base_url + 'user/register')
        focus_element = browser.switch_to.active_element.get_attribute('id')
        self.assertEqual(focus_element, email_input, 'Focus is on input field for email.')

    def test_help_popup(self):
        browser = self.browser
        help_input = 'edit-search-help'
        browser.get(self.base_url + 'overlay/help')
        focus_element = browser.switch_to.active_element.get_attribute('id')
        self.assertEqual(focus_element, help_input, 'Focus is on input field for searching help.')
