import smtplib, ssl
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.application import MIMEApplication
from PIL import ImageDraw, ImageFont, Image
message = MIMEMultipart('mixed')

class make_receipt():
    def receipt():
        img = Image.open('receipt.JPG')
        draw = ImageDraw.Draw(img)
        font = ImageFont.truetype('Mulish-VariableFont_wdht.tff', 16)
        x = 1
        y = 2
        draw.text((x, y), '', font=font)
    def send(send_to='al1hesap@yandex.com', sender='davesunzonsol@gmail.com'
             , subject='', files=None):
        password = str(input('Enter your e-mail password: '))
        message['To'] = 'al1hesap@yandex.com'
        message['From'] = 'davesunzonsol@gmail.com'
        message['Subject'] = 'Test'
        message['CC'] = 'al1hesap@yandex.com'
        msg_content = '<h4>Hi There,<br> This is a testing message.</h4>\n'
        body = MIMEText(msg_content, 'html')
        message.attach(body)
        path = 'C:/Users/ahmet/Desktop/Scripts [Coded by me]/whatthedogdoin.jpg'
        with open(path, 'rb') as attachment:
            p = MIMEApplication(attachment.read(), _subtype="jpg")
            p.add_header('Content-Disposition', "attachment; filename= %s" % path.split("\\")[-1])
            message.attach(p)
        context = ssl.create_default_context()
        msg_full = message.as_string()
        server = smtplib.SMTP('smtp.gmail.com', 587)
        server.ehlo()
        server.starttls(context=context)
        server.login(user='davesunzonsol@gmail.com', password=password)
        server.sendmail(sender,
                        send_to.split(";"),
                        msg_full)
        print('A message has been sent')
        server.quit()   


    send()
