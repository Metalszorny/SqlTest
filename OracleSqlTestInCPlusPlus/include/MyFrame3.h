///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef MYFRAME3_H
#define MYFRAME3_H

#include <windows.h>
#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/sizer.h>
#include <wx/gdicmn.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/frame.h>
#include <wx/grid.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statbox.h>
#include <wx/combobox.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <vector>
#include <Relationship.h>

///////////////////////////////////////////////////////////////////////////

using namespace std;

///////////////////////////////////////////////////////////////////////////////
/// \brief Interaction logic for MyFrame3.
///////////////////////////////////////////////////////////////////////////////
class MyFrame3 : public wxFrame
{
	protected:

	private:
		wxGrid* m_grid1;
		wxStaticText* m_staticText1;
		wxTextCtrl* m_textCtrl1;
		wxButton* m_button2;
		wxButton* m_button3;
		wxButton* m_button4;
		wxButton* m_button1;
		wxButton* m_button5;

		#ifndef REGION_Fields

		// The selected index.
        int selectedIndex;

        // The id value.
        int id;

        // The name value.
        string name;

        #endif // REGION_Fields

        #ifndef REGION_Methods

		/// \brief Handles the OnActivate event of the MyFrame3 control.
        /// \par event The wxActivateEvent instance containing the event data.
		virtual void MyFrame3OnActivate( wxActivateEvent& event )
		{
		    // Preset values.
            this->GetData();
		}

        /// \brief Handles the OnGridSelectCell event of the grid1 control.
        /// \par event The wxGridEvent instance containing the event data.
		virtual void m_grid1OnGridSelectCell( wxGridEvent& event )
		{
		    // An item must be selected in the grid.
		    if (event.GetRow() >= 0)
            {
                try
                {
                    // Get the selected index.
                    this->selectedIndex = event.GetRow();

                    // Give the textControl Values the selected values.
                    this->m_textCtrl1->SetValue(this->m_grid1->GetCellValue(this->selectedIndex, 1));
                }
                catch (...)
                {
                    // Empty the textControl Values.
                    this->m_textCtrl1->SetValue("");
                }
            }
            else
            {
                // Empty the textControl Values.
                this->m_textCtrl1->SetValue("");
            }
		}

        /// \brief Handles the OnText event of the textCtrl1 control.
        /// \par event The wxCommandEvent instance containing the event data.
		virtual void m_textCtrl1OnText( wxCommandEvent& event )
		{
		    // Give the field the textControl Text.
		    this->name = this->m_textCtrl1->GetValue();
		}

        /// \brief Handles the OnButtonClick event of the button2 control.
        /// \par event The wxCommandEvent instance containing the event data.
		virtual void m_button2OnButtonClick( wxCommandEvent& event )
		{
		    // Adds a record.
		    try
		    {
                // The fields must not be empty.
                if (/*this->name != NULL &&*/ this->name != "")
                {
                    /*this->id = 0;
                    bool matchFound = false;
                    bool deletedFound = false;

                    // Open a connection to the database.
                    SQLWCHAR retconstring[1024];
                    SQLHANDLE sqlenvhandle;
                    SQLHANDLE sqlconnectionhandle;
                    SQLHANDLE sqlstatementhandle;
                    // Allocate an environment handle.
                    SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlenvhandle);
                    // We want ODBC 3 support.
                    SQLSetEnvAttr(sqlenvhandle,SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);
                    // Allocate a connection handle.
                    SQLAllocHandle(SQL_HANDLE_DBC, sqlenvhandle, &sqlconnectionhandle);
                    // Connect to the DSN.
                    SQLDriverConnect(sqlconnectionhandle, NULL, (SQLWCHAR*)L"DSN=MySqlTestDatabase;SERVER=localhost;UID=root;PWD=root;DRIVER=MySQL Server;", SQL_NTS, retconstring, 1024, NULL, SQL_DRIVER_NOPROMPT);

                    // Get the items from the Relationships table.
                    // Allocate statement handle.
                    SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle);
                    // Process data.
                    SQLExecDirect(sqlstatementhandle, (SQLWCHAR*)L"SELECT * FROM MySqlTestDatabase.Relationships", SQL_NTS);

                    // Store the items in a Relationship list.
                    while(SQLFetch(sqlstatementhandle) == SQL_SUCCESS)
                    {
                        this->id += 1;

                        int idValue;
                        char nameValue[50];
                        bool isDeletedValue;

                        // Get the values from the statement.
                        SQLGetData(sqlstatementhandle, 1, SQL_C_ULONG, &idValue, 0, NULL);
                        SQLGetData(sqlstatementhandle, 2, SQL_C_CHAR, nameValue, 50, NULL);
                        SQLGetData(sqlstatementhandle, 3, SQL_C_BIT, &isDeletedValue, 0, NULL);

                        // Check if the new item already exists.
                        if (!matchFound && string(nameValue) == this->name && isDeletedValue == false)
                        {
                            matchFound = true;

                            break;
                        }

                        // Check if a deleted already exists.
                        if (!matchFound && string(nameValue) == this->name && isDeletedValue == true)
                        {
                            deletedFound = true;
                            this->id = idValue;

                            break;
                        }
                    }

                    // If no match was found.
                    if (matchFound == false)
                    {
                        // Add a new item if no deleted was found else restore the deleted item.
                        if (deletedFound == false)
                        {
                            // Add new item to the Relationships table.
                            // Allocate statement handle.
                            SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle);
                            // Process data.
                            SQLPrepare(sqlstatementhandle, (SQLWCHAR*)L"INSERT INTO MySqlTestDatabase.Relationships (Id, Name, IsDeleted) VALUES (?, ?, 0)", SQL_NTS);

                            this->id += 1;

                            // Data conversions.
                            char value1[50];
                            strncpy(value1, this->name.c_str(), sizeof(value1));
                            value1[sizeof(value1) - 1] = 0;

                            // Fill the values.
                            SQLBindParameter(sqlstatementhandle, 1, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 0, 0, &this->id, 0, 0);
                            SQLBindParameter(sqlstatementhandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 50, 0, value1, 50, 0);

                            // Execute.
                            SQLExecute(sqlstatementhandle);
                        }
                        else
                        {
                            // Edit the IsDeleted value to false.
                            // Allocate statement handle.
                            SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle);
                            // Process data.
                            SQLPrepare(sqlstatementhandle, (SQLWCHAR*)L"UPDATE MySqlTestDatabase.Relationships SET IsDeleted = 0 WHERE Id = ?", SQL_NTS);

                            // Fill the values.
                            SQLBindParameter(sqlstatementhandle, 1, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 0, 0, &this->id, 0, 0);

                            // Execute.
                            SQLExecute(sqlstatementhandle);
                        }
                    }

                    // Close the connection.
                    SQLFreeHandle(SQL_HANDLE_STMT, sqlstatementhandle);
                    SQLDisconnect(sqlconnectionhandle);
                    SQLFreeHandle(SQL_HANDLE_DBC, sqlconnectionhandle);
                    SQLFreeHandle(SQL_HANDLE_ENV, sqlenvhandle);

                    // Refresh.
                    this->GetData();*/
                }
		    }
		    catch (...)
		    { }
		}

        /// \brief Handles the OnButtonClick event of the button3 control.
        /// \par event The wxCommandEvent instance containing the event data.
		virtual void m_button3OnButtonClick( wxCommandEvent& event )
		{
		    // Edits a record.
		    try
		    {
                // The fields must not be empty.
                if (/*this->name != NULL &&*/ this->name != "")
                {
                    /*// An item must be selected in the grid.
                    if (this->selectedIndex >= 0)
                    {
                        // Get the Id value of the selected item.
                         this->id = wxAtoi(this->m_grid1->GetCellValue(this->selectedIndex, 0));

                        // Open a connection to the database.
                        SQLWCHAR retconstring[1024];
                        SQLHANDLE sqlenvhandle;
                        SQLHANDLE sqlconnectionhandle;
                        SQLHANDLE sqlstatementhandle;
                        // Allocate an environment handle.
                        SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlenvhandle);
                        // We want ODBC 3 support.
                        SQLSetEnvAttr(sqlenvhandle,SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);
                        // Allocate a connection handle.
                        SQLAllocHandle(SQL_HANDLE_DBC, sqlenvhandle, &sqlconnectionhandle);
                        // Connect to the DSN.
                        SQLDriverConnect(sqlconnectionhandle, NULL, (SQLWCHAR*)L"DSN=MySqlTestDatabase;SERVER=localhost;UID=root;PWD=root;DRIVER=MySQL Server;", SQL_NTS, retconstring, 1024, NULL, SQL_DRIVER_NOPROMPT);

                        // Get the items from the Relationships table.
                        // Allocate statement handle.
                        SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle);
                        // Process data.
                        SQLPrepare(sqlstatementhandle, (SQLWCHAR*)L"UPDATE MySqlTestDatabase.Relationships SET Name = ? WHERE Id = ?", SQL_NTS);

                        // Data conversions.
                        char value1[50];
                        strncpy(value1, this->name.c_str(), sizeof(value1));
                        value1[sizeof(value1) - 1] = 0;

                        // Fill the values.
                        SQLBindParameter(sqlstatementhandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 50, 0, value1, 50, 0);
                        SQLBindParameter(sqlstatementhandle, 2, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 0, 0, &this->id, 0, 0);

                        // Execute.
                        SQLExecute(sqlstatementhandle);

                        // Close the connection.
                        SQLFreeHandle(SQL_HANDLE_STMT, sqlstatementhandle);
                        SQLDisconnect(sqlconnectionhandle);
                        SQLFreeHandle(SQL_HANDLE_DBC, sqlconnectionhandle);
                        SQLFreeHandle(SQL_HANDLE_ENV, sqlenvhandle);

                        // Refresh.
                        this->GetData();
                    }*/
                }
		    }
		    catch (...)
		    { }
		}

        /// \brief Handles the OnButtonClick event of the button4 control.
        /// \par event The wxCommandEvent instance containing the event data.
		virtual void m_button4OnButtonClick( wxCommandEvent& event )
		{
		    // Deletes a record.
		    try
		    {
                // An item must be selected in the grid.
                if (this->selectedIndex >= 0)
                {
                    /* Logical Delete */
                    /*// Get the Id value of the selected item.
                    this->id = wxAtoi(this->m_grid1->GetCellValue(this->selectedIndex, 0));

                    // Open a connection to the database.
                    SQLWCHAR retconstring[1024];
                    SQLHANDLE sqlenvhandle;
                    SQLHANDLE sqlconnectionhandle;
                    SQLHANDLE sqlstatementhandle;
                    // Allocate an environment handle.
                    SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlenvhandle);
                    // We want ODBC 3 support.
                    SQLSetEnvAttr(sqlenvhandle,SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);
                    // Allocate a connection handle.
                    SQLAllocHandle(SQL_HANDLE_DBC, sqlenvhandle, &sqlconnectionhandle);
                    // Connect to the DSN.
                    SQLDriverConnect(sqlconnectionhandle, NULL, (SQLWCHAR*)L"DSN=MySqlTestDatabase;SERVER=localhost;UID=root;PWD=root;DRIVER=MySQL Server;", SQL_NTS, retconstring, 1024, NULL, SQL_DRIVER_NOPROMPT);

                    // Get the items from the Relationships table.
                    // Allocate statement handle.
                    SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle);
                    // Process data.
                    SQLPrepare(sqlstatementhandle, (SQLWCHAR*)L"UPDATE MySqlTestDatabase.Relationships SET IsDeleted = 1 WHERE Id = ?", SQL_NTS);

                    // Fill the values.
                    SQLBindParameter(sqlstatementhandle, 1, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 0, 0, &this->id, 0, 0);

                    // Execute.
                    SQLExecute(sqlstatementhandle);

                    // Close the connection.
                    SQLFreeHandle(SQL_HANDLE_STMT, sqlstatementhandle);
                    SQLDisconnect(sqlconnectionhandle);
                    SQLFreeHandle(SQL_HANDLE_DBC, sqlconnectionhandle);
                    SQLFreeHandle(SQL_HANDLE_ENV, sqlenvhandle);

                    // Refresh.
                    this->GetData();*/
                }
		    }
		    catch (...)
		    { }
		}

        /// \brief Handles the OnButtonClick event of the button1 control.
        /// \par event The wxCommandEvent instance containing the event data.
		virtual void m_button1OnButtonClick( wxCommandEvent& event )
		{
		    // List the records.
            this->GetData();
		}

        /// \brief Handles the OnButtonClick event of the button5 control.
        /// \par event The wxCommandEvent instance containing the event data.
		virtual void m_button5OnButtonClick( wxCommandEvent& event )
		{
		    // Close the frame.
		    this->Close();
		}

        /// \brief Gets the data.
		virtual void GetData()
		{
		    try
		    {
		        // Clear existing items.
                if (this->m_grid1->GetNumberRows() - 1 > 0)
                {
                    this->m_grid1->DeleteRows(0, this->m_grid1->GetNumberRows());
                }

                /*// Open a connection to the database.
                SQLWCHAR retconstring[1024];
                SQLHANDLE sqlenvhandle;
                SQLHANDLE sqlconnectionhandle;
                SQLHANDLE sqlstatementhandle;
                // Allocate an environment handle.
                SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlenvhandle);
                // We want ODBC 3 support.
                SQLSetEnvAttr(sqlenvhandle,SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);
                // Allocate a connection handle.
                SQLAllocHandle(SQL_HANDLE_DBC, sqlenvhandle, &sqlconnectionhandle);
                // Connect to the DSN.
                SQLDriverConnect(sqlconnectionhandle, NULL, (SQLWCHAR*)L"DSN=MySqlTestDatabase;SERVER=localhost;UID=root;PWD=root;DRIVER=MySQL Server;", SQL_NTS, retconstring, 1024, NULL, SQL_DRIVER_NOPROMPT);

                // Get the items from the Relationships table.
                vector<Relationship*>* relationships = new vector<Relationship*>();
                // Allocate statement handle.
                SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle);
                // Process data.
                SQLExecDirect(sqlstatementhandle, (SQLWCHAR*)L"SELECT * FROM MySqlTestDatabase.Relationships WHERE IsDeleted = 0", SQL_NTS);

                // Store the items in a Relationship list.
                while(SQLFetch(sqlstatementhandle) == SQL_SUCCESS)
                {
                    int idValue;
                    char nameValue[50];
                    bool isDeletedValue;

                    // Get the values from the statement.
                    SQLGetData(sqlstatementhandle, 1, SQL_C_ULONG, &idValue, 0, NULL);
                    SQLGetData(sqlstatementhandle, 2, SQL_C_CHAR, nameValue, 50, NULL);
                    SQLGetData(sqlstatementhandle, 3, SQL_C_BIT, &isDeletedValue, 0, NULL);

                    Relationship* relationship = new Relationship(idValue, string(nameValue), isDeletedValue);

                    //relationships->push_back(relationship);
                    relationships->insert(relationships->end(), relationship);
                }

                // Close the connection.
                SQLFreeHandle(SQL_HANDLE_STMT, sqlstatementhandle);
                SQLDisconnect(sqlconnectionhandle);
                SQLFreeHandle(SQL_HANDLE_DBC, sqlconnectionhandle);
                SQLFreeHandle(SQL_HANDLE_ENV, sqlenvhandle);

                // Fill the grid rows with the values of the Relationships table.
                for (int i = 0; i < (int)relationships->size(); i += 1)
                {
                    this->m_grid1->AppendRows(1);
                    Relationship* oneRelationship = relationships->at(i);

                    this->m_grid1->SetCellValue(this->m_grid1->GetNumberRows() - 1, 0, wxString::Format(wxT("%i"), oneRelationship->GetId()));
                    this->m_grid1->SetCellValue(this->m_grid1->GetNumberRows() - 1, 1, oneRelationship->GetName());
                }*/
		    }
		    catch (...)
		    { }
		}

        #endif // REGION_Methods

	public:

        #ifndef REGION_Constructors

        /// \brief Initializes a new instance of the MyFrame3 class.
        /// \par parent
        /// \par id
        /// \par title
        /// \par pos
        /// \par size
        /// \par style
		MyFrame3( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Relationships"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 715,610 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

        /// \brief Clean up any resources being used.
		~MyFrame3();

        #endif // REGION_Constructors

};

#endif // MYFRAME3_H
