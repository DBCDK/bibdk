import helpers


class TestBug17307Messages(helpers.BibdkUnitTestCase, helpers.BibdkUser):
    def test_message_on_no_search_result(self):
        browser = self.browser

        # do a empty search
        self._goto("search/work")

        # get all messages
        messages = browser.find_element(By.ID, "messages")

        # ensure that we have a message og type warning
        messages.find_element(By.CLASS_NAME, "message--warning")

        # do a actiual search request
        self._goto("search/work/master chief")

        # ensure no warnings are shown
        self._assert_no_class("message--warning")

        # ensure something is actually displayed
        browser.find_element(By.ID, "search-result-wrapper")

        # do a empty search
        self._goto("search/work")

        # get all messages
        messages = browser.find_element(By.ID, "messages")

        # ensure that we have a message og type warning
        messages.find_element(By.CLASS_NAME, "message--warning")

        # ensure no results are displayed
        self._assert_no_class("work-header")


