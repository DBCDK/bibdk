from selenium.webdriver.support.wait import WebDriverWait
import helpers


class TestReservationButton(helpers.BibdkUnitTestCase):

    def test_reservation_order_any_edition_button(self):
        browser = self.browser

        browser.get(self.base_url + "search/work/rec.id=870970-basis:50789748")

        #find the inner order button
        inner_oder_btn = browser.find_element_by_id("any_edtion_order_870970basis50789748")
        # find the memo button
        memo_btn = browser.find_element_by_id("cart-any-870970-basis50789748")

        # assert the inner order btn and the memo button to be not visible
        self.assertFalse(inner_oder_btn.is_displayed(), "The order button is not visible")
        self.assertFalse(memo_btn.is_displayed(), "The order button is not visible")

        #find the order_any_edition button
        order_any_edition_btn = browser.find_element_by_id("any_edition_but_870970basis50789748")

        # click the order any edition button
        order_any_edition_btn.click()

        # assert the inner order btn and the memo button to be visible
        self.assertTrue(inner_oder_btn.is_displayed(), "The order button is visible")
        self.assertTrue(memo_btn.is_displayed(), "The order button is visible")

        # click the order any edition button
        order_any_edition_btn.click()

        # assert the inner order btn and the memo button to be not visible
        self.assertFalse(inner_oder_btn.is_displayed(), "The order button is not visible")
        self.assertFalse(memo_btn.is_displayed(), "The order button is not visible")

        # click the order any edition button
        order_any_edition_btn.click()

        # assert the inner order btn and the memo button to be visible
        self.assertTrue(inner_oder_btn.is_displayed(), "The order button is visible")
        self.assertTrue(memo_btn.is_displayed(), "The order button is visible")

        # get the current classes on the memo button
        classes = memo_btn.get_attribute("class")

        #assert that the not-in-cart class is currently on the memo button
        self.assertTrue("in-cart" not in classes)

        # click the "Husk" button
        memo_btn.click()
        # wait for the button we clicked not to be disabled. It is disabled while the AJAX call is active
        WebDriverWait(memo_btn, 20).until_not(self.is_object_disabled)

        # assert that the correct classes are found on the button after the AJAX call finished
        self.assertTrue("in-cart" in memo_btn.get_attribute("class"), "found class in-cart")

        #undo everything

        # click the "Husk" button
        memo_btn.click()

        # wait for the button we clicked not to be disabled. It is disabled while the AJAX call is active
        WebDriverWait(memo_btn, 20).until_not(self.is_object_disabled)

        # assert that the correct classes are found on the button after the AJAX call finished
        self.assertTrue("in-cart" not in memo_btn.get_attribute("class"), "found class not-in-cart")


    def is_object_disabled(self, obj):
        return self.class_in_attributes("disabled", obj)

    def class_in_attributes(self, classname, obj):
        return classname in obj.get_attribute("class")
