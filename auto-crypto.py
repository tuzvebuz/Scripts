import pprint
import smtplib

key = '4e53ea0b-8683-4793-b9a6-e730662db6fa'

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

stats = data['data']['1']['quote']['USD']['price']
print(stats)
