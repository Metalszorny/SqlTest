----------------------------------------------------------------------------
-- Lua code generated with wxFormBuilder (version Jun 17 2015)
-- http://www.wxformbuilder.org/
----------------------------------------------------------------------------

-- Load the wxLua module, does nothing if running from wxLua, wxLuaFreeze, or wxLuaEdit
package.cpath = package.cpath..";./?.dll;./?.so;../lib/?.so;../lib/vc_dll/?.dll;../lib/bcc_dll/?.dll;../lib/mingw_dll/?.dll;"
require("wx")

UI = {}

-- Fields

	-- The selected index.
	UI.__selectedIndexValue = 0
	
	-- The id value.
	UI.__idValue = 0
	
	-- The name value.
	UI.__nameValue = ""

	-- The mothername value.
    UI.__mothernameValue = ""

    -- The location value.
    UI.__locationValue = ""

    -- The birthdate value.
    UI.__birthdateValue = ""
	
-- Fields

-- Constructors

-- Initializes a new instance of the MyFrame2 class.
UI.MyFrame2 = wx.wxFrame (wx.NULL, wx.wxID_ANY, "People", wx.wxDefaultPosition, wx.wxSize( 715,610 ), wx.wxDEFAULT_FRAME_STYLE+wx.wxTAB_TRAVERSAL )
	UI.MyFrame2:SetSizeHints( wx.wxDefaultSize, wx.wxDefaultSize )
	UI.MyFrame2 :SetBackgroundColour( wx.wxSystemSettings.GetColour( wx.wxSYS_COLOUR_SCROLLBAR ) )
	
	UI.gSizer1 = wx.wxGridSizer( 1, 2, 0, 170 )
	
	UI.m_grid1 = wx.wxGrid( UI.MyFrame2, wx.wxID_ANY, wx.wxDefaultPosition, wx.wxSize( 430,570 ), wx.wxHSCROLL + wx.wxVSCROLL )
	
	-- Grid
	UI.m_grid1:CreateGrid( 0, 5 )
	UI.m_grid1:EnableEditing( False )
	UI.m_grid1:EnableGridLines( True )
	UI.m_grid1:EnableDragGridSize( False )
	UI.m_grid1:SetMargins( 0, 0 )
	
	-- Columns
	UI.m_grid1:EnableDragColSize( True )
	UI.m_grid1:SetColLabelSize( 30 )
	UI.m_grid1:SetColLabelValue( 0, "Id" )
	UI.m_grid1:SetColLabelValue( 1, "Name" )
	UI.m_grid1:SetColLabelValue( 2, "Mothername" )
	UI.m_grid1:SetColLabelValue( 3, "Location" )
	UI.m_grid1:SetColLabelValue( 4, "Birthdate" )
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
	
	UI.sbSizer1 = wx.wxStaticBoxSizer( wx.wxStaticBox( UI.MyFrame2, wx.wxID_ANY, "Modify:" ), wx.wxVERTICAL )
	
	UI.gSizer3 = wx.wxGridSizer( 2, 1, 0, 0 )
	
	UI.gSizer5 = wx.wxGridSizer( 1, 2, 0, 0 )
	
	UI.gSizer7 = wx.wxGridSizer( 4, 1, 0, 0 )
	
	UI.m_staticText1 = wx.wxStaticText( UI.sbSizer1:GetStaticBox(), wx.wxID_ANY, "Name:", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.m_staticText1:Wrap( -1 )
	UI.gSizer7:Add( UI.m_staticText1, 1, wx.wxALL + wx.wxALIGN_CENTER_VERTICAL, 5 )
	
	UI.m_staticText2 = wx.wxStaticText( UI.sbSizer1:GetStaticBox(), wx.wxID_ANY, "Mothername:", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.m_staticText2:Wrap( -1 )
	UI.gSizer7:Add( UI.m_staticText2, 1, wx.wxALL + wx.wxALIGN_CENTER_VERTICAL, 5 )
	
	UI.m_staticText3 = wx.wxStaticText( UI.sbSizer1:GetStaticBox(), wx.wxID_ANY, "Location:", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.m_staticText3:Wrap( -1 )
	UI.gSizer7:Add( UI.m_staticText3, 1, wx.wxALL + wx.wxALIGN_CENTER_VERTICAL, 5 )
	
	UI.m_staticText4 = wx.wxStaticText( UI.sbSizer1:GetStaticBox(), wx.wxID_ANY, "Birthdate:", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.m_staticText4:Wrap( -1 )
	UI.gSizer7:Add( UI.m_staticText4, 1, wx.wxALL + wx.wxALIGN_CENTER_VERTICAL, 5 )
	
	
	UI.gSizer5:Add( UI.gSizer7, 1, wx.wxEXPAND, 5 )
	
	UI.gSizer8 = wx.wxGridSizer( 4, 1, 0, 0 )
	
	UI.m_textCtrl1 = wx.wxTextCtrl( UI.sbSizer1:GetStaticBox(), wx.wxID_ANY, "", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.gSizer8:Add( UI.m_textCtrl1, 1, wx.wxALL + wx.wxEXPAND + wx.wxALIGN_CENTER_HORIZONTAL + wx.wxALIGN_CENTER_VERTICAL, 5 )
	
	UI.m_textCtrl2 = wx.wxTextCtrl( UI.sbSizer1:GetStaticBox(), wx.wxID_ANY, "", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.gSizer8:Add( UI.m_textCtrl2, 1, wx.wxALL + wx.wxEXPAND + wx.wxALIGN_CENTER_HORIZONTAL + wx.wxALIGN_CENTER_VERTICAL, 5 )
	
	UI.m_textCtrl3 = wx.wxTextCtrl( UI.sbSizer1:GetStaticBox(), wx.wxID_ANY, "", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.gSizer8:Add( UI.m_textCtrl3, 1, wx.wxALL + wx.wxALIGN_CENTER_HORIZONTAL + wx.wxALIGN_CENTER_VERTICAL + wx.wxEXPAND, 5 )
	
	UI.m_textCtrl4 = wx.wxTextCtrl( UI.sbSizer1:GetStaticBox(), wx.wxID_ANY, "", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.gSizer8:Add( UI.m_textCtrl4, 1, wx.wxALL + wx.wxALIGN_CENTER_HORIZONTAL + wx.wxALIGN_CENTER_VERTICAL + wx.wxEXPAND, 5 )
	
	
	UI.gSizer5:Add( UI.gSizer8, 1, wx.wxEXPAND, 5 )
	
	
	UI.gSizer3:Add( UI.gSizer5, 1, wx.wxEXPAND, 5 )
	
	UI.gSizer6 = wx.wxGridSizer( 1, 3, 0, 0 )
	
	UI.m_button2 = wx.wxButton( UI.sbSizer1:GetStaticBox(), wx.wxID_ANY, "Add", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.gSizer6:Add( UI.m_button2, 1, wx.wxALL + wx.wxALIGN_CENTER_HORIZONTAL + wx.wxALIGN_BOTTOM, 5 )
	
	UI.m_button3 = wx.wxButton( UI.sbSizer1:GetStaticBox(), wx.wxID_ANY, "Edit", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.gSizer6:Add( UI.m_button3, 1, wx.wxALL + wx.wxALIGN_CENTER_HORIZONTAL + wx.wxALIGN_BOTTOM, 5 )
	
	UI.m_button4 = wx.wxButton( UI.sbSizer1:GetStaticBox(), wx.wxID_ANY, "Delete", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.gSizer6:Add( UI.m_button4, 1, wx.wxALL + wx.wxALIGN_CENTER_HORIZONTAL + wx.wxALIGN_BOTTOM, 5 )
	
	
	UI.gSizer3:Add( UI.gSizer6, 1, wx.wxEXPAND, 5 )
	
	
	UI.sbSizer1:Add( UI.gSizer3, 1, wx.wxEXPAND, 5 )
	
	
	UI.gSizer2:Add( UI.sbSizer1, 1, wx.wxEXPAND + wx.wxALIGN_CENTER_HORIZONTAL + wx.wxALIGN_CENTER_VERTICAL, 5 )
	
	UI.gSizer4 = wx.wxGridSizer( 1, 2, 0, 0 )
	
	UI.m_button1 = wx.wxButton( UI.MyFrame2, wx.wxID_ANY, "List", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.gSizer4:Add( UI.m_button1, 1, wx.wxALL + wx.wxALIGN_BOTTOM, 5 )
	
	UI.m_button5 = wx.wxButton( UI.MyFrame2, wx.wxID_ANY, "Close", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.gSizer4:Add( UI.m_button5, 1, wx.wxALL + wx.wxALIGN_BOTTOM + wx.wxALIGN_RIGHT, 5 )
	
	
	UI.gSizer2:Add( UI.gSizer4, 1, wx.wxEXPAND, 5 )
	
	
	UI.gSizer1:Add( UI.gSizer2, 1, wx.wxEXPAND, 5 )
	
	
	UI.MyFrame2:SetSizer( UI.gSizer1 )
	UI.MyFrame2:Layout()
	
	UI.MyFrame2:Centre( wx.wxBOTH )
	
	-- Constructors
	
	-- Methods
	
	-- Handles the OnActive event of the MyFrame2 control.
	UI.MyFrame2:Connect( wx.wxEVT_ACTIVATE, function(event)
		-- Preset values.
		
	end )
	
	UI.m_grid1:Connect( wx.wxEVT_GRID_SELECT_CELL, function(event)
	--implements m_grid1OnGridSelectCell
	
	event:Skip()
	end )
	
	UI.m_textCtrl1:Connect( wx.wxEVT_COMMAND_TEXT_UPDATED, function(event)
	--implements m_textCtrl1OnText
	
	event:Skip()
	end )
	
	UI.m_textCtrl2:Connect( wx.wxEVT_COMMAND_TEXT_UPDATED, function(event)
	--implements m_textCtrl2OnText
	
	event:Skip()
	end )
	
	UI.m_textCtrl3:Connect( wx.wxEVT_COMMAND_TEXT_UPDATED, function(event)
	--implements m_textCtrl3OnText
	
	event:Skip()
	end )
	
	UI.m_textCtrl4:Connect( wx.wxEVT_COMMAND_TEXT_UPDATED, function(event)
	--implements m_textCtrl4OnText
	
	event:Skip()
	end )
	
	-- Handles the OnButtonClick event of the button2 control.
	UI.m_button2:Connect( wx.wxEVT_COMMAND_BUTTON_CLICKED, function(event)
		--implements m_button2OnButtonClick
	
		event:Skip()
	end )
	
	-- Handles the OnButtonClick event of the button3 control.
	UI.m_button3:Connect( wx.wxEVT_COMMAND_BUTTON_CLICKED, function(event)
		--implements m_button3OnButtonClick
	
		event:Skip()
	end )
	
	-- Handles the OnButtonClick event of the button4 control.
	UI.m_button4:Connect( wx.wxEVT_COMMAND_BUTTON_CLICKED, function(event)
		--implements m_button4OnButtonClick
	
		event:Skip()
	end )
	
	-- Handles the OnButtonClick event of the button1 control.
	UI.m_button1:Connect( wx.wxEVT_COMMAND_BUTTON_CLICKED, function(event)
		-- List the records.
		
	end )
	
	-- Handles the OnButtonClick event of the button5 control.
	UI.m_button5:Connect( wx.wxEVT_COMMAND_BUTTON_CLICKED, function(event)
		-- Close the Frame.
		self.exit()
	end )

	-- Gets the data.
	function UI:GetData()
	
	end
	
	-- Methods