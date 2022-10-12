import pyautogui
import time
import tkinter
import webbrowser
import time

def login():
    # Open the coordinates.txt as read 
    with open('coordinates.txt', 'r') as coords:
        # Check if the line in the coordinates.txt is a valid coordinate or a string 
        for x in ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']:
            # Enumarate the coordinates.txt line by line (implemented from deneme.py)
            for index, line in enumerate(coords):
                # If it has any letter in it, then it is a string
                if x in line:
                    print('wrote')
                else:
                    #Other wise it is an coordinate.
                    print('clicked')
            
login()