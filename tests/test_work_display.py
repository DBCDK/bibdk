# coding=utf-8
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
import helpers

class TestWorkDisplay(helpers.BibdkUnitTestCase):

    def test_work_display_data(self):
        browser = self.browser
        self._goto_frontpage()
        wait = WebDriverWait(browser, 30)

        # Perform search
        input = wait.until(
            EC.visibility_of_element_located(
                (
                    By.CLASS_NAME, "search-block-form"
                )
            )
        )
        input.send_keys('rec.id=870970-basis:47334314')

        submit = wait.until(
            EC.visibility_of_element_located(
                (
                    By.ID, "edit-submit"
                )
            )
        )
        submit.click()

        # Display full record
        record = wait.until(
            EC.visibility_of_element_located(
                (
                    By.CLASS_NAME, "work-header"
                )
            )
        )
        record.click()

        # Check that record data is correct
        creator = wait.until(
            EC.visibility_of_element_located(
                (
                    By.CSS_SELECTOR, ".field-name-bibdk-mani-creators a"
                )
            )
        )
        if not "Tarjei Vesaas" in creator.text:
            assert False

        year = browser.find_elements(By.CSS_SELECTOR, '.field-name-bibdk-mani-pub-year span.openformat-field')
        if not "2019" in year[0].text:
            assert False

        shelf = browser.find_elements(By.CSS_SELECTOR, '.field-name-bibdk-mani-shelf a')
        if not u"skønlitteratur" in shelf[-1].text:
            assert False
        if not 'dkcclterm.dk%3D%22sk%22' in shelf[-1].get_attribute('href'):
            assert False

    def test_work_display_creator_link(self):
        browser = self.browser
        self._goto_frontpage()
        self._check_pop_up()
        wait = WebDriverWait(browser, 30)

        # Perform search
        input = wait.until(
            EC.visibility_of_element_located(
                (
                    By.CLASS_NAME, "search-block-form"
                )
            )
        )
        input.send_keys('rec.id=870970-basis:47334314')

        submit = wait.until(
            EC.visibility_of_element_located(
                (
                    By.ID, "edit-submit"
                )
            )
        )
        submit.click()

        # Display full record
        record = wait.until(
            EC.visibility_of_element_located(
                (
                    By.CLASS_NAME, "work-header"
                )
            )
        )
        record.click()

        # Find and activate creator search link
        creator = wait.until(
            EC.visibility_of_element_located(
                (
                    By.CSS_SELECTOR, ".field-name-bibdk-mani-creators a"
                )
            )
        )
        creator.click()

        # Check that the search input is correct
        new_input = wait.until(
            EC.visibility_of_element_located(
                (
                    By.CLASS_NAME, "search-block-form"
                )
            )
        )
        if not 'phrase.creator="Tarjei Vesaas"' in new_input.get_attribute('value'):
            assert False

    def test_work_display_subject_link(self):
        browser = self.browser
        self._goto_frontpage()
        wait = WebDriverWait(browser, 30)

        # Perform search
        input = wait.until(
            EC.visibility_of_element_located(
                (
                    By.CLASS_NAME, "search-block-form"
                )
            )
        )
        input.send_keys('rec.id=870970-basis:47334314')

        submit = wait.until(
            EC.visibility_of_element_located(
                (
                    By.ID, "edit-submit"
                )
            )
        )
        submit.click()

        # Display full record
        record = wait.until(
            EC.visibility_of_element_located(
                (
                    By.CLASS_NAME, "work-header"
                )
            )
        )
        record.click()

        # Find and activate creator search link
        subjects = wait.until(
            EC.visibility_of_element_located(
                (
                    By.CSS_SELECTOR, ".work-subject a"
                )
            )
        )
        subjects.click()

        # Check that the search input is correct
        new_input = wait.until(
            EC.visibility_of_element_located(
                (
                    By.CLASS_NAME, "search-block-form"
                )
            )
        )
        if not 'phrase.subject="lgbtqia+"' in new_input.get_attribute('value'):
            assert False

    def test_work_display_further_search_author(self):
        browser = self.browser
        self._goto_frontpage()
        wait = WebDriverWait(browser, 30)

        # Perform search
        input = wait.until(
            EC.visibility_of_element_located(
                (
                    By.CLASS_NAME, "search-block-form"
                )
            )
        )
        input.send_keys('rec.id=870970-basis:47334314')

        submit = wait.until(
            EC.visibility_of_element_located(
                (
                    By.ID, "edit-submit"
                )
            )
        )
        submit.click()

        # Display full record
        record = wait.until(
            EC.visibility_of_element_located(
                (
                    By.CLASS_NAME, "work-header"
                )
            )
        )
        record.click()

        # Open inspiration
        more = wait.until(
            EC.visibility_of_element_located(
                (
                    By.ID, "more-about"
                )
            )
        )
        more.click()

        # Open about author
        author = wait.until(
            EC.visibility_of_element_located(
                (
                    By.ID, "selid-worktab-about-author"
                )
            )
        )
        author.click()

        link = wait.until(
            EC.visibility_of_element_located(
                (
                    By.CLASS_NAME, "about-author-links"
                )
            )
        )

        if not 'phrase.subject%3D%22Tarjei%20Vesaas%22' in link.get_attribute('href'):
            assert False

    def test_work_display_further_search_subject(self):
        browser = self.browser
        self._goto_frontpage()
        wait = WebDriverWait(browser, 30)
        self._check_pop_up()

        # Perform search
        input = wait.until(
            EC.visibility_of_element_located(
                (
                    By.CLASS_NAME, "search-block-form"
                )
            )
        )
        input.send_keys('rec.id=870970-basis:47334314')

        submit = wait.until(
            EC.visibility_of_element_located(
                (
                    By.ID, "edit-submit"
                )
            )
        )
        submit.click()

        # Display full record
        record = wait.until(
            EC.visibility_of_element_located(
                (
                    By.CLASS_NAME, "work-header"
                )
            )
        )
        record.click()

        # Open inspiration
        more = wait.until(
            EC.visibility_of_element_located(
                (
                    By.ID, "more-about"
                )
            )
        )
        more.click()

        # Open about subjects
        subjects = wait.until(
            EC.visibility_of_element_located(
                (
                    By.ID, "selid-worktab-further-search"
                )
            )
        )
        subjects.click()

        select_subject = wait.until(
            EC.visibility_of_element_located(
                (
                    By.XPATH, "//*[@id='worktab-further-search']/table[2]/tbody/tr[1]/td[1]/input"
                )
            )
        )
        select_subject.click()

        select_genre = wait.until(
            EC.visibility_of_element_located(
                (
                    By.XPATH, "//*[@id='worktab-further-search']/table[2]/tbody/tr[1]/td[3]/input"
                )
            )
        )
        select_genre.click()

        submit = wait.until(
            EC.visibility_of_element_located(
                (
                    By.CLASS_NAME, "further-search-btn"
                )
            )
        )
        submit.click()

        # Check that the search input is correct
        new_input = wait.until(
            EC.visibility_of_element_located(
                (
                    By.CLASS_NAME, "search-block-form"
                )
            )
        )
        if not 'phrase.subject="venskab" and dkcclterm.dk="sk"' in new_input.get_attribute('value'):
            assert False

    def test_work_display_note_link(self):
        browser = self.browser
        self._goto_frontpage()
        self._check_pop_up()
        wait = WebDriverWait(browser, 30)

        # Perform search
        input = wait.until(
            EC.visibility_of_element_located(
                (
                    By.CLASS_NAME, "search-block-form"
                )
            )
        )
        input.send_keys('rec.id=870970-basis:50705633')

        submit = wait.until(
            EC.visibility_of_element_located(
                (
                    By.ID, "edit-submit"
                )
            )
        )
        submit.click()

        # Display full record
        record = wait.until(
            EC.visibility_of_element_located(
                (
                    By.CLASS_NAME, "work-header"
                )
            )
        )
        record.click()

        # Check that note link i present
        link = wait.until(
            EC.visibility_of_element_located(
                (
                    By.CSS_SELECTOR, ".field-name-bibdk-mani-access-note a"
                )
            )
        )

    def test_work_display_one_contributor(self):
        browser = self.browser
        self._goto_frontpage()
        self._check_pop_up()
        wait = WebDriverWait(browser, 30)

        # Perform search
        input = wait.until(
            EC.visibility_of_element_located(
                (
                    By.CLASS_NAME, "search-block-form"
                )
            )
        )
        input.send_keys('rec.id=870970-basis:47917727')

        submit = wait.until(
            EC.visibility_of_element_located(
                (
                    By.ID, "edit-submit"
                )
            )
        )
        submit.click()

        # Display full record
        record = wait.until(
            EC.visibility_of_element_located(
                (
                    By.CLASS_NAME, "work-header"
                )
            )
        )
        record.click()

        # Check that contributor is present
        contrib = wait.until(
            EC.visibility_of_element_located(
                (
                    By.CSS_SELECTOR, ".field-name-bibdk-mani-contribs .openformat-field"
                )
            )
        )
        assert contrib.text == u'illustrator'

    def test_work_display_several_contributors(self):
        browser = self.browser
        self._goto_frontpage()
        self._check_pop_up()
        wait = WebDriverWait(browser, 30)

        # Perform search
        input = wait.until(
            EC.visibility_of_element_located(
                (
                    By.CLASS_NAME, "search-block-form"
                )
            )
        )
        input.send_keys('rec.id=870970-basis:47917743')

        submit = wait.until(
            EC.visibility_of_element_located(
                (
                    By.ID, "edit-submit"
                )
            )
        )
        submit.click()

        # Display full record
        record = wait.until(
            EC.visibility_of_element_located(
                (
                    By.CLASS_NAME, "work-header"
                )
            )
        )
        record.click()

        # Check that contributors are present
        contrib = wait.until(
            EC.visibility_of_element_located(
                (
                    By.CSS_SELECTOR, ".field-name-bibdk-mani-contribs .openformat-field:first-of-type"
                )
            )
        )
        assert contrib.text == u'redaktører'
