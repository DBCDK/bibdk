from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
import helpers

class TestReviews(helpers.BibdkUnitTestCase):

    def test_other_reviews(self):
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

        # Open reviews
        reviews = wait.until(
            EC.visibility_of_element_located(
                (
                    By.ID, "reviews"
                )
            )
        )
        reviews.click()

        # Open journal/newspaper reviews
        news = wait.until(
            EC.visibility_of_element_located(
                (
                    By.ID, "selid-worktab-other-review"
                )
            )
        )
        news.click()

        # Check that at least one review is availble
        review = wait.until(
            EC.visibility_of_element_located(
                (
                    By.CLASS_NAME, "bibdk-article-review"
                )
            )
        )

    def test_materialevurdering(self):
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
        input.send_keys('rec.id=870970-basis:53369545')

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

        # Open reviews
        reviews = wait.until(
            EC.visibility_of_element_located(
                (
                    By.ID, "reviews"
                )
            )
        )
        reviews.click()

        # Open Materialevurdering
        matvurd = wait.until(
            EC.visibility_of_element_located(
                (
                    By.ID, "selid-worktab-material-review"
                )
            )
        )
        matvurd.click()

        heading = wait.until(
            EC.visibility_of_element_located(
                (
                    By.TAG_NAME, "h6"
                )
            )
        )

        if not 'Kort om bogen' in heading.text:
            assert False
