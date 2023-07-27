#include <wx/textfile.h>
#include <wx/msgdlg.h>
#include "edycja.h"

//(*InternalHeaders(edycja)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(edycja)
const long edycja::ID_TEXTCTRL1 = wxNewId();
const long edycja::ID_TEXTCTRL2 = wxNewId();
const long edycja::ID_TEXTCTRL3 = wxNewId();
const long edycja::ID_TEXTCTRL4 = wxNewId();
const long edycja::ID_BUTTON1 = wxNewId();
const long edycja::ID_STATICTEXT1 = wxNewId();
const long edycja::ID_STATICTEXT2 = wxNewId();
const long edycja::ID_STATICTEXT3 = wxNewId();
const long edycja::ID_STATICTEXT4 = wxNewId();
const long edycja::ID_TEXTCTRL5 = wxNewId();
const long edycja::ID_STATICTEXT5 = wxNewId();
//*)

BEGIN_EVENT_TABLE(edycja,wxFrame)
	//(*EventTable(edycja)
	//*)
END_EVENT_TABLE()

edycja::edycja(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(edycja)
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(650,300));
	SetBackgroundColour(wxColour(191,168,158));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(64,48), wxSize(130,30), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	wxFont TextCtrl1Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	TextCtrl1->SetFont(TextCtrl1Font);
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(24,144), wxSize(130,30), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	wxFont TextCtrl2Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	TextCtrl2->SetFont(TextCtrl2Font);
	TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(184,144), wxSize(130,30), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	wxFont TextCtrl3Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	TextCtrl3->SetFont(TextCtrl3Font);
	TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(344,144), wxSize(130,30), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	wxFont TextCtrl4Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	TextCtrl4->SetFont(TextCtrl4Font);
	Button1 = new wxButton(this, ID_BUTTON1, _("Edytuj"), wxPoint(256,48), wxSize(100,35), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button1->SetBackgroundColour(wxColour(235,245,238));
	wxFont Button1Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	Button1->SetFont(Button1Font);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Podaj ID do edycji"), wxPoint(64,16), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Autor"), wxPoint(224,112), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Tytul"), wxPoint(56,112), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	wxFont StaticText3Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	StaticText3->SetFont(StaticText3Font);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Cena"), wxPoint(384,112), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	wxFont StaticText4Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	StaticText4->SetFont(StaticText4Font);
	TextCtrl5 = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxPoint(504,144), wxSize(130,30), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	wxFont TextCtrl5Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	TextCtrl5->SetFont(TextCtrl5Font);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Gatunek"), wxPoint(528,112), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	wxFont StaticText5Font(14,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bookman Old Style"),wxFONTENCODING_DEFAULT);
	StaticText5->SetFont(StaticText5Font);
	Center();

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&edycja::OnButton1Click);
	//*)
}

edycja::~edycja()
{
	//(*Destroy(edycja)
	//*)
}


void edycja::OnButton1Click(wxCommandEvent& event)
{
    wxTextFile file;
    wxString line;
    wxString pom;
    wxString ogranicznik1 = "|: ";
    wxString ogranicznik2 = " |";
    wxString id = TextCtrl1->GetValue();
    wxString tytul = TextCtrl2->GetValue();
    wxString autor = TextCtrl3->GetValue();
    wxString cena = TextCtrl4->GetValue();
    wxString gatunek = TextCtrl5->GetValue();
    wxString szukana = ogranicznik1+id+ogranicznik2;
    if(id.find_first_not_of("0123456789")!=std::string::npos || cena.find_first_not_of("0123456789")!=std::string::npos) {wxMessageBox("Bledne dane!");}
    else {
    wxString dane = "|: " + id + " | " + tytul + " | " + autor + " | " + cena + " | " + gatunek + " |";

    file.Open("ksiazki.txt");

    for(size_t i=0; i<file.GetLineCount(); i++){
        line << file.GetLine(i) <<("\n");
        if(line.find(szukana) != wxNOT_FOUND){
            file.RemoveLine(i);
            file.InsertLine(dane,i);
            file.Write();
            wxMessageBox("Zedytowano dane!");
            TextCtrl1->Clear();
            TextCtrl2->Clear();
            TextCtrl3->Clear();
            TextCtrl4->Clear();
            TextCtrl5->Clear();
        }
        else {wxMessageBox("Bledne ID!"); break;}
        line.Clear();
    }
    file.Close();}
}
