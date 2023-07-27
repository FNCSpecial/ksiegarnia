/***************************************************************
 * Name:      ksiegarniaApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2020-12-29
 * Copyright:  ()
 * License:
 **************************************************************/

#include "ksiegarniaApp.h"

//(*AppHeaders
#include "ksiegarniaMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(ksiegarniaApp);

bool ksiegarniaApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	ksiegarniaFrame* Frame = new ksiegarniaFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
