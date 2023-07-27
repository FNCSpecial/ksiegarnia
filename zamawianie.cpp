#include <wx/textfile.h>
#include <wx/msgdlg.h>
#include "zamawianie.h"

//(*InternalHeaders(zamawianie)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(zamawianie)
const long zamawianie::ID_TEXTCTRL1 = wxNewId();
const long zamawianie::ID_TEXTCTRL2 = wxNewId();
const long zamawianie::ID_TEXTCTRL3 = wxNewId();
const long zamawianie::ID_TEXTCTRL4 = wxNewId();
const long zamawianie::ID_STATICTEXT1 = wxNewId();
const long zamawianie::ID_STATICTEXT2 = wxNewId();
const long zamawianie::ID_STATICTEXT3 = wxNewId();
const long zamawianie::ID_STATICTEXT4 = wxNewId();
const long zamawianie::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(zamawianie,wxFrame)
	//(*EventTable(zamawianie)
	//*)
END_EVENT_TABLE()

zamawianie::zamawianie(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(zamawianie)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(500,300));
	Move(wxDefaultPosition);
	SetBackgroundColour(wxColour(191,168,158));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(16,56), wxSize(150,35), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(176,56), wxSize(150,35), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(336,56), wxSize(150,35), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(176,152), wxSize(150,35), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Imie"), wxPoint(64,24), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Nazwisko"), wxPoint(208,24), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Telefon"), wxPoint(384,24), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	wxFont StaticText3Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	StaticText3->SetFont(StaticText3Font);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("ID_ksiazki"), wxPoint(208,120), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	wxFont StaticText4Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	StaticText4->SetFont(StaticText4Font);
	Button1 = new wxButton(this, ID_BUTTON1, _("Zamow"), wxPoint(200,216), wxSize(100,35), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button1->SetBackgroundColour(wxColour(235,245,238));
	wxFont Button1Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	Button1->SetFont(Button1Font);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&zamawianie::OnButton1Click);
	//*)
}

zamawianie::~zamawianie()
{
	//(*Destroy(zamawianie)
	//*)
}


void zamawianie::OnButton1Click(wxCommandEvent& event)
{
    wxString imie = TextCtrl1->GetValue();
    wxString nazwisko = TextCtrl2->GetValue();
    wxString telefon = TextCtrl3->GetValue();
    wxString id_ksiazki = TextCtrl4->GetValue();

    wxString ogranicznik1 = "|: ";
    wxString ogranicznik2 = " |";
    wxString szukana = ogranicznik1+id_ksiazki+ogranicznik2;
    wxTextFile file2;
    wxString line;
    bool check=false;

    file2.Open("ksiazki.txt");

    for(size_t i=0; i<file2.GetLineCount(); i++){
        line << file2.GetLine(i) <<("\n");
        if(line.find(szukana) != wxNOT_FOUND){
        check=true;
        }
    }
    file2.Close();

    if(telefon.length() != 9 || telefon.find_first_not_of("0123456789")!=std::string::npos || id_ksiazki.find_first_not_of("0123456789")!=std::string::npos || check!=true){
        wxMessageBox("Bledne dane!");
    }
    else {
        wxTextFile file( wxT("zamowienia.txt") );
        file.Open();
        file.AddLine("|: " + imie + " | " + nazwisko + " | " + telefon + " | " + id_ksiazki + " |");
        file.Write();
        wxMessageBox("Zamowiono!");
        file.Close();
        TextCtrl1->Clear();
        TextCtrl2->Clear();
        TextCtrl3->Clear();
        TextCtrl4->Clear();
    }
}
