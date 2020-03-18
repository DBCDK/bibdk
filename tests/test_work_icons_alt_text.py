import helpers


class TestWorkIconsAltText(helpers.BibdkUnitTestCase):
    def test_alt_text(self):
        browser = self.browser
        browser.implicitly_wait(10)
        url = self.base_url + '/search/work/rec.id=820030-katalog%3A626417'
        browser.get(url)
        xpath = '//div[@id="820030katalog626417"]//span[@class="svg-icon"]/*[@alt="Bog"]'
        element = browser.find_element_by_xpath(xpath)
        self.assertEqual(element.get_attribute("title"), "Bog")


