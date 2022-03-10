from PIL import Image
import pyautogui as pya

pya.PAUSE = 0

im = Image.open("C:/Users/ahmet/Desktop/Scripts[Codedbyme]/index.jpg")
rgb_im = im.convert("RGB")

for x in range(im.size[0]):
    for y in range(im.size[1]):
        r, g, b = rgb_im.getpixel((x, y))
        Y = 0.2126 * r + 0.7152 * g + 0.0722 * b
        if Y <= 80:
            pya.moveTo(x+504, y+322)
        
            