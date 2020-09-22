# -*- coding: utf-8 -*-

###########################################################################
## Python code generated with wxFormBuilder (version Jun 17 2015)
## http://www.wxformbuilder.org/
##
## PLEASE DO "NOT" EDIT THIS FILE!
###########################################################################

import Person
from Person import *
import wxversion
wxversion.select('3.0')
import wx
import wx.xrc
import wx.grid
import cx_Oracle
from datetime import *

###########################################################################
## Class MyFrame2
###########################################################################

# Interaction logic for MyFrame2.
class MyFrame2 ( wx.Frame ):

    #region Fields

    # The selected index.
    __selectedIndexValue = None

    # The id value.
    __idValue = None

    # The name value.
    __nameValue = None

    # The mothername value.
    __mothernameValue = None

    # The location value.
    __locationValue = None

    # The birthdate value.
    __birthdateValue = None

    #endregion Fields

    #region Constructors

    # Initializes a new instance of the MyFrame2 class.
    def __init__( self, parent ):
        wx.Frame.__init__ ( self, parent, id = wx.ID_ANY, title = u"People", pos = wx.DefaultPosition, size = wx.Size( 715,610 ), style = wx.DEFAULT_FRAME_STYLE|wx.TAB_TRAVERSAL )

        self.SetSizeHintsSz( wx.DefaultSize, wx.DefaultSize )
        self.SetBackgroundColour( wx.SystemSettings.GetColour( wx.SYS_COLOUR_SCROLLBAR ) )

        gSizer1 = wx.GridSizer( 1, 2, 0, 170 )

        self.m_grid1 = wx.grid.Grid( self, wx.ID_ANY, wx.DefaultPosition, wx.Size( 430,570 ), wx.HSCROLL|wx.VSCROLL )

        # Grid
        self.m_grid1.CreateGrid( 0, 5 )
        self.m_grid1.EnableEditing( False )
        self.m_grid1.EnableGridLines( True )
        self.m_grid1.EnableDragGridSize( False )
        self.m_grid1.SetMargins( 0, 0 )

        # Columns
        self.m_grid1.EnableDragColMove( False )
        self.m_grid1.EnableDragColSize( True )
        self.m_grid1.SetColLabelSize( 30 )
        self.m_grid1.SetColLabelValue( 0, u"Id" )
        self.m_grid1.SetColLabelValue( 1, u"Name" )
        self.m_grid1.SetColLabelValue( 2, u"Mothername" )
        self.m_grid1.SetColLabelValue( 3, u"Location" )
        self.m_grid1.SetColLabelValue( 4, u"Birthdate" )
        self.m_grid1.SetColLabelAlignment( wx.ALIGN_CENTRE, wx.ALIGN_CENTRE )

        # Rows
        self.m_grid1.EnableDragRowSize( True )
        self.m_grid1.SetRowLabelSize( 0 )
        self.m_grid1.SetRowLabelAlignment( wx.ALIGN_CENTRE, wx.ALIGN_CENTRE )

        # Label Appearance

        # Cell Defaults
        self.m_grid1.SetDefaultCellAlignment( wx.ALIGN_LEFT, wx.ALIGN_TOP )
        gSizer1.Add( self.m_grid1, 0, wx.ALL, 5 )

        gSizer2 = wx.GridSizer( 2, 1, 0, 0 )

        sbSizer1 = wx.StaticBoxSizer( wx.StaticBox( self, wx.ID_ANY, u"Modify:" ), wx.VERTICAL )

        gSizer3 = wx.GridSizer( 2, 1, 0, 0 )

        gSizer5 = wx.GridSizer( 1, 2, 0, 0 )

        gSizer7 = wx.GridSizer( 4, 1, 0, 0 )

        self.m_staticText1 = wx.StaticText( sbSizer1.GetStaticBox(), wx.ID_ANY, u"Name:", wx.DefaultPosition, wx.DefaultSize, 0 )
        self.m_staticText1.Wrap( -1 )
        gSizer7.Add( self.m_staticText1, 1, wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )

        self.m_staticText2 = wx.StaticText( sbSizer1.GetStaticBox(), wx.ID_ANY, u"Mothername:", wx.DefaultPosition, wx.DefaultSize, 0 )
        self.m_staticText2.Wrap( -1 )
        gSizer7.Add( self.m_staticText2, 1, wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )

        self.m_staticText3 = wx.StaticText( sbSizer1.GetStaticBox(), wx.ID_ANY, u"Location:", wx.DefaultPosition, wx.DefaultSize, 0 )
        self.m_staticText3.Wrap( -1 )
        gSizer7.Add( self.m_staticText3, 1, wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )

        self.m_staticText4 = wx.StaticText( sbSizer1.GetStaticBox(), wx.ID_ANY, u"Birthdate:", wx.DefaultPosition, wx.DefaultSize, 0 )
        self.m_staticText4.Wrap( -1 )
        gSizer7.Add( self.m_staticText4, 1, wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )


        gSizer5.Add( gSizer7, 1, wx.EXPAND, 5 )

        gSizer8 = wx.GridSizer( 4, 1, 0, 0 )

        self.m_textCtrl1 = wx.TextCtrl( sbSizer1.GetStaticBox(), wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, 0 )
        gSizer8.Add( self.m_textCtrl1, 1, wx.ALL|wx.EXPAND|wx.ALIGN_CENTER_HORIZONTAL|wx.ALIGN_CENTER_VERTICAL, 5 )

        self.m_textCtrl2 = wx.TextCtrl( sbSizer1.GetStaticBox(), wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, 0 )
        gSizer8.Add( self.m_textCtrl2, 1, wx.ALL|wx.EXPAND|wx.ALIGN_CENTER_HORIZONTAL|wx.ALIGN_CENTER_VERTICAL, 5 )

        self.m_textCtrl3 = wx.TextCtrl( sbSizer1.GetStaticBox(), wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, 0 )
        gSizer8.Add( self.m_textCtrl3, 1, wx.ALL|wx.ALIGN_CENTER_HORIZONTAL|wx.ALIGN_CENTER_VERTICAL|wx.EXPAND, 5 )

        self.m_textCtrl4 = wx.TextCtrl( sbSizer1.GetStaticBox(), wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, 0 )
        gSizer8.Add( self.m_textCtrl4, 1, wx.ALL|wx.ALIGN_CENTER_HORIZONTAL|wx.ALIGN_CENTER_VERTICAL|wx.EXPAND, 5 )


        gSizer5.Add( gSizer8, 1, wx.EXPAND, 5 )


        gSizer3.Add( gSizer5, 1, wx.EXPAND, 5 )

        gSizer6 = wx.GridSizer( 1, 3, 0, 0 )

        self.m_button2 = wx.Button( sbSizer1.GetStaticBox(), wx.ID_ANY, u"Add", wx.DefaultPosition, wx.DefaultSize, 0 )
        gSizer6.Add( self.m_button2, 1, wx.ALL|wx.ALIGN_CENTER_HORIZONTAL|wx.ALIGN_BOTTOM, 5 )

        self.m_button3 = wx.Button( sbSizer1.GetStaticBox(), wx.ID_ANY, u"Edit", wx.DefaultPosition, wx.DefaultSize, 0 )
        gSizer6.Add( self.m_button3, 1, wx.ALL|wx.ALIGN_CENTER_HORIZONTAL|wx.ALIGN_BOTTOM, 5 )

        self.m_button4 = wx.Button( sbSizer1.GetStaticBox(), wx.ID_ANY, u"Delete", wx.DefaultPosition, wx.DefaultSize, 0 )
        gSizer6.Add( self.m_button4, 1, wx.ALL|wx.ALIGN_CENTER_HORIZONTAL|wx.ALIGN_BOTTOM, 5 )


        gSizer3.Add( gSizer6, 1, wx.EXPAND, 5 )


        sbSizer1.Add( gSizer3, 1, wx.EXPAND, 5 )


        gSizer2.Add( sbSizer1, 1, wx.EXPAND|wx.ALIGN_CENTER_HORIZONTAL|wx.ALIGN_CENTER_VERTICAL, 5 )

        gSizer4 = wx.GridSizer( 1, 2, 0, 0 )

        self.m_button1 = wx.Button( self, wx.ID_ANY, u"List", wx.DefaultPosition, wx.DefaultSize, 0 )
        gSizer4.Add( self.m_button1, 1, wx.ALL|wx.ALIGN_BOTTOM, 5 )

        self.m_button5 = wx.Button( self, wx.ID_ANY, u"Close", wx.DefaultPosition, wx.DefaultSize, 0 )
        gSizer4.Add( self.m_button5, 1, wx.ALL|wx.ALIGN_BOTTOM|wx.ALIGN_RIGHT, 5 )


        gSizer2.Add( gSizer4, 1, wx.EXPAND, 5 )


        gSizer1.Add( gSizer2, 1, wx.EXPAND, 5 )


        self.SetSizer( gSizer1 )
        self.Layout()

        self.Centre( wx.BOTH )

        # Connect Events
        self.Bind( wx.EVT_ACTIVATE, self.MyFrame2OnActivate )
        self.m_grid1.Bind( wx.grid.EVT_GRID_SELECT_CELL, self.m_grid1OnGridSelectCell )
        self.m_textCtrl1.Bind( wx.EVT_TEXT, self.m_textCtrl1OnText )
        self.m_textCtrl2.Bind( wx.EVT_TEXT, self.m_textCtrl2OnText )
        self.m_textCtrl3.Bind( wx.EVT_TEXT, self.m_textCtrl3OnText )
        self.m_textCtrl4.Bind( wx.EVT_TEXT, self.m_textCtrl4OnText )
        self.m_button2.Bind( wx.EVT_BUTTON, self.m_button2OnButtonClick )
        self.m_button3.Bind( wx.EVT_BUTTON, self.m_button3OnButtonClick )
        self.m_button4.Bind( wx.EVT_BUTTON, self.m_button4OnButtonClick )
        self.m_button1.Bind( wx.EVT_BUTTON, self.m_button1OnButtonClick )
        self.m_button5.Bind( wx.EVT_BUTTON, self.m_button5OnButtonClick )

    # Deletes the instance of the MyFrame2 class.
    def __del__( self ):
        self.m_mgr.UnInit()

    #endregion Constructors

    #region Methods

    # Gets the data.
    def GetData(self):
        try:
            # Clear existing items.
            if (self.m_grid1.GetNumberRows() - 1 > 0):
                self.m_grid1.DeleteRows(0, self.m_grid1.GetNumberRows())

            # Open a connection to the database.
            __connection = cx_Oracle.connect('root/root@localhost/orcl')

            # Get the items from the People table.
            __people = []
            __cursor = __connection.cursor()

            # Execute.
            __cursor.execute('SELECT * FROM root.People WHERE IsDeleted = 0')

            # Store the items in a Person list.
            for __row in __cursor.fetchall():
                __people.append(__row)

            # Close the cursor and the connection.
            __cursor.close()
            __connection.close()

            # Fill the grid rows with the values of the People table.
            for __oneItem in __people:
                self.m_grid1.AppendRows(1)

                self.m_grid1.SetCellValue(self.m_grid1.GetNumberRows() - 1, 0, str(__oneItem[0]))
                self.m_grid1.SetCellValue(self.m_grid1.GetNumberRows() - 1, 1, str(__oneItem[1]))
                self.m_grid1.SetCellValue(self.m_grid1.GetNumberRows() - 1, 2, str(__oneItem[2]))
                self.m_grid1.SetCellValue(self.m_grid1.GetNumberRows() - 1, 3, str(__oneItem[3]))
                self.m_grid1.SetCellValue(self.m_grid1.GetNumberRows() - 1, 4, str(__oneItem[4]).split(' ')[0])
        except:
            pass

    # Handles the OnActive event of the MyFrame2 control.
    def MyFrame2OnActivate( self, event ):
        # Preset values.
        self.GetData()

    # Handles the OnButtonClick event of the button1 control.
    def m_button1OnButtonClick( self, event ):
        # List the records.
        self.GetData()

    # Handles the OnButtonClick event of the button2 control.
    def m_button2OnButtonClick( self, event ):
        # Add a record.
        try:
            # The fields must not be empty.
            if (self.__nameValue <> None and self.__mothernameValue <> None and self.__locationValue <> None and self.__birthdateValue <> None and
                self.__nameValue <> '' and self.__mothernameValue <> '' and self.__locationValue <> '' and self.__birthdateValue <> ''):
                self.__idValue = 0
                __matchFound = False

                # Open a connection to the database.
                __connection = cx_Oracle.connect('root/root@localhost/orcl')

                # Get the items from the People table.
                __cursor = __connection.cursor()

                # Execute.
                __cursor.execute('SELECT * FROM root.People')

                # Store the items in a Person list.
                for __row in __cursor.fetchall():
                    self.__idValue += 1

                    # Search for a deleted maching item.
                    if (__matchFound == False and str(__row[1]) == self.__nameValue and str(__row[2]) == self.__mothernameValue and
                        str(__row[3]) == self.__locationValue and str(__row[4]).split(' ')[0] == self.__birthdateValue and __row[5] == 1):
                        __matchFound = True
                        self.__idValue = int(__row[0])

                        break

                # Add a new item if no deleted was found else restore the deleted item.
                if (__matchFound == False):
                    # Add new item to the People table.
                    slist = self.__birthdateValue.split('-')
                    __dt = datetime(int(slist[0]), int(slist[1]), int(slist[2]))
                    __cursor.execute('INSERT INTO root.People (Id, Name, Mothername, Location, Birthdate, IsDeleted) VALUES (:param1, :param2, :param3, :param4, :param5, :param6)',
                                     param1 = self.__idValue + 1,
                                     param2 = self.__nameValue,
                                     param3 = self.__mothernameValue,
                                     param4 = self.__locationValue,
                                     param5 = __dt,
                                     param6 = 0)

                    # Execute.
                    __connection.commit()
                else:
                    # Edit the IsDeleted value to false.
                    __cursor.execute('UPDATE root.People SET IsDeleted = :param1 WHERE Id = :param2',
                                     param1 = 0, param2 = self.__idValue)

                    # Execute.
                    __connection.commit()

                # Close the cursor and the connection.
                __cursor.close()
                __connection.close()

                # Refresh.
                self.GetData()
        except:
            pass

    # Handles the OnButtonClick event of the button3 control.
    def m_button3OnButtonClick( self, event ):
        # Edit a record.
        try:
            # The fields must not be empty.
            if (self.__nameValue <> None and self.__mothernameValue <> None and self.__locationValue <> None and self.__birthdateValue <> None and
                self.__nameValue <> '' and self.__mothernameValue <> '' and self.__locationValue <> '' and self.__birthdateValue <> ''):
                # An item must be selected in the grid.
                if (self.__selectedIndexValue >= 0):
                    # Get the Id value of the selected item.
                    self.__idValue = int(self.m_grid1.GetCellValue(self.__selectedIndexValue, 0))

                    # Open a connection to the database.
                    __connection = cx_Oracle.connect('root/root@localhost/orcl')

                    # Get the items from the People table.
                    __cursor = __connection.cursor()

                    # Execute.
                    slist = self.__birthdateValue.split('-')
                    __dt = datetime(int(slist[0]), int(slist[1]), int(slist[2]))
                    __cursor.execute('UPDATE root.People SET Name = :param1, Mothername = :param2, Location = :param3, Birthdate = :param4 WHERE Id = :param5',
                                     param1 = self.__nameValue,
                                     param2 = self.__mothernameValue,
                                     param3 = self.__locationValue,
                                     param4 = __dt,
                                     param5 = self.__idValue)

                    # Execute.
                    __connection.commit()

                    # Close the cursor and the connection.
                    __cursor.close()
                    __connection.close()

                    # Refresh.
                    self.GetData()
        except:
            pass

    # Handles the OnButtonClick event of the button4 control.
    def m_button4OnButtonClick( self, event ):
        # Delete a record.
        try:
            # An item must be selected in the grid.
            if (self.__selectedIndexValue >= 0):
                # Logical Delete
                # Get the Id value of the selected item.
                self.__idValue = int(self.m_grid1.GetCellValue(self.__selectedIndexValue, 0))

                # Open a connection to the database.
                __connection = cx_Oracle.connect('root/root@localhost/orcl')

                # Get the items from the People table.
                __cursor = __connection.cursor()

                # Execute.
                __cursor.execute('UPDATE root.People SET IsDeleted = :param1 WHERE Id = :param2',
                                param1 = 1, param2 = self.__idValue)

                # Execute.
                __connection.commit()

                # Close the cursor and the connection.
                __cursor.close()
                __connection.close()

                # Refresh.
                self.GetData()
        except:
            pass

    # Handles the OnButtonClick event of the button5 control.
    def m_button5OnButtonClick( self, event ):
        # Close the Frame.
        self.Close()

    # Handles the OnGridSelectCell event of the grid1 control.
    def m_grid1OnGridSelectCell( self, event ):
        # An item must be selected in the grid.
        if (event.GetRow() >= 0):
            try:
                # Get the selected index.
                self.__selectedIndexValue = event.GetRow()

                # Give the textControl Values the selected values.
                self.m_textCtrl1.SetValue(self.m_grid1.GetCellValue(self.__selectedIndexValue, 1))
                self.m_textCtrl2.SetValue(self.m_grid1.GetCellValue(self.__selectedIndexValue, 2))
                self.m_textCtrl3.SetValue(self.m_grid1.GetCellValue(self.__selectedIndexValue, 3))
                self.m_textCtrl4.SetValue(self.m_grid1.GetCellValue(self.__selectedIndexValue, 4))
            except:
                # Empty the textControl Values.
                self.m_textCtrl1.SetValue('')
                self.m_textCtrl2.SetValue('')
                self.m_textCtrl3.SetValue('')
                self.m_textCtrl4.SetValue('')
        else:
            # Empty the textControl Values.
            self.m_textCtrl1.SetValue('')
            self.m_textCtrl2.SetValue('')
            self.m_textCtrl3.SetValue('')
            self.m_textCtrl4.SetValue('')

    # Handles the OnText event of the textCtrl1 control.
    def m_textCtrl1OnText( self, event ):
        # Give the field the textControl Text.
        self.__nameValue = str(self.m_textCtrl1.GetValue())

    # Handles the OnText event of the textCtrl2 control.
    def m_textCtrl2OnText( self, event ):
        # Give the field the textControl Text.
        self.__mothernameValue = str(self.m_textCtrl2.GetValue())

    # Handles the OnText event of the textCtrl3 control.
    def m_textCtrl3OnText( self, event ):
        # Give the field the textControl Text.
        self.__locationValue = str(self.m_textCtrl3.GetValue())

    # Handles the OnText event of the textCtrl4 control.
    def m_textCtrl4OnText( self, event ):
        # Give the field the textControl Text.
        self.__birthdateValue = str(self.m_textCtrl4.GetValue())

    #endregion Methods