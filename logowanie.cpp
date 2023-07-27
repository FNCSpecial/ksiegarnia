#include "logowanie.h"
#include "pracownik.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(logowanie)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(logowanie)
const long logowanie::ID_STATICTEXT1 = wxNewId();
const long logowanie::ID_STATICTEXT2 = wxNewId();
const long logowanie::ID_STATICTEXT3 = wxNewId();
const long logowanie::ID_TEXTCTRL1 = wxNewId();
const long logowanie::ID_TEXTCTRL2 = wxNewId();
const long logowanie::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(logowanie,wxFrame)
	//(*EventTable(logowanie)
	//*)
END_EVENT_TABLE()

logowanie::logowanie(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(logowanie)
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(350,250));
	SetBackgroundColour(wxColour(191,168,158));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Logowanie"), wxPoint(128,24), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Login:"), wxPoint(32,64), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Haslo:"), wxPoint(32,112), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	wxFont StaticText3Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	StaticText3->SetFont(StaticText3Font);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(112,64), wxSize(130,30), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	wxFont TextCtrl1Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	TextCtrl1->SetFont(TextCtrl1Font);
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(112,112), wxSize(130,30), wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	wxFont TextCtrl2Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	TextCtrl2->SetFont(TextCtrl2Font);
	Button1 = new wxButton(this, ID_BUTTON1, _("Zaloguj"), wxPoint(128,168), wxSize(100,35), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button1->SetBackgroundColour(wxColour(235,245,238));
	wxFont Button1Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	Button1->SetFont(Button1Font);
	Center();

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&logowanie::OnTextCtrl1Text);
	Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&logowanie::OnTextCtrl2Text);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&logowanie::OnButton1Click);
	//*)
}

logowanie::~logowanie()
{
	//(*Destroy(logowanie)
	//*)
}


void logowanie::OnTextCtrl1Text(wxCommandEvent& event)
{
}

void logowanie::OnTextCtrl2Text(wxCommandEvent& event)
{
}

void logowanie::OnButton1Click(wxCommandEvent& event)
{
    wxString Login = ("admin");
    wxString Haslo = ("123");
    wxString Input_Login = TextCtrl1->GetValue();
    wxString Input_Haslo = TextCtrl2->GetValue();
    if(Login == Input_Login && Haslo == Input_Haslo) {
        this->Hide();
        pracownik* Frame = new pracownik(0);
        Frame->Show();
    }
    else {
        wxMessageBox("Bledne dane logowania!");
    }
}
