# -*- coding: utf-8 -*-

###########################################################################
## Python code generated with wxFormBuilder (version Jun 17 2015)
## http://www.wxformbuilder.org/
##
## PLEASE DO "NOT" EDIT THIS FILE!
###########################################################################

from MyFrame2 import *
from MyFrame3 import *
from MyFrame4 import *
import wxversion
wxversion.select('3.0')
import wx
import wx.xrc

###########################################################################
## Class MyFrame1
###########################################################################

# Interaction logic for MyFrame1.
class MyFrame1 ( wx.Frame ):

    #region Constructors

    # Initializes a new instance of the MyFrame1 class.
    def __init__( self, parent ):
        wx.Frame.__init__ ( self, parent, id = wx.ID_ANY, title = u"Menu", pos = wx.DefaultPosition, size = wx.Size( 230, 300 ), style = wx.DEFAULT_FRAME_STYLE|wx.TAB_TRAVERSAL )

        self.SetSizeHintsSz( wx.DefaultSize, wx.DefaultSize )
        self.SetBackgroundColour( wx.SystemSettings.GetColour( wx.SYS_COLOUR_SCROLLBAR ) )

        gSizer1 = wx.GridSizer( 9, 1, 0, 0 )

        gSizer2 = wx.GridSizer( 1, 1, 0, 0 )


        gSizer1.Add( gSizer2, 1, wx.EXPAND, 5 )

        self.m_button1 = wx.Button( self, wx.ID_ANY, u"People", wx.DefaultPosition, wx.DefaultSize, 0 )
        gSizer1.Add( self.m_button1, 1, wx.ALIGN_CENTER_HORIZONTAL|wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )

        gSizer3 = wx.GridSizer( 1, 1, 0, 0 )


        gSizer1.Add( gSizer3, 1, wx.EXPAND, 5 )

        self.m_button2 = wx.Button( self, wx.ID_ANY, u"Relationships", wx.DefaultPosition, wx.DefaultSize, 0 )
        gSizer1.Add( self.m_button2, 1, wx.ALIGN_CENTER_HORIZONTAL|wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )

        gSizer4 = wx.GridSizer( 1, 1, 0, 0 )


        gSizer1.Add( gSizer4, 1, wx.EXPAND, 5 )

        self.m_button3 = wx.Button( self, wx.ID_ANY, u"Relations", wx.DefaultPosition, wx.DefaultSize, 0 )
        gSizer1.Add( self.m_button3, 1, wx.ALIGN_CENTER_HORIZONTAL|wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )

        gSizer5 = wx.GridSizer( 1, 1, 0, 0 )


        gSizer1.Add( gSizer5, 1, wx.EXPAND, 5 )

        self.m_button4 = wx.Button( self, wx.ID_ANY, u"Exit", wx.DefaultPosition, wx.DefaultSize, 0 )
        gSizer1.Add( self.m_button4, 1, wx.ALIGN_CENTER_HORIZONTAL|wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )

        gSizer6 = wx.GridSizer( 1, 1, 0, 0 )


        gSizer1.Add( gSizer6, 1, wx.EXPAND, 5 )


        self.SetSizer( gSizer1 )
        self.Layout()

        self.Centre( wx.BOTH )

        # Connect Events
        self.m_button1.Bind( wx.EVT_BUTTON, self.m_button1OnButtonClick )
        self.m_button2.Bind( wx.EVT_BUTTON, self.m_button2OnButtonClick )
        self.m_button3.Bind( wx.EVT_BUTTON, self.m_button3OnButtonClick )
        self.m_button4.Bind( wx.EVT_BUTTON, self.m_button4OnButtonClick )

    # Deletes the instance of the MyFrame1 class.
    def __del__( self ):
        self.m_mgr.UnInit()

    #endregion Constructors

    #region Methods

    # Handles the Click event of the button1 control.
    def m_button1OnButtonClick( self, event ):
        # Open the People Frame.
        __people = MyFrame2(None)
        __people.Show()

    # Handles the Click event of the button2 control.
    def m_button2OnButtonClick( self, event ):
        # Open the Relationships Frame.
        __relationships = MyFrame3(None)
        __relationships.Show()

    # Handles the Click event of the button3 control.
    def m_button3OnButtonClick( self, event ):
        # Open the Relations Frame.
        __relations = MyFrame4(None)
        __relations.Show()

    # Handles the Click event of the button4 control.
    def m_button4OnButtonClick( self, event ):
        # Exit the Program.
        self.Close()

    #endregion Methods