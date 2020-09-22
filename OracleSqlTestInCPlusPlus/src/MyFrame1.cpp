///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MyFrame1.h"

///////////////////////////////////////////////////////////////////////////

/// \brief Initializes a new instance of the MyFrame1 class.
/// \par parent
/// \par id
/// \par title
/// \par pos
/// \par size
/// \par style
MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_SCROLLBAR ) );

	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 9, 1, 0, 0 );

	wxGridSizer* gSizer2;
	gSizer2 = new wxGridSizer( 1, 1, 0, 0 );


	gSizer1->Add( gSizer2, 1, wxEXPAND, 5 );

	m_button1 = new wxButton( this, wxID_ANY, wxT("People"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	wxGridSizer* gSizer3;
	gSizer3 = new wxGridSizer( 1, 1, 0, 0 );


	gSizer1->Add( gSizer3, 1, wxEXPAND, 5 );

	m_button2 = new wxButton( this, wxID_ANY, wxT("Relationships"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	wxGridSizer* gSizer4;
	gSizer4 = new wxGridSizer( 1, 1, 0, 0 );


	gSizer1->Add( gSizer4, 1, wxEXPAND, 5 );

	m_button3 = new wxButton( this, wxID_ANY, wxT("Relations"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_button3, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxGridSizer* gSizer5;
	gSizer5 = new wxGridSizer( 1, 1, 0, 0 );


	gSizer1->Add( gSizer5, 1, wxEXPAND, 5 );

	m_button4 = new wxButton( this, wxID_ANY, wxT("Exit"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_button4, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxGridSizer* gSizer6;
	gSizer6 = new wxGridSizer( 1, 1, 0, 0 );


	gSizer1->Add( gSizer6, 1, wxEXPAND, 5 );


	this->SetSizer( gSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button1OnButtonClick ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button2OnButtonClick ), NULL, this );
	m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button3OnButtonClick ), NULL, this );
	m_button4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button4OnButtonClick ), NULL, this );
}

/// \brief Clean up any resources being used.
MyFrame1::~MyFrame1()
{
	// Disconnect Events
	m_button1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button1OnButtonClick ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button2OnButtonClick ), NULL, this );
	m_button3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button3OnButtonClick ), NULL, this );
	m_button4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button4OnButtonClick ), NULL, this );

}
