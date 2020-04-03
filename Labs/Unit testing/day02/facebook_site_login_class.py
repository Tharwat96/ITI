import unittest
import os
import secrets
from selenium import webdriver
from selenium.webdriver.common.keys import Keys


class TestFacebookComLogin(unittest.TestCase):

    def setUp(self):
        self.driver = webdriver.Chrome()

    def test_login_in_facebook_com(self):
        EMAIL = secrets.EMAIL
        PASSWORD = secrets.PASSWORD
        driver = self.driver
        driver.get("http:/www.facebook.com")
        assert "Facebook" in driver.title
        email = driver.find_element_by_id('email')
        email.clear()
        email.send_keys(EMAIL)
        password = driver.find_element_by_id('pass')
        password.clear()
        password.send_keys(PASSWORD)
        password.send_keys(Keys.RETURN)
        assert "Notifications" in driver.page_source

    def tearDown(self):
        self.driver.quit()


if __name__ == '__main__':
    unittest.main()
