///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef MYFRAME4_H
#define MYFRAME4_H

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
#include <Relationship.h>
#include <Relation.h>

///////////////////////////////////////////////////////////////////////////

using namespace std;

///////////////////////////////////////////////////////////////////////////////
/// \brief Interaction logic for MyFrame4.
///////////////////////////////////////////////////////////////////////////////
class MyFrame4 : public wxFrame
{
	protected:

	private:
		wxGrid* m_grid1;
		wxStaticText* m_staticText1;
		wxStaticText* m_staticText2;
		wxStaticText* m_staticText3;
		wxComboBox* m_comboBox1;
		wxComboBox* m_comboBox2;
		wxComboBox* m_comboBox3;
		wxButton* m_button2;
		wxButton* m_button3;
		wxButton* m_button4;
		wxStaticText* m_staticText4;
		wxStaticText* m_staticText5;
		wxStaticText* m_staticText6;
		wxStaticText* m_staticText7;
		wxStaticText* m_staticText8;
		wxStaticText* m_staticText9;
		wxButton* m_button1;
		wxButton* m_button5;

		#ifndef REGION_Fields

        // The selected index.
        int selectedIndex;

        // The id value.
        int id;

        // The person1 value.
        int name1;

        // The relationship value.
        int relationship;

        // The person2 value.
        int name2;

        #endif // REGION_Fields

        #ifndef REGION_Methods

		/// \brief Handles the OnActivate event of the MyFrame4 control.
        /// \par event The wxActivateEvent instance containing the event data.
		virtual void MyFrame4OnActivate( wxActivateEvent& event )
		{
		    // Preset values.
		    this->m_staticText7->SetLabelText("");
		    this->m_staticText8->SetLabelText("");
		    this->m_staticText9->SetLabelText("");

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
                    string cellValue = this->m_grid1->GetCellValue(this->selectedIndex, 0).ToStdString();
                    this->id = atoi(cellValue.c_str());
                    int cell1Value = 0;
                    int cell2Value = 0;
                    int cell3Value = 0;

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

                    // Get the items from the Relations table.
                    Relation* relation = new Relation();
                    // Allocate statement handle.
                    SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle);
                    // Process data.
                    SQLPrepare(sqlstatementhandle, (SQLWCHAR*)L"SELECT * FROM MySqlTestDatabase.Relations WHERE Id = ?", SQL_NTS);

                    // Fill the values.
                    SQLBindParameter(sqlstatementhandle, 1, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 0, 0, &this->id, 0, 0);

                    // Execute.
                    SQLExecute(sqlstatementhandle);

                    // Store the items in a Relation list.
                    while(SQLFetch(sqlstatementhandle) == SQL_SUCCESS)
                    {
                        int idValue;
                        int person1Value;
                        int relationshipValue;
                        int person2Value;
                        bool isDeletedValue;

                        // Get the values from the statement.
                        SQLGetData(sqlstatementhandle, 1, SQL_C_ULONG, &idValue, 0, NULL);
                        SQLGetData(sqlstatementhandle, 2, SQL_C_ULONG, &person1Value, 0, NULL);
                        SQLGetData(sqlstatementhandle, 3, SQL_C_ULONG, &relationshipValue, 0, NULL);
                        SQLGetData(sqlstatementhandle, 4, SQL_C_ULONG, &person2Value, 0, NULL);
                        SQLGetData(sqlstatementhandle, 5, SQL_C_BIT, &isDeletedValue, 0, NULL);

                        relation->SetId(idValue);
                        relation->SetPerson1(person1Value);
                        relation->SetRelationship(relationshipValue);
                        relation->SetPerson2(person2Value);
                        relation->SetIsDeleted(isDeletedValue);

                        cell1Value = relation->GetPerson1();
                        cell2Value = relation->GetRelationship();
                        cell3Value = relation->GetPerson2();
                    }

                    // Give the comboBox Values the selected values.
                    this->m_comboBox1->SetValue(wxString::Format(wxT("%i"), cell1Value));
                    this->m_comboBox2->SetValue(wxString::Format(wxT("%i"), cell2Value));
                    this->m_comboBox3->SetValue(wxString::Format(wxT("%i"), cell3Value));

                    wxCommandEvent cm1;

                    // Invoke the Selected Index Change methods.
                    this->m_comboBox1OnCombobox(cm1);
                    this->m_comboBox2OnCombobox(cm1);
                    this->m_comboBox3OnCombobox(cm1);

                    // Close the connection.
                    SQLFreeHandle(SQL_HANDLE_STMT, sqlstatementhandle);
                    SQLDisconnect(sqlconnectionhandle);
                    SQLFreeHandle(SQL_HANDLE_DBC, sqlconnectionhandle);
                    SQLFreeHandle(SQL_HANDLE_ENV, sqlenvhandle);
                }
                catch (...)
                {
                    // Empty the comboBox Values.
                    this->m_comboBox1->SetValue("");
                    this->m_comboBox2->SetValue("");
                    this->m_comboBox3->SetValue("");
                }
            }
            else
            {
                // Empty the comboBox Values.
                this->m_comboBox1->SetValue("");
                this->m_comboBox2->SetValue("");
                this->m_comboBox3->SetValue("");
            }
		}

		/// \brief Handles the OnCombobox event of the comboBox1 control.
        /// \par event The wxCommandEvent instance containing the event data.
		virtual void m_comboBox1OnCombobox( wxCommandEvent& event )
		{
		    try
		    {
                // Store the comboBox selected item.
                string cellValue = this->m_comboBox1->GetValue().ToStdString();
                this->name1 = atoi(cellValue.c_str());

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
                Person* returnValue = new Person();
                // Allocate statement handle.
                SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle);
                // Process data.
                SQLPrepare(sqlstatementhandle, (SQLWCHAR*)L"SELECT * FROM MySqlTestDatabase.People WHERE Id = ?", SQL_NTS);

                // Fill the values.
                SQLBindParameter(sqlstatementhandle, 1, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 0, 0, &this->name1, 0, 0);

                // Execute.
                SQLExecute(sqlstatementhandle);

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

                    returnValue->SetId(idValue);
                    returnValue->SetName(string(nameValue));
                    returnValue->SetMothername(string(mothernameValue));
                    returnValue->SetLocation(string(locationValue));
                    returnValue->SetBirthdate(birthdateValue);
                    returnValue->SetIsDeleted(isDeletedValue);
                }

                // Give the helper label the selected value.
                this->m_staticText7->SetLabelText(returnValue->GetName());

                // Close the connection.
                SQLFreeHandle(SQL_HANDLE_STMT, sqlstatementhandle);
                SQLDisconnect(sqlconnectionhandle);
                SQLFreeHandle(SQL_HANDLE_DBC, sqlconnectionhandle);
                SQLFreeHandle(SQL_HANDLE_ENV, sqlenvhandle);
		    }
		    catch (...)
            { }
		}

		/// \brief Handles the OnCombobox event of the comboBox2 control.
        /// \par event The wxCommandEvent instance containing the event data.
		virtual void m_comboBox2OnCombobox( wxCommandEvent& event )
		{
		    try
		    {
                // Store the comboBox selected item.
                string cellValue = this->m_comboBox2->GetValue().ToStdString();
                this->relationship = atoi(cellValue.c_str());

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
                Relationship* returnValue = new Relationship();
                // Allocate statement handle.
                SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle);
                // Process data.
                SQLPrepare(sqlstatementhandle, (SQLWCHAR*)L"SELECT * FROM MySqlTestDatabase.Relationships WHERE Id = ?", SQL_NTS);

                // Fill the values.
                SQLBindParameter(sqlstatementhandle, 1, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 0, 0, &this->relationship, 0, 0);

                // Execute.
                SQLExecute(sqlstatementhandle);

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

                    returnValue->SetId(idValue);
                    returnValue->SetName(string(nameValue));
                    returnValue->SetIsDeleted(isDeletedValue);
                }

                // Give the helper label the selected value.
                this->m_staticText8->SetLabelText(returnValue->GetName());

                // Close the connection.
                SQLFreeHandle(SQL_HANDLE_STMT, sqlstatementhandle);
                SQLDisconnect(sqlconnectionhandle);
                SQLFreeHandle(SQL_HANDLE_DBC, sqlconnectionhandle);
                SQLFreeHandle(SQL_HANDLE_ENV, sqlenvhandle);
		    }
		    catch (...)
            { }
		}

		/// \brief Handles the OnCombobox event of the comboBox3 control.
        /// \par event The wxCommandEvent instance containing the event data.
		virtual void m_comboBox3OnCombobox( wxCommandEvent& event )
		{
		    try
		    {
                // Store the comboBox selected item.
                string cellValue = this->m_comboBox3->GetValue().ToStdString();
                this->name2 = atoi(cellValue.c_str());

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
                Person* returnValue = new Person();
                // Allocate statement handle.
                SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle);
                // Process data.
                SQLPrepare(sqlstatementhandle, (SQLWCHAR*)L"SELECT * FROM MySqlTestDatabase.People WHERE Id = ?", SQL_NTS);

                // Fill the values.
                SQLBindParameter(sqlstatementhandle, 1, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 0, 0, &this->name2, 0, 0);

                // Execute.
                SQLExecute(sqlstatementhandle);

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

                    returnValue->SetId(idValue);
                    returnValue->SetName(string(nameValue));
                    returnValue->SetMothername(string(mothernameValue));
                    returnValue->SetLocation(string(locationValue));
                    returnValue->SetBirthdate(birthdateValue);
                    returnValue->SetIsDeleted(isDeletedValue);
                }

                // Give the helper label the selected value.
                this->m_staticText9->SetLabelText(returnValue->GetName());

                // Close the connection.
                SQLFreeHandle(SQL_HANDLE_STMT, sqlstatementhandle);
                SQLDisconnect(sqlconnectionhandle);
                SQLFreeHandle(SQL_HANDLE_DBC, sqlconnectionhandle);
                SQLFreeHandle(SQL_HANDLE_ENV, sqlenvhandle);
		    }
		    catch (...)
            { }
		}

		/// \brief Handles the OnButtonClick event of the button2 control.
        /// \par event The wxCommandEvent instance containing the event data.
		virtual void m_button2OnButtonClick( wxCommandEvent& event )
		{
		    // Add a record.
		    try
		    {
                // The fields must not be empty.
                if (/*this->name1 != NULL && this->relationship != NULL && this->name2 != NULL &&*/
                    this->name1 > 0 && this->relationship > 0 && this->name2 > 0 && this->name1 != this->name2)
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
                    SQLExecDirect(sqlstatementhandle, (SQLWCHAR*)L"SELECT * FROM MySqlTestDatabase.Relations", SQL_NTS);

                    // Store the items in a Person list.
                    while(SQLFetch(sqlstatementhandle) == SQL_SUCCESS)
                    {
                        this->id += 1;

                        int idValue;
                        int person1Value;
                        int relationshipValue;
                        int person2Value;
                        bool isDeletedValue;

                        // Get the values from the statement.
                        SQLGetData(sqlstatementhandle, 1, SQL_C_ULONG, &idValue, 0, NULL);
                        SQLGetData(sqlstatementhandle, 2, SQL_C_ULONG, &person1Value, 0, NULL);
                        SQLGetData(sqlstatementhandle, 3, SQL_C_ULONG, &relationshipValue, 0, NULL);
                        SQLGetData(sqlstatementhandle, 4, SQL_C_ULONG, &person2Value, 0, NULL);
                        SQLGetData(sqlstatementhandle, 5, SQL_C_BIT, &isDeletedValue, 0, NULL);

                        // Search for a deleted matching item.
                        if (!matchFound && person1Value == this->name1 && relationshipValue == this->relationship &&
                            person2Value == this->name2 && isDeletedValue == true)
                        {
                            matchFound = true;
                            this->id = idValue;

                            break;
                        }
                    }

                    // Add a new item if no deleted was found else restore the deleted item.
                    if (matchFound == false)
                    {
                        // Add new item to the Relations table.
                        // Allocate statement handle.
                        SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle);
                        // Process data.
                        SQLPrepare(sqlstatementhandle, (SQLWCHAR*)L"INSERT INTO MySqlTestDatabase.Relations (Id, Person1, Relationship, Person2, IsDeleted) VALUES (?, ?, ?, ?, 0)", SQL_NTS);

                        this->id += 1;

                        // Fill the values.
                        SQLBindParameter(sqlstatementhandle, 1, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 0, 0, &this->id, 0, 0);
                        SQLBindParameter(sqlstatementhandle, 2, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 0, 0, &this->name1, 0, 0);
                        SQLBindParameter(sqlstatementhandle, 3, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 0, 0, &this->relationship, 0, 0);
                        SQLBindParameter(sqlstatementhandle, 4, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 0, 0, &this->name2, 0, 0);

                        // Execute.
                        SQLExecute(sqlstatementhandle);
                    }
                    else
                    {
                        // Edit the IsDeleted value to false.
                        // Allocate statement handle.
                        SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle);
                        // Process data.
                        SQLPrepare(sqlstatementhandle, (SQLWCHAR*)L"UPDATE MySqlTestDatabase.Relations SET IsDeleted = 0 WHERE Id = ?", SQL_NTS);

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
		    // Edit a record.
		    try
		    {
                // The fields must not be empty.
                if (/*this->name1 != NULL && this->relationship != NULL && this->name2 != NULL &&*/
                    this->name1 > 0 && this->relationship > 0 && this->name2 > 0 && this->name1 != this->name2)
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

                        // Get the items from the Relations table.
                        // Allocate statement handle.
                        SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle);
                        // Process data.
                        SQLPrepare(sqlstatementhandle, (SQLWCHAR*)L"UPDATE MySqlTestDatabase.Relations SET Person1 = ?, Relationship = ?, Person2 = ? WHERE Id = ?", SQL_NTS);

                        // Fill the values.
                        SQLBindParameter(sqlstatementhandle, 1, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 0, 0, &this->name1, 0, 0);
                        SQLBindParameter(sqlstatementhandle, 2, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 0, 0, &this->relationship, 0, 0);
                        SQLBindParameter(sqlstatementhandle, 3, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 0, 0, &this->name2, 0, 0);
                        SQLBindParameter(sqlstatementhandle, 4, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 0, 0, &this->id, 0, 0);

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
		    // Delete a record.
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

                    // Get the items from the Relations table.
                    // Allocate statement handle.
                    SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle);
                    // Process data.
                    SQLPrepare(sqlstatementhandle, (SQLWCHAR*)L"UPDATE MySqlTestDatabase.Relations SET IsDeleted = 1 WHERE Id = ?", SQL_NTS);

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
                this->m_comboBox1->Clear();
                this->m_comboBox2->Clear();
                this->m_comboBox3->Clear();

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
                SQLExecDirect(sqlstatementhandle, (SQLWCHAR*)L"SELECT * FROM MySqlTestDatabase.People", SQL_NTS);

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

                // Get the items from the Relationships table.
                vector<Relationship*>* relationships = new vector<Relationship*>();
                // Allocate statement handle.
                SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle);
                // Process data.
                SQLExecDirect(sqlstatementhandle, (SQLWCHAR*)L"SELECT * FROM MySqlTestDatabase.Relationships", SQL_NTS);

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

                // Get the items from the Relations table.
                vector<Relation*>* relations = new vector<Relation*>();
                // Allocate statement handle.
                SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle);
                // Process data.
                SQLExecDirect(sqlstatementhandle, (SQLWCHAR*)L"SELECT * FROM MySqlTestDatabase.Relations WHERE IsDeleted = 0", SQL_NTS);

                // Store the items in a Relation list.
                while(SQLFetch(sqlstatementhandle) == SQL_SUCCESS)
                {
                    int idValue;
                    int person1Value;
                    int relationshipValue;
                    int person2Value;
                    bool isDeletedValue;

                    // Get the values from the statement.
                    SQLGetData(sqlstatementhandle, 1, SQL_C_ULONG, &idValue, 0, NULL);
                    SQLGetData(sqlstatementhandle, 2, SQL_C_ULONG, &person1Value, 0, NULL);
                    SQLGetData(sqlstatementhandle, 3, SQL_C_ULONG, &relationshipValue, 0, NULL);
                    SQLGetData(sqlstatementhandle, 4, SQL_C_ULONG, &person2Value, 0, NULL);
                    SQLGetData(sqlstatementhandle, 5, SQL_C_BIT, &isDeletedValue, 0, NULL);

                    Relation* relation = new Relation(idValue, person1Value, relationshipValue, person2Value, isDeletedValue);

                    //relations->push_back(relation);
                    relations->insert(relations->end(), relation);
                }

                // Close the connection.
                SQLFreeHandle(SQL_HANDLE_STMT, sqlstatementhandle);
                SQLDisconnect(sqlconnectionhandle);
                SQLFreeHandle(SQL_HANDLE_DBC, sqlconnectionhandle);
                SQLFreeHandle(SQL_HANDLE_ENV, sqlenvhandle);

                // Fill the grid rows with the values of the Relations table.
                for (int i = 0; i < (int)relations->size(); i += 1)
                {
                    this->m_grid1->AppendRows(1);
                    Relation* oneRelation = relations->at(i);

                    this->m_grid1->SetCellValue(this->m_grid1->GetNumberRows() - 1, 0, wxString::Format(wxT("%i"), oneRelation->GetId()));

                    // Substitute the Person1 and Person2 ids with their names.
                    for (int j = 0; j < (int)people->size(); j += 1)
                    {
                        Person* onePerson = people->at(j);

                        if (oneRelation->GetPerson1() == onePerson->GetId())
                        {
                            this->m_grid1->SetCellValue(this->m_grid1->GetNumberRows() - 1, 1, onePerson->GetName());
                        }

                        if (oneRelation->GetPerson2() == onePerson->GetId())
                        {
                            this->m_grid1->SetCellValue(this->m_grid1->GetNumberRows() - 1, 3, onePerson->GetName());
                        }
                    }

                    // Substitute the Relationship ids with their names.
                    for (int j = 0; j < (int)relationships->size(); j += 1)
                    {
                        Relationship* oneRelationship = relationships->at(j);

                        if (oneRelation->GetRelationship() == oneRelationship->GetId())
                        {
                            this->m_grid1->SetCellValue(this->m_grid1->GetNumberRows() - 1, 2, oneRelationship->GetName());
                        }
                    }
                }

                // Fill the comboBox items with the values of the People table.
                for (int i = 0; i < (int)people->size(); i += 1)
                {
                    Person* onePerson = people->at(i);

                    if (onePerson->GetIsDeleted() == false)
                    {
                        this->m_comboBox1->Append(wxString::Format(wxT("%i"), onePerson->GetId()));
                        this->m_comboBox3->Append(wxString::Format(wxT("%i"), onePerson->GetId()));
                    }
                }

                // Fill the comboBox items with the values of the Relationships table.
                for (int i = 0; i < (int)relationships->size(); i += 1)
                {
                    Relationship* oneRelationship = relationships->at(i);

                    if (oneRelationship->GetIsDeleted() == false)
                    {
                        this->m_comboBox2->Append(wxString::Format(wxT("%i"), oneRelationship->GetId()));
                    }
                }
		    }
		    catch (...)
		    { }
		}

        #endif // REGION_Methods

	public:

	    #ifndef REGION_Constructors

        /// \brief Initializes a new instance of the MyFrame4 class.
        /// \par parent
        /// \par id
        /// \par title
        /// \par pos
        /// \par size
        /// \par style
		MyFrame4( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Relations"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 715,610 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

        /// \brief Clean up any resources being used.
		~MyFrame4();

		#endif // REGION_Constructors

};

#endif // MYFRAME4_H
