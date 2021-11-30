import pprint
import smtplib

key = 'Your API key'

from requests import Request, Session
from requests.exceptions import ConnectionError, Timeout, TooManyRedirects
import json

url = 'https://pro-api.coinmarketcap.com/v1/cryptocurrency/quotes/latest'

parameteres = {
    'slug': 'bitcoin',
    'convert': 'USD'
}

headers = {
    'Accepts': 'application/json',
    'X-CMC_PRO_API_KEY': key
}

session = Session()
session.headers.update(headers)


response = session.get(url, params=parameteres)
data = json.loads(response.text)
pprint.pprint(data['data']['1']['quote']['USD'])

price = float(1)
stats = data['data']['1']['quote']['USD']['price']
if data['data']['1']['quote']['USD']['price'] > price:
    sender_email = "your email"
    receiver_email = "The target e-mail adress"
    password = str(input("Type your password and press enter: "))
    message = 'Basic E-mail'
    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.starttls()
    server.login(sender_email, password)
    server.sendmail(sender_email, receiver_email, message)
    print(f'An e-mail has been sent to {receiver_email}')
