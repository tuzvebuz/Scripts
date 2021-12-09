import time
from PIL import ImageGrab
import pytesseract
import matplotlib.pyplot as mt
import numpy as np
import pyautogui
import cv2
import fileinput

pytesseract.pytesseract.tesseract_cmd = 'pytesseract executable path'


def convertandtype():
    time.sleep(5)
    cap = ImageGrab.grab(bbox=(106, 294, 853, 515))
    tesstr = pytesseract.image_to_string(
        cv2.cvtColor(np.array(cap), cv2.COLOR_BGR2GRAY),
        lang='eng')
    print(tesstr)
    script = open('text.txt', 'w')
    script.write(tesstr)
    script = open('text.txt', 'r')
    for word in script:
        if not word.isspace():
            pyautogui.write(word, interval=0.08


convertandtype()
