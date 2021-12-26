import time
import requests
from selenium import webdriver
import pyautogui
print("Please don't click off the tab that will be opened. If you have a problem with the script there will be a"
      "option to e-mail the owner after the process. Thank you for buying, have a nice day.")
code = str(input('Does the creator have a discount code? Type "No" if he/she does not own a code and "Yes" If he/she does.'))
driver = webdriver.Firefox()
if code == 'No':
    pass
elif code == 'Yes':
    disc = str(input('Please type the discount code. [CAPITAL SENSITIVE!]'))
driver = webdriver.Firefox()
url = 'https://youtooz.com/'
driver.get(url)
driver.maximize_window()
def add_to_cart():
    try:
        click = driver.find_element_by_xpath('/html/body/main/div/div[1]/div/div[2]/div/div[1]/a')
        click.click()
        time.sleep(4)
        cart = driver.find_element_by_xpath(
            '/html/body/div[4]/div/div[2]/div/div[3]/div/div[2]/div/form/div[2]/div/div[2]/div/button')
        cart.click()
        time.sleep(2)
        shop_cart = driver.find_element_by_xpath('/html/body/div[4]/div/div[3]/div/div/div/a')
        shop_cart.click()
    except DeprecationWarning:
        print('Going through the process...')


def checkout():
    time.sleep(2)
    if code == 'No':
        pass
    elif code == 'Yes':
        pyautogui.click(600, 637)
        pyautogui.typewrite(disc)
    pyautogui.click(1200, 637)
add_to_cart()
checkout()



# TODO
# credit = input('Please put your card number: ')
# cvv = input('Please put your CVV Here: ')
# shipping_info = {}
