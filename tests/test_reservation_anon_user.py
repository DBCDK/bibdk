from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
import helpers

class TestReservationAnonUser(helpers.BibdkUnitTestCase):

    def test_reservation_book(self):
        browser = self.browser
        self._goto_frontpage()
        wait = WebDriverWait(browser, 30)

        agree = wait.until(
          EC.visibility_of_element_located((By.CLASS_NAME, "agree-button"))
        )
        agree.click()

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

        # Open Reservation
        reservation = wait.until(
            EC.visibility_of_element_located(
                (
                    By.ID, "any_edition_but_870970basis47334314"
                )
            )
        )
        reservation.click()

        # Order material
        order = wait.until(
            EC.visibility_of_element_located(
                (
                    By.ID, "any_edtion_order_870970basis47334314"
                )
            )
        )
        order.click()

        # wait for the PopUpWindow to visible
        wait.until(
            self.found_window('PopUpWindowreservation')
        )
        # ensure we have two windows available
        self.assertEqual(2, len(browser.window_handles))

        # Find library
        input = wait.until(
            EC.visibility_of_element_located(
                (
                    By.ID, "edit-anyfield"
                )
            )
        )
        input.send_keys('790900')

        submit = wait.until(
            EC.visibility_of_element_located(
                (
                    By.ID, "edit-search"
                )
            )
        )
        submit.click()

        # Choose Library
        library = wait.until(
            EC.visibility_of_element_located(
                (
                    By.CSS_SELECTOR, ".ting-agency--actions .form-submit"
                )
            )
        )
        library.click()

        # Input user data
        user = self.getTestUser("790900")
        user_id = wait.until(
            EC.visibility_of_element_located(
                (
                    By.ID, "edit-userid"
                )
            )
        )
        user_id.send_keys(user['userid'])
        pin = wait.until(
            EC.visibility_of_element_located(
                (
                    By.ID, "edit-pincode"
                )
            )
        )
        pin.send_keys(user['pin'])

        # Place order
        place = wait.until(
            EC.visibility_of_element_located(
                (
                    By.ID, "edit-next"
                )
            )
        )
        place.click()

        # Check message
        message = wait.until(
            EC.visibility_of_element_located(
                (
                    By.CLASS_NAME, "message--status"
                )
            )
        )
        if not 'bestilling er modtaget' in message.text:
            assert False
