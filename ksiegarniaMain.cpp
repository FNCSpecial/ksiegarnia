/***************************************************************
 * Name:      ksiegarniaMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2020-12-29
 * Copyright:  ()
 * License:
 **************************************************************/

#include "ksiegarniaMain.h"
#include "klient.h"
#include "pracownik.h"
#include "logowanie.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(ksiegarniaFrame)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(ksiegarniaFrame)
const long ksiegarniaFrame::ID_BUTTON1 = wxNewId();
const long ksiegarniaFrame::ID_BUTTON2 = wxNewId();
const long ksiegarniaFrame::ID_STATICTEXT1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ksiegarniaFrame,wxFrame)
    //(*EventTable(ksiegarniaFrame)
    //*)
END_EVENT_TABLE()

ksiegarniaFrame::ksiegarniaFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(ksiegarniaFrame)
    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(640,360));
    SetMinSize(wxSize(696,391));
    SetMaxSize(wxSize(696,391));
    SetBackgroundColour(wxColour(191,168,158));
    Button1 = new wxButton(this, ID_BUTTON1, _("Klient"), wxPoint(170,110), wxSize(150,150), wxBORDER_RAISED, wxDefaultValidator, _T("ID_BUTTON1"));
    Button1->SetBackgroundColour(wxColour(235,245,238));
    wxFont Button1Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
    Button1->SetFont(Button1Font);
    Button2 = new wxButton(this, ID_BUTTON2, _("Pracownik"), wxPoint(370,110), wxSize(150,150), wxBORDER_RAISED, wxDefaultValidator, _T("ID_BUTTON2"));
    Button2->SetBackgroundColour(wxColour(235,245,238));
    wxFont Button2Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
    Button2->SetFont(Button2Font);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Witaj w naszej ksiegarni!"), wxPoint(184,32), wxSize(144,24), 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(20,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    Center();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ksiegarniaFrame::OnButton1Click2);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ksiegarniaFrame::OnButton2Click);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&ksiegarniaFrame::OnClose);
    //*)
}

ksiegarniaFrame::~ksiegarniaFrame()
{
    //(*Destroy(ksiegarniaFrame)
    //*)
}

void ksiegarniaFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void ksiegarniaFrame::OnClose(wxCloseEvent& event)
{
    Close();
}

void ksiegarniaFrame::OnButton1Click2(wxCommandEvent& event)
{
    klient* Frame2 = new klient(0);
    	Frame2->Show();
}

void ksiegarniaFrame::OnButton2Click(wxCommandEvent& event)
{
    logowanie* Frame3 = new logowanie(0);
    	Frame3->Show();
}
