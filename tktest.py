class RedirectText(object):
    def __init__(self, text_widget):
        """Constructor"""
        self.output = text_widget

    def write(self, string):
        """Add text to the end and scroll to the end"""
        self.output.insert('end', string)
        self.output.see('end')
        self.output.update_idletasks()
from tkinter import *
import tkinter as tk
 
root = Tk()
 
# specify size of window.
root.geometry("250x170")
 
# Create text widget and specify size.
T = Text(root, height = 5, width = 52)
 
# Create label
l = Label(root, text = "Fact of the Day")
l.config(font =("Courier", 14))
 
Fact = """A man can be arrested in
Italy for wearing a skirt in public."""
 
# Create button for next text.
\
 
# Create an Exit button.
\
 
l.pack()
T.pack()

 
# Insert The Fact.
T.insert(tk.END, Fact)
 
tk.mainloop()