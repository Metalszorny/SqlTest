///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef MYFRAME2_H
#define MYFRAME2_H

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
#include <Person.h>

///////////////////////////////////////////////////////////////////////////

using namespace std;

///////////////////////////////////////////////////////////////////////////////
/// \brief Interaction logic for MyFrame2.
///////////////////////////////////////////////////////////////////////////////
class MyFrame2 : public wxFrame
{
	protected:

	private:
		wxGrid* m_grid1;
		wxStaticText* m_staticText1;
		wxStaticText* m_staticText2;
		wxStaticText* m_staticText3;
		wxStaticText* m_staticText4;
		wxTextCtrl* m_textCtrl1;
		wxTextCtrl* m_textCtrl2;
		wxTextCtrl* m_textCtrl3;
		wxTextCtrl* m_textCtrl4;
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

        // The mothername value.
        string mothername;

        // The location value.
        string location;

        // The birthdate value.
        string birthdate;

        #endif // REGION_Fields

        #ifndef REGION_Methods

		/// \brief Handles the OnActivate event of the MyFrame2 control.
        /// \par event The wxActivateEvent instance containing the event data.
		virtual void MyFrame2OnActivate( wxActivateEvent& event )
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
                    this->m_textCtrl2->SetValue(this->m_grid1->GetCellValue(this->selectedIndex, 2));
                    this->m_textCtrl3->SetValue(this->m_grid1->GetCellValue(this->selectedIndex, 3));
                    this->m_textCtrl4->SetValue(this->m_grid1->GetCellValue(this->selectedIndex, 4));
                }
                catch (...)
                {
                    // Empty the textControl Values.
                    this->m_textCtrl1->SetValue("");
                    this->m_textCtrl2->SetValue("");
                    this->m_textCtrl3->SetValue("");
                    this->m_textCtrl4->SetValue("");
                }
            }
            else
            {
                // Empty the textControl Values.
                this->m_textCtrl1->SetValue("");
                this->m_textCtrl2->SetValue("");
                this->m_textCtrl3->SetValue("");
                this->m_textCtrl4->SetValue("");
            }
		}

        /// \brief Handles the OnText event of the textCtrl1 control.
        /// \par event The wxCommandEvent instance containing the event data.
		virtual void m_textCtrl1OnText( wxCommandEvent& event )
		{
		    // Give the field the textControl Text.
		    this->name = this->m_textCtrl1->GetValue();
		}

        /// \brief Handles the OnText event of the textCtrl2 control.
        /// \par event The wxCommandEvent instance containing the event data.
		virtual void m_textCtrl2OnText( wxCommandEvent& event )
		{
		    // Give the field the textControl Text.
		    this->mothername = this->m_textCtrl2->GetValue();
		}

        /// \brief Handles the OnText event of the textCtrl3 control.
        /// \par event The wxCommandEvent instance containing the event data.
		virtual void m_textCtrl3OnText( wxCommandEvent& event )
		{
		    // Give the field the textControl Text.
		    this->location = this->m_textCtrl3->GetValue();
		}

        /// \brief Handles the OnText event of the textCtrl4 control.
        /// \par event The wxCommandEvent instance containing the event data.
		virtual void m_textCtrl4OnText( wxCommandEvent& event )
		{
		    // Give the field the textControl Text.
		    this->birthdate = this->m_textCtrl4->GetValue();
		}

        /// \brief Handles the OnButtonClick event of the button2 control.
        /// \par event The wxCommandEvent instance containing the event data.
		virtual void m_button2OnButtonClick( wxCommandEvent& event )
		{
		    // Adds a record.
		    try
		    {
                // The fields must not be empty.
                if (/*this->name != NULL && this->mothername != NULL && this-> location != NULL && this->birthdate != NULL &&*/
                    this->name != "" && this->mothername != "" && this->location != "" && this->birthdate != "")
                {
                    this->id = 0;
                    bool matchFound = false;

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

                    // Get the items from the People table.
                    // Allocate statement handle.
                    SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle);
                    // Process data.
                    SQLExecDirect(sqlstatementhandle, (SQLWCHAR*)L"SELECT * FROM MySqlTestDatabase.People", SQL_NTS);

                    // Store the items in a Person list.
                    while(SQLFetch(sqlstatementhandle) == SQL_SUCCESS)
                    {
                        this->id += 1;

                        int idValue;
                        char nameValue[50];
                        char mothernameValue[50];
                        char locationValue[50];
                        TIMESTAMP_STRUCT birthdateValue;
                        bool isDeletedValue;

                        SQLGetData(sqlstatementhandle, 1, SQL_C_ULONG, &idValue, 0, NULL);
                        SQLGetData(sqlstatementhandle, 2, SQL_C_CHAR, nameValue, 50, NULL);
                        SQLGetData(sqlstatementhandle, 3, SQL_C_CHAR, mothernameValue, 50, NULL);
                        SQLGetData(sqlstatementhandle, 4, SQL_C_CHAR, locationValue, 50, NULL);
                        SQLGetData(sqlstatementhandle, 5, SQL_C_DATE, &birthdateValue, 0, NULL);
                        SQLGetData(sqlstatementhandle, 6, SQL_C_BIT, &isDeletedValue, 0, NULL);

                        // Search for a deleted matching item.
                        if (!matchFound && string(nameValue) == this->name && string(mothernameValue) == this->mothername &&
                            string(locationValue) == this->location && string(TimestampStructToCharArray(birthdateValue)) == this->birthdate &&
                            isDeletedValue == true)
                        {
                            matchFound = true;
                            this->id = idValue;

                            break;
                        }
                    }

                    // Add a new item if no deleted was found else restore the deleted item.
                    if (matchFound == false)
                    {
                        // Add new item to the People table.
                        // Allocate statement handle.
                        SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle);
                        // Process data.
                        SQLPrepare(sqlstatementhandle, (SQLWCHAR*)L"INSERT INTO MySqlTestDatabase.People (Id, Name, Mothername, Location, Birthdate, IsDeleted) VALUES (?, ?, ?, ?, ?, 0)", SQL_NTS);

                        this->id += 1;

                        // Data conversions.
                        char value1[50];
                        strncpy(value1, this->name.c_str(), sizeof(value1));
                        value1[sizeof(value1) - 1] = 0;
                        char value2[50];
                        strncpy(value2, this->mothername.c_str(), sizeof(value2));
                        value2[sizeof(value2) - 1] = 0;
                        char value3[50];
                        strncpy(value3, this->location.c_str(), sizeof(value3));
                        value3[sizeof(value3) - 1] = 0;
                        char temp1[20];
                        strncpy(temp1, this->birthdate.c_str(), sizeof(temp1));
                        temp1[sizeof(temp1) - 1] = 0;
                        int day, month, year;
                        sscanf(temp1, "%4d.%2d.%2d", &year, &month, &day);
                        TIMESTAMP_STRUCT ts = {0};
                        ts.year = year;
                        ts.month = month;
                        ts.day = day;

                        // Fill the values.
                        SQLBindParameter(sqlstatementhandle, 1, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 0, 0, &this->id, 0, 0);
                        SQLBindParameter(sqlstatementhandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 50, 0, value1, 50, 0);
                        SQLBindParameter(sqlstatementhandle, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 50, 0, value2, 50, 0);
                        SQLBindParameter(sqlstatementhandle, 4, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 50, 0, value3, 50, 0);
                        SQLBindParameter(sqlstatementhandle, 5, SQL_PARAM_INPUT, SQL_C_DATE, SQL_TIMESTAMP, 0, 0, &ts, 0, 0);

                        // Execute.
                        SQLExecute(sqlstatementhandle);
                    }
                    else
                    {
                        // Edit the IsDeleted value to false.
                        // Allocate statement handle.
                        SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle);
                        // Process data.
                        SQLPrepare(sqlstatementhandle, (SQLWCHAR*)L"UPDATE MySqlTestDatabase.People SET IsDeleted = 0 WHERE Id = ?", SQL_NTS);

                        // Fill the values.
                        SQLBindParameter(sqlstatementhandle, 1, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 0, 0, &this->id, 0, 0);

                        // Execute.
                        SQLExecute(sqlstatementhandle);
                    }

                    // Close the connection.
                    SQLFreeHandle(SQL_HANDLE_STMT, sqlstatementhandle);
                    SQLDisconnect(sqlconnectionhandle);
                    SQLFreeHandle(SQL_HANDLE_DBC, sqlconnectionhandle);
                    SQLFreeHandle(SQL_HANDLE_ENV, sqlenvhandle);

                    // Refresh.
                    this->GetData();
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
                if (/*this->name != NULL && this->mothername != NULL && this-> location != NULL && this->birthdate != NULL &&*/
                    this->name != "" && this->mothername != "" && this->location != "" && this->birthdate != "")
                {
                    // An item must be selected in the grid.
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

                        // Get the items from the People table.
                        // Allocate statement handle.
                        SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle);
                        // Process data.
                        SQLPrepare(sqlstatementhandle, (SQLWCHAR*)L"UPDATE MySqlTestDatabase.People SET Name = ?, Mothername = ?, Location = ?, Birthdate = ? WHERE Id = ?", SQL_NTS);

                        // Data conversions.
                        char value1[50];
                        strncpy(value1, this->name.c_str(), sizeof(value1));
                        value1[sizeof(value1) - 1] = 0;
                        char value2[50];
                        strncpy(value2, this->mothername.c_str(), sizeof(value2));
                        value2[sizeof(value2) - 1] = 0;
                        char value3[50];
                        strncpy(value3, this->location.c_str(), sizeof(value3));
                        value3[sizeof(value3) - 1] = 0;
                        char temp1[20];
                        strncpy(temp1, this->birthdate.c_str(), sizeof(temp1));
                        temp1[sizeof(temp1) - 1] = 0;
                        int day, month, year;
                        sscanf(temp1, "%4d.%2d.%2d", &year, &month, &day);
                        TIMESTAMP_STRUCT ts = {0};
                        ts.year = year;
                        ts.month = month;
                        ts.day = day;

                        // Fill the values.
                        SQLBindParameter(sqlstatementhandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 50, 0, value1, 50, 0);
                        SQLBindParameter(sqlstatementhandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 50, 0, value2, 50, 0);
                        SQLBindParameter(sqlstatementhandle, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 50, 0, value3, 50, 0);
                        SQLBindParameter(sqlstatementhandle, 4, SQL_PARAM_INPUT, SQL_C_DATE, SQL_TIMESTAMP, 0, 0, &ts, 0, 0);
                        SQLBindParameter(sqlstatementhandle, 5, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 0, 0, &this->id, 0, 0);

                        // Execute.
                        SQLExecute(sqlstatementhandle);

                        // Close the connection.
                        SQLFreeHandle(SQL_HANDLE_STMT, sqlstatementhandle);
                        SQLDisconnect(sqlconnectionhandle);
                        SQLFreeHandle(SQL_HANDLE_DBC, sqlconnectionhandle);
                        SQLFreeHandle(SQL_HANDLE_ENV, sqlenvhandle);

                        // Refresh.
                        this->GetData();
                    }
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

                    // Get the items from the People table.
                    // Allocate statement handle.
                    SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle);
                    // Process data.
                    SQLPrepare(sqlstatementhandle, (SQLWCHAR*)L"UPDATE MySqlTestDatabase.People SET IsDeleted = 1 WHERE Id = ?", SQL_NTS);

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
                    this->GetData();
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
		    // Close the Frame.
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

                // Get the items from the People table.
                vector<Person*>* people = new vector<Person*>();
                // Allocate statement handle.
                SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle);
                // Process data.
                SQLExecDirect(sqlstatementhandle, (SQLWCHAR*)L"SELECT * FROM MySqlTestDatabase.People WHERE IsDeleted = 0", SQL_NTS);

                // Store the items in a Person list.
                while(SQLFetch(sqlstatementhandle) == SQL_SUCCESS)
                {
                    int idValue;
                    char nameValue[50];
                    char mothernameValue[50];
                    char locationValue[50];
                    TIMESTAMP_STRUCT birthdateValue;
                    bool isDeletedValue;

                    // Get the values from the statement.
                    SQLGetData(sqlstatementhandle, 1, SQL_C_ULONG, &idValue, 0, NULL);
                    SQLGetData(sqlstatementhandle, 2, SQL_C_CHAR, nameValue, 50, NULL);
                    SQLGetData(sqlstatementhandle, 3, SQL_C_CHAR, mothernameValue, 50, NULL);
                    SQLGetData(sqlstatementhandle, 4, SQL_C_CHAR, locationValue, 50, NULL);
                    SQLGetData(sqlstatementhandle, 5, SQL_C_DATE, &birthdateValue, 0, NULL);
                    SQLGetData(sqlstatementhandle, 6, SQL_C_BIT, &isDeletedValue, 0, NULL);

                    Person* person = new Person(idValue, string(nameValue), string(mothernameValue), string(locationValue), birthdateValue, isDeletedValue);

                    //people->push_back(person);
                    people->insert(people->end(), person);
                }

                // Close the connection.
                SQLFreeHandle(SQL_HANDLE_STMT, sqlstatementhandle);
                SQLDisconnect(sqlconnectionhandle);
                SQLFreeHandle(SQL_HANDLE_DBC, sqlconnectionhandle);
                SQLFreeHandle(SQL_HANDLE_ENV, sqlenvhandle);

                // Fill the grid rows with the values of the People table.
                for (int i = 0; i < (int)people->size(); i += 1)
                {
                    this->m_grid1->AppendRows(1);
                    Person* onePerson = people->at(i);

                    this->m_grid1->SetCellValue(this->m_grid1->GetNumberRows() - 1, 0, wxString::Format(wxT("%i"), onePerson->GetId()));
                    this->m_grid1->SetCellValue(this->m_grid1->GetNumberRows() - 1, 1, onePerson->GetName());
                    this->m_grid1->SetCellValue(this->m_grid1->GetNumberRows() - 1, 2, onePerson->GetMothername());
                    this->m_grid1->SetCellValue(this->m_grid1->GetNumberRows() - 1, 3, onePerson->GetLocation());
                    this->m_grid1->SetCellValue(this->m_grid1->GetNumberRows() - 1, 4, TimestampStructToCharArray(onePerson->GetBirthdate()));
                }
		    }
		    catch (...)
		    { }
		}

        /// \brief Converts timestamp struct to char array in a Y.m.d format.
        /// \par ts The timestamp date that needs to be converted.
        /// \return The date as character array.
        virtual char* TimestampStructToCharArray(TIMESTAMP_STRUCT ts)
        {
            try
            {
                char stringMonth[4], stringDay[4], stringYear[8];
                char returnValue[12];

                sprintf(stringYear, "%u", ts.year);
                sprintf(stringMonth, "%u", ts.month);
                sprintf(stringDay, "%u", ts.day);

                strcpy(returnValue, stringYear);
                strcat(returnValue, ".");
                if (ts.month < 10)
                {
                    strcat(returnValue, "0");
                }
                strcat(returnValue, stringMonth);
                strcat(returnValue, ".");
                if (ts.day < 10)
                {
                    strcat(returnValue, "0");
                }
                strcat(returnValue, stringDay);

                return returnValue;
            }
            catch (...)
            {
                return NULL;
            }
        }

        #endif // REGION_Methods

	public:

        #ifndef REGION_Constructors

        /// \brief Initializes a new instance of the MyFrame2 class.
        /// \par parent
        /// \par id
        /// \par title
        /// \par pos
        /// \par size
        /// \par style
		MyFrame2( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("People"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 715,610 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

        /// \brief Clean up any resources being used.
		~MyFrame2();

		#endif // REGION_Constructors

};

#endif // MYFRAME2_H
