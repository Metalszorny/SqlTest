----------------------------------------------------------------------------
-- Lua code generated with wxFormBuilder (version Jun 17 2015)
-- http://www.wxformbuilder.org/
----------------------------------------------------------------------------

-- Load the wxLua module, does nothing if running from wxLua, wxLuaFreeze, or wxLuaEdit
package.cpath = package.cpath..";./?.dll;./?.so;../lib/?.so;../lib/vc_dll/?.dll;../lib/bcc_dll/?.dll;../lib/mingw_dll/?.dll;"
require("wx")

UI = {}

-- Constructors

-- Initializes a new instance of the MyFrame1 class.
UI.MyFrame1 = wx.wxFrame (wx.NULL, wx.wxID_ANY, "Menu", wx.wxDefaultPosition, wx.wxSize( 230,300 ), wx.wxDEFAULT_FRAME_STYLE+wx.wxTAB_TRAVERSAL )
	UI.MyFrame1:SetSizeHints( wx.wxDefaultSize, wx.wxDefaultSize )
	UI.MyFrame1 :SetBackgroundColour( wx.wxSystemSettings.GetColour( wx.wxSYS_COLOUR_SCROLLBAR ) )
	
	UI.gSizer1 = wx.wxGridSizer( 9, 1, 0, 0 )
	
	UI.gSizer2 = wx.wxGridSizer( 1, 1, 0, 0 )
	
	
	UI.gSizer1:Add( UI.gSizer2, 1, wx.wxEXPAND, 5 )
	
	UI.m_button1 = wx.wxButton( UI.MyFrame1, wx.wxID_ANY, "People", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.gSizer1:Add( UI.m_button1, 1, wx.wxALL + wx.wxALIGN_CENTER_HORIZONTAL + wx.wxALIGN_CENTER_VERTICAL, 5 )
	
	UI.gSizer3 = wx.wxGridSizer( 1, 1, 0, 0 )
	
	
	UI.gSizer1:Add( UI.gSizer3, 1, wx.wxEXPAND, 5 )
	
	UI.m_button2 = wx.wxButton( UI.MyFrame1, wx.wxID_ANY, "Relationships", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.gSizer1:Add( UI.m_button2, 1, wx.wxALL + wx.wxALIGN_CENTER_HORIZONTAL + wx.wxALIGN_CENTER_VERTICAL, 5 )
	
	UI.gSizer4 = wx.wxGridSizer( 1, 1, 0, 0 )
	
	
	UI.gSizer1:Add( UI.gSizer4, 1, wx.wxEXPAND, 5 )
	
	UI.m_button3 = wx.wxButton( UI.MyFrame1, wx.wxID_ANY, "Relations", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.gSizer1:Add( UI.m_button3, 1, wx.wxALL + wx.wxALIGN_CENTER_VERTICAL + wx.wxALIGN_CENTER_HORIZONTAL, 5 )
	
	UI.gSizer5 = wx.wxGridSizer( 1, 1, 0, 0 )
	
	
	UI.gSizer1:Add( UI.gSizer5, 1, wx.wxEXPAND, 5 )
	
	UI.m_button4 = wx.wxButton( UI.MyFrame1, wx.wxID_ANY, "Exit", wx.wxDefaultPosition, wx.wxDefaultSize, 0 )
	UI.gSizer1:Add( UI.m_button4, 1, wx.wxALL + wx.wxALIGN_CENTER_VERTICAL + wx.wxALIGN_CENTER_HORIZONTAL, 5 )
	
	UI.gSizer6 = wx.wxGridSizer( 1, 1, 0, 0 )
	
	
	UI.gSizer1:Add( UI.gSizer6, 1, wx.wxEXPAND, 5 )
	
	
	UI.MyFrame1:SetSizer( UI.gSizer1 )
	UI.MyFrame1:Layout()
	
	UI.MyFrame1:Centre( wx.wxBOTH )
	
	-- Constructors
	
	-- Methods
	
	-- Handles the OnButtonClick event of the button1 control.
	UI.m_button1:Connect( wx.wxEVT_COMMAND_BUTTON_CLICKED, function(event)
		-- Open the People Frame.
		people = assert(dofile("MyFrame2.lua"))
		people()
	end )
	
	-- Handles the OnButtonClick event of the button2 control.
	UI.m_button2:Connect( wx.wxEVT_COMMAND_BUTTON_CLICKED, function(event)
		-- Open the Relationships Frame.
		relationships = assert(dofile("MyFrame3.lua"))
		relationships()
	end )
	
	-- Handles the OnButtonClick event of the button3 control.
	UI.m_button3:Connect( wx.wxEVT_COMMAND_BUTTON_CLICKED, function(event)
		-- Open the Relations Frame.
		relations = assert(dofile("MyFrame4.lua"))
		relations()
	end )
	
	-- Handles the OnButtonClick event of the button4 control.
	UI.m_button4:Connect( wx.wxEVT_COMMAND_BUTTON_CLICKED, function(event)
		-- Exit the Program.
		os.exit()
	end )

	-- Methods