# coding=utf-8
import helpers
import time


class TestReservationBorchk(helpers.BibdkUnitTestCase):

    pid = '870970-basis:50984508' # Stillidsen - Donna Tartt
    guldborgsund = '737600' # Library with strict borrower check
    aabenraa = '758000' # Library accepting unknown users (NOT a test library!)
    dummy_bestil = '100400'
    dummy_userdata = {
            'userid': '0',
            'pincode': '0',
            'username': 'test',
            'usermail': 'noreply@dbc.dk',
    }
    empty_userdata = {
            'userid': '',
            'pincode': '',
            'username': '',
            'usermail': '',
    }
    guldborgsund_dummy_data = {
            'cardno': '0',
            'pincode': '0',
            'username': 'test',
            'usermail': 'noreply@dbc.dk',
    }

    def bootstrap_reservation(self, item, library_no, userdata):
        browser = self.browser
        browser.implicitly_wait(20)
        self._goto("reservation?ids=" + item)
        search_field = browser.find_element(BY.ID, 'edit-anyfield')
        search_field.send_keys(library_no)
        browser.find_element(BY.ID, 'edit-search').click()
        browser.find_element(BY.NAME, 'branch-' + library_no).click()

        # time.sleep(10)
        for i in userdata:
            browser.find_element(BY.ID, 'edit-' + i).send_keys(userdata[i])

        browser.find_element(BY.ID, 'edit-next').click()

    def get_error_messages(self):
        error_elements = self.browser.find_elements_by_class_name('message--error')
        error_messages = map(lambda x : x.text, error_elements)
        return error_messages

    def get_warning_messages(self):
        warning_elements = self.browser.find_elements_by_class_name('message--warning')
        warning_messages = map(lambda x : x.text, warning_elements)
        return warning_messages

    def check_available_service(self):
        error_messages = self.get_error_messages()
        self.assertNotIn('Service Unavailable. We can not make reservation right know', error_messages,
            'Service Unavailable!')

    def test_reservation_missing_value(self):
        """
        No borrower check should be done when a required value is missing
        """
        browser = self.browser
        self.bootstrap_reservation(self.pid, self.aabenraa, self.empty_userdata)

        error_messages = self.get_error_messages()
        missing_fields = [
            u"CPR-nummer ELLER de 10 cifre fra lånerkortet skal udfyldes", # this is a unicode string due to Danish characters
            u"Pinkode/brugerkode - den du bruger på biblioteket skal udfyldes",
            u"Navn skal udfyldes"
        ]
        for f in missing_fields:
            self.assertIn(f, error_messages, 'Field: %s is missing in error messages' % f)
        step3 = browser.find_element(BY.ID, 'edit-3')
        self.assertIn('inactive', step3.get_attribute('class'), 'Still at step 2.')

    def test_reservation_accept_unknown_user(self):
        """
        Library accepts orders from unknown users though it is necessary to
        fill out all required values but it can be done with phony input.

        NOTICE: Abort reservation before finishing because Aabenraa is not a test
        library!
        """
        browser = self.browser
        #self.bootstrap_reservation(self.pid, self.dummy_bestil, self.dummy_userdata)
        self.bootstrap_reservation(self.pid, self.aabenraa, self.dummy_userdata)
        step3 = browser.find_element(BY.ID, 'edit-3')
        #self.assertNotIn('inactive', step3.get_attribute('class'), 'Not advanced to step 3.')
        self.assertIn('inactive', step3.get_attribute('class'), 'Not advanced to step 3.')
        self.check_available_service()
        warning_messages = self.get_warning_messages()
        # PJO TODO find a library that accepts orders from unknown user - and then enable the test
        #self.assertIn('Borrower not found, but Library accepts reservations from unknown users', warning_messages, 'Library should accept unknown users.')

    """
    def test_reservation_reject_unknown_user(self):
        #Library accepts only orders from known user.
        browser = self.browser
        self.bootstrap_reservation(self.pid, self.guldborgsund, self.guldborgsund_dummy_data)
        step3 = browser.find_element(BY.ID, 'edit-3')
        self.assertIn('inactive', step3.get_attribute('class'), 'Still at step 2.')
        error_messages = self.get_error_messages()
        self.check_available_service()
        error_message = u"Du kan ikke findes i bibliotekets lånerregister ud fra dine indtastede lånerdata - har du skrevet rigtigt? Gå evt. tilbage og prøv igen."
        self.assertIn(error_message, error_messages, 'Library should reject unknown users.')
        print(error_message)
        print(error_messages)
    """

    def test_reservation_known_user(self):
        """
        Library accepts orders from a known user
        """
        # outcommented for now - get a testuser for fbs
        """
        browser = self.browser
        self.bootstrap_reservation(self.pid, self.guldborgsund, self.guldborgsund_testuser)
        step3 = browser.find_element(BY.ID, 'edit-3')
        self.assertNotIn('inactive', step3.get_attribute('class'), 'Library should not reject known users.')
        error_messages = self.get_error_messages()
        self.assertEqual(error_messages, []) # No error messages here, please!
        warning_messages = self.get_warning_messages()
        self.assertEqual(warning_messages, []) # No warning messages here, either!
        """
