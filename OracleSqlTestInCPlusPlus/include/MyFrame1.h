///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef MYFRAME1_H
#define MYFRAME1_H

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
#include <MyFrame2.h>
#include <MyFrame3.h>
#include <MyFrame4.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// \brief Interaction logic for MyFrame1.
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
	protected:

	private:
		wxButton* m_button1;
		wxButton* m_button2;
		wxButton* m_button3;
		wxButton* m_button4;

		#ifndef REGION_Methods

		/// \brief Handles the OnButtonClick event of the button1 control.
        /// \par event The wxCommandEvent instance containing the event data.
		virtual void m_button1OnButtonClick( wxCommandEvent& event )
		{
		    // Opens the People Frame.
		    MyFrame2* people = new MyFrame2(NULL);
		    people->Show();
		}

        /// \brief Handles the OnButtonClick event of the button2 control.
        /// \par event The wxCommandEvent instance containing the event data.
		virtual void m_button2OnButtonClick( wxCommandEvent& event )
		{
		    // Opens the Relationships Frame.
		    MyFrame3* relationships = new MyFrame3(NULL);
		    relationships->Show();
		}

        /// \brief Handles the OnButtonClick event of the button3 control.
        /// \par event The wxCommandEvent instance containing the event data.
		virtual void m_button3OnButtonClick( wxCommandEvent& event )
		{
		    // Opens the Relations Frame.
		    MyFrame4* relations = new MyFrame4(NULL);
		    relations->Show();
		}

        /// \brief Handles the OnButtonClick event of the button4 control.
        /// \par event The wxCommandEvent instance containing the event data.
		virtual void m_button4OnButtonClick( wxCommandEvent& event )
		{
		    // Exit the program.
		    this->Close();
		}

        #endif // REGION_Methods

	public:

        #ifndef REGION_Constructors

        /// \brief Initializes a new instance of the MyFrame1 class.
        /// \par parent
        /// \par id
        /// \par title
        /// \par pos
        /// \par size
        /// \par style
		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Menu"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 230,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

        /// \brief Clean up any resources being used.
		~MyFrame1();

		#endif // REGION_Constructors

};

#endif // MYFRAME1_H
