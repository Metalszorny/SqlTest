# -*- coding: utf-8 -*-

###########################################################################
## Python code generated with wxFormBuilder (version Jun 17 2015)
## http://www.wxformbuilder.org/
##
## PLEASE DO "NOT" EDIT THIS FILE!
###########################################################################

import Relationship
from Relationship import *
import wxversion
wxversion.select('3.0')
import wx
import wx.xrc
import wx.grid
import mysql.connector

###########################################################################
## Class MyFrame3
###########################################################################

# Interaction logic for MyFrame3.
class MyFrame3 ( wx.Frame ):

	#region Fields

	# The selected index.
	__selectedIndexValue = None

	# The id value.
	__idValue = None

	# The name value.
	__nameValue = None

	#endregion Fields

	#region Constructors

	# Initializes a new instance of the MyFrame3 class.
	def __init__( self, parent ):
		wx.Frame.__init__ ( self, parent, id = wx.ID_ANY, title = u"Relationships", pos = wx.DefaultPosition, size = wx.Size( 715,610 ), style = wx.DEFAULT_FRAME_STYLE|wx.TAB_TRAVERSAL )

		self.SetSizeHintsSz( wx.DefaultSize, wx.DefaultSize )
		self.SetBackgroundColour( wx.SystemSettings.GetColour( wx.SYS_COLOUR_SCROLLBAR ) )

		gSizer1 = wx.GridSizer( 1, 2, 0, 170 )

		self.m_grid1 = wx.grid.Grid( self, wx.ID_ANY, wx.DefaultPosition, wx.Size( 430,570 ), wx.HSCROLL|wx.VSCROLL )

		# Grid
		self.m_grid1.CreateGrid( 0, 2 )
		self.m_grid1.EnableEditing( False )
		self.m_grid1.EnableGridLines( True )
		self.m_grid1.EnableDragGridSize( False )
		self.m_grid1.SetMargins( 0, 0 )

		# Columns
		self.m_grid1.EnableDragColMove( False )
		self.m_grid1.EnableDragColSize( True )
		self.m_grid1.SetColLabelSize( 30 )
		self.m_grid1.SetColLabelValue( 0, u"Id" )
		self.m_grid1.SetColLabelValue( 1, u"Type" )
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

		self.m_staticText1 = wx.StaticText( sbSizer1.GetStaticBox(), wx.ID_ANY, u"Type:", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText1.Wrap( -1 )
		gSizer7.Add( self.m_staticText1, 1, wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )


		gSizer5.Add( gSizer7, 1, wx.EXPAND, 5 )

		gSizer8 = wx.GridSizer( 4, 1, 0, 0 )

		self.m_textCtrl1 = wx.TextCtrl( sbSizer1.GetStaticBox(), wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, 0 )
		gSizer8.Add( self.m_textCtrl1, 1, wx.ALL|wx.EXPAND|wx.ALIGN_CENTER_VERTICAL|wx.ALIGN_CENTER_HORIZONTAL, 5 )


		gSizer5.Add( gSizer8, 1, wx.EXPAND, 5 )


		gSizer3.Add( gSizer5, 1, wx.EXPAND, 5 )

		gSizer6 = wx.GridSizer( 1, 3, 0, 0 )

		self.m_button2 = wx.Button( sbSizer1.GetStaticBox(), wx.ID_ANY, u"Add", wx.DefaultPosition, wx.DefaultSize, 0 )
		gSizer6.Add( self.m_button2, 1, wx.ALL|wx.ALIGN_CENTER_HORIZONTAL|wx.ALIGN_BOTTOM, 5 )

		self.m_button3 = wx.Button( sbSizer1.GetStaticBox(), wx.ID_ANY, u"Edit", wx.DefaultPosition, wx.DefaultSize, 0 )
		gSizer6.Add( self.m_button3, 1, wx.ALL|wx.ALIGN_CENTER_HORIZONTAL|wx.ALIGN_BOTTOM, 5 )

		self.m_button4 = wx.Button( sbSizer1.GetStaticBox(), wx.ID_ANY, u"Delete", wx.DefaultPosition, wx.DefaultSize, 0 )
		gSizer6.Add( self.m_button4, 1, wx.ALL|wx.ALIGN_BOTTOM|wx.ALIGN_CENTER_HORIZONTAL, 5 )


		gSizer3.Add( gSizer6, 1, wx.EXPAND, 5 )


		sbSizer1.Add( gSizer3, 1, wx.EXPAND, 5 )


		gSizer2.Add( sbSizer1, 1, wx.EXPAND, 5 )

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
		self.Bind( wx.EVT_ACTIVATE, self.MyFrame3OnActivate )
		self.m_grid1.Bind( wx.grid.EVT_GRID_SELECT_CELL, self.m_grid1OnGridSelectCell )
		self.m_textCtrl1.Bind( wx.EVT_TEXT, self.m_textCtrl1OnText )
		self.m_button2.Bind( wx.EVT_BUTTON, self.m_button2OnButtonClick )
		self.m_button3.Bind( wx.EVT_BUTTON, self.m_button3OnButtonClick )
		self.m_button4.Bind( wx.EVT_BUTTON, self.m_button4OnButtonClick )
		self.m_button1.Bind( wx.EVT_BUTTON, self.m_button1OnButtonClick )
		self.m_button5.Bind( wx.EVT_BUTTON, self.m_button5OnButtonClick )

	# Deletes the instance of the MyFrame3 class.
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
			__connection = mysql.connector.connect(user='root', password='root', host='localhost', database='MySqlTestDatabase')

			# Get the items from the Relationships table.
			__relationships = []
			__cursor = __connection.cursor()

			# Execute.
			__cursor.execute('SELECT * FROM MySqlTestDatabase.Relationships WHERE IsDeleted = 0')

			# Store the items in a Relationship list.
			for __row in __cursor.fetchall():
				__relationships.append(__row)

			# Close the cursor and the connection.
			__cursor.close()
			__connection.close()

			# Fill the grid rows with the values of the Relationships table.
			for __oneItem in __relationships:
				self.m_grid1.AppendRows(1)

				self.m_grid1.SetCellValue(self.m_grid1.GetNumberRows() - 1, 0, str(__oneItem[0]))
				self.m_grid1.SetCellValue(self.m_grid1.GetNumberRows() - 1, 1, str(__oneItem[1]))
		except:
			pass

	# Handles the OnActive event of the MyFrame3 control.
	def MyFrame3OnActivate( self, event ):
		# Preset values.
		self.GetData()

	# Handles the OnGridSelectCell event of the grid1 control.
	def m_grid1OnGridSelectCell( self, event ):
		# An item must be selected in the grid.
		if (event.GetRow() >= 0):
			try:
				# Get the selected index.
				self.__selectedIndexValue = event.GetRow()

				# Give the textControl Values the selected values.
				self.m_textCtrl1.SetValue(self.m_grid1.GetCellValue(self.__selectedIndexValue, 1))
			except:
				# Empty the textControl Values.
				self.m_textCtrl1.SetValue('')
		else:
			# Empty the textControl Values.
			self.m_textCtrl1.SetValue('')

	# Handles the OnText event of the textCtrl1 control.
	def m_textCtrl1OnText( self, event ):
		# Give the field the textControl Text.
		self.__nameValue = str(self.m_textCtrl1.GetValue())

	# Handles the OnButtonClick event of the button2 control.
	def m_button2OnButtonClick( self, event ):
		# Add a record.
		try:
			# The fields must not be empty.
			if (self.__nameValue <> None and self.__nameValue <> ''):
				self.__idValue = 0
				__matchFound = False
				__deletedFound = False

				# Open a connection to the database.
				__connection = mysql.connector.connect(user='root', password='root', host='localhost', database='MySqlTestDatabase')

				# Get the items from the Relationships table.
				__cursor = __connection.cursor()

				# Execute.
				__cursor.execute('SELECT * FROM MySqlTestDatabase.Relationships')

				# Store the items in a Relationships list.
				for __row in __cursor.fetchall():
					self.__idValue += 1

					# Check if the new item already exists.
					if (__matchFound == False and str(__row[1]) == self.__nameValue and __row[2] == False):
						__matchFound = True

						break

					# Check if a deleted already exists.
					if (__deletedFound == False and str(__row[1]) == self.__nameValue and __row[2] == True):
						__deletedFound = True
						self.__idValue = int(__row[0])

						break

				# If no match was found.
				if (__matchFound == False):
					# Add a new item if no deleted match found else restore the deleted item.
					if (__deletedFound == False):
						# Add new item to the Relationships table.
						__cursor.execute('INSERT INTO MySqlTestDatabase.Relationships (Id, Name, IsDeleted) VALUES (%s, %s, %s)',
										(self.__idValue + 1, self.__nameValue, False))

						# Execute.
						__connection.commit()
					else:
						# Edit the IsDeleted value to false.
						__cursor.execute('UPDATE MySqlTestDatabase.Relationships SET IsDeleted = %s WHERE Id = %s',
										(False, self.__idValue))

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
				__connection = mysql.connector.connect(user='root', password='root', host='localhost', database='MySqlTestDatabase')

				# Get the items from the Relationships table.
				__cursor = __connection.cursor()

				# Execute.
				__cursor.execute('UPDATE MySqlTestDatabase.Relationships SET IsDeleted = %s WHERE Id = %s',
								(True, self.__idValue))

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
			if (self.__nameValue <> None and self.__nameValue <> ''):
				# An item must be selected in the grid.
				if (self.__selectedIndexValue >= 0):
					# Get the Id value of the selected item.
					self.__idValue = int(self.m_grid1.GetCellValue(self.__selectedIndexValue, 0))

					# Open a connection to the database.
					__connection = mysql.connector.connect(user='root', password='root', host='localhost', database='MySqlTestDatabase')

					# Get the items from the Relationships table.
					__cursor = __connection.cursor()

					# Execute.
					__cursor.execute('UPDATE MySqlTestDatabase.Relationships SET Name = %s WHERE Id = %s',
                                     (self.__nameValue, self.__idValue))

					# Execute.
					__connection.commit()

					# Close the cursor and the connection.
					__cursor.close()
					__connection.close()

					# Refresh.
					self.GetData()
		except:
			pass

	# Handles the OnButtonClick event of the button1 control.
	def m_button1OnButtonClick( self, event ):
		# List the records.
		self.GetData()

	# Handles the OnButtonClick event of the button5 control.
	def m_button5OnButtonClick( self, event ):
		# Close the Frame.
		self.Close()

	#endregion Methods