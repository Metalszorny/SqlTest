# -*- coding: utf-8 -*-

###########################################################################
## Python code generated with wxFormBuilder (version Jun 17 2015)
## http://www.wxformbuilder.org/
##
## PLEASE DO "NOT" EDIT THIS FILE!
###########################################################################

import Person
from Person import *
import Relationship
from Relationship import *
import Relation
from Relation import *
import wxversion
wxversion.select('3.0')
import wx
import wx.xrc
import wx.grid
import pymssql

###########################################################################
## Class MyFrame4
###########################################################################

# Interaction logic for MyFrame4.
class MyFrame4 ( wx.Frame ):

	#region Fields

	# The selected index.
	__selectedIndexValue = None

	# The id value.
	__idValue = None

	# The name1 value.
	__name1Value = None

	# The relationship value.
	__relationshipValue = None

	# The name2 value.
	__name2Value = None

	#endregion Fields

	#region Constructors

    # Initializes a new instance of the MyFrame4 class.
	def __init__( self, parent ):
		wx.Frame.__init__ ( self, parent, id = wx.ID_ANY, title = u"Relations", pos = wx.DefaultPosition, size = wx.Size( 715,610 ), style = wx.DEFAULT_FRAME_STYLE|wx.TAB_TRAVERSAL )

		self.SetSizeHintsSz( wx.DefaultSize, wx.DefaultSize )
		self.SetBackgroundColour( wx.SystemSettings.GetColour( wx.SYS_COLOUR_SCROLLBAR ) )

		gSizer1 = wx.GridSizer( 1, 2, 0, 170 )

		self.m_grid1 = wx.grid.Grid( self, wx.ID_ANY, wx.DefaultPosition, wx.Size( 430,570 ), wx.HSCROLL|wx.WANTS_CHARS )

		# Grid
		self.m_grid1.CreateGrid( 0, 4 )
		self.m_grid1.EnableEditing( False )
		self.m_grid1.EnableGridLines( True )
		self.m_grid1.EnableDragGridSize( False )
		self.m_grid1.SetMargins( 0, 0 )

		# Columns
		self.m_grid1.EnableDragColMove( False )
		self.m_grid1.EnableDragColSize( True )
		self.m_grid1.SetColLabelSize( 30 )
		self.m_grid1.SetColLabelValue( 0, u"Id" )
		self.m_grid1.SetColLabelValue( 1, u"Person1" )
		self.m_grid1.SetColLabelValue( 2, u"Relationship" )
		self.m_grid1.SetColLabelValue( 3, u"Person2" )
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

		gSizer7 = wx.GridSizer( 1, 2, 0, 0 )

		gSizer9 = wx.GridSizer( 4, 1, 0, 0 )

		self.m_staticText1 = wx.StaticText( sbSizer1.GetStaticBox(), wx.ID_ANY, u"Person1:", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText1.Wrap( -1 )
		gSizer9.Add( self.m_staticText1, 1, wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )

		self.m_staticText2 = wx.StaticText( sbSizer1.GetStaticBox(), wx.ID_ANY, u"Relationship:", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText2.Wrap( -1 )
		gSizer9.Add( self.m_staticText2, 1, wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )

		self.m_staticText3 = wx.StaticText( sbSizer1.GetStaticBox(), wx.ID_ANY, u"Person2:", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText3.Wrap( -1 )
		gSizer9.Add( self.m_staticText3, 1, wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )


		gSizer7.Add( gSizer9, 1, wx.EXPAND, 5 )

		gSizer10 = wx.GridSizer( 4, 1, 0, 0 )

		m_comboBox1Choices = []
		self.m_comboBox1 = wx.ComboBox( sbSizer1.GetStaticBox(), wx.ID_ANY, u"Combo!", wx.DefaultPosition, wx.DefaultSize, m_comboBox1Choices, 0 )
		gSizer10.Add( self.m_comboBox1, 1, wx.ALL|wx.ALIGN_CENTER_HORIZONTAL|wx.ALIGN_CENTER_VERTICAL|wx.EXPAND, 5 )

		m_comboBox2Choices = []
		self.m_comboBox2 = wx.ComboBox( sbSizer1.GetStaticBox(), wx.ID_ANY, u"Combo!", wx.DefaultPosition, wx.DefaultSize, m_comboBox2Choices, 0 )
		gSizer10.Add( self.m_comboBox2, 1, wx.ALL|wx.ALIGN_CENTER_HORIZONTAL|wx.ALIGN_CENTER_VERTICAL|wx.EXPAND, 5 )

		m_comboBox3Choices = []
		self.m_comboBox3 = wx.ComboBox( sbSizer1.GetStaticBox(), wx.ID_ANY, u"Combo!", wx.DefaultPosition, wx.DefaultSize, m_comboBox3Choices, 0 )
		gSizer10.Add( self.m_comboBox3, 1, wx.ALL|wx.EXPAND|wx.ALIGN_CENTER_VERTICAL|wx.ALIGN_CENTER_HORIZONTAL, 5 )


		gSizer7.Add( gSizer10, 1, wx.EXPAND, 5 )


		gSizer3.Add( gSizer7, 1, wx.EXPAND, 5 )

		gSizer8 = wx.GridSizer( 1, 3, 0, 0 )

		self.m_button2 = wx.Button( sbSizer1.GetStaticBox(), wx.ID_ANY, u"Add", wx.DefaultPosition, wx.DefaultSize, 0 )
		gSizer8.Add( self.m_button2, 1, wx.ALL|wx.ALIGN_BOTTOM|wx.ALIGN_CENTER_HORIZONTAL, 5 )

		self.m_button3 = wx.Button( sbSizer1.GetStaticBox(), wx.ID_ANY, u"Edit", wx.DefaultPosition, wx.DefaultSize, 0 )
		gSizer8.Add( self.m_button3, 1, wx.ALL|wx.ALIGN_CENTER_HORIZONTAL|wx.ALIGN_BOTTOM, 5 )

		self.m_button4 = wx.Button( sbSizer1.GetStaticBox(), wx.ID_ANY, u"Delete", wx.DefaultPosition, wx.DefaultSize, 0 )
		gSizer8.Add( self.m_button4, 1, wx.ALL|wx.ALIGN_CENTER_HORIZONTAL|wx.ALIGN_BOTTOM, 5 )


		gSizer3.Add( gSizer8, 1, wx.EXPAND, 5 )


		sbSizer1.Add( gSizer3, 1, wx.EXPAND, 5 )


		gSizer2.Add( sbSizer1, 1, wx.EXPAND, 5 )

		gSizer4 = wx.GridSizer( 2, 1, 0, 0 )

		sbSizer2 = wx.StaticBoxSizer( wx.StaticBox( self, wx.ID_ANY, u"Helper:" ), wx.VERTICAL )

		gSizer6 = wx.GridSizer( 1, 2, 0, 0 )

		gSizer11 = wx.GridSizer( 4, 1, 0, 0 )

		self.m_staticText4 = wx.StaticText( sbSizer2.GetStaticBox(), wx.ID_ANY, u"Person1:", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText4.Wrap( -1 )
		gSizer11.Add( self.m_staticText4, 1, wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )

		self.m_staticText5 = wx.StaticText( sbSizer2.GetStaticBox(), wx.ID_ANY, u"Relationship:", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText5.Wrap( -1 )
		gSizer11.Add( self.m_staticText5, 1, wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )

		self.m_staticText6 = wx.StaticText( sbSizer2.GetStaticBox(), wx.ID_ANY, u"Person2:", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText6.Wrap( -1 )
		gSizer11.Add( self.m_staticText6, 1, wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )


		gSizer6.Add( gSizer11, 1, wx.EXPAND, 5 )

		gSizer12 = wx.GridSizer( 4, 1, 0, 0 )

		self.m_staticText7 = wx.StaticText( sbSizer2.GetStaticBox(), wx.ID_ANY, u"MyLabel", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText7.Wrap( -1 )
		gSizer12.Add( self.m_staticText7, 1, wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )

		self.m_staticText8 = wx.StaticText( sbSizer2.GetStaticBox(), wx.ID_ANY, u"MyLabel", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText8.Wrap( -1 )
		gSizer12.Add( self.m_staticText8, 1, wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )

		self.m_staticText9 = wx.StaticText( sbSizer2.GetStaticBox(), wx.ID_ANY, u"MyLabel", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText9.Wrap( -1 )
		gSizer12.Add( self.m_staticText9, 1, wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )


		gSizer6.Add( gSizer12, 1, wx.EXPAND, 5 )


		sbSizer2.Add( gSizer6, 1, wx.EXPAND, 5 )


		gSizer4.Add( sbSizer2, 1, wx.EXPAND, 5 )

		gSizer5 = wx.GridSizer( 1, 2, 0, 0 )

		self.m_button1 = wx.Button( self, wx.ID_ANY, u"List", wx.DefaultPosition, wx.DefaultSize, 0 )
		gSizer5.Add( self.m_button1, 1, wx.ALL|wx.ALIGN_BOTTOM, 5 )

		self.m_button5 = wx.Button( self, wx.ID_ANY, u"Close", wx.DefaultPosition, wx.DefaultSize, 0 )
		gSizer5.Add( self.m_button5, 1, wx.ALL|wx.ALIGN_BOTTOM|wx.ALIGN_RIGHT, 5 )


		gSizer4.Add( gSizer5, 1, wx.EXPAND, 5 )


		gSizer2.Add( gSizer4, 1, wx.EXPAND, 5 )


		gSizer1.Add( gSizer2, 1, wx.EXPAND, 5 )


		self.SetSizer( gSizer1 )
		self.Layout()

		self.Centre( wx.BOTH )

		# Connect Events
		self.Bind( wx.EVT_ACTIVATE, self.MyFrame4OnActivate )
		self.m_grid1.Bind( wx.grid.EVT_GRID_SELECT_CELL, self.m_grid1OnGridSelectCell )
		self.m_comboBox1.Bind( wx.EVT_COMBOBOX, self.m_comboBox1OnCombobox )
		self.m_comboBox2.Bind( wx.EVT_COMBOBOX, self.m_comboBox2OnCombobox )
		self.m_comboBox3.Bind( wx.EVT_COMBOBOX, self.m_comboBox3OnCombobox )
		self.m_button2.Bind( wx.EVT_BUTTON, self.m_button2OnButtonClick )
		self.m_button3.Bind( wx.EVT_BUTTON, self.m_button3OnButtonClick )
		self.m_button4.Bind( wx.EVT_BUTTON, self.m_button4OnButtonClick )
		self.m_button1.Bind( wx.EVT_BUTTON, self.m_button1OnButtonClick )
		self.m_button5.Bind( wx.EVT_BUTTON, self.m_button5OnButtonClick )

	# Deletes the instance of the MyFrame4 class.
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
			self.m_comboBox1.Clear()
			self.m_comboBox2.Clear()
			self.m_comboBox3.Clear()

			# Open a connection to the database.
			__connection = pymssql.connect('localhost', 'root', 'RootUser0123456789', 'MsSqlTestDatabase')

			# Get the items from the People table.
			__people = []
			__cursor = __connection.cursor()

			# Execute.
			__cursor.execute('SELECT * FROM [MsSqlTestDatabase].[dbo].[People]')

			# Store the items in a Person list.
			for __row in __cursor.fetchall():
				__people.append(__row)

			# Get the items from the Relationships table.
			__relationships = []
			__cursor.execute('SELECT * FROM [MsSqlTestDatabase].[dbo].[Relationships]')

			# Store the items in a Relationship list.
			for __row in __cursor.fetchall():
				__relationships.append(__row)

			# Get the items from the Relations table.
			__relations = []
			__cursor.execute('SELECT * FROM [MsSqlTestDatabase].[dbo].[Relations] WHERE IsDeleted = 0')

			# Store the items in a Relation list.
			for __row in __cursor.fetchall():
				__relations.append(__row)

			# Close the cursor and the connection.
			__cursor.close()
			__connection.close()

			# Fill the grid rows with the values of the Relations table.
			for __oneItem in __relations:
				self.m_grid1.AppendRows(1)

				self.m_grid1.SetCellValue(self.m_grid1.GetNumberRows() - 1, 0, str(__oneItem[0]))

				# Substitute the Person1 and Person2 ids with their names.
				for __onePerson in __people:
					if (__oneItem[1] == __onePerson[0]):
						self.m_grid1.SetCellValue(self.m_grid1.GetNumberRows() - 1, 1, str(__onePerson[1]))

					if (__oneItem[3] == __onePerson[0]):
						self.m_grid1.SetCellValue(self.m_grid1.GetNumberRows() - 1, 3, str(__onePerson[1]))

				# Substitute the Relationship ids with their names.
				for __oneRelationship in __relationships:
					if (__oneItem[2] == __oneRelationship[0]):
						self.m_grid1.SetCellValue(self.m_grid1.GetNumberRows() - 1, 2, str(__oneRelationship[1]))

			# Fill the comboBox items with the values of the People table.
			for __onePerson in __people:
				if (__onePerson[5] == False):
					self.m_comboBox1.Append(str(__onePerson[0]))
					self.m_comboBox3.Append(str(__onePerson[0]))

			# Fill the comboBox items with the values of the Relationships table.
			for __oneRelationship in __relationships:
				if (__oneRelationship[2] == False):
					self.m_comboBox2.Append(str(__oneRelationship[0]))
		except Exception as e:
			print e

	# Handles the OnActive event of the MyFrame4 control.
	def MyFrame4OnActivate( self, event ):
		# Preset values.
		self.m_staticText7.SetLabelText('')
		self.m_staticText8.SetLabelText('')
		self.m_staticText9.SetLabelText('')

		self.GetData()

	# Handles the OnGridSelectCell event of the grid1 control.
	def m_grid1OnGridSelectCell( self, event ):
		# An item must be selected in the grid.
		if (event.GetRow() >= 0):
			try:
				# Get the Id value of the selected item.
				self.__selectedIndexValue = event.GetRow()
				self.__idValue = int(self.m_grid1.GetCellValue(self.__selectedIndexValue, 0))

				# Open a connection to the database.
				__connection = pymssql.connect('localhost', 'root', 'RootUser0123456789', 'MsSqlTestDatabase')

				# Get the items from the Relations table.
				__relation = None
				__cursor = __connection.cursor()

				# Execute.
				__cursor.execute('SELECT * FROM [MsSqlTestDatabase].[dbo].[Relations] WHERE Id = %d' % (self.__idValue))

				# Store it in a Relation object.
				for __row in __cursor.fetchall():
					__relation = __row

				# Give the comboBox Values the selected values.
				self.m_comboBox1.SetValue(str(__relation[1]))
				self.m_comboBox2.SetValue(str(__relation[2]))
				self.m_comboBox3.SetValue(str(__relation[3]))

				# Invoke the Selected Index Change methods.
				self.m_comboBox1OnCombobox(None)
				self.m_comboBox2OnCombobox(None)
				self.m_comboBox3OnCombobox(None)

				# Close the cursor and the connection.
				__cursor.close()
				__connection.close()
			except:
				# Empty the comboBox Values.
				self.m_comboBox1.SetValue('')
				self.m_comboBox2.SetValue('')
				self.m_comboBox3.SetValue('')
		else:
			# Empty the comboBox Values.
			self.m_comboBox1.SetValue('')
			self.m_comboBox2.SetValue('')
			self.m_comboBox3.SetValue('')

	# Handles the OnCombobox event of the comboBox1 control.
	def m_comboBox1OnCombobox( self, event ):
		try:
			# Store the comboBox selected item.
			self.__name1Value = int(self.m_comboBox1.GetValue())

			# Open a connection to the database.
			__connection = pymssql.connect('localhost', 'root', 'RootUser0123456789', 'MsSqlTestDatabase')

			# Get the items from the People table.
			__retVal = None
			__cursor = __connection.cursor()

			# Execute.
			__cursor.execute('SELECT * FROM [MsSqlTestDatabase].[dbo].[People] WHERE Id = %d' % (self.__name1Value))

			# Store it in a Person object.
			for __row in __cursor.fetchall():
				__retVal = __row

			# Give the helper label the selected value.
			self.m_staticText7.SetLabelText(str(__retVal[1]))

			# Close the cursor and the connection.
			__cursor.close()
			__connection.close()
		except Exception as e:
			print e

	# Handles the OnCombobox event of the comboBox2 control.
	def m_comboBox2OnCombobox( self, event ):
		try:
			# Store the comboBox selected item.
			self.__relationshipValue = int(self.m_comboBox2.GetValue())

			# Open a connection to the database.
			__connection = pymssql.connect('localhost', 'root', 'RootUser0123456789', 'MsSqlTestDatabase')

			# Get the items from the Relationships table.
			__retVal = None
			__cursor = __connection.cursor()

			# Execute.
			__cursor.execute('SELECT * FROM [MsSqlTestDatabase].[dbo].[Relationships] WHERE Id = %d' % (self.__relationshipValue))

			# Store it in a Relationship object.
			for __row in __cursor.fetchall():
				__retVal = __row

			# Give the helper label the selected value.
			self.m_staticText8.SetLabelText(str(__retVal[1]))

			# Close the cursor and the connection.
			__cursor.close()
			__connection.close()
		except Exception as e:
			print e

	# Handles the OnCombobox event of the comboBox3 control.
	def m_comboBox3OnCombobox( self, event ):
		try:
			# Store the comboBox selected item.
			self.__name2Value = int(self.m_comboBox3.GetValue())

			# Open a connection to the database.
			__connection = pymssql.connect('localhost', 'root', 'RootUser0123456789', 'MsSqlTestDatabase')

			# Get the items from the People table.
			__retVal = None
			__cursor = __connection.cursor()

			# Execute.
			__cursor.execute('SELECT * FROM [MsSqlTestDatabase].[dbo].[People] WHERE Id = %d' % (self.__name2Value))

			# Store it in a Person object.
			for __row in __cursor.fetchall():
				__retVal = __row

			# Give the helper label the selected value.
			self.m_staticText9.SetLabelText(str(__retVal[1]))

			# Close the cursor and the connection.
			__cursor.close()
			__connection.close()
		except Exception as e:
			print e

	# Handles the OnButtonClick event of the button2 control.
	def m_button2OnButtonClick( self, event ):
		# Add a record.
		try:
			# The fileds must not be empty and the names must not match.
			if (self.__name1Value <> None and self.__relationshipValue <> None and self.__name2Value <> None and
				self.__name1Value > 0 and self.__relationshipValue > 0 and self.__name2Value > 0 and
				self.__name1Value <> self.__name2Value):
				self.__idValue = 0
				__matchFound = False

				# Open a connection to the database.
				__connection = pymssql.connect('localhost', 'root', 'RootUser0123456789', 'MsSqlTestDatabase')

				# Get the items from the Relations table.
				__cursor = __connection.cursor()

				# Execute.
				__cursor.execute('SELECT * FROM [MsSqlTestDatabase].[dbo].[Relations]')

				# Store the items in a Relation list.
				for __row in __cursor.fetchall():
					self.__idValue += 1

					# Search for a deleted maching item.
					if (__matchFound == False and int(__row[1]) == self.__name1Value and int(__row[2]) == self.__relationshipValue and
						int(__row[3]) == self.__name2Value and __row[4] == True):
						__matchFound = True
						self.__idValue = int(__row[0])

						break

				# Add a new item if no deleted was found else restore the deleted item.
				if (__matchFound == False):
					# Add new item to the Relations table.
					__cursor.execute('INSERT INTO [MsSqlTestDatabase].[dbo].[Relations] (Id, Person1, Relationship, Person2, IsDeleted) VALUES (%s, %s, %s, %s, %s)',
									(self.__idValue + 1, self.__name1Value, self.__relationshipValue, self.__name2Value, False))

					# Execute.
					__connection.commit()
				else:
					# Edit the IsDeleted value to false.
					__cursor.execute('UPDATE [MsSqlTestDatabase].[dbo].[Relations] SET IsDeleted = %s WHERE Id = %s',
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

	# Handles the OnButtonClick event of the button3 control.
	def m_button3OnButtonClick( self, event ):
		# Edit a record.
		try:
			# The fields must not be empty.
			if (self.__name1Value <> None and self.__relationshipValue <> None and self.__name2Value <> None and
				self.__name1Value > 0 and self.__relationshipValue > 0 and self.__name2Value > 0 and
				self.__name1Value <> self.__name2Value):
				# An item must be selected in the grid.
				if (self.__selectedIndexValue >= 0):
					# Get the Id value of the selected item.
					self.__idValue = int(self.m_grid1.GetCellValue(self.__selectedIndexValue, 0))

					# Open a connection to the database.
					__connection = pymssql.connect('localhost', 'root', 'RootUser0123456789', 'MsSqlTestDatabase')

					# Get the items from the Relations table.
					__cursor = __connection.cursor()

					# Execute.
					__cursor.execute('UPDATE [MsSqlTestDatabase].[dbo].[Relations] SET Person1 = %s, Relationship = %s, Person2 = %s WHERE Id = %s',
									(self.__name1Value, self.__relationshipValue, self.__name2Value, self.__idValue))

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
				__connection = pymssql.connect('localhost', 'root', 'RootUser0123456789', 'MsSqlTestDatabase')

				# Get the items from the Relations table.
				__cursor = __connection.cursor()

				# Execute.
				__cursor.execute('UPDATE [MsSqlTestDatabase].[dbo].[Relations] SET IsDeleted = %s WHERE Id = %s',
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

	# Handles the OnButtonClick event of the button1 control.
	def m_button1OnButtonClick( self, event ):
		# List the records.
		self.GetData()

	# Handles the OnButtonClick event of the button5 control.
	def m_button5OnButtonClick( self, event ):
		# Close the Frame.
		self.Close()

	#endregion Methods