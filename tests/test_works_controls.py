import helpers


class TestWorksControlsResponiveness(helpers.BibdkUnitTestCase):

    def test_works_controls_xlarge(self):
        """
        Testing visiblity of links in search result controls on large devices
        """
        browser = self.browser
       # testing on default (x-large) size (W:1024)
        browser.set_window_size(1024, 1800)

         # url: master chief
        url = self.base_url + 'search/work/foo'
        browser.get(url)
        browser.implicitly_wait(5)

        works_controls = browser.find_element_by_css_selector(".works-controls")

        # search result count
        amount_block = works_controls.find_element_by_css_selector(".ting-openformat-search-amount-block")
        self.assertTrue(amount_block.is_displayed(), "amount block is displayed in works controls")

        # view search result in list format
        list_view = works_controls.find_element_by_css_selector("#ting-openformat-full-view-button-closed")
        self.assertTrue(list_view.is_displayed(), "list view link is displayed in works controls")

        list_view_icon = list_view.find_element_by_css_selector(".svg-view-list")
        self.assertTrue(list_view_icon.is_displayed(), "list view icon is displayed in works controls")

        list_view_text = list_view.find_element_by_css_selector("span")
        self.assertTrue(list_view_text.is_displayed(), "list view text is displayed in works controls")

        # view search result in detail format
        detail_view = works_controls.find_element_by_css_selector("#ting-openformat-full-view-button-expanded")
        self.assertTrue(detail_view.is_displayed(), "detail view link is displayed in works controls")

        detail_view_icon = detail_view.find_element_by_css_selector(".svg-view-details")
        self.assertTrue(detail_view_icon.is_displayed(), "detail view icon is displayed in works controls")

        detail_view_text = list_view.find_element_by_css_selector("span")
        self.assertTrue(detail_view_text.is_displayed(), "detail view text is displayed in works controls")

        # Sorting options dropdown
        sort_dropdown = works_controls.find_element_by_css_selector("#bibdk-search-controls-form")
        self.assertTrue(sort_dropdown.is_displayed(), "sort dropdown is displayed in works controls")

        # RSS feed button
        rss_feed = works_controls.find_element_by_css_selector(".ting-openformat-feeds")
        self.assertTrue(rss_feed.is_displayed(), "RSS feed is displayed in works controls")

        # Pagers
        pager_next = works_controls.find_element_by_css_selector(".bibdk-pager-next")
        self.assertTrue(pager_next.is_displayed(), "pager next is displayed in works controls (x-large)")

        pager_next_text = pager_next.find_element_by_css_selector('a[data-pager="text"]')
        self.assertTrue(pager_next_text.is_displayed(), "pager next text is displayed in works controls")

        pager_next_icon = pager_next.find_element_by_css_selector('a[data-pager="icon"]')
        self.assertFalse(pager_next_icon.is_displayed(), "pager next icon is not displayed in works controls")

        pager_next_text.click()

        browser.implicitly_wait(5)

        works_controls = browser.find_element_by_css_selector(".works-controls")


    def test_works_controls_large(self):
        """
        Testing visiblity of links in search result controls on large devices
        """
        browser = self.browser
        browser.set_window_size(768, 768)

        url = self.base_url + 'search/work/foo'
        browser.get(url)
        browser.implicitly_wait(5)

        # testing on large size (W:760)

        works_controls = browser.find_element_by_xpath("//div[contains(@class,'works-controls')]")

        amount_block = works_controls.find_element_by_xpath("//div[@class='ting-openformat-search-amount-block']")
        self.assertTrue(amount_block.is_displayed(), "amount block is displayed in works controls")

        list_view = works_controls.find_element_by_xpath("//a[@id='ting-openformat-full-view-button-closed']")

        list_view_icon = list_view.find_element_by_xpath("//*[local-name()='svg' and contains(@class,'svg-view-list')]")

        list_view_text = list_view.find_element_by_css_selector("span")
        self.assertFalse(list_view_text.is_displayed(), "list view text is not displayed in works controls")

        detail_view = works_controls.find_element_by_xpath("//a[@id='ting-openformat-full-view-button-expanded']")

        detail_view_icon = detail_view.find_element_by_xpath("//*[local-name()='svg' and contains(@class,'svg-view-details')]")

        detail_view_text = list_view.find_element_by_css_selector("span")
        self.assertFalse(detail_view_text.is_displayed(), "detail view text is not displayed in works controls")

        sort_dropdown = works_controls.find_element_by_id("bibdk-search-controls-form")

        rss_feed = works_controls.find_element_by_css_selector(".ting-openformat-feeds")

        pager_next = works_controls.find_element_by_css_selector(".bibdk-pager-next")
        self.assertTrue(pager_next.is_displayed(), "pager next is displayed in works controls (large)")

        pager_next_text = pager_next.find_element_by_css_selector('a[data-pager="text"]')
        self.assertFalse(pager_next_text.is_displayed(), "pager next text is not displayed in works controls")

        pager_next_icon = pager_next.find_element_by_css_selector('a[data-pager="icon"]')
        self.assertTrue(pager_next_icon.is_displayed(), "pager next icon is not displayed in works controls")


    def test_works_controls_medium(self):
        """
        Testing visiblity of links in search result controls on medium devices
        """
        browser = self.browser
        browser.set_window_size(480, 768)

        url = self.base_url + 'search/work/foo'
        browser.get(url)
        browser.implicitly_wait(5)

        # testing on medium size (W:480)

        works_controls = browser.find_element_by_css_selector(".works-controls")

        amount_block = works_controls.find_element_by_css_selector(".ting-openformat-search-amount-block")
        self.assertTrue(amount_block.is_displayed(), "amount block is displayed in works controls")

        list_view = works_controls.find_element_by_css_selector("#ting-openformat-full-view-button-closed")
        self.assertFalse(list_view.is_displayed(), "list view link is not displayed in works controls")

        list_view_icon = list_view.find_element_by_css_selector(".svg-view-list")
        self.assertFalse(list_view_icon.is_displayed(), "list view icon is not displayed in works controls")

        detail_view = works_controls.find_element_by_css_selector("#ting-openformat-full-view-button-expanded")
        self.assertFalse(detail_view.is_displayed(), "detail view link is not displayed in works controls")

        detail_view_icon = detail_view.find_element_by_css_selector(".svg-view-details")
        self.assertFalse(detail_view_icon.is_displayed(), "detail view icon is not displayed in works controls")

        sort_dropdown = works_controls.find_element_by_css_selector("#bibdk-search-controls-form")
        self.assertFalse(sort_dropdown.is_displayed(), "sort dropdown is displayed in works controls")

        rss_feed = works_controls.find_element_by_css_selector(".ting-openformat-feeds")
        self.assertFalse(rss_feed.is_displayed(), "RSS feed is not displayed in works controls")

        pager_next = works_controls.find_element_by_css_selector(".bibdk-pager-next")


    '''
    PJO 19/05/19 outcomment - FIX IT
    def test_works_controls_small(self):
        """
        Testing visiblity of links in search result controls on small devices
        """
        browser = self.browser
        browser.set_window_size(360, 640)

        url = self.base_url + 'search/work/foo'
        browser.get(url)
        browser.implicitly_wait(5)

        # testing on small size (W:360)

        works_controls = browser.find_element_by_css_selector(".works-controls")

        amount_block = works_controls.find_element_by_css_selector(".ting-openformat-search-amount-block")
        self.assertTrue(amount_block.is_displayed(), "amount block is displayed in works controls")

        list_view = works_controls.find_element_by_css_selector("#ting-openformat-full-view-button-closed")
        self.assertFalse(list_view.is_displayed(), "list view link is not displayed in works controls")

        list_view_icon = list_view.find_element_by_css_selector(".svg-view-list")
        self.assertFalse(list_view_icon.is_displayed(), "list view icon is not displayed in works controls")

        detail_view = works_controls.find_element_by_css_selector("#ting-openformat-full-view-button-expanded")
        self.assertFalse(detail_view.is_displayed(), "detail view link is not displayed in works controls")

        detail_view_icon = detail_view.find_element_by_css_selector(".svg-view-details")
        self.assertFalse(detail_view_icon.is_displayed(), "detail view icon is not displayed in works controls")

        sort_dropdown = works_controls.find_element_by_css_selector("#bibdk-search-controls-form")
        self.assertFalse(sort_dropdown.is_displayed(), "sort dropdown is not displayed in works controls")

        rss_feed = works_controls.find_element_by_css_selector(".ting-openformat-feeds")
        self.assertFalse(rss_feed.is_displayed(), "RSS feed is not displayed in works controls")

        pager_next = works_controls.find_element_by_css_selector(".bibdk-pager-next")
        self.assertFalse(pager_next.is_displayed(), "pager next is displayed in works controls (small)")
     '''
