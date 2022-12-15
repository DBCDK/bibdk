# coding=utf-8

import time
import re
import helpers
import requests
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
from selenium.common.exceptions import NoSuchElementException
from selenium.common.exceptions import TimeoutException
from selenium.webdriver.common.action_chains import ActionChains


class TestBibdkCart(helpers.BibdkUnitTestCase):

    def test_cart_login_logout(self):
        # Testings the procedures regarding the cart and login/logout

        browser = self.browser
        browser.implicitly_wait(10)

        # add item to cart, using the add any edition btn
        self._add_item_to_cart('870970-basis:51155963', 'Bog')

        # goto cart and verify we have one item
        browser.get(self.base_url + "user/cart")

        # count items on the current page and verify that 1 item is visible
        items = browser.find_elements_by_class_name("manifestation-data")
        assert len(items) == 1, "1 item was found"

        username = str(int(time.time())) + 'bibdk_cart_test_01.bibdk@guesstimate.dbc.dk'
        password = 'bibdk_cart_test_01'

        # create new user and login
        user = self.getUser(username, password)
        user.delete()
        user.create()
        self.assertTrue(user.login())

        # goto cart and verify we have one item
        browser.get(self.base_url + "user/cart")

        # count items on the current page and verify that 1 item is visible
        items = browser.find_elements_by_class_name("manifestation-data")
        self.assertEqual(len(items), 1, "1 item was found")

        # add another item to the cart
        self._add_item_to_cart('870970-basis:51188233', 'Bog')

        # goto cart and verify we have two items in cart
        browser.get(self.base_url + "user/cart")


        # count items on the current page and verify that 2 items is visible
        items = browser.find_elements_by_class_name("manifestation-data")
        assert len(items) == 2, "2 items was found"

        # logout
        self.assertTrue(user.logout())

        # goto cart and verify we have zero items in cart
        browser.get(self.base_url + "user/cart")

        # count items on the current page and verify that 0 items are visible
        items = browser.find_elements_by_class_name("manifestation-data")
        assert len(items) == 0, "0 items was found"

        # login and verify that we still have two items in the cart
        self.assertTrue(user.login())

        # goto cart and verify we have two items in cart
        browser.get(self.base_url + "user/cart")

        # count items on the current page and verify that 2 items is visible
        items = browser.find_elements_by_class_name("manifestation-data")
        assert len(items) == 2, "2 items was found"

        #remove the two items from the cart
        self._remove_item_to_cart('870970-basis:51155963', 'Bog')

        # goto cart and verify we have one item
        browser.get(self.base_url + "user/cart")

        # count items on the current page and verify that 1 item is visible
        items = browser.find_elements_by_class_name("manifestation-data")
        assert len(items) == 1, "1 item was found"

        # remove another item to the cart
        self._remove_item_to_cart('870970-basis:51188233', 'Bog')

        # goto cart and verify we have zero items
        browser.get(self.base_url + "user/cart")

        # count items on the current page and verify that 0 items are visible
        items = browser.find_elements_by_class_name("manifestation-data")
        assert len(items) == 0, "0 items was found"

        # logout and login again to verify that the items actually are gone from the cart

        # logout
        self.assertTrue(user.logout())
        # verify that we currently doesn't have any materials in our cart
        # goto cart and verify we have zero items
        browser.get(self.base_url + "user/cart")

        # count items on the current page and verify that 0 items are visible
        items = browser.find_elements_by_class_name("manifestation-data")
        assert len(items) == 0, "0 items was found"

        # login and verify that we still have no items in the cart
        self.assertTrue(user.login())
        # goto cart and verify we have zero items
        browser.get(self.base_url + "user/cart")

        # count items on the current page and verify that 0 items are visible
        items = browser.find_elements_by_class_name("manifestation-data")
        # self.assertEqual(len(items), 0, "0 items was found")

        assert len(items) == 0, "0 items was found"

        # Logout and delete user
        # self.assertTrue(user.logout())
        user.logout()
        user.delete()

    def _test_cart_pager(self):
        # Tmp hack: Disable test - Python may have some issues with the openuserinfo_url SSL certificate:
        #           InsecurePlatformWarning: A true SSLContext object is not available. This prevents urllib3 from configuring SSL appropriately and may cause
        #           certain SSL connections to fail. You can upgrade to a newer version of Python to solve this. For more information, see
        #           https://urllib3.readthedocs.io/en/latest/advanced-usage.html#ssl-warnings
        # Test the bibdk cart pager

        browser = self.browser
        browser.implicitly_wait(10)
        # goto frontpage
        browser.get(self.base_url)

        username = str(int(time.time())) + 'bibdk_cart_test_02.bibdk@guesstimate.dbc.dk'
        password = 'bibdk_cart_test_02'

        # create new user and login
        user = self.getUser(username, password)
        user.delete()
        user.create()
        self.assertTrue(user.login())

        # Add a bunch of items to the cart:
        # form the request
        request = self.get_bibdk_cart_request(username)

        # Send the request
        r = requests.post(self.openuserinfo_url(), request)

        # ensure that the request was accepted
        assert "<Response [200]>" == str(r), "Requst to OpenUserInfo was accepted"

        # go to cart
        browser.get(self.base_url + "user/cart")

        # assert that the pager is present
        pager = browser.find_element(BY.ID, "bibdk-cart-pager")

        # with the default setting 20 items should be present on each page - that gives us to pages
        # first ensure that the current page is highlighted with the bold class
        link_1 = pager.find_element(BY.CLASS_NAME, "bold")
        assert link_1.text == "1", "bold class was found on active link"

        link_2 = pager.find_element(BY.XPATH, "//a[contains(@href, 'user/cart?page=2')]")
        assert link_2.get_attribute('class') == "", "did not find bold class in active"

        # count items on the current page and verify that 20 items is visible
        items = browser.find_elements_by_class_name("manifestation-data")
        assert len(items) == 20, "20 items was found on page 1"

        # go to second page and verify that the bold class has moved
        link_2.click()

        # assert that the pager is present
        pager = browser.find_element(BY.ID, "bibdk-cart-pager")

        link_2 = pager.find_element(BY.CLASS_NAME, "bold")
        assert link_2.text == "2", "bold class was found on active link"

        link_1 = pager.find_element(BY.XPATH, "//a[contains(@href, 'user/cart?page=1')]")
        assert link_1.get_attribute('class') == "", "did not find bold class in active"

        # count items on the current page and verify that 12 items is visible
        items = browser.find_elements_by_class_name("manifestation-data")

        assert len(items) == 17, "17 items was found on page 2"

        # Logout and delete user
        user.logout()
        user.delete()

    def _test_add_remove_to_cart_as_logged_in_user(self):
        # Tmp hack: Disable test - Python may have some issues with the openuserinfo_url SSL certificate:
        #           InsecurePlatformWarning: A true SSLContext object is not available. This prevents urllib3 from configuring SSL appropriately and may cause
        #           certain SSL connections to fail. You can upgrade to a newer version of Python to solve this. For more information, see
        #           https://urllib3.readthedocs.io/en/latest/advanced-usage.html#ssl-warnings
        """
        test_add_remove_to_cart_as_logged_in_user
        Related to bug 17945 - can't delete from cart
        """
        browser = self.browser
        browser.implicitly_wait(10)
        # goto frontpage
        browser.get(self.base_url)

        username = str(int(time.time())) + 'bibdk_cart_test_03.bibdk@guesstimate.dbc.dk'
        password = 'bibdk_cart_test_03'

        # create new user and login
        user = self.getUser(username, password)
        user.delete()
        fisk = user.create()
        assert fisk == 1, 'user created with success'

        self.assertTrue(user.login())

        # search for a specific item and add to the cart
        self._add_item_to_cart('870970-basis:51155963', 'Bog')

        # goto cart and verify we have one item
        browser.get(self.base_url + "user/cart")

        # count items on the current page and verify that 1 item is visible
        items = browser.find_elements_by_class_name("manifestation-data")
        assert len(items) == 1, "1 item was found"

        # go to cart
        browser.get(self.base_url + "user/cart")

        # verify that the item is in the cart
        browser.find_element(BY.CLASS_NAME, "cart-item-id-870970-basis-51155963")


        browser.execute_script("window.confirm = function(){return true;}")
        # remove item from cart

        browser.find_element(BY.ID, "edit-cart-table-870970-basis51155963").click()

        browser.find_element(BY.CLASS_NAME, "cart-view-delete-selected").click()

        #WebDriverWait(browser, 60).until(expected_conditions.invisibility_of_element_located((By.CLASS_NAME, "cart-item-id-870970-basis-51155963")))

        browser.get(self.base_url + "user/cart")
        assert self._class_is_present("edit-cart-table-870970-basis51155963") == 0, "Not found"

        # Add a bunch of items to the cart:
        request = self.get_bibdk_cart_request(username)

        # Send the request
        r = requests.post(self.openuserinfo_url(), request)

        # ensure that the request was accepted
        assert "<Response [200]>" == str(r), "Requst to OpenUserInfo was accepted"
        # go to cart
        browser.get(self.base_url + "user/cart")

        # verify that the item is in the cart
        browser.find_element(BY.ID, "edit-cart-table-870970-basis51155963")

        user.delete()

    def test_cart_view(self):
        browser = self.browser
        browser.implicitly_wait(10)

        # goto /user
        browser.get(self.base_url + "user/cart")

        table = browser.find_element(BY.CLASS_NAME, "table")
        table.find_element(BY.CLASS_NAME, "empty")

        # search for a specific item and add to the cart
        self._add_item_to_cart('870970-basis:51155963', 'Bog')

        # goto /user
        browser.get(self.base_url + "user/cart")

        browser.find_element(BY.CLASS_NAME, "cart-actions")
        cart_text = browser.find_element(BY.CLASS_NAME, "cart-view-delete-selected").text
        assert cart_text != ""

    def test_cart_view_mobile_size(self):
        """
        Verify test_cart_view_mobile_size
        """
        browser = self.browser
        # set windows size to mobile
        browser.set_window_size(480, 768)
        browser.implicitly_wait(10)

        # goto /user
        browser.get(self.base_url + "user/cart")

        time.sleep(10)
        table = browser.find_element(BY.CLASS_NAME, "table")
        table.find_element(BY.CLASS_NAME, "empty")

        time.sleep(1)
        # search for a specific item and add to the cart
        self._add_item_to_cart('870970-basis:51155963', 'Bog')

        # goto /user
        browser.get(self.base_url + "user/cart")

        browser.find_element(BY.CLASS_NAME, "cart-actions")
        cart_text = browser.find_element(BY.CLASS_NAME, "cart-view-delete-selected").text
        assert cart_text != ""

    def _test_add_remove_to_cart_as_logged_in_user_mobile_size(self):
        # Tmp hack: Disable test - Python may have some issues with the openuserinfo_url SSL certificate:
        #           InsecurePlatformWarning: A true SSLContext object is not available. This prevents urllib3 from configuring SSL appropriately and may cause
        #           certain SSL connections to fail. You can upgrade to a newer version of Python to solve this. For more information, see
        #           https://urllib3.readthedocs.io/en/latest/advanced-usage.html#ssl-warnings
        """
        Verify test_add_remove_to_cart_as_logged_in_user_mobile_size
        """
        browser = self.browser
        browser.implicitly_wait(10)
        # set windows size to mobile
        browser.set_window_size(480, 768)

        # goto frontpage
        browser.get(self.base_url)

        username = str(int(time.time())) + 'bibdk_cart_test_04.bibdk@guesstimate.dbc.dk'
        password = 'bibdk_cart_test_04'

        user = self.getUser(username, password)
        user.create()
        self.assertTrue(user.login())

        # search for a specific item and add to the cart
        self._add_item_to_cart('870970-basis:51155963', 'Bog')

        # goto cart and verify we have one item
        browser.get(self.base_url + "user/cart")

        # count items on the current page and verify that 1 item is visible
        items = browser.find_elements_by_class_name("manifestation-data")
        assert len(items) == 1, "1 item was found"

        # go to cart
        browser.get(self.base_url + "user/cart")

        # verify that the item is in the cart
        browser.find_element(BY.CLASS_NAME, "cart-item-id-870970-basis-51155963")


        browser.execute_script("window.confirm = function(){return true;}")
        # remove item from cart

        browser.find_element(BY.ID, "edit-cart-table-870970-basis51155963").click()

        browser.find_element(BY.CLASS_NAME, "cart-view-delete-selected").click()

        browser.get(self.base_url + "user/cart")

        assert self._class_is_present("edit-cart-table-870970-basis51155963") == 0

        # Add a bunch of items to the cart:
        request = self.get_bibdk_cart_request(username)

        # Send the request
        r = requests.post(self.openuserinfo_url(), request)

        # ensure that the request was accepted
        assert "<Response [200]>" == str(r), "Requst to OpenUserInfo was accepted"
        # go to cart
        browser.get(self.base_url + "user/cart")

        # verify that the item is in the cart
        browser.find_element(BY.ID, "edit-cart-table-870970-basis51155963")

        user.delete()

    def _add_item_to_cart(self, id, type):
        browser = self.browser
        browser.implicitly_wait(10)
        # search for a specific item and add to the cart
        browser.get(self.base_url + "search/work/rec.id=" + id)
        #self._check_popup()

        time.sleep(1)

        # get input field
        #try:
        #    manifestation = wait.until(
        #        EC.visibility_of_element_located((By.ID, "selid-" + re.sub('[-:]', '', id)))
        #    )
        #except NoSuchElementException:
        #    assert False

        time.sleep(1)
        self._check_pop_up()
        time.sleep(1)
        wait = WebDriverWait(browser, 30)
        ActionChains(browser).move_to_element(wait.until(EC.visibility_of_element_located((By.ID, "selid-" + re.sub('[-:]', '', id))))).click().perform()

        # add item to cart, using the add any edition btn
        browser.find_element(BY.ID, "any_edition_but_" + re.sub('[-:]', '', id)).click()
        id = re.sub('[:]', '', id)
        browser.find_element(BY.ID, "cart-any-" + id).click()

        time.sleep(10)
        browser.find_element(BY.ID, "manifestation-toggle-button-" + type + "-" + id).click()
        # wait for the AJAX to have finished

    def _check_pop_up(self):
        agree = False
        browser = self.browser
        wait = WebDriverWait(browser, 1)
        try:
            agree = wait.until(
                EC.visibility_of_element_located((By.CLASS_NAME, "agree-button"))
            )
        except (TimeoutException, NoSuchElementException):
            pass

        if agree:
            agree.click()

    def _remove_item_to_cart(self, id, type):
        browser = self.browser
        browser.implicitly_wait(10)
        # search for a specific item and add to the cart
        browser.get(self.base_url + "search/work/rec.id=" + id)

        # unfold work
        browser.find_element(BY.ID, "selid-" + re.sub('[-:]', '', id)).click()

        # wait for AJAX to be completed

        # add item to cart, using the add any edition btn
        browser.find_element(BY.ID, "any_edition_but_" + re.sub('[-:]', '', id)).click()
        id = re.sub('[:]', '', id)
        browser.find_element(BY.ID, "cart-any-" + id).click()

        browser.find_element(BY.ID, "manifestation-toggle-button-" + type + "-" + id).click()
        # wait for the AJAX to have finished
