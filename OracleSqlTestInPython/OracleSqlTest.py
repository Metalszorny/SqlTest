from MyFrame1 import *

# The main method of the application.
if __name__ == '__main__':
    __app = wx.App(False)
    __menu = MyFrame1(None)
    __menu.Show()
    __app.MainLoop()