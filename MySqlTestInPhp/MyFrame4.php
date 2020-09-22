<?php

/*
* PHP code generated with wxFormBuilder (version Jun 17 2015)
* http://www.wxformbuilder.org/
*
* PLEASE DO "NOT" EDIT THIS FILE!
*/

include_once 'Person.php';
include_once 'Relationship.php';
include_once 'Relation.php';

/*
 * Interaction logic for MyFrame4.
 */
class MyFrame4 extends wxFrame
{
    //<editor-fold defaultstate="collapsed" desc="Fields">

    // The selected index.
    private $selectedIndexValue;

    // The id value.
    private $idValue;

    // The name1 value.
    private $name1Value;

    // The relationship value.
    private $relationshipValue;

    // The name2 value.
    private $name2Value;

    // </editor-fold>

    //<editor-fold defaultstate="collapsed" desc="Constructors">

    /**
     * Initializes a new instance of the MyFrame4 class.
     * @param type $parent
     */
    function __construct( $parent=null )
    {
        parent::__construct ( $parent, wxID_ANY, "Relations", wxDefaultPosition, new wxSize( 715,610 ), wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
        
        $this->SetSizeHints( wxDefaultSize, wxDefaultSize );
        $this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_SCROLLBAR ) );
        
        $gSizer1 = new wxGridSizer( 1, 2, 0, 170 );
        
        $this->m_grid1 = new wxGrid( $this, wxID_ANY, wxDefaultPosition, new wxSize( 430,570 ), wxHSCROLL|wxWANTS_CHARS );
        
        # Grid
        $this->m_grid1->CreateGrid( 0, 4 );
        $this->m_grid1->EnableEditing( false );
        $this->m_grid1->EnableGridLines( true );
        $this->m_grid1->EnableDragGridSize( false );
        $this->m_grid1->SetMargins( 0, 0 );
        
        # Columns
        $this->m_grid1->EnableDragColMove( false );
        $this->m_grid1->EnableDragColSize( true );
        $this->m_grid1->SetColLabelSize( 30 );
        $this->m_grid1->SetColLabelValue( 0, "Id" );
        $this->m_grid1->SetColLabelValue( 1, "Person1" );
        $this->m_grid1->SetColLabelValue( 2, "Relationship" );
        $this->m_grid1->SetColLabelValue( 3, "Person2" );
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
        
        $gSizer7 = new wxGridSizer( 1, 2, 0, 0 );
        
        $gSizer9 = new wxGridSizer( 4, 1, 0, 0 );
        
        $this->m_staticText1 = new wxStaticText( $sbSizer1->GetStaticBox(), wxID_ANY, "Person1:", wxDefaultPosition, wxDefaultSize, 0 );
        $this->m_staticText1->Wrap( -1 );
        $gSizer9->Add( $this->m_staticText1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
        
        $this->m_staticText2 = new wxStaticText( $sbSizer1->GetStaticBox(), wxID_ANY, "Relationship:", wxDefaultPosition, wxDefaultSize, 0 );
        $this->m_staticText2->Wrap( -1 );
        $gSizer9->Add( $this->m_staticText2, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
        
        $this->m_staticText3 = new wxStaticText( $sbSizer1->GetStaticBox(), wxID_ANY, "Person2:", wxDefaultPosition, wxDefaultSize, 0 );
        $this->m_staticText3->Wrap( -1 );
        $gSizer9->Add( $this->m_staticText3, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
        
        
        $gSizer7->Add( $gSizer9, 1, wxEXPAND, 5 );
        
        $gSizer10 = new wxGridSizer( 4, 1, 0, 0 );
        
        $m_comboBox1Choices = array();
        $this->m_comboBox1 = new wxComboBox( $sbSizer1->GetStaticBox(), wxID_ANY, "Combo!", wxDefaultPosition, wxDefaultSize, $m_comboBox1Choices, 0 );
        $gSizer10->Add( $this->m_comboBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
        
        $m_comboBox2Choices = array();
        $this->m_comboBox2 = new wxComboBox( $sbSizer1->GetStaticBox(), wxID_ANY, "Combo!", wxDefaultPosition, wxDefaultSize, $m_comboBox2Choices, 0 );
        $gSizer10->Add( $this->m_comboBox2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
        
        $m_comboBox3Choices = array();
        $this->m_comboBox3 = new wxComboBox( $sbSizer1->GetStaticBox(), wxID_ANY, "Combo!", wxDefaultPosition, wxDefaultSize, $m_comboBox3Choices, 0 );
        $gSizer10->Add( $this->m_comboBox3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
        
        
        $gSizer7->Add( $gSizer10, 1, wxEXPAND, 5 );
        
        
        $gSizer3->Add( $gSizer7, 1, wxEXPAND, 5 );
        
        $gSizer8 = new wxGridSizer( 1, 3, 0, 0 );
        
        $this->m_button2 = new wxButton( $sbSizer1->GetStaticBox(), wxID_ANY, "Add", wxDefaultPosition, wxDefaultSize, 0 );
        $gSizer8->Add( $this->m_button2, 1, wxALL|wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL, 5 );
        
        $this->m_button3 = new wxButton( $sbSizer1->GetStaticBox(), wxID_ANY, "Edit", wxDefaultPosition, wxDefaultSize, 0 );
        $gSizer8->Add( $this->m_button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_BOTTOM, 5 );
        
        $this->m_button4 = new wxButton( $sbSizer1->GetStaticBox(), wxID_ANY, "Delete", wxDefaultPosition, wxDefaultSize, 0 );
        $gSizer8->Add( $this->m_button4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_BOTTOM, 5 );
        
        
        $gSizer3->Add( $gSizer8, 1, wxEXPAND, 5 );
        
        
        $sbSizer1->Add( $gSizer3, 1, wxEXPAND, 5 );
        
        
        $gSizer2->Add( $sbSizer1, 1, wxEXPAND, 5 );
        
        $gSizer4 = new wxGridSizer( 2, 1, 0, 0 );
        
        $sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( $this, wxID_ANY, "Helper:" ), wxVERTICAL );
        
        $gSizer6 = new wxGridSizer( 1, 2, 0, 0 );
        
        $gSizer11 = new wxGridSizer( 4, 1, 0, 0 );
        
        $this->m_staticText4 = new wxStaticText( $sbSizer2->GetStaticBox(), wxID_ANY, "Person1:", wxDefaultPosition, wxDefaultSize, 0 );
        $this->m_staticText4->Wrap( -1 );
        $gSizer11->Add( $this->m_staticText4, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
        
        $this->m_staticText5 = new wxStaticText( $sbSizer2->GetStaticBox(), wxID_ANY, "Relationship:", wxDefaultPosition, wxDefaultSize, 0 );
        $this->m_staticText5->Wrap( -1 );
        $gSizer11->Add( $this->m_staticText5, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
        
        $this->m_staticText6 = new wxStaticText( $sbSizer2->GetStaticBox(), wxID_ANY, "Person2:", wxDefaultPosition, wxDefaultSize, 0 );
        $this->m_staticText6->Wrap( -1 );
        $gSizer11->Add( $this->m_staticText6, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
        
        
        $gSizer6->Add( $gSizer11, 1, wxEXPAND, 5 );
        
        $gSizer12 = new wxGridSizer( 4, 1, 0, 0 );
        
        $this->m_staticText7 = new wxStaticText( $sbSizer2->GetStaticBox(), wxID_ANY, "MyLabel", wxDefaultPosition, wxDefaultSize, 0 );
        $this->m_staticText7->Wrap( -1 );
        $gSizer12->Add( $this->m_staticText7, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
        
        $this->m_staticText8 = new wxStaticText( $sbSizer2->GetStaticBox(), wxID_ANY, "MyLabel", wxDefaultPosition, wxDefaultSize, 0 );
        $this->m_staticText8->Wrap( -1 );
        $gSizer12->Add( $this->m_staticText8, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
        
        $this->m_staticText9 = new wxStaticText( $sbSizer2->GetStaticBox(), wxID_ANY, "MyLabel", wxDefaultPosition, wxDefaultSize, 0 );
        $this->m_staticText9->Wrap( -1 );
        $gSizer12->Add( $this->m_staticText9, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
        
        
        $gSizer6->Add( $gSizer12, 1, wxEXPAND, 5 );
        
        
        $sbSizer2->Add( $gSizer6, 1, wxEXPAND, 5 );
        
        
        $gSizer4->Add( $sbSizer2, 1, wxEXPAND, 5 );
        
        $gSizer5 = new wxGridSizer( 1, 2, 0, 0 );
        
        $this->m_button1 = new wxButton( $this, wxID_ANY, "List", wxDefaultPosition, wxDefaultSize, 0 );
        $gSizer5->Add( $this->m_button1, 1, wxALL|wxALIGN_BOTTOM, 5 );
        
        $this->m_button5 = new wxButton( $this, wxID_ANY, "Close", wxDefaultPosition, wxDefaultSize, 0 );
        $gSizer5->Add( $this->m_button5, 1, wxALL|wxALIGN_BOTTOM|wxALIGN_RIGHT, 5 );
        
        
        $gSizer4->Add( $gSizer5, 1, wxEXPAND, 5 );
        
        
        $gSizer2->Add( $gSizer4, 1, wxEXPAND, 5 );
        
        
        $gSizer1->Add( $gSizer2, 1, wxEXPAND, 5 );
        
        
        $this->SetSizer( $gSizer1 );
        $this->Layout();
        
        $this->Centre( wxBOTH );
        
        // Connect Events
        $this->Connect( wxEVT_ACTIVATE, array($this, "MyFrame4OnActivate") );
        $this->m_grid1->Connect( wxEVT_GRID_SELECT_CELL, array($this, "m_grid1OnGridSelectCell") );
        $this->m_comboBox1->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, array($this, "m_comboBox1OnCombobox") );
        $this->m_comboBox2->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, array($this, "m_comboBox2OnCombobox") );
        $this->m_comboBox3->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, array($this, "m_comboBox3OnCombobox") );
        $this->m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, array($this, "m_button2OnButtonClick") );
        $this->m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, array($this, "m_button3OnButtonClick") );
        $this->m_button4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, array($this, "m_button4OnButtonClick") );
        $this->m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, array($this, "m_button1OnButtonClick") );
        $this->m_button5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, array($this, "m_button5OnButtonClick") );
    }

    /**
     * Deletes the instance of the MyFrame4 class.
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
            $this->m_comboBox1->Clear();
            $this->m_comboBox2->Clear();
            $this->m_comboBox3->Clear();
            
            // Open a connection to the database.
            $connection = mysqli_connect("localhost", "root", "root", "MySqlTestDatabase");
            
            // Get the items from the People table.
            $people = array();
            $cursor = mysqli_query($connection, "SELECT * FROM MySqlTestDatabase.People");
            
            // Execute.
            $result = mysqli_fetch_all($cursor);
            
            // Store the items in a Person list.
            foreach ($result as $oneRow)
            {
                foreach ($oneRow as $oneCell)
                {
                    $people[] = $oneCell;
                }
            }
            
            // Get the items from the Relationships table.
            $relationships = array();
            $cursor = mysqli_query($connection, "SELECT * FROM MySqlTestDatabase.Relationships");
            
            // Execute.
            $result = mysqli_fetch_all($cursor);
            
            // Store the items in a Relationship list.
            foreach ($result as $oneRow)
            {
                foreach ($oneRow as $oneCell)
                {
                    $relationships[] = $oneCell;
                }
            }
            
            // Get the items from the Relations table.
            $relations = array();
            $cursor = mysqli_query($connection, "SELECT * FROM MySqlTestDatabase.Relations WHERE IsDeleted = 0");
            
            // Execute.
            $result = mysqli_fetch_all($cursor);
            
            // Store the items in a Person list.
            foreach ($result as $oneRow)
            {
                foreach ($oneRow as $oneCell)
                {
                    $relations[] = $oneCell;
                }
            }
            
            // Close the connection.
            mysqli_close($connection);
            
            // Fill the grid rows with the values of the Relations table.
            for ($i = 0; $i < count($relations) / 5; $i++)
            {
                $this->m_grid1->AppendRows(1);
                
                $this->m_grid1->SetCellValue($this->m_grid1->GetNumberRows() - 1, 0, $relations[$i * 5 + 0]);
                
                // Substitute the Person1 and Person2 ids with their names.
                for ($j = 0; $j < count($people) / 6; $j++)
                {
                    if ($relations[$i * 5 + 1] == $people[$j * 6 + 0])
                    {
                        $this->m_grid1->SetCellValue($this->m_grid1->GetNumberRows() - 1, 1, $people[$j * 6 + 1]);
                    }
                    
                    if ($relations[$i * 5 + 3] == $people[$j * 6 + 0])
                    {
                        $this->m_grid1->SetCellValue($this->m_grid1->GetNumberRows() - 1, 3, $people[$j * 6 + 1]);
                    }
                }
                
                // Substitute the Relationship ids with their names.
                for ($j = 0; $j < count($relationships) / 3; $j++)
                {
                    if ($relations[$i * 5 + 2] == $relationships[$j * 3 + 0])
                    {
                        $this->m_grid1->SetCellValue($this->m_grid1->GetNumberRows() - 1, 2, $relationships[$j * 3 + 1]);
                    }
                }
            }
            
            // Fill the comboBox items with the values of the People table.
            for ($i = 0; $i < count($people) / 6; $i++)
            {
                if ($people[$i * 6 + 5] == false)
                {
                    $this->m_comboBox1->Append($people[$i * 6 + 0]);
                    $this->m_comboBox3->Append($people[$i * 6 + 0]);
                }
            }
            
            // Fill the comboBox items with the values of the Relationships table.
            for ($i = 0; $i < count($relationships) / 3; $i++)
            {
                if ($relationships[$i * 3 + 2] == false)
                {
                    $this->m_comboBox2->Append($relationships[$i * 3 + 0]);
                }
            }
        }
        catch (Exception $ex)
        { }
    }

    /**
     * Handles the OnActive event of the MyFrame4 control.
     * @param type $event
     */
    function MyFrame4OnActivate( $event )
    {
        // Preset values.
        $this->m_staticText7->SetLabelText('');
        $this->m_staticText8->SetLabelText('');
        $this->m_staticText9->SetLabelText('');

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
                // Get the Id value of the selected item.
                $this->selectedIndexValue = $event->GetRow();
                $this->idValue = $this->m_grid1->GetCellValue($this->selectedIndexValue, 0);
                
                // Open a connection to the database.
                $connection = mysqli_connect("localhost", "root", "root", "MySqlTestDatabase");
                
                // Get the items from the Relations table.
                $relation = array();
                $cursor = mysqli_query($connection, "SELECT * FROM MySqlTestDatabase.Relations WHERE Id = '$this->idValue'");
                
                // Execute.
                $result = mysqli_fetch_all($cursor);
                
                // Store it in a Relation object.
                foreach ($result as $oneRow)
                {
                    foreach ($oneRow as $oneCell)
                    {
                        $relation[] = $oneCell;
                    }
                }
                
                // Give the comboBox Values the selected values.
                $this->m_comboBox1->SetValue($relation[1]);
                $this->m_comboBox2->SetValue($relation[2]);
                $this->m_comboBox3->SetValue($relation[3]);
                
                // Invoke the Selected Index Change methods.
                $this->m_comboBox1OnCombobox(null);
                $this->m_comboBox2OnCombobox(null);
                $this->m_comboBox3OnCombobox(null);
                
                // Close the connection.
                mysqli_close($connection);
            }
            catch (Exception $ex)
            {
                // Empty the comboBox Values.
                $this->m_comboBox1->SetValue('');
                $this->m_comboBox2->SetValue('');
                $this->m_comboBox3->SetValue('');
            }
        }
        else
        {
            // Empty the comboBox Values.
            $this->m_comboBox1->SetValue('');
            $this->m_comboBox2->SetValue('');
            $this->m_comboBox3->SetValue('');
        }
    }

    /**
     * Handles the OnCombobox event of the comboBox1 control.
     * @param type $event
     */
    function m_comboBox1OnCombobox( $event )
    {
        try
        {
            // Store the comboBox selected item.
            $this->name1Value = $this->m_comboBox1->GetValue();
            
            // Open a connection to the database.
            $connection = mysqli_connect("localhost", "root", "root", "MySqlTestDatabase");
            
            // Get the items from the People table.
            $retVal = array();
            $cursor = mysqli_query($connection, "SELECT * FROM MySqlTestDatabase.People WHERE Id = '$this->name1Value'");
            
            // Execute.
            $result = mysqli_fetch_all($cursor);
            
            // Store it in a Person object.
            foreach ($result as $oneRow)
            {
                foreach ($oneRow as $oneCell)
                {
                    $retVal[] = $oneCell;
                }
            }
            
            // Give the staticText Text the selected values.
            $this->m_staticText7->SetLabelText($retVal[1]);
            
            // Close the connection.
            mysqli_close($connection);
        }
        catch (Exception $ex)
        { }
    }

    /**
     * Handles the OnCombobox event of the comboBox2 control.
     * @param type $event
     */
    function m_comboBox2OnCombobox( $event )
    {
        try
        {
            // Store the comboBox selected item.
            $this->relationshipValue = $this->m_comboBox2->GetValue();
            
            // Open a connection to the database.
            $connection = mysqli_connect("localhost", "root", "root", "MySqlTestDatabase");
            
            // Get the items from the Relationships table.
            $retVal = array();
            $cursor = mysqli_query($connection, "SELECT * FROM MySqlTestDatabase.Relationships WHERE Id = '$this->relationshipValue'");
            
            // Execute.
            $result = mysqli_fetch_all($cursor);
            
            // Store it in a Relationship object.
            foreach ($result as $oneRow)
            {
                foreach ($oneRow as $oneCell)
                {
                    $retVal[] = $oneCell;
                }
            }
            
            // Give the staticText Text the selected values.
            $this->m_staticText8->SetLabelText($retVal[1]);
            
            // Close the connection.
            mysqli_close($connection);
        }
        catch (Exception $ex)
        { }
    }

    /**
     * Handles the OnCombobox event of the comboBox3 control.
     * @param type $event
     */
    function m_comboBox3OnCombobox( $event )
    {
        try
        {
            // Store the comboBox selected item.
            $this->name2Value = $this->m_comboBox3->GetValue();
            
            // Open a connection to the database.
            $connection = mysqli_connect("localhost", "root", "root", "MySqlTestDatabase");
            
            // Get the items from the People table.
            $retVal = array();
            $cursor = mysqli_query($connection, "SELECT * FROM MySqlTestDatabase.People WHERE Id = '$this->name2Value'");
            
            // Execute.
            $result = mysqli_fetch_all($cursor);
            
            // Store it in a Person object.
            foreach ($result as $oneRow)
            {
                foreach ($oneRow as $oneCell)
                {
                    $retVal[] = $oneCell;
                }
            }
            
            // Give the staticText Text the selected values.
            $this->m_staticText9->SetLabelText($retVal[1]);
            
            // Close the connection.
            mysqli_close($connection);
        }
        catch (Exception $ex)
        { }
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
            // The fileds must not be empty and the names must not match.
            if ($this->name1Value != null && $this->relationshipValue != null && $this->name2Value != null && 
                $this->name1Value > 0 && $this->relationshipValue > 0 && $this->name2Value > 0 && $this->name1Value != $this->name2Value)
            {
                $this->idValue = 0;
                $matchFound = false;
                
                // Open a connection to the database.
                $connection = mysqli_connect("localhost", "root", "root", "MySqlTestDatabase");
                
                // Get the items from the Relations table.
                $cursor = mysqli_query($connection, "SELECT * FROM MySqlTestDatabase.Relations");
                
                // Execute.
                $result = mysqli_fetch_all($cursor);
                
                // Store the items in a Relation list.
                foreach ($result as $oneRow)
                {
                    $this->idValue += 1;
                    
                    // Search for a deleted maching item.
                    if ($matchFound == false && $oneRow[1] == $this->name1Value && $oneRow[2] == $this->relationshipValue && 
                        $oneRow[3] == $this->name2Value && $oneRow[4] == true)
                    {
                        $matchFound = true;
                        $this->idValue = $oneRow[0];
                        
                        break;
                    }
                }
                
                // Add a new item if no deleted was found else restore the deleted item.
                if ($matchFound == false)
                {
                    // Add new item to the Relations table.
                    $cursor = mysqli_query($connection, "INSERT INTO MySqlTestDatabase.Relations (Id, Person1, Relationship, Person2, IsDeleted) VALUES ('$this->idValue' + 1, '$this->name1Value', '$this->relationshipValue', '$this->name2Value', false)");
                }
                else
                {
                    // Edit the IsDeleted value to false.
                    $cursor = mysqli_query($connection, "UPDATE MySqlTestDatabase.Relations SET IsDeleted = false WHERE Id = '$this->idValue'");
                }
                
                // Close the connection.
                mysqli_close($connection);
                
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
            // The fileds must not be empty and the names must not match.
            if ($this->name1Value != null && $this->relationshipValue != null && $this->name2Value != null && 
                $this->name1Value > 0 && $this->relationshipValue > 0 && $this->name2Value > 0 && $this->name1Value != $this->name2Value)
            {
                // An item must be selected in the grid.
                if ($this->selectedIndexValue >= 0)
                {
                    // Get the Id value of the selected item.
                    $this->idValue = $this->m_grid1->GetCellValue($this->selectedIndexValue, 0);
                    
                    // Open a connection to the database.
                    $connection = mysqli_connect("localhost", "root", "root", "MySqlTestDatabase");
                
                    // Update the values in the Relations table.
                    $cursor = mysqli_query($connection, "UPDATE MySqlTestDatabase.Relations SET Person1 = '$this->name1Value', Relationship = '$this->relationshipValue', Person2 = '$this->name2Value' WHERE Id = '$this->idValue'");

                    // Close the connection.
                    mysqli_close($connection);
                    
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
                $connection = mysqli_connect("localhost", "root", "root", "MySqlTestDatabase");
                
                // Edit the IsDeleted value to true.
                $cursor = mysqli_query($connection, "UPDATE MySqlTestDatabase.Relations SET IsDeleted = true WHERE Id = '$this->idValue'");

                // Close the connection.
                mysqli_close($connection);
                    
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
