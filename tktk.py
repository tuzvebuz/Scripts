import tkinter as tk
import tkinter.font as tkFont
from tkinter import *
class App:
    def __init__(self, root):
        #setting title
        root.title("E-Commerce Ad Software for Murat Yucel")
        #setting window size
        width=900
        height=600
        screenwidth = root.winfo_screenwidth()
        screenheight = root.winfo_screenheight()
        alignstr = '%dx%d+%d+%d' % (width, height, (screenwidth - width) / 2, (screenheight - height) / 2)
        root.geometry(alignstr)
        root.resizable(width=False, height=False)
        # System log
        GLabel_589=tk.Label(root)
        GLabel_589["activebackground"] = "#999999"
        ft = tkFont.Font(family='Helvetica',size=18)
        GLabel_589["font"] = ft
        GLabel_589["fg"] = "#333333"
        GLabel_589["justify"] = "center"
        GLabel_589["text"] = "System Log"
        GLabel_589.place(x=370,y=120,width=244,height=30)
        T = Text(root, height = 5, width = 52)
        T.place(x=350,y=250,width=244,height=50)
        # Start button
        GButton_104=tk.Button(root)
        GButton_104["bg"] = "#e9e9ed"
        ft = tkFont.Font(family='Helvetica',size=20)
        GButton_104["font"] = ft
        GButton_104["fg"] = "#000000"
        GButton_104["justify"] = "center"
        GButton_104["text"] = "Start"
        GButton_104.place(x=400,y=380,width=200,height=55)
        #GButton_104["command"] = self.GButton_104_command
        
        SystemLog = 'System Log will appear here...'
        T.insert(tk.END, SystemLog)
if __name__ == "__main__":
    root = tk.Tk()
    app = App(root)
    root.mainloop()