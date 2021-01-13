from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
import helpers

class TestReservationAnonUser(helpers.BibdkUnitTestCase):

    def test_reservation_book(self):
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
                    By.CSS_SELECTOR, ".bibdk-favourite--actions .form-submit"
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

    def test_reservation_request_other_manifestation(self):
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

        input.send_keys('svenskevældets fald aakjær')

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
                    By.ID, "any_edition_but_800010katalog99122907984205763"
                )
            )
        )
        reservation.click()

        # Order material
        order = wait.until(
            EC.visibility_of_element_located(
                (
                    By.ID, "any_edtion_order_800010katalog99122907984205763"
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

        # Check that a manifestation can be ordered
        search_library = wait.until(
            EC.visibility_of_element_located(
                (
                    By.ID, "edit-anyfield"
                )
            )
        )

    def test_reservation_no_request_button(self):
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

        input.send_keys('svenskevældets fald aakjær')

        submit = wait.until(
            EC.visibility_of_element_located(
                (
                    By.ID, "edit-submit"
                )
            )
        )
        submit.click()

        # Toggle work
        work = wait.until(
            EC.visibility_of_element_located(
                (
                    By.ID, "800010katalog99122907984205763"
                )
            )
        )
        work.click()

        # Check that first manifestation has no request button
        try:
            first = wait.until(
                EC.visibility_of_element_located(
                    (
                        By.ID, "this_edition_800010-katalog:99122907984205763"
                    )
                )
            )
            not_found = False
        except:
            not_found = True
        assert not_found

        # Expand all manifestations
        all = wait.until(
            EC.visibility_of_element_located(
                (
                    By.CLASS_NAME, "manifestation-toggle-link"
                )
            )
        )
        all.click()

        # Check that second manifestation has order button
        second = wait.until(
            EC.visibility_of_element_located(
                (
                    By.ID, "this_edition_820030-katalog:512230"
                )
            )
        )
