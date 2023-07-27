#include "zamowienia.h"
#include <wx/textfile.h>
#include <wx/msgdlg.h>

//(*InternalHeaders(zamowienia)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(zamowienia)
const long zamowienia::ID_BUTTON1 = wxNewId();
const long zamowienia::ID_BUTTON2 = wxNewId();
const long zamowienia::ID_TEXTCTRL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(zamowienia,wxFrame)
	//(*EventTable(zamowienia)
	//*)
END_EVENT_TABLE()

zamowienia::zamowienia(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(zamowienia)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(670,328));
	Move(wxDefaultPosition);
	SetBackgroundColour(wxColour(191,168,158));
	Button1 = new wxButton(this, ID_BUTTON1, _("Wyswietl"), wxPoint(48,40), wxSize(100,35), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button1->SetBackgroundColour(wxColour(235,245,238));
	wxFont Button1Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	Button1->SetFont(Button1Font);
	Button2 = new wxButton(this, ID_BUTTON2, _("Zrealizuj"), wxPoint(48,96), wxSize(100,35), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Button2->SetBackgroundColour(wxColour(235,245,238));
	wxFont Button2Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	Button2->SetFont(Button2Font);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(176,32), wxSize(464,264), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	wxFont TextCtrl1Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	TextCtrl1->SetFont(TextCtrl1Font);
	Center();

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&zamowienia::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&zamowienia::OnButton2Click);
	//*)
}

zamowienia::~zamowienia()
{
	//(*Destroy(zamowienia)
	//*)
}


void zamowienia::OnButton1Click(wxCommandEvent& event)
{
    wxTextFile file;
    wxString text;
    file.Open("zamowienia.txt");

    for(size_t i=0; i<file.GetLineCount(); i++){
        text << file.GetLine(i) <<("\n");
        TextCtrl1->SetValue(text);
    }
    file.Close();
}

void zamowienia::OnButton2Click(wxCommandEvent& event)
{
    wxTextFile file;
    wxString text;
    file.Open("zamowienia.txt");
    file.RemoveLine(0);
    for(size_t i=0; i<file.GetLineCount(); i++){
        text << file.GetLine(i) <<("\n");
        TextCtrl1->SetValue(text);
    }
    if(file.GetLineCount()==0) {
            TextCtrl1->Clear();
        }
    file.Write();
    file.Close();
}
