import requests
from requests import Request, Session
import webbrowser

#'139.162.182.54:49165
#'139.162.182.54:49165'


def sending_request(session, proxy):
    try:
        response = session.get('http://httpbin.org/ip', proxies={'http': f"http://{proxy}"})
        print(response.json())
    except:
        pass
with requests.Session() as session:
    sending_request(session, '139.162.182.54:49165')
    webbrowser.open('https://www.amazon.com/ap/signin?openid.pape.max_auth_age=0&openid.return_to=https%3A%2F%2Fwww.amazon.com%2Flog%2Fs%3Fk%3Dlog%2Bin%26ref_%3Dnav_signin&openid.identity=http%3A%2F%2Fspecs.openid.net%2Fauth%2F2.0%2Fidentifier_select&openid.assoc_handle=usflex&openid.mode=checkid_setup&openid.claimed_id=http%3A%2F%2Fspecs.openid.net%2Fauth%2F2.0%2Fidentifier_select&openid.ns=http%3A%2F%2Fspecs.openid.net%2Fauth%2F2.0&')