<?php

/*
* PHP code generated with wxFormBuilder (version Jun 17 2015)
* http://www.wxformbuilder.org/
*
* PLEASE DO "NOT" EDIT THIS FILE!
*/

include_once 'MyFrame2.php';
include_once 'MyFrame3.php';
include_once 'MyFrame4.php';

/*
 * Interaction logic for MyFrame1.
 */
class MyFrame1 extends wxFrame
{
    //<editor-fold defaultstate="collapsed" desc="Constructors">

    /**
     * Initializes a new instance of the MyFrame1 class.
     * @param type $parent
     */
    function __construct( $parent=null )
    {
        parent::__construct ( $parent, wxID_ANY, "Menu", wxDefaultPosition, new wxSize( 230,300 ), wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
	
        $this->SetSizeHints( wxDefaultSize, wxDefaultSize );
        $this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_SCROLLBAR ) );
	
        $gSizer1 = new wxGridSizer( 9, 1, 0, 0 );
	
        $gSizer2 = new wxGridSizer( 1, 1, 0, 0 );
	
	
        $gSizer1->Add( $gSizer2, 1, wxEXPAND, 5 );
	
        $this->m_button1 = new wxButton( $this, wxID_ANY, "People", wxDefaultPosition, wxDefaultSize, 0 );
        $gSizer1->Add( $this->m_button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
        $gSizer3 = new wxGridSizer( 1, 1, 0, 0 );
	
	
        $gSizer1->Add( $gSizer3, 1, wxEXPAND, 5 );
	
        $this->m_button2 = new wxButton( $this, wxID_ANY, "Relationships", wxDefaultPosition, wxDefaultSize, 0 );
        $gSizer1->Add( $this->m_button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
        $gSizer4 = new wxGridSizer( 1, 1, 0, 0 );
	
	
        $gSizer1->Add( $gSizer4, 1, wxEXPAND, 5 );
	
        $this->m_button3 = new wxButton( $this, wxID_ANY, "Relations", wxDefaultPosition, wxDefaultSize, 0 );
        $gSizer1->Add( $this->m_button3, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
        $gSizer5 = new wxGridSizer( 1, 1, 0, 0 );
	
	
        $gSizer1->Add( $gSizer5, 1, wxEXPAND, 5 );
	
        $this->m_button4 = new wxButton( $this, wxID_ANY, "Exit", wxDefaultPosition, wxDefaultSize, 0 );
        $gSizer1->Add( $this->m_button4, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
        $gSizer6 = new wxGridSizer( 1, 1, 0, 0 );
	
	
        $gSizer1->Add( $gSizer6, 1, wxEXPAND, 5 );
	
	
        $this->SetSizer( $gSizer1 );
        $this->Layout();
	
        $this->Centre( wxBOTH );
	
        // Connect Events
        $this->m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, array($this, "m_button1OnButtonClick") );
        $this->m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, array($this, "m_button2OnButtonClick") );
        $this->m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, array($this, "m_button3OnButtonClick") );
        $this->m_button4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, array($this, "m_button4OnButtonClick") );
    }

    /**
     * Deletes the instance of the MyFrame1 class.
     */
    function __destruct( )
    { }

    // </editor-fold>

    //<editor-fold defaultstate="collapsed" desc="Methods">

    /**
     * Handles the OnButtonClick event of the button1 control.
     * @param type $event
     */
    function m_button1OnButtonClick( $event )
    {
        // Open the People Frame.
        $people = new MyFrame2(null);
        $people->Show();
    }

    /**
     * Handles the OnButtonClick event of the button2 control.
     * @param type $event
     */
    function m_button2OnButtonClick( $event )
    {
        // Open the Relationships Frame.
        $relationships = new MyFrame3(null);
        $relationships->Show();
    }

    /**
     * Handles the OnButtonClick event of the button3 control.
     * @param type $event
     */
    function m_button3OnButtonClick( $event )
    {
        // Open the Relations Frame.
        $relations = new MyFrame4(null);
        $relations->Show();
    }

    /**
     * Handles the OnButtonClick event of the button4 control.
     * @param type $event
     */
    function m_button4OnButtonClick( $event )
    {
        // Exit the Program.
        $this->Close();
    }

    // </editor-fold>
}

?>