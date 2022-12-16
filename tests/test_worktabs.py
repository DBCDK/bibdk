# Coding needed to tell nosetests about encode of Danish characters.
# -*- coding: utf-8 -*-

from selenium.webdriver.common.by import By
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions
import helpers
from functools import reduce
import time


class TestWorktabs(helpers.BibdkUnitTestCase):
    '''Test that is loaded and if a tab has empty content the text of the
       corresponding toggle button will reflect this. '''

    def test_double(self):
        '''Get "Lev livet uden frygt og angst - find ro i sindet" by Patrick
           McKeown which is missing both types of reviews'''
        self.wid = ['870970', 'basis', '50980235']
        self.load_reviews(1)

    def load_worktab(self, get_tab):
        '''Load a work, opens a specific worktab, and find elements with no
        content'''
        browser = self.browser
        wait = WebDriverWait(browser, 15)
        browser.get(self.base_url)
        search = browser.find_element(By.ID, 'edit-search-block-form--2')
        search.send_keys('rec.id=' + self.rec_id())
        browser.find_element(By.ID, 'edit-submit').click()
        browser.find_element(By.ID, self.work_href()).click()
        WebDriverWait(browser, 15).until(expected_conditions.presence_of_element_located((By.CSS_SELECTOR, '.worktabs')))
        forms = browser.find_elements(By.CSS_SELECTOR, get_tab() + ' .tab-content form')
        browser.find_element(By.CSS_SELECTOR, 'a[href="' + get_tab() + '"]').click()
        # Asyncronous loading and no more waiting than 15 seconds in total
        # Check for removal of forms used for triggering ajax call
        WebDriverWait(browser, 15).until(lambda a: reduce(lambda b,e: expected_conditions.staleness_of(e)(None) and b, forms, True))
        return browser.find_elements(By.CSS_SELECTOR, '.worktabs-no-content')

    def load_reviews(self, count):
        no_contents = self.load_worktab(self.reviews_href)
        self.assertEqual(len(no_contents), count, str(count) + ' element(s) with class worktabs-no-content was found.')
        for no in no_contents:
            ancestor = no.find_element(By.XPATH, '../../..')
            button_txts = ancestor.find_elements(By.CLASS_NAME, ('toggle-text')
            self.assertEqual(len(button_txts), 1, 'Two button texts found.')
            i = 1
            no_text = no.get_attribute('data-button-txt')
            for t in button_txts:
                # use attribute innerHTML because text is empty for hidden element
                self.assertEqual(t.get_attribute('innerHTML'), no_text, 'Button text changed (iteration ' + str(i) + ')')
                i += 1

    def rec_id(self):
        return self.wid[0] + '-' + self.wid[1] + ':' + self.wid[2]

    def work_href(self):
        return 'selid-' + self.wid[0] + self.wid[1] + self.wid[2]

    def reviews_href(self):
        return '#reviews' + self.wid[0] + '_' + self.wid[1] + '_' + self.wid[2]

    def more_about_href(self):
        return '#more-about' + self.wid[0] + '_' + self.wid[1] + '_' + self.wid[2]

    ''' This test does not work, because it does have 'Bog'
    def test_more_about(self):
        #Get "Underretning om Skælskør Købstad 1759" by Peder Edvardsen Friis
        #which has no data for further search.
        self.wid = ['870970', 'basis', '05990572']
        self.load_further(1)


    def load_further(self, count):
        no_contents = self.load_worktab(self.more_about_href)
        self.assertEqual(len(no_contents), count, str(count) + ' element(s) with class worktabs-no-content was found.')
        for no in no_contents:
            ancestor = no.find_element(By.XPATH, '../..')
            button_txts = ancestor.find_elements(By.CLASS_NAME, ('toggle-text')
            self.assertEqual(len(button_txts), 1, 'Three button texts found.' +
            str(len(button_txts)))
            i = 1
            no_text = no.get_attribute('data-button-txt')
            for t in button_txts:
                # use attribute innerHTML because text is empty for hidden element
                self.assertEqual(t.get_attribute('innerHTML'), no_text, 'Button text changed (iteration ' + str(i) + ')')
                i += 1
    '''

    def test_subjects_below_abstract_in_tab(self):
        browser = self.browser
        browser.get(self.base_url + "work/870970-basis:28373988")
        wait = WebDriverWait(browser, 30)

        # ensure we have reviews and more-about tabs available
        browser.find_element(By.ID, "more-about")
        browser.find_element(By.ID, "reviews")
        self.assertFalse(self._id_is_present("subjects"), "subjects tab not found")

        # ensure both abstract and subjects are visible
        info = browser.find_element(By.ID, 'basic-information870970_basis_28373988')
        self.assertTrue(self._class_is_present("work-abstract", info), "found abstract")
        self.assertTrue(self._class_is_present("work-subject", info), "found subjects")
