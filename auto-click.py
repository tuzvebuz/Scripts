import pyautogui
f = open('script', 'r')
for word in f:
    pyautogui.typewrite(word)
    pyautogui.press('enter')