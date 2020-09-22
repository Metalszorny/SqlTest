///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MyFrame4.h"

///////////////////////////////////////////////////////////////////////////

/// \brief Initializes a new instance of the MyFrame4 class.
/// \par parent
/// \par id
/// \par title
/// \par pos
/// \par size
/// \par style
MyFrame4::MyFrame4( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_SCROLLBAR ) );

	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 1, 2, 0, 170 );

	m_grid1 = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxSize( 430,570 ), wxHSCROLL|wxWANTS_CHARS );

	// Grid
	m_grid1->CreateGrid( 0, 4 );
	m_grid1->EnableEditing( false );
	m_grid1->EnableGridLines( true );
	m_grid1->EnableDragGridSize( false );
	m_grid1->SetMargins( 0, 0 );

	// Columns
	m_grid1->EnableDragColMove( false );
	m_grid1->EnableDragColSize( true );
	m_grid1->SetColLabelSize( 30 );
	m_grid1->SetColLabelValue( 0, wxT("Id") );
	m_grid1->SetColLabelValue( 1, wxT("Person1") );
	m_grid1->SetColLabelValue( 2, wxT("Relationship") );
	m_grid1->SetColLabelValue( 3, wxT("Person2") );
	m_grid1->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );

	// Rows
	m_grid1->EnableDragRowSize( true );
	m_grid1->SetRowLabelSize( 0 );
	m_grid1->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );

	// Label Appearance

	// Cell Defaults
	m_grid1->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	gSizer1->Add( m_grid1, 0, wxALL, 5 );

	wxGridSizer* gSizer2;
	gSizer2 = new wxGridSizer( 2, 1, 0, 0 );

	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Modify:") ), wxVERTICAL );

	wxGridSizer* gSizer3;
	gSizer3 = new wxGridSizer( 2, 1, 0, 0 );

	wxGridSizer* gSizer7;
	gSizer7 = new wxGridSizer( 1, 2, 0, 0 );

	wxGridSizer* gSizer9;
	gSizer9 = new wxGridSizer( 4, 1, 0, 0 );

	m_staticText1 = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Person1:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	gSizer9->Add( m_staticText1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText2 = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Relationship:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	gSizer9->Add( m_staticText2, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText3 = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Person2:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	gSizer9->Add( m_staticText3, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	gSizer7->Add( gSizer9, 1, wxEXPAND, 5 );

	wxGridSizer* gSizer10;
	gSizer10 = new wxGridSizer( 4, 1, 0, 0 );

	m_comboBox1 = new wxComboBox( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	gSizer10->Add( m_comboBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );

	m_comboBox2 = new wxComboBox( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	gSizer10->Add( m_comboBox2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );

	m_comboBox3 = new wxComboBox( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	gSizer10->Add( m_comboBox3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );


	gSizer7->Add( gSizer10, 1, wxEXPAND, 5 );


	gSizer3->Add( gSizer7, 1, wxEXPAND, 5 );

	wxGridSizer* gSizer8;
	gSizer8 = new wxGridSizer( 1, 3, 0, 0 );

	m_button2 = new wxButton( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer8->Add( m_button2, 1, wxALL|wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_button3 = new wxButton( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Edit"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer8->Add( m_button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_BOTTOM, 5 );

	m_button4 = new wxButton( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer8->Add( m_button4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_BOTTOM, 5 );


	gSizer3->Add( gSizer8, 1, wxEXPAND, 5 );


	sbSizer1->Add( gSizer3, 1, wxEXPAND, 5 );


	gSizer2->Add( sbSizer1, 1, wxEXPAND, 5 );

	wxGridSizer* gSizer4;
	gSizer4 = new wxGridSizer( 2, 1, 0, 0 );

	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Helper:") ), wxVERTICAL );

	wxGridSizer* gSizer6;
	gSizer6 = new wxGridSizer( 1, 2, 0, 0 );

	wxGridSizer* gSizer11;
	gSizer11 = new wxGridSizer( 4, 1, 0, 0 );

	m_staticText4 = new wxStaticText( sbSizer2->GetStaticBox(), wxID_ANY, wxT("Person1:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	gSizer11->Add( m_staticText4, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText5 = new wxStaticText( sbSizer2->GetStaticBox(), wxID_ANY, wxT("Relationship:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	gSizer11->Add( m_staticText5, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText6 = new wxStaticText( sbSizer2->GetStaticBox(), wxID_ANY, wxT("Person2:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	gSizer11->Add( m_staticText6, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	gSizer6->Add( gSizer11, 1, wxEXPAND, 5 );

	wxGridSizer* gSizer12;
	gSizer12 = new wxGridSizer( 4, 1, 0, 0 );

	m_staticText7 = new wxStaticText( sbSizer2->GetStaticBox(), wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	gSizer12->Add( m_staticText7, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText8 = new wxStaticText( sbSizer2->GetStaticBox(), wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	gSizer12->Add( m_staticText8, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText9 = new wxStaticText( sbSizer2->GetStaticBox(), wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	gSizer12->Add( m_staticText9, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	gSizer6->Add( gSizer12, 1, wxEXPAND, 5 );


	sbSizer2->Add( gSizer6, 1, wxEXPAND, 5 );


	gSizer4->Add( sbSizer2, 1, wxEXPAND, 5 );

	wxGridSizer* gSizer5;
	gSizer5 = new wxGridSizer( 1, 2, 0, 0 );

	m_button1 = new wxButton( this, wxID_ANY, wxT("List"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer5->Add( m_button1, 1, wxALL|wxALIGN_BOTTOM, 5 );

	m_button5 = new wxButton( this, wxID_ANY, wxT("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer5->Add( m_button5, 1, wxALL|wxALIGN_BOTTOM|wxALIGN_RIGHT, 5 );


	gSizer4->Add( gSizer5, 1, wxEXPAND, 5 );


	gSizer2->Add( gSizer4, 1, wxEXPAND, 5 );


	gSizer1->Add( gSizer2, 1, wxEXPAND, 5 );


	this->SetSizer( gSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_ACTIVATE, wxActivateEventHandler( MyFrame4::MyFrame4OnActivate ) );
	m_grid1->Connect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( MyFrame4::m_grid1OnGridSelectCell ), NULL, this );
	m_comboBox1->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MyFrame4::m_comboBox1OnCombobox ), NULL, this );
	m_comboBox2->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MyFrame4::m_comboBox2OnCombobox ), NULL, this );
	m_comboBox3->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MyFrame4::m_comboBox3OnCombobox ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame4::m_button2OnButtonClick ), NULL, this );
	m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame4::m_button3OnButtonClick ), NULL, this );
	m_button4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame4::m_button4OnButtonClick ), NULL, this );
	m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame4::m_button1OnButtonClick ), NULL, this );
	m_button5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame4::m_button5OnButtonClick ), NULL, this );
}

/// \brief Clean up any resources being used.
MyFrame4::~MyFrame4()
{
	// Disconnect Events
	this->Disconnect( wxEVT_ACTIVATE, wxActivateEventHandler( MyFrame4::MyFrame4OnActivate ) );
	m_grid1->Disconnect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( MyFrame4::m_grid1OnGridSelectCell ), NULL, this );
	m_comboBox1->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MyFrame4::m_comboBox1OnCombobox ), NULL, this );
	m_comboBox2->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MyFrame4::m_comboBox2OnCombobox ), NULL, this );
	m_comboBox3->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MyFrame4::m_comboBox3OnCombobox ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame4::m_button2OnButtonClick ), NULL, this );
	m_button3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame4::m_button3OnButtonClick ), NULL, this );
	m_button4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame4::m_button4OnButtonClick ), NULL, this );
	m_button1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame4::m_button1OnButtonClick ), NULL, this );
	m_button5->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame4::m_button5OnButtonClick ), NULL, this );

}
