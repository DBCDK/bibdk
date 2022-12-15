from selenium.webdriver.common.by import By
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions
from selenium.common.exceptions import WebDriverException
from selenium.webdriver.common.action_chains import ActionChains

import helpers
import time

class TestCovers(helpers.BibdkUnitTestCase):
    '''
    def test_work_cover_plus_back_cover(self):

        # Search for work without back cover (Carter: Bodlen) rec.id=870970-basis:28917074
        self.browser.get(self.base_url)

        self.search_pid('870970-basis:28917074')
        self.assertTrue(self.browser.find_element(BY.ID, 'selid-870970basis28917074'))

        # Expand article view - wait for result
        self.browser.find_element(BY.ID, 'selid-870970basis28917074').click()
        WebDriverWait(self.browser, 10).until(expected_conditions.presence_of_element_located((By.ID, "870970-basis28917074")))

        # Assert cover field is present
        self.assertTrue(self.browser.find_element(BY.CSS_SELECTOR, '.field-name-bibdk-cover-work'))

        # Assert Foundation reveal cover image is present, but hidden
        self.assertTrue(self.browser.find_element(BY.CSS_SELECTOR, '#reveal-cover-large-0sfhfxx'), 'Foundation reveal cover image is present')
        self.assertFalse(self.browser.find_element(BY.CSS_SELECTOR, '#reveal-cover-large-0sfhfxx').is_displayed(), 'Foundation reveal cover image is hidden')

        # Assert Foundation reveal back cover image is present, but hidden
        self.assertTrue(self.browser.find_element(BY.CSS_SELECTOR, '#reveal-cover-back-0sfhfxx'), 'Foundation reveal back cover image is present')
        self.assertFalse(self.browser.find_element(BY.CSS_SELECTOR, '#reveal-cover-back-0sfhfxx').is_displayed(), 'Foundation reveal back cover image is hidden')

        # If files are not cached, they are fetched by AJAX
        WebDriverWait(self.browser, 10).until(expected_conditions.presence_of_element_located((By.CSS_SELECTOR, '#work-cover-0sfhfxx')))

        # Assert image is present
        self.assertTrue(self.browser.find_element(BY.CSS_SELECTOR, '.bibdk-cover-work-object-id-28917074'), 'Found div with class ".bibdk-cover-work-object-id-28917074"')

        WebDriverWait(self.browser, 10).until(expected_conditions.presence_of_element_located((By.CSS_SELECTOR, '.bibdk-cover-work-object-id-28917074 img')))
        self.assertTrue(self.browser.find_element(BY.CSS_SELECTOR, '.bibdk-cover-work-object-id-28917074 img'), 'Found image in "div.bibdk-cover-work-object-id-28917074"')

        # Assert link to Foundation reveal cover image is present
        WebDriverWait(self.browser, 10).until(expected_conditions.visibility_of_element_located((By.CSS_SELECTOR, 'a[data-reveal-id="reveal-cover-large-0sfhfxx"]')))
        self.assertTrue(self.browser.find_element(BY.CSS_SELECTOR, 'a[data-reveal-id="reveal-cover-large-0sfhfxx"]').is_displayed(), 'Link to Foundation reveal cover image is visible')

        # Assert link to Foundation reveal cover image is present
        WebDriverWait(self.browser, 10).until(expected_conditions.visibility_of_element_located((By.CSS_SELECTOR, 'a[data-reveal-id="reveal-cover-back-0sfhfxx"]')))
        self.assertTrue(self.browser.find_element(BY.CSS_SELECTOR, 'a[data-reveal-id="reveal-cover-back-0sfhfxx"]').is_displayed(), 'Link to Foundation reveal back cover image is visible')

        # Assert Foundation reveal cover image is populated
        self.assertTrue(self.browser.find_element(BY.CSS_SELECTOR, '#reveal-cover-large-0sfhfxx img'))

        # Assert Foundation reveal back cover image is populated
        self.assertTrue(self.browser.find_element(BY.CSS_SELECTOR, '#reveal-cover-back-0sfhfxx object'))

        # show cover in modal window
        self.browser.find_element(BY.CSS_SELECTOR, 'a[data-reveal-id="reveal-cover-large-0sfhfxx"]').click()

        WebDriverWait(self.browser, 10).until(expected_conditions.visibility_of_element_located((By.CSS_SELECTOR, '#reveal-cover-large-0sfhfxx')))
        modal = self.browser.find_element(BY.CSS_SELECTOR, '#reveal-cover-large-0sfhfxx img')
        self.assertTrue(modal.is_displayed(), 'Cover is displayed in a Foundation reveal')

        close = modal.find_element(BY.XPATH, "//a[@class='close-reveal-modal']//*[local-name()='svg']")

        actions = ActionChains(self.browser)
        actions.move_to_element(close)
        actions.click(close)
        actions.perform()

        time.sleep(1)

        # show back cover in modal window
        self.browser.find_element(BY.CSS_SELECTOR, 'a[data-reveal-id="reveal-cover-back-0sfhfxx"]').click()

        WebDriverWait(self.browser, 10).until(expected_conditions.visibility_of_element_located((By.CSS_SELECTOR, '#reveal-cover-back-0sfhfxx')))
        self.assertTrue(self.browser.find_element(BY.CSS_SELECTOR, '#reveal-cover-back-0sfhfxx object').is_displayed(), 'Back cover is displayed in a Foundation reveal')

    '''

    def test_work_cover_no_back_cover(self):

        # Search for work without back cover (Gaiman: Coraline) rec.id=870970-basis:24601986
        self.browser.get(self.base_url)

        self.search_pid('870970-basis:24601986')
        self.assertTrue(self.browser.find_element(BY.ID, 'selid-870970basis24601986'))

        # Expand article view - wait for result
        self.browser.find_element(BY.ID, 'selid-870970basis24601986').click()
        WebDriverWait(self.browser, 30).until(expected_conditions.presence_of_element_located((By.ID, "870970-basis24601986")))

        # Assert cover field is present
        self.assertTrue(self.browser.find_element(BY.CSS_SELECTOR, '.field-name-bibdk-cover-work'))

        # Assert Foundation reveal cover image is present, but hidden
        self.assertTrue(self.browser.find_element(BY.CSS_SELECTOR, '#reveal-cover-large-5bqr'), 'Foundation reveal cover image is present')
        self.assertFalse(self.browser.find_element(BY.CSS_SELECTOR, '#reveal-cover-large-5bqr').is_displayed(), 'Foundation reveal cover image is hidden')

        # Assert Foundation reveal back cover image is present, but hidden
        self.assertTrue(self.browser.find_element(BY.CSS_SELECTOR, '#reveal-cover-back-5bqr'), 'Foundation reveal back cover image is present')
        self.assertFalse(self.browser.find_element(BY.CSS_SELECTOR, '#reveal-cover-back-5bqr').is_displayed(), 'Foundation reveal back cover image is hidden')

        # If files are not cached, they are fetched by AJAX
        WebDriverWait(self.browser, 10).until(expected_conditions.presence_of_element_located((By.CSS_SELECTOR, '#work-cover-5bqr')))

        # Assert image is present
        self.assertTrue(self.browser.find_element(BY.CSS_SELECTOR, '.bibdk-cover-work-object-id-24601986'), 'Found div with class ".bibdk-cover-work-object-id-24601986"')

        WebDriverWait(self.browser, 10).until(expected_conditions.presence_of_element_located((By.CSS_SELECTOR, '.bibdk-cover-work-object-id-24601986 img')))
        self.assertTrue(self.browser.find_element(BY.CSS_SELECTOR, '.bibdk-cover-work-object-id-24601986 img'), 'Found image in "div.bibdk-cover-work-object-id-24601986"')

        # Assert link to Foundation reveal cover image is present
        WebDriverWait(self.browser, 10).until(expected_conditions.visibility_of_element_located((By.CSS_SELECTOR, 'a[data-reveal-id="reveal-cover-large-5bqr"]')))
        self.assertTrue(self.browser.find_element(BY.CSS_SELECTOR, 'a[data-reveal-id="reveal-cover-large-5bqr"]').is_displayed(), 'Link to Foundation reveal cover image is visible')

        # Assert link to Foundation reveal cover image is present, but hidden
        self.assertTrue(self.browser.find_element(BY.CSS_SELECTOR, 'a[data-reveal-id="reveal-cover-back-5bqr"]'))
        self.assertFalse(self.browser.find_element(BY.CSS_SELECTOR, 'a[data-reveal-id="reveal-cover-back-5bqr"]').is_displayed(), 'Link to Foundation reveal back cover image is hidden')

        # Assert Foundation reveal cover image is populated
        self.assertTrue(self.browser.find_element(BY.CSS_SELECTOR, '#reveal-cover-large-5bqr img'))

        # show cover in modal window
        self.browser.find_element(BY.CSS_SELECTOR, 'a[data-reveal-id="reveal-cover-large-5bqr"]').click()

        WebDriverWait(self.browser, 10).until(expected_conditions.visibility_of_element_located((By.CSS_SELECTOR, '#reveal-cover-large-5bqr')))
        self.assertTrue(self.browser.find_element(BY.CSS_SELECTOR, '#reveal-cover-large-5bqr img').is_displayed(), 'Cover is displayed in a Foundation reveal')


    def test_work_no_cover_no_back_cover(self):

        # Search for work without back cover (Foo Fighters: One by one) rec.id=870970-basis:43290894
        self.browser.get(self.base_url);

        self.search_pid('870970-basis:43290894')
        self.assertTrue(self.browser.find_element(BY.ID, 'selid-870970basis43290894'))

        # Expand article view - wait for result
        self.browser.find_element(BY.ID, 'selid-870970basis43290894').click()
        WebDriverWait(self.browser, 10).until(expected_conditions.presence_of_element_located((By.ID, "870970-basis43290894")))

        # Assert cover field is present
        self.assertTrue(self.browser.find_element(BY.CSS_SELECTOR, '.field-name-bibdk-cover-work'))

        # Assert link to Foundation reveal cover image is present
        self.assertTrue(self.browser.find_element(BY.CSS_SELECTOR, 'a[data-reveal-id="reveal-cover-large-1md"]'))
        self.assertFalse(self.browser.find_element(BY.CSS_SELECTOR, 'a[data-reveal-id="reveal-cover-large-1md"]').is_displayed(), 'Link to Foundation reveal cover image is visible')

        # Assert link to Foundation reveal cover image is present, but hidden
        self.assertTrue(self.browser.find_element(BY.CSS_SELECTOR, 'a[data-reveal-id="reveal-cover-back-1md"]'))
        self.assertFalse(self.browser.find_element(BY.CSS_SELECTOR, 'a[data-reveal-id="reveal-cover-back-1md"]').is_displayed(), 'Link to Foundation reveal back cover image is hidden')

    # Helper method : Search for element with specific pid
    def search_pid(self, pid):
        self.browser.find_element(BY.ID, "edit-search-block-form--2").send_keys("rec.id=" + pid)
        self.browser.find_element(BY.ID, "edit-submit").click()


