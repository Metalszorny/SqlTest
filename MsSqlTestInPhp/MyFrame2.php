<?php

/*
* PHP code generated with wxFormBuilder (version Jun 17 2015)
* http://www.wxformbuilder.org/
*
* PLEASE DO "NOT" EDIT THIS FILE!
*/

include_once 'Person.php';

/*
 * Interaction logic for MyFrame2.
 */
class MyFrame2 extends wxFrame
{
    //<editor-fold defaultstate="collapsed" desc="Fields">

    // The selected index.
    private $selectedIndexValue;

    // The id value.
    private $idValue;

    // The name value.
    private $nameValue;

    // The mothername value.
    private $mothernameValue;

    // The location value.
    private $locationValue;

    // The birthdate value.
    private $birthdateValue;

    // </editor-fold>

    //<editor-fold defaultstate="collapsed" desc="Constructors">

    /**
     * Initializes a new instance of the MyFrame2 class.
     * @param type $parent
     */
    function __construct( $parent=null )
    {
        parent::__construct ( $parent, wxID_ANY, "People", wxDefaultPosition, new wxSize( 715,610 ), wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
        
        $this->SetSizeHints( wxDefaultSize, wxDefaultSize );
        $this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_SCROLLBAR ) );
        
        $gSizer1 = new wxGridSizer( 1, 2, 0, 170 );
        
        $this->m_grid1 = new wxGrid( $this, wxID_ANY, wxDefaultPosition, new wxSize( 430,570 ), wxHSCROLL|wxVSCROLL );
        
        # Grid
        $this->m_grid1->CreateGrid( 0, 5 );
        $this->m_grid1->EnableEditing( false );
        $this->m_grid1->EnableGridLines( true );
        $this->m_grid1->EnableDragGridSize( false );
        $this->m_grid1->SetMargins( 0, 0 );
        
        # Columns
        $this->m_grid1->EnableDragColMove( false );
        $this->m_grid1->EnableDragColSize( true );
        $this->m_grid1->SetColLabelSize( 30 );
        $this->m_grid1->SetColLabelValue( 0, "Id" );
        $this->m_grid1->SetColLabelValue( 1, "Name" );
        $this->m_grid1->SetColLabelValue( 2, "Mothername" );
        $this->m_grid1->SetColLabelValue( 3, "Location" );
        $this->m_grid1->SetColLabelValue( 4, "Birthdate" );
        $this->m_grid1->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
        
        # Rows
        $this->m_grid1->EnableDragRowSize( true );
        $this->m_grid1->SetRowLabelSize( 0 );
        $this->m_grid1->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
        
        # Label Appearance
        
        # Cell Defaults
        $this->m_grid1->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
        $gSizer1->Add( $this->m_grid1, 0, wxALL, 5 );
        
        $gSizer2 = new wxGridSizer( 2, 1, 0, 0 );
        
        $sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( $this, wxID_ANY, "Modify:" ), wxVERTICAL );
        
        $gSizer3 = new wxGridSizer( 2, 1, 0, 0 );
        
        $gSizer5 = new wxGridSizer( 1, 2, 0, 0 );
        
        $gSizer7 = new wxGridSizer( 4, 1, 0, 0 );
        
        $this->m_staticText1 = new wxStaticText( $sbSizer1->GetStaticBox(), wxID_ANY, "Name:", wxDefaultPosition, wxDefaultSize, 0 );
        $this->m_staticText1->Wrap( -1 );
        $gSizer7->Add( $this->m_staticText1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
        
        $this->m_staticText2 = new wxStaticText( $sbSizer1->GetStaticBox(), wxID_ANY, "Mothername:", wxDefaultPosition, wxDefaultSize, 0 );
        $this->m_staticText2->Wrap( -1 );
        $gSizer7->Add( $this->m_staticText2, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
        
        $this->m_staticText3 = new wxStaticText( $sbSizer1->GetStaticBox(), wxID_ANY, "Location:", wxDefaultPosition, wxDefaultSize, 0 );
        $this->m_staticText3->Wrap( -1 );
        $gSizer7->Add( $this->m_staticText3, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
        
        $this->m_staticText4 = new wxStaticText( $sbSizer1->GetStaticBox(), wxID_ANY, "Birthdate:", wxDefaultPosition, wxDefaultSize, 0 );
        $this->m_staticText4->Wrap( -1 );
        $gSizer7->Add( $this->m_staticText4, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
        
        
        $gSizer5->Add( $gSizer7, 1, wxEXPAND, 5 );
        
        $gSizer8 = new wxGridSizer( 4, 1, 0, 0 );
        
        $this->m_textCtrl1 = new wxTextCtrl( $sbSizer1->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
        $gSizer8->Add( $this->m_textCtrl1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
        
        $this->m_textCtrl2 = new wxTextCtrl( $sbSizer1->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
        $gSizer8->Add( $this->m_textCtrl2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
        
        $this->m_textCtrl3 = new wxTextCtrl( $sbSizer1->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
        $gSizer8->Add( $this->m_textCtrl3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
        
        $this->m_textCtrl4 = new wxTextCtrl( $sbSizer1->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
        $gSizer8->Add( $this->m_textCtrl4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
        
        
        $gSizer5->Add( $gSizer8, 1, wxEXPAND, 5 );
        
        
        $gSizer3->Add( $gSizer5, 1, wxEXPAND, 5 );
        
        $gSizer6 = new wxGridSizer( 1, 3, 0, 0 );
        
        $this->m_button2 = new wxButton( $sbSizer1->GetStaticBox(), wxID_ANY, "Add", wxDefaultPosition, wxDefaultSize, 0 );
        $gSizer6->Add( $this->m_button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_BOTTOM, 5 );
        
        $this->m_button3 = new wxButton( $sbSizer1->GetStaticBox(), wxID_ANY, "Edit", wxDefaultPosition, wxDefaultSize, 0 );
        $gSizer6->Add( $this->m_button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_BOTTOM, 5 );
        
        $this->m_button4 = new wxButton( $sbSizer1->GetStaticBox(), wxID_ANY, "Delete", wxDefaultPosition, wxDefaultSize, 0 );
        $gSizer6->Add( $this->m_button4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_BOTTOM, 5 );
        
        
        $gSizer3->Add( $gSizer6, 1, wxEXPAND, 5 );
        
        
        $sbSizer1->Add( $gSizer3, 1, wxEXPAND, 5 );
        
        
        $gSizer2->Add( $sbSizer1, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
        
        $gSizer4 = new wxGridSizer( 1, 2, 0, 0 );
        
        $this->m_button1 = new wxButton( $this, wxID_ANY, "List", wxDefaultPosition, wxDefaultSize, 0 );
        $gSizer4->Add( $this->m_button1, 1, wxALL|wxALIGN_BOTTOM, 5 );
        
        $this->m_button5 = new wxButton( $this, wxID_ANY, "Close", wxDefaultPosition, wxDefaultSize, 0 );
        $gSizer4->Add( $this->m_button5, 1, wxALL|wxALIGN_BOTTOM|wxALIGN_RIGHT, 5 );
        
        
        $gSizer2->Add( $gSizer4, 1, wxEXPAND, 5 );
        
        
        $gSizer1->Add( $gSizer2, 1, wxEXPAND, 5 );
        
        
        $this->SetSizer( $gSizer1 );
        $this->Layout();
        
        $this->Centre( wxBOTH );
        
        // Connect Events
        $this->Connect( wxEVT_ACTIVATE, array($this, "MyFrame2OnActivate") );
        $this->m_grid1->Connect( wxEVT_GRID_SELECT_CELL, array($this, "m_grid1OnGridSelectCell") );
        $this->m_textCtrl1->Connect( wxEVT_COMMAND_TEXT_UPDATED, array($this, "m_textCtrl1OnText") );
        $this->m_textCtrl2->Connect( wxEVT_COMMAND_TEXT_UPDATED, array($this, "m_textCtrl2OnText") );
        $this->m_textCtrl3->Connect( wxEVT_COMMAND_TEXT_UPDATED, array($this, "m_textCtrl3OnText") );
        $this->m_textCtrl4->Connect( wxEVT_COMMAND_TEXT_UPDATED, array($this, "m_textCtrl4OnText") );
        $this->m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, array($this, "m_button2OnButtonClick") );
        $this->m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, array($this, "m_button3OnButtonClick") );
        $this->m_button4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, array($this, "m_button4OnButtonClick") );
        $this->m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, array($this, "m_button1OnButtonClick") );
        $this->m_button5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, array($this, "m_button5OnButtonClick") );
    }

    /**
     * Deletes the instance of the MyFrame2 class.
     */
    function __destruct( )
    { }

    // </editor-fold>

    //<editor-fold defaultstate="collapsed" desc="Methods">

    /**
     * Gets the data.
     */
    function GetData()
    {
        try
        {
            // Clear existing items.
            if ($this->m_grid1->GetNumberRows() - 1 > 0)
            {
                $this->m_grid1->DeleteRows(0, $this->m_grid1->GetNumberRows());
            }
            
            // Open a connection to the database.
            $connection = odbc_connect("Driver={SQL Server};Server=localhost;Database=MsSqlTestDatabase;", "root", "RootUser0123456789");
            
            // Get the items from the People table.
            $people = array();
            $cursor = odbc_exec($connection, "SELECT * FROM [MsSqlTestDatabase].[dbo].[People] WHERE IsDeleted = 0");

            // Store the items in a Person list.
            while(odbc_fetch_row($cursor))
            {
                $people[] = odbc_result($cursor, 1);
                $people[] = odbc_result($cursor, 2);
                $people[] = odbc_result($cursor, 3);
                $people[] = odbc_result($cursor, 4);
                $people[] = odbc_result($cursor, 5);
                $people[] = odbc_result($cursor, 6);
            }

            // Close the connection.
            odbc_close($connection);
            
            // Fill the grid rows with the values of the People table.
            for ($i = 0; $i < count($people) / 6; $i++)
            {
                $this->m_grid1->AppendRows(1);
                
                $this->m_grid1->SetCellValue($this->m_grid1->GetNumberRows() - 1, 0, $people[$i * 6 + 0]);
                $this->m_grid1->SetCellValue($this->m_grid1->GetNumberRows() - 1, 1, $people[$i * 6 + 1]);
                $this->m_grid1->SetCellValue($this->m_grid1->GetNumberRows() - 1, 2, $people[$i * 6 + 2]);
                $this->m_grid1->SetCellValue($this->m_grid1->GetNumberRows() - 1, 3, $people[$i * 6 + 3]);
                $this->m_grid1->SetCellValue($this->m_grid1->GetNumberRows() - 1, 4, explode(" ", $people[$i * 6 + 4])[0]);
            }
        }
        catch (Exception $ex)
        { }
    }

    /**
     * Handles the OnActive event of the MyFrame2 control.
     * @param type $event
     */
    function MyFrame2OnActivate( $event )
    {
        // Preset values.
        $this->GetData();
    }

    /**
     * Handles the OnGridSelectCell event of the grid1 control.
     * @param type $event
     */
    function m_grid1OnGridSelectCell( $event )
    {
        // An item must be selected in the grid.
        if ($event->GetRow() >= 0)
        {
            try
            {
                // Get the selected index.
                $this->selectedIndexValue = $event->GetRow();
                
                // Give the textControl Values the selected values.
                $this->m_textCtrl1->SetValue($this->m_grid1->GetCellValue($this->selectedIndexValue, 1));
                $this->m_textCtrl2->SetValue($this->m_grid1->GetCellValue($this->selectedIndexValue, 2));
                $this->m_textCtrl3->SetValue($this->m_grid1->GetCellValue($this->selectedIndexValue, 3));
                $this->m_textCtrl4->SetValue($this->m_grid1->GetCellValue($this->selectedIndexValue, 4));
            }
            catch (Exception $ex)
            {
                // Empty the textControl Values.
                $this->m_textCtrl1->SetValue('');
                $this->m_textCtrl2->SetValue('');
                $this->m_textCtrl3->SetValue('');
                $this->m_textCtrl4->SetValue('');
            }
        }
        else
        {
            // Empty the textControl Values.
            $this->m_textCtrl1->SetValue('');
            $this->m_textCtrl2->SetValue('');
            $this->m_textCtrl3->SetValue('');
            $this->m_textCtrl4->SetValue('');
        }
    }

    /**
     * Handles the OnText event of the textCtrl1 control.
     * @param type $event
     */
    function m_textCtrl1OnText( $event )
    {
        // Give the field the textControl Text.
        $this->nameValue = $this->m_textCtrl1->GetValue();
    }

    /**
     * Handles the OnText event of the textCtrl2 control.
     * @param type $event
     */
    function m_textCtrl2OnText( $event )
    {
        // Give the field the textControl Text.
        $this->mothernameValue = $this->m_textCtrl2->GetValue();
    }

    /**
     * Handles the OnText event of the textCtrl3 control.
     * @param type $event
     */
    function m_textCtrl3OnText( $event )
    {
        // Give the field the textControl Text.
        $this->locationValue = $this->m_textCtrl3->GetValue();
    }

    /**
     * Handles the OnText event of the textCtrl4 control.
     * @param type $event
     */
    function m_textCtrl4OnText( $event )
    {
        // Give the field the textControl Text.
        $this->birthdateValue = $this->m_textCtrl4->GetValue();
    }

    /**
     * Handles the OnButtonClick event of the button2 control.
     * @param type $event
     */
    function m_button2OnButtonClick( $event )
    {
        // Add a record.
        try
        {
            // The fields must not be empty.
            if ($this->nameValue != null && $this->mothernameValue != null && $this->locationValue != null && $this->birthdateValue != null && 
                $this->nameValue != "" && $this->mothernameValue != "" && $this->locationValue != "" && $this->birthdateValue != "")
            {
                $this->idValue = 0;
                $matchFound = false;
                
                // Open a connection to the database.
                $connection = odbc_connect("Driver={SQL Server};Server=localhost;Database=MsSqlTestDatabase;", "root", "RootUser0123456789");
                
                // Get the items from the People table.
                $cursor = odbc_exec($connection, "SELECT * FROM [MsSqlTestDatabase].[dbo].[People]");

                // Store the items in a Person list.
                while(odbc_fetch_row($cursor))
                {
                    $this->idValue += 1;
                    
                    // Search for a deleted maching item.
                    if ($matchFound == false && odbc_result($cursor, 2) == $this->nameValue && odbc_result($cursor, 3) == $this->mothernameValue && 
                        odbc_result($cursor, 4) == $this->locationValue && explode(" ", odbc_result($cursor, 5))[0] == $this->birthdateValue && 
                        odbc_result($cursor, 6) == true)
                    {
                        $matchFound = true;
                        $this->idValue = odbc_result($cursor, 1);
                        
                        break;
                    }
                }
                
                // Add a new item if no deleted was found else restore the deleted item.
                if ($matchFound == false)
                {
                    // Add new item to the People table.
                    $cursor = odbc_exec($connection, "INSERT INTO [MsSqlTestDatabase].[dbo].[People] (Id, Name, Mothername, Location, Birthdate, IsDeleted) VALUES ('$this->idValue' + 1, '$this->nameValue', '$this->mothernameValue', '$this->locationValue', '$this->birthdateValue', 0)");
                }
                else
                {
                    // Edit the IsDeleted value to false.
                    $cursor = odbc_exec($connection, "UPDATE [MsSqlTestDatabase].[dbo].[People] SET IsDeleted = 0 WHERE Id = '$this->idValue'");
                }
                
                // Close the connection.
                odbc_close($connection);
                
                // Refresh.
                $this->GetData();
            }
        }
        catch (Exception $ex)
        { }
    }

    /**
     * Handles the OnButtonClick event of the button3 control.
     * @param type $event
     */
    function m_button3OnButtonClick( $event )
    {
        // Edit a record.
        try
        {
            // The fields must not be empty.
            if ($this->nameValue != null && $this->mothernameValue != null && $this->locationValue != null && $this->birthdateValue != null && 
                $this->nameValue != "" && $this->mothernameValue != "" && $this->locationValue != "" && $this->birthdateValue != "")
            {
                // An item must be selected in the grid.
                if ($this->selectedIndexValue >= 0)
                {
                    // Get the Id value of the selected item.
                    $this->idValue = $this->m_grid1->GetCellValue($this->selectedIndexValue, 0);
                    
                    // Open a connection to the database.
                    $connection = odbc_connect("Driver={SQL Server};Server=localhost;Database=MsSqlTestDatabase;", "root", "RootUser0123456789");
                
                    // Update the values in the People table.
                    $cursor = odbc_exec($connection, "UPDATE [MsSqlTestDatabase].[dbo].[People] SET Name = '$this->nameValue', Mothername = '$this->mothernameValue', Location = '$this->locationValue', Birthdate = '$this->birthdateValue' WHERE Id = '$this->idValue'");

                    // Close the connection.
                    odbc_close($connection);
                    
                    // Refresh.
                    $this->GetData();
                }
            }
        }
        catch (Exception $ex)
        { }
    }

    /**
     * Handles the OnButtonClick event of the button4 control.
     * @param type $event
     */
    function m_button4OnButtonClick( $event )
    {
        // Delete a record.
        try
        {
            // An item must be selected in the grid.
            if ($this->selectedIndexValue >= 0)
            {
                // Get the Id value of the selected item.
                $this->idValue = $this->m_grid1->GetCellValue($this->selectedIndexValue, 0);
                    
                // Open a connection to the database.
                $connection = odbc_connect("Driver={SQL Server};Server=localhost;Database=MsSqlTestDatabase;", "root", "RootUser0123456789");
                
                // Edit the IsDeleted value to true.
                $cursor = odbc_exec($connection, "UPDATE [MsSqlTestDatabase].[dbo].[People] SET IsDeleted = 1 WHERE Id = '$this->idValue'");

                // Close the connection.
                odbc_close($connection);
                    
                // Refresh.
                $this->GetData();
            }
        }
        catch (Exception $ex)
        { }
    }

    /**
     * Handles the OnButtonClick event of the button1 control.
     * @param type $event
     */
    function m_button1OnButtonClick( $event )
    {
        // List the records.
        $this->GetData();
    }

    /**
     * Handles the OnButtonClick event of the button5 control.
     * @param type $event
     */
    function m_button5OnButtonClick( $event )
    {
        // Close the Frame.
        $this->Close();
    }

    // </editor-fold>
}

?>
