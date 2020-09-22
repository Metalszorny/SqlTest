/***************************************************************
 * Name:      OracleSqlTestApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2016-01-18
 * Copyright:  ()
 * License:
 **************************************************************/

#include "OracleSqlTestApp.h"
#include "MyFrame1.h"
#include <wx/image.h>

IMPLEMENT_APP(OracleSqlTestApp);

bool OracleSqlTestApp::OnInit()
{
    bool wxsOK = true;
    wxInitAllImageHandlers();

    if ( wxsOK )
    {
    	MyFrame1* Frame = new MyFrame1(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }

    return wxsOK;
}
