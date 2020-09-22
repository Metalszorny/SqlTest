----------------------------------------------------------------------------
-- Lua code generated with wxFormBuilder (version Jun 17 2015)
-- http://www.wxformbuilder.org/
----------------------------------------------------------------------------

-- Load the wxLua module, does nothing if running from wxLua, wxLuaFreeze, or wxLuaEdit
package.cpath = package.cpath..";./?.dll;./?.so;../lib/?.so;../lib/vc_dll/?.dll;../lib/bcc_dll/?.dll;../lib/mingw_dll/?.dll;"
require("wx")

UI = {}


-- create MyFrame4
UI.MyFrame4 = wx.wxFrame (wx.NULL, wx.wxID_ANY, "Relations", wx.wxDefaultPosition, wx.wxSize( 715,610 ), wx.wxDEFAULT_FRAME_STYLE+wx.wxTAB_TRAVERSAL )
	UI.MyFrame4:SetSizeHints( wx.wxDefaultSize, wx.wxDefaultSize )
	UI.MyFrame4 :SetBackgroundColour( wx.wxSystemSettings.GetColour( wx.wxSYS_COLOUR_SCROLLBAR ) )
	
	UI.gSizer1 = wx.wxGridSizer( 1, 2, 0, 170 )
	
	UI.m_grid1 = wx.wxGrid( UI.MyFrame4, wx.wxID_ANY, wx.wxDefaultPosition, wx.wxSize( 430,570 ), wx.wxHSCROLL + wx.wxWANTS_CHARS )
	
	-- Grid
	UI.m_grid1:CreateGrid( 0, 4 )
	UI.m_grid1:EnableEditing( False )
	UI.m_grid1:EnableGridLines( True )
	UI.m_grid1:EnableDragGridSize( False )
	UI.m_grid1:SetMargins( 0, 0 )
	
	-- Columns
	UI.m_grid1:EnableDragColSize( True )
	UI.m_grid1:SetColLabelSize( 30 )
	UI.m_grid1:SetColLabelValue( 0, "Id" )
	UI.m_grid1:SetColLabelValue( 1, "Person1" )
	UI.m_grid1:SetColLabelValue( 2, "Relationship" )
	UI.m_grid1:SetColLabelValue( 3, "Person2" )
	UI.m_grid1:SetColLabelAlignment( wx.wxALIGN_CENTRE, wx.wxALIGN_CENTRE )
	
	-- Rows
	UI.m_grid1:EnableDragRowSize( True )
	UI.m_grid1:SetRowLabelSize( 0 )
	UI.m_grid1:SetRowLabelAlignment( wx.wxALIGN_CENTRE, wx.wxALIGN_CENTRE )
	
	-- Label Appearance
	
	-- Cell Defaults
	UI.m_grid1:SetDefaultCellAlignment( wx.wxALIGN_LEFT, wx.wxALIGN_TOP )
	UI.gSizer1:Add( UI.m_grid1, 0, wx.wxALL, 5 )
	
	UI.gSizer2 = wx.wxGridSizer( 2, 1, 0, 0 )
	
	UI.sbSizer1 = wx.wxStaticBoxSizer( wx.wxStaticBox( UI.MyFrame4, wx.wxID_ANY, "Modify:" ), wx.wxVERTICAL )
	
	UI.gSizer3 = wx.wxGridSizer( 2, 1, 0, 0 )
	
	UI.gSizer7 = wx.wxGridSizer( 1, 2, 0, 0 )
	
	UI.gSizer9 = wx.wxGridSizer( 4, 1, 0, 0 )
	
	UI.m_staticText1 = wx.wxStaticText( UI.sbSizer1:GetStaticBox(), wx.wxID_ANY, "Person1:", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.m_staticText1:Wrap( -1 )
	UI.gSizer9:Add( UI.m_staticText1, 1, wx.wxALL + wx.wxALIGN_CENTER_VERTICAL, 5 )
	
	UI.m_staticText2 = wx.wxStaticText( UI.sbSizer1:GetStaticBox(), wx.wxID_ANY, "Relationship:", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.m_staticText2:Wrap( -1 )
	UI.gSizer9:Add( UI.m_staticText2, 1, wx.wxALL + wx.wxALIGN_CENTER_VERTICAL, 5 )
	
	UI.m_staticText3 = wx.wxStaticText( UI.sbSizer1:GetStaticBox(), wx.wxID_ANY, "Person2:", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.m_staticText3:Wrap( -1 )
	UI.gSizer9:Add( UI.m_staticText3, 1, wx.wxALL + wx.wxALIGN_CENTER_VERTICAL, 5 )
	
	
	UI.gSizer7:Add( UI.gSizer9, 1, wx.wxEXPAND, 5 )
	
	UI.gSizer10 = wx.wxGridSizer( 4, 1, 0, 0 )
	
	UI.m_comboBox1Choices = {}
	UI.m_comboBox1 = wx.wxComboBox( UI.sbSizer1:GetStaticBox(), wx.wxID_ANY, "Combo!", wx.wxDefaultPosition, wx.wxDefaultSize, UI.m_comboBox1Choices, 0 )
	UI.gSizer10:Add( UI.m_comboBox1, 1, wx.wxALL + wx.wxALIGN_CENTER_HORIZONTAL + wx.wxALIGN_CENTER_VERTICAL + wx.wxEXPAND, 5 )
	
	UI.m_comboBox2Choices = {}
	UI.m_comboBox2 = wx.wxComboBox( UI.sbSizer1:GetStaticBox(), wx.wxID_ANY, "Combo!", wx.wxDefaultPosition, wx.wxDefaultSize, UI.m_comboBox2Choices, 0 )
	UI.gSizer10:Add( UI.m_comboBox2, 1, wx.wxALL + wx.wxALIGN_CENTER_HORIZONTAL + wx.wxALIGN_CENTER_VERTICAL + wx.wxEXPAND, 5 )
	
	UI.m_comboBox3Choices = {}
	UI.m_comboBox3 = wx.wxComboBox( UI.sbSizer1:GetStaticBox(), wx.wxID_ANY, "Combo!", wx.wxDefaultPosition, wx.wxDefaultSize, UI.m_comboBox3Choices, 0 )
	UI.gSizer10:Add( UI.m_comboBox3, 1, wx.wxALL + wx.wxEXPAND + wx.wxALIGN_CENTER_VERTICAL + wx.wxALIGN_CENTER_HORIZONTAL, 5 )
	
	
	UI.gSizer7:Add( UI.gSizer10, 1, wx.wxEXPAND, 5 )
	
	
	UI.gSizer3:Add( UI.gSizer7, 1, wx.wxEXPAND, 5 )
	
	UI.gSizer8 = wx.wxGridSizer( 1, 3, 0, 0 )
	
	UI.m_button2 = wx.wxButton( UI.sbSizer1:GetStaticBox(), wx.wxID_ANY, "Add", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.gSizer8:Add( UI.m_button2, 1, wx.wxALL + wx.wxALIGN_BOTTOM + wx.wxALIGN_CENTER_HORIZONTAL, 5 )
	
	UI.m_button3 = wx.wxButton( UI.sbSizer1:GetStaticBox(), wx.wxID_ANY, "Edit", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.gSizer8:Add( UI.m_button3, 1, wx.wxALL + wx.wxALIGN_CENTER_HORIZONTAL + wx.wxALIGN_BOTTOM, 5 )
	
	UI.m_button4 = wx.wxButton( UI.sbSizer1:GetStaticBox(), wx.wxID_ANY, "Delete", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.gSizer8:Add( UI.m_button4, 1, wx.wxALL + wx.wxALIGN_CENTER_HORIZONTAL + wx.wxALIGN_BOTTOM, 5 )
	
	
	UI.gSizer3:Add( UI.gSizer8, 1, wx.wxEXPAND, 5 )
	
	
	UI.sbSizer1:Add( UI.gSizer3, 1, wx.wxEXPAND, 5 )
	
	
	UI.gSizer2:Add( UI.sbSizer1, 1, wx.wxEXPAND, 5 )
	
	UI.gSizer4 = wx.wxGridSizer( 2, 1, 0, 0 )
	
	UI.sbSizer2 = wx.wxStaticBoxSizer( wx.wxStaticBox( UI.MyFrame4, wx.wxID_ANY, "Helper:" ), wx.wxVERTICAL )
	
	UI.gSizer6 = wx.wxGridSizer( 1, 2, 0, 0 )
	
	UI.gSizer11 = wx.wxGridSizer( 4, 1, 0, 0 )
	
	UI.m_staticText4 = wx.wxStaticText( UI.sbSizer2:GetStaticBox(), wx.wxID_ANY, "Person1:", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.m_staticText4:Wrap( -1 )
	UI.gSizer11:Add( UI.m_staticText4, 1, wx.wxALL + wx.wxALIGN_CENTER_VERTICAL, 5 )
	
	UI.m_staticText5 = wx.wxStaticText( UI.sbSizer2:GetStaticBox(), wx.wxID_ANY, "Relationship:", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.m_staticText5:Wrap( -1 )
	UI.gSizer11:Add( UI.m_staticText5, 1, wx.wxALL + wx.wxALIGN_CENTER_VERTICAL, 5 )
	
	UI.m_staticText6 = wx.wxStaticText( UI.sbSizer2:GetStaticBox(), wx.wxID_ANY, "Person2:", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.m_staticText6:Wrap( -1 )
	UI.gSizer11:Add( UI.m_staticText6, 1, wx.wxALL + wx.wxALIGN_CENTER_VERTICAL, 5 )
	
	
	UI.gSizer6:Add( UI.gSizer11, 1, wx.wxEXPAND, 5 )
	
	UI.gSizer12 = wx.wxGridSizer( 4, 1, 0, 0 )
	
	UI.m_staticText7 = wx.wxStaticText( UI.sbSizer2:GetStaticBox(), wx.wxID_ANY, "MyLabel", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.m_staticText7:Wrap( -1 )
	UI.gSizer12:Add( UI.m_staticText7, 1, wx.wxALL + wx.wxALIGN_CENTER_VERTICAL, 5 )
	
	UI.m_staticText8 = wx.wxStaticText( UI.sbSizer2:GetStaticBox(), wx.wxID_ANY, "MyLabel", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.m_staticText8:Wrap( -1 )
	UI.gSizer12:Add( UI.m_staticText8, 1, wx.wxALL + wx.wxALIGN_CENTER_VERTICAL, 5 )
	
	UI.m_staticText9 = wx.wxStaticText( UI.sbSizer2:GetStaticBox(), wx.wxID_ANY, "MyLabel", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.m_staticText9:Wrap( -1 )
	UI.gSizer12:Add( UI.m_staticText9, 1, wx.wxALL + wx.wxALIGN_CENTER_VERTICAL, 5 )
	
	
	UI.gSizer6:Add( UI.gSizer12, 1, wx.wxEXPAND, 5 )
	
	
	UI.sbSizer2:Add( UI.gSizer6, 1, wx.wxEXPAND, 5 )
	
	
	UI.gSizer4:Add( UI.sbSizer2, 1, wx.wxEXPAND, 5 )
	
	UI.gSizer5 = wx.wxGridSizer( 1, 2, 0, 0 )
	
	UI.m_button1 = wx.wxButton( UI.MyFrame4, wx.wxID_ANY, "List", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.gSizer5:Add( UI.m_button1, 1, wx.wxALL + wx.wxALIGN_BOTTOM, 5 )
	
	UI.m_button5 = wx.wxButton( UI.MyFrame4, wx.wxID_ANY, "Close", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.gSizer5:Add( UI.m_button5, 1, wx.wxALL + wx.wxALIGN_BOTTOM + wx.wxALIGN_RIGHT, 5 )
	
	
	UI.gSizer4:Add( UI.gSizer5, 1, wx.wxEXPAND, 5 )
	
	
	UI.gSizer2:Add( UI.gSizer4, 1, wx.wxEXPAND, 5 )
	
	
	UI.gSizer1:Add( UI.gSizer2, 1, wx.wxEXPAND, 5 )
	
	
	UI.MyFrame4:SetSizer( UI.gSizer1 )
	UI.MyFrame4:Layout()
	
	UI.MyFrame4:Centre( wx.wxBOTH )
	
	-- Connect Events
	
	UI.MyFrame4:Connect( wx.wxEVT_ACTIVATE, function(event)
	--implements MyFrame4OnActivate
	
	event:Skip()
	end )
	
	UI.m_grid1:Connect( wx.wxEVT_GRID_SELECT_CELL, function(event)
	--implements m_grid1OnGridSelectCell
	
	event:Skip()
	end )
	
	UI.m_comboBox1:Connect( wx.wxEVT_COMMAND_COMBOBOX_SELECTED, function(event)
	--implements m_comboBox1OnCombobox
	
	event:Skip()
	end )
	
	UI.m_comboBox2:Connect( wx.wxEVT_COMMAND_COMBOBOX_SELECTED, function(event)
	--implements m_comboBox2OnCombobox
	
	event:Skip()
	end )
	
	UI.m_comboBox3:Connect( wx.wxEVT_COMMAND_COMBOBOX_SELECTED, function(event)
	--implements m_comboBox3OnCombobox
	
	event:Skip()
	end )
	
	UI.m_button2:Connect( wx.wxEVT_COMMAND_BUTTON_CLICKED, function(event)
	--implements m_button2OnButtonClick
	
	event:Skip()
	end )
	
	UI.m_button3:Connect( wx.wxEVT_COMMAND_BUTTON_CLICKED, function(event)
	--implements m_button3OnButtonClick
	
	event:Skip()
	end )
	
	UI.m_button4:Connect( wx.wxEVT_COMMAND_BUTTON_CLICKED, function(event)
	--implements m_button4OnButtonClick
	
	event:Skip()
	end )
	
	UI.m_button1:Connect( wx.wxEVT_COMMAND_BUTTON_CLICKED, function(event)
	--implements m_button1OnButtonClick
	
	event:Skip()
	end )
	
	UI.m_button5:Connect( wx.wxEVT_COMMAND_BUTTON_CLICKED, function(event)
	--implements m_button5OnButtonClick
		self.exit()
	end )
